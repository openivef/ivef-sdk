/*
 *  MainApp.h
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

#ifndef __MAINAPP_H__
#define __MAINAPP_H__

#include <iostream>

#include <QCoreApplication>
#include "cmdlineoption.h"
#include "handler.h"
#include "codegenqt.h"
#include "codegenpb.h"
#include "codegenphp.h"
#include "codegenjava.h"
#include "codegenobjc.h"

class MainApp : public QCoreApplication {
    Q_OBJECT

public:
    MainApp( int & argc, char ** argv );

private:
    CmdLineOptions m_options;
	QXmlSimpleReader *m_reader;
    Handler *m_handler;

private slots:
    void slotStart( void );

};

#endif
