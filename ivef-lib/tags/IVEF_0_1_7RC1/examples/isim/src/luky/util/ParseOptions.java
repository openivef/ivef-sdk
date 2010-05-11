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


import java.io.PrintStream;
import java.util.Vector;


/*******************************************************************************
 * This Class is a simple wrapper to extract commandline properties <br>
 * <br>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class ParseOptions {

    /***************************************************************************
     variables
     ***************************************************************************/
    public String remArgs[];
    String option;
    int i;
    int j;
    private String usage_string = "";

    /***************************************************************************
     constants
     ***************************************************************************/
    private static String none = "None";

    /***************************************************************************
     * default constructor <br>
     * Parses options and sets values according to options. options[] is an 
     * array of options and values[] is the returned array of string values. <br>
     * If options[i] has no associated string, set values[i] = "None" before 
     * calling this. The usage string must be supplied by the user. <br>
     **************************************************************************/
    public ParseOptions(String args[], String options[], String values[], String usage) {
        usage_string = null;
        none = "None";
        option = null;
        i = 0;
        j = 0;
        Vector leftOvers = new Vector();

        usage_string = usage;
        for (i = 0; i < args.length; i++) {
            for (j = 0; j < options.length; j++) {
                if (checkOption(args, options[j], values[j])) {
                    values[j] = option;
                    break;
                }
            }
            if (j >= options.length) {
                leftOvers.addElement(args[i]);
            }
        }
        remArgs = new String[leftOvers.size()];
        for (i = 0; i < leftOvers.size(); i++) {
            remArgs[i] = (String) leftOvers.elementAt(i);
        }
    }

    /***************************************************************************
     * CheckOption
     **************************************************************************/
    private boolean checkOption(String args[], String tryOption, String value) {
        if (!args[i].equals(tryOption)) {
            return false;
        }

        if (none.equals(value)) {
            option = "Set";
        } else if (++i < args.length) {
            option = args[i];
        } else { 
            usage_error(value);
        }

        return true;
    }

    /***************************************************************************
     * Usage error, Print usage error and exit <br>
     **************************************************************************/
    public void usage_error() {
        System.out.println(
                new StringBuffer("Usage: ").append(usage_string).toString());
        System.exit(1);
    }

    /***************************************************************************
     * Usage error, Print usage error and exit <br>
     **************************************************************************/
    public void usage_error(String value) {
        System.out.println(
                new StringBuffer("Unknown option: ").append(value).toString());
        System.out.println(
                new StringBuffer("Usage: ").append(usage_string).toString());
        System.exit(1);
    }

}
