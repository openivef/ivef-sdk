/*
 *  ivef2kmlApplication.cpp
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

#include "ivef2kmlapplication.h"

ivef2kmlApplication::ivef2kmlApplication( int & argc, char ** argv )
        :QApplication(argc, argv, false) {

    // handle the commandline args
    // add default command line m_options
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "help",        "show this information and exit." ) );
    m_options.append( CmdLineOption( CmdLineOption::TEXT,    "host",        "server ip nummer or hostname (default localhost)." ) );
    m_options.append( CmdLineOption( CmdLineOption::INTEGER, "port",        "port for IVEF XML connection (default 8043)." ) );
    m_options.append( CmdLineOption( CmdLineOption::INTEGER, "httpport",    "port for HTTP://KML connection (default 8080)." ) );
    m_options.append( CmdLineOption( CmdLineOption::TEXT,    "user",        "user name (default guest)." ) );
    m_options.append( CmdLineOption( CmdLineOption::TEXT,    "password",    "password (default guest)." ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "version",     "show version information and exit." ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "restamp",     "set the update time to the time received." ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "slipstream",  "use compression for the transmission." ) );

    // parse command line m_options
    m_options.parse( argc, argv );

    // is there a request for some version info?
    if ( m_options.getBoolean( "version" ) ) {
        std::cout << "\n ivef2kml 0.1.0\n----------------------------------------\n\n an example implementation for an IVEF bridge to KML.\n\n Copyright 2009\n"  << std::endl;
        std::exit(0);
    }
            
    // setup the parser
    m_streamHandler = new IVEFStreamHandler(&m_parser);
    // and the printer
    connect( &m_parser, SIGNAL( signalMSG_VesselData(MSG_VesselData)), this, SLOT( printVesselData(MSG_VesselData) ));

    // create a track store
    m_trackStore = new QMap<int, VesselData>;
            
    // startup timer, to allow the event loop to start
    QTimer *timer = new QTimer( 0 ); // we leak one timer here, is acceptable
    timer->setInterval( 100 );
    timer->setSingleShot( true );
    connect( timer, SIGNAL( timeout() ), this, SLOT( slotStart() ) );
    timer->start();
}

void ivef2kmlApplication::slotStart( void ) {

    // setup the IVEF connection
    std::cout << "ivef2kml started" << std::endl;
    QString host = "localhost";
    m_options.getText( "host", host );

    int port = 8043;
    m_options.getInteger( "port", port );

    bool slipstream = m_options.getBoolean( "slipstream" );

    QString user = "guest";
    m_options.getText( "user", user );

    QString password = "guest";
    m_options.getText( "password", password );

    m_streamHandler->connectToServer(host, port, user, password, "", slipstream, false);

    // and the http connection
    port = 8080;
    m_options.getInteger( "httpport", port );
    m_server = new HttpDaemon(this, port, m_trackStore);

    // make sure old tracks get cleaned up
    QTimer *timer = new QTimer( 0 ); 
    timer->setInterval( 10*1000 ); // check every x seconds
    connect( timer, SIGNAL( timeout() ), this, SLOT( slotCleanUp() ) );
    timer->start();

}

void ivef2kmlApplication::slotCleanUp( void ) {

    QMapIterator<int, VesselData> i(*m_trackStore);
    while (i.hasNext()) {
         i.next();
         VesselData vessel = i.value();

         int timeOut = 60;
         /*
	 if (vessel.getPosReport().hasUpdSensorType()) {
		switch(vessel.getPosReport().getUpdSensorType()) {
		  case 1: timeOut = 6; break; // radar updates every 3 sec
		  case 2: timeOut = 5*60; break; // AIS every 5 minutes
		  case 3: timeOut = 6; break; // take radar
		  default : timeOut = 6; break; // take radar
		}
         }
         */
         QDateTime updateTime = vessel.getPosReport().getUpdateTime();
         QDateTime now = QDateTime::currentDateTime();
         int age = updateTime.secsTo( now );
         
         if (age > timeOut ) {
              m_trackStore->remove(vessel.getPosReport().getId());
              std::cout << "Track: " << vessel.getPosReport().getId() << " has expired by secs: " << age;
              std::cout << " time: " <<  vessel.getPosReport().getUpdateTime().toString("yyyy-MM-ddThh:mm:ss.zzz").toLatin1().data() << std::endl;
         }
    }

}
            
void ivef2kmlApplication::printVesselData( MSG_VesselData obj ) {
            
    bool restamp = m_options.getBoolean( "restamp" );
    QDateTime now = QDateTime::currentDateTime();

    for (int i=0; i < obj.getBody().countOfVesselDatas();i++) {
        VesselData vessel = obj.getBody().getVesselDataAt(i);
        // update the track store
        if ( vessel.getPosReport().getLost() == "yes" ) {
        	m_trackStore->remove(vessel.getPosReport().getId());
        } else {
                if (restamp) {
                       PosReport pos = vessel.getPosReport();
                       pos.setUpdateTime(now);
                       vessel.setPosReport(pos);
                }
        	m_trackStore->insert(vessel.getPosReport().getId(), vessel);
        }
    }
    //std::cout << m_trackStore->count() << std::endl;
}
