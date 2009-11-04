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
	m_hasBaseClass = false;
	m_type = false;
	m_isEmbedded = false;
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

bool XSDObject::isTypeDefinition() {
	return m_type;
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
