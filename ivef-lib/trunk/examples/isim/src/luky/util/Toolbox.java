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


import java.io.*;
import java.net.*;
import java.awt.*;
import java.util.Locale;


/******************************************************************************
 * This class is a placeholder for functions that seemed to have no logical other
 * place. It's a toolbox for your convienance <p>
 * Revision Changes : <br>
 *  <ul>
 *   <li> 1.00 - initial version </li>
 *   <li> 1.01 - improved lookup of ip</li>
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.01
 ******************************************************************************/
public class Toolbox {

    public static boolean isWindows = false;
    public static boolean isWindowsNT = false;
    public static boolean isWindowsXP = false;
    public static boolean isWindowsNTor2000orXP = false;
    public static boolean isWindows2000orXP = false;
    public static boolean isWindows95 = false;
    public static boolean isWindows98 = false;
    public static boolean isWindowsMe = false;
    public static boolean isMacOSX = false;
    public static boolean isLinux = false;
    public static boolean isSolaris = false;
    public static boolean isOS2 = false;
 	     
    /**************************************************************************
     * default constructor
     **************************************************************************/
    public Toolbox() {
        System.setProperty("java.net.preferIPv4Stack", "true");

        isWindows = false;
        isWindowsNTor2000orXP = false;
        isWindows2000orXP = false;
        isWindowsNT = false;
        isWindowsXP = false;
        isWindows95 = false;
        isWindows98 = false;
        isWindowsMe = false;
        isSolaris = false;
        isLinux = false;
        isOS2 = false;
        isMacOSX = false;

        String os = System.getProperty("os.name").toLowerCase(Locale.US);

        // set the operating system variables
        isWindows = os.indexOf("windows") != -1;
        if (os.indexOf("windows nt") != -1 || os.indexOf("windows 2000") != -1
                || os.indexOf("windows xp") != -1) {
            isWindowsNTor2000orXP = true;
        }

        if (os.indexOf("windows 2000") != -1 || os.indexOf("windows xp") != -1) {
            isWindows2000orXP = true;
        }

        if (os.indexOf("windows nt") != -1) { 
            isWindowsNT = true;
        }

        if (os.indexOf("windows xp") != -1) { 
            isWindowsXP = true;
        }

        if (os.indexOf("windows 95") != -1) {
            isWindows95 = true;
        }

        if (os.indexOf("windows 98") != -1) {
            isWindows98 = true;
        }

        if (os.indexOf("windows me") != -1) {
            isWindowsMe = true;
        }
        isSolaris = os.indexOf("solaris") != -1;
        isLinux = os.indexOf("linux") != -1;

        isOS2 = os.indexOf("os/2") != -1;

        if (os.startsWith("mac os")) {
            if (os.endsWith("x")) {
                isMacOSX = true;
            }
        }

    }

    /**************************************************************************
     * takes a constant status as input and returns the text value
     * @param status the status that must be outputted
     * @return status in String format
     *************************************************************************/
    public static String statusString(int status) {
        if (status == Constants.OK) {
            return "OK";
        }
        if (status == Constants.NOK) {
            return "NOK";
        }
        if (status == Constants.TIMEOUT) {
            return "TIMEOUT";
        }
        if (status == Constants.UNKNOWN) {
            return "UNKNOWN";
        }
        if (status == Constants.MARGINAL) {
            return "MARGINAL";
        }
        if (status == Constants.EXCEPTION) {
            return "EXCEPTION";
        }
        return ("ILLIGAL");
    }

    /**************************************************************************
     * takes a constant status as input and returns the allocated color value
     * @param name the status color that must be outputted
     * @return status color
     *************************************************************************/
    public static Color statusColor(String name) {

        if (name.equals("OK")) {
            return Constants.GREEN;
        } else if (name.equals("UNKNOWN")) {
            return Constants.LIGHTCYAN;
        } else if (name.equals("MARGINAL")) {
            return Constants.YELLOW;
        } else if (name.equals("TIMEOUT")) {
            return Constants.ORANGE;
        } else if (name.equals("NOK")) {
            return Constants.RED;
        } else if (name.equals("EXCEPTION")) {
            return Constants.LIGHTPURPLE;
        }	

        Log.print(Log.FATAL,
                "Toolbox.statusColor unknown status: \"" + name + "\"");
        return Constants.GREY;	
    }

