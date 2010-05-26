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

#include "codegenphp.h"

CodeGenPHP::CodeGenPHP()
        : CodeGen() {
    m_prefix = "";
}

void CodeGenPHP::setObjects(QVector<XSDObject*>objects) {
    m_objects = objects;
}

void CodeGenPHP::setOutputDir(QString outDir) {
    m_outDir = outDir;
}

QString CodeGenPHP::sizeEvaluatorForType (QString type, QString varName) {
    if (type == "xs:string")
        return "strlen (" + varName + ")";
    else
        return varName;
}

QString CodeGenPHP::localType(QString type) {
    if (type == "xs:string")
        return "String";
    else if (type == "xs:boolean")
        return "bool";
    else if (type == "xs:integer")
        return "int";
    else if (type == "xs:dateTime")
        return "int"; // dates are stored as ints
    else if (type == "xs:hexBinary")
        return "String";
    else if (type == "unknown") {
        std::cout << "WARNING unknown type found:" << type.toLatin1().data() <<  ", defaulting to String" << std::endl;
        return "String";
    } else if (type == "xs:decimal") // double
        return "double";
    else
        return className(type);
}

bool CodeGenPHP::knownType(QString type) {
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

QString CodeGenPHP::stringConversionForAttribute(XSDAttribute *attr) {

    QString attrType = attr->type();
    QString type = localType(attr->type()); // convert to php types
    QString varName = variableName(attr->name());

    if (attrType == "xs:dateTime") {
        varName = "date(\"Y-m-d\\TH:i:sZ\" ," + variableName(attr->name()) + ")";
    } else if (type == "double") { 
        if (attr->hasDigits()) {
            varName = "number_format(" + variableName(attr->name()) + ", " + attr->digits() + ")"; 
        } else {
            varName = "number_format(" + variableName(attr->name()) + ", 6)"; // default
        }
    }
                
    return varName;
}

QString CodeGenPHP::methodName(QString name) {

    // handle special methods
    if (name == "Class")
        name = m_prefix + name;

    return name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenPHP::className(QString name) {
    return m_prefix + name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenPHP::fileBaseName(QString name) {
    return className(name);
}

QString CodeGenPHP::variableNameDef(QString name) {

    if (name.mid(1,1).toUpper() == name.mid(1,1)) { // if second char is uppercase
        return "$m_" + name;
    } else {
        return "$m_" + name.replace(0, 1, name.left(1).toLower());
    }
} 

QString CodeGenPHP::variableName(QString name) { // reference is different from definition

    QString varName = variableNameDef(name).remove(0, 1);
    return "$this->" + varName;
}

QString CodeGenPHP::longestCommonPrefix(QStringList strings) {

    if (strings.size() < 1) {
        return ""; // not good
    }
    if (strings.size() < 2) {
        return strings.at(0); // all in common with myself
    }
    // take the first item as initial prefix
    QString prefix = strings.at(0);
    int length = prefix.length();

    // compare the current prefix with the prefix of the same length of the other items
    foreach(QString item, strings) {
        // check if there is a match; if not, decrease the prefix by one character at a time
        while ((length > 0) && (item.left(length) != prefix)) {
            length--;
            prefix = prefix.left(length);
        }
    }

    // if no common prefix, return value will be ""
    return prefix;
}

QString CodeGenPHP::writeHeader(QString fileName) {

    QString header;
    header.append( "// \n" );
    header.append( "//  " + fileName + "\n" );
    header.append( "//\n" );
    header.append( "//  " + fileName + " is free software: you can redistribute it and/or modify\n" );
    header.append( "//  it under the terms of the GNU Lesser General Public License as published by\n" );
    header.append( "//  the Free Software Foundation, either version 3 of the License, or\n" );
    header.append( "//  (at your option) any later version.\n" );
    header.append( "//\n" );
    header.append( "//  "+ fileName + " is distributed in the hope that it will be useful,\n" );
    header.append( "//  but WITHOUT ANY WARRANTY ); without even the implied warranty of\n" );
    header.append( "//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" );
    header.append( "//  GNU General Public License for more details.\n" );
    header.append( "//\n" );
    header.append( "//*********************************************************************************\n" );
    header.append( "//  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD\n" );
    header.append( "//  Generated by xsd2code on "+  QDateTime::currentDateTime().toString() + ".\n" );
    header.append( "//*********************************************************************************\n" );
    header.append( "//  Copyright 2010\n" );
    header.append( "//\n\n" );

    return header;
}

void CodeGenPHP::go() {

    // first analyse the objects if they are embedded objects
    // for all objects that could accept such an object
    QString nameSpace = "none";
    bool useNameSpace = false;
    for (int i=0; i < m_objects.size(); i++) {
        // for all objects
        XSDObject *obj1 = m_objects.at(i);
        obj1->setSimpleElement(false); // assume not a simple element

        // find if there is another object that refers to the obj
        for (int h=0; h < m_objects.size(); h++) {

            XSDObject *obj2 = m_objects.at(h);

            // refers means obj2 has an attribute of type obj1
            for (int j=0; j < obj2->attributes().size(); j++) {
                XSDAttribute *attr = obj2->attributes().at(j);
                QString objType = attr->type();

                // if obj1 is a simple element of obj2 we don't need to generate a class for it
                if (attr->isSimpleElement() && attr->name() == obj1->name()) {
                    //std::cout << QString("Should i ignore attr: %1 for obj2 %2 obj1 %3?").arg(attr->name(), obj2->name(), obj1->name()).toLatin1().data() << std::endl;
                    obj1->setSimpleElement(true);
                    std::cout << QString("marking class: %1 for skip").arg(className(obj1->name())).toLatin1().data() << std::endl;
                }

                if (objType == obj1->name()) {
                    obj1->setEmbedded();    // obj1 is embedded in obj2
                }
            }
        }

        // find out what our namespace is
        if (obj1->name() == "Schema") {
            for (int j=0; j < obj1->fixedValues().size(); j++) {
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
    } else {
        m_prefix = "XSD";
    }

    for (int i=0; i < m_objects.size(); i++) {
        // get a class
        XSDObject *obj = m_objects.at(i);

        // get some vars we frequently use
        QString name = obj->name();
        QString upperName = name.toUpper();
        QString lowerName = name.toLower();
        QVector<XSDAttribute*>attributes = obj->attributes();
        QMap<QString, QString>fixedValues = obj->fixedValues();

        // check for simple elements
        if (obj->isSimpleElement()) {
            std::cout << QString("skipping class: %1").arg(className(name)).toLatin1().data() << std::endl;
            continue;
        }

        // report
        std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;

        // and the class file
        QString baseName = m_outDir + "/" + package + "/" + fileBaseName(name);
        QFile classFile(baseName + ".php");
        if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("cannot create file: %1").arg(baseName + ".php").toLatin1().data() << std::endl;
            std::exit(-1);
        }
        QTextStream classFileOut(&classFile);

        //-----------------------------------------------------------------------------------------------
        // generate the declaration
        //-----------------------------------------------------------------------------------------------

        classFileOut << "<?php\n\n";
        classFileOut << writeHeader( className(name) );

        // include dependend files
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            if (!knownType(attr->type())) {
                classFileOut << "require \"" << fileBaseName(attr->type()) << ".php\";\n";
            }
        }

        classFileOut << "\nclass " << className(name) << " { \n\n";

        // variables section
        // all attributes
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
                classFileOut << "    var " << variableNameDef(attr->name()) << "; // default value is uninitialized\n";
                classFileOut << "    var " << variableNameDef(attr->name()) << "Present;\n";
        }

        //-----------------------------------------------------------------------------------------------
        // create the implementation
        //-----------------------------------------------------------------------------------------------

        // constructor
        classFileOut << "\n    public function " << className(name) << "() {\n\n";
        classFileOut << "        date_default_timezone_set('UTC');\n";
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString type = localType(attr->type()); // convert to php types
            if (attr->isFixed()) {
                classFileOut << "        " << variableName(attr->name()) << " = \"" << attr->fixed() << "\";\n";
                classFileOut << "        " << variableName(attr->name()) << "Present = true;\n"; 
            } else {
                classFileOut << "        " << variableName(attr->name()) << "Present = false;\n"; 
                if (attr->isScalar()) { // there more then one
                    classFileOut << "        " << variableName(attr->name()) << "s = array();\n";
                } else if (attr->isElement()) {
                    classFileOut << "        " << variableName(attr->name()) << " = new "<< type <<"();\n";
		}
            }
        }
        classFileOut << "    }\n\n";

        // methods for attributes
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to php types
            if (attr->isScalar()) { // there more then one
                // setter
                classFileOut << "    public function " << "add" << methodName(attr->name()) << "(" << type << " $val ) {\n";

                if (attr->hasMax()) { 
                    classFileOut << "          if ( count("<< variableName(attr->name()) << "s) >= " << attr->max() << ") {\n";
                    classFileOut << "              return false; // scalar already at maxOccurs\n";
                    classFileOut << "          }\n";
                }
                classFileOut << "\n        " << variableName(attr->name()) << "s[] = $val;\n";
                classFileOut << "        return true;\n";
                classFileOut << "    }\n\n";
                // getter
                classFileOut << "    public function get" << methodName(attr->name()) << "At($i) {\n";
                classFileOut << "\n        return " << variableName(attr->name()) << "s[$i];\n    }\n\n";
                // count
                classFileOut << "    public function countOf" << methodName(attr->name()) << "s() {\n";
                classFileOut << "\n        return count(" << variableName(attr->name()) << "s);\n    }\n\n";
            } else {
                // setter
                classFileOut << "    public function set" << methodName(attr->name()) << "( $val ) {\n";
                QVector<QString> enums = attr->enumeration();
                if (enums.size() > 0) { // there are enumeration constraints for this item

                    // strings should be between quotes, numbers not
                    if (type == "String") {
                        classFileOut << "\n        if ( ( $val != \"" << enums.at(0) <<"\" ) ";
                        for (int h=1; h < enums.size(); h++) {
                            classFileOut << "&&\n             ( $val != \"" << enums.at(h) << "\" ) ";
                        }
                    } else { // numbers

                        classFileOut << "\n        if ( ( $val != " << enums.at(0) <<" ) ";
                        for (int h=1; h < enums.size(); h++) {
                            classFileOut << "&&\n             ( $val != " << enums.at(h) << " ) ";
                        }
                    }
                    classFileOut <<    ")\n            return false;";
                }
                if (attr->hasMin() && knownType(attr->type()) ) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " < " << attr->min() << ")\n          return false;";
                }
                if (attr->hasMax() && knownType(attr->type()) ) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " > " << attr->max() << ")\n          return false;";
                }
                classFileOut << "\n        " << variableName(attr->name()) << "Present = true;";
                classFileOut << "\n        " << variableName(attr->name()) << " = $val;\n";
                classFileOut << "        return true;\n";
                classFileOut << "    }\n\n";
                // getter
                classFileOut << "    public function get" << methodName(attr->name()) << "() {\n";
                classFileOut << "\n        return " << variableName(attr->name()) << ";\n    }\n\n";
                if (!attr->required() || obj->isMerged()) { 
                    classFileOut << "    public function has" << methodName(attr->name()) << "() {\n";
                    classFileOut << "\n        return " << variableName(attr->name()) << "Present;\n    }\n\n";
                }
            }
        }

        // and fixed values
        for (int j=0; j < fixedValues.size(); j++) {
            QString attrName = fixedValues.keys().at(j);
            QString attrValue = fixedValues.values().at(j);
            QString type = "String"; // always a string

            // getter
            classFileOut << "    public function get" << methodName(attrName) << "() {\n";
            classFileOut << "\n        return \"" << attrValue << "\";\n    }\n\n";
        }

        // xml generator
        // if attribute name and type are the same it means it was data
        classFileOut << "    public function toXML() {\n\n";
  	classFileOut << "        $xml = new SimpleXMLElement(\"<" << name << "></" << name << ">\");\n";
        classFileOut << "\n";

        // for attributes
        bool hasDataMembers = false;
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);

            if (!attr->isElement()) { 

                // non-qstring items (ints) may give problems, so convert them
		QString varName = stringConversionForAttribute(attr);

                // check if the attribute exist
                if ((!attr->required() || obj->isMerged()) && !attr->isScalar()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
	            classFileOut << "            $xml->addAttribute('"<< attr->name()<<"', " << varName << ");\n";
                    classFileOut << "        }\n";
                } else { 
                    classFileOut << "        if ( " << variableName(attr->name()) << "Present ) {\n";
	            classFileOut << "            $xml->addAttribute('"<< attr->name()<<"', " << varName << ");\n";
                    classFileOut << "        } else { \n";
                    classFileOut << "            return \"\"; // not all required attributes have been set \n";
                    classFileOut << "        } \n";
                }
            } else {
                hasDataMembers = true;
            }
        }
        if (hasDataMembers) {
            // for data members
            for (int j=0; j < attributes.size(); j++) {
                XSDAttribute *attr = attributes.at(j);
                QString attrType = attr->type();

                if (attr->isElement()) { 
                    // check if the attribute exist
                    if (attr->isScalar()) {
                        if (attr->hasMin()) { 
                            classFileOut << "        if ( count(" << variableName(attr->name()) << "s) < " << attr->min() << ") {\n";
                            classFileOut << "            return \"\"; // not enough values\n";
                            classFileOut << "        }\n";
                        }
                        if (attr->hasMin()) { 
                            classFileOut << "        if ( count(" << variableName(attr->name()) << "s) < " << attr->min() << ") {\n";
                            classFileOut << "            return \"\"; // not enough values\n";
                            classFileOut << "        }\n";
                        }
                        classFileOut << "        foreach("<<  variableName(attr->name())<<"s as $attribute) {\n";

                        if (attr->isSimpleElement()) {
                            // non-qstring items (ints) may give problems, so convert them
		            QString varName = stringConversionForAttribute(attr);
                            classFileOut << "            $xml->addChild('" << attr->name() << "', " << varName << ");\n";
                        } else {
                            classFileOut << "        $dom = dom_import_simplexml($xml);\n";
                            classFileOut << "        $child_as_xml = $attribute->toXML();\n";
                            classFileOut << "        $child_as_simplexml = new SimpleXMLElement($child_as_xml);\n";
                            classFileOut << "        $child_as_dom = dom_import_simplexml($child_as_simplexml);\n";
                            classFileOut << "        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);\n";
                            classFileOut << "        $dom->appendChild($child_as_leaf);\n";
                            classFileOut << "        $xml = simplexml_import_dom($dom);\n";
                        }
                        classFileOut << "        } \n";
                    } else if (!attr->required() || obj->isMerged()) {  // optional test for it
                        classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                        if (attr->isSimpleElement()) {
		            QString varName = stringConversionForAttribute(attr);
                            classFileOut << "            $xml->addChild('" << attr->name() << "', " << varName << ");\n";
                        } else {
                            classFileOut << "            $dom = dom_import_simplexml($xml);\n";
                            classFileOut << "            $child_as_xml = " << variableName(attr->name()) << "->toXML();\n";
                            classFileOut << "            $child_as_simplexml = new SimpleXMLElement($child_as_xml);\n";
                            classFileOut << "            $child_as_dom = dom_import_simplexml($child_as_simplexml);\n";
                            classFileOut << "            $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);\n";
                            classFileOut << "            $dom->appendChild($child_as_leaf);\n";
                            classFileOut << "            $xml = simplexml_import_dom($dom);\n";
                        }
                        classFileOut << "        } \n";
                    } else {  // required
                        classFileOut << "        if ( " << variableName(attr->name()) << "Present ) {\n"; 
                        classFileOut << "            $dom = dom_import_simplexml($xml);\n";
                        classFileOut << "            $child_as_xml = " << variableName(attr->name()) << "->toXML();\n";
                        classFileOut << "            $child_as_simplexml = new SimpleXMLElement($child_as_xml);\n";
                        classFileOut << "            $child_as_dom = dom_import_simplexml($child_as_simplexml);\n";
                        classFileOut << "            $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);\n";
                        classFileOut << "            $dom->appendChild($child_as_leaf);\n";
                        classFileOut << "            $xml = simplexml_import_dom($dom);\n";
                        classFileOut << "        } else { \n";
                        classFileOut << "            return \"\"; // not all required data members have been set \n";
                        classFileOut << "        } \n";
                    }
                }
            }
        } 
        classFileOut << "        return $xml->asXML();\n";
        classFileOut << "    }\n\n";

        // string generator
        classFileOut << "    public function toString() {\n\n";
        classFileOut << "    	return $this->toStringWithLead(\"\");\n";
        classFileOut << "    }\n\n";

        // if attribute name and type are the same it means it was data
        classFileOut << "    public function toStringWithLead( $lead ) {\n\n";
        classFileOut << "        $str = $lead . \"" << name << "\\n\";\n"; // append attributes
        classFileOut << "\n";

        // for attributes
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);

            if (!attr->isElement()) { 
                // non-qstring items (ints) may give problems, so convert them
		QString varName = stringConversionForAttribute(attr);

                // check if the attribute exist
                if ((!attr->required() || obj->isMerged()) && !attr->isScalar()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "            $str .= $lead . \"    " << attr->name() << " = \" . " << varName << " . \"\\n\";\n";
                    classFileOut << "        }\n";
                } else {
                    classFileOut << "        $str .= $lead . \"    " << attr->name() << " = \" . " << varName << " . \"\\n\";\n";
                }
            }
        }

        // for data members
        for (int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();

            if (attr->isElement()) {
                // check if the attribute exist
                if (attr->isScalar() ) {
                    classFileOut << "        foreach("<<  variableName(attr->name())<<"s as $attribute) {\n";
                    classFileOut << "           $str .= $attribute->toStringWithLead($lead + \"    \");\n        }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                    if (attr->isSimpleElement()) {
                        classFileOut << "            $str .= $lead . \" \" ;\n";
                        classFileOut << "            $str .= \"" << attr->name() << " = \" ;\n";
                        classFileOut << "            $str .= " << variableName(attr->name()) << " ;\n";
                        classFileOut << "            $str .= \"\\n\" );\n";
                    } else {
                        classFileOut << "            $str .= " << " " << variableName(attr->name()) << "->toStringWithLead($lead . \"    \") ;\n        }\n";
                    }
                } else {
                    classFileOut << "        $str .= " << " " << variableName(attr->name()) << "->toStringWithLead($lead . \"    \");\n";
                }
            }
        }

        // close up
        classFileOut << "\n        return $str;\n";
        classFileOut << "    }\n";

        // round up
        classFileOut << "}\n"; 
        classFileOut << "?>\n";

        // close and flush
        classFileOut.flush();
        classFile.close();
    }

    //-----------------------------------------------------------------------------------------------
    // now generate the interface
    //-----------------------------------------------------------------------------------------------

    // generate the parser file
    QString name = "ParserListener";
    QString fileName = m_outDir + "/" +  package + "/" + fileBaseName(name) + ".php";
    QFile classFile2(fileName);
    if (!classFile2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(fileName).toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream classFileOut2(&classFile2);
    std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;

    //-----------------------------------------------------------------------------------------------
    // generate the interface declaration
    //-----------------------------------------------------------------------------------------------
    classFileOut2 << writeHeader( className(name) );

    classFileOut2 << "package " << package << ";\n\n";

    // define the interface
    classFileOut2 << "\npublic function interface " << className(name) << " { \n\n";

    // public function overrides
    classFileOut2 << "    // subclass these methods to receive events \n";
    for (int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((obj->name() != "Schema") && (!obj->isEmbedded()) && !obj->isSimpleElement()) { // only if this object is not embedded
            classFileOut2 << "    public function void handle" << className(obj->name()) << "(" << className(obj->name()) << " obj);\n";
        }
    }

    // round up
    classFileOut2 << "\n}\n"; // make sure there is a newline at the end of the source

    // close and flush
    classFileOut2.flush();
    classFile2.close();

    //-----------------------------------------------------------------------------------------------
    // now generate the parser
    //-----------------------------------------------------------------------------------------------

    // generate the parser file
    name = "Parser";
    fileName = m_outDir + "/" +  package + "/" + fileBaseName(name) + ".php";
    QFile classFile(fileName);
    if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(fileName).toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream classFileOut(&classFile);
    std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;

    //-----------------------------------------------------------------------------------------------
    // generate the declaration
    //-----------------------------------------------------------------------------------------------
    classFileOut << writeHeader( className(name) );

    classFileOut << "package " << package << ";\n\n";
    classFileOut << "import " << package << "." << fileBaseName("ParserListener") << ";\n";
    classFileOut << "import php.util.*;\n";
    classFileOut << "import php.util.regex.*;\n";
    classFileOut << "import php.text.DateFormat;\n";
    classFileOut << "import php.io.*;\n";
    classFileOut << "import php.text.SimpleDateFormat;\n";
    classFileOut << "import phpx.xml.parsers.*;\n";
    classFileOut << "import org.xml.sax.*;\n";
    classFileOut << "import org.xml.sax.helpers.*;\n";

    // include dependend files
    for (int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if (obj->name() != "Schema" && !obj->isSimpleElement()) { 
            classFileOut << "import " << package << "." << fileBaseName(obj->name()) << ";\n";
        }
    }

    // define the class
    classFileOut << "\npublic function class " << className(name) << " extends DefaultHandler { \n\n";

    // variables
    classFileOut << "    private String m_dataBuffer = new String();\n";
    classFileOut << "    private String m_characterBuffer = new String();\n"; 
    classFileOut << "    private " << fileBaseName("ParserListener") << " m_handler =  null;\n";
    classFileOut << "    private Stack m_objStack = new Stack(); // cannot use a template since it stores different Objects\n";
    classFileOut << "    private SAXParser m_parser; // init in constructor\n";
    classFileOut << "    private Pattern m_closeTagsPattern; \n";

    // count the number of messages
    QStringList closeTags, rootObjects;
    for (int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((!obj->isEmbedded()) && (obj->name() != "Schema") ) {
            rootObjects.append(obj->name());
            closeTags.append("</" + obj->name() + ">");
        }
    }

    // build a regexp for the rootTags
    QString regExp;
    QString commonPrefix = longestCommonPrefix(rootObjects);
    if (commonPrefix.size() > 0) {
        regExp = "</" + commonPrefix +  "([A-Za-z0-9]*)>";
    } else {
        regExp = closeTags.join("|");
    }

    // constructor
    classFileOut << "\n    public function " << className(name) << "("<< fileBaseName("ParserListener") << " handler) {\n\n";
    classFileOut << "        m_handler = handler;\n\n";
    classFileOut << "        // set the parser\n";
    classFileOut << "        SAXParserFactory factory = SAXParserFactory.newInstance();\n";
    classFileOut << "        m_closeTagsPattern = Pattern.compile( \"" + regExp + "\");\n";

    classFileOut << "        try { \n";
    classFileOut << "            m_parser = factory.newSAXParser();\n";
    classFileOut << "        } catch(Exception e) {\n";
    classFileOut << "            e.printStackTrace();\n";
    classFileOut << "        }\n";

    classFileOut << "}\n";

    // the character parser
    classFileOut << "     // Character buffer routine\n";
    classFileOut << "     public function void characters(char[] ch, int start, int length) throws SAXException {\n\n";
    classFileOut << "         m_characterBuffer += ch;\n";
    classFileOut << "     };\n";

    // main handler routine
    classFileOut << "\n    public function void startElement(String namespaceUri,\n"; // the parser routine
    classFileOut << "                             String localName,\n";
    classFileOut << "                             String qName,\n";
    classFileOut << "                             Attributes atts) throws SAXException {\n\n";
    classFileOut << "         m_characterBuffer = \"\"; // reset buffer\n";

    // run through all objects
    bool first = true;
    classFileOut << "    // check all possible options\n";

    for (int i=0; i < m_objects.size(); i++) {

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
        if (!obj->isSimpleElement()) {
            classFileOut << " (qName == \"" << className(obj->name()) << "\") {\n";
            // create a temp object
            classFileOut << "        " << className(obj->name()) << " obj = new " << className(obj->name()) << "();\n";

            // check if there are attributes in this class or just data
            int attrCount = 0;
            for (int j=0; j < obj->attributes().size(); j++) {
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
                for (int j=0; j < obj->attributes().size(); j++) {
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
                        else if (type == "boolean") {
                            classFileOut << "                " << type << " val = (value.toUpperCase() == \"YES\" ||\n";
                            classFileOut << "                               value.toUpperCase() == \"TRUE\" ||\n";
                            classFileOut << "                               value.toUpperCase() == \"1\");\n";
                        } else if (type == "int")
                            classFileOut << "                " << type << " val = Integer.parseInt(value);\n";
                        else if (type == "Date") {
                            classFileOut << "                if (value.endsWith(\"Z\")) { \n"; 
                            classFileOut << "                    value = value.substring(0, value.length() - 1);\n";
                            classFileOut << "                } \n";
                            classFileOut << "                Date val = new Date(); // starts since the epoch\n";
                            classFileOut << "                try { \n";
                            classFileOut << "                    DateFormat df = new SimpleDateFormat(\"yyyy-MM-dd'T'HH:mm:ss.SSS\");\n";
                            classFileOut << "                    val = df.parse( value );\n";
                            classFileOut << "                } catch(Exception e) {\n";
                            classFileOut << "                    try { // if there are no miliseconds they will not be sent\n";
                            classFileOut << "                       DateFormat df = new SimpleDateFormat(\"yyyy-MM-dd'T'HH:mm:ss\");\n";
                            classFileOut << "                       val = df.parse( value );\n";
                            classFileOut << "                    } catch(Exception e2) {\n";
                            classFileOut << "                        e2.printStackTrace();\n";
                            classFileOut << "                    }\n";
                            classFileOut << "                }\n";
                        } else if (type == "double") {
                            classFileOut << "                " << type << " val = Double.parseDouble(value.replace(\",\", \".\"));\n";
                        }
                        classFileOut << "                if (! obj.set" << methodName(attrName) << "(val) ) {\n";
                        classFileOut << "                   throw new SAXException(\"Validation Exception: \" + key + \" = \" + value );\n";
                        classFileOut << "                }\n";
                        classFileOut << "            }\n";
                    }
                }
                classFileOut << "        }\n";
            }

            // store in local object (or stack) and signal on end tag
            // this way we can set obj in objects
            classFileOut << "        m_objStack.push( obj );\n";
        } else {
            classFileOut << "        // data will follow and end up in the m_characterBuffer\n";
        }
        classFileOut << "    }\n";
    }
    //classFileOut << "    return true;\n";
    classFileOut << "}\n\n";

    // TODO check for attributes and messages we do not know and give an alert

    // the endTag routine
    classFileOut << "    public function void endElement(String namespaceUri,\n"; // the parser routine
    classFileOut << "                           String localName,\n";
    classFileOut << "                           String qName) throws SAXException {\n\n";

    // run through all objects
    first = true;
    classFileOut << "    // check all possible options\n";

    for (int i=0; i < m_objects.size(); i++) {
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

        if (!obj->isSimpleElement()) { // normal flow
            //classFileOut << "        m_typeStack.pop();\n"; // will be equal to qName so ignore
            classFileOut << "        " << className(obj->name()) << " obj = (" << className(obj->name()) << ") ( m_objStack.pop() );\n";

            // for all objects that could accept such an object
            for (int i=0; i < m_objects.size(); i++) {
                XSDObject *parent = m_objects.at(i);

                for (int j=0; j < parent->attributes().size(); j++) {
                    XSDAttribute *attr = parent->attributes().at(j);
                    QString objType = attr->type();

                    if (objType == className(obj->name())) { // this object has an attribute of that type
                        classFileOut << "        if ( m_objStack.peek().getClass() == new " << parent->name() << "().getClass() ) {\n";
                        if (attr->isScalar() ) {
                            classFileOut << "                if (! (("<< parent->name() << ") ( m_objStack.peek() ) ).add" << className(obj->name()) << "( obj ) ) {\n";
                            classFileOut << "                   throw new SAXException(\"Validation Exception: \" + qName);\n";
                            classFileOut << "                }\n";
                        } else {
                            classFileOut << "                if (! (("<< parent->name() << ") ( m_objStack.peek() ) ).set" << className(obj->name()) << "( obj ) ) {\n";
                            classFileOut << "                   throw new SAXException(\"Validation Exception: \" + qName);\n";
                            classFileOut << "                }\n";
                        }
                        classFileOut << "        }\n"; // close if
                    }
                }
            }
            if ((!obj->isEmbedded())) { // only if this object is not embedded
                classFileOut << "        if (m_handler != null) \n";
                classFileOut << "            m_handler.handle" << className(obj->name()) << "( obj ); \n";
            }
            //classFileOut << "        delete( obj ); \n";
        } else { // closed element is not an element with properties but a data holder, this is stored at the parent level

            // for all objects that could accept such an object
            for (int i=0; i < m_objects.size(); i++) {
                XSDObject *parent = m_objects.at(i);

                for (int j=0; j < parent->attributes().size(); j++) {
                    XSDAttribute *attr = parent->attributes().at(j);
                    //std::cout << QString("####: %1").arg(attr->name()).toLatin1().data() << std::endl;
                    //std::cout << QString("##: %1").arg(obj->name()).toLatin1().data() << std::endl;

                    if (obj->name() == attr->name() ) { // this object has an datamember of that type

                        classFileOut << "        " << className(parent->name()) << " *parent = (" << className(parent->name()) << ") ( m_objStack.top() );\n";
                        classFileOut << "        if (parent) {\n";
                        classFileOut << "             // add the found characters to the parent\n";
                        if (attr->isScalar()) {
                            classFileOut << "             parent.add" << className(obj->name()) << "(m_characterBuffer);\n";
                        } else {
                            classFileOut << "             parent.set" << className(obj->name()) << "(m_characterBuffer);\n";
                        }
                        classFileOut << "             // clear the character buffer\n";
                        classFileOut << "             m_characterBuffer = "";\n";
                        classFileOut << "        }\n";
                    }
                }
            }
        }
        classFileOut << "    }\n"; // close if
    }
    //classFileOut << "    return true;\n";
    classFileOut << "}\n\n"; // close method

    // the parseXMLString routine
    // rewritten for issue 60
    classFileOut << "    public function boolean parseXMLString(String data, boolean cont) { \n\n";
    classFileOut << "     m_dataBuffer += data;\n\n";
    classFileOut << "\n";
    classFileOut << "     // search the buffer for the nearest closetag\n";
    classFileOut << "     int indexStart = 0, indexEnd = -1;\n";
    classFileOut << "\n";
    classFileOut << "     // look for the pattern that defines a root element\n";
    classFileOut << "     Matcher matcher = m_closeTagsPattern.matcher( m_dataBuffer );\n";
    classFileOut << "\n";
    classFileOut << "     // parse the messages in the buffer one by one\n";
    classFileOut << "     while ( matcher.find() ) {\n";
    classFileOut << "         indexEnd = matcher.end();\n";
    classFileOut << "         // isolate the messages\n";
    classFileOut << "         String messages = m_dataBuffer.substring(indexStart, indexEnd);\n";
    classFileOut << "         indexStart = indexEnd;\n";
    classFileOut << "         // and parse\n";
    classFileOut << "         try { \n";
    classFileOut << "             m_parser.parse(new InputSource(new StringReader(messages)), this);\n";
    classFileOut << "         } catch(Exception e) {\n";
    classFileOut << "             String errorMessage =\n";
    classFileOut << "             \"Error parsing \" + messages + \": \" + e;\n";
    classFileOut << "             System.err.println(errorMessage);\n";
    classFileOut << "             e.printStackTrace();\n";
    classFileOut << "             return false;\n";
    classFileOut << "         }\n";
    classFileOut << "     }\n";
    classFileOut << "\n";
    classFileOut << "     // check if we parsed messages\n";
    classFileOut << "     if (indexEnd > -1) {\n";
    classFileOut << "         // remove from buffer\n";
    classFileOut << "         m_dataBuffer = m_dataBuffer.substring(indexEnd);\n";
    classFileOut << "     }\n";
    classFileOut << "\n";
    classFileOut << "     // check if we should flush the buffer\n";
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

