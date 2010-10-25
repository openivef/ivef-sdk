/*
 *  XSDObj.cpp
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

#include "xsdobject.h"

XSDObject::XSDObject() {
	m_merged = false;
	m_root = false;
	m_hasBaseClass = false;
	m_type = false;
        m_simple = false;
	m_isEmbedded = false;
}

void XSDObject::dump() {
        std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "object name         " << QString(m_name).toLatin1().data() << std::endl;
	std::cout << "object hasBaseClass " << QString((m_hasBaseClass ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_hasBaseClass) {
		std::cout << "object baseClass         " << QString(m_baseClass).toLatin1().data() << std::endl;
        }
	std::cout << "object document     " << QString(m_docu).toLatin1().data() << std::endl;
	std::cout << "object isMerged     " << QString(m_merged).toLatin1().data() << std::endl;
	std::cout << "object isType       " << QString(m_type).toLatin1().data() << std::endl;
        std::cout << "object isSimple     " << QString(m_simple).toLatin1().data() << std::endl;
	std::cout << "object isRoot       " << QString(m_root).toLatin1().data() << std::endl;
	std::cout << "object isEmbedded   " << QString(m_isEmbedded).toLatin1().data() << std::endl;
        for (int h=0; h < m_attributes.size(); h++) {
		std::cout << "object attribute    " << QString(m_attributes.at(h)->name()).toLatin1().data() << std::endl;
        }
        for (int h=0; h < m_fixedValues.keys().size(); h++) {
		std::cout << "object fixed key    " << QString(m_fixedValues.keys().at(h)).toLatin1().data();
		std::cout << "    value " << QString(m_fixedValues[(m_fixedValues.keys().at(h))]).toLatin1().data()  << std::endl;
        }
        std::cout << "-----------------------------------------------------" << std::endl;
}

XSDObject::XSDObject(QString name ) {
	m_merged = false;
	m_isEmbedded = false;
	m_name = name;
}

void XSDObject::setBaseClass(QString name ) {
	m_hasBaseClass = true;
	m_baseClass = name;
}

QString XSDObject::baseClass() {
	return m_baseClass;
}

bool XSDObject::hasBaseClass() {
        if ((m_hasBaseClass) && (m_baseClass != "")) 
	   return true;
	return false;
}

QString XSDObject::name() {
	return m_name;
}

void XSDObject::setName(QString name ) {
	m_name = name;
}

bool XSDObject::isSimpleElement() {
	return m_simple;
}

bool XSDObject::isTypeDefinition() {
	return m_type;
}

void XSDObject::setSimpleElement(bool val) {
	m_simple = val;
}

void XSDObject::setTypeDefinition(bool val) {
	m_type = val;
}

void XSDObject::setRootObject() {
	m_root = true;
}

bool XSDObject::isRootObject() {
	return m_root;
}

void XSDObject::setEmbedded() {
	m_isEmbedded = true;
}

bool XSDObject::isEmbedded() {
	return m_isEmbedded;
}

void XSDObject::setMerged() {
	m_merged = true;
}

bool XSDObject::isMerged() {
	return m_merged;
}

void XSDObject::addKeyWithValue(QString key, QString value) {
	m_fixedValues.insert(key, value);
}

void XSDObject::addAttribute(XSDAttribute *attr) {

        // merged objects may lead to duplicate attributes
        for (int i=0; i<m_attributes.size(); i++) {
            XSDAttribute *existingAttr = m_attributes.at(i);

	    if ((existingAttr->name() == attr->name()) &&
                (existingAttr->type()== attr->type())) {
                std::cout << QString("WARNING Object %1 reused attribute %2, ignoring second entry").arg(m_name, attr->name()).toLatin1().data() << std::endl;
		return;
            }
        } 
	m_attributes.append(attr);
}

QVector<XSDAttribute*> XSDObject::attributes() {
	return m_attributes;
}

QMap<QString, QString> XSDObject::fixedValues() {
	return m_fixedValues;
}

QString XSDObject::docu()
{
    return m_docu;
}

void XSDObject::setDocu(const QString& docu)
{
    m_docu = docu;
}
