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


import java.util.*;
import java.io.*;
import luky.util.*;
import luky.crypt.*;
import luky.serverSimple.*;
import luky.events.*;


/******************************************************************************
 * The Handler class is a template class for the luky server handler thread.
 * The class is beeing invoked by the Server on receipt of a socket connection.
 * For each connection a new Thread of the handler class will be spawned.
 * This handler will then handle the incomming commands, some of the commands
 * are standarized like : HELLO, CLOSE and SHUTDOWN.
 * <BR> In order to make use of this class you must extend from it and add your
 * extended class to your extention of the luky.server.server class. From there
 * you will make sure that your class is called and not the default Handler.
 * <BR> Handler will serve the incomming connection and handle the HELLO, CLOSE,
 * HELP and SHUTDOWN command for you. If it cannot identify the command, it will
 * call upon the 'handleUserCommand method. This method is protected and should
 * be overwritten by you. You can handle this command and return OK or NOK to
 * the super class.
 * <BR> If for some reason you need to parse all incomming lines (like when they
 * are encrypted) you can overload the 'decrypt' method. All incomming lines
 * are passed through this function.
 * <BR> the in and out variables give you direct access to the socket you are
 * connected to and you may use the propsMan to get any properties.
 * Further you will have protected access to the luky variable which will handle
 * all database access for you.
 * <BR> User specific data is available in the hashtable userData. You can use
 * this table in the server class to pass some specific data to your Handler,
 * like a crypt object for example.<br>
 * The Handler uses the Log class for it's loggings<br>
 * Version 1.10 also supports the CLEAN command, that forces the garbage collector
 * clean up. (handy for testin)
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.10
 ******************************************************************************/
public class Handler extends Thread {

    /***************************************************************************
     variables
     ***************************************************************************/

    /** this propertyManager holds all settings read from the .ini file
     *  at the startup of the server */
    protected PropertyManager propsMan = null;

    /** in is your input stream, directly connected to the user you are
     *  supposed to handle */
    protected BufferedReader in = null;

    /** out is your connection to the user you are supposed to handle, you can
     *  use it to tell him how well you are doing with his commands */
    protected PrintWriter out = null;
    private Hashtable userData = null;

    /** parent access can be overloaded for convieniance **/
    protected Server parent = null;
    private boolean rootUser = false;

    /***************************************************************************
     constants
     ***************************************************************************/
    private int OK = Constants.OK;
    private int NOK = Constants.NOK;

    /***************************************************************************
     methods
     ***************************************************************************/

    /**************************************************************************
     * constructor, there is no need to call this constructor yourself,
     * it will be called from the luky.server.server class.
     * (So don't sweat over it)
     **************************************************************************/
    public Handler(Hashtable userData, Server parent,
            BufferedReader in, PrintWriter out, PropertyManager propsMan,
            String caller) {
        this.userData = userData;
        this.in = in;
        this.out = out;
        this.parent = parent;
        this.propsMan = propsMan;
        // only local users are rootUsers
        if (caller.substring(0, 7).equals("192.168")
                || caller.substring(0, 9).equals("127.0.0.1")) {
            rootUser = true;
        }
    }

    /**************************************************************************
     * run method, there is no need to call this constructor yourself,
     * it will be called from the luky.server.server class.
     * (So don't sweat over it)
     **************************************************************************/
    public void run() {
        handleCommand();
    }

    /**************************************************************************
     * handleUserCommand, overwrite this function with your own version in
     * which you must handle 'command' passed to this method. You can read/write
     * to your corresponding party using the in/out parameters.
     * @param in the input reader of the socket connection you are serving
     * @param out the output writer of the socket connection you are serving
     * @param command the command you should handle
     * @return OK or NOK
     **************************************************************************/
    protected int handleUserCommand(BufferedReader in, PrintWriter out, String command) {
        return OK;
    }

