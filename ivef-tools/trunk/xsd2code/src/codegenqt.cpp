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

#include "codegenqt.h"

CodeGenQT::CodeGenQT()
: CodeGen()
{
        m_prefix = "";
}

void CodeGenQT::setObjects(QVector<XSDObject*>objects) {
    m_objects = objects;
}

void CodeGenQT::setOutputDir(QString outDir) {
    m_outDir = outDir;
}

QString dateToString(QString varName) {
    // new time format (issue 28)
    return varName + ".toString(\"yyyy-MM-dd'T'HH:mm:ss.zzzZ\")";
}

QString dateFromString(QString varName, bool withMillies) {
  
    if (withMillies) 
        return "QDateTime::fromString(" + varName + ", \"yyyy-MM-dd'T'HH:mm:ss.z\")";
    else
        return "QDateTime::fromString(" + varName + ", \"yyyy-MM-dd'T'HH:mm:ss\")";
}

QString CodeGenQT::sizeEvaluatorForType (QString type, QString varName) {
    if (type == "xs:string")
        return varName + ".length()";
    else if (type == "xs:hexBinary") // or should it by a QByteArray?
        return varName + ".size()";
    else 
        return varName; 
}

QString CodeGenQT::localType(QString type) {
    if (type == "xs:string")
        return "QString";
    else if (type == "xs:hexBinary") // or should it by a QByteArray?
        return "QString";
    else if (type == "xs:boolean")
        return "bool";
    else if (type == "xs:integer")
        return "int";
    else if (type == "xs:dateTime")
        return "QDateTime";
    else if (type == "unknown") {
        std::cout << "WARNING unknown type found:" << type.toLatin1().data() <<  ", defaulting to QString" << std::endl;
        return "QString";
    }
    else if (type == "xs:decimal") // float
        return "float";
    else
        return className(type);
}

bool CodeGenQT::knownType(QString type) {
    if (type == "xs:string")
        return true;
    else if (type == "xs:hexBinary") 
        return true;
    else if (type == "xs:boolean")
        return true;
    else if (type == "xs:integer")
        return true;
    else if (type == "xs:dateTime")
        return true;
    else if (type == "unknown")
        return true;
    else if (type == "xs:decimal") // float
        return true;
    else
        return false;
}

QString CodeGenQT::fileBaseName(QString name) {
    //if (m_prefix != "") { 
      return m_prefix + name.replace(0, 1, name.left(1).toUpper());
    //}
}

