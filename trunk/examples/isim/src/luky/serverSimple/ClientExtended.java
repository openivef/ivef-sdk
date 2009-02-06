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
import luky.events.*;
import luky.serverSimple.*;


/******************************************************************************
 * The ClientExtended class extends the Client class and is created to make a
 * general listner for servers which communicates with MyEventListners
 *  Revision Changes : <br>
 *  <ul>
 *   <li> ver 1.00 initial version </li>
 *   <li> ver 1.01 added watchdog</li>
 *   <li> ver 1.02 fixed multithreaded problem</li>
 * </ul>
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.02
 ******************************************************************************/
public class ClientExtended extends luky.serverSimple.Client implements Runnable, MyEventListener {
    	
    protected String name = "ClientExtended";
    private Thread kick = null;
    protected javax.swing.event.EventListenerList listenerList = new javax.swing.event.EventListenerList();
    protected static final int IDLE = 0;
    protected static final int STARTING = 1;
    protected static final int RUNNING = 2;
    protected static final int RECONNECTING = 3;
    protected static final int STOPPING = 4;
    protected int status = IDLE;

    /**************************************************************************
     * constructor, takes ip number and portnumber of the server to connect to
     * and the watchdog interval < 0 means disable
     **************************************************************************/
    public ClientExtended(String ip, String port, int interval) {

        super(ip, port);

        if (interval > 0) {
            Log.print(Log.DEBUG,
                    "ClientExtended.constructor setting watchdog to "
                    + interval * 1000 + " ms");
            // run in seperate thread
            Timer poller = new Timer(true); 

            // start after 1 minute
            poller.scheduleAtFixedRate(new Watchdog(this), 60 * 1000,
                    interval * 1000);
        }
    }

    /**************************************************************************
     * This methods allows classes to register for MyEvents
     **************************************************************************/
    public void addMyEventListener(MyEventListener listener) {
        listenerList.add(MyEventListener.class, listener);
    }

    /**************************************************************************
     *  This methods allows classes to unregister for MyEvents
     **************************************************************************/
    public void removeMyEventListener(MyEventListener listener) {
        listenerList.remove(MyEventListener.class, listener);
    }

    /**************************************************************************
     *  This method is used to fire MyEvents
     **************************************************************************/
    protected void fireMyEvent(MyEvent evt) {
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
     * This method gets called by the Watchdog 
     **************************************************************************/
    public void myEventOccurred(MyEvent evt) {

        if (status == RECONNECTING) {
            Log.print(Log.DEBUG,
                    "ClientExtended.myEventOccured test connection " + name
                    + " skipped");
            return;
        }

        if (evt.getSource() instanceof Watchdog) {
            try {
                Log.print(Log.DEBUG,
                        "ClientExtended.myEventOccured test connection " + name);
		       
                // test the connection
                writer.println("HELLO");
                if (writer.checkError()) {
                    Log.print(Log.WARNING,
                            "ClientExtended.myEventOccured test connection "
                            + name + " NOK");
                    handleCommError();
                    return;
                } 
            } catch (Exception e) {
                Log.print(Log.WARNING,
                        "ClientExtended.myEventOccured test connection " + name
                        + " NOK");
                handleCommError();
            }

        } else {
            Log.print(Log.FATAL,
                    "ClientExtended.myEventOccurred unknown event source: "
                    + evt.getSource().toString());
            return;
        }
    }

    /**************************************************************************
     *  This method starts the client in a seperate thread
     **************************************************************************/
    public void start() {

        if (status != IDLE) {
            Log.print(Log.MESSAGE,
                    "ClientExtended.start cannot start, status is not IDLE");
            return;
        }

        if (kick == null) {
            status = STARTING;
            Log.print(Log.DEBUG, "ClientExtended.start thread");
            kick = new Thread(this);
            kick.setPriority(Thread.MIN_PRIORITY);
            kick.start();
        }
    }
    
    /**************************************************************************
     *  This method stops the client
     **************************************************************************/
    public synchronized void stop() {

        // IDLE, STARTING, RUNNING, RECONNECTING, STOPPING 
        if ((status != RUNNING) && (status != RECONNECTING)) {
            Log.print(Log.MESSAGE,
                    "ClientExtended.stop cannot stop, status is not RUNNING");
            return;
        }

        // close any connections if we have them
        getLine("CLOSE");

        if (kick != null) {
            status = STOPPING;
            kick = null;
        }
    }

    /**************************************************************************
     *  comm error occured re-initialize and report to listners
     **************************************************************************/
    public int handleCommError() {

        // IDLE, STARTING, RUNNING, RECONNECTING, STOPPING 
        if ((status == IDLE) || (status == STOPPING)) {
            Log.print(Log.MESSAGE,
                    "ClientExtended.handleCommError cannot, status is IDLE or STOPPING");
            return Constants.NOK;
        }

        status = RECONNECTING;

        Log.print(Log.FATAL, "ClientExtended.handleCommError entered");
        // report the comm error
        MyEventExtended evt = new MyEventExtended(this);

        evt.putEventData("comm-error", (Object) name);
        fireMyEvent((MyEvent) evt);

        // try to reinitialize the connection
        try {
            kick.sleep(3000); // wait three seconds
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "ClientExtended.handleCommError sleep interrupted");
            return Constants.NOK;
        }

        Log.print(Log.WARNING,
                "ClientExtended.handleCommError attemting to reconnect");

        if (openConnection() == Constants.NOK) {
            return Constants.NOK;
        } else {// yes, resurrected
            // the caller of this routine should setup the connection and 
            // adjust the status accordingly
        }
        return Constants.OK;
    }

    /**************************************************************************
     * main loop of the client, override with more sensible actions <br>
     * currently listens to input and fires each line as an event <br>
     **************************************************************************/
    public void run() {

        if (!connected) {
            if (openConnection() == Constants.NOK) {
                return;
            }
        }

        status = RUNNING;
        while (status == RUNNING) {
            try {
                String input;

                while (status == RUNNING) {
                    // keep reading status changes
                    input = reader.readLine();
                    Log.print(Log.DEBUG,
                            "ClientExtended.run status changes received: "
                            + input);
                    if (input != null) {
                        // filter out the watchdog messages
                        if (input.equals("HI.")) {
                            Log.print(Log.STACK,
                                    "ClientExtended.run received HI. message, connection: "
                                    + name + " = OK");
                        } else {
                            // normal reply received
                            MyEvent evt = new MyEvent(this);

                            evt.setEventData((Object) input);
                            fireMyEvent(evt);
                        }
                    } else { 
                        Log.print(Log.DEBUG,
                                "ClientExtended.run status connection must have closed");
                        if (handleCommError() == Constants.NOK) {
                            // give up
                            status = STOPPING;
                        } else {
                            // resurrected
                            status = RUNNING;
                        }
                    }
                }
            } catch (Exception e) {
                Log.print(Log.FATAL,
                        "ClientExtended.run Exception occured: " + e.toString());
                e.printStackTrace();	
                if (handleCommError() == Constants.NOK) {
                    // give up
                    status = STOPPING;
                } else {
                    // resurrected
                    status = RUNNING;
                }
            }
        }

        // end of run loop
        status = IDLE;
        Log.print(Log.DEBUG, "ClientExtended.run done");

        return; 
    }
}
