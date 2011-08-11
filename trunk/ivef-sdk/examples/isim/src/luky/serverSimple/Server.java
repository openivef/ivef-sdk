/******************************************************************************
 *   Copyright (C) 2006 Chris Lukassen
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 ******************************************************************************/
package luky.serverSimple;


import java.io.*;
import java.util.*;
import java.net.*;
import java.security.*;
import luky.Version;
import luky.util.*;
import luky.serverSimple.*;
import luky.events.*;


/*******************************************************************************
 * Server class is a template class which can be used to create a socket server
 * program. It implents a standard interface which can easily be extended.<br>
 * In order to use it properly one must also extend the Handler class and override
 * it's methods to add the wanted functionality.<br> To give this extended handler
 * to the server, one must override the server method "makeNewHandler" and use
 * this function to create a new handler object of the derived type. The server
 * will call this method each time a new connection is made and pass this
 * connection to the handler.<br>
 * When one needs special initialization, eg. the creation of an encryption object
 * or a connection to a special database, one can override the userInit method.
 * This method is called during the initialization and can store data in the
 * userData hashtable. This hashtable is also passed to the handlers so the
 * data is available where you may need it.<br>
 * The properyManager is also available. You can use this object to get parameters
 * from the initialization file that you provided for this server.<br> *
 * The Server class uses the Log class and the propertyManager
 *  Revision Changes : <br>
 *  <ul>
 *   <li> ver 1.01 important bugfix in handleCommand, readerror now returns NOK
 *           instead of OK ! </li>
 *   <li> ver 2.00 all settings are adjustable, ready for the util class </li>
 *   <li> ver 3.00 ported to luky
 *   <li> ver 3.01 added support for listening to, and firing  MyEvents
 *   <li> ver 3.02 added LogBackupFileName and LogMaxFileSize to allow filelog rollover
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 3.02
 ******************************************************************************/
public class Server extends Thread implements MyEventListener {

    /***************************************************************************
     variables
     ***************************************************************************/
    protected Vector    myHandlers = new Vector();
    protected PropertyManager propsMan = null;
    protected String version = null;
    private boolean quiet = false;
    private boolean quit = false;
    protected Hashtable userData = null;
    protected javax.swing.event.EventListenerList listenerList = new javax.swing.event.EventListenerList();

    /***************************************************************************
     constants
     ***************************************************************************/
    private int OK = Constants.OK;
    private int NOK = Constants.NOK;
    private String usage = version + "\n"
            + "----------------------------------------\n"
            + " -h                  help \n"
            + " -log                logging enabled \n"
            + " -l <level>          log level \n"
            + " -p <property file>  property file \n"
            + " -quiet              guess what :-)\n";

