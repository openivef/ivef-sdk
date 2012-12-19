/******************************************************************************
 *   Copyright (C) 2010 Chris Lukassen
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
package testjava;


import java.util.*;
import java.io.*;
import ivef.*;

/******************************************************************************
 * The Handler class handles an IVEF listener <br>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.0.0
 ******************************************************************************/
public class Handler implements ivef.ParserListener {

    /**************************************************************************/
    public void printMessage(String text, String XML) {
        System.out.print(text);
        System.out.println(XML);
    }
    
    /**************************************************************************/
    public void handleMSG_IVEF(MSG_IVEF obj) {
        printMessage(obj.toString(""), obj.toXML());
    };
}
