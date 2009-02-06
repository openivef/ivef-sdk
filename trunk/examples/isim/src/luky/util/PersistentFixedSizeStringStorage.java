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


/******************************************************************************
 * A linked list of fixed size. Adding an element beyond the size will cause
 * the deletion of the oldest element. The contents is persistant by use 
 * of circulair files <p>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *   <li> 1.01 - closing files, memory leak </li>
 * </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.01
 **************************************************************************/
public class PersistentFixedSizeStringStorage extends FixedSizeStringStorage {
    private String oldestItemsFileName = "/tmp/PersistentFixedSizeStringStorage1.log";
    private String newestItemsFileName = "/tmp/PersistentFixedSizeStringStorage2.log";
    private int linesLogged = 0;
    private PrintWriter out = null;
	
    /******************************************************************************
     * Constructor size must be 1 or greater
     **************************************************************************/
    public PersistentFixedSizeStringStorage(int size, String oldestItemsFile, String newestItemsFile) {

        // initialize the list
        super(size);

        // get the file names
        if (oldestItemsFile != null) {
            oldestItemsFileName = oldestItemsFile;
        }
        if (newestItemsFile != null) {
            newestItemsFileName = newestItemsFile;
        }

        // read the oldestItems file
        Log.print(Log.DEBUG,
                "PersistentFixedSizeStringStorage.constructor try "
                + oldestItemsFileName);
        int linesOldestItems = addFileToList(oldestItemsFileName);

        // read the newestItems file
        Log.print(Log.DEBUG,
                "PersistentFixedSizeStringStorage.constructor try "
                + newestItemsFileName);
        int linesNewestItems = addFileToList(newestItemsFileName);
	
        // situations: 
        // - no files (first time) -> start logging in newest
        // - only a newest -> continue log in newest
        // - only a oldest (strange !) -> move to newest and append
        // - both files (normal) -> continue log in newest
        if ((linesOldestItems > 0) && (linesNewestItems <= 0)) {
            // move files
            File src = new File(oldestItemsFileName);
            File dst = new File(newestItemsFileName);

            Log.print(Log.WARNING,
                    "PersistentFixedSizeStringStorage.constructor making old log new ! ");
            try {
                Toolbox.copy(src, dst);
            } catch (Exception e) {
                Log.print(Log.FATAL,
                        "PersistentFixedSizeStringStorage ERROR copying :"
                        + oldestItemsFileName + " to " + newestItemsFileName
                        + " (" + e.toString() + ")");	
            }
            linesNewestItems = linesOldestItems;
        }

        // open and append to file		
        if (linesNewestItems > 0) { // apped to existing lines
            linesLogged = linesNewestItems;
        }

        // try to open the output, always append existing files
        try {
            Log.print(Log.DEBUG,
                    "PersistentFixedSizeStringStorage.constructor appending to: "
                    + newestItemsFileName);
            if (out != null) {
                out.close();
            }
            out = new PrintWriter(
                    new BufferedWriter(new FileWriter(newestItemsFileName, true)));
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PersistentFixedSizeStringStorage.constructor cannot open file "
                    + newestItemsFileName);
            if (out != null) {
                out.close();
            }
            out = null; // serious trouble
        }
        return;
    }

    /******************************************************************************
     * replaces the superclass add function
     **************************************************************************/
    private void addLineToList(String line) {
        super.add(line);
    }

    /******************************************************************************
     * reads a file and puts it in the buffer, returns the number of lines read
     * or -1 on error
     **************************************************************************/
    private int addFileToList(String fileName) {

        String line = "";
        BufferedReader in = null;
        int lineCount = 0;

        // see if it can be opened
        try {
            in = new BufferedReader(new FileReader(fileName));
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "PersistentFixedSizeStringStorage.addFileToList cannot open file "
                    + fileName);
            return -1;
        }

        // try to read it
        try {
            while (in.ready()) {
                line = in.readLine();
                addLineToList(line);		
                lineCount += 1;
			
            }
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PersistentFixedSizeStringStorage.addFileToList error reading file "
                    + fileName);
            return -1;
        }

        // try to close it
        try {
            in.close();
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "PersistentFixedSizeStringStorage.addFileToList cannot close file "
                    + fileName);
            return -1;
        }

        Log.print(Log.DEBUG,
                "PersistentFixedSizeStringStorage.addFileToList " + lineCount
                + " lines of history read from " + fileName);
        return lineCount;
    }

    /***************************************************************************
     * writes the properties to the file specified by fileName
     * @param fileName the name of the file from to which the settings are written
     * @return OK or NOK
     **************************************************************************/
    private void storeLine(String line) {
        Log.print(Log.DEBUG,
                "PersistentFixedSizeStringStorage.storeLine: " + line);

        // try to write it
        try {
            out.println(line);
            out.flush();
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PersistentFixedSizeStringStorage.storeLine error writing file "
                    + newestItemsFileName);
            return;
        }

        // done another one, check for file rollover
        Log.print(Log.STACK,
                "PersistentFixedSizeStringStorage.storeLine:" + line
                + ",  written to " + newestItemsFileName);
        linesLogged += 1;
        if (linesLogged < maxSize) {
            return;
        }

        // we have reached maxSize lines. Close this file, move
        // it to oldestItems, and reopen the file
        Log.print(Log.MESSAGE,
                "PersistentFixedSizeStringStorage.storeLine: file full ("
                + maxSize + ") swapping files");
        try {
            out.close();
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "PersistentFixedSizeStringStorage.storeLine cannot close file "
                    + newestItemsFileName);
            return;
        }

        // move
        File src = new File(newestItemsFileName);
        File dst = new File(oldestItemsFileName);

        try {
            Toolbox.copy(src, dst);
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PersistentFixedSizeStringStorage.storeLine ERROR copying :"
                    + newestItemsFileName + " to " + oldestItemsFileName + " ("
                    + e.toString() + ")");	
        }

        linesLogged = 0;

        // try to open the output, don't append (overwrite old file)
        Log.print(Log.DEBUG,
                "PersistentFixedSizeStringStorage.storeLine reopening file");

        try {
            out = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter(newestItemsFileName, false)));
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PersistentFixedSizeStringStorage.storeLine cannot open file "
                    + newestItemsFileName);
            out = null; // serious trouble
        }

        return;
    }

    /******************************************************************************
     * adds an element to the list
     **************************************************************************/
    public void add(String line) {
        super.add(line);
        storeLine(line);
    }

}