QString CodeGenQT::className(QString name) {
    //return name.replace(0, 1, name.left(1).toUpper());
    return name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenQT::methodName(QString name) {
    return className(name);
}

QString CodeGenQT::variableName(QString name) {

    if (name.mid(1,1).toUpper() == name.mid(1,1)) { // if second char is uppercase
        return "m_" + name;
    } else {
        return "m_" + name.replace(0, 1, name.left(1).toLower());
    }
}

QString CodeGenQT::longestCommonPrefix(QStringList strings) {

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

QString CodeGenQT::writeHeader(QString fileName) {

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
    header.append( " *  Copyright 2010\n" );
    header.append( " *\n" );
    header.append( " */\n\n" );

    return header;
}

void CodeGenQT::go() {

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

    for(int i=0; i < m_objects.size(); i++) {
        // get a class
        XSDObject *obj = m_objects.at(i);

        // get some vars we frequently use
        QString name = obj->name();
        QString upperName = name.toUpper();
        QVector<XSDAttribute*>attributes = obj->attributes();
        QMap<QString, QString>fixedValues = obj->fixedValues();

        // report
        std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;

        // open the header file
        QString baseName = m_outDir + "/" + fileBaseName(name);
        QFile headerFile(baseName + ".h");
        if (!headerFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("cannot create file: %1").arg(baseName + ".h").toLatin1().data() << std::endl;
            std::exit(-1);
        }
        QTextStream headerFileOut(&headerFile);

        // and the class file
        QFile classFile(baseName + ".cpp");
        if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("cannot create file: %1").arg(baseName + ".cpp").toLatin1().data() << std::endl;
            std::exit(-1);
        }
        QTextStream classFileOut(&classFile);

        //-----------------------------------------------------------------------------------------------
        // generate the header
        //-----------------------------------------------------------------------------------------------
        headerFileOut << writeHeader( className(name) );

        headerFileOut << "#ifndef __" << upperName << "_H__\n";
        headerFileOut << "#define __" << upperName << "_H__\n\n";
        headerFileOut << "#include <QtCore>\n";  // we generate for Qt types

        // include dependend files
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            if(!knownType(attr->type())) {
                headerFileOut << "#include \"" << fileBaseName(attr->type()) << ".h\"\n";
            }
        }

        QString docu = obj->docu();
        if (docu != "") { // there is documentation
            docu.replace("\n", "\\n\n//! ");
            docu.replace("\r", "");
        }

        headerFileOut << "\n//-----------------------------------------------------------\n";
        headerFileOut << "//! \\brief       Class definition of " << className(name) << "\n";
        headerFileOut << "//!\n";
        headerFileOut << "//! " << docu << "\n";
        headerFileOut << "//!\n";

        // define the class
        QString baseClass = "QObject";
        if (obj->hasBaseClass()) {
           baseClass = obj->baseClass();
        }
        headerFileOut << "\nclass " << className(name) << " : public " << baseClass << " { \n";
        headerFileOut << "    Q_OBJECT\n\n";

        // public section
        headerFileOut << "public:\n";
        headerFileOut << "    //!constructor\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << "();\n";

        headerFileOut << "    //!copy constructor\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << "(const " << className(name) << "&);\n";

        headerFileOut << "    //!= operator\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << " & operator=(const " << className(name) << "&/*val*/);\n"; // = operator

        // all attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString type = localType(attr->type()); // convert to cpp types
            QString doc = attr->doc();

            if (doc != "") { // there is documentation
                doc.replace("\n", "\\n\n    //!              ");
                doc.replace("\r", "");
            }

            if (attr->unbounded()) { // there more then one
                // setter
                headerFileOut << "    //!              adds a " << methodName(attr->name()) << ".\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    void add" << methodName(attr->name()) << "(" << type << " val);\n\n";
                // getter
                headerFileOut << "    //!              gets the i-th " << methodName(attr->name()) << ".\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    " << type << " get" << methodName(attr->name()) << "At(int i) const;\n\n";
                // count
                headerFileOut << "    //!              return the number of " << methodName(attr->name()) << " objects.\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    //! \\return     int\n";
                headerFileOut << "    int countOf" << methodName(attr->name()) << "s() const;\n\n";
            } else {
               
		// setter
		if (doc != "")
		    headerFileOut << "    //!              sets the " << methodName(attr->name()) << ": " << doc << "\n";
		else
		    headerFileOut << "    //!              sets the " << methodName(attr->name()) << "\n";
		headerFileOut << "    //!\n";
		headerFileOut << "    void set" << methodName(attr->name()) << "(" << type << " val);\n\n";

                // getter
                if (doc != "")
                    headerFileOut << "    //!              gets the " << methodName(attr->name()) << ": " << doc << "\n";
                else
                    headerFileOut << "    //!              gets the " << methodName(attr->name()) << "\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    //! \\return     " << type << "\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    " << type << " get" << methodName(attr->name()) << "() const;\n\n";
                if (!attr->required() || obj->isMerged()) 
                {
                    headerFileOut << "    //!              returns true if " << methodName(attr->name()) << "is used (optional field).\n";
                    headerFileOut << "    //!\n";
                    headerFileOut << "    //! \\return     bool\n";
                    headerFileOut << "    bool has" << methodName(attr->name()) << "() const;\n\n";
                }
            }
        }
        // and fixed values
        for(int j=0; j < fixedValues.size(); j++) {
            QString attrName = fixedValues.keys().at(j);
            QString type = "QString"; // always a string

            

            // getter
            headerFileOut << "    //!              gets the " << methodName(attrName) << "\n";
            headerFileOut << "    //!\n";
            headerFileOut << "    //! \\return     " << type << "\n";
            headerFileOut << "    //!\n";
            headerFileOut << "    " << type << " get" << methodName(attrName) << "() const;\n";
        }
        
        headerFileOut << "    //!              generates XML of this object including attributes and child elements\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    QString toXML();\n\n";

        headerFileOut << "    //!              generates output of this object including attributes and child elements\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    QString toString();\n\n";

        headerFileOut << "    //!              generates output of this object including attributes and child elements\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    QString toString(QString lead);\n\n";

        headerFileOut << "    //!              encodes a string returning the encoded string\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    QString encode(QString str);\n\n"; // issue 19

        // private section
        headerFileOut << "\nprivate:\n";

        // all attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString type = localType(attr->type()); // convert to cpp types
            // definition
            if (attr->unbounded()) { // there more then one
                headerFileOut << "    QVector<" << type << "> " << variableName(attr->name()) << "s;\n";
            } else {
                headerFileOut << "    " << type << " " << variableName(attr->name()) << ";\n";
            }
            if (!attr->required() || obj->isMerged()) {
                headerFileOut << "    bool " << variableName(attr->name()) << "Present;\n";
            }
        }

        // close the header
        headerFileOut << "\n}; \n\n#endif\n\n";

        // close and flush
        headerFileOut.flush();
        headerFile.close();

        //-----------------------------------------------------------------------------------------------
        // create the class file
        //-----------------------------------------------------------------------------------------------
        classFileOut << "\n#include \"" << fileBaseName(name) << ".h\"\n\n";

        // constructor
        classFileOut << "// Constructor\n";
        classFileOut << className(name) << "::" << className(name) << "() {\n\n";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);

            QString type = localType(attr->type()); // convert to cpp types

            if (! attr->unbounded()) {
                if (type=="QString") {
                    if (attr->isFixed()) {
                       classFileOut << "    // initialize fixed value\n";
                       classFileOut << "    " << variableName(attr->name()) << " = \"" << attr->fixed()  << "\";\n";
                    } else {
                       classFileOut << "    // initialize empty string\n";
                       classFileOut << "    " << variableName(attr->name()) << " = \"\";\n";
                    }
                }
                else {
		    if (type=="bool") {
		        classFileOut << "    // initialize defaults to false\n";
		        classFileOut << "    " << variableName(attr->name()) << " = false;\n";
		    } else if (type=="int") {
		        classFileOut << "    " << variableName(attr->name()) << " = 0;\n";
		    } else if (type=="QDateTime") {
		        classFileOut << "    // initialize with random value\n";
		        classFileOut << "    " << variableName(attr->name()) << " = QDateTime();\n";
		    } else if (type=="float") {
		        classFileOut << "    " << variableName(attr->name()) << " = 0.0;\n";
		    }
		}
	    }

            // ev: is not used     QString niceVarName  = attr->name().replace(0, 1, attr->name().left(1).toLower());
            if (!attr->required() || obj->isMerged()) {
                classFileOut << "    // optional attributes are by default not present\n";
                classFileOut << "    " << variableName(attr->name()) << "Present = false;\n";
            }
        }
        classFileOut << "}\n\n";

        // copy constructor
        classFileOut << "// copy constructor\n";
        classFileOut << className(name) << "::" << className(name) << "(const " << className(name) << " &val) : QObject() {\n\n";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            if (!attr->required() || obj->isMerged()) {
                classFileOut << "    " << variableName(attr->name()) << "Present = val." << variableName(attr->name()) << "Present;\n";
            }
            if (attr->unbounded()) { // there more then one
                classFileOut << "    " << variableName(attr->name()) << "s = val." << variableName(attr->name()) << "s;\n";
            } else {
                classFileOut << "    " << variableName(attr->name()) << " = val." << variableName(attr->name()) << ";\n";
            }
        }
        classFileOut << "}\n\n";

        // = operator
        classFileOut << "// assignement\n";
        classFileOut << className(name) << " & " << className(name) << "::operator=(const " << className(name) << " &val) {\n\n";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            if (!attr->required() || obj->isMerged()) {
                classFileOut << "    " << variableName(attr->name()) << "Present = val." << variableName(attr->name()) << "Present;\n";
            }
            if (attr->unbounded()) { // there more then one
                classFileOut << "    " << variableName(attr->name()) << "s = val." << variableName(attr->name()) << "s;\n";
            } else {
                classFileOut << "    " << variableName(attr->name()) << " = val." << variableName(attr->name()) << ";\n";
            }
        }
        classFileOut << "    return *this;\n";
        classFileOut << "}\n\n";

        // string encoder, issue 19
        classFileOut << "// String encoder\n";
        classFileOut << "QString " << className(name) << "::encode( QString str) {\n";
        classFileOut << "\n";
        classFileOut << "    // replace characters that are illigal in XML with their encodings\n";
        classFileOut << "    str.replace('&', \"&amp;\");\n";
        classFileOut << "    str.replace('<', \"&lt;\");\n";
        classFileOut << "    str.replace('>', \"&gt;\");\n";
        classFileOut << "    str.replace('\"', \"&quot;\");\n";
        classFileOut << "    return str;\n";
        classFileOut << "}\n\n";
       // end issue 19

        // methods for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            if (attr->unbounded()) { // there more then one
                // setter
                classFileOut << "// setter for " << className(name) << "\n";
                classFileOut << "void " << className(name) << "::add" << methodName(attr->name()) << "(" << type << " val) {\n";
                classFileOut << "\n    " << variableName(attr->name()) << "s.append(val);\n}\n\n";
                // getter
                classFileOut << "// getter for " << className(name) << "\n";
                classFileOut << type << " " << className(name) << "::get" << methodName(attr->name()) << "At(int i) const {\n";
                classFileOut << "\n    return " << variableName(attr->name()) << "s.at(i);\n}\n\n";
                // count
                classFileOut << "// count for " << className(name) << "\n";
                classFileOut << "int " << className(name) << "::countOf" << methodName(attr->name()) << "s() const {\n";
                classFileOut << "\n    return " << variableName(attr->name()) << "s.count();\n}\n\n";
            } else {
		// setter
                classFileOut << "// setter for " << className(name) << "\n";
		classFileOut << "void " << className(name) << "::set" << methodName(attr->name()) << "(" << type << " val) {\n";
		QVector<QString> enums = attr->enumeration();
		if (enums.size() > 0) { // there are enumeration constraints for this item

		    // strings should be between quotes, numbers not
		    QString quote;
		    if (type == "QString") {
			quote = "\"";
		    }

                    classFileOut << "// check if the new value is an approved value \n";
		    classFileOut << "\n    if ( ( val != " << quote << enums.at(0) << quote <<" ) ";
		    for (int h=1; h < enums.size(); h++) {
			classFileOut << "&&\n         ( val != " << quote << enums.at(h) << quote << " ) ";
		    }
		    classFileOut <<    ")\n        return;";
		}
		if (attr->hasMin() && knownType(attr->type())) {

		     QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                     classFileOut << "    // check if the new value is within bounds \n";
		     classFileOut << "\n    if (" << evaluator << " < " << attr->min() << ")\n        return;";
		}
		if (attr->hasMax() && knownType(attr->type())) {

		     QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                     classFileOut << "    // check if the new value is within bounds \n";
		     classFileOut << "\n    if (" << evaluator << " > " << attr->max() << ")\n        return;";
		}
		if (!attr->required() || obj->isMerged()) {
		     classFileOut << "\n    " << variableName(attr->name()) << "Present = true;";
		}
		classFileOut << "\n    " << variableName(attr->name()) << " = val;\n}\n\n";

                // getter
                classFileOut << "// getter for " << className(name) << "\n";
                classFileOut << type << " " << className(name) << "::get" << methodName(attr->name()) << "() const {\n";
                classFileOut << "\n    return " << variableName(attr->name()) << ";\n}\n\n";

                if (!attr->required() || obj->isMerged()) {
                    classFileOut << "// check if optional element " << className(name) << " has been set\n";
                    classFileOut << "bool " << className(name) << "::has" << methodName(attr->name()) << "() const {\n";
                    classFileOut << "\n    return " << variableName(attr->name()) << "Present;\n}\n\n";
                }
            }
        }

        // and fixed values
        for(int j=0; j < fixedValues.size(); j++) {
            QString attrName = fixedValues.keys().at(j);
            QString attrValue = fixedValues.values().at(j);
            QString type = "QString"; // always a string

            // getter
            classFileOut << "// getter for " << className(name) << "\n";
            classFileOut << type << " " << className(name) << "::get" << methodName(attrName) << "() const {\n";
            classFileOut << "\n    return \"" << attrValue << "\";\n}\n\n";
        }

        // xml generator
        // if attribute name and type are the same it means it was data
        classFileOut << "// Get XML Representation\n";
        classFileOut << "QString " << className(name) << "::toXML() {\n\n";
        classFileOut << "    QString xml = \"<" << name << "\";\n"; // append attributes

        // for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            QString varName = "encode (" + variableName(attr->name()) + ")"; // default to string, issue 19

            if (attrType != attr->name()) {

                // non-qstring items (ints) may give problems, so convert them
                if (type == "QDateTime") {
                    varName = dateToString(variableName(attr->name()) );
                } else if (type == "bool" ) {
                    varName = "QString(" + variableName(attr->name()) + " ? \"true\" : \"false\" )";
                } else if (type == "float") {
                    varName = "QString::number(" + variableName(attr->name()) + ", 'f')";
                } else if (type != "QString") {
                    varName = "QString::number(" + variableName(attr->name()) + ")";
                }
                // check if the attribute exist
                if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    // check for presence of optional attribute\n";
                    classFileOut << "    if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "        xml.append(\" " << attr->name() << "=\\\"\" + " << varName << " + \"\\\"\");\n    }\n";
                } else {
                    classFileOut << "    xml.append(\" " << attr->name() << "=\\\"\" + " << varName << " + \"\\\"\");\n";
                }
            }
        }
        classFileOut << "    xml.append(\">\\n\");\n"; // close the statement

        // for data members
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = localType (attr->type());

            if (attrType == attr->name()) {
                // check if the attribute exist
                if (attr->unbounded() ) {
                    classFileOut << "    // add all included data\n";
                    classFileOut << "    for(int i=0; i < " << variableName(attr->name()) << "s.count(); i++ ) {\n";
                    classFileOut << "        " << attrType << " attribute = " << variableName(attr->name()) << "s.at(i);\n";
                    classFileOut << "        xml.append( attribute.toXML() );\n    }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    // add optional data if available\n";
                    classFileOut << "    if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "        xml.append(" << " " << variableName(attr->name()) << ".toXML() );\n    }\n";
                } else {
                    classFileOut << "    xml.append(" << " " << variableName(attr->name()) << ".toXML() );\n";
                }
            }
        }

        // close up
        classFileOut << "    xml.append( \"</" << name << ">\\n\");\n"; // append attributes
        classFileOut << "    return xml;\n";
        classFileOut << "}\n\n";

        // string generator
        // if attribute name and type are the same it means it was data
        classFileOut << "// Get String Representation\n";
        classFileOut << "QString " << className(name) << "::toString() {\n\n";
        classFileOut << "    return toString(\"\");\n";
        classFileOut << "}\n\n";

        classFileOut << "// Get String Representation with a lead\n";
        classFileOut << "QString " << className(name) << "::toString(QString lead) {\n\n";
        classFileOut << "    QString str = lead + \"" << name << "\\n\";\n"; // append attributes

        // for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            QString varName = variableName(attr->name());

            if (attrType != attr->name()) {

                // non-qstring items (ints) may give problems, so convert them
                if (type == "QDateTime") {
                    varName = dateToString(variableName(attr->name()) );
                } else if (type != "QString") {
                    varName = "QString::number(" + variableName(attr->name()) + ")";
                }
                // check if the attribute exist
                if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    // check for presence of optional attribute\n";
                    classFileOut << "    if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "        str.append( lead + \"    " << attr->name() << " = \" + " << varName << " + \"\\n\");\n    }\n";
                } else {
                    classFileOut <<     "    str.append( lead + \"    " << attr->name() << " = \" + " << varName << " + \"\\n\");\n";
                }
            }
        }

        // for data members
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = localType (attr->type());

            if (attrType == attr->name()) {
                // check if the attribute exist
                if (attr->unbounded() ) {
                    classFileOut << "    // add all included data\n";
                    classFileOut << "    for(int i=0; i < " << variableName(attr->name()) << "s.count(); i++ ) {\n";
                    classFileOut << "       " << attrType << " attribute = " << variableName(attr->name()) << "s.at(i);\n";
                    classFileOut << "       str.append( attribute.toString(lead + \"    \") );\n    }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    // add all optional data if present\n";
                    classFileOut << "    if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "        str.append(" << " " << variableName(attr->name()) << ".toString(lead + \"    \") );\n    }\n";
                } else {
                    classFileOut <<     "    str.append(" << " " << variableName(attr->name()) << ".toString(lead + \"    \") );\n";
                }
            }
        }

        // close up
        classFileOut << "    return str;\n";
        classFileOut << "}\n";

        // round up
        classFileOut << "\n"; // make sure there is a newline at the end of the source

        // close and flush
        classFileOut.flush();
        classFile.close();
    }

    //-----------------------------------------------------------------------------------------------
    // now generate the parser
    //-----------------------------------------------------------------------------------------------

    // open the header file
    QString name = "Parser";

    QFile headerFile(m_outDir + "/" + fileBaseName(name) + ".h");
    if (!headerFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(m_outDir + "/" +  fileBaseName(name) + ".h").toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream headerFileOut(&headerFile);

    // and the parser file
    QFile classFile(m_outDir + "/" +  fileBaseName(name) + ".cpp");
    if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(m_outDir + "/" +  fileBaseName(name) + ".cpp").toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream classFileOut(&classFile);

    // generate the header
    headerFileOut << "#ifndef __" << name.toUpper() << "_H__\n";
    headerFileOut << "#define __" << name.toUpper() << "_H__\n\n";
    headerFileOut << "#include <QtCore>\n";
    headerFileOut << "#include <QXmlInputSource>\n";
    headerFileOut << "#include <QXmlDefaultHandler>\n\n";

    // include dependend files
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if (obj->name() != "Schema") {
           headerFileOut << "#include \"" << fileBaseName(obj->name()) << ".h\"\n";
        } 
    }

    headerFileOut << "\n//-----------------------------------------------------------\n";
    headerFileOut << "//! \\brief       Class definition of " << className(name) << "\n";
    headerFileOut << "//!\n";

    // define the class
    headerFileOut << "\nclass " << className(name) << " : public QObject, QXmlDefaultHandler, QXmlSimpleReader { \n";
    headerFileOut << "    Q_OBJECT\n\n";

    // public section
    headerFileOut << "public:\n";
    headerFileOut << "    //!constructor\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    " << className(name) << "();\n"; // constructor
    headerFileOut << "    //!delegate methods for QXmlDefaultHandler\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    bool startElement(const QString &,\n"; // the parser routine
    headerFileOut << "                      const QString &,\n";
    headerFileOut << "                      const QString & qName,\n";
    headerFileOut << "                      const QXmlAttributes & atts);\n";
    headerFileOut << "    bool endElement(const QString &,\n"; // the parser routine
    headerFileOut << "                      const QString &,\n";
    headerFileOut << "                      const QString & qName);\n";
    headerFileOut << "    //!the actual parse routine\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    bool parseXMLString(QString data, bool cont);\n";

    // define the signales
    headerFileOut << "\nsignals:\n";
    headerFileOut << "    //!signals fired by the parser when a new object has been parsed\n";
    headerFileOut << "    //!\n";
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((!obj->isEmbedded()) && (obj->name() != "Schema") ) {
            headerFileOut << "    void signal" << className(obj->name()) << "( " << className(obj->name()) << " obj );\n";
        }
    }
    // issue 24
    headerFileOut << "    //!signals fired by the parser when a parser problem occured\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    void signalError(QString errorStr);\n";
    headerFileOut << "    void signalWarning(QString errorStr);\n";

    // protected section (Issue 24)
    headerFileOut << "protected:\n";
    headerFileOut << "    virtual QString composeMessage( const QXmlParseException& exception );\n";
    headerFileOut << "    virtual bool    error( const QXmlParseException& exception );\n";
    headerFileOut << "    virtual bool    fatalError( const QXmlParseException& exception );\n";
    headerFileOut << "    virtual bool    warning( const QXmlParseException& exception );\n";
    // end of Issue 24

    // private section
    headerFileOut << "\nprivate:\n";
    headerFileOut << "    QString m_dataBuffer;\n";
    headerFileOut << "    QXmlInputSource m_inputForParser;\n";
    headerFileOut << "    QStack<QObject *> m_objStack;\n";
    headerFileOut << "    QStack<QString> m_typeStack;\n";

    // close the header
    headerFileOut << "\n}; \n\n#endif\n\n";

    // close and flush
    headerFileOut.flush();

    // The class file
    classFileOut << "\n#include \"" << fileBaseName(name) << ".h\"\n\n";

    // constructor
    classFileOut << "// Constructor\n";
    classFileOut << className(name) << "::" << className(name) << "() {\n\n";
    classFileOut << "    // we are a subclass of the parser, and our own delegate\n";
    classFileOut << "    setContentHandler(this);\n";
    classFileOut << "    setErrorHandler(this);\n"; // Issue 24
    classFileOut << "}\n\n";

    // main parser routine
    classFileOut << "// Parser delegate routine\n";
    classFileOut << "bool " << className(name) << "::startElement(const QString &,\n"; // the parser routine
    classFileOut << "     const QString &,\n";
    classFileOut << "     const QString & qName,\n";
    classFileOut << "     const QXmlAttributes & atts) {\n\n";

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
        classFileOut << "        // create a placeholder\n";
        classFileOut << "        " << className(obj->name()) << " *obj = new " << className(obj->name()) << ";\n";

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
            classFileOut << "        // examine all supplied attributes\n";
            classFileOut << "        for (int i=0; i < atts.length(); i++) {\n";
            classFileOut << "            QString key = atts.localName(i);\n";
            classFileOut << "            QString value = atts.value(i);\n\n";
            classFileOut << "            // and add them if we know them\n";
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

                    if (type == "QString") {
                        classFileOut << "                QString val = value;\n";
                    } else if (type == "bool") {
                        classFileOut << "                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings \n";
                        classFileOut << "                bool val = (value.toUpper() == \"YES\" ||\n";
                        classFileOut << "                            value.toUpper() == \"TRUE\" ||\n";
                        classFileOut << "                            value == \"1\");\n";
                    } else if (type == "int") {
                        classFileOut << "                int val = value.toInt();\n";
                    } else if (type == "QDateTime") {
                        // timea may have a leading Z (issue 28)
                        classFileOut << "                // date encoding should end on a Z, but some suppliers may exclude it\n";
                        classFileOut << "                // we can be robust by checking for it\n";
                        classFileOut << "                if (value.right(1) == \"Z\") { // new time encoding\n";
                        classFileOut << "                     value = value.left(value.length() - 1);\n";
                        classFileOut << "                }\n"; 
                        // dates may have milies or not according to xs:dateTime
                        classFileOut << "                QDateTime val = " << dateFromString("value", true) << ";\n";
                        classFileOut << "                // a date may be sent with or without miliseconds\n";
                        classFileOut << "                if (!val.isValid()) { \n";
                        classFileOut << "                     // try other variant\n";
                        classFileOut << "                     val = " << dateFromString("value", false) << ";\n";
                        classFileOut << "                }\n";
                    }
                    else if (type == "float") {
                        classFileOut << "                float val = value.toFloat();\n";
                    } else  {
                        classFileOut << "                " << type << " val = value;\n";
		    }

                    classFileOut << "                obj->set" << methodName(attrName) << "(val);\n";
                    classFileOut << "            }\n";
                }
            }
            classFileOut << "        }\n";
        }

        // store in local object (or stack) and signal on end tag
        // this way we can set obj in objects
        classFileOut << "        // push the new object on the stack, on a close element we will pop it\n";
        classFileOut << "        m_objStack.push( obj );\n";
        classFileOut << "        m_typeStack.push( \"" << className(obj->name()) << "\" );\n";
        classFileOut << "    }\n";
    }
    classFileOut << "    return true;\n";
    classFileOut << "}\n\n";

    // TODO check for attributes and messages we do not know and give an alert

    // the endTag routine
    classFileOut << "// Parser delegate routine\n";
    classFileOut << "bool " << className(name) << "::endElement(const QString &,\n"; // the parser routine
    classFileOut << "     const QString &,\n";
    classFileOut << "     const QString & qName) {\n\n";

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
        classFileOut << "        // we know this tag, so we can close the top most object on the object stack\n";
        classFileOut << "        m_typeStack.pop();\n"; // will be equal to qName so ignore
        classFileOut << "        " << className(obj->name()) << " *obj = (" << className(obj->name()) << "*) ( m_objStack.pop() );\n";

        // for all objects that could accept such an object
        for(int i=0; i < m_objects.size(); i++) {
            XSDObject *parent = m_objects.at(i);

            for(int j=0; j < parent->attributes().size(); j++) {
                XSDAttribute *attr = parent->attributes().at(j);
                QString objType = attr->type();

                if (objType == className(obj->name()) /*&& parent->isRootObject()*/) { // this object has an attribute of that type
                    classFileOut << "        // check if there is a parent on the stack that needs this object as a child\n";
                    classFileOut << "        if ( m_typeStack.top() == \"" << parent->name() << "\") {\n";
                    if (attr->unbounded() ) {
                        classFileOut << "                (("<< parent->name() << "*) ( m_objStack.top() ) )->add" << className(obj->name()) << "( *obj );\n";
                    } else {
                        classFileOut << "                (("<< parent->name() << "*) ( m_objStack.top() ) )->set" << className(obj->name()) << "( *obj );\n";
                    }
                    classFileOut << "        }\n"; // close if
                }
            }
        }
        if ((!obj->isEmbedded())) { // only if this object is not embedded
            classFileOut << "        // tell the world a new object is available\n";
            classFileOut << "        // this is only done for root level objects to avoid a storm of signals\n";
            classFileOut << "        emit signal" << className(obj->name()) << "( *obj ); \n";
        }
        classFileOut << "        delete( obj ); \n";
        classFileOut << "    }\n"; // close if
    }
    classFileOut << "    return true;\n";
    classFileOut << "}\n\n"; // close method

    // the parseXMLString routine
    classFileOut << "// the actual parsing routine\n";
    classFileOut << "bool " << className(name) << "::parseXMLString(QString data, bool cont) { \n\n";
    classFileOut << "     // add the data to what was left over from a previous parse run\n";
    classFileOut << "     m_dataBuffer.append(data);\n\n";

    // count the number of messages
    QStringList closeTags, rootObjects;
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ((!obj->isEmbedded()) && (obj->name() != "Schema") ) {
            rootObjects.append(obj->name());
            closeTags.append("</" + obj->name() + ">");
        }
    }

    // Issue 40 start
    // build a regexp for the rootTags
    QString regExp;
    QString commonPrefix = longestCommonPrefix(rootObjects);
    if (commonPrefix.size() > 0) {
        regExp = "</" + commonPrefix +  "([A-Za-z0-9]*)>";
    } else {
        regExp = closeTags.join("|");
    }

    // we search the buffer for any close tag that matches our regexp
    classFileOut << "     // search the buffer for the nearest closetag\n";
    classFileOut << "     int index = 0;\n";
    classFileOut << "     QRegExp rx( \"" + regExp + "\");\n";

    // then we eat the buffer message by message and parse it
    classFileOut << "     // parse the messages in the buffer one by one\n";
    classFileOut << "     while ( (index = rx.indexIn( m_dataBuffer )) != -1 ) {\n";
    classFileOut << "          int len = index + rx.matchedLength();\n";
    classFileOut << "          QString message = m_dataBuffer.left(len);\n";
    classFileOut << "          m_dataBuffer.remove(0, len);\n";
    classFileOut << "          m_inputForParser.setData(message);\n";
    classFileOut << "          this->parse(&m_inputForParser, false);\n";
    classFileOut << "     }\n";
    // Issue 40 end

    classFileOut << "     // we finished parsing, check if we should keep possible\n";
    classFileOut << "     // partial messages in the buffer\n";
    classFileOut << "     if (!cont) {\n";
    classFileOut << "         m_dataBuffer = \"\";\n";
    classFileOut << "     }\n";
    classFileOut << "     return true;\n";

    classFileOut << "}\n\n"; // close method

    // add error handling routines (Issue 24)
    classFileOut << "// helper routine to make a readable error report\n";
    classFileOut << "QString Parser::composeMessage( const QXmlParseException& exception ) {\n";
    classFileOut << "    QString errorstr( exception.message() );\n";
    classFileOut << "    errorstr += \" at line \" + QString::number(exception.lineNumber());\n";
    classFileOut << "    errorstr += \" (column \" + QString::number(exception.columnNumber());\n";
    classFileOut << "    errorstr += \"): \" + m_inputForParser.data().section('\\n', exception.lineNumber()-1, exception.lineNumber()-1);\n";
    classFileOut << "    return errorstr;\n";
    classFileOut << "}\n\n";
    classFileOut << "// parser delegate method to turn parser errors in readable messages\n";
    classFileOut << "bool Parser::error( const QXmlParseException& exception ) {\n";
    classFileOut << "    emit signalError( composeMessage( exception ) );\n";
    classFileOut << "    return QXmlDefaultHandler::error( exception );\n";
    classFileOut << "}\n\n";
    classFileOut << "// parser delegate method to turn parser errors in readable messages\n";
    classFileOut << "bool Parser::fatalError( const QXmlParseException& exception ) {\n";
    classFileOut << "    emit signalError( composeMessage( exception ) );\n";
    classFileOut << "    return QXmlDefaultHandler::fatalError( exception );\n";
    classFileOut << "}\n\n";
    classFileOut << "// parser delegate method to turn parser errors in readable messages\n";
    classFileOut << "bool Parser::warning( const QXmlParseException& exception ) {\n";
    classFileOut << "    emit signalWarning( composeMessage( exception ) );\n";
    classFileOut << "    return QXmlDefaultHandler::warning( exception );\n";
    classFileOut << "}\n";
    // end of Issue 24

    // round up
    classFileOut << "\n"; // make sure there is a newline at the end of the source

    // close and flush
    classFileOut.flush();
    classFile.close();
}

