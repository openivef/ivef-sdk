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
package luky.lua;


import java.io.*;
import java.util.*;
import luky.util.*;


/*******************************************************************************
 * Reads Lua files from HW2 							<br>
 * <br>
 * token:      ( NAME = ( COLLECTION | VALUE ) | DATA | COLLECTION ) , <br>
 * collection: { <TOKEN> } 						<br>
 * name:       String <br>
 * data:       String<br>
 * value:      String <br>
 *   <br>
 * @author Chris Lukassen <lukassen@hitt.nl> 
 * @version 1.00 
 ******************************************************************************/
public class LuaParser { 

    /***************************************************************************
     variables     
     ***************************************************************************/
    private LuaToken rootToken = null;
    private int indent = 0;
    private int tabsize = 4;

    /***************************************************************************
     * default constructor     
     **************************************************************************/    
    public LuaParser() {}    

    /***************************************************************************
     * returns the parsed rootToken, makes most sense after a succesfull readFile
     * @return the parsed rootToken
     **************************************************************************/
    public LuaToken getRootToken() {
        return rootToken;
    }

    /***************************************************************************
     * reads the lua file     
     * @param fileName the name      
     * @return Constants.OK or Constants.NOK     
     **************************************************************************/
    public int readFile(String fileName) {
        BufferedReader in = null;

        // see if it can be opened
        try {
            in = new BufferedReader(new FileReader(fileName));
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "LuaParser.readFile cannot open file " + fileName);
            return Constants.NOK;
        }     

