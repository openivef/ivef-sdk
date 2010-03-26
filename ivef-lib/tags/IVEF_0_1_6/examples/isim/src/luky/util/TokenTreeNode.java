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
import java.awt.*;
import javax.swing.*;


public class TokenTreeNode {

    private String name;
    private String token;
    private Hashtable data = new Hashtable();

    public TokenTreeNode(String name, String token) {
	
        this.name = name;
        this.token = token;
    }
    ;

    public String getToken() {
        return token;
    }	

    public Object getUserData(String name) {
        return data.get(name);
    }	

    public void putUserData(String name, Object value) {
        data.put(name, value);
    }	

    public String toString() {
        return name;
    }	

    public ImageIcon getIcon(boolean bSelected, boolean bExpanded, boolean bLeaf, boolean bHasFocus) {
		
        // currently we support only 3 icons
        // leaf, expanded or not
        if (bLeaf) {
            return (ImageIcon) getUserData("icon-leaf");
        } else if (bExpanded) {
            return (ImageIcon) getUserData("icon-open");
        } else {
            return (ImageIcon) getUserData("icon-closed");
        }
    }

} 
