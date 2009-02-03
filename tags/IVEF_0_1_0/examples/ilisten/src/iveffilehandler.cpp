/*
 *  IVEFFileHandler.cpp
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

#include "iveffilehandler.h"

IVEFFileHandler::IVEFFileHandler(Parser *parser) {
    m_parser = parser;
}

IVEFFileHandler::~IVEFFileHandler() {
}

void IVEFFileHandler::readFiles(QStringList files) {
    // try to load all the files
    for (int i = 0; i < files.count(); i++) {
        std::cout << QString("iListen parsing file: %1").arg(files.at(i)).toLatin1().data() << std::endl;

        // open each file
        QFile *file = new QFile(files.at(i));

        // test if we can read it
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
            std::cout << QString("iListen error opening file: %1").arg(files.at(i)).toLatin1().data() << std::endl;
            break;
        }

        while (!file->atEnd()) {
            QString line = file->readLine();
            m_parser->parseXMLString(line, true);
        }
    }
}

