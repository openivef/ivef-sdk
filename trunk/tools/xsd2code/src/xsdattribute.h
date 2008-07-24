/*
 *  XSDAttribute.h
 *
 *  xsd2code is free software: you can redistribute it and/or modify
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
    	XSDAttribute(QString name, QString type, bool required);
	void setMinOccurs(int min);
	void setMaxOccurs(int max);
	void setMaxLength(int length);
	void setType(QString type);
	void setUnbounded();
	void appendEnumeration(QString enum1);
	QString name();
	QString type();
	bool required();
	bool unbounded();
	bool hasMin();
	bool hasMax();
	int min();
	int max();
	
private:
	QVector<QString> m_enums;
	QString m_name;
	QString m_type;
	bool m_required;
	bool m_unbounded;
	int m_min;
	int m_maxLength;
	int m_max;
	bool m_hasMin;
	bool m_hasMax;
};

#endif
