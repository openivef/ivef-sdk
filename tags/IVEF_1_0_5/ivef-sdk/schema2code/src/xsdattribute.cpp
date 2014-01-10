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

XSDAttribute::XSDAttribute(QString name, QString type, bool required, QString fixed) :
    m_name(name),
    m_type(type),
    m_isFixed(true),
    m_fixed(fixed),
    m_required(required),
    m_element(false),
    m_hasMinOccurs(false),
    m_minOccurs(-1),
    m_hasMaxOccurs(false),
    m_maxOccurs(-1),
    m_unbounded(false),
    m_hasMinLength(false),
    m_minLength(-1),
    m_hasMaxLength(false),
    m_maxLength(-1),
    m_hasDigits(false),
    m_digits(0),
    m_hasMinExclusive(false),
    m_minExclusive(-1),
    m_hasMaxExclusive(false),
    m_maxExclusive(-1),
    m_hasMinInclusive(false),
    m_minInclusive(-1),
    m_hasMaxInclusive(false),
    m_maxInclusive(-1)
{
    if (fixed == "") {
        m_isFixed = false;
    } else {
        // std::cout << "XSDAttribute contructor: has fixed [" << fixed.toLatin1().data() << "]" << std::endl;
    }
    //std::cout << QString("XSDAttribute created: %1 of type %2").arg(name, type).toLatin1().data() << std::endl;
}

void XSDAttribute::dump() {
        std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "attribute name      " << m_name.toLatin1().data() << std::endl;
    std::cout << "attribute type      " << m_type.toLatin1().data() << std::endl;
    std::cout << "attribute isFixed   " << (m_isFixed ? "true" : "false") << std::endl;
    if (m_isFixed) {
        std::cout << "attribute fixedVal  " << m_fixed.toLatin1().data() << std::endl;
    }
    std::cout << "attribute required  " << (m_required ? "true" : "false") << std::endl;
    std::cout << "attribute doc       " << m_doc.toLatin1().data() << std::endl;
    std::cout << "attribute isElement " << (m_element ? "true" : "false") << std::endl;
    for (int h=0; h < m_enums.size(); h++) {
        std::cout << "attribute enum      " << m_enums.at(h).toLatin1().data() << std::endl;
    }
    std::cout << "attribute hasMinOccurs " << (m_hasMinOccurs ? "true" : "false") << std::endl;
    if (m_hasMinOccurs) {
        std::cout << "attribute minOccurs " << m_minOccurs << std::endl;
    }
    std::cout << "attribute hasMaxOccurs " << (m_hasMaxOccurs ? "true" : "false") << std::endl;
    if (m_hasMaxOccurs) {
        std::cout << "attribute maxOccurs " << m_maxOccurs << std::endl;
    }
    std::cout << "attribute unbounded " << (m_unbounded ? "true" : "false") << std::endl;
    std::cout << "attribute hasMinLength " << (m_hasMinLength ? "true" : "false") << std::endl;
    if (m_hasMinLength) {
        std::cout << "attribute minLength " << m_minLength << std::endl;
    }
    std::cout << "attribute hasMaxLength " << (m_hasMaxLength ? "true" : "false") << std::endl;
    if (m_hasMaxLength) {
        std::cout << "attribute maxLength " << m_maxLength << std::endl;
    }
    std::cout << "attribute hasDigits " << (m_hasDigits ? "true" : "false") << std::endl;
    if (m_hasDigits) {
        std::cout << "attribute digits    " << m_digits << std::endl;
    }
    std::cout << "attribute hasMinExc " << (m_hasMinExclusive ? "true" : "false") << std::endl;
    if (m_hasMinExclusive) {
        std::cout << "attribute minExc    " << m_minExclusive << std::endl;
    }
    std::cout << "attribute hasMaxExc " << (m_hasMaxExclusive ? "true" : "false") << std::endl;
    if (m_hasMaxExclusive) {
        std::cout << "attribute maxExc    " << m_maxExclusive << std::endl;
    }
    std::cout << "attribute hasMinInc " << (m_hasMinInclusive ? "true" : "false") << std::endl;
    if (m_hasMinInclusive) {
        std::cout << "attribute minInc    " << m_minInclusive << std::endl;
    }
    std::cout << "attribute hasMaxInc " << (m_hasMaxInclusive ? "true" : "false") << std::endl;
    if (m_hasMaxInclusive) {
        std::cout << "attribute maxInc    " << m_maxInclusive << std::endl;
    }
    std::cout << "-----------------------------------------------------" << std::endl;
}

