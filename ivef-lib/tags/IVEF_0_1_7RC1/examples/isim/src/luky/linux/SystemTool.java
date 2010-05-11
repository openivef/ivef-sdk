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
package luky.linux;


import java.net.*;
import java.io.*;
import java.io.File;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import luky.util.*;
import luky.events.*;


/******************************************************************************
 * Supports a number of system commands, currently available only for linux
 * either single shot or with a poll frequency, sends myEvents with result
 * <p>
 *
 *  <ul>
 *   <li> 1.0.0 - Release under LGPL (a.b.c) (a=major, b=class compatible, c=api compatible)</li>
 * </ul>
 *
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.0.0
 ******************************************************************************/
public class SystemTool extends MyEventManager implements Runnable {

    private String cmd = null;
    private String dir = null;
    private int poll = 5;

    public SystemTool(String cmd, String dir) {
        Log.print(Log.DEBUG, "SystemCommand.constuctor : " + dir + "/" + cmd);
        this.cmd = cmd;
        this.dir = dir;
    }

    public void setPollTime(int poll) {
        this.poll = poll;
    }

    public void run() {
        Log.print(Log.DEBUG, "SystemCommand.run : executing " + dir + "/" + cmd);

        String retVal = null;
        String oldVal = "";

        while (true) {
            Log.print(Log.STACK, "SystemCommand.run cmd: " + cmd + " dir " + dir);
            retVal = SystemCommand(cmd, dir);
            if (!(oldVal.equals(retVal))) {
                oldVal = retVal;
                MyEvent evt = new MyEvent(this);

                evt.setEventData(
                        (Object) "cmd:" + cmd + " dir:" + dir + "res:" + retVal);
                Log.print(Log.STACK, "SystemCommand.run fire event: " + retVal);
                fireMyEvent(evt);
            }
            try {
                Thread.sleep(poll * 1000);
            } catch (Exception e) {
                Log.print(Log.FATAL,
                        "SystemCommand.run cmd: " + cmd + " dir " + dir
                        + " sleep failed: " + e.toString());
                return;	
            }
        }
    }

    public String Ping(String host) {
        return Ping(host, 4);
    }

    public String Ping(String host, int retry) {
        return SystemCommand("ping -n -q -c " + retry + " " + host, "/bin");
    }

    public String Pinger(String host, int retry) {
        if (SystemCommand("ping -n -q -c " + retry + " " + host, "/bin").lastIndexOf(
                "error")
                        > -1) {
            return "timeout";
        } else {
            return "ok";
        }
    }

    public String SystemCommand(String cmd, String dir) {

        String s = null;
        String retVal = "";
        // system command to run
        // set the working directory for the OS command processor
        File workDir = new File(dir);

        try {
            Process p = Runtime.getRuntime().exec(cmd, null, workDir);
            BufferedReader stdInput = new BufferedReader(
                    new InputStreamReader(p.getInputStream()));
            BufferedReader stdErr = new BufferedReader(
                    new InputStreamReader(p.getErrorStream()));

            // read the output from the command
            while ((s = stdInput.readLine()) != null) {
                retVal += s;
            }

            // wait for the exit code to appear
            int i = p.waitFor();

            if (i != 0) {
                // read the output from the command
                while ((s = stdErr.readLine()) != null) {
                    retVal += s;
                }
            }
            stdInput.close();
            stdErr.close();
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "SystemCommand cmd: " + cmd + " dir " + dir + " failed: "
                    + e.toString());
            return null;
        }

        // clean up the mess
        System.gc();

        // Log.print(Log.DEBUG,"SystemCommand.SystemCommand result: "+retVal);
        return retVal;
    }
}
