/*
 *  XSDAttribute.cpp
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

#include "xsdattribute.h"

XSDAttribute::XSDAttribute(QString name, QString type, bool required, QString fixed) {
	m_name = name;
	m_type = type;
	m_required = required;
	m_unbounded = false;
	m_element = false;
	m_hasMinLength = false;
	m_hasMaxLength = false;
	m_hasMin = false;
	m_hasMax = false;
    m_hasDigits = false;
	m_maxLength = -1; 
	m_minLength = -1; 
    m_min = -1;
    m_max = -1;
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

void XSDAttribute::dump() {
        std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "attribute name      " << QString(m_name).toLatin1().data() << std::endl;
	std::cout << "attribute type      " << QString(m_type).toLatin1().data() << std::endl;
	std::cout << "attribute isFixed   " << QString((m_isFixed ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_isFixed) {
		std::cout << "attribute fixedVal  " << QString(m_fixed).toLatin1().data() << std::endl;
	}
	std::cout << "attribute doc       " << QString(m_doc).toLatin1().data() << std::endl;
	std::cout << "attribute isElement " << QString((m_element ? "true" : "false")).toLatin1().data() << std::endl;
	std::cout << "attribute required  " << QString((m_required ? "true" : "false")).toLatin1().data() << std::endl;
	std::cout << "attribute unbound   " << QString((m_unbounded ? "true" : "false")).toLatin1().data() << std::endl;
	std::cout << "attribute hasMin    " << QString((m_hasMin ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_hasMin) {
		std::cout << "attribute min       " << QString::number(m_min).toLatin1().data() << std::endl;
	}
	std::cout << "attribute hasMinLength " << QString((m_hasMinLength ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_hasMinLength) {
	    	std::cout << "attribute minLength " << QString(m_minLength).toLatin1().data() << std::endl;
        }
	std::cout << "attribute hasMaxLength " << QString((m_hasMaxLength ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_hasMaxLength) {
		std::cout << "attribute maxLength " << QString(m_maxLength).toLatin1().data() << std::endl;
	}
	std::cout << "attribute hasMax    " << QString((m_hasMax ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_hasMax) {
		std::cout << "attribute max       " << QString::number(m_max).toLatin1().data() << std::endl;
	}
        std::cout << "attribute hasDigits " << QString((m_hasDigits ? "true" : "false")).toLatin1().data() << std::endl;
	if (m_hasDigits) {
		std::cout << "attribute digits    " << QString::number(m_digits).toLatin1().data() << std::endl;
	}
        for (int h=0; h < m_enums.size(); h++) {
	    std::cout << "attribute enum      " << QString(m_enums.at(h)).toLatin1().data() << std::endl;
        }
        std::cout << "-----------------------------------------------------" << std::endl;
}

void XSDAttribute::setElement(bool req) {
	m_element = req;
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
    m_hasDigits = true;
	m_digits = length;
	//std::cout << QString("XSDAttribute %1: maxLength: %2").arg(m_name, ""+length).toLatin1().data() << std::endl;
}

void XSDAttribute::setMinLength(int length) {
	m_hasMinLength = true;
	m_minLength = length;
	//std::cout << QString("XSDAttribute %1: maxLength: %2").arg(m_name, ""+length).toLatin1().data() << std::endl;
}

void XSDAttribute::setMaxLength(int length) {
	m_hasMaxLength = true;
	m_maxLength = length;
	//std::cout << QString("XSDAttribute %1: maxLength: %2").arg(m_name, ""+length).toLatin1().data() << std::endl;
}

void XSDAttribute::setUnbounded() {
    m_unbounded = true;
}

QVector<QString> XSDAttribute::enumeration() {
	return m_enums;
}

bool XSDAttribute::hasMinLength() {
	return m_hasMinLength;
}

bool XSDAttribute::hasMin() {
	return m_hasMin;
}

bool XSDAttribute::hasDigits() {
	return m_hasDigits;
}

bool XSDAttribute::isSimpleElement() {
    // simple elements are elements (data members)
    // which have a type (like xs:string)
    return m_element && (m_type != m_name);
} 

bool XSDAttribute::isElement() {    
	return m_element;
}

bool XSDAttribute::hasMaxLength() {
	return m_hasMaxLength;
}

bool XSDAttribute::hasMax() {
	return m_hasMax;
}

int XSDAttribute::minLength() {
	return m_minLength;
}

int XSDAttribute::maxLength() {
	return m_maxLength;
}

int XSDAttribute::min() {
	return m_min;
}

int XSDAttribute::max() {
	return m_max;
}

int XSDAttribute::digits() {
	return m_digits;
}

bool XSDAttribute::isUnbounded() {
	return m_unbounded;
}

// create a scalar for unbounded or bounded entries
bool XSDAttribute::isScalar() {
	return m_unbounded || ((m_max > 1) && m_element);
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
