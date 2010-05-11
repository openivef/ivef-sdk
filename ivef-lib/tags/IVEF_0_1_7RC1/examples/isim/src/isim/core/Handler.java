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
package isim.core;


import java.util.*;
import java.io.*;
import luky.util.*;
import luky.crypt.*;
import luky.events.*;
import ivef.*;

/******************************************************************************
 * The Handler class handles an IVEF listener <br>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.0.0
 ******************************************************************************/
public class Handler extends Thread implements ivef.ParserListener {

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
     *  use it to tell him how well you are doing with his inputs */
    protected PrintWriter out = null;
    private Hashtable userData = null;

    /** parent access can be overloaded for convieniance **/
    protected Server parent = null;
    private boolean rootUser = false;
    protected boolean exit = false;

    /** ivef parser **/
    private ivef.Parser parser = null;

    /** ivef movements holder **/
    private Vector movements = null;

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
        this.parser = new Parser(this);
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
        handleInput();
    }

    /**************************************************************************/
    private void handleInput() {

        String rawInput = null;
        String input = null;

        while (!exit) {
            // get the input
            try {
                rawInput = in.readLine();
            } catch (Exception e) {
                Log.print(Log.WARNING, "Handler.handleInput read error");
                exit = true;
                parent.println("    Reading input............failed, read error.");
            }

            // decrypt the input to
            input = decrypt(rawInput);
            Log.print(Log.DEBUG, "Handler.handleInput read " + input);
            //parent.println("    Reading input............done.");

            if (input == null) {
                parent.print("    Garbage in input, quiting..");
                Log.print(Log.DEBUG,
                          "Handler.handleInput garbage input, quiting ");
                parent.println("done.");
                exit = true; // auto close connection to avoid hog
            } else { // all other inputs
                //parent.print("    Handling input...........");

                // handle the actual input, the parser will call us back if there is interesting data
                parser.parseXMLString(input, true);
            }
        }
        destroy(in, out);
    }

    /**************************************************************************
    * decrypt is fed with every input string before it is passed to the
    * internal input handler. Implement a decryption function here if you
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

    /**************************************************************************/
    public void handleMSG_VesselData(MSG_VesselData obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_VesselData Received vesseldata, did not expect that..");
    };

    /**************************************************************************/
    public void handleMSG_LoginRequest(MSG_LoginRequest obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_LoginRequest Received LoginRequest, Sending Reply..");
        sendLoginResponse(obj);
    };

    /**************************************************************************/
    public void handleMSG_LoginResponse(MSG_LoginResponse obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_LoginResponse Received Login Response, did not expect that..");
    };

    /**************************************************************************/
    public void handleMSG_Ping(MSG_Ping obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_Ping Received Ping, did not expect that..");
    };

    /**************************************************************************/
    public void handleMSG_Pong(MSG_Pong obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_Pong Received Pong..");
        // could check if it matches the pings we send out
    };

    /**************************************************************************/
    public void handleMSG_ServerStatus(MSG_ServerStatus obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_ServerStatus Received Server Status, did not expect that..");
    };

    /**************************************************************************/
    public void handleMSG_Logout(MSG_Logout obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_Logout Received Logout, disconnecting..");
        destroy(in, out);
    };

    /**************************************************************************/
    public void handleMSG_ServiceRequest(MSG_ServiceRequest obj) {
        Log.print(Log.DEBUG, "Handler.handleMSG_ServiceRequest Received Service Request..");
        sendSeverStatus(obj);
    };

    /**************************************************************************/
    public Header newHeader() {
        // every message has a header
        Header header = new Header();
        header.setMsgRefId("{"+UUID.randomUUID().toString()+"}");
        header.setVersion("1.0");
        return header;
    }

    /**************************************************************************/
    public void sendLoginResponse(MSG_LoginRequest obj) {

        // create a message
        MSG_LoginResponse msg = new MSG_LoginResponse();
        msg.setHeader(newHeader());

        // and a body with the request
        Body body = new Body();
        LoginResponse data = new LoginResponse();
        data.setMsgId(obj.getHeader().getMsgRefId());
        data.setResult(1); // allways succesfull login
        data.setReason("Because we love you");
        body.setLoginResponse(data);
        msg.setBody(body);

        // output the message
        Log.print(Log.STACK, "Handler.sendLoginResponse Sending: "+msg.toXML());
        out.println(msg.toXML());
        out.flush();

        // login is completed we can start sending movements
        startSendingMovements();
    };

    /**************************************************************************/
    public void sendSeverStatus(MSG_ServiceRequest obj) {

        // create a message
        MSG_ServerStatus msg = new MSG_ServerStatus();
        msg.setHeader(newHeader());

        // and a body with the request
        Body body = new Body();
        ServerStatus data = new ServerStatus();
        data.setStatus("Operational");
        data.setDetails("We are really enjoying ourselfs here");
        body.setServerStatus(data);
        msg.setBody(body);

        // output the message
        Log.print(Log.STACK, "Handler.sendSeverStatus Sending: "+msg.toXML());
        out.println(msg.toXML());
        out.flush();
    };

    /**************************************************************************/
    public void sendMSGVesselData(VesselData obj) {

        // create a message
        MSG_VesselData msg = new MSG_VesselData();
        msg.setHeader(newHeader());

        // and a body with the request
        Body body = new Body();
        body.addVesselData(obj);
        msg.setBody(body);

        // output the message
        Log.print(Log.STACK, "Handler.sendMSGVesselData Sending: "+msg.toXML());
        out.println(msg.toXML());
        out.flush();
    };

    /**************************************************************************/
    public void startSendingMovements() {

        Log.print(Log.DEBUG, "Handler.startSendingMovements");

        while (!exit) {  // keep repeating until the other side disconnects

            Vector movements = (Vector)userData.get("Movements");
            if ((movements == null) || (movements.size() == 0)) {
                Log.print(Log.DEBUG, "Handler.startSendingMovements NO movements available");
                return;
            }

            // send first movement, store update time
            VesselData vessel = (VesselData) movements.remove(0);
            long updateTime = vessel.getPosReport().getUpdateTime().getTime();
            sendMSGVesselData(vessel);

            // get next movement, wait for this update time - previous update time
            while ((movements.size() > 0) && (!exit)) {
                vessel = (VesselData) movements.remove(0);

                long nextUpdateTime = vessel.getPosReport().getUpdateTime().getTime();
                long delta = nextUpdateTime - updateTime;

                if (delta > 0) {
                    Log.print(Log.DEBUG, "Handler.startSendingMovements sleeping for " + delta + " ms");
                    try {
                        Thread.sleep(delta);
                    } catch (Exception e) {
                        Log.print(Log.WARNING, "Handler.startSendingMovements sleep interrupted" +  e);
                    }
                }

                // send movement
                sendMSGVesselData(vessel);
                updateTime = nextUpdateTime;
            }
            // we are done, repeat the scenario
            Log.print(Log.DEBUG, "Handler.startSendingMovements repeating scenario");
        }
    };
}
