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


/******************************************************************************
 * A linked list of fixed size. Adding an element beyond the size will cause
 * the deletion of the oldest element
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 **************************************************************************/
public class FixedSizeStringStorage {
    protected int maxSize = 0;
    protected Vector list = new Vector();
	
    /******************************************************************************
     * Constructor size must be 1 or greater
     **************************************************************************/
    public FixedSizeStringStorage(int size) {
        Log.print(Log.DEBUG, "FixedSizeStringStorage.constructor size " + size);
        if (size > 1) {
            maxSize = size;
        }	
    }

    /******************************************************************************
     * adds an element to the list
     **************************************************************************/
    public void add(String line) {
        Log.print(Log.DEBUG, "FixedSizeStringStorage.add : " + line);
        // a vector always adds to the end
        list.add(line);
        // remove the front if needed
        if (list.size() > maxSize) {
            Log.print(Log.DEBUG,
                    "FixedSizeStringStorage.add removeing last entry ");
            list.remove(0);
        }
    }

    /******************************************************************************
     * gets the list as an vector
     **************************************************************************/
    public Vector get() {
        return list;
    }
}
