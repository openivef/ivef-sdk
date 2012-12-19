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


import java.util.Calendar;
import java.io.*;
import java.net.*;
//import com.borland.dx.sql.dataset.*;


/*******************************************************************************
 *
 * The Log class has been created to facilitate in a standard interface to output
 * logging information to a device. The main advantage is that the program using
 * the logging class encapsulates no knownledge on the level to which logging is
 * required and to which output this logging should be directed.<br>
 * Currently 6 levels of logging are defined:<br>
 *
 * <ul>
 *      <li>level  0 : no logging
 * </li><li>level  1 : fatal errors
 * </li><li>level  2 : minor errors
 * </li><li>level  3 : operational logging
 * </li><li>level  4 : detailed operational logging
 * </li><li>level  5 : debug logging
 * </li><li>level  6 : debug logging with stacktraces
 * </ul>
 * And 4 different ways of output logging exist:<br>
 * <ul>
 *      <li>file
 * </li><li>screen
 * </li><li>database
 * </li><li>mail
 * </ul>
 * There is also a fallback parameter implemented. This parameter indicates
 * fallback if the logging tool should try to fall back incase of an output error.
 * For example when logging to disc is activated with fallback and the disc runs
 * out of space, screen logging will be activated to report that the disc write
 * has failed and the logging will continue to the screen. Fallback will only
 * activate when loggings would be lost. If for example one logs to disc and the
 * database, then fallback would not be activated. <br>
 * Two different forms of output exist:<br>
 * <ul>
 *      <li>timed
 * </li><li>clean
 * </ul>
 * Use timed logging to get a timestamped message with a module headername, use
 * clean to get the plain message.<br>
 * <br>
 *  usage : <br>
 *  <ul><bold> Screen Logging </bold> <br> <ul>
 *  <code> setLogLeveL(&lt;level&gt;); </code><br>
 *  <code> setModuleName(&lt;moduleName&gt;);</code><br>
 *  <code> setOutput(Log.SCREEN, true);</code><br>
 *  <code> print (&lt;level&gt;, "&lt;text&gt;");</code><br> </ul>
 *  <bold> File Logging </bold> <br> <ul>
 *  <code> setLogLeveL(&lt;level&gt;); </code><br>
 *  <code> setModuleName(&lt;moduleName&gt;);</code><br>
 *  <code> setFile("&lt;file&gt;", true);</code><br>
 *  <code> setOutput(Log.FILE, true);</code><br>
 *  <code> print (&lt;level&gt;, "&lt;text&gt;");</code><br> </ul>
 *  <bold> Database Logging: setLogLeveL(&lt;level&gt;); </code> <br> <ul>
 *  <code> setModuleName(&lt;moduleName&gt;);</code><br>
 *  <code> setDatabase("&lt;url&gt;","&lt;driver&gt;","&lt;user&gt;","&lt;pass&gt;");</code><br>
 *  <code> setOutput(Log.FILE, true);</code><br>
 *  <code> print (&lt;level&gt;, "&lt;text&gt;");</code><br></ul>
 * <br> </ul>
 *  Revision Changes : <br>
 *  <ul>
 *   <li>  ver 1.01 added option to mail fatal errors to a mailing address </li>
 *   <li>  ver 2.00 ported to luky </li>
 *   <li>  ver 2.01 bug fix, Log.Constants.OK and Log.Constants.NOK are now in Constants</li>
 *   <li>  ver 2.02 added backup logfile when size is exceeded</li>
 *   <li>  ver 2.03 bugfix, hour is now in 24h format </li>
 *   <li>  ver 2.04 bugfix, mili sec now have leading zeros</li>
 *   <li>  ver 2.05 timed output adds loglevel, and reduced memory</li>
 *   <li>  ver 2.06 you can now actually set the fallback</li>
 *   <li>  ver 2.07 bugfix, calendar is now given right time again</li>
 *  </ul>
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 2.07
 ******************************************************************************/
public class Log {

