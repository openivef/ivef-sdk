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
package luky.linux;


import java.io.*;
import java.net.*;
import java.awt.*;
import java.util.*;
import luky.util.*;
import luky.events.*;


/******************************************************************************
 * This class tails to a file and pass the contents to a manageble buffer <p>
 * Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class FileTail extends MyEventManager implements Runnable {

    private int maxSize = 100;
    private LinkedList lines = new LinkedList();
    private String fileName = null;
    private boolean running = true;

    /**************************************************************************
     * default constructor
     * @param name the file to be tailed
     **************************************************************************/
    public FileTail(String name) {
        this.fileName = name;
    }

    /**************************************************************************
     * Alternative constructor
     * @param name the file to be tailed
     * @param maxSize number of lines kept online
     **************************************************************************/
    public FileTail(int maxSize, String name) {
        this.fileName = name;
        this.maxSize = maxSize;
    }

    /**************************************************************************
     * stop tailing the file
     **************************************************************************/
    public void stop() {
        running = false;
    }

    /**************************************************************************
     * get lines, returns the last lines (maxSize)
     **************************************************************************/
    public LinkedList getLines() {
        return lines;
    }

    /**************************************************************************
     * Start tailing the file
     *************************************************************************/
    public void run() {

        BufferedReader in;

        try {
            in = new BufferedReader(new FileReader(fileName));
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "FileTail.run file: " + fileName + " open failed: "
                    + e.toString());
            return;
        }

        Log.print(Log.DEBUG, "FileTail.run tailing to file: " + fileName);

        running = true;
        String line;

        while (running) {
            try {
                line = in.readLine();
                if (line != null) {
                    // store the result
                    lines.addFirst(line);
                    Log.print(Log.STACK,
                            "FileTail.run got line: " + line + " to file: "
                            + fileName);
                    if (lines.size() > maxSize) {
                        lines.removeLast();
                    }

                    // and fire the event
                    MyEvent evt = new MyEvent(this);

                    evt.setEventData((Object) line);
                    fireMyEvent(evt);
                } else {
                    try {
                        // try again in 500 ms
                        Thread.sleep(500);
                    } catch (Exception e) {
                        Log.print(Log.FATAL,
                                "FileTail.run file: " + fileName
                                + " sleep failed: " + e.toString());
                    }
                }
            } catch (Exception e) {
                Log.print(Log.FATAL,
                        "FileTail.run file: " + fileName + " io error: "
                        + e.toString());
            }
        }
    }

}
