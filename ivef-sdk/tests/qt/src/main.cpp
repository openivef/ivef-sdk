/*
 *  main.cpp
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

#include <iostream>
#include <QCoreApplication>
#include "testqt.h"


int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);
    testqt parser;

    std::cout << "TestApp ready for input" << std::endl;

    std::string input_line;
    while (std::getline(std::cin, input_line)) {
        input_line += "\n";
        parser.parseXMLString(QString::fromStdString(input_line));
    }

    std::cout << "TestApp shutting down" << std::endl;
    return 0;
}
