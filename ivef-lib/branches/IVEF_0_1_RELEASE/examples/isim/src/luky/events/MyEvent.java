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
 * The My Event Class is a class that holds all logic that's required
 * for synchronizing access and execution of threads using events
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class MyEvent extends EventObject {

    private Object eventData = null;
    private final static long serialVersionUID = 42L;

    public MyEvent(Object source) {
        super(source);
    }

    public Object getEventData() {	
        return eventData;
    }	

    public void setEventData(Object data) {	
        eventData = data;
    }	
}

