/*
 *  testqt.cpp
 *
 *  ivef2kml is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ivef2kml is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Created by Lukassen on 11/06/08.
 *  Copyright 2008
 *
 */

#include <iostream>

#include "testqt.h"

testqt::testqt() {
    // connect to the events from the parser
    connect( &m_parser, SIGNAL( signalMSG_IVEF(ivef::MSG_IVEF)), this, SLOT( slotMSG_IVEF(ivef::MSG_IVEF) ));
    connect( &m_parser, SIGNAL( signalError(QString)), this, SLOT( slotPrintError(QString) ));
    connect( &m_parser, SIGNAL( signalWarning(QString)), this, SLOT( slotPrintError(QString) ));
    connect( &m_parser, SIGNAL( signalValidationError(QString)), this, SLOT( slotPrintError(QString) ));
}

void testqt::parseXMLString( QString str ) {
    m_parser.parseXMLString(str, true);
}

void testqt::slotMSG_IVEF( ivef::MSG_IVEF obj ) {
    std::cout << obj.toString("").toUtf8().data();
    QString xml = obj.toXML();
    if ( xml.isEmpty() )
        std::cout << obj.lastError().toUtf8().data();
    else
        std::cout << xml.toUtf8().data();
    std::cout << std::endl;
}

void testqt::slotPrintError( QString errorStr ) {
     std::cout << errorStr.toUtf8().data() << std::endl;
}
