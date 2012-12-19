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
package luky.events;


import java.util.*;


/******************************************************************************
 * The MyEventExtended is a class that extends the logic 
 * for synchronizing access and execution of threads using events, by suplying
 * more information than normal events
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.00
 ******************************************************************************/
public class MyEventExtended extends MyEvent {

    private Hashtable store = null;
    // Java 1.5 compatibility
    private final static long serialVersionUID = 42L;

    public MyEventExtended(Object source) {
        super(source);
        store = new Hashtable();
        setEventData((Object) store);
    }

    public Object getEventData(String name) {	
        return store.get(name);
    }	

    public void putEventData(String name, Object data) {	
        store.put(name, data);
    }	
}

