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
 *  Copyright 2010
 *
 */

#include <cstdlib>

#include "codegenqt.h"

CodeGenQT::CodeGenQT()
: CodeGen(),
  m_prefix(),
  m_namespace( true )
{
}

void CodeGenQT::setObjects(QVector<XSDObject*>objects) {
    m_objects = objects;
}

void CodeGenQT::setOutputDir(QString outDir) {
    m_outDir = outDir;
}

QString CodeGenQT::nameSpaceName() {
    return m_prefix.toLower();
}

QString dateToString(QString varName) {

    return "dateToString( "+ varName + ")";
}

QString dateFromString(QString varName) {

    return "QDateTime::fromString(" + varName + ", Qt::ISODate)";
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
        return "long long";
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

QString CodeGenQT::localTypeToString(XSDAttribute *attr, QString varName, bool encode) {

    QString type = localType(attr->type()); // convert to cpp types

    if (type == "QDateTime") {
        varName = dateToString( varName );
    } else if (type == "bool" ) {
        varName = "QString( " + varName + " ? \"true\" : \"false\" )";
    } else if (type == "float") { // issue 63
        if (attr->hasDigits()) {
            varName = "QString::number(" + varName + ", 'f', " + QString::number(attr->digits()) + ")";
        } else {
            varName = "QString::number( " + varName + ", 'f')";
        }
    } else if (type != "QString") {
        varName = "QString::number( " + varName + " )";
    } else if (encode) {
        varName = "encode (" + varName + ")"; // default to string, issue 19
    }

    return varName;
}

QString CodeGenQT::fileBaseName(QString name) {
    return m_prefix + name.replace(0, 1, name.left(1).toUpper());
}

QString CodeGenQT::className(QString name) {
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
    header.append( "/*\n" );
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
    header.append( " *  Generated by schema2code on "+  QDateTime::currentDateTime().toString() + ".\n" );
    header.append( " **********************************************************************************\n" );
    header.append( " *  Copyright 2010\n" );
    header.append( " *\n" );
    header.append( " */\n\n" );

    return header;
}

void CodeGenQT::go() {

    QDir outDir( m_outDir );
    if ( !outDir.exists() )
    {
        std::cerr << QString("output dir does not exist: %1").arg(m_outDir).toLatin1().data() << std::endl;
        std::exit(1);
    }
    if ( !outDir.exists( "include" ) &&
         !outDir.mkdir( "include" ) )
    {
        std::cerr << QString("can not create output dir: %1/include").arg(outDir.path()).toLatin1().data() << std::endl;
        std::exit(2);
    }
    if ( !outDir.exists( "src" ) &&
         !outDir.mkdir( "src" ) )
    {
        std::cerr << QString("can not create output dir: %1/src").arg(outDir.path()).toLatin1().data() << std::endl;
        std::exit(2);
    }

    functionsFile();
    classFiles();
    parserFile();
}

QString CodeGenQT::attributeConstructor( QVector<XSDAttribute*>& attributes )
{
    QString constructor( "\n :  QObject()" );
    for(int j=0; j < attributes.size(); j++) {
        XSDAttribute *attr = attributes.at(j);

        QString type = localType(attr->type()); // convert to cpp types

        if (! attr->isScalar()) {
            if (type=="QString") {
                if (attr->isFixed()) {
                    constructor += ",\n    " + variableName(attr->name()) + "( \"" + attr->fixed()  + "\" )";
                    constructor += ", // initialize fixed value\n    " + variableName(attr->name()) + "Present( true )"; // issue 21
                } else {
                    constructor += ",\n    " + variableName(attr->name()) + "()";
                    constructor += ",\n    " + variableName(attr->name()) + "Present( false )"; // issue 21
                }
            }
            else {
                if (type=="bool") {
                    constructor += ",\n    " + variableName(attr->name()) + "( false )";
                } else if (type=="int") {
                    constructor += ",\n    " + variableName(attr->name()) + "( 0 )";
                } else if (type=="QDateTime") {
                    constructor += ",\n    " + variableName(attr->name()) + "()";
                } else if (type=="float") {
                    constructor += ",\n    " + variableName(attr->name()) + "( 0.0 )";
                }
                constructor += ",\n    " + variableName(attr->name()) + "Present( false )"; // issue 21
            }
        }
    }
    constructor += ",\n    m_changed(true)";
    return constructor;
}

void CodeGenQT::classFiles() {

    // first analyse the objects if they are embedded objects
    // for all objects that could accept such an object
    QString nameSpace = "none";
    // bool useNameSpace = false;
    for(int i=0; i < m_objects.size(); i++) {
        // for all objects
        XSDObject *obj1 = m_objects.at(i);
        obj1->setSimpleElement(false); // assume not a simple element

        // find if there is another object that refers to the obj
        for(int h=0; h < m_objects.size(); h++) {

            XSDObject *obj2 = m_objects.at(h);

            // refers means obj2 has an attribute of type obj1
            for(int j=0; j < obj2->attributes().size(); j++) {
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
            for(int j=0; j < obj1->fixedValues().size(); j++) {
                QString attrName = obj1->fixedValues().keys().at(j);
                if (attrName == "targetNamespace") {
                    nameSpace = obj1->fixedValues().values().at(j);
                    std::cout << "Using namespace: " << nameSpace.toLatin1().data() << std::endl;
                    // useNameSpace = true;
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

        // check for simple elements
        if (obj->isSimpleElement()) {
            std::cout << QString("skipping class: %1").arg(className(name)).toLatin1().data() << std::endl;
            continue;
        }

        // report
        std::cout << QString("creating class: %1").arg(className(name)).toLatin1().data() << std::endl;

        // open the header file
        QFile headerFile(m_outDir + "/include/" + fileBaseName(name) + ".h");
        if (!headerFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("cannot create file: %1").arg(headerFile.fileName()).toLatin1().data() << std::endl;
            std::exit(3);
        }
        QTextStream headerFileOut(&headerFile);

        // and the class file
        QFile classFile(m_outDir + "/src/" + fileBaseName(name) + ".cpp");
        if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("cannot create file: %1").arg(classFile.fileName()).toLatin1().data() << std::endl;
            std::exit(3);
        }
        QTextStream classFileOut(&classFile);

        //-----------------------------------------------------------------------------------------------
        // generate the header
        //-----------------------------------------------------------------------------------------------
        headerFileOut << writeHeader( className(name) );

        headerFileOut << "#ifndef __" << upperName << "_H__\n";
        headerFileOut << "#define __" << upperName << "_H__\n\n";
        headerFileOut << "#include <QObject>\n";
        headerFileOut << "#include <QString>\n";
        headerFileOut << "#include <QDateTime>\n";

        // include dependend files
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            if(!knownType(attr->type())) {
                headerFileOut << "#include \"" << fileBaseName(attr->type()) << ".h\"\n";
            }
        }
        headerFileOut << "#ifndef SCHEMA" << m_prefix.toUpper() << "_EXPORT\n";
        headerFileOut << "# ifdef SCHEMA" << m_prefix.toUpper() << "_BUILD_STATIC\n";
        headerFileOut << "#  define SCHEMA" << m_prefix.toUpper() << "_EXPORT\n";
        headerFileOut << "# else\n";
        headerFileOut << "#  ifdef SCHEMA" << m_prefix.toUpper() << "_BUILD\n";
        headerFileOut << "#   define SCHEMA" << m_prefix.toUpper() << "_EXPORT Q_DECL_EXPORT\n";
        headerFileOut << "#  else\n";
        headerFileOut << "#   define SCHEMA" << m_prefix.toUpper() << "_EXPORT Q_DECL_IMPORT\n";
        headerFileOut << "#  endif\n";
        headerFileOut << "# endif\n";
        headerFileOut << "#endif\n";

        headerFileOut << "\nclass XmlStreamReader;\n";

        if ( m_namespace ) {
            headerFileOut << "\nnamespace " << nameSpaceName() << " {\n";
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
        headerFileOut << "class SCHEMA" << m_prefix.toUpper() << "_EXPORT " << className(name) << " : public " << baseClass << " {\n";
        headerFileOut << "    Q_OBJECT\n\n";

        // public section
        headerFileOut << "public:\n";
        headerFileOut << "    //! constructor\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << "();\n";

        headerFileOut << "    //! constructor for parser function\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << "(XmlStreamReader&);\n";

        headerFileOut << "    //! copy constructor\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << "(const " << className(name) << "&);\n";

        headerFileOut << "    //! = operator\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    " << className(name) << " & operator=(const " << className(name) << "& val);\n"; // = operator

        headerFileOut << "    //! == operator\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    bool operator==(const " << className(name) << "& val) const;\n"; // = operator

        // all attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString type = localType(attr->type()); // convert to cpp types
            QString doc = attr->doc();

            if (doc != "") { // there is documentation
                doc.replace("\n", "\\n\n    //! ");
                doc.replace("\r", "");
            }

            if (attr->isScalar()) { // there more then one
                // issue 72 delete
                headerFileOut << "    //! removes a " << methodName(attr->name()) << ".\n";
                headerFileOut << "    //!\n";
                if ( attr->isElement() )
                    headerFileOut << "    bool remove" << methodName(attr->name()) << "(const " << type << "& val);\n\n";
                else
                    headerFileOut << "    bool remove" << methodName(attr->name()) << "(" << type << " val);\n\n";
                // setter
                headerFileOut << "    //! adds a " << methodName(attr->name()) << ".\n";
                headerFileOut << "    //!\n";
                if ( attr->isElement() )
                    headerFileOut << "    bool add" << methodName(attr->name()) << "(const " << type << "& val);\n\n";
                else
                    headerFileOut << "    bool add" << methodName(attr->name()) << "(" << type << " val);\n\n";
                // getter
                headerFileOut << "    //! gets the i-th " << methodName(attr->name()) << ".\n";
                headerFileOut << "    //!\n";
                if ( attr->isElement() )
                    headerFileOut << "    const " << type << "& get" << methodName(attr->name()) << "At(int i) const;\n\n";
                else
                    headerFileOut << "    " << type << " get" << methodName(attr->name()) << "At(int i) const;\n\n";
                // count
                headerFileOut << "    //!              return the number of " << methodName(attr->name()) << " objects.\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    //! \\return     int\n";
                headerFileOut << "    int countOf" << methodName(attr->name()) << "s() const;\n\n";
            } else {

                // setter
                if (doc != "")
                    headerFileOut << "    //! sets the " << methodName(attr->name()) << ": " << doc << "\n";
                else
                    headerFileOut << "    //! sets the " << methodName(attr->name()) << "\n";
                headerFileOut << "    //!\n";
                if ( attr->isElement() )
                    headerFileOut << "    bool set" << methodName(attr->name()) << "(const " << type << "& val);\n\n";
                else
                    headerFileOut << "    bool set" << methodName(attr->name()) << "(" << type << " val);\n\n";

                // getter
                if (doc != "")
                    headerFileOut << "    //! gets the " << methodName(attr->name()) << ": " << doc << "\n";
                else
                    headerFileOut << "    //! gets the " << methodName(attr->name()) << "\n";
                headerFileOut << "    //!\n";
                headerFileOut << "    //! \\return     " << type << "\n";
                headerFileOut << "    //!\n";
                if ( attr->isElement() )
                    headerFileOut << "    const " << type << "& get" << methodName(attr->name()) << "() const;\n\n";
                else
                    headerFileOut << "    " << type << " get" << methodName(attr->name()) << "() const;\n\n";
                if (!attr->required() || obj->isMerged())
                {
                    headerFileOut << "    //! returns true if " << methodName(attr->name()) << "is used (optional field).\n";
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
            headerFileOut << "    //! gets the " << methodName(attrName) << "\n";
            headerFileOut << "    //!\n";
            headerFileOut << "    //! \\return     " << type << "\n";
            headerFileOut << "    //!\n";
            headerFileOut << "    " << type << " get" << methodName(attrName) << "() const;\n";
        }

        headerFileOut << "    //! generates XML of this object including attributes and child elements\n";
        headerFileOut << "    //! returns empty string if not all required elements are available\n";
        headerFileOut << "    //! If empty string returned, check lastError() for problem description\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    const QString& toXML(bool outputNamespace = true);\n\n";

        headerFileOut << "    //! generates output of this object including attributes and child elements\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    QString toString() const;\n\n";

        headerFileOut << "    //! generates output of this object including attributes and child elements\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    QString toString(QString lead) const;\n\n";

        headerFileOut << "    //! return last error found in toXML function\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    const QString& lastError() const;\n\n";

        headerFileOut << "    //! return changed\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     bool\n";
        headerFileOut << "    const bool& changed() const;\n\n";

        headerFileOut << "    //! return store\n";
        headerFileOut << "    //!\n";
        headerFileOut << "    //! \\return     QString\n";
        headerFileOut << "    const QString& store() const;\n\n";


        // private section
        headerFileOut << "\nprivate:\n";

        // all attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString type = localType(attr->type()); // convert to cpp types
            // definition
            if (attr->isScalar()) { // there more then one
                headerFileOut << "    QList<" << type << "> " << variableName(attr->name()) << "s;\n";
            } else {
                headerFileOut << "    " << type << " " << variableName(attr->name()) << ";\n";
                //if (!attr->required() || obj->isMerged()) { // issue 21
                headerFileOut << "    bool " << variableName(attr->name()) << "Present;\n";
                //}
            }
        }

        // close the header
        headerFileOut << "    QString m_lastError;\n";
        headerFileOut << "    bool m_changed;\n";
        headerFileOut << "    QString m_store;\n};\n";

        if ( m_namespace ) {
            headerFileOut << "} //end ns\n";
        }
        headerFileOut << "\n#endif\n";

        // close and flush
        headerFileOut.flush();
        headerFile.close();

        //-----------------------------------------------------------------------------------------------
        // create the class file
        //-----------------------------------------------------------------------------------------------
        classFileOut << "#include <cstdlib>\n";  // for the occasional debug string
        classFileOut << "#include <iostream>\n"; // for the occasional debug string
        classFileOut << "#include \"" << fileBaseName("Functions") << ".h\"\n";

        classFileOut << "\n#include \"" << fileBaseName(name) << ".h\"\n\n";

        if ( m_namespace ) {
            classFileOut << "namespace " << nameSpaceName() << " {\n\n";
        }

        // constructor
        classFileOut << "// Constructor\n";
        classFileOut << className(name) << "::" << className(name) << "()";
        classFileOut << attributeConstructor( attributes );
        classFileOut << "\n{\n}\n\n";

        // constructor for parser function
        classFileOut << "// Constructor for parser function\n";
        classFileOut << className(name) << "::" << className(name) << "(XmlStreamReader& xml)";
        classFileOut << attributeConstructor( attributes );
        classFileOut << "\n{\n";

        bool first( true );
        for(int j=0; j < attributes.size(); j++) {

            XSDAttribute *attr = attributes.at(j);
            if ( !attr->isElement() ) {

                if ( first )
                {
                    classFileOut << "    QXmlStreamAttributes attr = xml.attributes();\n";
                    first = false;
                }
                QString attrType = attr->type();
                QString type = localType(attrType); // convert to cpp types

                classFileOut << "    if ( attr.hasAttribute( \"" << attr->name() << "\" ) )\n";
                classFileOut << "    {\n";

                if (type == "QString") {
                    classFileOut << "        if ( !set" << attr->name() << "( attr.value( \"" << attr->name()
                                 << "\" ).toString() ) )\n";
                } else if (type == "bool") {
                    classFileOut << "        // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings\n";
                    classFileOut << "        QString value = attr.value( \"" << attr->name() << "\" ).toString().toUpper();\n";
                    classFileOut << "        if ( !set" << attr->name() << "( value == \"YES\" ||\n";
                    classFileOut << "                             value == \"TRUE\" ||\n";
                    classFileOut << "                             value == \"1\") )\n";
                } else if (type == "long long") {
                    classFileOut << "        if ( !set" << attr->name() << "( attr.value( \"" << attr->name()
                                 << "\" ).toString().toLongLong() ) )\n";
                } else if (type == "QDateTime") {
                    /* was removed with issue 80
                    // timea may have a leading Z (issue 28)
                    classFileOut << "                // date encoding should end on a Z, but some suppliers may exclude it\n";
                    classFileOut << "                // we can be robust by checking for it\n";
                    classFileOut << "                if (value.right(1) != \"Z\") { // new time encoding\n";
                    classFileOut << "                     value.append(\"Z\");\n";
                    classFileOut << "                }\n";
                    */
                    classFileOut << "        if ( !set" << attr->name() << "( ";
                    classFileOut << dateFromString( "attr.value( \"" + attr->name() + "\" ).toString()" );
                    classFileOut << ") )\n";
                }
                else if (type == "float") {
                    classFileOut << "        if ( !set" << attr->name() << "( attr.value( \"" << attr->name()
                                 << "\" ).toString().replace(\",\", \".\").toFloat() ) )\n";
                } else  {
                    classFileOut << "        if ( !set" << attr->name() << "( attr.value( \"" << attr->name()
                                 << "\" ) ) )\n";
                }
                classFileOut << "            xml.validationError( \"error set " << attr->name() << " = \" + attr.value( \""
                             << attr->name() << "\" ).toString() );\n";
                classFileOut << "    }\n";
            }
        }

        classFileOut << "    bool stop(false);\n";
        classFileOut << "    while(!xml.atEnd() && !stop)\n    {\n";
        classFileOut << "        QXmlStreamReader::TokenType token = xml.readNext();\n";
        classFileOut << "        switch ( token )\n        {\n";
        classFileOut << "        case QXmlStreamReader::EndElement:\n";
        classFileOut << "            if (  xml.name() == QStringLiteral(\""<< name <<"\") )\n";
        classFileOut << "                stop = true;\n";
        classFileOut << "            break;\n";

        bool element(false);
        for(int j=0; j < attributes.size(); j++) {

            XSDAttribute *attr = attributes.at(j);
            if ( attr->isElement() ) {

                if ( !element )
                {
                    classFileOut << "        case QXmlStreamReader::StartElement:\n";
                    classFileOut << "            if ( xml.name() == QStringLiteral(\"" << attr->name() <<"\") )\n";
                    element = true;
                }
                else
                {
                    classFileOut << "            else if ( xml.name() == QStringLiteral(\"" << attr->name() <<"\") )\n";
                }
                classFileOut << "            {\n";
                if ( attr->isSimpleElement() )
                {
                    classFileOut << "                " << localType(attr->type()) <<" val = xml.readElementText();\n";
                }
                else
                {
                    classFileOut << "                " << attr->name() << " val( xml );\n";
                }
                classFileOut << "                if ( xml.name() != QStringLiteral(\"" << attr->name() << "\") )\n";
                classFileOut << "                    xml.raiseError( \"tag mismatch " << attr->name() << "\" );\n";
                if ( attr->isScalar() )
                {
                    classFileOut << "                else if ( !add" << attr->name() << "( val ) )\n";
                    classFileOut << "                    xml.validationError( \"error add " << attr->name() <<"\"  );\n";
                }
                else
                {
                    classFileOut << "                else if ( !set" << attr->name() << "( val ) )\n";
                    classFileOut << "                    xml.validationError( \"error set " << attr->name() <<"\"  );\n";
                }
                classFileOut << "            }\n";
            }
        }
        if ( element )
        {
            classFileOut << "            else\n            {\n";
            classFileOut << "                xml.validationError( \"unexpected element \" + xml.name().toString() );\n";
            classFileOut << "            }\n";
            classFileOut << "            break;\n";
        }
        classFileOut << "        default:\n";
        //classFileOut << "            xml.validationError( \"unexpected element in " << name << "\" );\n";
        classFileOut << "            break;\n";
        classFileOut << "        }\n";
        classFileOut << "    }\n}\n\n";

        // copy constructor
        classFileOut << "// copy constructor\n";
        classFileOut << className(name) << "::" << className(name) << "(const " << className(name) << " &val)";
        classFileOut << "\n :  QObject()";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attrType); // convert to cpp types
            if (attr->isScalar()) { // there more then one
                classFileOut << ",\n    " << variableName(attr->name()) << "s( val." << variableName(attr->name()) << "s )";
            } else {
                classFileOut << ",\n    " << variableName(attr->name()) << "( val." << variableName(attr->name()) << " )";
                //if (!attr->required() || obj->isMerged()) { //issue 21
                classFileOut << ",\n    " << variableName(attr->name()) << "Present( val." << variableName(attr->name()) << "Present )";
                //}
            }
        }
        classFileOut << ",\n    m_lastError()";
        classFileOut << ",\n    m_changed(val.m_changed )";
        classFileOut << ",\n    m_store(val.m_store )";

        classFileOut << "\n{\n}\n\n";

        // == operator
        classFileOut << "// compare\n";
        classFileOut << "bool " << className(name) << "::operator==(const " << className(name) << " &";
        if (attributes.empty()) { // val is unused variable
            classFileOut << "/*val*/) const {\n\n";
        } else {
            classFileOut << "val) const {\n\n";
        }
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            if (attr->isScalar()) { // there more then one
                classFileOut << "    if (!(" << variableName(attr->name()) << "s == val." << variableName(attr->name()) << "s)) return false;\n";
            } else {
                classFileOut << "    if (!(" << variableName(attr->name()) << "Present == val." << variableName(attr->name()) << "Present)) return false;\n";
                classFileOut << "    if (!(" << variableName(attr->name()) << " == val." << variableName(attr->name()) << ")) return false;\n";
            }
        }
        classFileOut << "    return true;\n";
        classFileOut << "}\n\n";

        // = operator
        classFileOut << "// assignement\n";
        classFileOut << className(name) << " & " << className(name) << "::operator=(const " << className(name) << " &val) {\n\n";
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            if (attr->isScalar()) { // there more then one
                classFileOut << "    " << variableName(attr->name()) << "s = val." << variableName(attr->name()) << "s;\n";
            } else {
                //if (!attr->required() || obj->isMerged()) { // issue 21
                classFileOut << "    " << variableName(attr->name()) << "Present = val." << variableName(attr->name()) << "Present;\n";
                //}
                classFileOut << "    " << variableName(attr->name()) << " = val." << variableName(attr->name()) << ";\n";
            }
        }
        classFileOut << "    m_changed = val.m_changed;\n";
        classFileOut << "    m_store = val.m_store;\n";
        classFileOut << "    return *this;\n";
        classFileOut << "}\n\n";

        // methods for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types
            if (attr->isScalar()) { // there more then one
                // deleter issue 70
                classFileOut << "// remover for " << className(name) << "\n";
                if ( attr->isElement() )
                    classFileOut << "bool " << className(name) << "::remove" << methodName(attr->name()) << "(const " << type << "& val) {\n\n";
                else
                    classFileOut << "bool " << className(name) << "::remove" << methodName(attr->name()) << "(" << type << " val) {\n\n";

                if (attr->hasMinOccurs()) {
                    classFileOut << "    if ("<< variableName(attr->name()) << "s.count() <= " << attr->minOccurs() << ") {\n";
                    classFileOut << "        return false; // scalar already at minOccurs\n";
                    classFileOut << "    }\n";
                }
                classFileOut << "    m_changed = true;\n";
                classFileOut << "    return "<< variableName(attr->name()) << "s.removeOne(val);\n";
                classFileOut << "}\n\n";

                // setter
                classFileOut << "// setter for " << className(name) << "\n";
                if ( attr->isElement() )
                    classFileOut << "bool " << className(name) << "::add" << methodName(attr->name()) << "(const " << type << "& val) {\n\n";
                else
                    classFileOut << "bool " << className(name) << "::add" << methodName(attr->name()) << "(" << type << " val) {\n\n";

                if (attr->hasMaxOccurs()) { // issue 26
                    classFileOut << "    if ("<< variableName(attr->name()) << "s.count() >= " << attr->maxOccurs() << ") {\n";
                    classFileOut << "        return false; // scalar already at maxOccurs\n";
                    classFileOut << "    }\n";
                }
                if (attr->hasMinLength()) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "    if (" << evaluator << " < " << attr->minLength() << ") {\n        return false; // value is too small\n";
                    classFileOut << "    }\n";
                }
                if (attr->hasMaxLength()) {
                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "    if (" << evaluator << " > " << attr->maxLength() << ") {\n        return false; // value is too long\n";
                    classFileOut << "    }\n";
                }

                classFileOut << "    " << variableName(attr->name()) << "s.append(val);\n";
                classFileOut << "    m_changed = true;\n";
                classFileOut << "    return true;\n";
                classFileOut << "}\n\n";

                // getter
                classFileOut << "// getter for " << className(name) << "\n";
                if ( attr->isElement() )
                    classFileOut << "const " << type << "& " << className(name) << "::get" << methodName(attr->name()) << "At(int i) const {\n";
                else
                    classFileOut << type << " " << className(name) << "::get" << methodName(attr->name()) << "At(int i) const {\n";
                classFileOut << "\n    return " << variableName(attr->name()) << "s.at(i);\n}\n\n";
                // count
                classFileOut << "// count for " << className(name) << "\n";
                classFileOut << "int " << className(name) << "::countOf" << methodName(attr->name()) << "s() const {\n";
                classFileOut << "\n    return " << variableName(attr->name()) << "s.count();\n}\n\n";
            } else {
                // setter
                classFileOut << "// setter for " << className(name) << "\n";
                if ( attr->isElement() )
                    classFileOut << "bool " << className(name) << "::set" << methodName(attr->name()) << "(const " << type << "& val) {\n";
                else
                    classFileOut << "bool " << className(name) << "::set" << methodName(attr->name()) << "(" << type << " val) {\n";
                QVector<QString> enums = attr->enumeration();
                if (enums.size() > 0) { // there are enumeration constraints for this item

                    // strings should be between quotes, numbers not
                    QString quote;
                    if (type == "QString") {
                        quote = "\"";
                    }

                    classFileOut << "\n    // check if the new value is an approved value";
                    classFileOut << "\n    if ( ( val != " << quote << enums.at(0) << quote <<" ) ";
                    for (int h=1; h < enums.size(); h++) {
                        classFileOut << "&&\n         ( val != " << quote << enums.at(h) << quote << " ) ";
                    }
                    classFileOut <<    ")\n        return false;";
                }
                /////////////issue 72 start
                // check for strings too! you never have a min and a minLength!
                if (attr->hasMinLength() && knownType(attr->type())) {

                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "\n    // check if the new value is within min length";
                    classFileOut << "\n    if (" << evaluator << " < " << attr->minLength() << ")\n        return false;";
                }
                // check for strings too!
                if (attr->hasMaxLength() && knownType(attr->type())) {

                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "\n    // check if the new value is within max length";
                    classFileOut << "\n    if (" << evaluator << " > " << attr->maxLength() << ")\n        return false;";
                }
                /////////////issue 72 end
                if (attr->hasMinExclusive() && knownType(attr->type())) {

                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "\n    // check if the new value is within min exclusive";
                    classFileOut << "\n    if (" << evaluator << " <= " << attr->minExclusive() << ")\n        return false;";
                }
                if (attr->hasMaxExclusive() && knownType(attr->type())) {

                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "\n    // check if the new value is within max exclusive";
                    classFileOut << "\n    if (" << evaluator << " >= " << attr->maxExclusive() << ")\n        return false;";
                }
                if (attr->hasMinInclusive() && knownType(attr->type())) {

                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "\n    // check if the new value is within min inclusive";
                    classFileOut << "\n    if (" << evaluator << " < " << attr->minInclusive() << ")\n        return false;";
                }
                if (attr->hasMaxInclusive() && knownType(attr->type())) {

                    QString evaluator = sizeEvaluatorForType(attr->type(), "val");

                    classFileOut << "\n    // check if the new value is within max inclusive";
                    classFileOut << "\n    if (" << evaluator << " > " << attr->maxInclusive() << ")\n        return false;";
                }
                //if (!attr->required() || obj->isMerged()) { // issue 21
                classFileOut << "\n    " << variableName(attr->name()) << "Present = true;";
                //}
                classFileOut << "\n    " << variableName(attr->name()) << " = val;\n";
                classFileOut << "    m_changed = true;\n";
                classFileOut << "    return true;\n";
                classFileOut << "}\n\n";

                // getter
                classFileOut << "// getter for " << className(name) << "\n";
                if ( attr->isElement() )
                    classFileOut << "const " << type << "& " << className(name) << "::get" << methodName(attr->name()) << "() const {\n";
                else
                    classFileOut << type << " " << className(name) << "::get" << methodName(attr->name()) << "() const {\n";
                classFileOut << "\n    return " << variableName(attr->name()) << ";\n}\n\n";

                if (!attr->required() || obj->isMerged()) { // issue 21 present only optional attributes on the interface
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
        classFileOut << "const QString& " << className(name) << "::toXML(bool outputNamespace) {\n\n";
        classFileOut << "    if ( m_changed ) {\n";
        classFileOut << "        const static QString endAttr( \"\\\"\" );\n";
        classFileOut << "        QString xml = \"<" << name << "\";\n"; // append attributes

        classFileOut << "        if (outputNamespace)\n";
        classFileOut << "        {\n";

        classFileOut << "            xml.append(\" xmlns:xsi=\\\"http://www.w3.org/2001/XMLSchema-instance\\\"\");\n";
        classFileOut << "            xml.append(\" xmlns=\\\"" << nameSpace << "\\\"\");\n";
        classFileOut << "        }\n";

        classFileOut << "        QString dataMember;\n"; // append attributes

        // for attributes
        bool hasDataMembers = false;
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            // QString attrType = attr->type();
           /*
            if ((attrType != attr->name()) && attr->isElement()) {
                std::cout << "ERROR: item assumed to be attribute but is element: " << attr->name().toLatin1().data() << std::endl;
            }

            if ((attrType != attr->name()) && attr->isElement()) {
                std::cout << "ERROR unknown attr :" <<  attr->name().toLatin1().data() <<  " mistaken for attribute" << std::endl;
            }
            */
            if (!attr->isElement()) {

                // non-qstring items (ints) may give problems, so convert them
                QString varName = localTypeToString(attr, variableName(attr->name()), attr->enumeration().empty() && !attr->isFixed() );

                // check if the attribute exist
                if (!attr->required() || obj->isMerged()) { // issue 21
                    classFileOut << "            // check for presence of optional attribute\n";
                    classFileOut << "            if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "                xml.append(\" " << attr->name() << "=\\\"\" + " << varName << " + endAttr);\n        }\n";
                } else {
                    classFileOut << "            // check for presence of required  attribute\n";
                    classFileOut << "        if ( " << variableName(attr->name()) << "Present) {\n";
                    classFileOut << "            xml.append(\" " << attr->name() << "=\\\"\" + " << varName << " + endAttr);\n";
                    classFileOut << "        } else { // required attribute not present\n";
                    classFileOut << "            m_lastError = \"" << attr->name() << " not set\";\n";
                    classFileOut << "            m_store  = QString();\n";
                    classFileOut << "            return m_store;\n";
                    classFileOut << "        }\n";
                }
            } else {
                hasDataMembers = true;
            }
        }

        // check for data members
        if (hasDataMembers) {
            classFileOut << "        xml.append(\">\\n\");\n"; // close the statement

            // for data members
            for(int j=0; j < attributes.size(); j++) {
                XSDAttribute *attr = attributes.at(j);
                QString attrType = localType (attr->type());

                if ((attrType != attr->name()) && attr->isElement()) {
                    std::cout << "ERROR: item assumed to be attribute but is element: " << attr->name().toLatin1().data() << std::endl;
                }

                if (attr->isElement()) {
                    // check if the attribute exist
                    if (attr->isScalar() ) {
                        if (attr->hasMinOccurs()) { // issue 26
                            classFileOut << "        if (" << variableName(attr->name()) << "s.count() < " << attr->minOccurs() << ") {\n";
                            classFileOut << "            m_lastError = \"not enough " << attr->name() << " values\";\n";
                            classFileOut << "            m_store  = QString();\n";
                            classFileOut << "            return m_store;\n";
                            classFileOut << "        }\n";
                        }
                        if (attr->hasMaxOccurs()) { // issue 26
                            classFileOut << "        if (" << variableName(attr->name()) << "s.count() > " << attr->maxOccurs() << ") {\n";
                            classFileOut << "            m_lastError = \"too much " << attr->name() << " values\";\n";
                            classFileOut << "            m_store  = QString();\n";
                            classFileOut << "            return m_store;\n";
                            classFileOut << "        }\n";
                        }
                        classFileOut << "        // add all included data\n";
                        classFileOut << "        for(int i=0; i < " << variableName(attr->name()) << "s.count(); i++ ) {\n";
                        classFileOut << "            " << attrType << " attribute = " << variableName(attr->name()) << "s.at(i);\n";

                        if (attr->isSimpleElement()) {
                            // non-qstring items (ints) may give problems, so convert them
                            QString varName = localTypeToString(attr, "attribute", attr->enumeration().empty() && !attr->isFixed());
                            classFileOut << "            xml.append( \"<" << attr->name() << ">\" + " << varName << " +  \"</" << attr->name() << ">\" );\n";
                        } else {
                            classFileOut << "            dataMember = attribute.toXML(false);\n";
                            classFileOut << "            if (dataMember != QString()) {\n";
                            classFileOut << "               xml.append( dataMember );\n";
                            classFileOut << "            } else {\n";
                            classFileOut << "                m_lastError = \"" << attr->name() << ":\" + attribute.lastError();\n";
                            classFileOut << "                m_store  = QString();\n";
                            classFileOut << "                return m_store;\n";
                            classFileOut << "            }\n";
                        }
                        classFileOut << "        }\n";
                    } else if (!attr->required() || obj->isMerged()) {
                        classFileOut << "        // add optional data if available\n";
                        classFileOut << "        if ( has" << methodName(attr->name()) << "() ) {\n";
                        if (attr->isSimpleElement()) {
                            classFileOut << "            xml.append( \"<" << attr->name() << ">\" );\n";
                            classFileOut << "            xml.append( " << variableName(attr->name()) << " );\n";
                            classFileOut << "            xml.append( \"</" << attr->name() << ">\\n\" );\n";
                        } else {
                            classFileOut << "            dataMember = " << variableName(attr->name()) << ".toXML(false);\n";
                            classFileOut << "            if (dataMember != QString()) {\n";
                            classFileOut << "                xml.append( dataMember );\n";
                            classFileOut << "            } else {\n";
                            classFileOut << "                m_lastError = \"" << attr->name() << ":\" + " << variableName(attr->name()) << ".lastError();\n";
                            classFileOut << "                m_store  = QString();\n";
                            classFileOut << "                return m_store;\n";
                            classFileOut << "            }\n";
                        }
                        classFileOut << "        }\n";
                    } else {
                        classFileOut << "        // check for presence of required data member\n";
                        classFileOut << "        if ( " << variableName(attr->name()) << "Present) {\n";
                        classFileOut << "            dataMember = " << variableName(attr->name()) << ".toXML(false);\n";
                        classFileOut << "            if (dataMember != QString()) {\n";
                        classFileOut << "                xml.append( dataMember );\n";
                        classFileOut << "            } else {\n";
                        classFileOut << "                m_lastError = \"" << attr->name() << ":\" + " << variableName(attr->name()) << ".lastError();\n";
                        classFileOut << "                m_store  = QString();\n";
                        classFileOut << "                return m_store;\n";
                        classFileOut << "            }\n";
                        classFileOut << "        } else {\n";
                        classFileOut << "            m_lastError = \"" << attr->name() << " not set\";\n";
                        classFileOut << "            m_store  = QString();\n";
                        classFileOut << "            return m_store;\n";
                        classFileOut << "        }\n";
                    }
                }
            }
            classFileOut << "        xml.append( \"</" << name << ">\\n\");\n"; // append attributes
        }
        else {
            classFileOut << "        xml.append(\"/>\\n\");\n"; // close the statement
        }

        // close up
        classFileOut << "        m_store = xml;\n";
        classFileOut << "        m_changed = false;\n    }\n";
        classFileOut << "    return m_store;\n";
        classFileOut << "}\n\n";

        // string generator
        // if attribute name and type are the same it means it was data
        classFileOut << "// Get String Representation\n";
        classFileOut << "QString " << className(name) << "::toString() const{\n\n";
        classFileOut << "    return toString(\"\");\n";
        classFileOut << "}\n\n";

        classFileOut << "// Get String Representation with a lead\n";
        classFileOut << "QString " << className(name) << "::toString(QString lead) const{\n\n";
        classFileOut << "    const static QString endAttr( \"\\n\" );\n";
        classFileOut << "    QString str = lead + \"" << name << "\\n\";\n"; // append attributes

        // for attributes
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = attr->type();
            QString type = localType(attr->type()); // convert to cpp types

            if ((attrType != attr->name()) && attr->isElement()) {
                std::cout << "ERROR: item assumed to be attribute but is element: " << attr->name().toLatin1().data() << std::endl;
            }

            if (!attr->isElement()) {

                // non-qstring items (ints) may give problems, so convert them
                QString varName = localTypeToString(attr, variableName(attr->name()), false);
                // check if the attribute exist
                if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    // check for presence of optional attribute\n";
                    classFileOut << "    if ( has" << methodName(attr->name()) << "() ) {\n";
                    classFileOut << "        str.append( lead + \"    " << attr->name() << " = \" + " << varName << " + endAttr);\n    }\n";
                } else {
                    classFileOut <<     "    str.append( lead + \"    " << attr->name() << " = \" + " << varName << " + endAttr);\n";
                }
            }
        }

        // for data members
        for(int j=0; j < attributes.size(); j++) {
            XSDAttribute *attr = attributes.at(j);
            QString attrType = localType (attr->type());

            if ((attrType != attr->name()) && attr->isElement()) {
                std::cout << "ERROR: item assumed to be attribute but is element: " << attr->name().toLatin1().data() << std::endl;
            }

            if (attr->isElement()) {
                // check if the attribute exist
                if (attr->isScalar() ) {
                    classFileOut << "    // add all included data\n";
                    classFileOut << "    for(int i=0; i < " << variableName(attr->name()) << "s.count(); i++ ) {\n";
                    classFileOut << "        " << attrType << " attribute = " << variableName(attr->name()) << "s.at(i);\n";

                    if (attr->isSimpleElement()) {
                        // non-qstring items (ints) may give problems, so convert them
                        QString varName = localTypeToString(attr, "attribute", false);
                        classFileOut << "        str.append( lead + \"    \" + " << varName << " );\n";
                    } else {
                        classFileOut << "        str.append( attribute.toString( lead + \"    \" ) );\n";
                    }

                    classFileOut << "    }\n";
                } else if (!attr->required() || obj->isMerged()) {
                    classFileOut << "    // add all optional data if present\n";
                    classFileOut << "    if ( has" << methodName(attr->name()) << "() ) {\n";
                    if (attr->isSimpleElement()) {
                        classFileOut << "        str.append( lead + \" \" );\n";
                        classFileOut << "        str.append( \"" << attr->name() << " = \" );\n";
                        classFileOut << "        str.append( " << variableName(attr->name()) << " );\n";
                        classFileOut << "        str.append( \"\\n\" );\n";
                    } else {
                        classFileOut << "        str.append(" << " " << variableName(attr->name()) << ".toString(lead + \"    \") );\n";
                    }
                    classFileOut << "    }\n";
                } else {
                    classFileOut <<     "    str.append(" << " " << variableName(attr->name()) << ".toString(lead + \"    \") );\n";
                }
            }
        }

        // close up
        classFileOut << "    return str;\n";
        classFileOut << "}\n\n";

        classFileOut << "const QString& " << className(name) <<"::lastError() const {\n";
        classFileOut << "    return m_lastError;\n}\n\n";

        classFileOut << "const bool& " << className(name) <<"::changed() const {\n";
        classFileOut << "    return m_changed;\n}\n\n";

        classFileOut << "const QString& " << className(name) <<"::store() const {\n";
        classFileOut << "    return m_store;\n}\n\n";

        // round up
        if ( m_namespace ) {
            classFileOut << "\n} //end ns";
        }
        classFileOut << "\n";

        // close and flush
        classFileOut.flush();
        classFile.close();
    }
}