QString XSDAttribute::name() {
    return m_name;
}

void XSDAttribute::setType(QString type) {
    //std::cout << QString("XSDAttribute %1: type: %2").arg(m_name, type).toLatin1().data() << std::endl;
    m_type = type;
}

QString XSDAttribute::type() {
    return m_type;
}

void XSDAttribute::setFixed(QString type) {
    m_fixed = type;
    m_isFixed = true;
}

bool XSDAttribute::isFixed() {
    return m_isFixed;
}

QString XSDAttribute::fixed() {
    return m_fixed;
}

void XSDAttribute::setRequired(bool req) {
    m_required = req;
}

bool XSDAttribute::required() {
    return m_required;
}

void XSDAttribute::setDocumentation(QString doc) {
    m_doc = doc;
}

QString XSDAttribute::doc() {
    return m_doc;
}

void XSDAttribute::setElement(bool req) {
    m_element = req;
}

// create a scalar for unbounded or bounded entries
bool XSDAttribute::isScalar() {
    return m_unbounded || ((m_maxOccurs > 1) && m_element);
}

bool XSDAttribute::isSimpleElement() {
    // simple elements are elements (data members)
    // which have a type (like xs:string)
    return m_element && (m_type != m_name);
}

bool XSDAttribute::isElement() {
    return m_element;
}

void XSDAttribute::appendEnumeration(QString enum1) {
    m_enums.append(enum1);
}

QVector<QString> XSDAttribute::enumeration() {
    return m_enums;
}

void XSDAttribute::setMinOccurs(int min) {
    m_hasMinOccurs = true;
    m_minOccurs = min;
}

bool XSDAttribute::hasMinOccurs() {
    return m_hasMinOccurs;
}

int XSDAttribute::minOccurs() {
    return m_minOccurs;
}

void XSDAttribute::setMaxOccurs(int max) {
    m_hasMaxOccurs = true;
    m_maxOccurs = max;
}

bool XSDAttribute::hasMaxOccurs() {
    return m_hasMaxOccurs;
}

int XSDAttribute::maxOccurs() {
    return m_maxOccurs;
}

void XSDAttribute::setUnbounded() {
    m_unbounded = true;
}

bool XSDAttribute::isUnbounded() {
    return m_unbounded;
}

void XSDAttribute::setMinLength(int length) {
    m_hasMinLength = true;
    m_minLength = length;
}

bool XSDAttribute::hasMinLength() {
    return m_hasMinLength;
}

int XSDAttribute::minLength() {
    return m_minLength;
}

void XSDAttribute::setMaxLength(int length) {
    m_hasMaxLength = true;
    m_maxLength = length;
}

bool XSDAttribute::hasMaxLength() {
    return m_hasMaxLength;
}

int XSDAttribute::maxLength() {
    return m_maxLength;
}

void XSDAttribute::setDigits(int length) {
    m_hasDigits = true;
    m_digits = length;
}

bool XSDAttribute::hasDigits() {
    return m_hasDigits;
}

int XSDAttribute::digits() {
    return m_digits;
}

void XSDAttribute::setMinExclusive(double min) {
    m_hasMinExclusive = true;
    m_minExclusive = min;
}

bool XSDAttribute::hasMinExclusive() {
    return m_hasMinExclusive;
}

double XSDAttribute::minExclusive() {
    return m_minExclusive;
}

void XSDAttribute::setMaxExclusive(double max) {
    m_hasMaxExclusive = true;
    m_maxExclusive = max;
}

bool XSDAttribute::hasMaxExclusive() {
    return m_hasMaxExclusive;
}

double XSDAttribute::maxExclusive() {
    return m_maxExclusive;
}

void XSDAttribute::setMinInclusive(double min) {
    m_hasMinInclusive = true;
    m_minInclusive = min;
}

bool XSDAttribute::hasMinInclusive() {
    return m_hasMinInclusive;
}

double XSDAttribute::minInclusive() {
    return m_minInclusive;
}

void XSDAttribute::setMaxInclusive(double max) {
    m_hasMaxInclusive = true;
    m_maxInclusive = max;
}

bool XSDAttribute::hasMaxInclusive() {
    return m_hasMaxInclusive;
}

double XSDAttribute::maxInclusive() {
    return m_maxInclusive;
}
