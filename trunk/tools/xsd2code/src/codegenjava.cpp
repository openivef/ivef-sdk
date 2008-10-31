/*
 *  codegenqt.cpp
 *
 *  xsd2code is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  xsd2code is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Created by Lukassen on 11/06/08.
 *  Copyright 2008
 *
 */

#include <cstdlib>

#include "codegenjava.h"

CodeGenJava::CodeGenJava()
: CodeGen()
{
        m_prefix = "";
}

void CodeGenJava::setObjects(QVector<XSDObject*>objects) {
    m_objects = objects;
}

void CodeGenJava::setOutputDir(QString outDir) {
    m_outDir = outDir;
}

QString CodeGenJava::localType(QString type) {
    if (type == "xs:string")
        return "String";
    else if (type == "xs:boolean")
        return "boolean";
    else if (type == "xs:integer")
        return "int";
    else if (type == "xs:dateTime") 
        return "Date";
    else if (type == "xs:hexBinary") 
        return "String";
    else if (type == "unknown") {
        std::cout << "WARNING unknown type found:" << type.toLatin1().data() <<  ", defaulting to String" << std::endl;
        return "String";
    }
    else if (type == "xs:decimal") // double
        return "double";
    else
        return type;
}

bool CodeGenJava::knownType(QString type) {
    if (type == "xs:string")
        return true;
    else if (type == "xs:boolean")
        return true;
    else if (type == "xs:integer")
        return true;
    else if (type == "xs:dateTime")
        return true;
	else if (type == "xs:hexBinary") 
		return true;
    else if (type == "unknown")
        return true;
    else if (type == "xs:decimal") // double
        return true;
    else
        return false;
}

