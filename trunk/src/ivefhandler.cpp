/*
 *  IVEFHandler.cpp
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

#include "ivefhandler.h"

QString IVEFHandler::makeReadableValueForKey(QString key, QString value) {
    // change some known fields to better readable values
    if (key == "ShipType") {
        bool canRead;
        int  intVal = value.toInt(&canRead, 10);
        if (!canRead) {
            return value; // cannot convert shiptype, leave as string
        }

        switch (intVal) {
        case 20:
            return "WIG";
            break;
        case 30:
            return "fishing vessel";
        case 31:
            return "towing vessel";
            break;
        case 32:
            return "big towing vessel";
            break;
        case 33:
            return "dredging vessel";
            break;
        case 34:
            return "diving vessel";
            break;
        case 35:
            return "military vessel";
            break;
        case 36:
            return "sailing vessel";
            break;
        case 37:
            return "pleasure craft";
            break;
        case 40:
            return "HSC";
            break;
        case 50:
            return "pilot vissel";
            break;
        case 51:
            return "SAR";
            break;
        case 52:
            return "tug";
            break;
        case 53:
            return "port tender";
            break;
        case 54:
            return "anti pollution vessel";
            break;
        case 55:
            return "law enforcement vessel";
            break;
        case 58:
            return "medical vessel";
            break;
        case 59:
            return "mob83 vessel";
            break;
        case 60:
            return "passenger ship";
            break;
        case 70:
            return "cargo ship";
            break;
        case 80:
            return "tanker";
            break;
        case 90:
            return "other types of ship ";
            break;
        default:
            return value;
            break;
        }
    } // ShipType
    else if (key == "CargoType") {
        bool canRead;
        int  intVal = value.toInt(&canRead, 10);
        if (!canRead) {
            return value; // cannot convert cargotype, leave as string
        }

        switch (intVal) {
        case 0:
            return "All ships of this type";
            break;
        case 1:
            return "Carrying DG, HS, or MP, IMO hazard or pollutant category A";
            break;
        case 2:
            return "Carrying DG, HS, or MP, IMO hazard or pollutant category B";
            break;
        case 3:
            return "Carrying DG, HS, or MP, IMO hazard or pollutant category C";
            break;
        case 4:
            return "Carrying DG, HS, or MP, IMO hazard or pollutant category D";
            break;
        case 9:
            return "No additional information";
            break;
        default:
            return value;
            break;
        }
    } // CargoType
    else if (key == "NavStatus") {
        if      ( value == "0" ) {
            value = "Under Way Using Engine";
        } else if ( value == "1" ) {
            value = "At Anchor";
        } else if ( value == "2" ) {
            value = "Not Under Command";
        } else if ( value == "3" ) {
            value = "Restricted Manoevrability";
        } else if ( value == "4" ) {
            value = "Constrained By Draught";
        } else if ( value == "5" ) {
            value = "Moored";
        } else if ( value == "6" ) {
            value = "Aground";
        } else if ( value == "7" ) {
            value = "Engaged In Fishing";
        } else if ( value == "8" ) {
            value = "Under Way Sailing";
        }
    } // key = NavStatus
    else if (key == "UpdSensorType") {
        if ( value == "1" ) {
            value = "Radar";
        } else if ( value == "2" ) {
            value = "AIS";
        } else if ( value == "3" ) {
            value = "Radar and AIS";
        } else if ( value == "4" ) {
            value = "Dead Reckoning";
        }
    } // key = UdpSensorType
    else if ( key == "Source" ) {
        if ( value == "1" ) {
            value = "AIS";
        } else if ( value == "2" ) {
            value = "Database";
        } else if ( value == "3" ) {
            value = "Manual";
        }
    } // key = Source
    else if ( key == "ATONType" ) {
        if ( value == "1" ) {
            value = "Fixed";
        } else if ( value == "2" ) {
            value = "Floating";
        }
    } // key = ATONType

    return value;
}

bool IVEFHandler::startElement (const QString & /* namespaceURI */,
                                const QString & /* localName */,
                                const QString & qName,
                                const QXmlAttributes & atts) {

    std::cout << QString("%1").arg(qName).toLatin1().data() << std::endl;

     for (int i=0; i < atts.length(); i++) {
        QString key = atts.localName(i);
        QString value = this->makeReadableValueForKey(key, atts.value(i));
        std::cout << QString("    %1 = %2").arg(key, value).toLatin1().data() << std::endl;
    }

    return true;
}

bool IVEFHandler::error ( const QXmlParseException & exception ) {

    std::cout << exception.message().toLatin1().data() << std::endl;
    return true;
}
