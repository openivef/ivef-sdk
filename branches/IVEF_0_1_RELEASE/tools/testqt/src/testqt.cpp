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
 
#include <cstdlib>

#include "testqt.h"

testqt::testqt( int & argc, char ** argv )
        :QApplication(argc, argv, false) {

    // connect to the events from the parser
    connect( &m_parser, SIGNAL( signalMSG_VesselData(MSG_VesselData)),         this, SLOT( slotMSG_VesselData(MSG_VesselData) ));
    connect( &m_parser, SIGNAL( signalMSG_LoginRequest(MSG_LoginRequest)),     this, SLOT( slotMSG_LoginRequest(MSG_LoginRequest)));
    connect( &m_parser, SIGNAL( signalMSG_LoginResponse(MSG_LoginResponse)),   this, SLOT( slotMSG_LoginResponse(MSG_LoginResponse)));
    connect( &m_parser, SIGNAL( signalMSG_Ping(MSG_Ping)),                     this, SLOT( slotMSG_Ping(MSG_Ping)));
    connect( &m_parser, SIGNAL( signalMSG_Pong(MSG_Pong)),                     this, SLOT( slotMSG_Pong(MSG_Pong)));
    connect( &m_parser, SIGNAL( signalMSG_ServerStatus(MSG_ServerStatus)),     this, SLOT( slotMSG_ServerStatus(MSG_ServerStatus)));
    connect( &m_parser, SIGNAL( signalMSG_Logout(MSG_Logout)),                 this, SLOT( slotMSG_Logout(MSG_Logout)));
    connect( &m_parser, SIGNAL( signalMSG_ServiceRequest(MSG_ServiceRequest)), this, SLOT( slotMSG_ServiceRequest(MSG_ServiceRequest)));
    // Issue 24
    connect( &m_parser, SIGNAL( signalError(QString)), this, SLOT( slotPrintError(QString) ));
    connect( &m_parser, SIGNAL( signalWarning(QString)), this, SLOT( slotPrintError(QString) ));
    // End Issue 24

    // and keep reading from standard in
    std::cout << "TestQt ready for input" << std::endl;
    std::string input_line;
    while(!std::cin.fail()) {
        getline(std::cin, input_line);
        input_line += "\n"; // getline eats the new line
        //std::cout << input_line << std::endl;
        m_parser.parseXMLString(QString(input_line.c_str()), true);
    };
    std::cout << "TestQt shutting down" << std::endl;
    std::exit(0);
}

void testqt::slotMSG_VesselData( MSG_VesselData obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; } 
void testqt::slotMSG_LoginRequest( MSG_LoginRequest obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
void testqt::slotMSG_LoginResponse( MSG_LoginResponse obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
void testqt::slotMSG_Ping( MSG_Ping obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
void testqt::slotMSG_Pong( MSG_Pong obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
void testqt::slotMSG_ServerStatus( MSG_ServerStatus obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
void testqt::slotMSG_Logout( MSG_Logout obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
void testqt::slotMSG_ServiceRequest( MSG_ServiceRequest obj ) { std::cout << obj.toString("").toLatin1().data() << obj.toXML().toLatin1().data() << std::endl; }
// Issue 24
void testqt::slotPrintError( QString errorStr ) { std::cout << errorStr.toUtf8().data() << std::endl; }
// End Issue 24