    /**************************************************************************
     * constructor, pass the arguments of the server here,
     * @param args the arguments that were used to start the server
     * @param _version the version of this server
     * @param iniFile the file
     **************************************************************************/
    public Server(String[] args, String _version, String iniFile) {
        int argc = args.length;
        int i = 0;
        int logLevel = 0;
        String level = null;
        String propsFile = iniFile;
        boolean log = false;

        // check the parameters
        if (_version == null) {
            version = "unknown version";
        } else {
            version = _version;
        }

        // parse command line options
        while (i < argc) {
            if (args[i].equals("-log")) // logging enabled
            {
                log = true;
            } else if (args[i].equals("-quiet")) // no commandline console
            {
                quiet = true;
            } else if (args[i].substring(0, 2).equals("-l")) // log level
            {
                if (args[i].length() > 2) // format -l<level>
                {
                    level = args[i].substring(2, args[i].length());
                } else // format -l <level>>
                {
                    i++;
                    level = args[i].substring(0, args[i].length());
                }
            } else if (args[i].substring(0, 2).equals("-p")) // properties file
            {
                if (args[i].length() > 2) // format -p<filename>
                {
                    propsFile = args[i].substring(2, args[i].length());
                } else // format -p <filname>
                {
                    i++;
                    propsFile = args[i].substring(0, args[i].length());
                }
            } else if (args[i].equals("-h")) // usage
            {
                System.out.println(usage);
                System.exit(0);
            } else // unknown option
            {
                System.out.println(
                        "That one is new to me, stick to the usage please");
                System.out.println(usage);
                System.exit(0);
            }
            // next token
            i++;
        }

        // show them who we are
        println("\n" + version);
        println("----------------------------------");

        // and what library we are using
        Version ver = new Version();

        println("Using: " + ver.getLibVersion());

        // always try to read properties
        propsMan = new PropertyManager();
        print("Reading property file..........");
        if (propsMan.readFile(propsFile) == OK) {
            println("ok.");
        } else {
            println("failed.");
        }

        // initiate logging
        if (log) {
            print("Starting logging...............");
            if (startLogging() == NOK) {
                println("failed");
            } else {
                println("ok.");
            }
        }
        // change the level if needed
        if (!(level == null)) {
            print("Changing log level.............");
            try {
                logLevel = Integer.parseInt(level);
                if (Log.setLogLevel(logLevel) == NOK) {
                    println("failed, setLoglevel (" + level + ")");
                    System.exit(1);
                } else {
                    println("ok.");
                }
            } catch (Exception e) {
                println("failed, level is not a number (" + level + ")");
                System.exit(1);
            }
        }

        // see what the user has to do
        print("Running user constructor.......");
        userData = new Hashtable();
        if (userInit() == NOK) {
            println("failed");
        } else {
            println("ok.");
        }
    }

    /**************************************************************************
     * constructor, pass the arguments of the server here,
     **************************************************************************/
    public Server(boolean log, int logLevel, boolean _quiet, String _version, PropertyManager props) {
        int i = 0;
        String level = null;

        // check the parameters
        if (_version == null) {
            version = "unknown version";
        } else {
            version = _version;
        }

        // use the parameters
        quiet = _quiet;

        // show them who we are
        println("\n" + version);
        println("----------------------------------");

        // and what library we are using
        Version ver = new Version();

        println("Using: " + ver.getLibVersion());

        // always try to read properties
        propsMan = props;

        // initiate logging
        if (log) {
            print("Starting logging...............");
            if (startLogging() == NOK) {
                println("failed");
            } else {
                println("ok.");
            }
        }
        // change the level if needed
        if (!(level == null)) {
            print("Changing log level.............");
            try {
                logLevel = Integer.parseInt(level);
                if (Log.setLogLevel(logLevel) == NOK) {
                    println("failed, setLoglevel (" + level + ")");
                    System.exit(1);
                } else {
                    println("ok.");
                }
            } catch (Exception e) {
                println("failed, level is not a number (" + level + ")");
                System.exit(1);
            }
        }

        // see what the user has to do
        print("Running user constructor.......");
        userData = new Hashtable();
        if (userInit() == NOK) {
            println("failed");
        } else {
            println("ok.");
        }
    }

    /**************************************************************************
     * function that will be called by the handler class once a shutdown command
     * is given. It shutdowns the server loop.
     * @param status TRUE or FALSE, on TRUE the server will stop
     **************************************************************************/
    public void setQuit(boolean status) {
        quit = status;
    }

    /**************************************************************************
     * userInit is called during the initalization of the server and can be used
     * to add initialization to your server.
     * @return OK or NOK
     **************************************************************************/
    protected int userInit() {
        return OK;
    }

    /**************************************************************************
     * getPropsMan() will return the property manager of this server. It is the
     * same object that is also passed to the handlers.
     * @return propsMan
     **************************************************************************/
    public PropertyManager getPropsMan() {
        return propsMan;
    }