    /***************************************************************************
     variables
     ***************************************************************************/
    private static Log       log = null;
    private static int       level = 1;
    private static int       mailLevel = 1;
    private static int       format = 1;
    private static long      maxFileSize = -1;
    private static long      fileSize = 0;
    private static boolean   fallBack = false;
    private static boolean   fileLog = false;
    private static boolean   screenLog = false;
    private static boolean   dbLog = false;
    private static boolean   mailLog = false;
    private static String    header = "";
    private static String    fileName = "";
    private static String    backupFileName = null;
    private static String    mailToAddress = null;
    private static String    hostname = null;
    private static PrintWriter outFile = null;
 //   private static Database  database = null;
    private static Calendar  cal = Calendar.getInstance();

    /***************************************************************************
     constants
     ***************************************************************************/

    /** constant representing FILE logging */
    public  final static int FILE = 0;

    /** constant representing SCREEN logging */
    public  final static int SCREEN = 1;

    /** constant representing DATABASE logging */
    public  final static int DATABASE = 2;

    /** constant representing MAIL logging */
    public  final static int MAIL = 3;

    /** constant representing logging level 0 */
    public  final static int NONE = 0;

    /** constant representing logging level 1 */
    public  final static int FATAL = 1;

    /** constant representing logging level 2 */
    public  final static int WARNING = 2;

    /** constant representing logging level 3 */
    public  final static int MESSAGE = 3;

    /** constant representing logging level 4 */
    public  final static int DETAIL = 4;

    /** constant representing logging level 5 */
    public  final static int DEBUG = 5;

    /** constant representing logging level 6 */
    public  final static int STACK = 6;

    /** constant representing CLEAN printing of the log */
    public  final static int CLEAN = 0;

    /** constant representing TIMED printing of the log */
    public  final static int TIMED = 1;

    /***************************************************************************
     methods
     ***************************************************************************/

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public Log() {// empy constructor
    }
    ;

    /**************************************************************************
     * close stops the logging, closes the logfiles if needed
     **************************************************************************/
    protected void finalize() {
        // close all open descriptors
        if (outFile != null) {
            try {
                print(Log.DETAIL, "Log.finalize closing log file " + fileName);
                outFile.flush();
                outFile.close();
                outFile = null;
            } catch (Exception e) {
                print(Log.FATAL, "Log.finalize couldn't close file " + fileName);
                print(Log.STACK, e.toString());
            }
        }
    }
    ;

    /**************************************************************************
     * close stops the logging, closes the logfiles if needed
     * @return Constants.OK or Constants.NOK
     **************************************************************************/
    public static int close() {
        // close all open descriptors
        if (outFile != null) {
            try {
                print(Log.DETAIL, "Log.close closing log file " + fileName);
                outFile.flush();
                outFile.close();
                outFile = null;
            } catch (Exception e) {
                print(Log.FATAL, "Log.close couldn't close file " + fileName);
                print(Log.STACK, e.toString());
            }
        }
        return (Constants.OK);
    }
    ;

    /**************************************************************************
     * Initializes the logging module, not required but handy. (it should be
     * called automatically upon the first method invocation.)
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int init() {
        // create the one and only instance for the data
        // methods are static anyway but data is not
        if (log == null) {
            log = new Log();
        }
        return Constants.OK;
    }
    ;

    /**************************************************************************
     * specifies whether there is log fallback enabled (default off)
     * @param enable true or false
     *************************************************************************/
    public static void setLogFallBack(boolean enable) {
        fallBack = enable;
    }

    /**************************************************************************
     * specifies the log level (0..6) for the logging.
     * @param newLevel values are FATAL, WARNING, MESSAGE, DETAIL, DEBUG or STACK
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setLogLevel(int newLevel) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        // see if the new level is within limits
        if ((newLevel < 0) || (newLevel > 6)) {
            print(WARNING,
                    "Log.setLogLevel illigal level " + newLevel + " ("
                    + getLogLevelName(newLevel) + ")");
            return Constants.NOK;
        }

        level = newLevel;
        print(Log.DETAIL,
                "Log.setLogLevel set level to " + newLevel + " ("
                + getLogLevelName(newLevel) + ")");

        return Constants.OK;
    }
    ;

    /**************************************************************************/
    private static String getLogLevelName(int level) {
        if (level == Log.NONE) {
            return "NONE";
        } else if (level == Log.FATAL) {
            return "FATAL";
        } else if (level == Log.WARNING) {
            return "WARNING";
        } else if (level == Log.MESSAGE) {
            return "MESSAGE";
        } else if (level == Log.DETAIL) {
            return "DETAIL";
        } else if (level == Log.DEBUG) {
            return "DEBUG";
        } else if (level == Log.STACK) {
            return "STACK";
        } else {
            return "<INTERNAL ERROR, UNKNOWN LEVEL>";
        }
    }