    /**************************************************************************
     * returns the canonical name of the current machine
     * @return the canonical name
     *************************************************************************/
    public static String getCanonicalHostName() {

        try {
            InetAddress addr = InetAddress.getLocalHost();
    
            // Get canonical name
            return(addr.getCanonicalHostName());

        } catch (UnknownHostException e) {
            Log.print(Log.FATAL,
                    "Toolbox.getCanonicalHostName unknown error: "
                    + e.toString());
            return null;
        }
    }

    /**************************************************************************
     * returns the hostname of the current machine
     * @return the hostname
     *************************************************************************/
    public static String getHostname() {

        try {
            InetAddress addr = InetAddress.getLocalHost();
    
            // Get hostname
            return(addr.getHostName());

        } catch (UnknownHostException e) {
            Log.print(Log.FATAL,
                    "Toolbox.getHostName unknown error: " + e.toString());
            return null;
        }
    }

    /**************************************************************************
     * returns the ip of the current machine
     * @return the ip address
     *************************************************************************/
    public static String getIPaddress() {

        try {
            InetAddress addr = InetAddress.getLocalHost();
    
            // Get IP Address
            byte[] ipAddr = addr.getAddress();

            // Convert to dot representation
            String ipAddrStr = "";

            for (int i = 0; i < ipAddr.length; i++) {
                if (i > 0) {
                    ipAddrStr += ".";
                }
                ipAddrStr += ipAddr[i] & 0xFF;
            }
    
            // Get ip address
            return(ipAddrStr);

        } catch (UnknownHostException e) {
            Log.print(Log.FATAL,
                    "Toolbox.getIPaddress unknown error: " + e.toString());
            return null;
        }
    }

    /**************************************************************************
     * takes a number and fills it to n places (e.g. 2,2 becomes 02)
     * @param number the input digit
     * @param size the total number of digits
     * @return the number as a string
     *************************************************************************/
    public static String fillString(int number, int size) {
        String result = "" + number;

        // fill the string to size places
        while (result.length() < size) { 
            result = "0" + result;
        }

        return result;
    }
    ;

    /**************************************************************************
     * copies the src file to the dst file
     * if dst does not exist, it will be created
     *************************************************************************/
    public static void copy(File src, File dst) throws IOException {

        InputStream in = new FileInputStream(src);
        OutputStream out = new FileOutputStream(dst);
    
        // Transfer bytes from in to out
        byte[] buf = new byte[1024];
        int len;

        while ((len = in.read(buf)) > 0) {
            out.write(buf, 0, len);
        }
        in.close();
        out.close();
    }

    /**************************************************************************
     * returns the version of the current JVM
     *************************************************************************/
    public static String getJDKversion() {
        Log.print(Log.DEBUG,
                "Toolbox.getJDKversion : "
                + System.getProperty("java.class.version", "44.0"));
        if (isJDK11()) {
            return "1.1";
        } else if (isJDK12()) {
            return "1.2";
        } else if (isJDK13()) {
            return "1.3";
        } else if (isJDK14()) {
            return "1.4";
        } else if (isJDK15()) {
            return "1.5";
        } else {
            return "unknown";
        }
    }

    /**************************************************************************/
    private static boolean isJDK11() {
        String v = System.getProperty("java.class.version", "44.0");

        return ("46.0".compareTo(v) > 0) && ("45.3".compareTo(v) <= 0);
    }

     /**************************************************************************/
    private static boolean isJDK12() {
        String v = System.getProperty("java.class.version", "44.0");

        return ("47.0".compareTo(v) > 0) && ("46.0".compareTo(v) <= 0);
    }

     /**************************************************************************/
    private static boolean isJDK13() {
        String v = System.getProperty("java.class.version", "44.0");

        return ("48.0".compareTo(v) > 0) && ("47.0".compareTo(v) <= 0);
    }

     /**************************************************************************/
    private static boolean isJDK14() {
        String v = System.getProperty("java.class.version", "44.0");

        return ("49.0".compareTo(v) > 0) && ("48.0".compareTo(v) <= 0);
    }

     /**************************************************************************/
    private static boolean isJDK15() {
        String v = System.getProperty("java.class.version", "44.0");

        return ("50.0".compareTo(v) > 0) && ("49.0".compareTo(v) <= 0);
    }

}