    /**************************************************************************
     * print a message to the console of the server program, warning there is no
     * newline included in this function, this may clutter your prints consideralbly
     * since you are running in different threads.
     * @param msg the string that is to be printed
     **************************************************************************/
    public void print(String msg) {
        if (!quiet) {
            System.out.print(msg);
        }
    }

    /**************************************************************************
     * print a message to the console of the server program, followed by a newline
     * @param msg the string that is to be printed
     **************************************************************************/
    public void println(String msg) {
        if (!quiet) {
            System.out.println(msg);
        }
    }

    /**************************************************************************/
    public void removeHandler(Handler handler) {
        Log.print(Log.DEBUG, "Server.removeHandler entered");
        myHandlers.remove(handler);
    }

     /**************************************************************************/
    private int startLogging() {
        // set module name
        Log.setModuleName(version + ",");

        // is there any output device ?
        String screenLog = propsMan.getProperty("LogToScreen");

        if (screenLog == null) {
            Log.print(Log.WARNING,
                    "Server.startLogging " + "LogToScreen should be set");
            screenLog = "FALSE";
        }

        // uppercase
        screenLog = screenLog.toUpperCase();
        // is the parameter valid ?
        if (!screenLog.equals("FALSE") && !screenLog.equals("TRUE")) {
            Log.print(Log.FATAL,
                    "Server.startLogging "
                    + "LogToScreen can only be true/false " + screenLog);
            return NOK;
        }

        String fileLog = propsMan.getProperty("LogToFile");

        if (fileLog == null) {
            Log.print(Log.WARNING,
                    "Server.startLogging " + "LogToFile should be set");
            fileLog = "FALSE";
        }

        // uppercase
        fileLog = fileLog.toUpperCase();
        // is the parameter valid ?
        if (!fileLog.equals("FALSE") && !fileLog.equals("TRUE")) {
            Log.print(Log.FATAL,
                    "Server.startLogging " + "LogToFile can only be true/false "
                    + fileLog);
            return NOK;
        }

        String dbLog = propsMan.getProperty("LogToDatabase");

        if (dbLog == null) {
            Log.print(Log.WARNING,
                    "Server.startLogging " + "LogToDatabase should be set");
            dbLog = "FALSE";
        }

        // uppercase
        dbLog = dbLog.toUpperCase();
        // is the parameter valid ?
        if (!dbLog.equals("FALSE") && !dbLog.equals("TRUE")) {
            Log.print(Log.FATAL,
                    "Server.startLogging "
                    + "LogToDatabase can only be true/false " + dbLog);
            return NOK;
        }

        // try the screenLog
        if (screenLog.equals("TRUE")) {
            Log.setOutput(Log.SCREEN, true);
        }

        // and the fileLog
        if (fileLog.equals("TRUE")) {
            // get additional properties for file logging
            String logFileName = propsMan.getProperty("LogFileName");
            String appendToLog = propsMan.getProperty("LogAppendToFile");

            // test if we have a LogBackupFileName
            String backupLogFileName = propsMan.getProperty("LogBackupFileName");
            int size = 0;

            try {
                size = propsMan.getIntProperty("LogMaxFileSize");
            } catch (Exception e) {
                Log.print(Log.DEBUG,
                        "Server.startLogging " + "size not set, or not int");
                size = 0;
            }

            appendToLog = appendToLog.toUpperCase();

            if (logFileName == null) { // is there a filename ?
                Log.print(Log.FATAL,
                        "Server.startLogging " + "LogFileName not set");
                fileLog = "FALSE";
            } // is there a append to log option
            else if (appendToLog == null) {
                Log.print(Log.FATAL,
                        "Server.startLogging " + "AppendToLogFile not set");
                fileLog = "FALSE";
            } // are the options correct ?
            else if (!appendToLog.equals("TRUE") && !appendToLog.equals("FALSE")) {
                Log.print(Log.FATAL,
                        "Server.startLogging "
                        + "AppendToLogFile can only be true/false "
                        + appendToLog);
                fileLog = "FALSE";
            } // try to set the file
            else if (appendToLog.equals("TRUE")) {
                if ((backupLogFileName != null) && (size > 0)) {
                    if (Log.setFile(logFileName, true, backupLogFileName, size)
                            == NOK) {
                        Log.print(Log.FATAL,
                                "Server.startLogging " + "setFile failed");
                        fileLog = "FALSE";
                    }
                } else {
                    if (Log.setFile(logFileName, true) == NOK) {
                        Log.print(Log.FATAL,
                                "Server.startLogging " + "setFile failed");
                        fileLog = "FALSE";
                    }
                }
            } else {

                if ((backupLogFileName != null) && (size > 0)) {
	
                    if (Log.setFile(logFileName, false, backupLogFileName, size)
                            == NOK) {
                        Log.print(Log.FATAL,
                                "Server.startLogging " + "setFile failed");
                        fileLog = "FALSE";
                    }
                } else {	

                    if (Log.setFile(logFileName, false) == NOK) {
                        Log.print(Log.FATAL,
                                "Server.startLogging " + "setFile failed");
                        fileLog = "FALSE";
                    }
                }
            }
            // now try to set it
            if (fileLog.equals("TRUE")) {
                if (Log.setOutput(Log.FILE, true) == NOK) {
                    Log.print(Log.FATAL,
                            "Server.startLogging " + "setOutput failed");
                    fileLog = "FALSE";
                }
            }
        }

        // try the database log
        if (dbLog.equals("TRUE")) {
            // get additional properties for file logging
            String url = propsMan.getProperty("LogDatabaseUrl");
            String user = propsMan.getProperty("LogDatabaseUser");
            String pass = propsMan.getProperty("LogDatabasePassword");
            String driver = propsMan.getProperty("LogDatabaseDriver");

            if (url == null) {
                Log.print(Log.FATAL,
                        "Server.startLogging " + "LogDatabaseUrl not set");
                dbLog = "FALSE";
            } // is there a append to log option
            else if (user == null) {
                Log.print(Log.FATAL,
                        "Server.startLogging " + "LogDatabaseUser not set");
                dbLog = "FALSE";
            } else if (pass == null) {
                Log.print(Log.FATAL,
                        "Server.startLogging " + "LogDatabasePassword not set");
                dbLog = "FALSE";
            } else if (driver == null) {
                Log.print(Log.FATAL,
                        "Server.startLogging " + "LogDatabaseDriver not set");
                dbLog = "FALSE";
            } // try to connect to the database
/*            else if (Log.setDatabase(url, driver, user, pass) == NOK) {
                Log.print(Log.FATAL,
                        "Server.startLogging " + "setDatabase failed");
                dbLog = "FALSE";
            }
*/
            // now try to set it
            if (Log.setOutput(Log.DATABASE, true) == NOK) {
                Log.print(Log.FATAL, "Server.startLogging " + "setOutput failed");
                dbLog = "FALSE";
            }
        }

        if (screenLog.equals("FALSE") && fileLog.equals("FALSE")
                && dbLog.equals("FALSE")) {
            Log.print(Log.FATAL, "Server.startLogging " + "no output realized");
            return NOK;
        }

        Log.print(Log.DEBUG, "Server.startLogging succeded");
        return OK;
    }