     /**************************************************************************
     * returns the level of the logging
     * @return  a int corresponding to Log.NONE Log.FATAL, Log.WARNING, 
     * Log.MESSAGE, Log.DETAIL, Log.DEBUG,
     * or Log.STACK
     **************************************************************************/
    public static int getLogLevelValue() {
        // first check if there is a object
        if (log == null) {
            init();
        }

        return (level);
    }
    ;

    /**************************************************************************
     * returns the level of the logging
     * @return a string "NONE", "FATAL", "WARNING", "MESSAGE", "DETAIL", "DEBUG",
     * or "STACK"
     **************************************************************************/
    public static String getLogLevel() {
        // first check if there is a object
        if (log == null) {
            init();
        }

        return getLogLevelName(level);
    }
    ;

    /**************************************************************************
     * sets the output on or of
     * @param type constant specifying the LogType, values are FILE, SCREEN,
     * DATABASE or MAIL
     * @param status TRUE or FALSE
     * @return returns Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setOutput(int type, boolean status) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        if (type == FILE) {
            fileLog = status;
        } else if (type == SCREEN) {
            screenLog = status;
        } else if (type == DATABASE) {
            dbLog = status;
        } else if (type == MAIL) {
            mailLog = status;
        } else {
            log.print(WARNING,
                    "Log.setOutput illigal type " + getOutputName(type));
            return Constants.NOK;
        }

        if (status == true) {
            print(Log.MESSAGE, "LOGGING TO " + getOutputName(type) + " ENABLED");
        } else {
            print(Log.MESSAGE, "LOGGING TO " + getOutputName(type) + " DISABLED");
        }

        return Constants.OK;
    }
    ;

    /**************************************************************************/
    private static String getOutputName(int type) {
        if (type == Log.SCREEN) {
            return "SCREEN";
        } else if (type == Log.FILE) {
            return "FILE";
        } else if (type == Log.DATABASE) {
            return "DATABASE";
        } else if (type == Log.MAIL) {
            return "MAIL";
        } else {
            return "<INTERNAL ERROR, UNKNOWN TYPE>";
        }
    }

