/*
 *  MainApp.cpp
 *
 *  xsd2code is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  xsd2code is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Created by Lukassen on 11/06/08.
 *  Copyright 2008
 *
 */
 
#include <cstdlib>

#include "mainapp.h"

MainApp::MainApp( int & argc, char ** argv )
        :QApplication(argc, argv, false) {

    // handle the commandline args
    // add default command line m_options
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "help",     "show this information and exit." ) );
    m_options.append( CmdLineOption( CmdLineOption::TEXT,    "file",     "read from XSD file" ) );
    m_options.append( CmdLineOption( CmdLineOption::TEXT,    "out",      "target dir (default is file)" ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "version",  "show version information and exit." ) );
    m_options.append( CmdLineOption( CmdLineOption::TEXT,    "prefix",   "a prefix for the classes" ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "qt",       "generate qt cpp files (default)." ) );
//    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "cpp",      "generate cpp files" ) );
//    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "cs",       "generate c# files" ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "java",     "generate java files" ) );
    m_options.append( CmdLineOption( CmdLineOption::BOOLEAN, "objc",     "generate objective-C files" ) );


    // parse command line m_options
    m_options.parse( argc, argv );

    // is there a request for some version info?
    if ( m_options.getBoolean( "version" ) ) {
        std::cout << "\n xsd2code 0.0.1\n----------------------------------------\n\nCopyright 2008\n"  << std::endl;
        std::exit(0);
    }

	// setup the file handler
	m_reader = new QXmlSimpleReader();
    m_handler = new Handler();

    // setup the parser
    m_reader->setContentHandler(m_handler);
    m_reader->setErrorHandler(m_handler);
	
    // startup timer, to allow the event loop to start
    QTimer *timer = new QTimer( 0 ); // we leak one timer here, is acceptable
    timer->setInterval( 100 );
    timer->setSingleShot( true );
    connect( timer, SIGNAL( timeout() ), this, SLOT( slotStart() ) );
    timer->start();
}

void MainApp::slotStart( void ) {
    std::cout << "xsd2code started" << std::endl;

    QString fileName("");
    if (m_options.getText("file", fileName)) {
        // read from file
        QFile *file = new QFile(fileName);

        // test if we can read it
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
            std::cout << QString("xsd2code error opening file: %1").arg(fileName).toLatin1().data() << std::endl;
            std::exit(-1);
        }

        // and the input
        QXmlInputSource inputXML(file);
        m_reader->parse(inputXML); // presume we can read the whole file at once

		CodeGen *generator = new CodeGenQT(); // default to Qt
		if ( m_options.getBoolean( "java" ) ) {
			std::cout << "xsd2code: sorry not implemented yet" << std::endl;
            std::exit(-1);
		} else if ( m_options.getBoolean( "java" ) ) {
			std::cout << "xsd2code: sorry not implemented yet" << std::endl;
            std::exit(-1);
		} else if ( m_options.getBoolean( "objc" ) ) {
		        generator = new CodeGenObjC(); 
		} else if ( m_options.getBoolean( "cpp" ) ) {
			std::cout << "xsd2code: sorry not implemented yet" << std::endl;
            std::exit(-1);
		}
		
    		QString prefix("");
    		m_options.getText("prefix", prefix); // get an optional prefix

		// set properties and go
		generator->setObjects(m_handler->objects());
		generator->setPrefix(prefix);
		QString outDir(fileName); // probably need to create it first, strip of leading path etc TODO
        	m_options.getText("out", outDir);
		generator->setOutputDir(outDir);
		generator->go();
		
        // we are finished
        std::exit(0);
    } 
}