     /**************************************************************************/
    private int spawnHandler(BufferedReader in, PrintWriter out, String caller) {
        // create a new handler
        Handler handler = makeNewHandler(userData, in, out, propsMan, caller);

        // start it
        handler.start();

        // add it 
        if (handler != null) {
            myHandlers.add(handler);
        }

        // exit this function, the out stream will be handled by the handler
        // thread.
        Log.print(Log.DEBUG, "Server.spawnHandler done ");

        return OK;
    }

     /**************************************************************************
     * make a new handler class, must be overridden to add the custom handler class
     * @return new Handler
     **************************************************************************/
    protected Handler makeNewHandler(Hashtable userData,
            BufferedReader in, PrintWriter out, PropertyManager propsMan,
            String caller) {
        return new Handler(userData, this, in, out, propsMan, caller);
    }

    /**************************************************************************
     * The server can listen to generic events, this can be overwritten
     * to interact with 
     **************************************************************************/
    public void	myEventOccurred(MyEvent evt) {
        String event = (String) evt.getEventData();

        Log.print(Log.DEBUG, "Server.myEventOccurred: " + event);
    }

    /**************************************************************************
     * This methods allows classes to register for MyEvents
     **************************************************************************/
    public void addMyEventListener(MyEventListener listener) {
        listenerList.add(MyEventListener.class, listener);
    }
    
