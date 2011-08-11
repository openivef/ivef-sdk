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
package luky.lua;


import java.util.*;
import luky.util.*;


/******************************************************************************
 * This class is a data holder for lua data<br><code
 * collection: { <TOKEN> } 						<br></code>
 *  Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *  </ul>
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.00
 ******************************************************************************/
public class LuaCollection {

    /**************************************************************************
     * constants
     **************************************************************************/

    /**************************************************************************
     * variables
     **************************************************************************/
    private Vector tokens = new Vector();
    private String name = null;

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public LuaCollection(String name) {
        this.name = name;
    }

    /***************************************************************************/
    public int getSize() {
        Log.print(Log.MESSAGE, "LuaCollection.getSize (" + name + ") entered");
        return tokens.size();
    }

     /***************************************************************************/
    public String getName() {
        Log.print(Log.MESSAGE, "LuaCollection.getName (" + name + ") entered");
        return name;
    }

     /***************************************************************************/
    public int findTokenIndex(LuaToken token) {
        Log.print(Log.MESSAGE,
                "LuaCollection.findToken from " + name + " entered");
        for (int i = 0; i < tokens.size(); i++) {
            if (token == tokens.get(i)) {
                return i;
            }	
        }
        return -1;
    }

     /***************************************************************************/
    public LuaToken findToken(LuaToken token) {
        int id = findTokenIndex(token);

        if (id < 0) {
            return null;
        }
        return getToken(id);
    }

     /***************************************************************************/
    public LuaToken findToken(String name) {
        int id = findTokenIndex(name);

        if (id < 0) {
            return null;
        }
        return getToken(id);
    }

     /***************************************************************************/
    public int findTokenIndex(String name) {
        Log.print(Log.MESSAGE,
                "LuaCollection.findToken from " + this.name + " entered with "
                + name);
        if (name == null) {
            return -1;
        }
        for (int i = 0; i < tokens.size(); i++) {
            String tokenName = ((LuaToken) tokens.get(i)).getName();

            if ((tokenName != null) && (name.equals(tokenName))) {
                return i;
            }	
        }
        return -1;
    }

     /***************************************************************************/
    public LuaToken getToken(int i) {
        Log.print(Log.MESSAGE,
                "LuaCollection.getToken (" + i + ") from " + name + " entered");
        if (i > tokens.size()) {
            Log.print(Log.FATAL,
                    "LuaCollection.getToken " + i + " > " + tokens.size());
        }
        return (LuaToken) tokens.get(i);
    }

     /***************************************************************************/
    public void addToken(LuaToken token) {
        Log.print(Log.MESSAGE,
                "LuaCollection.addToken (" + name + ") entered with [" + token
                + "]");
        tokens.add(token);
    }

     /***************************************************************************/
    public int removeToken(LuaToken token) {
        Log.print(Log.MESSAGE,
                "LuaCollection.removeToken (" + name + ") entered with ["
                + token + "]");
        int i = findTokenIndex(token);

        if (i < 0) {
            Log.print(Log.FATAL,
                    "LuaCollection.removeToken no such token " + token);
            return Constants.NOK;
        }
        tokens.remove(i);
        return Constants.OK;
    }

}
