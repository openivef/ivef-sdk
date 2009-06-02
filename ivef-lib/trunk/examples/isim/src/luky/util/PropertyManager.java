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
import java.util.*;


/*******************************************************************************
 * The property manager manages properties. It is actually a wrapper class around
 * the java.util.propery object which can be used to interface with it.<br>
 * Major enhancement is the read file and write file function which are used to
 * read and write propery settings from a standarized file. <br>
 * The file may have empty lines and comments starting with "#". The other lines
 * must be in the format :<br>
 * <ul> <code> label=value </code> </ul>
 * The properyManager uses the Log class.
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class PropertyManager {

    /***************************************************************************
     variables
     ***************************************************************************/
    private Properties props = null;

    /***************************************************************************
     constants
     ***************************************************************************/
    private  final int OK = Constants.OK;
    private  final int NOK = Constants.NOK;

    /***************************************************************************
     methods
     ***************************************************************************/

    /***************************************************************************
     * default constructor, allocates an empty propertyManager
     **************************************************************************/
    public PropertyManager() {
        props = new Properties();
    }

    /***************************************************************************
     * pre loaded constructor, allocates a propertyManager with pre loaded
     * properties
     * @param properties the properties with which the propertyManager is created
     **************************************************************************/
    public PropertyManager(Properties properties) {
        props = properties;
    }

    /***************************************************************************
     * sets the properties to the property object passed to the property manager
     * all previous settings are lost
     * @param newProps the properties with which the propertyManager is filled
     * @return OK
     **************************************************************************/
    public int setProperties(Properties newProps) {
        props = newProps;
        Log.print(Log.DEBUG, "PropertyManager.setProperties all properties set");
        return OK;
    }

    /***************************************************************************
     * gets the properties with which the propertyManager is filed
     * @return the properties
     **************************************************************************/
    public Properties getProperties() {
        Log.print(Log.DEBUG, "PropertyManager.getProperties return properties");
        return props;
    }

    /***************************************************************************
     * gets the property specified by the parameter
     * @param name property label name
     * @return the value of the property or null if it was not known
     **************************************************************************/
    public String getProperty(String name) {
        return props.getProperty(name);
    }

    /***************************************************************************
     * gets the property specified by the parameter as an int
     * @param name property label name
     * @return the value of the property or trows exception
     **************************************************************************/
    public int getIntProperty(String name) throws NumberFormatException {
        return Integer.parseInt(props.getProperty(name));
    }

    /***************************************************************************
     * sets the property specified by the parameter name to the value specified
     * by the parameter value
     * @param name property label name
     * @param value the value of this label
     * @return OK
     **************************************************************************/
    public int setProperty(String name, String value) {
        props.setProperty(name, value);
        return OK;
    }

    /***************************************************************************
     * gets the properties from the file specified by fileName
     * @param fileName the name of the file from which the settings are read
     * @return OK or NOK
     **************************************************************************/
    public int readFile(String fileName) {
        String line = "";
        String label = "";
        String value = "";
        BufferedReader in = null;

        // see if it can be opened
        try {
            in = new BufferedReader(new FileReader(fileName));
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "PropertyManager.readFile cannot open file " + fileName);
            return NOK;
        }

        // try to read it
        try {
            while (in.ready()) {
                line = in.readLine();
                // except comment lines
                if ((line.length() > 0) && (!line.substring(0, 1).equals("#"))) {
                    // take only the lines that contain "label=value"
                    StringTokenizer tokenizer = new StringTokenizer(line, "=");

                    if (tokenizer.hasMoreTokens()) {
                        label = tokenizer.nextToken();
                        value = "";
                        if (tokenizer.hasMoreTokens()) {
                            value = tokenizer.nextToken();
                            // value may contain a token
                            while (tokenizer.hasMoreTokens()) {
                                value += "=" + tokenizer.nextToken();
                            }
                        }
                        setProperty(label, value);
                    }
                }
            }
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PropertyManager.readFile error reading file " + fileName);
            return NOK;
        }

        // try to close it
        try {
            in.close();
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "PropertyManager.readFile cannot close file " + fileName);
            return NOK;
        }

        Log.print(Log.DEBUG,
                "PropertyManager.readFile properties read from " + fileName);
        return OK;
    }

    /***************************************************************************
     * writes the properties to the file specified by fileName
     * @param fileName the name of the file from to which the settings are written
     * @return OK or NOK
     **************************************************************************/
    public int writeFile(String fileName) {
        String label = "";
        String value = "";
        Enumeration labels = null;
        PrintWriter out = null;

        // try to open the output
        try {
            out = new PrintWriter(new BufferedWriter(new FileWriter(fileName)));
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PropertyManager.writeFile cannot open file " + fileName);
            return NOK;
        }

        // try to write the labels to it
        try {
            out.println("[Generated Properties]");
            out.println("[ number of labels : " + props.size() + " ]");
            out.println(
                    "[ written at : "
                            + Calendar.getInstance().getTime().toString() + " ]");

            for (labels = props.propertyNames(); labels.hasMoreElements();) {
                label = (String) labels.nextElement();
                value = props.getProperty(label);

                if (value.equals("")) {
                    value = "null";
                }
                out.println(label + "=" + value);
            }
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "PropertyManager.writeFile error writing file " + fileName);
            return NOK;
        }

        // try to close it
        try {
            out.flush();
            out.close();
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "PropertyManager.writeFile cannot close file " + fileName);
            return NOK;
        }

        Log.print(Log.DEBUG,
                "PropertyManager.writeFile properties written to " + fileName);
        return OK;
    }
}