    /**************************************************************************
     * This methods allows classes to unregister for MyEvents
     **************************************************************************/
    public void removeMyEventListener(MyEventListener listener) {
        listenerList.remove(MyEventListener.class, listener);
    }
    
    /**************************************************************************
     * This methods fires my events to registered listeners
     **************************************************************************/
    public void fireMyEvent(MyEvent evt) {
        Object[] listeners = listenerList.getListenerList();

        // Each listener occupies two elements - the first is the listener class
        // and the second is the listener instance
        for (int i = 0; i < listeners.length; i += 2) {
            if (listeners[i] == MyEventListener.class) {
                ((MyEventListener) listeners[i + 1]).myEventOccurred(evt);
            }
        }
    }

    /**************************************************************************
     * The server can listen to events from his childeren, this can be overwritten
     * to interact with them
     **************************************************************************/
    public void	childEventOccurred(MyEvent evt) {
        String event = (String) evt.getEventData();

        Log.print(Log.DEBUG, "Server.childEventOccurred: " + event);
    }

    /**************************************************************************
     * run method. Create an instance of your derived server and start it in a
     * seperate thread by calling the start function or in the same one by
     * executing the run method. Note that the method will only return when a
     * shutdown command is given.
     **************************************************************************/
    public void run() {
        int portNr = -1;
        ServerSocket server = null;

        print("Starting socket server.........");

        // do we have a port ?
        String port = propsMan.getProperty("Port");

        if (port == null) {
            Log.print(Log.FATAL, "Server.runServer " + "Port should be set");
            println("failed, no port specified");
            return;
        }

        // is this a number ?
        try {
            portNr = Integer.parseInt(port);
        } catch (Exception e) {
            println("failed, port is not a number (" + port + ")");
            System.exit(1);
        }

        // try to make a server socket
        try {
            server = new ServerSocket(portNr);
            println("ok.");
        } catch (Exception e) {
            println("failed, can't create a server socket");
            System.exit(1);
        }

        try {
            // keep hanging for socket connections
            Socket handler = null;

            println("Server ready for connection....waiting");
            handler = server.accept();
            while (!(handler == null)) {
                String caller = handler.getInetAddress().getHostAddress();

                println("Connection established to......" + caller);

                // create a reader to read from this input
                BufferedReader reader = new BufferedReader(new
                        InputStreamReader(handler.getInputStream()));

                // make writer so we can return the commands
                PrintWriter writer = new PrintWriter(handler.getOutputStream());

                // welcome user
                writer.println("WELCOME TO " + version);
                writer.flush();

                // start handler
                spawnHandler(reader, writer, caller);

                if (!quit) {
                    // wait for the next one
                    println("Server ready for connection....waiting");
                    handler = server.accept();
                } else {
                    handler = null;
                    print("Server is going for shutdown...");
                }
            }

        } catch (Exception e) {
            println("Socket Server error !");
            e.printStackTrace();
            println("going for a restart !");
            run();
        }

        // close off the logs
        Log.close();
        // find some way to wait for our threads to stop !
        // ....

        println("bye.");

        return;
    }
}
