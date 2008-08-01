/*
 *  IVEFHandler.h
 *
 *  iListen is free software: you can redistribute it and/or modify
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

#ifndef __IVEFHANDLER_H__
#define __IVEFHANDLER_H__

#include <QXmlDefaultHandler>
#include <QtCore>
#include <iostream>

class IVEFHandler : public QXmlDefaultHandler {

public:
    IVEFHandler() { };

    QString makeReadableValueForKey(QString key, QString value);

    bool startElement (const QString & namespaceURI,
                       const QString & localName,
                       const QString & qName,
                       const QXmlAttributes & atts);
    bool error ( const QXmlParseException & exception );
};

#endif
