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
import java.net.*;
import luky.util.*;
import luky.serverSimple.*;
import luky.events.*;


/******************************************************************************
 * The Client class is a template class for the luky server client thread.
 * use this class to setup, communicat and close server communications.
 * The Client uses the Log class for it's loggings <p>
 * the class is threadsafe since rev. 2 <br>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 2.00
 ******************************************************************************/
public class Client {

    /***************************************************************************
     variables
     ***************************************************************************/
    protected BufferedReader reader = null;     
    protected PrintWriter writer = null;
    private int portNr;
    private String ip;
    protected boolean connected = false;

    /***************************************************************************
     methods
     ***************************************************************************/

    /**************************************************************************
     * constructor, takes ip number and portnumber of the server to connect to
     **************************************************************************/
    public Client(String ip, int portNr) {
        this.ip = ip;
        this.portNr = portNr;
    }

    public Client(String ip, String port) {
        int portNr = 60000;

        try {
            portNr = Integer.parseInt(port);
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "Client.constructor failed, port is not a number (" + port
                    + ")");
        }
        this.ip = ip;
        this.portNr = portNr;
    }

    /**************************************************************************/
    public int openConnection() {
        try {
            // make a socket
            Socket socket = new Socket(ip, portNr);

            if (socket == null) {
                Log.print(Log.FATAL, "Client.openConnection cannot open socket");
                return Constants.NOK;
            }

            // make somer readers and writers
            reader = new BufferedReader(new
                    InputStreamReader(socket.getInputStream()));
            if (reader == null) {
                Log.print(Log.FATAL,
                        "Client.openConnection cannot create reader");
                return Constants.NOK;
            }
            writer = new PrintWriter(socket.getOutputStream());
            if (writer == null) {
                Log.print(Log.FATAL,
                        "Client.openConnection cannot create writer");
                return Constants.NOK;
            }

            // catch the welome line
            String reply = reader.readLine();
        } catch (Exception e) {
            Log.print(Log.WARNING, "Client.openConnection Exception occured");
            Log.print(Log.STACK, e.toString());
            return Constants.NOK;
        }
        Log.print(Log.MESSAGE,
                "Client.openConnection to " + ip + " port: " + portNr);
	
        connected = true;
        return Constants.OK;
    }

     /**************************************************************************
     * sends a command and expects OK. on return
     **************************************************************************/
    public synchronized int sendCommand(String command) {
        if (!connected) {
            if (openConnection() == Constants.NOK) {
                return Constants.NOK;
            }
        }

        try {
            // run a command
            writer.println(command);
            writer.flush();

            // get the reply
            String reply = reader.readLine();

            // test the reply
            if (!(reply.equals("OK."))) {
                Log.print(Log.FATAL, "Client.sendCommand reports error");
                return Constants.NOK;
            }
        } catch (Exception e) {
            Log.print(Log.FATAL, "Client.sendCommand Exception occured");
            Log.print(Log.STACK, e.toString());
            e.printStackTrace();	
            return Constants.NOK;
        }

        Log.print(Log.DEBUG, "Client.sendCommand done for (" + command + ")");

        return Constants.OK;
    }

    /**************************************************************************
     * sends a command and expects one line terminated with OK. on return
     **************************************************************************/
    public synchronized String getLine(String command) {
	
        Vector result = getList(command);
	
        if ((result == null) || (result.size() != 1)) {
            Log.print(Log.DEBUG,
                    "Client.getLine (" + command
                    + ") return more or less than one line");
            return null;
        }

        return (String) result.get(0);
    }

    /**************************************************************************
     * sends a command and expects a list of lines terminated with OK. on return
     **************************************************************************/
    public synchronized Vector getList(String command) {
        if (!connected) {
            if (openConnection() == Constants.NOK) {
                return null;
            }
        }

        Vector replyLines = new Vector();

        try {
            // run a command
            writer.println(command);
            writer.flush();

            // get the reply
            String reply = reader.readLine();

            // tricky ! assume the server sends an OK. to terminate !
            while (!(reply.equals("OK."))) {
                replyLines.add(reply);
                reply = reader.readLine();	
            }
        } catch (Exception e) {
            Log.print(Log.FATAL, "Client.getList Exception occured");
            Log.print(Log.STACK, e.toString());
            return null;
        }

        Log.print(Log.DEBUG, "Client.getList done for (" + command + ")");

        return replyLines;
    }
}
