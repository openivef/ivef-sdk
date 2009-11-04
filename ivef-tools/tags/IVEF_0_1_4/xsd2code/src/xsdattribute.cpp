/*
 *  XSDAttribute.cpp
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

#include "xsdattribute.h"

XSDAttribute::XSDAttribute(QString name, QString type, bool required, QString fixed) {
	m_name = name;
	m_type = type;
	m_required = required;
	m_unbounded = false;
	m_hasMin = false;
	m_hasMax = false;
	m_maxLength = -1; 
	m_minLength = -1; 
        m_digits = 0;
        m_fixed = fixed;
        m_isFixed = true;
        if (fixed == "") {
          m_isFixed = false;
        } else {
	 // std::cout << "XSDAttribute contructor: has fixed [" << fixed.toLatin1().data() << "]" << std::endl;
        }
    //std::cout << QString("XSDAttribute created: %1 of type %2").arg(name, type).toLatin1().data() << std::endl;
}

void XSDAttribute::setRequired(bool req) {
	m_required = req;
}

void XSDAttribute::setFixed(QString type) {
	m_fixed = type;
        m_isFixed = true;
}

void XSDAttribute::setType(QString type) {
    //std::cout << QString("XSDAttribute %1: type: %2").arg(m_name, type).toLatin1().data() << std::endl;
	m_type = type;
}

void XSDAttribute::appendEnumeration(QString enum1) {
    //std::cout << QString("XSDAttribute %1: enum: %2").arg(m_name, enum1).toLatin1().data() << std::endl;
	m_enums.append(enum1);
}

void XSDAttribute::setDigits(int length) {
	m_digits = length;
	//std::cout << QString("XSDAttribute %1: maxLength: %2").arg(m_name, ""+length).toLatin1().data() << std::endl;
}

void XSDAttribute::setMinLength(int length) {
	m_minLength = length;
	//std::cout << QString("XSDAttribute %1: maxLength: %2").arg(m_name, ""+length).toLatin1().data() << std::endl;
}

void XSDAttribute::setMaxLength(int length) {
	m_maxLength = length;
	//std::cout << QString("XSDAttribute %1: maxLength: %2").arg(m_name, ""+length).toLatin1().data() << std::endl;
}

void XSDAttribute::setUnbounded() {
	 m_unbounded = true;
}

QVector<QString> XSDAttribute::enumeration() {
	return m_enums;
}

bool XSDAttribute::hasMin() {
	return m_hasMin;
}

bool XSDAttribute::hasMax() {
	return m_hasMax;
}

int XSDAttribute::min() {
	return m_min;
}

int XSDAttribute::max() {
	return m_max;
}

bool XSDAttribute::unbounded() {
	return m_unbounded;
}

void XSDAttribute::setMinOccurs(int min) {
	m_hasMin = true;
	m_min = min;
	//std::cout << QString("XSDAttribute %1: min: %2").arg(m_name, ""+min).toLatin1().data() << std::endl;
}

bool XSDAttribute::required() {
	return m_required;
}

bool XSDAttribute::isFixed() {
	return m_isFixed;
}

QString XSDAttribute::fixed() {
	return m_fixed;
}

QString XSDAttribute::doc() {
	return m_doc;
}

void XSDAttribute::setDocumentation(QString doc) {
	m_doc = doc;
}

QString XSDAttribute::name() {
	return m_name;
}

QString XSDAttribute::type() {
	return m_type;
}

void XSDAttribute::setMaxOccurs(int max) {
	m_hasMax = true;
	m_max = max;
	//std::cout << QString("XSDAttribute %1: max: %2").arg(m_name, ""+max).toLatin1().data() << std::endl;
}
