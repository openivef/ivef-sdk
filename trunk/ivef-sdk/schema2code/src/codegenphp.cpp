/*
 *  codegenqt.cpp
 *
 *  schema2code is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  schema2code is distributed in the hope that it will be useful,
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
        return "string"; // dates are stored as strings
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

    // dates are stored in strings
    /*if (attrType == "xs:dateTime") {
        varName = "date(\"Y-m-d\\TH:i:sZ\" ," + variableName(attr->name()) + ")";
    } else */if (type == "double") {
        if (attr->hasDigits()) {
            varName = "number_format(" + variableName(attr->name()) + ", " + QString::number(attr->digits()) + ")";
        } else {
            varName = "number_format(" + variableName(attr->name()) + ", 6)"; // default
        }
    }

    return varName;
}

QString CodeGenPHP::methodName(QString name) {

    // handle special methods
    if (name == "class")
        name = m_prefix + name;

    return name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenPHP::className(QString name) {
    return /*m_prefix +*/ name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenPHP::fileBaseName(QString name) {
    return m_prefix + className(name);
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
    header.append( "//  Generated by schema2code on "+  QDateTime::currentDateTime().toString() + ".\n" );
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
        QString baseName = m_outDir + "/" + fileBaseName(name);
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
                classFileOut << "require_once \"" << fileBaseName(attr->type()) << ".php\";\n";
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
            QString type = localType(attr->type()); // convert to php types
            if (attr->isScalar()) { // there more then one
                // remover issue 70
                classFileOut << "    public function " << "remove" << methodName(attr->name()) << "(" << type << " $val ) {\n";

                if (attr->hasMinOccurs()) {
                    classFileOut << "        if ( count("<< variableName(attr->name()) << "s) <= " << attr->minOccurs() << ") {\n";
                    classFileOut << "            return false; // scalar already at minOccurs\n";
                    classFileOut << "        }\n";
                }
                classFileOut << "        for($i=0; $i< count(" << variableName(attr->name()) << "s); $i++) {\n";
                classFileOut << "            if(" << variableName(attr->name()) << "s[i] == $val) {\n";
                classFileOut << "                unset(" << variableName(attr->name()) << "s[i]);\n";
                classFileOut << "            }\n";
                classFileOut << "        }\n";
                classFileOut << "        return true;\n";
                classFileOut << "    }\n\n";
                // setter
                classFileOut << "    public function " << "add" << methodName(attr->name()) << "(" << type << " $val ) {\n";

                if (attr->hasMaxOccurs()) {
                    classFileOut << "        if ( count("<< variableName(attr->name()) << "s) >= " << attr->maxOccurs() << ") {\n";
                    classFileOut << "            return false; // scalar already at maxOccurs\n";
                    classFileOut << "        }\n";
                }
                if (attr->hasMinLength() && knownType(attr->type())) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " < " << attr->minLength() << ")\n            return false;";
                }
                if (attr->hasMaxLength() && knownType(attr->type())) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " > " << attr->maxLength() << ")\n            return false;";
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
                // issue 72
                if (attr->hasMinLength() && knownType(attr->type())) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " < " << attr->minLength() << ")\n            return false;";
                }
                if (attr->hasMaxLength() && knownType(attr->type())) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " > " << attr->maxLength() << ")\n            return false;";
                }
                // issue 72
                if (attr->hasMinExclusive() && knownType(attr->type()) ) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " <= " << attr->minExclusive() << ")\n          return false;";
                }
                if (attr->hasMaxExclusive() && knownType(attr->type()) ) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " >= " << attr->maxExclusive() << ")\n          return false;";
                }
                if (attr->hasMinInclusive() && knownType(attr->type()) ) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " < " << attr->minInclusive() << ")\n          return false;";
                }
                if (attr->hasMaxInclusive() && knownType(attr->type()) ) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "$val");
                    classFileOut << "\n        if (" << evaluator << " > " << attr->maxInclusive() << ")\n          return false;";
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
        classFileOut << "    public function toXML($outputNamespace = true) {\n\n";
     
        classFileOut << "        if ($outputNamespace)\n";
        classFileOut << "        {\n";
        classFileOut << "            $rootNodeTag  = \"<" << name << "\";\n";
        classFileOut << "            $rootNodeTag .= \" xmlns:xsi=\\\"http://www.w3.org/2001/XMLSchema-instance\\\"\";\n";
        classFileOut << "            $rootNodeTag .= \" xmlns=\\\"" << nameSpace << "\\\"\";\n";
        classFileOut << "            $rootNodeTag .= \"></" << name << ">\";\n";
        classFileOut << "        }\n";
        classFileOut << "        else\n";
        classFileOut << "            $rootNodeTag = \"<" << name << "></" << name << ">\";\n";
        
        classFileOut << "        $xml = new SimpleXMLElement($rootNodeTag);\n";
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
                    classFileOut << "        if ( $this->has" << methodName(attr->name()) << "() ) {\n";
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

                if (attr->isElement()) {
                    // check if the attribute exist
                    if (attr->isScalar()) {
                        if (attr->hasMinOccurs()) {
                            classFileOut << "        if ( count(" << variableName(attr->name()) << "s) < " << attr->minOccurs() << ") {\n";
                            classFileOut << "            return \"\"; // not enough values\n";
                            classFileOut << "        }\n";
                        }
                        if (attr->hasMaxOccurs()) {
                            classFileOut << "        if ( count(" << variableName(attr->name()) << "s) > " << attr->maxOccurs() << ") {\n";
                            classFileOut << "            return \"\"; // too much values\n";
                            classFileOut << "        }\n";
                        }
                        classFileOut << "        foreach("<<  variableName(attr->name())<<"s as $attribute) {\n";

                        if (attr->isSimpleElement()) {
                            // non-qstring items (ints) may give problems, so convert them
                    QString varName = stringConversionForAttribute(attr);
                            classFileOut << "            $xml->addChild('" << attr->name() << "', " << varName << ");\n";
                        } else {
                            classFileOut << "        $dom = dom_import_simplexml($xml);\n";
                            classFileOut << "        $child_as_xml = $attribute->toXML(false);\n";
                            classFileOut << "        $child_as_simplexml = new SimpleXMLElement($child_as_xml);\n";
                            classFileOut << "        $child_as_dom = dom_import_simplexml($child_as_simplexml);\n";
                            classFileOut << "        $child_as_leaf = $dom->ownerDocument->importNode($child_as_dom, true);\n";
                            classFileOut << "        $dom->appendChild($child_as_leaf);\n";
                            classFileOut << "        $xml = simplexml_import_dom($dom);\n";
                        }
                        classFileOut << "        } \n";
                    } else if (!attr->required() || obj->isMerged()) {  // optional test for it
                        classFileOut << "        if ( $this->has" << methodName(attr->name()) << "() ) {\n";
                        if (attr->isSimpleElement()) {
                    QString varName = stringConversionForAttribute(attr);
                            classFileOut << "            $xml->addChild('" << attr->name() << "', " << varName << ");\n";
                        } else {
                            classFileOut << "            $dom = dom_import_simplexml($xml);\n";
                            classFileOut << "            $child_as_xml = " << variableName(attr->name()) << "->toXML(false);\n";
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
                        classFileOut << "            $child_as_xml = " << variableName(attr->name()) << "->toXML(false);\n";
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
                    classFileOut << "        if ( $this->has" << methodName(attr->name()) << "() ) {\n";
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
                    classFileOut << "           $str .= $attribute->toStringWithLead($lead . \"    \");\n        }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "        if ( $this->has" << methodName(attr->name()) << "() ) {\n";
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
    // now generate the parser
    //-----------------------------------------------------------------------------------------------

    // generate the parser file
    QString name = "Parser";
    QString fileName = m_outDir + "/" +  fileBaseName(name) + ".php";
    QFile classFile(fileName);
    if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(fileName).toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream classFileOut(&classFile);
    std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;


    // count the number of messages
    QStringList closeTags, rootObjects;
    for (int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((!obj->isEmbedded()) && (obj->name() != "Schema") ) {
            rootObjects.append(obj->name());
            closeTags.append("</" + obj->name() + ">");
        }
    }

    /* may be usefull in future version
    // build a regexp for the rootTags
    QString regExp;
    QString commonPrefix = longestCommonPrefix(rootObjects);
    if (commonPrefix.size() > 0) {
        regExp = "</" + commonPrefix +  "([A-Za-z0-9]*)>";
    } else {
        regExp = closeTags.join("|");
    }
    */

    //-----------------------------------------------------------------------------------------------
    // generate the declaration
    //-----------------------------------------------------------------------------------------------
    classFileOut << "<?php\n\n";
    classFileOut << writeHeader( className(name) );

    // include dependend files
    for (int i=0; i < rootObjects.size(); i++) {
        classFileOut << "require_once \"" << fileBaseName(rootObjects.at(i)) << ".php\";\n";
    }

    // define the class
    classFileOut << "\nclass " << className(name) << " { \n\n";

    // constructor

    // name finder routine
    classFileOut << "    public function messageNameOfXMLString($data) { \n\n";
    classFileOut << "        $xml = new SimpleXMLElement($data);\n";
    classFileOut << "        return $xml->getName();\n";
    classFileOut << "    }\n\n";

    // main parser routine
    classFileOut << "    public function parseXMLMessage($data) { \n\n";
    classFileOut << "        $tag = $this->messageNameOfXMLString($data);\n\n";

    bool first = true;
    for (int i=0; i < rootObjects.size(); i++) {
        if (first) {
            classFileOut << "        if";
            first = false;
        } else {
            classFileOut << " else if";
        }
    classFileOut << " ($tag == \"" << className(rootObjects.at(i)) << "\") {\n";
        classFileOut << "            $xml = new SimpleXMLElement($data);\n";
        classFileOut << "            return $this->parse"<< className(rootObjects.at(i)) << "($xml);\n";
        classFileOut << "        } ";
    }
    classFileOut << "\n        return; // error no root message found\n";
    classFileOut << "    }\n\n";

    // helper routine
    classFileOut << "    private function hasAttribute($object, $attribute) { \n";
    classFileOut << "        foreach($object->attributes() as $a => $b) { \n";
    classFileOut << "            if ($a == $attribute) { \n";
    classFileOut << "                return true; \n";
    classFileOut << "            }     \n";
    classFileOut << "        } \n";
    classFileOut << "        return false; \n";
    classFileOut << "    }\n\n";

    classFileOut << "    private function hasChild($object, $child) { \n";
    classFileOut << "        foreach($object->children() as $a => $b) { \n";
    classFileOut << "            if ($a == $child) { \n";
    classFileOut << "                return true; \n";
    classFileOut << "            }     \n";
    classFileOut << "        } \n";
    classFileOut << "        return false; \n";
    classFileOut << "    }\n\n";

    classFileOut << "    private function countOfChild($object, $child) { \n";
    classFileOut << "        $count = 0;\n";
    classFileOut << "        foreach($object->children() as $a => $b) { \n";
    classFileOut << "            if ($a == $child) { \n";
    classFileOut << "                $count++; \n";
    classFileOut << "            }     \n";
    classFileOut << "        } \n";
    classFileOut << "        return $count; \n";
    classFileOut << "    }\n\n";

    // parser routines
    for (int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if (obj->name() != "Schema") { // ignore this object, it will never be sent
           QString scope = "private";
           if (!obj->isEmbedded()) {  // root object
        scope = "public";
       }
           classFileOut << "    "<< scope <<" function parse" << className(obj->name()) << "( $simplexml ) {\n\n";
           classFileOut << "        $element = new "<< className(obj->name()) << "();\n\n";

       // parse all attributes of this object
           QVector<XSDAttribute*>attributes = obj->attributes();
           QMap<QString, QString>fixedValues = obj->fixedValues();

       // check for the presence of fixed values
           for (int j=0; j < fixedValues.size(); j++) {
                QString name = (fixedValues.keys().at(j));
        classFileOut << "        $element->set" << name << "((string) $simplexml[\"" << name << "\"]);\n";
           }

       // check for the presence of sub elements and attributes
           for (int j=0; j < attributes.size(); j++) {
                XSDAttribute *attr = attributes.at(j);
        QString name = attr->name();
        if (attr->isElement()) {   // its an embedded subelement
           if(attr->isScalar()) {
            classFileOut << "        for ($i = 0; $i < $this->countOfChild($simplexml, \"" << name << "\"); $i++) { \n";
                    classFileOut << "            $child = $this->parse"<< name << "($simplexml->"<< name <<"[$i]);\n";
            classFileOut << "            $element->add" << name << "($child);\n";
                        classFileOut << "        }\n";
                   } else {
            classFileOut << "        if ($this->hasChild($simplexml, \"" << name << "\")) { \n";
                    classFileOut << "            $child = $this->parse"<< name << "($simplexml->"<< name <<");\n";
            classFileOut << "            $element->set" << name << "($child);\n";
                        classFileOut << "        }";
            if (attr->required() && !obj->isMerged()) { // merged objects have weak refernces due to merge
                            classFileOut << " else { \n";
                classFileOut << "            // required element is missing\n";
                            classFileOut << "        }\n";
                        } else {
                            classFileOut << "\n";
            }
                  }
        } else {                   // its an attribute
            classFileOut << "        if ($this->hasAttribute($simplexml, \"" << name << "\")) { \n";
            classFileOut << "            $element->set" << name << "((string) $simplexml[\"" << name << "\"]);\n";
                        classFileOut << "        }";
            if (attr->required() && !obj->isMerged()) {
                            classFileOut << " else { \n";
                classFileOut << "            // required attribute is missing\n";
                            classFileOut << "        }\n";
                        } else {
                            classFileOut << "\n";
            }
        }
       }

           classFileOut << "        return $element;\n";
           classFileOut << "    }\n\n";
    } // ignore schema
    }

    // round up
    classFileOut << "\n}\n"; // make sure there is a newline at the end of the source
    classFileOut << "?>\n";

    // close and flush
    classFileOut.flush();
    classFile.close();
    std::cout << "done.\n" << std::endl;
}

