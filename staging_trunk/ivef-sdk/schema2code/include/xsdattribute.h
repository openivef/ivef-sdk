/*
 *  XSDAttribute.h
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

#ifndef __XSDATTR_H__
#define __XSDATTR_H__

#include <iostream>
#include <QtCore>

class XSDAttribute : public QObject {
    Q_OBJECT

public:
    	XSDAttribute(QString name, QString type, bool required, QString fixed);
	void setMinOccurs(int min);
	void setMaxOccurs(int max);
	void setMaxLength(int length);
	void setMinLength(int length);
        void setDigits(int length);
	void setType(QString type);
	void setFixed(QString val);
	void setUnbounded();
	void setElement(bool req);
	void setRequired(bool req);
	void setDocumentation(QString doc);
	void appendEnumeration(QString enum1);
	QString name();
	QString type();
	QString doc();
	QString fixed();
	QVector<QString> enumeration();
	bool required();
	bool isFixed();
	bool isUnbounded();
	bool isScalar();
        bool hasDigits();
	bool isElement();
    	bool isSimpleElement();
	bool hasMinLength();
	bool hasMaxLength();
	bool hasMin();
	bool hasMax();
	int min();
	int max();
	int minLength();
	int maxLength();
    	int digits();
    	void dump();
	
private:
	QVector<QString> m_enums;
	QString m_name;
	QString m_type;
	QString m_fixed;
	QString m_doc;
	bool m_element;
	bool m_required;
	bool m_unbounded;
	int m_min;
	int m_digits;
	int m_maxLength;
	int m_minLength;
	int m_max;
	bool m_isFixed;
	bool m_hasMin;
	bool m_hasMax;
	bool m_hasMinLength;
	bool m_hasMaxLength;
    bool m_hasDigits;
};

#endif
