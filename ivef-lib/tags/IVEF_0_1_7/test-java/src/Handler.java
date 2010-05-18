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
    public void handleMSG_VesselData(MSG_VesselData obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_LoginRequest(MSG_LoginRequest obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_LoginResponse(MSG_LoginResponse obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_Ping(MSG_Ping obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_Pong(MSG_Pong obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_ServerStatus(MSG_ServerStatus obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_Logout(MSG_Logout obj) {
        printMessage(obj.toString(""), obj.toXML());
    };

    /**************************************************************************/
    public void handleMSG_ServiceRequest(MSG_ServiceRequest obj) {
        printMessage(obj.toString(""), obj.toXML());
    };
}
