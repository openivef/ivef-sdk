/*
 *  Handler.cpp
 *
 *  schema2code is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Created by Lukassen on 11/06/08.
 *  Copyright 2008
 *
 */

#include "handler.h"

bool Handler::startDocument () {
    //std::cout << "SD" << std::endl;
    return true;
}

QVector<XSDObject*> Handler::objects() {
    return m_objects;
}


QString Handler::stripNameSpace(QString tag) {

    // note: attributes with fields type, ref, base may contain a
    //       namespace like ssn:type, this must be removed
    int i = tag.indexOf(":");
    if (i > 0) {
        QString ns = tag.left(i);
        if (ns != "xs") { // preserve the default namespace or we have to rewrite all code generators
            QString newTag = tag.right(tag.length() - i -1);
            //std::cout << QString("processing %1 to %2, %3").arg(tag, ns, newTag).toLatin1().data() << std::endl;
            return newTag;
        }
    }
    return tag;
}

void Handler::handleStartOfElement ( QString qName, QXmlAttributes atts, bool isTypeDef) {
    //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;

    XSDObject *parent = 0;

    if (m_objStack.size() > 0) {
        parent = m_objStack.top();
    }
    QString name, max, min;
    XSDObject *obj = new XSDObject("unknown");
    obj->setTypeDefinition(isTypeDef);
    if (m_objStack.size() == 1) { // schema is level 0
        //std::cout << QString("setting root object on %1").arg(qName).toLatin1().data() << std::endl;
        obj->setRootObject();
    }
    m_objStack.push(obj); // mus always push, since we will always pop. if it was a reference we will leak here!
    bool hasMax = false, hasMin = false;
    for (int i=0; i < atts.length(); i++) {
        QString key = atts.localName(i);
        QString value = atts.value(i);
        //std::cout << QString("Attr key %1 val %2").arg(key, value).toLatin1().data() << std::endl;
        if (key == "name") {
            // new object (but name could occur multiple times)
            XSDObject *existingObj = 0;
            for(int i=0; i < m_objects.size(); i++) {
                if (m_objects.at(i)->name() == value) {
                    existingObj = m_objects.at(i); // append attributes to the old object, just as with a ref
                    break;
                }
            }

            if (existingObj == 0) {
                obj->setName(value);
                m_objects.append(obj); // only append new objects, references will be there anyway
            } else {
                // replace stack object with ref to other obj
                // this will result in a merged version of the object
                std::cout << QString("WARNING %1 reused, merging objects").arg(value).toLatin1().data() << std::endl;
                m_objStack.pop();
                m_objStack.push(existingObj);
                existingObj->setMerged();
                existingObj->setTypeDefinition(isTypeDef);  // is this really needed???? we may demote an object
            }
            name = value;
        } else if (key == "maxOccurs") {
            // parent can have maxOccurs objects of this object
            max = value;
            hasMax = true;
        } else if (key == "minOccurs") {
            // parent can have maxOccurs objects of this object
            min = value;
            hasMin = true;

        } else if (key == "ref") {
            // not a new object but an reference to an existing one
            name = stripNameSpace( value );
        } else if (key == "type") {
            // not a new object but an reference to an existing one (as type)
            name = stripNameSpace( value );
        } else {
            std::cerr << QString("unexpected %1, %2 in tag %3").arg(key, value, qName).toLatin1().data() << std::endl;
        }
    }
    XSDAttribute *attr = new XSDAttribute(name, name, true, ""); // keep name and type the same
    attr->setElement(true); // i am sure it is a ellement

    if (hasMax) {
        if (max == "unbounded") {
            attr->setUnbounded();
        } else {
            attr->setMaxOccurs(max.toInt());
        }
    }
    if (hasMin) {
        attr->setMinOccurs(min.toInt());
    }
    if ((min == "0")){  // default is 1
        // && ((!hasMax || max == "1"))) { // default max is 1
        attr->setRequired(false);   // means the attribute is optional
        std::cout << QString("detected optional attribute %1 due to minOccurs").arg(name).toLatin1().data() << std::endl;
    }
    if (parent != 0) {
        parent->addAttribute(attr);
    }
    m_attrStack.push(attr);

}

