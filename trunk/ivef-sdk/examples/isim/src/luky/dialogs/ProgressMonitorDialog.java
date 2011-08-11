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
package luky.dialogs;


import java.awt.*;
import java.util.*;
import javax.swing.*;
import luky.util.*;


/******************************************************************************
 * The ProgressMonitor is an improved version of Java's ProgressMonitor
 * @author Chris Lukassen <lukassen@luky.nl>
 * @version 1.00
 ******************************************************************************/
public class ProgressMonitorDialog extends JDialog implements Runnable {

    private Thread kick = null;
    protected boolean isRunning = true;
    private JProgressBar progressBar = new JProgressBar();
    private JLabel text = new JLabel();
    private JLabel note = new JLabel();
    // Java 1.5 compatibility
    private final static long serialVersionUID = 42L;

    /**************************************************************************
     * Constructor
     **************************************************************************/
    public ProgressMonitorDialog() {

        Log.print(Log.DEBUG, "ProgressMonitorDialog.constructor entered");

        setTitle("ProgressMonitorDialog");
        setModal(false);
        setMinimum(0);
        setMaximum(500);
        setText("Progress...");
        setLayout();
    }

    /**************************************************************************
     * Constructor
     **************************************************************************/
    public ProgressMonitorDialog(String title, int min, int max, String text) {

        Log.print(Log.DEBUG,
                "ProgressMonitorDialog.constructor entered: " + title + " "
                + " (" + min + ".." + max + ") " + text);

        setTitle(title);
        setModal(false);
        setMinimum(min);
        setMaximum(max);
        setText(text);
        setLayout();
    }

    /**************************************************************************/
    private void setLayout() {

        Log.print(Log.DEBUG, "ProgressMonitorDialog.setLayout entered");

        Log.print(Log.STACK, "ProgressMonitorDialog.setLayout setting font");
        text.setFont(text.getFont().deriveFont(Font.BOLD));

        Log.print(Log.STACK, "ProgressMonitorDialog.setLayout setting layout");
        getContentPane().setLayout(new BorderLayout());
        Log.print(Log.STACK,
                "ProgressMonitorDialog.setLayout adding progressBar");
        getContentPane().add(BorderLayout.SOUTH, progressBar);
        Log.print(Log.STACK, "ProgressMonitorDialog.setLayout adding note");
        getContentPane().add(BorderLayout.CENTER, note);        
        Log.print(Log.STACK, "ProgressMonitorDialog.setLayout adding text");
        getContentPane().add(BorderLayout.NORTH, text);        
        Log.print(Log.STACK,
                "ProgressMonitorDialog.setLayout setting close operation");
        setDefaultCloseOperation(JDialog.DO_NOTHING_ON_CLOSE);

        Log.print(Log.STACK, "ProgressMonitorDialog.setLayout setting size");
        setSize(300, 300);
        // Log.print(Log.STACK, "ProgressMonitorDialog.setLayout setting visible");
        // setVisible(true);
        Log.print(Log.STACK,
                "ProgressMonitorDialog.setLayout setting indeterminate");
        setIndeterminate(true);

        Log.print(Log.DEBUG, "ProgressMonitorDialog.setLayout done");
    }

     /**************************************************************************
     * Sets the icon of dialog (default none)
     * @param icon 
     **************************************************************************/
    public void setIcon(Icon icon) {
        Log.print(Log.DEBUG, "ProgressMonitorDialog.setIcon entered: " + icon);
        text.setIcon(icon);
    }

    /**************************************************************************
     * Sets the note of dialog (default none)
     * @param note 
     **************************************************************************/
    public void setNote(String note) {
        Log.print(Log.DEBUG, "ProgressMonitorDialog.setNote entered: " + note);
        this.note.setText(note);
    }

    /**************************************************************************
     * Sets the text of dialog (default "Progress...")
     * @param text 
     **************************************************************************/
    public void setText(String text) {
        Log.print(Log.DEBUG, "ProgressMonitorDialog.setText entered: " + text);
        this.text.setText(text);
    }

    /**************************************************************************
     * Sets the max of the progressbar (default 500)
     * @param max max value
     **************************************************************************/
    public void setMaximum(int max) {
        Log.print(Log.DEBUG, "ProgressMonitorDialog.setMaximum entered: " + max);
        progressBar.setMaximum(max);
    }
	
    /**************************************************************************
     * Sets the min of the progressbar (default 0)
     * @param min min value
     **************************************************************************/
    public void setMinimum(int min) {
        Log.print(Log.DEBUG, "ProgressMonitorDialog.setMinimum entered: " + min);
        progressBar.setMinimum(min);
    }

    /**************************************************************************
     * Gets the progress of the bar
     **************************************************************************/
    public int getValue() {
        Log.print(Log.DEBUG,
                "ProgressMonitorDialog.getValue entered: "
                + progressBar.getValue());
        return progressBar.getValue();
    }

    /**************************************************************************
     * Sets the progress of the bar
     * @param progress 
     **************************************************************************/
    public void setValue(int progress) {
        Log.print(Log.DEBUG,
                "ProgressMonitorDialog.setValue entered: " + progress);
        progressBar.setValue(progress);
    }

    /**************************************************************************
     * Sets the indeterminate of the progressbar (default true)
     * @param indeterminate 
     **************************************************************************/
    public void setIndeterminate(boolean indeterminate) {
        Log.print(Log.DEBUG,
                "ProgressMonitorDialog.setIndeterminate entered: "
                + indeterminate);
        progressBar.setIndeterminate(indeterminate);
    }

    /**************************************************************************
     * Sets if the the progressbar string should be displayed (default false)
     * @param b 
     **************************************************************************/
    public void setStringPainted(boolean b) {
        Log.print(Log.DEBUG,
                "ProgressMonitorDialog.setStringPainted entered: " + b);
        progressBar.setStringPainted(b);
    }

    /**************************************************************************
     * Show the dialog 
     **************************************************************************/
    public void run() {
        Log.print(Log.DEBUG, "ProgressMonitorDialog.run entered");
        setVisible(true);
        Log.print(Log.DEBUG, "ProgressMonitorDialog.run completed");
    }

    /**************************************************************************
     *  This method stops the client
     **************************************************************************/
    public synchronized void stop() {

        super.setVisible(false);

        if (kick != null) {
            isRunning = false;
            kick = null;
        }
    }

    /**************************************************************************
     *  Overriding since this can cause deadlock
     *  @param setVisible Visible or not (equals start or stop)
     **************************************************************************/
    public void setVisible(boolean setVisible) {

        if (setVisible) {
            start();
        } else {
            stop();
        }
    }

    /**************************************************************************
     *  This method starts the client in a seperate thread
     **************************************************************************/
    public void start() {

        if (kick == null) {
            isRunning = true;
            Log.print(Log.DEBUG, "ProgressMonitorDialog.start thread");
            kick = new Thread(this);
            kick.setPriority(Thread.MIN_PRIORITY);
            kick.start();
        }
    }
    
}