        // try to read it 
        try {
            rootToken = readToken(in);
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "LuaParser.readFile error reading file " + fileName);
            return Constants.NOK;
        }  

        // try to close it        
        try {
            in.close();
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "LuaParser.readFile cannot close file " + fileName);
            return Constants.NOK;
        }
        Log.print(Log.DEBUG, "LuaParser.readFile data read from " + fileName);
        return Constants.OK;
    }

    /***************************************************************************
     * reads the token in the lua file     
     **************************************************************************/
    private LuaToken readToken(BufferedReader in) {
        Log.print(Log.DEBUG, "LuaParser.readToken entered");
        LuaToken token = new LuaToken();

        // check for data fields first
        if (isDataField(in)) {
            Log.print(Log.DEBUG, "LuaParser.readToken found data token");
            token.setData(readUpToAndIncludingChar(in, ','));
        } else { 
            // its  a name follewed by a collection or a value	
            String name = null;

            // there are also nameless collections
            if (!nextChar(in, '{')) {
                name = readName(in);
                token.setName(name);
            } else {
                Log.print(Log.DEBUG, "LuaParser.readToken found nameless token");
            }

            // is it a collection or a value 
            if (nextChar(in, '{')) {
                Log.print(Log.DEBUG,
                        "LuaParser.readToken found collection token");
                token.setCollection(readCollection(in, name));
                // remove ,
                readUpToAndIncludingChar(in, ',');
            } else {
                Log.print(Log.DEBUG,
                        "LuaParser.readToken found valuea token for " + name);
                token.setValue(readValue(in));
                // readValue eats ,
            }
        }

        return token;
    }    

    /***************************************************************************
     * reads the fields in the lua file     
     **************************************************************************/
    private LuaCollection readCollection(BufferedReader in, String name) {
        Log.print(Log.DEBUG, "LuaParser.readCollection entered");
        LuaCollection collection = new LuaCollection(name);

        // remove ,  {
        readUpToAndIncludingChar(in, '{');

        // check for the last field 
        int i = 0;

        while (!(nextChar(in, '}'))) {
            Log.print(Log.DEBUG,
                    "LuaParser.readCollection checking token " + i + " of "
                    + name);
            i++;
            collection.addToken(readToken(in));
        }
        Log.print(Log.DEBUG, "LuaParser.readCollection end of fields detected");
        readUpToAndIncludingChar(in, '}');
        return collection;
    }    

    /***************************************************************************
     * reads the value in the lua file     
     **************************************************************************/
    private String readValue(BufferedReader in) {
        Log.print(Log.DEBUG, "LuaParser.readValue entered");
        return readUpToAndIncludingChar(in, ',');
    }    

    /***************************************************************************
     * reads the name in the lua file     
     **************************************************************************/
    private String readName(BufferedReader in) {
        Log.print(Log.DEBUG, "LuaParser.readName entered");
        return readUpToAndIncludingChar(in, '=');
    } 

    /***************************************************************************
     * verifies the next char     
     **************************************************************************/    
    private boolean nextChar(BufferedReader in, char c) {
        Log.print(Log.DEBUG, "LuaParser.nextChar(" + c + ") entered");
        try {             
            // check in the next 20 chars 
            in.mark(20);
            char ch = '?';

            while (in.ready()) {
                int i = in.read();

                if (i < 0) {
                    Log.print(Log.FATAL, "LuaParser.nextChar read error");
                }
                ch = (String.valueOf((char) i)).charAt(0);
                if (ch == c) {
                    Log.print(Log.DEBUG, "LuaParser.nextChar(" + c + ") found");
                    in.reset();
                    return true;
                }   
                // skip some chars
                if (!((ch == '\n') || (ch == ' ') || (ch == '\r'))) {
                    break;
                }
            }
            Log.print(Log.DEBUG,
                    "LuaParser.nextChar(" + c + ") not found, but (" + ch + ")");
            in.reset();
        } catch (Exception e) {
            Log.print(Log.FATAL, "LuaParser.nextChar exeception " + e);
        }
        return false;
    }
    
    /***************************************************************************
     * verifies the next char is a data field
     **************************************************************************/    
    private boolean isDataField(BufferedReader in) {
        Log.print(Log.DEBUG, "LuaParser.isDataField entered");
        try {             
            // check in the next 100 chars 
            in.mark(100);

            char ch = '?';
            int count = 0;

            while (in.ready()) {
                int i = in.read();

                if (i < 0) {
                    Log.print(Log.FATAL, "LuaParser.isDataField read error");
                }
                ch = (String.valueOf((char) i)).charAt(0);
                if (ch == '=') {
                    Log.print(Log.DEBUG, "LuaParser.isDataField = found (false)");
                    in.reset();
                    return false;
                }   
                if (ch == ',') {
                    Log.print(Log.DEBUG, "LuaParser.isDataField , found (true)");
                    in.reset();
                    return true;
                }   
                if (count++ > 100) {
                    Log.print(Log.DEBUG,
                            "LuaParser.isDataField nothing found (false)");
                    in.reset();
                    break;
                }   
            }
            Log.print(Log.DEBUG, "LuaParser.isDataField syntax error");
            in.reset();
        } catch (Exception e) {
            Log.print(Log.FATAL, "LuaParser.isDataField exeception " + e);
        }
        return false;
    }
    
    /***************************************************************************
     * reads an item     
     **************************************************************************/
    private String readUpToAndIncludingChar(BufferedReader in, char c) {
        Log.print(Log.DEBUG,
                "LuaParser.readUpToAndIncludingChar(" + c + ") entered");
        String result = "";
        char ch = '?';

        try {
            while (in.ready()) {
                int i = in.read();

                if (i < 0) {
                    Log.print(Log.FATAL,
                            "LuaParser.readUpToAndIncludingChar read error");
                }
                ch = (String.valueOf((char) i)).charAt(0);

                if (ch == c) {
                    break;
                }
                result += ch;
            }
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "LuaParser.readUpToAndIncludingChar exeception " + e);
        }

        // check for EOF
        if (ch != c) {
            Log.print(Log.MESSAGE,
                    "LuaParser.readUpToAndIncludingChar found end of file ");
        }

        // clean up 
        result = result.replace('\n', ' ');
        result = result.replace('\r', ' ');
        result = result.trim();
        Log.print(Log.DEBUG,
                "LuaParser.readUpToAndIncludingChar(" + c + ") found: ["
                + result + "]");
        return result;
    }   
 
    /***************************************************************************
     * writes the indent
     **************************************************************************/
    private void writeIndent(PrintWriter out) {

        for (int i = 0; i < indent * tabsize; i++) {
            out.print(" ");
        }

    }

    /***************************************************************************
     * writes the string
     **************************************************************************/
    private void writeStringWithNewLine(PrintWriter out, String str) {

        writeIndent(out);
        out.println(str);
    }

    /***************************************************************************
     * writes the string
     **************************************************************************/
    private void writeString(PrintWriter out, String str) {

        writeIndent(out);
        out.print(str);
    }

    /***************************************************************************
     * writes the token
     **************************************************************************/
    private int writeToken(PrintWriter out, LuaToken token) {

        if (token == null) {

            Log.print(Log.MESSAGE, "LuaParser.writeToken (null) ??");
            return Constants.NOK;
        }
	
        // token:      ( NAME = ( COLLECTION | VALUE ) | DATA | COLLECTION ) , 

        if (token.isData) {

            Log.print(Log.DEBUG, "LuaParser.writeToken (data) entered");
            writeStringWithNewLine(out, token.getData() + ",");
	
        } else if (token.isValue) {
            Log.print(Log.DEBUG,
                    "LuaParser.writeToken (" + token.getName() + ") entered");

            // may have a name
            if (token.getName() != null) {
                writeStringWithNewLine(out,
                        token.getName() + " = " + token.getValue() + ",");
            } else {
                writeStringWithNewLine(out, token.getValue() + ",");
            }
        } else if (token.isCollection) {
            Log.print(Log.DEBUG,
                    "LuaParser.writeToken (" + token.getName() + ") entered");
            writeCollection(out, token.getName(), token.getCollection());
            // write the comma in the writeCollection, to avoid newline
            // writeStringWithNewLine( out, "," );

        } else {
            Log.print(Log.FATAL,
                    "LuaParser.writeToken (" + token.getName()
                    + ") is illigal token");
        }

        return Constants.OK;
    }

    /***************************************************************************
     * writes the collection
     **************************************************************************/
    private int writeCollection(PrintWriter out, String name, LuaCollection collection) {

        if (collection == null) {

            Log.print(Log.MESSAGE, "LuaParser.writeToken (null) ??");
            return Constants.NOK;
        }
	
        // collection: { <TOKEN> } 						

        Log.print(Log.DEBUG, "LuaParser.writeToken entered");

        // may have a name
        if (name != null) {
            writeStringWithNewLine(out, name + " = {");
        } else {
            writeStringWithNewLine(out, "{");
        }
        indent++;
        for (int i = 0; i < collection.getSize(); i++) {
            writeToken(out, collection.getToken(i));
        }
        indent--;
        writeStringWithNewLine(out, "},");
	
        return Constants.OK;
    }

    /***************************************************************************
     * writes the lua file     
     * @param fileName the name      
     * @return Constants.OK or Constants.NOK     
     **************************************************************************/
    public int writeFile(String fileName) {
        PrintWriter out = null;

        // see if it can be opened
        try {
            out = new PrintWriter(new FileWriter(fileName));
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "LuaParser.writeFile cannot open file " + fileName);
            return Constants.NOK;
        }     

        // try to write it 
        try {
            writeToken(out, rootToken); 
	    
        } catch (Exception e) {
            Log.print(Log.FATAL,
                    "LuaParser.writeFile error reading file " + fileName);
            return Constants.NOK;
        }  

        // try to close it        
        try {
            out.flush();
            out.close();
        } catch (Exception e) {
            Log.print(Log.WARNING,
                    "LuaParser.writeFile cannot close file " + fileName);
            return Constants.NOK;
        }
        Log.print(Log.DEBUG, "LuaParser.writeFile data written to " + fileName);
        return Constants.OK;
    }

    /**************************************************************************
     * main routine used for testing     
     * @param args the arguments that were used to start the server     
     **************************************************************************/
    public static void main(String args[]) {
        if (args.length < 1) {
            System.out.println("need a filename...");
        } else {
            if (args.length > 1) {  
                // assume debug level 
                try {
                    int level = Integer.parseInt(args[1]);

                    Log.setLogLevel(level);
                } catch (Exception e) {
                    Log.print(Log.FATAL,
                            "LuaParser.main wrong level (1-6): " + args[1]);
                    Log.setLogLevel(Log.DEBUG);
                }
            } else {
                Log.setLogLevel(Log.FATAL);
            }
            Log.setOutput(Log.SCREEN, true);
            Log.setModuleName("LuaParser");
            LuaParser parser = new LuaParser();

            Log.print(Log.DEBUG, "LuaParser.main(+" + args[0] + ")");
            if (parser.readFile(args[0]) == Constants.NOK) {
                System.out.println("Error parsing file...");
            } else {
                // print the records 
                System.out.println(
                        "File parsed ok, writing to " + args[0] + ".out"); 
                if (parser.writeFile(args[0] + ".out") == Constants.NOK) {
                    System.out.println("Error writing file...");
                }
            }
        }
    }
}
