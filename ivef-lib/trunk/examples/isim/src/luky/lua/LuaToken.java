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


import luky.util.*;
import java.util.*;


/******************************************************************************
 * This class is a data holder for lua data <br><code>
 * token:      ( NAME = ( COLLECTION | VALUE ) | DATA | COLLECTION ) , <br> </code>
 *  Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *  </ul>
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.00
 ******************************************************************************/
public class LuaToken {

    /**************************************************************************
     * variables
     **************************************************************************/
    protected String name = null;
    private LuaCollection collection = null;
    private String value = null;
    private String data = null;
    public boolean isValue = false;
    public boolean isCollection = false;
    public boolean isData = false;

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public LuaToken() {}

    /***************************************************************************/
    public void setValue(String value) {
        Log.print(Log.MESSAGE,
                "LuaToken.setValue (" + name + ") entered with [" + value + "]");
        this.value = value;
        isValue = true;
        isCollection = false;
        isData = false;
    }

     /***************************************************************************/
    public void setData(String data) {
        Log.print(Log.MESSAGE,
                "LuaToken.setData (cannot have name) entered with [" + data
                + "]");
        this.data = data;
        isValue = false;
        isCollection = false;
        isData = true;
    }

     /***************************************************************************/
    public void setCollection(LuaCollection collection) {
        Log.print(Log.MESSAGE,
                "LuaToken.setCollection (" + name + ") entered with ["
                + collection + "]");
        this.collection = collection;
        isValue = false;
        isCollection = true;
        isData = false;
    }

     /***************************************************************************/
    public void setName(String value) {
        Log.print(Log.MESSAGE, "LuaToken.setName (" + value + ") entered");
        name = value;
    }

     /***************************************************************************/
    public String getName() {
        Log.print(Log.MESSAGE, "LuaToken.getName (" + name + ") entered");
        if (isData) {
            return null;
        }
        return name;
    }

     /***************************************************************************/
    public String getData() {
        Log.print(Log.MESSAGE, "LuaToken.getData (" + name + ") entered");
        if (isData) {
            return data;
        }
        return null;
    }

     /***************************************************************************/
    public String getValue() {
        Log.print(Log.MESSAGE, "LuaToken.getValue (" + name + ") entered");
        if (isValue) {
            return value;
        }
        return null;
    }

     /***************************************************************************/
    public LuaCollection getCollection() {
        Log.print(Log.MESSAGE, "LuaToken.getCollection (" + name + ") entered");
        if (isCollection) {
            return collection;
        }
        return null;
    }

}
