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

}

void CodeGenQT::setObjects(QVector<XSDObject*>objects) {
	m_objects = objects;
}

void CodeGenQT::setOutputDir(QString outDir) {
	m_outDir = outDir;
}

QString CodeGenQT::localType(QString type) {
	if (type == "xs:string") 
		return "QString";
	else if (type == "xs:boolean")
		return "bool";
	else if (type == "xs:integer")
		return "int";
	else if (type == "xs:dateTime") 
		return "QDate";
	else if (type == "unknown") {
		std::cout << "WARNING unknown type found, defaulting to QString" << std::endl;
		return "QString";
	}
	else if (type == "xs:decimal") // float
		return "float";
	else
		return type;
}

bool CodeGenQT::knownType(QString type) {
	if (type == "xs:string") 
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

void CodeGenQT::go() {
	for(int i=0; i < m_objects.size(); i++) {
		// get a class
		XSDObject *obj = m_objects.at(i);
		
		// get some vars we frequently use
		QString name = obj->name();
		QString upperName = name.toUpper();
		QString lowerName = name.toLower();
		QString niceName  = name.replace(0, 1, name.left(1).toUpper());
		QVector<XSDAttribute*>attributes = obj->attributes();
		QMap<QString, QString>fixedValues = obj->fixedValues();
		
		// report
		std::cout << QString("creating class: %1").arg(niceName).toLatin1().data() << std::endl;
		
		// open the header file
		QString baseName = m_outDir + "/" + lowerName;
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
		
		// generate the header
		headerFileOut << "#ifndef __" << upperName << "_H__\n";
		headerFileOut << "#define __" << upperName << "_H__\n\n";
		headerFileOut << "#include <QtCore>\n";  // we generate for Qt types
		
		// include dependend files
		for(int j=0; j < attributes.size(); j++) {
			XSDAttribute *attr = attributes.at(j);
			if(!knownType(attr->type())) {
				headerFileOut << "#include \"" << attr->type().toLower() << ".h\"\n";
			}
		}
		
		// define the class
		headerFileOut << "\nclass " << niceName << " : QObject { \n\n";
		
		// public section
		headerFileOut << "public:\n";
		headerFileOut << "    " << niceName << "();\n"; // constructor
		headerFileOut << "    " << niceName << "(const " << niceName << "&);\n"; // copy constructor

		// all attributes
		for(int j=0; j < attributes.size(); j++) {
			XSDAttribute *attr = attributes.at(j);
			QString type = localType(attr->type()); // convert to cpp types
			QString attrName = attr->name();
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toUpper());
			QString doc = attr->doc();
			if (doc != "") { // there is documentation
				doc.replace("\n", "\n       ");
				doc.replace("\r", "");
				headerFileOut << "\n    /* " << niceAttrName << ":\n       " << doc << " */\n";
			}
			if (attr->unbounded()) { // there more then one
				// setter
				headerFileOut << "    void add" << niceAttrName << "(" << type << " val);\n";
				// getter
				headerFileOut << "    " << type << " get" << niceAttrName << "At(int i);\n";
				// count
				headerFileOut << "    int countOf" << niceAttrName << "s();\n";
			} else {
				// setter
				headerFileOut << "    void set" << niceAttrName << "(" << type << " val);\n";
				// getter
				headerFileOut << "    " << type << " get" << niceAttrName << "();\n";
				if (!attr->required() || obj->isMerged()) {
					headerFileOut << "    bool has" << niceAttrName << "();\n";
				}
			}
		}
		// and fixed values
		for(int j=0; j < fixedValues.size(); j++) {
			QString attrName = fixedValues.keys().at(j);
			QString type = "QString"; // always a string
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toUpper());
			// getter
			headerFileOut << "    " << type << " get" << niceAttrName << "();\n";
		}
		headerFileOut << "    QString toXML();\n";
		
		// private section
		headerFileOut << "\nprivate:\n";
		
		// all attributes
		for(int j=0; j < attributes.size(); j++) {
			XSDAttribute *attr = attributes.at(j);
			QString type = localType(attr->type()); // convert to cpp types
			QString attrName = attr->name();
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toLower());
			// definition
			if (attr->unbounded()) { // there more then one
				headerFileOut << "    QVector<" << type << "> m_" << niceAttrName << "s;\n";
			} else {
				headerFileOut << "    " << type << " m_" << niceAttrName << ";\n";
			}
			if (!attr->required() || obj->isMerged()) {
				headerFileOut << "    bool " << niceAttrName << "Present = false;\n";
			}
		}
		
		// close the header
		headerFileOut << "\n}; \n\n#endif\n\n";
		
		// close and flush
		headerFileOut.flush();
		headerFile.close();
	
		// create the class file	
		classFileOut << "\n#include \"" << lowerName << ".h\"\n\n";
	
		// constructor
		classFileOut << niceName << "::" << niceName << "() {\n\n"; 
		classFileOut << "}\n\n";

		// copy constructor
		// TODO
		classFileOut << niceName << "::" << niceName << "(const " << niceName << "&) : QObject() {\n\n"; 
		classFileOut << "}\n\n";

		// methods for attributes
		for(int j=0; j < attributes.size(); j++) {
			XSDAttribute *attr = attributes.at(j);
			QString type = localType(attr->type()); // convert to cpp types
			QString attrName = attr->name();
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toUpper());
			QString niceVarName  = attrName.replace(0, 1, attrName.left(1).toLower());
			if (attr->unbounded()) { // there more then one
				// setter
				classFileOut << "void " << niceName << "::add" << niceAttrName << "(" << type << " val) {\n";
				classFileOut << "\n    m_" << niceVarName << "s.append(val);\n}\n\n";
				// getter
				classFileOut << type << " " << niceName << "::get" << niceAttrName << "At(int i) {\n";
				classFileOut << "\n    return m_" << niceVarName << "s.at(i);\n}\n\n";
				// count
				classFileOut << "int " << niceName << "::countOf" << niceAttrName << "s() {\n";
				classFileOut << "\n    return m_" << niceVarName << "s.count();\n}\n\n";
			} else {
				// setter
				classFileOut << "void " << niceName << "::set" << niceAttrName << "(" << type << " val) {\n";
				QVector<QString> enums = attr->enumeration(); 
				if (enums.size() > 0) { // there are enumeration constraints for this item
					classFileOut << "\n    if ( ( val != \"" << enums.at(0) << "\" ) ";
					for (int h=1; h < enums.size(); h++) {
						classFileOut << "&&\n         ( val != \"" << enums.at(h) << "\" ) ";
					}
					classFileOut <<	")\n        return;";
				}
				if (attr->hasMin()) {
				     classFileOut << "\n    if (val < " << attr->min() << ")\n        return;";
				}
				if (attr->hasMax()) {
				     classFileOut << "\n    if (val > " << attr->max() << ")\n        return;";
				}
				if (!attr->required() || obj->isMerged()) {
				     classFileOut << "\n    m_" << niceVarName << "Present = true;";
				}
				classFileOut << "\n    m_" << niceVarName << " = val;\n}\n\n";
				// getter
				classFileOut << type << " " << niceName << "::get" << niceAttrName << "() {\n";
				classFileOut << "\n    return m_" << niceVarName << ";\n}\n\n";
				if (!attr->required() || obj->isMerged()) {
					classFileOut << "bool " << niceName << "::has" << niceAttrName << "() {\n";
					classFileOut << "\n    return m_" << niceVarName << "Present;\n}\n\n";
				}
			}
		}

		// and fixed values
		for(int j=0; j < fixedValues.size(); j++) {
			QString attrName = fixedValues.keys().at(j);
			QString attrValue = fixedValues.values().at(j);
			QString type = "QString"; // always a string
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toUpper());
			// getter
			classFileOut << type << " " << niceName << "::get" << niceAttrName << "() {\n";
			classFileOut << "\n    return \"" << attrValue << "\";\n}\n\n";
		}

		// xml generator
		// TODO generate attributes
		// if attribute name and type are the same it means it was data
		classFileOut << "QString " << niceName << "::toXML() {\n\n";
		classFileOut << "    QString xml = \"<" << name << "\";\n"; // append attributes

		// for attributes
		for(int j=0; j < attributes.size(); j++) {
			XSDAttribute *attr = attributes.at(j);
			QString attrName = attr->name();
			QString attrType = attr->type();
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toUpper());
			QString niceVarName  = attrName.replace(0, 1, attrName.left(1).toLower());
			attrName = attr->name();

			if (attrType != attrName) {
				// check if the attribute exist 
				if (!attr->required() || obj->isMerged()) {
					classFileOut << "    if ( has" << niceAttrName << "() ) {\n";
					classFileOut << "        xml.append(\" " << attrName << " = \\\"\" << m_" << niceVarName << " << \"\\\"\");\n    }\n";
				} else {
					classFileOut << "    xml.append(\" " << attrName << " = \\\"\" << m_" << niceVarName << " << \"\\\"\");\n";
				}
			}
		}
		classFileOut << "    xml.append(\">\\n\");\n"; // close the statement

		// for data members
		for(int j=0; j < attributes.size(); j++) {
			XSDAttribute *attr = attributes.at(j);
			QString attrName = attr->name();
			QString attrType = attr->type();
			QString niceAttrName  = attrName.replace(0, 1, attrName.left(1).toUpper());
			QString niceVarName  = attrName.replace(0, 1, attrName.left(1).toLower());
			attrName = attr->name();

			if (attrType == attrName) {
				// check if the attribute exist 
				if (attr->unbounded() ) {
					classFileOut << "    for(int i=0; i < m_" << niceVarName << "s.count(); i++ ) {\n";
					classFileOut << "        xml.append(" << " m_" << niceVarName << "s.at(i).toXML() );\n    }\n"; 
				} else {
					classFileOut << "    xml.append(" << " m_" << niceVarName << ".toXML() );\n"; 
				}
			}
		}

		// close up
		classFileOut << "    xml.append( \"<" << name << " />\\n\");\n"; // append attributes
		classFileOut << "    return xml;\n";
		classFileOut << "}\n";

		// round up
		classFileOut << "\n"; // make sure there is a newline at the end of the source

		// close and flush
		classFileOut.flush();
		classFile.close();
	}
}
