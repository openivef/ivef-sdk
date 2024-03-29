/* 
 *  Message
 *
 *  Message is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY ); without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 **********************************************************************************
 *  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
 *  Generated by schema2code on Mon Jan 14 21:23:33 2013.
 **********************************************************************************
 *  Copyright 2010
 *
 */

package tst;

import java.util.*;
import java.text.DecimalFormat;
import java.text.DateFormat;
import java.text.SimpleDateFormat;


public class Message { 

    private Vector<Argument> m_arguments = new Vector<Argument>();
    private Date m_timeStamp; // default value is uninitialized
    private boolean m_timeStampPresent;
    private int m_code; // default value is uninitialized
    private boolean m_codePresent;
    private String m_version; // default value is uninitialized
    private boolean m_versionPresent;

    public Message() {

        m_timeStampPresent = false;
        m_codePresent = false;
        m_version = "1.0.0";
        m_versionPresent = true;
    }

    public Message(Message val) {

        for(int i=0; i < val.countOfArguments(); i++ ) {
            m_arguments.add( val.getArgumentAt(i) );
        }
        m_timeStamp = val.getTimeStamp();
        if (val != null) {
            m_timeStampPresent = true;
        }
        m_code = val.getCode();
        if (val != null) {
            m_codePresent = true;
        }
        m_version = val.getVersion();
        if (val != null) {
            m_versionPresent = true;
        }
    }

    public boolean removeArgument(String val) {
        if (m_arguments.size() <= 0) {
            return false; // scalar already at minOccurs
        }

        m_arguments.remove(val);
        return true;
    }

    public boolean addArgument(String val) {
        if (m_arguments.size() >= 10) {
            return false; // scalar already at maxOccurs
        }

        if (val.length() < 1)
            return false;
        if (val.length() > 1024)
            return false;
        m_arguments.add(val);
        return true;
    }

    public String getArgumentAt(int i) {

        return m_arguments.get(i);
    }

    public int countOfArguments() {

        return m_arguments.size();
    }

    public boolean setTimeStamp(Date val) {

        m_timeStampPresent = true;
        m_timeStamp = val;
        return true;
    }

    public Date getTimeStamp() {

        return m_timeStamp;
    }

    public boolean setCode(int val) {

        if ( ( val != 1 ) &&
             ( val != 2 ) &&
             ( val != 3 ) )
            return false;
        m_codePresent = true;
        m_code = val;
        return true;
    }

    public int getCode() {

        return m_code;
    }

    public boolean setVersion(String val) {

        m_versionPresent = true;
        m_version = val;
        return true;
    }

    public String getVersion() {

        return m_version;
    }

    public String toXML() {

       return toXML(true);

    }

    public String toXML(boolean outputNamespace) {

        String xml = "<Message";
        if (outputNamespace) {
            xml += " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            xml += " xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"";
        };

        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        if ( m_timeStampPresent ) {
            xml += " TimeStamp=\"" + df.format(m_timeStamp) + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        if ( m_codePresent ) {
            xml += " Code=\"" + m_code + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        if ( m_versionPresent ) {
            xml += " Version=\"" + encode( m_version) + "\"";
        } else { 
            return null; // not all required attributes have been set 
        } 
        String dataMember;
        xml += ">\n";
        if (m_arguments.size() < 0) {
            return null; // not enough values
        }
        if (m_arguments.size() > 10) {
            return null; // too much values
        }
        for(int i=0; i < m_arguments.size(); i++ ) {
           xs:string attribute = m_arguments.get(i);
            xml += "<Argument>" + m_argument +  "</Argument>";
        } 
        xml += "</Message>\n";
        return xml;
    }

    public String toString(String lead) {

        String str = lead + "Message\n";
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

            str +=  lead + "    TimeStamp = " + df.format(m_timeStamp) + "\n";
            str +=  lead + "    Code = " + m_code + "\n";
            str +=  lead + "    Version = " + m_version + "\n";
        for(int i=0; i < m_arguments.size(); i++ ) {
           str += lead + "    " + m_argument;
        return str;
    }
    public String encode( String str) {

        str = str.replaceAll("&", "&amp;");
        str = str.replaceAll("<", "&lt;");
        str = str.replaceAll(">", "&gt;");
        str = str.replaceAll("\"", "&quot;");
        return str;
    }


}