void CodeGenQT::parserFile() {

    //-----------------------------------------------------------------------------------------------
    // now generate the parser
    //-----------------------------------------------------------------------------------------------

    // open the header file
    QString name = "Parser";

    QFile headerFile(m_outDir + "/include/" + fileBaseName(name) + ".h");
    if (!headerFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(headerFile.fileName()).toLatin1().data() << std::endl;
        std::exit(3);
    }
    QTextStream headerFileOut(&headerFile);

    // and the parser file
    QFile classFile(m_outDir + "/src/" +  fileBaseName(name) + ".cpp");
    if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(classFile.fileName()).toLatin1().data() << std::endl;
        std::exit(3);
    }
    QTextStream classFileOut(&classFile);

    // generate the header
    headerFileOut << writeHeader( className(name) );
    headerFileOut << "#ifndef __" << name.toUpper() << "_H__\n";
    headerFileOut << "#define __" << name.toUpper() << "_H__\n\n";

    // include dependend files
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ( !obj->isEmbedded() && (obj->name() != "Schema") && !obj->isSimpleElement()) {
            headerFileOut << "#include \"" << fileBaseName(obj->name()) << ".h\"\n";
        }
    }
    headerFileOut << "#ifndef SCHEMA" << m_prefix.toUpper() << "_EXPORT\n";
    headerFileOut << "# ifdef SCHEMA" << m_prefix.toUpper() << "_BUILD_STATIC\n";
    headerFileOut << "#  define SCHEMA" << m_prefix.toUpper() << "_EXPORT\n";
    headerFileOut << "# else\n";
    headerFileOut << "#  ifdef SCHEMA" << m_prefix.toUpper() << "_BUILD\n";
    headerFileOut << "#   define SCHEMA" << m_prefix.toUpper() << "_EXPORT Q_DECL_EXPORT\n";
    headerFileOut << "#  else\n";
    headerFileOut << "#   define SCHEMA" << m_prefix.toUpper() << "_EXPORT Q_DECL_IMPORT\n";
    headerFileOut << "#  endif\n";
    headerFileOut << "# endif\n";
    headerFileOut << "#endif\n";
    headerFileOut << "class XmlStreamReader;\n";

    if ( m_namespace ) {
        headerFileOut << "\nnamespace " << nameSpaceName() << " {\n";
    }
    headerFileOut << "\n//-----------------------------------------------------------\n";
    headerFileOut << "//! \\brief       Class definition of " << className(name) << "\n";
    headerFileOut << "//!\n";

    // define the class
    headerFileOut << "class SCHEMA" << m_prefix.toUpper() << "_EXPORT " << className(name) << " : public QObject {\n";
    headerFileOut << "    Q_OBJECT\n\n";

    // public section
    headerFileOut << "public:\n";
    headerFileOut << "    //!constructor\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    " << className(name) << "();\n";
    headerFileOut << "    //!the actual parse routine\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    bool parseXMLString(QString data, bool cont);\n";

    // define the signals
    headerFileOut << "\nsignals:\n";
    headerFileOut << "    //!signals fired by the parser when a new object has been parsed\n";
    headerFileOut << "    //!\n";
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ( !obj->isEmbedded() && (obj->name() != "Schema") && !obj->isSimpleElement() ) {
            headerFileOut << "    void signal" << className(obj->name()) << "( const ";
            if ( m_namespace ) {
                headerFileOut << "" << nameSpaceName() << "::";
            }
            headerFileOut << className(obj->name()) << "& obj );\n";
        }
    }
    // issue 24
    headerFileOut << "    //!signals fired by the parser when a parser problem occured\n";
    headerFileOut << "    //!\n";
    headerFileOut << "    void signalError(const QString& errorStr);\n";
    headerFileOut << "    void signalWarning(const QString& errorStr);\n";

    // issue 69
    headerFileOut << "    void signalValidationError(const QString& errorStr);\n";

    // private section
    headerFileOut << "\nprivate:\n";
    headerFileOut << "    void parse();\n";
    headerFileOut << "    XmlStreamReader* m_xml;\n";

    // close the header
    headerFileOut << "\n};\n";
    if ( m_namespace ) {
        headerFileOut << "} //end ns\n";
    }

    headerFileOut << "\n#endif\n";

    // close and flush
    headerFileOut.flush();
    headerFile.close();

    // The class file
    classFileOut << "#include <QRegExp>\n";
    classFileOut << "\n#include \"" << fileBaseName("Functions") << ".h\"\n\n";
    classFileOut << "\n#include \"" << fileBaseName(name) << ".h\"\n\n";

    if ( m_namespace ) {
        classFileOut << "namespace " << nameSpaceName() << " {\n\n";
    }
    // constructor
    classFileOut << "// Constructor\n";
    classFileOut << className(name) << "::" << className(name) << "() {\n\n";
    classFileOut << "    m_xml = new XmlStreamReader;\n";
    classFileOut << "    connect( m_xml, SIGNAL(signalValidationError(const QString&)),\n";
    classFileOut << "             this,  SIGNAL(signalValidationError(const QString&)) );\n";
    classFileOut << "}\n\n";

    // the parseXMLString routine
    classFileOut << "// the actual parsing routine\n";
    classFileOut << "bool " << className(name) << "::parseXMLString(QString data, bool cont) {\n\n";
    classFileOut << "     // add the data to what was left over from a previous parse run\n";

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
    classFileOut << "    // search the buffer for the nearest closetag\n";
    classFileOut << "    int index = 0;\n";
    classFileOut << "    QRegExp rx( \"" + regExp + "\");\n";

    classFileOut << "    m_xml->addData( data );\n";
    classFileOut << "    if ( (index = rx.indexIn( data )) != -1 )\n";
    classFileOut << "    {\n";
    classFileOut << "        // end found in last part\n";
    classFileOut << "        QString residu( data );\n";
    classFileOut << "        do\n        {\n";
    classFileOut << "            parse();\n";
    classFileOut << "            m_xml->clear();\n\n";
    classFileOut << "            // add make residu\n";
    classFileOut << "            int len = index + rx.matchedLength();\n";
    classFileOut << "            residu = residu.right( residu.length() - len );\n";
    classFileOut << "            m_xml->addData( residu );\n\n";
    classFileOut << "            // loop until no end found in residu\n";
    classFileOut << "        } while ( (index = rx.indexIn( residu )) != -1 );\n";
    classFileOut << "    }\n\n";
    classFileOut << "    if (!cont) {\n";
    classFileOut << "        m_xml->clear();\n";
    classFileOut << "    }\n";

    classFileOut << "    return true;\n";
    classFileOut << "}\n\n"; // close method

    classFileOut << "QString composeMessage( const QXmlStreamReader& xml ) {\n";
    classFileOut << "    QString errorstr( xml.errorString() );\n";
    classFileOut << "    errorstr += \" at line \" + QString::number(xml.lineNumber());\n";
    classFileOut << "    errorstr += \" (column \" + QString::number(xml.columnNumber());\n";
    classFileOut << "    errorstr += \")\";\n";
    classFileOut << "    return errorstr;\n";
    classFileOut << "}\n\n";

    // main parser routine
    classFileOut << "void Parser::parse() {\n\n";

    classFileOut << "    bool stop( false );\n";
    classFileOut << "    while(!m_xml->atEnd() && !stop)\n";
    classFileOut << "    {\n";
    classFileOut << "        QXmlStreamReader::TokenType token = m_xml->readNext();\n";
    classFileOut << "        if ( token == QXmlStreamReader::StartElement )\n        {\n";

    bool element( false );
    for(int i=0; i < m_objects.size(); i++) {
        XSDObject *obj = m_objects.at(i);
        if ( !obj->isEmbedded() && (obj->name() != "Schema") && !obj->isSimpleElement()) {
            if ( !element )
            {
                classFileOut << "            if( m_xml->name()==QStringLiteral(\"" << className(obj->name()) << "\") )\n";
                element = true;
            }
            else
                classFileOut << "            else if( m_xml->name()==QStringLiteral(\"" << className(obj->name()) << "\") )\n";

            classFileOut << "            {\n";
            classFileOut << "                " << className(obj->name()) << " obj( *m_xml );\n";
            classFileOut << "                if ( m_xml->name() != QStringLiteral(\"" << className(obj->name()) << "\") )\n";
            classFileOut << "                    m_xml->raiseError( \"tag mismatch " << className(obj->name()) << "\" );\n";
            classFileOut << "                else\n";
            classFileOut << "                {\n";
            classFileOut << "                    emit signal" << className(obj->name()) << "( obj );\n";
            classFileOut << "                    stop = true;\n";
            classFileOut << "                }\n";
            classFileOut << "            }\n";
        }
    }
    classFileOut << "        }\n    }\n\n";
    classFileOut << "    if ( m_xml->hasError() )\n";
    classFileOut << "    {\n";
    classFileOut << "        switch ( m_xml->error() )\n";
    classFileOut << "        {\n";
    classFileOut << "        case QXmlStreamReader::CustomError:\n";
    classFileOut << "            emit( signalValidationError( composeMessage( *m_xml ) ) );\n";
    classFileOut << "            break;\n";
    classFileOut << "        case QXmlStreamReader::PrematureEndOfDocumentError:\n";
    classFileOut << "            emit( signalWarning( composeMessage( *m_xml ) ) );\n";
    classFileOut << "            break;\n";
    classFileOut << "        case QXmlStreamReader::NotWellFormedError:\n";
    classFileOut << "        case QXmlStreamReader::UnexpectedElementError:\n";
    classFileOut << "            emit( signalError( composeMessage( *m_xml ) ) );\n";
    classFileOut << "            break;\n";
    classFileOut << "        case QXmlStreamReader::NoError:\n";
    classFileOut << "            break;\n";
    classFileOut << "        }\n    }\n}\n\n";

    if ( !element ) {
        std::cout << "ERROR: No base element found" << std::endl;
    }
    // round up
    if ( m_namespace ) {
        classFileOut << "} //end ns\n";
    }

    // close and flush
    classFileOut.flush();
    classFile.close();
}

