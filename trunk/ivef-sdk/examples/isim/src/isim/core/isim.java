/******************************************************************************
 *   Copyright (C) 2005 Chris Lukassen
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 ******************************************************************************/

package isim.core;

import java.io.*;
import java.util.*;
import luky.util.*;
import isim.core.*;
import ivef.*;


/***************************************************************************
 * isim is a simulator for ivef tracks
 * <br>
 * [-p] <port>         - port number <br>
 * [-l] <loglevel>     - debug logging level<br>
 * -s   <sim file>  - simulation file
 * [-q] 	       - quiet mode
 * <br><br>
 * The sim file has the syntax as specified in ivef, intermediates will be prediced lineairly<br> <br>
  *  Revision Changes : <br>
 *  <ul>
 *   <li> 1.0.0 - initial version </li>
 *  </ul>
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.0.0
 ******************************************************************************/

public class isim {

    /***************************************************************************
     variables
     ***************************************************************************/

    /** the holder of all settings of the Server */
    protected PropertyManager propsMan = null;

    /***************************************************************************
     constants
     ***************************************************************************/
    private static int PORT = 0;
    private static int LOGLEVEL = 1;
    private static int SIMFILE = 2;
    private static int QUIET = 3;
    private static int LAST_OPTION = 4;

    /**************************************************************************
     * constructor, used to initialize libraries
     **************************************************************************/
    public void isim() {
        propsMan = new PropertyManager();
        // prepare logging
        Log.setOutput(Log.SCREEN, false);
        Log.setLogFallBack(false);

    }

    /**************************************************************************
     * main routine, pass the arguments of the server here,
     * @param args the arguments that were used to start the server
     **************************************************************************/
    public static void main(String args[]) {

        // ------------------------------
        // Take care of getting options
        // ------------------------------

        String usage = "isim [-p port] [-q]  [-l loglevel] [-s simfile] ";
        String options[] = { "-p", "-l", "-s", "-q" };
        String values[] = { null, null, null, "None" };

        String simfile = "";
        int port = 60000;
        boolean log = false;
        boolean quiet = false;
        int logLevel = 0;
        ScenarioReader scenarioReader = new ScenarioReader();
        PropertyManager props = new PropertyManager();

        props.setProperty("LogToScreen", "false");

        ParseOptions opt = new ParseOptions(args, options, values, usage);

        if (opt.remArgs.length != 0) {
            System.out.println(
                "isim.main error parsing args " + opt.remArgs.length);
            opt.usage_error();
        }

        // test
        // for (int i=0; i < LAST_OPTION; i++) {
        // System.out.println(options[i]+" = "+values[i]);
        // }

        try {

            if (values[LOGLEVEL] != null) {
                Log.setModuleName("isim");
                log = true;
                logLevel = Integer.parseInt(values[LOGLEVEL]);
                if (Log.setLogLevel(logLevel) == Constants.NOK) {
                    System.out.println("failed, setLoglevel (" + logLevel + ")");
                    System.exit(1);
                }
                Log.print(Log.DEBUG, "isim.main start logging succeded");
                props.setProperty("LogLevel", "" + logLevel);
            }

            if ((values[QUIET] != null) && (!(values[QUIET].equals("None")))) {
                quiet = true;
                Log.setOutput(Log.SCREEN, false);
                props.setProperty("LogToScreen", "false");
            } else {
                quiet = true; // server is always quiet, -q now used for screenlog
                Log.setOutput(Log.SCREEN, true);
                props.setProperty("LogToScreen", "true");
            }

            if (values[SIMFILE] != null) {
                simfile = values[SIMFILE];
                Log.print(Log.DEBUG, "isim.main using simfile " + simfile);
                // try to read the file and create an array of updates
                try {
                    // Open the file
                    FileInputStream fstream = new FileInputStream(simfile);
                    DataInputStream in = new DataInputStream(fstream);
                    BufferedReader br = new BufferedReader(new InputStreamReader(in));

                    String strLine;
                    ivef.Parser parser = new ivef.Parser(scenarioReader);

                    //Read File Line By Line
                    while ((strLine = br.readLine()) != null)   {
                        //System.out.println (strLine);
                        if (!strLine.equals("<xml>\n")) {   // ilisten makes logfiles that start with <xml> but do not end with it
                            parser.parseXMLString(strLine, true);
                        }
                    }

                    //Close the input stream
                    in.close();
                } catch (Exception e) {//Catch exception if any
                    Log.print(Log.FATAL, "isim.main Error: " + e.getMessage());
                }
                Log.print(Log.DEBUG, "isim.main read " + scenarioReader.getMovements().size() + " movements");
            }

            if (values[PORT] != null) {
                port = (Integer.parseInt(values[PORT]));
            }

            Log.print(Log.DEBUG, "isim.main using port " + port);

        } catch (NumberFormatException ex) {
            System.err.println("Invalid Integer Arg");
        }

        // ------------------------------
        // the property manager
        // ------------------------------

        // don't use the servers logging
        props.setProperty("LogToFile", "false");
        props.setProperty("LogToDatabase", "false");
        props.setProperty("LogToScreen", "false");
        props.setProperty("Port", "" + port);

        // activate the logging
        String logFileName = props.getProperty("LogFileName");
        String logBackupFileName = props.getProperty("LogBackupFileName");

        if (logBackupFileName != null) { // is there a filename ?
            logBackupFileName = logFileName + ".bak";
        }

        int maxSize = 100000;

        if (logFileName != null) { // is there a filename ?
            Log.print(Log.DEBUG, "isim.main logging to " + logFileName);
            if (Log.setFile(logFileName, true, logBackupFileName, maxSize)
                    == Constants.NOK) { // try to append
                Log.print(Log.FATAL, "isim.main " + logFileName + " failed");
            }
            Log.setOutput(Log.FILE, true); // log to file
        }

        // ------------------------------
        // the isim server
        // ------------------------------
        // we need to instantiate a server for the client handling

        Server server = new Server(log, logLevel, props, quiet, scenarioReader.getMovements());

        Log.print(Log.DEBUG, "isim.main starting at port " + port);
        server.start();
    }

    /*************************************************************************/
    private static byte[] gethexValue(String value) {
        byte temp;
        byte[] Key = new byte[value.length() / 2 - 1];
        String ss, str;

        ss = value.substring(2);
        for (int i = 0; i < ss.length(); i += 2) {
            str = ss.substring(i, i + 2);
            temp = (byte) Integer.parseInt(str, 16);
            Key[i / 2] = temp;
        }
        return Key;
    }

}