    /**************************************************************************/
    private void handleCommand() {
        // we only support a simple command structure
        // valid commands are:
        //
        // HELLO       : replies with HI.
        // CLOSE       : close connection
        // SHUTDOWN    : close down the server
        //

        boolean exit = false;
        String command = null;
        String input = null;

        while (!exit) {
            // get the command

            try {
                input = in.readLine();
            } catch (Exception e) {
                Log.print(Log.WARNING, "Handler.handleCommand read error");
                out.println("NOK.");
                out.flush();
                exit = true;
                parent.println(
                        "    Reading command............failed, read error.");
            }

            // decrypt the input to a command
            command = decrypt(input);
            Log.print(Log.DEBUG, "Handler.handleCommand read " + command);
            parent.println("    Reading command............done.");

            if (command == null) {
                parent.print("    Garbage in input, quiting..");
                Log.print(Log.DEBUG,
                        "Handler.handleCommand garbage input, quiting ");
                out.println("NOK.");
                out.flush();
                parent.println("done.");
                exit = true; // auto close connection to avoid hog
            } else if (command.equals("HELLO") || command.equals("hello")) {
                parent.print("    Handling HELLO command.....");
                out.println("HI.");
                out.flush();
                parent.println("done.");
            } else if (command.equals("CLEAN") || command.equals("clean")) {
                parent.print("    Handling CLEAN command.....");
                // finalize all objects
                System.runFinalization();
                // clean the heap
                System.gc();
                out.println("OK.");
                out.flush();
                parent.println("done.");
            } else if (command.equals("SHUTDOWN") || command.equals("shutdown")) {
                // close this baby
                parent.print("    Handling SHUTDOWN command..");
                if (rootUser) {
                    out.println("OK.");
                    parent.setQuit(true);
                    parent.println("done.");
                } else {
                    out.println("NOK.");
                    parent.println("refused.");
                }
                out.flush();
                exit = true;
            } else if (command.equals("CLOSE") || command.equals("close")) {
                // list all shops
                parent.print("    Handling CLOSE command.....");
                out.println("OK.");
                out.flush();
                exit = true;
                parent.println("done.");
            } else if (command.equals("?") || command.equals("HELP")
                    || command.equals("help")) {
                // unknown command
                parent.print("    Received help command......");
                String validCommands = propsMan.getProperty("SupportedCommands");

                if (validCommands == null) {
                    Log.print(Log.FATAL,
                            "Handler.handleCommand SupportedCommands not set");
                    validCommands = "unknown";
                }
                out.println(
                        "VALID COMMANDS: HELLO, SHUTDOWN, CLOSE, CLEAN, HELP, "
                                + validCommands);
                out.flush();
                parent.println("done.");
            } else // all other commands
            {
                parent.print("    Handling command...........");

                // load kick a handler
                if (handleUserCommand(in, out, command) == NOK) {
                    // quit only after a wrong command
                    parent.println("error.");
                    Log.print(Log.FATAL,
                            "Handler.handleCommand command error, exit handler");
                    out.println("NOK.");
                    out.flush();
                    exit = true;
                } else {
                    parent.println("done.");
                    out.println("OK.");
                    out.flush();
                }

            }
        }
        destroy(in, out);
    }

     /**************************************************************************
     * decrypt is fed with every command string before it is passed to the
     * internal command handler. Implement a decryption function here if you
     * need to parse all incomming lines.<BR> the standard function simply
     * returns the input string.
     * @param in the input string
     * @return the decrypted string
     **************************************************************************/
    protected String decrypt(String in) {
        return in;
    }

    /**************************************************************************
     * destroy is called before the thread is closed,
     * it allows for the user to close existing streams or handle notifications
     * when overriding, please remember to close the in and out streams !
     **************************************************************************/
    protected int destroy(BufferedReader in, PrintWriter out) {
        Log.print(Log.DEBUG, "Handler.destroy going down !");

        try {
            out.flush();
            out.close();
            in.close();
        } catch (Exception e) {
            Log.print(Log.WARNING, "Handler.destroy i/o error");
        }
	
        parent.removeHandler(this);

        return OK;
    }

}
