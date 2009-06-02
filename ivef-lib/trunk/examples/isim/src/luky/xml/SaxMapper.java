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
package luky.xml;


import java.io.*;
import java.util.*;
import org.xml.sax.*;
import org.xml.sax.helpers.*;
import luky.util.*;


/******************************************************************************
 * SaxMapper is a simple mapper for XML objects. You can extend it to 
 * app the mapper classes for your XML files <br>
 * <p>
 *
 *  <ul>
 *   <li> 1.0.0 - Release under LGPL (a.b.c) (a=major, b=class compatible, c=api compatible)</li>
 * </ul>
 *
 * @author Chris Lukassen <lukassen@hitt.nl>
 * @version 1.0.0
 ******************************************************************************/
public abstract class SaxMapper extends DefaultHandler {

    public abstract Object getMappedObject();

    public abstract TagTracker createTagTrackerNetwork();

    // A stack for the tag trackers to
    // coordinate on.
    //
    private Stack tagStack = new Stack();

    // The SAX 2 parser...
    private XMLReader xr;

    // Buffer for collecting data from
    // the "characters" SAX event.
    private CharArrayWriter contents = new CharArrayWriter();

    /**************************************************************************
     * default constructor
     **************************************************************************/
    public SaxMapper() {

        try {
            // Create the XML reader...

            // use the recommended xerces parser
            // xr = XMLReaderFactory.createXMLReader("org.apache.xerces.parsers.SAXParser");
            // or the lightweight Picolo parser
            xr = XMLReaderFactory.createXMLReader("com.bluecast.xml.Piccolo");
        } catch (Exception e) {
            e.printStackTrace();
        }	

        // Create the tag tracker network 
        // and initialize the stack with 
        // it.
        //
        // This constructor anchors the tag
        // tracking network to the begining
        // of the XML document. ( before the
        // first tag name is located ).
        //
        // By placing it first on the stack
        // all future tag tracking will follow
        // the network anchored by this
        // root tag tracker.
        //
        // The createTagTrackerNetwork() method
        // is abstract.  All sub classes are 
        // responsible for reacting to this 
        // request with the creation of a 
        // tag tracking network that will 
        // perform the mapping for the sub class.
        //
        Log.print(Log.MESSAGE, "Creating the tag tracker network.");
        tagStack.push(createTagTrackerNetwork());
        Log.print(Log.MESSAGE, "Tag tracker network created.");
		
    }	

    /**************************************************************************
     * creates an mapper from an url
     * @param url location of XML file
     **************************************************************************/
    public Object fromXML(String url) {

        try {
            return fromXML(new InputSource(url));

        } catch (Exception e) {
            e.printStackTrace();
            return null;	
        }
    }

    /**************************************************************************
     * creates an mapper from an input stream
     * @param in location of XML file
     **************************************************************************/
    public Object fromXML(InputStream in) {
        try {
            return fromXML(new InputSource(in));

        } catch (Exception e) {
            e.printStackTrace();
            return null;	
        }
    }

    /**************************************************************************
     * creates an mapper from a reader
     * @param in location of XML file
     **************************************************************************/
    public Object fromXML(Reader in) {
        try {
            return fromXML(new InputSource(in));

        } catch (Exception e) {
            e.printStackTrace();
            return null;	
        }
    }

    private synchronized Object fromXML(InputSource in) throws Exception {

        // notes, 
        // 1.  The calling "fromXML" methods catch 
        // any parsing exceptions.
        // 2.  The method is synchronized to keep 
        // multiple threads from accessing the XML parser
        // at once.  This is a limitation imposed by SAX.


        // Set the ContentHandler...
        xr.setContentHandler(this);

        // Parse the file...
        Log.print(Log.MESSAGE, "About to parser XML document.");
        xr.parse(in);
        Log.print(Log.MESSAGE, "XML document parsing complete.");

        return getMappedObject();
    }

    /**************************************************************************
     * Implement the content hander methods that 
     * will delegate SAX events to the tag tracker network.
     **************************************************************************/
    public void startElement(String namespaceURI,
            String localName,
            String qName,
            Attributes attr) throws SAXException {

        // Resetting contents buffer.
        // Assuming that tags either tag content or children, not both.
        // This is usually the case with XML that is representing 
        // data strucutures in a programming language independant way.
        // This assumption is not typically valid where XML is being 
        // used in the classical text mark up style where tagging 
        // is used to style content and several styles may overlap 
        // at once.
        contents.reset();

        // delegate the event handling to the tag tracker
        // network.
        TagTracker activeTracker = (TagTracker) tagStack.peek();

        activeTracker.startElement(namespaceURI, localName, qName, attr,
                tagStack);

    }

    /**************************************************************************
     * Implement the content hander methods that 
     * will delegate SAX events to the tag tracker network.
     **************************************************************************/
    public void endElement(String namespaceURI,
            String localName,
            String qName) throws SAXException {

        // delegate the event handling to the tag tracker
        // network.
        TagTracker activeTracker = (TagTracker) tagStack.peek();

        activeTracker.endElement(namespaceURI, localName, qName, contents,
                tagStack);

    }

    /**************************************************************************
     * accumulate the contents into a buffer.
     **************************************************************************/
    public void characters(char[] ch, int start, int length)
        throws SAXException {
        // accumulate the contents into a buffer.
        contents.write(ch, start, length);

    }

}
