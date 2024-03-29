/* 
 *  Schema
 *
 *  Schema is free software: you can redistribute it and/or modify
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


public class Schema { 


    public Schema() {

    }

    public Schema(Schema val) {

    }

    public String getElementFormDefault() {

        return "qualified";
    }

    public String getTargetNamespace() {

        return "http://www.mvi.org/XMLSchema/mvi/2.0";
    }

    public String toXML() {

       return toXML(true);

    }

    public String toXML(boolean outputNamespace) {

        String xml = "<Schema";
        if (outputNamespace) {
            xml += " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"";
            xml += " xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"";
        };

        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

        xml += "/>\n";
        return xml;
    }

    public String toString(String lead) {

        String str = lead + "Schema\n";
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(TimeZone.getTimeZone("UTC"));
        DecimalFormat nf = new DecimalFormat();
        nf.setMinimumFractionDigits(6);
        nf.setGroupingSize(0);

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
