/*
 *  Handler.h
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

#ifndef __HANDLER_H__
#define __HANDLER_H__

#include <QXmlDefaultHandler>
#include <QtCore>
#include <iostream>
#include "xsdobject.h"

class Handler : public QObject {

public:
    Handler() { };

    bool startDocument ();
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    bool startElement (const QStringRef &namespaceURI,
                       const QStringRef &localName,
                       const QStringRef &qName,
                       const QXmlStreamAttributes &atts);

    bool characters (const QStringRef &ch);
    bool endElement (const QStringRef &namespaceURI,
                     const QStringRef &localName,
                     const QStringRef &qName );
#else
    bool startElement (QStringView namespaceURI,
                       QStringView localName,
                       QStringView qName,
                       const QXmlStreamAttributes &atts);

    bool characters (QStringView ch);
    bool endElement (QStringView namespaceURI,
                     QStringView localName,
                     QStringView qName );
#endif
    bool endDocument ();

    QVector<XSDObject*> objects();
    void handleStartOfElement (const QString & qName,
                               const QXmlStreamAttributes & atts,
                               bool isTypeDef);
    QString stripNameSpace(QString tag);

private:
    QStack<XSDObject*> m_objStack;
    QStack<XSDAttribute*>m_attrStack;
    QVector<XSDObject*> m_objects;
    QString m_doc;
};

#endif
