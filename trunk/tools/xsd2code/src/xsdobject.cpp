/*
 *  XSDObj.cpp
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

#include "xsdobject.h"

XSDObject::XSDObject() {
	m_merged = false;
	m_root = false;
	m_isEmbedded = false;
}

XSDObject::XSDObject(QString name ) {
	m_merged = false;
	m_isEmbedded = false;
	m_name = name;
    //std::cout << QString("XSDObject created: %1").arg(name).toLatin1().data() << std::endl;
}

void XSDObject::setName(QString name ) {
	m_name = name;
    //std::cout << QString("XSDObject named: %1").arg(name).toLatin1().data() << std::endl;
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
    //std::cout << QString("XSDObject %1: added key: %2 value: %3").arg(m_name, key, value).toLatin1().data() << std::endl;
	m_fixedValues.insert(key, value);
}

void XSDObject::addAttribute(XSDAttribute *attr) {
    //std::cout << QString("XSDObject %1: added attribute: %2").arg(m_name, attr->name()).toLatin1().data() << std::endl;
	m_attributes.append(attr);
}

QString XSDObject::name() {
	return m_name;
}

QVector<XSDAttribute*> XSDObject::attributes() {
	return m_attributes;
}

QMap<QString, QString> XSDObject::fixedValues() {
	return m_fixedValues;
}
