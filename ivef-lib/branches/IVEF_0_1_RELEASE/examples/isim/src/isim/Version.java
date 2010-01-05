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
package isim;


import java.util.Date;
import java.text.SimpleDateFormat;
import java.awt.event.*;
import javax.swing.*;
import luky.util.*;


/******************************************************************************
 * Version Class is used to get the version of the Luky utilities class runtime
 * <br>
 * The Luky Libraries incorporate the: <br>
 *  <ul>
 *      <li> <a href=../../doc-westhawk/index.html target=_top> Westhawk Libraries </a> </li>
 *	<li> AdventNet MIB reader </li>
 *	<li> Piccolo XML parser </li>
 *	<li> Interbase dx classes </li>
 *  </ul>
 * <p>
 * Revision History<br>
 *
 *  <ul>
 *   <li> 1.0.0 - initial version </li>
 * </ul>
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 4.1.1
 ******************************************************************************/
public class Version implements MouseListener {

    private String version = "1.0.0";
    private String name = "iSim";
    private String appVersion = null;
    private String appName = null;
    private String appBuildTime = null;

    /**
     * This string will be automatically expanded upon "ant commit".
     * Do not edit it by hand!
     */
    private static final String BUILD_TIME_STRING = "20090922-1152";

    /** A {@link Date} version of the build time. */
    private final Date BUILD_TIME = _getBuildDate();

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public Version() {}

    /**************************************************************************
     * alternative constructor
     * @param name name name of the application using the library
     * @param version version of the application using the library
     * @param buildTime build time of the application using the library
     **************************************************************************/
    public Version(String name, String version, String buildTime) {
        appName = name;
        appVersion = version;
        appBuildTime = buildTime;
    }

    /**************************************************************************
     * returns the current version of the Application using the library
     * @return the version as a string
     **************************************************************************/
    public String getAppVersion() {
        if ((appName != null) && (appVersion != null)) {
            return appName + " - " + appVersion;
        } else {
            return null;
        }
    }

    /**************************************************************************
     * returns the current version of the Library
     * @return the version as a string
     **************************************************************************/
    public String getLibVersion() {
        return name + " - " + version;
    }

    /**************************************************************************
     * runtime function to get the current version, prints it to stdout
     **************************************************************************/
    public static void main(String[] args) {

        Version ver = new Version();

        if (ver.getAppVersion() != null) {
            System.out.println(
                ver.getAppVersion() + " (" + ver.getAppBuildTimeString()
                + ")");
        }
        System.out.println(
            ver.getLibVersion() + " (" + ver.getLibBuildTimeString() + ")");
    }

    /**************************************************************************
     * returns the build time as a string of the application
     * @return the build time as a string
     **************************************************************************/
    public String getAppBuildTimeString() {
        return appBuildTime;
    }

    /**************************************************************************
     * returns the build time as a string of the library
     * @return the build time as a string
     **************************************************************************/
    public String getLibBuildTimeString() {
        return BUILD_TIME_STRING;
    }

    /**************************************************************************
     * set application buildtime shown in about box
     * @param time buildTime of the application using the library
     **************************************************************************/
    public void setAppBuildTime(String time) {

        this.appBuildTime = time;
    }

    /**************************************************************************
     * set application name shown in about box
     * @param name name name of the application using the library
     **************************************************************************/
    public void setAppName(String name) {

        this.appName = name;
    }

    /**************************************************************************
     * set application version shown in about box
     * @param version version of the application using the library
     **************************************************************************/
    public void setAppVersion(String version) {

        this.appVersion = version;
    }

    /**************************************************************************
     * aboutBox shows a about box
     * @param name name name of the application using the library
     * @param version version of the application using the library
     **************************************************************************/
    public void about(String name, String version) {

        if ((name != null) && (version != null)) {
            setAppName(name);
            setAppVersion(version);
        }
        this.about();
    }

    /**************************************************************************
     * aboutBox shows a about box
     **************************************************************************/
    public void about() {

        JOptionPane optionPane = null;

        if ((appName != null) && (appVersion != null)) {
            optionPane = new JOptionPane(
                getAppVersion() + " (" + getAppBuildTimeString() + ")\n"
                + getLibVersion() + " (" + getLibBuildTimeString() + ")",
                JOptionPane.INFORMATION_MESSAGE);
        } else {
            optionPane = new JOptionPane(
                getLibVersion() + " (" + getLibBuildTimeString() + ")",
                JOptionPane.INFORMATION_MESSAGE);
        }
        JDialog dialog = optionPane.createDialog(null, "About");

        dialog.setModal(true);
        dialog.setVisible(true);
    }

    /**************************************************************************
     * Invoked when the mouse button has been clicked (pressed and released) on a component.
     * nothing happens
     **************************************************************************/
    public void 	mouseClicked(MouseEvent e) {
        Log.print(Log.STACK, "Version.mouseClicked");
        about();
    }

    /**************************************************************************
     * Invoked when the mouse enters a component.
     * nothing happens
     **************************************************************************/
    public void 	mouseEntered(MouseEvent e) {
        Log.print(Log.STACK, "Version.mouseEntered");
    }

    /**************************************************************************
     * Invoked when the mouse exits a component.
     * nothing happens
     **************************************************************************/
    public void 	mouseExited(MouseEvent e) {
        Log.print(Log.STACK, "Version.mouseExited");
    }

    /**************************************************************************
     * Invoked when a mouse button has been pressed on a component.
     * shows the about dialog
     **************************************************************************/
    public void 	mousePressed(MouseEvent e) {
        Log.print(Log.STACK, "Version.mousePressed");
    }

    /**************************************************************************
     * Invoked when a mouse button has been released on a component.
     **************************************************************************/
    public void 	mouseReleased(MouseEvent e) {}

    /**************************************************************************/
    private Date _getBuildDate() {
        try {
            return new SimpleDateFormat("yyyyMMdd-HHmm z").parse(
                       BUILD_TIME_STRING + " GMT");
        } catch (Exception e) { // parse format or whatever problem
            return null;
        }
    }

}
