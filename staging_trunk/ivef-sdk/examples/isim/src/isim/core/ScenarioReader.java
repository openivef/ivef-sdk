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

    public void handleMSG_IVEF(MSG_IVEF obj) {
        Body body = obj.getBody();
        if ( body.hasObjectDatas() ) {
            for (int i=0; i < body.getObjectDatas().countOfObjectDatas();i++) {

                ObjectData vessel = body.getObjectDatas().getObjectDataAt(i);
                movements.add(vessel);
            }
        }
    };
}
