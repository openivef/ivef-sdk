/*
 *  CmdLineOption.cpp
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

#include <cstdlib>
#include <iostream>

#include <QStringList>
#include <QStack>

#include "cmdlineoption.h"


CmdLineOption::CmdLineOption( Types type, const char *field, const char *help ) {
    // constructor
    m_FieldType = type;
    m_FieldName = QString( field );
    m_HelpText  = QString( help );

    m_Set       = false;
}

void CmdLineOption::setVal( bool val ) {
    m_FieldData.b = val;
    m_Set         = true;
}

void CmdLineOption::setVal( int val ) {
    m_FieldData.i = val;
    m_Set         = true;
}

void CmdLineOption::setVal( QString val ) {
    m_FieldData.s = new QString( val ) ;
    m_Set         = true;
}

QString CmdLineOption::getHelpText( void ) {
    return m_HelpText;
}

CmdLineOption::Types CmdLineOption::getType() const {
    return m_FieldType;
}

void CmdLineOption::reset( void ) {
    m_Set = false;
}

// ---

CmdLineOptions::~CmdLineOptions() {
    m_Options.clear();
}

void CmdLineOptions::append( CmdLineOption o ) {
    m_Options.insert( o.getFieldName(), o );
}

void CmdLineOptions::parse( int &argc, char **argv ) {
    int i;
    QStringList arglist;
    QString argument;
    QRegExp rx;
    QStack<int> stack;

    // convenience only: put arguments in a list
    arglist.clear();
    for ( i = 1; i < argc; i++ ) {
        arglist.append( argv[i] );
    }

    // now let's parse all arguments
    for ( int i = 0; i < arglist.count(); i++ ) {
        argument = arglist[i];

        // boolean
        rx.setPattern( "^--([A-Za-z0-9]+)$" );
        if ( rx.indexIn( argument ) != -1 ) {
            if ( m_Options.contains( rx.cap(1) ) && ( m_Options.value( rx.cap(1) ).getType() == CmdLineOption::BOOLEAN ) ) {
                stack.push( i );
                m_Options[ rx.cap(1) ].setVal( true );
            }
        }

        // text
        rx.setPattern( "^--([A-Za-z0-9]+)=(\\S+)$" );
        if ( rx.indexIn( argument ) != -1 ) {
            if ( m_Options.contains( rx.cap(1) ) && ( m_Options.value( rx.cap(1) ).getType() == CmdLineOption::TEXT ) ) {
                stack.push( i );
                m_Options[ rx.cap(1) ].setVal( rx.cap(2) );
            }
        }

        // integer
        rx.setPattern( "^--([A-Za-z0-9]+)=(\\d+)$" );
        if ( rx.indexIn( argument ) != -1 ) {
            if ( m_Options.contains( rx.cap(1) ) && ( m_Options.value( rx.cap(1) ).getType() == CmdLineOption::INTEGER ) ) {
                stack.push( i );
                m_Options[ rx.cap(1) ].setVal( rx.cap(2).toInt() );
            }
        }
    }

    // now let's cleanup the list...
    while ( ! stack.isEmpty() ) {
        // removing item...
        arglist.removeAt( stack.pop() );
    }

    if ( arglist.count() > 0 ) {
        std::cout << "Unknown option! Use iListen --help' for more information." << std::endl;
        std::exit(1);
    }

    if ( getBoolean( "help" ) ) printHelp();
}

bool CmdLineOptions::getBoolean( const QString &var ) {
    if ( m_Options.contains( var ) &&
            ( m_Options.value( var ).getType() == CmdLineOption::BOOLEAN ) &&
            ( m_Options.value( var ).isSet() ) )
        return true;

    return false;
}

bool CmdLineOptions::getText( const QString &var, QString &val ) {
    if ( m_Options.contains( var ) &&
            ( m_Options.value( var ).getType() == CmdLineOption::TEXT ) &&
            ( m_Options.value( var ).isSet() ) ) {
        val = *m_Options.value( var ).getValue().s;
        return true;
    }

    return false;
}

bool CmdLineOptions::getInteger( const QString &var, int &val ) {
    if ( m_Options.contains( var ) &&
            ( m_Options.value( var ).getType() == CmdLineOption::INTEGER ) &&
            ( m_Options.value( var ).isSet() ) ) {
        val = m_Options.value( var ).getValue().i;
        return true;
    }

    return false;
}

void CmdLineOptions::printHelp( void ) {
    QMap<QString, CmdLineOption>::iterator it;

    std::cout << "Usage: iListen [ options ]" << std::endl << std::endl;
    std::cout << "Available options:" << std::endl;

    for ( it = m_Options.begin(); it != m_Options.end(); ++it ) {
        if ( it.value().getType() == CmdLineOption::BOOLEAN ) {
            std::cout << QString( "     --%1%2" ).arg( it.key(), -30 ).arg( it.value().getHelpText() ).toLatin1().data() << std::endl;
        }

        if ( it.value().getType() == CmdLineOption::TEXT ) {
            std::cout << QString( "     --%1%2" ).arg( it.key() + "=TEXT_STRING", -30 ).arg( it.value().getHelpText() ).toLatin1().data() << std::endl;
        }

        if ( it.value().getType() == CmdLineOption::INTEGER ) {
            std::cout << QString( "     --%1%2" ).arg( it.key() + "=INTEGER_VALUE", -30 ).arg( it.value().getHelpText() ).toLatin1().data() << std::endl;
        }
    }

    std::cout << std::endl;
    std::exit(0);
}