bool Handler::startElement (const QString & /* namespaceURI */,
                            const QString & /* localName */,
                            const QString & qualifiedName,
                            const QXmlAttributes & atts) {

    // some xsd use the xsd:<token> style
    QString qName = qualifiedName;
    qName.replace(QString("xsd:"), QString("xs:"));

#if 0
    std::cout << QString("SE: %1").arg(qName).toLatin1().data() << std::endl;

    for (int i=0; i < atts.length(); i++) {
        QString key = atts.localName(i);
        QString value = atts.value(i);
        std::cout << QString("AT:    %1 = %2").arg(key, value).toLatin1().data() << std::endl;
    }
#endif

    if (qName == "xs:annotation") {
        // ignore
        // std::cout << QString("ANNOTATION ignoring %1").arg(qName).toLatin1().data() << std::endl;
    } else if (qName == "xs:attribute") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        QString name = "unknown", type = "unknown", fixed = "";
        bool required = false;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);
            if (key == "name") {
                name = value;
            } else if (key == "type") {
                value.replace(QString("xsd:"), QString("xs:"));
                type = stripNameSpace( value );
            } else if (key == "fixed") {
                fixed = value;
            } else if (key == "use") {
                if (value == "required") {
                    required = true;
                } else if (value == "prohibited") {
                    required = false;
                }
            } else {
                std::cerr << QString("unexpected %1, %2 in tag %3").arg(key, value, qName).toLatin1().data() << std::endl;
            }
        }
        XSDAttribute *attr = new XSDAttribute(name, type, required, fixed);
        m_attrStack.push(attr);

        if (m_objStack.size() > 0) { // there can be attributes to the schema
            XSDObject *parent = m_objStack.top();
            parent->addAttribute(attr);
        } else {
            XSDObject *parent = m_objects.first();
            parent->addAttribute(attr);
        }

    } else if ((qName == "xs:simpleType") || (qName == "xs:group") || (qName == "xs:complexType")) {

        XSDObject *parent = m_objStack.top();

        if ((m_objStack.size() == 0) || (parent->isTypeDefinition())) { //  simple types on schema level are other objects used as referal data (or part of a referal)
            std::cout << QString("creating referal type for %1").arg(qName).toLatin1().data() << std::endl;
            QString name = "unknown";
            for (int i=0; i < atts.length(); i++) {
                QString key = atts.localName(i);
                QString value = atts.value(i);
                if (key == "name") {
                    name = value;
                }
            }
            handleStartOfElement(name, atts, true);
        }
    } else if (qName == "xs:complexContent") {
        // ignore, we will check for multiple attributes anyway
        //std::cout << QString("ignoring %1").arg(qName).toLatin1().data() << std::endl;
    } else if (qName == "xs:extension") {
        // this object is an extention of an existing object, lets add the properties of the
        // baseclass to this class as well
        QString base = "unknown";
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);
            if (key == "base") {
                base = stripNameSpace( value );
            }
        }
        std::cout << QString("extending class with base class %1").arg(base).toLatin1().data() << std::endl;

        // get object from stack and add all baseclass attributes also to it
        XSDObject *obj = m_objStack.top();
        obj->setBaseClass(base);

    } else if (qName == "xs:documentation") {
        //std::cout << QString("ignoring %1").arg(qName).toLatin1().data() << std::endl;

    } else if (qName == "xs:element") {

        handleStartOfElement(qName, atts, false);

    } else if (qName == "xs:enumeration") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->appendEnumeration(atts.value(0)); //  has only one attribute "value = xxx"
    } else if (qName == "xs:maxInclusive") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setMaxInclusive(atts.value(0).toDouble());
    } else if (qName == "xs:maxExclusive") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setMaxExclusive(atts.value(0).toDouble());
    } else if (qName == "xs:minInclusive") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setMinInclusive(atts.value(0).toDouble());
    } else if (qName == "xs:minExclusive") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setMinExclusive(atts.value(0).toDouble());
    } else if (qName == "xs:fractionDigits") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setDigits(atts.value(0).toInt());
    } else if (qName == "xs:minLength") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setMinLength(atts.value(0).toInt());
    } else if (qName == "xs:maxLength") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setMaxLength(atts.value(0).toInt());
    } else if (qName == "xs:restriction") {
        // get base class
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        XSDAttribute *attr = m_attrStack.top();
        attr->setType(atts.value(0));
    } else if (qName == "xs:schema") {
        //std::cout << QString("processing %1").arg(qName).toLatin1().data() << std::endl;
        // create a schema object
        // use this as collector object
        XSDObject *obj = new XSDObject("Schema");
        m_objects.append(obj);
        // though all objects are part of the schema it is better to not include them there
        // otherwise we have only one root object.
        //m_objStack.push(obj);
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);
            obj->addKeyWithValue(key, value);
        }
    } else if (qName == "xs:totalDigits") {
        // ignore
        std::cout << QString("ignoring %1").arg(qName).toLatin1().data() << std::endl;
    } else if (qName == "xs:choice") {
        // ignore
        //std::cout << QString("ignoring %1").arg(qName).toLatin1().data() << std::endl;
    } else if (qName == "xs:sequence") {
        // ignore
        //std::cout << QString("ignoring %1").arg(qName).toLatin1().data() << std::endl;
    } else if (qName == "xs:pattern") {
        // ignore
        //std::cout << QString("ignoring %1").arg(qName).toLatin1().data() << std::endl;
    } else {
        std::cerr << QString("SE: %1 unknown, breaking off parsing routine").arg(qName).toLatin1().data() << std::endl;
        exit(1); // this is a very bad situation, stop the generation completely to avoid half libraries
        return false;
    }

    return true;
}

