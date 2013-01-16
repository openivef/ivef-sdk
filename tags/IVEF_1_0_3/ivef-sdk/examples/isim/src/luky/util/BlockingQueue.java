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
import luky.util.*;


/******************************************************************************
 * BlockingQueue is used to coordinate work between a producer and consumer
 * threads. The producer adds elements to the queue containing information
 * The consumer threads remove objects from the queue, if the queue is empty
 * the thread will block until a new object is added to the queue.
 *
 * Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *   <li> 1.01 - synchronized list access</li>
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.01
 ******************************************************************************/
public class BlockingQueue {

    protected List queue = Collections.synchronizedList(new LinkedList());

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public BlockingQueue() {// nothing
    }

    /**************************************************************************
     * clear the queue and add an element to the queue
     **************************************************************************/
    public synchronized void clearAndAdd(Object o) {
        queue.clear();
        queue.add(o); // at the end
        notify();
    }

    /**************************************************************************
     * add an element to the queue (equals add, but for left for compatibilty)
     **************************************************************************/
    public synchronized void addLast(Object o) {
        add(o);
    }

    /**************************************************************************
     * add an element to the queue
     **************************************************************************/
    public synchronized void add(Object o) {
        Log.print(Log.DEBUG, "BlockingQueue.add adding: " + o.toString());
        queue.add(o);
        notify();
    }

    /**************************************************************************
     * Peeks a the first element, but leaves it in the queue
     **************************************************************************/
    public synchronized Object peekFirst() {
        if (queue.isEmpty()) {
            return null;
        } else {
            return queue.get(0);
        }
    }

    /**************************************************************************
     * get the first element from the queue (equals get, but for left for compatibilty)
     * @deprecated will be replaced by remove in the future
     **************************************************************************/
    public synchronized Object getFirst() {
        return get();
    }

    /**************************************************************************
     * get an element from the queue (and remove it from the queue)
     * @deprecated will be replaced by remove in the future, get will become peekFirst!
     **************************************************************************/
    public synchronized Object get() {
        return remove();
    }

    /**************************************************************************
     * get the first element from the queue (and remove it from the queue)
     **************************************************************************/
    public synchronized Object remove() {

        Log.print(Log.DEBUG, "BlockingQueue.get trying to get object");

        // main loop to protect against exceptions
        while (queue.isEmpty()) {
            try {
                // normal loop
                while (queue.isEmpty()) {
                    wait();
                }
            } catch (Exception e) {
                Log.print(Log.FATAL, "BlockingQueue: get interrupt exception");
            }
        }

        Object o = queue.remove(0); // first object

        if (o == null) {
            Log.print(Log.DEBUG, "BlockingQueue.get got no object");
        } else {
            Log.print(Log.DEBUG, "BlockingQueue.get got object: " + o.toString());
        }

        return o;
    }
}
