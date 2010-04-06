/******************************************************************************
 *   Copyright (C) 2010 Chris Lukassen
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 ******************************************************************************/

package testjava;

import java.io.*;
import java.util.*;
import ivef.*;


/***************************************************************************
 * testjava is a simple test program for the ivef library
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.0.0
 ******************************************************************************/

public class testjava {
    
    
    /**************************************************************************
     * constructor, used to initialize libraries
     **************************************************************************/
    public void testjava() {
        
    }
    
    /**************************************************************************
     * main routine, pass the arguments of the server here,
     * @param args the arguments that were used to start the server
     **************************************************************************/
    public static void main(String args[]) {
        
        try {
            // Open the file
            DataInputStream in = new DataInputStream(System.in);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));
            
            String strLine;
            Handler dumpToScreen = new Handler();
            ivef.Parser parser = new ivef.Parser(dumpToScreen);

            System.out.println("TestJava ready for input");

            //Read File Line By Line
            while ((strLine = br.readLine()) != null)   {
                //System.out.println (strLine);
                if (!strLine.equals("<xml>\n")) {   // ilisten makes logfiles that start with <xml> but do not end with it
                    parser.parseXMLString(strLine, true);
                }
            }
            
            //Close the input stream
            in.close();
        } catch (Exception e) {//Catch exception if any
            System.out.println ("testjava.main Error: " + e.getMessage());
        }
        System.out.println("TestJava shutting down");
    }
}