     /**************************************************************************
     * returns the status of the output devices
     * @param type constant specifying the LogType, values are FILE, SCREEN,
     * DATABASE or MAIL
     * @return returns TRUE or FALSE
     *************************************************************************/
    public static boolean getOutput(int type) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        if (type == FILE) {
            return fileLog;
        } else if (type == SCREEN) {
            return screenLog;
        } else if (type == DATABASE) {
            return dbLog;
        } else if (type == MAIL) {
            return mailLog;
        } else {
            log.print(WARNING, "Log.getOutput illigal type " + type);
            return false;
        }
    }
    ;

    /**************************************************************************
     * specifies the format used to log messages
     * @param type TIMED or CLEAN
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setFormat(int type) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        // see if the new level is within limits
        if ((type < 0) || (type > 1)) {
            print(WARNING, "Log.setFormat illigal type " + getFormatName(type));
            return Constants.NOK;
        }

        format = type;

        print(Log.DETAIL, "Log.setFormat format set to " + getFormatName(type));
        return Constants.OK;
    }
    ;

    /**************************************************************************/
    private static String getFormatName(int type) {
        if (type == Log.CLEAN) {
            return "CLEAN";
        } else if (type == Log.TIMED) {
            return "TIMED";
        } else {
            return "<INTERNAL ERROR, UNKOWN TYPE>";
        }
    }

     /**************************************************************************
     * returns the logging format
     * @return a string "TIMED" or "CLEAN"
     **************************************************************************/
    public static String getFormat() {
        // first check if there is a object
        if (log == null) {
            init();
        }

        return getFormatName(format);
    }
    ;

    /**************************************************************************
     * specifies the name used with each log print
     * @param moduleName string specifying the name for the logging
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setModuleName(String moduleName) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        header = moduleName;
        print(Log.DETAIL, "Log.setModuleName header set to " + moduleName);

        return Constants.OK;
    }
    ;

    /**************************************************************************
     * specifies the database parameters, it will try to connect to the database
     * and fallback if needed.
     * @param url the jdbc url that specifies the database
     * @param driver the driver that is required. It must be on the classpath too
     * @param user the username for the database
     * @param password the password for the database user
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
/*    public static int setDatabase(String url, String driver, String user,
            String password) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        try {
            database = new Database();
            database.setConnection(
                    new ConnectionDescriptor(url, user, password, false, driver));
        } catch (Exception e) {
            // could not create connection, stop logging
            setOutput(DATABASE, false);

            // do we fallback ?
            if ((fallBack) && (screenLog == false) && (dbLog == false)) {
                setOutput(SCREEN, true);
                print(Log.STACK, "Log.setDatabase fallBack activated");
            }

            // and report this error
            print(Log.FATAL, "Log.setDatabase couldn't connect");
            print(Log.STACK, e.toString());
            return Constants.NOK;
        }

        // normal log
        print(Log.DETAIL, "Log.setDatabase logging to " + url);
        return Constants.OK;
    }
*/
    /**************************************************************************
     * specifies the the log level (0..6) for the mail logging, and the address
     * to which the mail should be sent. The mail logging has not been activated
     * after calling this function, use setOutput for that
     * @param toAddress the mail address to be used
     * @param newMailLevel values are FATAL, WARNING, MESSAGE, DETAIL, DEBUG or STACK
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setMail(String toAddress, int newMailLevel) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        // check the input
        if (toAddress == null) {
            print(Log.FATAL, "Log.setMail toAddress not supplied");
            return Constants.NOK;
        }
        // see if the new level is within limits
        if ((newMailLevel < 0) || (newMailLevel > 6)) {
            print(WARNING, "Log.setMail illigal level " + newMailLevel);
            return Constants.NOK;
        }

        // take it
        mailLevel = newMailLevel;

        // see if it makes sense
        if (mailLevel > level) {
            mailLevel = level;
            print(WARNING,
                    "Log.setMail WARNING raise logLevel first, taking " + level);
        }

        print(Log.DETAIL,
                "Log.setMail set level to " + mailLevel + " ("
                + getLogLevelName(mailLevel) + ")");

        mailToAddress = toAddress;
        try {
            hostname = InetAddress.getLocalHost().getHostName();
        } catch (Exception e) {
            print(Log.WARNING, "Log.setMail can't get hostname, fix your DNS !");
            hostname = "unknown";
        }

        // normal log
        print(Log.DETAIL, "Log.setMail logging to " + toAddress);
        return Constants.OK;
    }

    /**************************************************************************
     * specifies the the logfile and if the tool should try to append to the file
     * or reopen it and the backup file with roll over size
     * @param file the name used for the file
     * @param backupFile the name used for the backup file
     * @param maxSize the maximum size of the file
     * @param append true or false
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setFile(String file, boolean append, String backupFile, long maxSize) {
        backupFileName = backupFile;
        maxFileSize = maxSize;

        return setFile(file, append);
    }

    /**************************************************************************
     * specifies the the logfile and if the tool should try to append to the file
     * or reopen it.
     * @param file the name used for the file
     * @param append true or false
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int setFile(String file, boolean append) {
        // first check if there is a object
        if (log == null) {
            init();
        }

        // check if we were already logging to a file
        if (outFile != null) {
            try {
                print(Log.DETAIL, "Log.setFile closing log file " + fileName);
                outFile.flush();
                outFile.close();
                outFile = null;
            } catch (Exception e) {
                print(Log.FATAL, "Log.setFile couldn't close file " + fileName);
                print(Log.STACK, e.toString());
            }
        }

        // create new file or append
        try {
            PrintWriter out = new PrintWriter(
                    new BufferedWriter(new FileWriter(file, append)));

            fileName = file;
            outFile = out;
	   
            // get the initial file size 
            if (append) {
                File existingFile = new File(file);

                fileSize = existingFile.length();
            } else {
                fileSize = 0;
            }
        } catch (Exception e) {
            // could not create file, stop logging to it
            setOutput(FILE, false);

            // do we fallback ?
            if ((fallBack == true) && (screenLog == false) && (dbLog == false)) {
                setOutput(SCREEN, true);
                print(Log.STACK, "Log.setFile fallBack activated");
            }

            // and report this error
            print(Log.FATAL, "Log.setFile couldn't create file " + file);
            print(Log.STACK, e.toString());
            return Constants.NOK;
        }

        print(Log.DETAIL, "Log.setFile logging to file " + file);

        return Constants.OK;
    }
    ;

    /**************************************************************************
     * returns the file to which the logging is taking place
     * @return filename
     **************************************************************************/
    public static String getFile() {
        // first check if there is a object
        if (log == null) {
            init();
        }

        return fileName;
    }
    ;

    /**************************************************************************
     * returns the name of module which is logging
     * @return module name
     **************************************************************************/
    public static String getModuleName() {
        // first check if there is a object
        if (log == null) {
            init();
        }

        return header;
    }

    /**************************************************************************/
    private static String fillString(int places, int number) {

        if (places == 1) {
            return "" + number;
        } else if (places == 2) {
            if (number < 10) { // fill the string to 2 places
                return "0" + number;
            } else {
                return "" + number;
            }
        }
        if (number < 100) {
            return "0" + fillString(places - 1, number);
        } else {
            return "" + number;
        }
    }

     /**************************************************************************/
    private static String getMonth(int month) {
        if (month == cal.JANUARY) {
            return "Jan";
        } else if (month == cal.FEBRUARY) {
            return "Feb";
        } else if (month == cal.MARCH) {
            return "Mar";
        } else if (month == cal.APRIL) {
            return "Apr";
        } else if (month == cal.MAY) {
            return "May";
        } else if (month == cal.JUNE) {
            return "Jun";
        } else if (month == cal.JULY) {
            return "Jul";
        } else if (month == cal.AUGUST) {
            return "Aug";
        } else if (month == cal.SEPTEMBER) {
            return "Sep";
        } else if (month == cal.OCTOBER) {
            return "Oct";
        } else if (month == cal.NOVEMBER) {
            return "Nov";
        } else if (month == cal.DECEMBER) {
            return "Dec";
        } else { // turn off time stamp, or we will loop
            int oldFormat = format;

            setFormat(CLEAN);
            print(Log.FATAL, "Log.getMonth internal error " + month);
            setFormat(oldFormat);
        }
        ;
        // moved return out of else, new compiler is more strict
        return "??? ";
    }
    ;

     /**************************************************************************/
    private static int mailPrint(String msg) {
        try {
            sendMail(mailToAddress, "log@" + hostname, header + " ERROR", msg);
        } catch (Exception e) {
            // shutdown logging
            setOutput(MAIL, false);

            // do we fallback ?
            if (fallBack && (screenLog == false) && (dbLog == false)
                    && (fileLog == false)) {
                setOutput(SCREEN, true);
                print(Log.STACK, "Log.mailPrint fallBack activated");
            }

            // and report this error
            print(Log.FATAL, "Log.mailPrint couldn't email " + mailToAddress);
            print(Log.STACK, e.toString());

            return Constants.NOK;
        }

        return Constants.OK;
    }
    ;

     /**************************************************************************/
    private static int screenPrint(String msg) {
        System.out.println(msg);
        return Constants.OK;
    }
    ;

     /**************************************************************************/
