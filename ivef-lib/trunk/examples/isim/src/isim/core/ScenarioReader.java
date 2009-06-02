/******************************************************************************
 *   Copyright (C) 2005 Chris Lukassen
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

package isim.core;

import java.util.*;
import ivef.*;


public class ScenarioReader implements ParserListener {

    /***************************************************************************
     variables
     ***************************************************************************/
    private Vector movements = null;

    /**************************************************************************
     * constructor, used to initialize libraries
     **************************************************************************/
    public ScenarioReader() {
        movements = new Vector();
    }

    public Vector getMovements () {
        return movements;
    }

    public void handleMSG_VesselData(MSG_VesselData obj) {
        Body body = obj.getBody();
        for (int i=0; i < body.countOfVesselDatas();i++) {

            VesselData vessel = body.getVesselDataAt(i);
            movements.add(vessel);
        }
    };
    public void handleMSG_LoginRequest(MSG_LoginRequest obj) {};
    public void handleMSG_LoginResponse(MSG_LoginResponse obj) {};
    public void handleMSG_Ping(MSG_Ping obj) {};
    public void handleMSG_Pong(MSG_Pong obj) {};
    public void handleMSG_ServerStatus(MSG_ServerStatus obj) {};
    public void handleMSG_Logout(MSG_Logout obj) {};
    public void handleMSG_ServiceRequest(MSG_ServiceRequest obj) {};

}
