
#include "parser.h"

Parser::Parser() {

}

bool Parser::startElement(const QString &,
     const QString &,
     const QString & qName,
     const QXmlAttributes & atts) {

    // check all possible options
    if (qName == "Schema") {
        Schema obj;
        emit signalSchema( obj );
    }
    else if (qName == "Header") {
        Header obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Version") {
                QString val = value;
                obj.setVersion(val);
            }
            else if (key == "MsgRefId") {
                QString val = value;
                obj.setMsgRefId(val);
            }
        }
        emit signalHeader( obj );
    }
    else if (qName == "MSG_VesselData") {
        MSG_VesselData obj;
        emit signalMSG_VesselData( obj );
    }
    else if (qName == "Body") {
        Body obj;
        emit signalBody( obj );
    }
    else if (qName == "VesselData") {
        VesselData obj;
        emit signalVesselData( obj );
    }
    else if (qName == "PosReport") {
        PosReport obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj.setId(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj.setSourceId(val);
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj.setUpdateTime(val);
            }
            else if (key == "SOG") {
                float val = value.toFloat();
                obj.setSOG(val);
            }
            else if (key == "COG") {
                float val = value.toFloat();
                obj.setCOG(val);
            }
            else if (key == "Lost") {
                QString val = value;
                obj.setLost(val);
            }
            else if (key == "RateOfTurn") {
                float val = value.toFloat();
                obj.setRateOfTurn(val);
            }
            else if (key == "Orientation") {
                float val = value.toFloat();
                obj.setOrientation(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj.setLength(val);
            }
            else if (key == "Breadth") {
                float val = value.toFloat();
                obj.setBreadth(val);
            }
            else if (key == "Altitude") {
                float val = value.toFloat();
                obj.setAltitude(val);
            }
            else if (key == "NavStatus") {
                int val = value.toInt();
                obj.setNavStatus(val);
            }
            else if (key == "UpdSensorType") {
                int val = value.toInt();
                obj.setUpdSensorType(val);
            }
            else if (key == "ATONOffPos") {
                bool val = (value.toUpper() == "YES");
                obj.setATONOffPos(val);
            }
        }
        emit signalPosReport( obj );
    }
    else if (qName == "StaticData") {
        StaticData obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj.setId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj.setSourceName(val);
            }
            else if (key == "Source") {
                int val = value.toInt();
                obj.setSource(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj.setLength(val);
            }
            else if (key == "Breadth") {
                float val = value.toFloat();
                obj.setBreadth(val);
            }
            else if (key == "Callsign") {
                QString val = value;
                obj.setCallsign(val);
            }
            else if (key == "ShipName") {
                QString val = value;
                obj.setShipName(val);
            }
            else if (key == "ObjectType") {
                int val = value.toInt();
                obj.setObjectType(val);
            }
            else if (key == "ShipType") {
                int val = value.toInt();
                obj.setShipType(val);
            }
            else if (key == "IMO") {
                int val = value.toInt();
                obj.setIMO(val);
            }
            else if (key == "MMSI") {
                int val = value.toInt();
                obj.setMMSI(val);
            }
            else if (key == "ATONType") {
                int val = value.toInt();
                obj.setATONType(val);
            }
            else if (key == "ATONName") {
                QString val = value;
                obj.setATONName(val);
            }
            else if (key == "AntPosDistFromFront") {
                float val = value.toFloat();
                obj.setAntPosDistFromFront(val);
            }
            else if (key == "AntPosDistFromLeft") {
                float val = value.toFloat();
                obj.setAntPosDistFromLeft(val);
            }
            else if (key == "NatLangShipName") {
                QString val = value;
                obj.setNatLangShipName(val);
            }
            else if (key == "PortOfRegistry") {
                QString val = value;
                obj.setPortOfRegistry(val);
            }
            else if (key == "CountryFlag") {
                QString val = value;
                obj.setCountryFlag(val);
            }
            else if (key == "MaxAirDraught") {
                float val = value.toFloat();
                obj.setMaxAirDraught(val);
            }
            else if (key == "MaxDraught") {
                float val = value.toFloat();
                obj.setMaxDraught(val);
            }
            else if (key == "DeepWaterVesselind") {
                QString val = value;
                obj.setDeepWaterVesselind(val);
            }
        }
        emit signalStaticData( obj );
    }
    else if (qName == "Voyage") {
        Voyage obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                QString val = value;
                obj.setId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj.setSourceName(val);
            }
            else if (key == "Source") {
                int val = value.toInt();
                obj.setSource(val);
            }
            else if (key == "CargoType") {
                int val = value.toInt();
                obj.setCargoType(val);
            }
            else if (key == "Destination") {
                QString val = value;
                obj.setDestination(val);
            }
            else if (key == "ETA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj.setETA(val);
            }
            else if (key == "ATA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj.setATA(val);
            }
            else if (key == "AirDraught") {
                float val = value.toFloat();
                obj.setAirDraught(val);
            }
            else if (key == "Draught") {
                float val = value.toFloat();
                obj.setDraught(val);
            }
        }
        emit signalVoyage( obj );
    }
    else if (qName == "MSG_LoginRequest") {
        MSG_LoginRequest obj;
        emit signalMSG_LoginRequest( obj );
    }
    else if (qName == "LoginRequest") {
        LoginRequest obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Name") {
                QString val = value;
                obj.setName(val);
            }
            else if (key == "Password") {
                QString val = value;
                obj.setPassword(val);
            }
            else if (key == "Encryption") {
                int val = value.toInt();
                obj.setEncryption(val);
            }
        }
        emit signalLoginRequest( obj );
    }
    else if (qName == "MSG_LoginResponse") {
        MSG_LoginResponse obj;
        emit signalMSG_LoginResponse( obj );
    }
    else if (qName == "LoginResponse") {
        LoginResponse obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "MsgId") {
                QString val = value;
                obj.setMsgId(val);
            }
            else if (key == "Result") {
                int val = value.toInt();
                obj.setResult(val);
            }
            else if (key == "Reason") {
                QString val = value;
                obj.setReason(val);
            }
        }
        emit signalLoginResponse( obj );
    }
    else if (qName == "MSG_Ping") {
        MSG_Ping obj;
        emit signalMSG_Ping( obj );
    }
    else if (qName == "Ping") {
        Ping obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj.setTimeStamp(val);
            }
        }
        emit signalPing( obj );
    }
    else if (qName == "MSG_Pong") {
        MSG_Pong obj;
        emit signalMSG_Pong( obj );
    }
    else if (qName == "Pong") {
        Pong obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj.setTimeStamp(val);
            }
            else if (key == "MsgId") {
                QString val = value;
                obj.setMsgId(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj.setSourceId(val);
            }
        }
        emit signalPong( obj );
    }
    else if (qName == "MSG_ServerStatus") {
        MSG_ServerStatus obj;
        emit signalMSG_ServerStatus( obj );
    }
    else if (qName == "ServerStatus") {
        ServerStatus obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Status") {
                QString val = value;
                obj.setStatus(val);
            }
            else if (key == "Details") {
                QString val = value;
                obj.setDetails(val);
            }
        }
        emit signalServerStatus( obj );
    }
    else if (qName == "MSG_Logout") {
        MSG_Logout obj;
        emit signalMSG_Logout( obj );
    }
    else if (qName == "Logout") {
        Logout obj;
        emit signalLogout( obj );
    }
    else if (qName == "MSG_ServiceRequest") {
        MSG_ServiceRequest obj;
        emit signalMSG_ServiceRequest( obj );
    }
    else if (qName == "ServiceRequest") {
        ServiceRequest obj;
        emit signalServiceRequest( obj );
    }
    else if (qName == "Area") {
        Area obj;
        emit signalArea( obj );
    }
    else if (qName == "Transmission") {
        Transmission obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Type") {
                int val = value.toInt();
                obj.setType(val);
            }
            else if (key == "Period") {
                float val = value.toFloat();
                obj.setPeriod(val);
            }
        }
        emit signalTransmission( obj );
    }
    else if (qName == "Item") {
        Item obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Element") {
                int val = value.toInt();
                obj.setElement(val);
            }
            else if (key == "Field") {
                QString val = value;
                obj.setField(val);
            }
        }
        emit signalItem( obj );
    }
    else if (qName == "Object") {
        Object obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "FileName") {
                QString val = value;
                obj.setFileName(val);
            }
        }
        emit signalObject( obj );
    }
    else if (qName == "Pos") {
        Pos obj;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Lat") {
                float val = value.toFloat();
                obj.setLat(val);
            }
            else if (key == "Long") {
                float val = value.toFloat();
                obj.setLong(val);
            }
        }
        emit signalPos( obj );
    }
    return true;
}

