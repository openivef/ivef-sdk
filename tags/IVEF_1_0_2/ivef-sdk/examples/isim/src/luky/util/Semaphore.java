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


/******************************************************************************
 * The Sempaphore Class is a class that holds all logic that's required
 * for synchronizing access and execution of threads with counting sems
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class Semaphore {

    private long    timeout;
    private int     status = 0;

    /**************************************************************************
     * constructor for a blocking semaphore (no timeout)
     **************************************************************************/
    public Semaphore() {
        // timeout 0 is no timeout
        this(0);
    }

    /**************************************************************************
     * timed constructor
     * @param timeout long value specifying the timeout value in milli seconds
     **************************************************************************/
    public Semaphore(long timeout) {
        this.timeout = timeout;
    }

    /**************************************************************************
     * timed constructor
     * @param timeout string value specifying the timeout value in milli seconds
     **************************************************************************/
    public Semaphore(String timeout) {
        try {
            this.timeout = Integer.parseInt(timeout);
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "Semaphore.constructor "
                    + "this is no number, defaulting to 0");
            this.timeout = 0;
        }
    }

    /**************************************************************************
     * sets the timeout value for this semaphore, blocked threads will not
     * be affected
     * @param timeout long value specifying the timeout value in milli seconds
     * @return Constants.NOK in case the timeout value is illegal or Constants.OK
     * in case the value was accepted
     **************************************************************************/
    public synchronized int setTimeoutValue(long timeout) {
        // timeout in milliseconds, 0 is no timeout
        if (timeout >= 0) {
            this.timeout = timeout;
            return(Constants.OK);
        } else {
            return(Constants.NOK);
        }
    }

    /**************************************************************************
     * returns the timeout value for this semaphore
     * @return the current timeout value
     **************************************************************************/
    public synchronized long getTimeoutValue() {
        return(timeout);
    }

    /**************************************************************************
     * takes the current semaphore, in case the semaphore is not available the
     * method will 'hang' until a semaphore is set or a timeout occurs
     * @return Constants.NOK in case an the wait method was interupted, Constants.OK
     * in case the semaphore has been taken succesfully or Constants.TIMEOUT
     * in case a timeout has occured
     **************************************************************************/
    public synchronized int getSem() {

        if (status > 0) {
            status -= 1;
            return(Constants.OK);
        } else {
            try {
                wait(timeout);
            } catch (Exception e) {
                return(Constants.NOK);
            }
        }

        if (status == 0) {
            return(Constants.TIMEOUT);
        } else {
            status -= 1;
            return(Constants.OK);
        }
    }

    /**************************************************************************
     * sets the current semaphore, in case a different thread was 'hanging' on
     * this thread will be released
     * @return Constants.NOK in case the semaphore had already been set,
     * Constants.OK if all went well
     **************************************************************************/
    public synchronized int setSem() {
        if (status == 0) {
            notify();
        }
        status += 1;
        return(Constants.OK);
    }
}