bool Handler::characters ( const QString  & ch ) {

    //std::cout << QString("CH:        [%1]").arg(ch.trimmed()).toLatin1().data() << std::endl;
    m_doc = ch.trimmed();
    return true;
}

bool Handler::endElement ( const QString & /* namespaceURI */,
                          const QString & /* localName */,
                          const QString & qualifiedName ) {

    // some xsd use the xsd:<token> style
    QString qName = qualifiedName;
    qName.replace(QString("xsd:"), QString("xs:"));

#if 0
    std::cout << QString("EE: %1").arg(qName).toLatin1().data() << std::endl;
#endif

    // pop elements previously been pushed
    if (qName == "xs:attribute") {
        m_attrStack.pop();
    } else if (qName == "xs:choice") {
        // this was a choice element which means all attributes are optional
        XSDObject *obj = m_objStack.top();
        //std::cout << QString("Choice for %1").arg(obj->name()).toLatin1().data() << std::endl;

        for(int j=0; j < obj->attributes().size(); j++) {
            XSDAttribute *attr = obj->attributes().at(j);

            // it would be better to set a choice paramater and generate precicely one
            // but 0-x is a reasonable alternative
            attr->setRequired(false);
        }
    } else if (qName == "xs:documentation") {
        // ignore documentation without a parent (probably on xml level)
        if (m_attrStack.size() > 0) {
            XSDAttribute *attr = m_attrStack.top();
            attr->setDocumentation(m_doc);

            XSDObject *obj = m_objStack.top();
            if (attr->name() == obj->name())
                obj->setDocu(m_doc);
        }
        else {
            XSDObject *obj = m_objects.first(); // schema is the first object
            obj->addKeyWithValue(qName, m_doc);
        }
    } else if (qName == "xs:element") {
        m_objStack.pop(); // pop the element
        m_attrStack.pop(); // pop the attribute of the parent
    } else if ((qName == "xs:complexType") ||(qName == "xs:simpleType") ||(qName == "xs:group")) {
        XSDObject *obj = m_objStack.top();
        if (obj->isTypeDefinition()) { //  complex types on schema level are other objects used as referal data
            std::cout << QString("closing referal type for %1").arg(qName).toLatin1().data() << std::endl;
            m_objStack.pop(); // pop the element
            m_attrStack.pop(); // pop the attribute of the parent
        }
    } else if (qName == "xs:schema") {
        // though all objects are part of the schema it is better to not include them there
        // otherwise we have only one root object.
        //m_objStack.pop();
    }

    return true;
}

bool Handler::endDocument () {

    //std::cout << "ED" << std::endl;
    return true;
}

bool Handler::error ( const QXmlParseException & exception ) {

    std::cout << exception.message().toLatin1().data() << std::endl;
    return true;
}
