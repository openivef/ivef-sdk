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


import java.awt.*;


/******************************************************************************
 * This class is a data holder for the all the constants used by different classes
 * of the luky package. It's purpose is to let the different packages communicate
 * in a standarized way. Hence Constants.
 * Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *   <li> 1.01 - added return codes </li>
 *   <li> 1.02 - added payment type codes </li>
 *   <li> 1.03 - added backend error codes </li>
 *   <li> 2.00 - ported to luky</li>
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 2.00
 ******************************************************************************/
public class Constants {
    public final static int OK = 0;
    public final static int UNKNOWN = -1;
    public final static int MARGINAL = -2;
    public final static int TIMEOUT = -3;
    public final static int NOK = -4;
    public final static int EXCEPTION = -5;

    public final static Color GREEN = new java.awt.Color(0, 192, 0);
    public final static Color GREY = new java.awt.Color(192, 192, 192);
    public final static Color YELLOW = new java.awt.Color(255, 255, 64);
    public final static Color ORANGE = new java.awt.Color(255, 128, 64);
    public final static Color RED = new java.awt.Color(192, 0, 0);
    public final static Color WHITE = new java.awt.Color(255, 255, 255);
    public final static Color ALMOSTWHITE = new java.awt.Color(240, 240, 240);
    public final static Color BLUE = new java.awt.Color(0, 0, 192);
    public final static Color LIGHTBLUE = new java.awt.Color(128, 128, 255);
    public final static Color LIGHTCYAN = new java.awt.Color(192, 255, 255);
    public final static Color LIGHTPURPLE = new java.awt.Color(255, 128, 255);
    public final static Color LIGHTYELLOW = new java.awt.Color(255, 255, 192);
    public final static Color LIGHTGREY = new java.awt.Color(212, 212, 212);
    public final static Color PORTALDARKBLUE = new java.awt.Color(0, 119, 192);
    public final static Color PORTALLIGHTBLUE = new java.awt.Color(39, 162, 215);
    public final static Color PORTALLIGHTERBLUE = new java.awt.Color(200, 221,
            241);
    public final static Color PORTALBGBLUE = new java.awt.Color(197, 221, 233);
    public final static Color PORTALBGLIGHTBLUE = new java.awt.Color(213, 247,
            255);

    public final static String DATA_ILLIGAL = "101";
    public final static String DATA_NOT_FOUND = "102";
    public final static String DATA_INCOMPLETE = "105";
    public final static String INTERNAL_ERROR = "104";

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public Constants() {}
}