void CodeGenQT::functionsFile()
{
    // open the header file
    QString name = "Functions";

    QFile headerFile(m_outDir + "/include/" + fileBaseName(name) + ".h");
    if (!headerFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(headerFile.fileName()).toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream headerFileOut(&headerFile);

    // and the source file
    QFile classFile(m_outDir + "/src/" +  fileBaseName(name) + ".cpp");
    if (!classFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << QString("cannot create file: %1").arg(classFile.fileName()).toLatin1().data() << std::endl;
        std::exit(-1);
    }
    QTextStream classFileOut(&classFile);

    headerFileOut << writeHeader( className(name) );
    headerFileOut << "#ifndef __" << name.toUpper() << "_H__\n";
    headerFileOut << "#define __" << name.toUpper() << "_H__\n\n";

    headerFileOut << "#include <QObject>\n";
    headerFileOut << "#include <QXmlStreamReader>\n";
    headerFileOut << "#include <QString>\n";
    headerFileOut << "#include <QDateTime>\n\n";
    if ( m_namespace ) {
        headerFileOut << "namespace " << nameSpaceName() << " {\n\n";
    }
    headerFileOut << "//! replace characters that are illigal in XML with their encodings\n";
    headerFileOut << "//!\n";
    headerFileOut << "//! \\return     QString\n";
    headerFileOut << "QString encode(const QString& str);\n\n"; // issue 19

    headerFileOut << "//! convert date time to string (faster than the QDateTime::toString)\n";
    headerFileOut << "//!\n";
    headerFileOut << "//! \\return     QString\n";
    headerFileOut << "QString dateToString( const QDateTime& dateTime );\n\n";

    headerFileOut << "//-----------------------------------------------------------\n";
    headerFileOut << "//! \\brief      Overload QXmlStreamReader to create a validation\n";
    headerFileOut << "//!             error and continue parsing (what raiseError does)\n";
    headerFileOut << "//!\n";
    headerFileOut << "class XmlStreamReader: public QObject,\n";
    headerFileOut << "                       public QXmlStreamReader\n{\n";
    headerFileOut << "Q_OBJECT\n\n";
    headerFileOut << "public:\n";
    headerFileOut << "    XmlStreamReader() : QXmlStreamReader() {}\n";
    headerFileOut << "    virtual ~XmlStreamReader() {}\n\n";
    headerFileOut << "    void validationError(const QString& errorStr);\n\n";
    headerFileOut << "signals:\n";
    headerFileOut << "    void signalValidationError(const QString& errorStr);\n";
    headerFileOut << "};\n";
    if ( m_namespace ) {
        headerFileOut << "} //end ns\n";
    }
    headerFileOut << "\n#endif\n";

    classFileOut << "#include \"" << fileBaseName(name) << ".h\"\n\n";
    if ( m_namespace ) {
        classFileOut << "namespace " << nameSpaceName() << " {\n\n";
    }
    classFileOut << "QString encode( const QString& str ) {\n\n";
    classFileOut << "    QString result( str );\n";
    classFileOut << "    const static QString  amp(\"&amp;\");\n";
    classFileOut << "    const static QString   lt(\"&lt;\");\n";
    classFileOut << "    const static QString   gt(\"&gt;\");\n";
    classFileOut << "    const static QString quot(\"&quot;\");\n";
    classFileOut << "    result.replace('&',  amp);\n";
    classFileOut << "    result.replace('<',  lt);\n";
    classFileOut << "    result.replace('>',  gt);\n";
    classFileOut << "    result.replace('\"', quot);\n";
    classFileOut << "    return result;\n";
    classFileOut << "}\n\n";

    classFileOut << "inline QString nrToString( int nr, int width ) {\n\n";
    classFileOut << "    if ( width == 2 && nr < 10 )\n";
    classFileOut << "        return QString::number( nr ).rightJustified( 2, '0' );\n";
    classFileOut << "    else if ( width == 3 && nr < 100 )\n";
    classFileOut << "        return QString::number( nr ).rightJustified( 3, '0' );\n";
    classFileOut << "    else\n";
    classFileOut << "        return QString::number( nr );\n";
    classFileOut << "}\n\n";

    classFileOut << "QString dateToString( const QDateTime& dateTime ) {\n\n";
    classFileOut << "    if ( !dateTime.isValid() ) return QString();\n\n";
    classFileOut << "    // make string yyyy-MM-ddTHH:mm:ss.zzzZ\n";
    classFileOut << "    QDateTime utcDateTime = dateTime.toUTC();\n";
    classFileOut << "    QString result( QString::number( utcDateTime.date().year() ) );\n";
    classFileOut << "    result += '-';\n    result += nrToString( utcDateTime.date().month(), 2 );\n";
    classFileOut << "    result += '-';\n    result += nrToString( utcDateTime.date().day(), 2 );\n";
    classFileOut << "    result += 'T';\n    result += nrToString( utcDateTime.time().hour(), 2 );\n";
    classFileOut << "    result += ':';\n    result += nrToString( utcDateTime.time().minute(), 2 );\n";
    classFileOut << "    result += ':';\n    result += nrToString( utcDateTime.time().second(), 2 );\n";
    classFileOut << "    result += '.';\n    result += nrToString( utcDateTime.time().msec(), 3 );\n";
    classFileOut << "    result += 'Z';\n    return result;\n";
    classFileOut << "}\n\n";

    classFileOut << "void XmlStreamReader::validationError(const QString& errorStr) {\n\n";
    classFileOut << "    QString error( errorStr );\n";
    classFileOut << "    error += \" at line \" + QString::number(lineNumber());\n";
    classFileOut << "    error += \" (column \" + QString::number(columnNumber());\n";
    classFileOut << "    error += \")\";\n";
    classFileOut << "    emit( signalValidationError( error ) );\n";
    classFileOut << "}\n";
    // round up
    if ( m_namespace ) {
        classFileOut << "\n} //end ns";
    }
    classFileOut << "\n";

    // close and flush
    headerFileOut.flush();
    headerFile.close();

    // close and flush
    classFileOut.flush();
    classFile.close();
}
