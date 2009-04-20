/*
 *  XSDObject.h
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

#ifndef __XSDOBJ_H__
#define __XSDOBJ_H__

#include <iostream>
#include <QtCore>

#include "xsdattribute.h"

class XSDObject : public QObject {
    Q_OBJECT

public:
    XSDObject(QString name);
	XSDObject();
	void setName(QString name);
	void addAttribute(XSDAttribute *attr);
	void addKeyWithValue(QString key, QString value);
	void setRootObject();	
	void setMerged();	
	void setEmbedded();	
	void setTypeDefinition(bool val);	
	void setBaseClass(QString base);	

	QString name();
	QString baseClass();
        bool hasBaseClass();
        bool isMerged();
        bool isTypeDefinition();
        bool isEmbedded();
        bool isRootObject();
	QVector<XSDAttribute*>attributes();
	QMap<QString, QString>fixedValues();

private:
	QString m_name;
	QString m_baseClass;
	bool m_merged;
	bool m_hasBaseClass;
	bool m_type;
	bool m_root;
	bool m_isEmbedded;
	QVector<XSDAttribute*>m_attributes;
	QMap<QString, QString>m_fixedValues;
};

#endif
