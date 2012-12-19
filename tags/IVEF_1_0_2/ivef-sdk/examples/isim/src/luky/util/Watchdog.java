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
package luky.util;


import java.util.*;
import java.io.*;
import java.net.*;
import luky.util.*;
import luky.events.*;


/******************************************************************************
 *
 * The Watchdog class extends the TimerTask class and is created to make a
 * periodic request of a certain routine by sending events<p>Usage:<br>
 * <code><pre>
 // run in seperate thread
 Timer poller = new Timer(true); 

 // start after 1 minute
 poller.scheduleAtFixedRate(new Watchdog(this), 60 * 1000,
 periodicSync * 1000);
 </pre></code>
 *  <ul>
 *   <li> 1.0.0 - initial version </li>
 * </ul>
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.0.0
 ******************************************************************************/
public class Watchdog extends TimerTask {
    	
    protected javax.swing.event.EventListenerList listenerList = new javax.swing.event.EventListenerList();
    private MyEvent evt = new MyEvent(this);

    /**************************************************************************
     * constructor
     **************************************************************************/
    public Watchdog(MyEventListener target) {

        super();
        addMyEventListener(target);
    }

    /**************************************************************************
     * execute the timeing action
     **************************************************************************/
    public void run() {
        Log.print(Log.STACK, "Watchdog.run firing event");
        fireMyEvent(evt);	
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
     * This methods is used to fire MyEvents
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
}