QString CodeGenJava::className(QString name) {
    return /*m_prefix +*/ name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenJava::fileBaseName(QString name) {
      return className(name);
}

QString CodeGenJava::variableName(QString name) {

    if (name.mid(1,1).toUpper() == name.mid(1,1)) { // if second char is uppercase
        return "m_" + name;
    } else {
        return "m_" + name.replace(0, 1, name.left(1).toLower());
    }
}

QString CodeGenJava::writeHeader(QString fileName) {

    QString header;
    header.append( "/* \n" );
    header.append( " *  " + fileName + "\n" );
    header.append( " *\n" );
    header.append( " *  " + fileName + " is free software: you can redistribute it and/or modify\n" );
    header.append( " *  it under the terms of the GNU Lesser General Public License as published by\n" );
    header.append( " *  the Free Software Foundation, either version 3 of the License, or\n" );
    header.append( " *  (at your option) any later version.\n" );
    header.append( " *\n" );
    header.append( " *  Foobar is distributed in the hope that it will be useful,\n" );
    header.append( " *  but WITHOUT ANY WARRANTY ); without even the implied warranty of\n" );
    header.append( " *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" );
    header.append( " *  GNU General Public License for more details.\n" );
    header.append( " *\n" );
    header.append( " **********************************************************************************\n" );
    header.append( " *  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD\n" );
    header.append( " *  Generated by xsd2code on "+  QDateTime::currentDateTime().toString() + ".\n" );
    header.append( " **********************************************************************************\n" );
    header.append( " *  Copyright 2008\n" );
    header.append( " *\n" );
    header.append( " */\n\n" );

    return header;
}

QString CodeGenJava::methodName(QString name) {
    return name.replace(0, 1, name.left(1).toUpper());
}

void CodeGenJava::go() {

    // first analyse the objects if they are embedded objects
    // for all objects that could accept such an object
    QString nameSpace = "none";
    bool useNameSpace = false;
    for(int i=0; i < m_objects.size(); i++) {
        // for all objects
        XSDObject *obj1 = m_objects.at(i);

        // find if there is another object that refers to the obj
        for(int h=0; h < m_objects.size(); h++) {

            XSDObject *obj2 = m_objects.at(h);

            // refers means obj2 has an attribute of type obj1
            for(int j=0; j < obj2->attributes().size(); j++) {
                XSDAttribute *attr = obj2->attributes().at(j);
                QString objType = attr->type();

                if (objType == obj1->name()) {
                    obj1->setEmbedded();    // obj1 is embedded in obj2
                }
            }
        }

        // find out what our namespace is
        if (obj1->name() == "Schema") {
	    for(int j=0; j < obj1->fixedValues().size(); j++) {
	        QString attrName = obj1->fixedValues().keys().at(j);
                if (attrName == "targetNamespace") {
                    nameSpace = obj1->fixedValues().values().at(j);
                    std::cout << "Using namespace: " << nameSpace.toLatin1().data() << std::endl;
                    useNameSpace = true;
                }
	    }
	}
    }

	QString package = "xsd2code";
    if (m_prefix != "") { 
        package =  m_prefix.toLower();
    }

    for(int i=0; i < m_objects.size(); i++) {
        // get a class
        XSDObject *obj = m_objects.at(i);

        // get some vars we frequently use
        QString name = obj->name();
        QString upperName = name.toUpper();
        QString lowerName = name.toLower();
        QVector<XSDAttribute*>attributes = obj->attributes();
        QMap<QString, QString>fixedValues = obj->fixedValues();

        // report
        std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;

        // and the class file
        QString baseName = m_outDir + "/" + package + "/" + fileBaseName(name);
        QFile classFile(baseName + ".java");
        if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("cannot create file: %1").arg(baseName + ".java").toLatin1().data() << std::endl;
            std::exit(-1);
        }
        QTextStream classFileOut(&classFile);

        //-----------------------------------------------------------------------------------------------
        // generate the declaration
        //-----------------------------------------------------------------------------------------------
        classFileOut << writeHeader( className(name) );
 
        classFileOut << "package " << package << ";\n\n";

		classFileOut << "import java.util.*;\n";
        classFileOut << "import java.text.DateFormat;\n";
		classFileOut << "import java.text.SimpleDateFormat;\n\n";


        // include dependend files
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            if(!knownType(attr->type())) {
                classFileOut << "import " << package << "." << fileBaseName(attr->type()) << ";\n";
            }
        }

        // define the class
        classFileOut << "\npublic class " << className(name) << " { \n\n";

        // variables section
        // all attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString type = localType(attr->type()); // convert to java types
            // definition
            if (attr->unbounded()) { // there more then one
                classFileOut << "    private Vector<" << className(attr->name()) << "> " << variableName(attr->name()) << "s = new Vector<" << className(attr->name()) << ">();\n";
            } else {
                classFileOut << "    private " << type << " " << variableName(attr->name()) << "; // default value is uninitialized\n";
            }
            if (!attr->required() || obj->isMerged()) {
                classFileOut << "    private boolean " << variableName(attr->name()) << "Present;\n";
            }
        }

        //-----------------------------------------------------------------------------------------------
        // create the implementation 
        //-----------------------------------------------------------------------------------------------

        // constructor
        classFileOut << "\n    public " << className(name) << "() {\n\n";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString niceVarName  = attr->name().replace(0, 1, attr->name().left(1).toLower());
            if (!attr->required() || obj->isMerged()) {
                classFileOut << "        " << variableName(attr->name()) << "Present = false;\n";
            }
        }
        classFileOut << "    }\n\n";

        // copy constructor
        classFileOut << "    public " << className(name) << "(" << className(name) << " val) {\n\n";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to java types
            if ((!attr->required() || obj->isMerged()) && !attr->unbounded()) {
                classFileOut << "        " << variableName(attr->name()) << "Present = val.has" << methodName(attr->name()) << "();\n";
            }
            if (attr->unbounded()) { // there more then one
                classFileOut << "        for(int i=0; i < val.countOf" << methodName(attr->name()) << "s(); i++ ) {\n";
                classFileOut << "            " << variableName(attr->name()) << "s.add( val.get" << methodName(attr->name()) << "At(i) );\n";
                classFileOut << "        }\n";
            } else {
                classFileOut << "        " << variableName(attr->name()) << " = val.get" << methodName(attr->name()) << "();\n";
            }
        }
        classFileOut << "    }\n\n";
       
        // methods for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to java types
            if (attr->unbounded()) { // there more then one
                // setter
                classFileOut << "    public void " << "add" << methodName(attr->name()) << "(" << type << " val) {\n";
                classFileOut << "\n        " << variableName(attr->name()) << "s.add(val);\n    }\n\n";
                // getter
                classFileOut << "    public " << type << " " << "get" << methodName(attr->name()) << "At(int i) {\n";
                classFileOut << "\n        return ("<< className(attr->name()) << ") " << variableName(attr->name()) << "s.get(i);\n    }\n\n";
                // count
                classFileOut << "    public int countOf" << methodName(attr->name()) << "s() {\n";
                classFileOut << "\n        return " << variableName(attr->name()) << "s.size();\n    }\n\n";
            } else {
                // setter
                classFileOut << "    public void set" << methodName(attr->name()) << "(" << type << " val) {\n";
                QVector<QString> enums = attr->enumeration();
                if (enums.size() > 0) { // there are enumeration constraints for this item

                    // strings should be between quotes, numbers not
                    QString quote;
                    if (type == "String") {
                        quote = "\"";
                    }

                    classFileOut << "\n        if ( ( val != " << quote << enums.at(0) << quote <<" ) ";
                    for (int h=1; h < enums.size(); h++) {
                        classFileOut << "&&\n             ( val != " << quote << enums.at(h) << quote << " ) ";
                    }
                    classFileOut <<    ")\n            return;";
                }
                if (attr->hasMin() && (attr->hasMax())) {
                     classFileOut << "\n        if (val < " << attr->min() << ")\n            return;";
                     classFileOut << "\n        if (val > " << attr->max() << ")\n            return;";
                }
                if (!attr->required() || obj->isMerged()) {
                     classFileOut << "\n        " << variableName(attr->name()) << "Present = true;";
                }
                classFileOut << "\n        " << variableName(attr->name()) << " = val;\n    }\n\n";
                // getter
                classFileOut << "    public " << type << " get" << methodName(attr->name()) << "() {\n";
                classFileOut << "\n        return " << variableName(attr->name()) << ";\n    }\n\n";
                if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    public boolean has" << methodName(attr->name()) << "() {\n";
                    classFileOut << "\n        return " << variableName(attr->name()) << "Present;\n    }\n\n";
                }
            }
        }

        // and fixed values
        for(int j=0; j < fixedValues.size(); j++) {
            QString attrName = fixedValues.keys().at(j);
            QString attrValue = fixedValues.values().at(j);
            QString type = "String"; // always a string

            // getter
            classFileOut << "    public " << type << " get" << methodName(attrName) << "() {\n";
            classFileOut << "\n        return \"" << attrValue << "\";\n    }\n\n";
        }

        // xml generator
        // if attribute name and type are the same it means it was data
        classFileOut << "    public String toXML() {\n\n";
        classFileOut << "        String xml = \"<" << name << "\";\n"; // append attributes
        classFileOut << "        DateFormat df = new SimpleDateFormat(\"yyyy-MM-ddThh:mm:ss.zzz\");\n";
		classFileOut << "\n";

        // for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to java types
            QString varName = variableName(attr->name());

            if (attrType != attr->name()) {

                // non-qstring items (ints) may give problems, so convert them
                if (type == "Date") {
				    varName = "df.format(" + variableName(attr->name()) + ")"; 
					// ".toString(\"yyyy-MM-ddThh:mm:ss.zzz\")";
                } /*else  if (type != "String") {
                    varName = "String.number(" + variableName(attr->name()) + ")";
                } */
                // check if the attribute exist
                if ((!attr->required() || obj->isMerged()) && !attr->unbounded()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "            xml += \" " << attr->name() << "=\\\"\" + " << varName << " + \"\\\"\";\n        }\n";
                } else {
                    classFileOut << "        xml += \" " << attr->name() << "=\\\"\" + " << varName << " + \"\\\"\";\n";
                }
            }
        }
        classFileOut << "        xml += \">\\n\";\n"; // close the statement

        // for data members
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();

            if (attrType == attr->name()) {
                // check if the attribute exist
                if (attr->unbounded() ) {
                    classFileOut << "        for(int i=0; i < " << variableName(attr->name()) << "s.size(); i++ ) {\n";
                    classFileOut << "           " << attrType << " attribute = ("<< className(attr->name()) << ") " << variableName(attr->name()) << "s.get(i);\n";
                    classFileOut << "            xml += attribute.toXML();\n        }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "            xml += " << " " << variableName(attr->name()) << ".toXML() ;\n            }\n";
                } else {
                    classFileOut << "        xml += " << " " << variableName(attr->name()) << ".toXML();\n";
                }
            }
        }

        // close up
        classFileOut << "        xml += \"</" << name << ">\\n\";\n"; // append attributes
        classFileOut << "        return xml;\n";
        classFileOut << "    }\n\n";

        // string generator
        // if attribute name and type are the same it means it was data
        classFileOut << "    public String toString(String lead) {\n\n";
        classFileOut << "        String str = lead + \"" << name << "\\n\";\n"; // append attributes
        classFileOut << "        DateFormat df = new SimpleDateFormat(\"yyyy-MM-ddThh:mm:ss.zzz\");\n";
		classFileOut << "\n";
                    
        // for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to java types
            QString varName = variableName(attr->name());

            if (attrType != attr->name()) {

                // non-qstring items (ints) may give problems, so convert them
                if (type == "Date") {
				    varName = "df.format(" + variableName(attr->name()) + ")"; 
					// ".toString(\"yyyy-MM-ddThh:mm:ss.zzz\")";
                } /*else  if (type != "String") {
                    varName = "String.number(" + variableName(attr->name()) + ")";
                } */
                // check if the attribute exist
                if ((!attr->required() || obj->isMerged()) && !attr->unbounded()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "            str +=  lead + \"    " << attr->name() << " = \" + " << varName << " + \"\\n\";\n        }\n";
                } else {
                    classFileOut << "        str +=  lead + \"    " << attr->name() << " = \" + " << varName << " + \"\\n\";\n";
                }
            }
        }

        // for data members
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();

            if (attrType == attr->name()) {
                // check if the attribute exist
                if (attr->unbounded() ) {
                    classFileOut << "        for(int i=0; i < " << variableName(attr->name()) << "s.size(); i++ ) {\n";
                    classFileOut << "           " << attrType << " attribute = ("<< className(attr->name()) << ") " << variableName(attr->name()) << "s.get(i);\n";
                    classFileOut << "           str += attribute.toString(lead + \"    \");\n        }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "            str += " << " " << variableName(attr->name()) << ".toString(lead + \"    \") ;\n        }\n";
                } else {
                    classFileOut << "        str += " << " " << variableName(attr->name()) << ".toString(lead + \"    \");\n";
                }
            }
        }

        // close up
        classFileOut << "        return str;\n";
        classFileOut << "    }\n";

        // round up
        classFileOut << "\n}\n"; // make sure there is a newline at the end of the source

        // close and flush
        classFileOut.flush();
        classFile.close();
    }

    //-----------------------------------------------------------------------------------------------
    // now generate the parser
    //-----------------------------------------------------------------------------------------------

    // generate the parser file
    QString name = "Parser";
    QString fileName = m_outDir + "/" +  package + "/" + fileBaseName(name) + ".java";
    QFile classFile(fileName);
    if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(fileName).toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream classFileOut(&classFile);
    std::cout << QString("creating class: %1, %2").arg(className(name), fileName).toLatin1().data() << std::endl;

    //-----------------------------------------------------------------------------------------------
    // generate the declaration
    //-----------------------------------------------------------------------------------------------
    classFileOut << writeHeader( className(name) );

    classFileOut << "package " << package << ";\n\n";

    classFileOut << "import java.util.*;\n";
    classFileOut << "import java.text.DateFormat;\n\n";
	classFileOut << "import java.text.SimpleDateFormat;\n";
    classFileOut << "import javax.xml.parsers.*;\n";
    classFileOut << "import org.xml.sax.*;\n";
    classFileOut << "import org.xml.sax.helpers.*;\n";

    // include dependend files
	 for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if (obj->name() != "Schema") {
           classFileOut << "import " << package << "." << fileBaseName(obj->name()) << ";\n";
        }
    }

    // define the class
    classFileOut << "\npublic abstract class " << className(name) << " extends DefaultHandler { \n\n";

	// public overrides
	classFileOut << "    // subclass these methods to receive events \n";
	for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if (obj->name() != "Schema") {
           classFileOut << "    public abstract void signal" << className(obj->name()) << "(" << className(obj->name()) << " obj);\n";
        }
    }
	
	// variables
    classFileOut << "    private String m_dataBuffer = new String();\n";
    classFileOut << "    private Stack m_objStack = new Stack(); // cannot use a template since it stores different Objects\n";
	classFileOut << "    private SAXParser parser; // init in constructor\n";

    // constructor
    classFileOut << "\n    public " << className(name) << "() {\n\n";
	classFileOut << "        String jaxpPropertyName =\n";
    classFileOut << "          \"javax.xml.parsers.SAXParserFactory\";\n";
    classFileOut << "        // Pass the parser factory in on the command line with\n";
    classFileOut << "        // -D to override the use of the Apache parser.\n";
    classFileOut << "        if (System.getProperty(jaxpPropertyName) == null) {\n";
    classFileOut << "          String apacheXercesPropertyValue =\n";
    classFileOut << "            \"org.apache.xerces.jaxp.SAXParserFactoryImpl\";\n";
    classFileOut << "          System.setProperty(jaxpPropertyName,\n";
    classFileOut << "                             apacheXercesPropertyValue);\n";
    classFileOut << "        }\n";
	classFileOut << "        // set the parser\n";
    classFileOut << "        SAXParserFactory factory = SAXParserFactory.newInstance();\n";
	
    classFileOut << "         try { \n";
    classFileOut << "             parser = factory.newSAXParser();\n";
    classFileOut << "         } catch(Exception e) {\n";
    classFileOut << "             e.printStackTrace();\n";
    classFileOut << "         }\n";

	
    classFileOut << "}\n\n";

    // main handler routine
    classFileOut << "\n    public void startElement(String namespaceUri,\n"; // the parser routine
    classFileOut << "                             String localName,\n";
    classFileOut << "                             String qName,\n";
    classFileOut << "                             Attributes atts) {\n\n";

        // run through all objects
    bool first = true;
    classFileOut << "    // check all possible options\n";

    for(int i=0; i < m_objects.size(); i++) {

        XSDObject *obj = m_objects.at(i);

        // the scheme object will never be sent
        if (obj->name() == "Schema") {
            continue;
        }
        if (!first) {
            classFileOut << "    else if";
        } else {
            classFileOut << "    if";
            first = false;
        }
        // if the name matches my object
        classFileOut << " (qName == \"" << className(obj->name()) << "\") {\n";
        // create a temp object
        classFileOut << "        " << className(obj->name()) << " obj = new " << className(obj->name()) << "();\n";

        // check if there are attributes in this class or just data
        int attrCount = 0;
        for(int j=0; j < obj->attributes().size(); j++) {
            XSDAttribute *attr = obj->attributes().at(j);
            QString type = localType(attr->type());
            QString attrName = attr->name();

            if (attrName != type) {
                attrCount++;
            }
        }

        // makes only sense if they are there
        if (attrCount > 0) {
            // run through all the attributes
            classFileOut << "        for (int i=0; i < atts.getLength(); i++) {\n";
            classFileOut << "            String key = atts.getLocalName(i);\n";
            classFileOut << "            String value = atts.getValue(i);\n\n";
            // and match them with mine
            bool first = true;
            for(int j=0; j < obj->attributes().size(); j++) {
                XSDAttribute *attr = obj->attributes().at(j);
                QString type = localType(attr->type());
                QString attrName = attr->name();

                if (attrName != type) { // if the same it is data
                    if (!first) {
                        classFileOut << "            else if (key == \"" << attrName << "\") {\n";
                    } else {
                        classFileOut << "            if (key == \"" << attrName << "\") {\n";
                        first = false;
                    }
                    if (type == "String")
                        classFileOut << "                " << type << " val = value;\n";
                    else if (type == "boolean")
                        classFileOut << "                " << type << " val = (value.toUpperCase() == \"YES\");\n";
                    else if (type == "int")
                        classFileOut << "                " << type << " val = Integer.parseInt(value);\n";
                    else if (type == "Date") {
				        classFileOut << "                DateFormat df = new SimpleDateFormat(\"yyyy-MM-ddThh:mm:ss.zzz\");\n";	
                        classFileOut << "                Date val = new Date(); // starts since the epoch\n";						
						classFileOut << "                try { \n";
                        classFileOut << "                    val = df.parse( value );\n";
                        classFileOut << "                } catch(Exception e) {\n";
                        classFileOut << "                    e.printStackTrace();\n";
                        classFileOut << "                }\n";
					}
					else if (type == "double")
                        classFileOut << "                " << type << " val = Double.parseDouble(value);\n";

                    classFileOut << "                obj.set" << methodName(attrName) << "(val);\n";
                    classFileOut << "            }\n";
                }
            }
            classFileOut << "        }\n";
        }

        // store in local object (or stack) and signal on end tag
        // this way we can set obj in objects
        classFileOut << "        m_objStack.push( obj );\n";
        classFileOut << "    }\n";
    }
    //classFileOut << "    return true;\n";
    classFileOut << "}\n\n";

    // TODO check for attributes and messages we do not know and give an alert

    // the endTag routine
    classFileOut << "    public void endElement(String namespaceUri,\n"; // the parser routine
    classFileOut << "                           String localName,\n";
    classFileOut << "                           String qName) {\n\n";

    // run through all objects
    first = true;
    classFileOut << "    // check all possible options\n";

    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        // the scheme object will never be sent
        if (obj->name() == "Schema") {
            continue;
        }
        if (!first) {
            classFileOut << "    else if";
        } else {
            classFileOut << "    if";
            first = false;
        }
        // if the name matches my object
        classFileOut << " (qName == \"" << className(obj->name()) << "\") {\n\n";
        //classFileOut << "        m_typeStack.pop();\n"; // will be equal to qName so ignore
        classFileOut << "        " << className(obj->name()) << " obj = (" << className(obj->name()) << ") ( m_objStack.pop() );\n";

        // for all objects that could accept such an object
        for(int i=0; i < m_objects.size(); i++) {
            XSDObject *parent = m_objects.at(i);

            for(int j=0; j < parent->attributes().size(); j++) {
                XSDAttribute *attr = parent->attributes().at(j);
                QString objType = attr->type();

                if (objType == className(obj->name())) { // this object has an attribute of that type
                    classFileOut << "        if ( m_objStack.peek().getClass() == " << parent->name() << ".class.getClass() ) {\n";
                    if (attr->unbounded() ) {
                        classFileOut << "                (("<< parent->name() << ") ( m_objStack.peek() ) ).add" << className(obj->name()) << "( obj );\n";
                    } else {
                        classFileOut << "                (("<< parent->name() << ") ( m_objStack.peek() ) ).set" << className(obj->name()) << "( obj );\n";
                    }
                    classFileOut << "        }\n"; // close if
                }
            }
        }
        if ((!obj->isEmbedded())) { // only if this object is not embedded
           classFileOut << "        signal" << className(obj->name()) << "( obj ); \n";
        }
        //classFileOut << "        delete( obj ); \n";
        classFileOut << "    }\n"; // close if
    }
    //classFileOut << "    return true;\n";
    classFileOut << "}\n\n"; // close method

    // the parseXMLString routine
    classFileOut << "    public boolean parseXMLString(String data, boolean cont) { \n\n";
    classFileOut << "     m_dataBuffer += data;\n\n";

    // count the number of messages
    int numOfMessages = 0;
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((!obj->isEmbedded()) && (obj->name() != "Schema") ) {
            numOfMessages++;
        }
    }

    classFileOut << "     int index[] = new int[" << numOfMessages << "], indexMax = -1;\n\n";
    classFileOut << "     // note that if a message does not exist the index will be equal to strlen(name\\n) - 1 so indexMax is always > 0\n";

    int message=0;
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((!obj->isEmbedded()) && (obj->name() != "Schema") ) {
            classFileOut << "     index[" << message << "] = m_dataBuffer.lastIndexOf(\"</" << obj->name() << ">\\n\") + (\"</" << obj->name() << ">\\n\").length();\n";
            message++;
        }
    }
    classFileOut << "     for (int i=0; i<" << numOfMessages << "; i++) {\n";
    classFileOut << "         if (index[i] > indexMax) {\n";
    classFileOut << "             indexMax = index[i];\n";
    classFileOut << "         }\n";
    classFileOut << "     }\n\n";

    classFileOut << "     if (indexMax > 30) {\n";
    classFileOut << "         String messages = m_dataBuffer.substring(0, indexMax);\n";
    classFileOut << "         m_dataBuffer = m_dataBuffer.substring(indexMax); // remove up to indexMax\n";
    classFileOut << "         try { \n";
    classFileOut << "             parser.parse(messages, this);\n";
    classFileOut << "         } catch(Exception e) {\n";
    classFileOut << "             String errorMessage =\n";
    classFileOut << "                 \"Error parsing \" + messages + \": \" + e;\n";
    classFileOut << "             System.err.println(errorMessage);\n";
    classFileOut << "             e.printStackTrace();\n";
    classFileOut << "         }\n";

    classFileOut << "     } else {\n";
    classFileOut << "         return false; // not enough data in string\n";
    classFileOut << "     }\n";

    classFileOut << "     if (!cont) {\n";
    classFileOut << "         m_dataBuffer = \"\";\n";
    classFileOut << "     }\n";
    classFileOut << "     return true;\n";

    classFileOut << "}\n\n"; // close method

	
    // round up
    classFileOut << "\n}\n"; // make sure there is a newline at the end of the source
	
    // close and flush
    classFileOut.flush();
    classFile.close();
    std::cout << "done.\n" << std::endl;
	
	
}