/*    private static int dbPrint(String msg) {
        // database has a fix format
        String statement = "INSERT INTO LOGGING (TIMESTAMP, MODULE, "
                + "ENTRY, MILLIS) VALUES(\'" + cal.getTime().toString()
                + "\', \'" + header + "\', \'" + msg + "\', \'"
                + System.currentTimeMillis() + "\')";

        try {
            database.executeStatement(statement);
        } catch (Exception e) {
            // shutdown logging
            setOutput(DATABASE, false);

            // do we fallback ?
            if ((fallBack) && (screenLog == false) && (dbLog == false)) {
                setOutput(SCREEN, true);
                print(Log.STACK, "Log.dpPrint fallBack activated");
            }

            // and report this error
            print(Log.FATAL, "Log.dbPrint couldn't write in database");
            print(Log.STACK, e.toString());

            return Constants.NOK;
        }

        return Constants.OK;
    }
    ;
*/
     /**************************************************************************/
    private static synchronized int rollOver() {

        // turn of file log for now
        fileLog = false;

        print(Log.DEBUG,
                "Log.rollOver copying :" + fileName + " to " + backupFileName);

        // close existing logging
        if (close() != Constants.OK) {
            return Constants.NOK;
        }
  
        // copy the file 
        File src = new File(fileName);
        File dst = new File(backupFileName);

        try {
            Toolbox.copy(src, dst);
        } catch (Exception e) {
            print(Log.FATAL,
                    "Log.rollOver ERROR copying :" + fileName + " to "
                    + backupFileName + " (" + e.toString() + ")");	
        }

        // and reopen the logfile, but this time, do not append 
        if (setFile(fileName, false) != Constants.OK) {
            return Constants.NOK;
        }

        // re-activate file logging
        fileLog = true;

        return Constants.OK;
    }
	
     /**************************************************************************/
    private static int filePrint(String msg) {

        if (outFile == null) {
            // there is no output file !
            if ((fallBack == true) && (screenLog == false) && (dbLog == false)) {
                setOutput(SCREEN, true);
                print(Log.STACK, "Log.filePrint fallBack activated");
            }
	
            // when fileLog is true, this would cause a call to print, which
            // would call filePrint, which would call .... etc
            // until the stack explodes, beter disable it here
            fileLog = false;

            print(Log.FATAL, "Log.filePrint no file to print to");

            return Constants.NOK;
        }

        try {
            outFile.println(msg);
            outFile.flush();
            fileSize += msg.length();
            if ((backupFileName != null) && (fileSize > maxFileSize)) {
                return rollOver();
            }
        } catch (Exception e) {
            print(Log.FATAL, "Log.filePrint couldn't write to file " + fileName);
            print(Log.STACK, e.toString());
            return Constants.NOK;
        }

        return Constants.OK;
    }
    ;

     /**************************************************************************
     * takes a string and removes the quotes so "she said "hello"" becomes: <br>
     * "she said hello"
     * @param msg the string that must be outputted
     * @return msg without quotes
     *************************************************************************/
    public static String removeQuotes(String msg) {
        String revised = "";

        for (int i = 0; i < msg.length(); i++) {
            char c = msg.charAt(i);

            if (c != '\"') { 
                revised += c;
            }        
        }
        return revised;
    }

    /**************************************************************************
     * print, prints the message string to the installed output. The format is
     * conform the installed type the level must be lower or equal the installed
     * log level
     * @param printLevel specifies the level for this print, legal values are
     * FATAL, WARNING, MESSAGE, DETAIL, DEBUG or STACK
     * @param msg the string that must be outputted
     * @return Constants.OK or Constants.NOK
     *************************************************************************/
    public static int print(int printLevel, String msg) {
        String newMsg = "";
        int status = Constants.OK;

        // first check if there is a object
        if (log == null) {
            init();
        }

        // then check if we should log
        if (printLevel > level) {
            return Constants.OK;
        }

        // or if we have an output device
        if ((fileLog == false) && (screenLog == false) && (dbLog == false)
                && (mailLog == false)) {
            return Constants.OK;
        }

        // check if level is in bounds
        if ((printLevel < 0) || (printLevel > 6)) {
            print(WARNING, "Log.print illigal level " + printLevel);
            return Constants.NOK;
        }

        // apply format
        if (format == CLEAN) {
            newMsg = "[" + header + "] " + msg;
        } else if (format == TIMED) {
            // need to create a new Calendar, to get now()
            cal = Calendar.getInstance();
            int month = cal.get(cal.MONTH);
            int day = cal.get(cal.DAY_OF_MONTH);
            int hour = cal.get(cal.HOUR_OF_DAY);
            int min = cal.get(cal.MINUTE);
            int sec = cal.get(cal.SECOND);
            int mili = cal.get(cal.MILLISECOND);

            newMsg = "[" + getError(printLevel) + "][" + header + " "
                    + getMonth(month) + " " + fillString(2, day) + " "
                    + fillString(2, hour) + ":" + fillString(2, min) + ":"
                    + fillString(2, sec) + "." + fillString(3, mili) + "] "
                    + msg;
        }

        // output string
        if (fileLog) {
            if (filePrint(newMsg) == Constants.NOK) {
                status = Constants.NOK;
            }
        }
        if (screenLog) {
            if (screenPrint(newMsg) == Constants.NOK) {
                status = Constants.NOK;
            }
        }
        // database has unformated logging !
/*        if (dbLog) {
            if (dbPrint(msg) == Constants.NOK) {
                status = Constants.NOK;
            }
        }
*/        // mailLog has it's own level
        if ((mailLog) && (printLevel <= mailLevel)) {
            if (mailPrint(newMsg) == Constants.NOK) {
                status = Constants.NOK;
            }
        }

        return status;
    }
    ;

    /**************************************************************************/
    private static String getError(int level) {
        if (level == NONE) {
            return "N";
        } else if (level == FATAL) {	
            return "F";
        } else if (level == WARNING) {	
            return "W";
        } else if (level == MESSAGE) {	
            return "M";
        } else if (level == DETAIL) {	
            return "I";
        } else if (level == DEBUG) {	
            return "D";
        } else if (level == STACK) {	
            return "S";
        } else {
            return "?";
        }
    }
	
     /**************************************************************************/
    private static int sendMail(String to_address, // Destinataire du message
            String from_address, // Emeteur du message
            String sSu, // Sujet du message
            String sMess)		    // Message
        throws IOException, ProtocolException, UnknownHostException {
        Socket          socket; // Le Socket
        BufferedReader  in; // Le stream de lecture du Socket
        PrintWriter     out; // Le stream d'ecriture du Socket
        String          str; // Pour la lecture de donnees

        // Ouverture du socket (connection au mailServer)
        // et des streams de lecture et d'ecriture
        socket = new Socket(hostname, 25);

        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(socket.getOutputStream());

        // lecture du message initial
        str = in.readLine();
        if (!str.startsWith("220")) {
            throw new ProtocolException(str);
        }

        while (str.indexOf('-') == 3) {
            str = in.readLine();
            if (!str.startsWith("220")) {
                throw new ProtocolException(str);
            }
        }
        // fin message initial

        // Dialogue avec les Serveur de mail
        // Envoie de HELO au serveur SMTP
        out.println("HELO " + hostname);
        out.flush();
        str = in.readLine();
        if (!str.startsWith("250")) {
            throw new ProtocolException(str);
        }

        // On est connecte au serveur de Mail...

        // Envoie du Mail
        out.println("MAIL FROM: " + from_address);
        out.flush();
        str = in.readLine();
        if (!str.startsWith("250")) {
            throw new ProtocolException(str);
        }

        // A qui envoie t on cela
        out.println("RCPT TO: " + to_address);
        out.flush();
        str = in.readLine();
        if (!str.startsWith("250")) {
            throw new ProtocolException(str);
        }

        // Est on pret a envoyer les donnees
        out.println("DATA");
        out.flush();
        str = in.readLine();
        if (!str.startsWith("354")) {
            throw new ProtocolException(str);
        }

        // Emmeteur - Destinataire - Sujet
        out.println("From: " + from_address);
        out.println("To: " + to_address);
        out.println("Subject: " + sSu + "\n");
        out.flush();

        out.println("Comment: sender " + header);
        out.println("X-Mailer: Lukassen Logging Software");
        out.println("");
        out.println(sMess);
        out.println(".");
        out.flush();

        str = in.readLine();
        if (!str.startsWith("250")) {
            throw new ProtocolException(str);
        }

        out.println("QUIT");
        out.flush();

        in.close();
        socket.close();

        return Constants.OK;
    }
}
