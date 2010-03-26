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
import javax.swing.tree.*;


/******************************************************************************
 * extends a the default tree with some handy new options
 * used to convert tokend strings to trees e.g. /xx/yy/zz
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 **************************************************************************/
public class TokenTree extends DefaultMutableTreeNode {
    // Java 1.5 compatibility
    private final static long serialVersionUID = 42L;

    /******************************************************************************
     * Constructor
     **************************************************************************/
    public TokenTree(Object token) {
        super(token);
    }

    /******************************************************************************
     * adds a user datafield to the object
     **************************************************************************/
    public void putUserData(String name, Object value) {
        ((TokenTreeNode) this.getUserObject()).putUserData(name, value);
    }

    /******************************************************************************
     * gets a user datafield 
     **************************************************************************/
    public Object getUserData(String name) {
        return ((TokenTreeNode) this.getUserObject()).getUserData(name);
    }

    /******************************************************************************
     * adds a tokenized string to the tree
     * @deprecated replaced by put will be removed in the future
     **************************************************************************/
    public int putToken(String token) {
        return putToken(token, token);
    }
	
    /******************************************************************************
     * remove a tokenized item from the tree
     **************************************************************************/
    public TokenTree remove(String token) {
        return removeToken(token, token);
    }
	
    /******************************************************************************
     * adds a tokenized string to the tree
     **************************************************************************/
    public int put(String token) {
        return putToken(token, token);
    }
	
    /******************************************************************************
     * removes a tokenized string 
     * will remove a from /b/c/a
     **************************************************************************/
    private TokenTree removeToken(String token, String fullToken) {

        String head = getHead(token);

        // returns "b" on first call returns "c" on second call
        if (head == null) {
            Log.print(Log.FATAL,
                    "TokenTree.removeToken string " + token + " failed");
            return null;
        }

        if (!(this.toString().equals(head))) { // i am not the head ?
            Log.print(Log.FATAL,
                    "TokenTree.removeToken string " + token + " does not fit "
                    + this.toString());
            return null;
        }

        // returns "/c/a" on first call returns "/a" on second call
        String remainder = cutHead(token, "/" + head); // what do we need to remove

        if (remainder.length() == 0) {
            Log.print(Log.FATAL,
                    "TokenTree.removeToken " + token
                    + " failed cannot remove myself");
            return null;
        } 		  

        // returns "c" on first call, returns "a" on second
        head = getHead(remainder); // get new head	

        if (("/" + head).length() == remainder.length()) {
            // we are at the right depth, the child should be here
            for (int i = 0; i < this.getChildCount(); i++) {
                if (this.getChildAt(i).toString().equals(head)) { // found child node
                    TokenTree child = (TokenTree) this.getChildAt(i);

                    remove(child);	
                    return child;
                }  
            }
		
            Log.print(Log.FATAL,
                    "TokenTree.removeToken " + token
                    + " failed cannot find child at final level " + head);
            return null;
        } else {
            // look for the next depth in my children
            for (int i = 0; i < this.getChildCount(); i++) {
                if (this.getChildAt(i).toString().equals(head)) { // found child node
                    return ((TokenTree) this.getChildAt(i)).removeToken(
                            remainder, fullToken);
                }  // remove the remainder
            }
		
            Log.print(Log.FATAL,
                    "TokenTree.removeToken " + token
                    + " failed cannot find child " + head);
            return null;
        }	

    }

    /******************************************************************************
     * adds a tokenized string to the tree
     **************************************************************************/
    private int putToken(String token, String fullToken) {

        String head = getHead(token);

        if (head == null) {
            Log.print(Log.FATAL,
                    "TokenTree.putToken string " + token + " failed");
            return Constants.NOK;
        }

        if (!(this.toString().equals(head))) { // i am not the head ?
            Log.print(Log.FATAL,
                    "TokenTree.putToken string " + token + " does not fit "
                    + this.toString());
            return Constants.NOK;
        }

        String remainder = cutHead(token, "/" + head); // what do we need to put

        if (remainder.length() == 0) {
            return Constants.OK;
        } 		  // root node always exists

        head = getHead(remainder); // get new head	
        for (int i = 0; i < this.getChildCount(); i++) {
            if (this.getChildAt(i).toString().equals(head)) { // found child node
                return ((TokenTree) this.getChildAt(i)).putToken(remainder,
                        fullToken);
            }  // put the remainder
        }
	
        // child not found, lets make it	
        TokenTree child = new TokenTree(new TokenTreeNode(head, fullToken));

        this.add(child);			
        return child.putToken(remainder);
    }

    /**************************************************************************
     * get a node indexed by the token
     **************************************************************************/
    public TokenTree get(String token) {

        String head = getHead(token);

        if (head == null) {
            Log.print(Log.FATAL, "TokenTree.get string " + token + " failed");
            return null;
        }

        if (!(this.toString().equals(head))) { // i am not the head ?
            Log.print(Log.FATAL,
                    "TokenTree.get string " + token + " does not fit "
                    + this.toString());
            return null;
        }

        String remainder = cutHead(token, "/" + head); // what do we need to get

        if (remainder.length() == 0) {
            return this;
        } 		  // it's me

        head = getHead(remainder); // get new head	
        for (int i = 0; i < this.getChildCount(); i++) {
            if (this.getChildAt(i).toString().equals(head)) { // found child node
                return ((TokenTree) this.getChildAt(i)).get(remainder);
            }  // get the remainder
        }
	
        // child not found, 
        return null;
    }

    /**************************************************************************
     * cut's the given head from a string 
     **************************************************************************/
    private String cutHead(String str, String head) {
	
        // sample : /cms/xxx/yyy, /cms should return /xxx/yyy
        if ((str.length() < 2) || (str.indexOf(head) != 0)) {
            // Log.print(Log.WARNING, "TokenTree.cutHead string "+str+" does not start with "+head);
            return str;
        }

        // it's there and at the start, so remove it	
        return str.substring(head.length(), str.length());
    }

    /**************************************************************************
     * return the head from a string as a tree node
     **************************************************************************/
    private String getHead(String str) {

        // sample /cms/xxx/yyy should return cms 
        if ((str.length() < 2) || (str.charAt(0) != '/')) {
            // Log.print(Log.WARNING, "TokenTree.getHead string "+str+" does not start with /");
            return null;
        }
        // cut the first char
        str = str.substring(1, str.length());
        // find end token
        int i = str.indexOf("/");

        if (i < 0) {
            // Log.print(Log.WARNING, "TokenTree.getHead string "+str+" does not has a  /");
            i = str.length(); // assume it is a /cms thing
        }
	
        // it's there and at the start, so remove it	
        return str.substring(0, i);
    }

}

