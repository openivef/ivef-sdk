
#include "IVEF2ivef2parser.h"

IVEF2Parser::IVEF2Parser() {

    setContentHandler(this);
}

bool IVEF2Parser::startElement(const QString &,
     const QString &,
     const QString & qName,
     const QXmlAttributes & atts) {

    // check all possible options
    if (qName == "MSG_LoginRequest") {
        MSG_LoginRequest *obj = new MSG_LoginRequest;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_LoginRequest" );
    }
    else if (qName == "Body") {
        Body *obj = new Body;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Forcast") {
                QString val = value;
                obj->setForcast(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Body" );
    }
    else if (qName == "MSG_LoginResponse") {
        MSG_LoginResponse *obj = new MSG_LoginResponse;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_LoginResponse" );
    }
    else if (qName == "MSG_Logout") {
        MSG_Logout *obj = new MSG_Logout;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Logout" );
    }
    else if (qName == "Logout") {
        Logout *obj = new Logout;
        m_objStack.push( obj );
        m_typeStack.push( "Logout" );
    }
    else if (qName == "MSG_ObjectData") {
        MSG_ObjectData *obj = new MSG_ObjectData;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ObjectData" );
    }
    else if (qName == "MSG_Notification") {
        MSG_Notification *obj = new MSG_Notification;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Notification" );
    }
    else if (qName == "Forcast") {
        Forcast *obj = new Forcast;
        m_objStack.push( obj );
        m_typeStack.push( "Forcast" );
    }
    else if (qName == "MSG_Ping") {
        MSG_Ping *obj = new MSG_Ping;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Ping" );
    }
    else if (qName == "MSG_Pong") {
        MSG_Pong *obj = new MSG_Pong;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Pong" );
    }
    else if (qName == "MSG_ServerStatus") {
        MSG_ServerStatus *obj = new MSG_ServerStatus;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ServerStatus" );
    }
    else if (qName == "MSG_ServiceRequest") {
        MSG_ServiceRequest *obj = new MSG_ServiceRequest;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ServiceRequest" );
    }
    else if (qName == "Header") {
        Header *obj = new Header;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Version") {
                QString val = value;
                obj->setVersion(val);
            }
            else if (key == "MsgRefId") {
                QString val = value;
                obj->setMsgRefId(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Header" );
    }
    else if (qName == "ObjectData") {
        ObjectData *obj = new ObjectData;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "ObjectData" );
    }
    else if (qName == "Pos") {
        Pos *obj = new Pos;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Lat") {
                float val = value.toFloat();
                obj->setLat(val);
            }
            else if (key == "Long") {
                float val = value.toFloat();
                obj->setLong(val);
            }
            else if (key == "EstAcc") {
                float val = value.toFloat();
                obj->setEstAcc(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Pos" );
    }
    else if (qName == "PosReport") {
        PosReport *obj = new PosReport;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj->setSourceId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj->setSourceName(val);
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setUpdateTime(val);
            }
            else if (key == "SOG") {
                float val = value.toFloat();
                obj->setSOG(val);
            }
            else if (key == "COG") {
                float val = value.toFloat();
                obj->setCOG(val);
            }
            else if (key == "Orientation") {
                float val = value.toFloat();
                obj->setOrientation(val);
            }
            else if (key == "EstAccSOG") {
                float val = value.toFloat();
                obj->setEstAccSOG(val);
            }
            else if (key == "EstAccCOG") {
                float val = value.toFloat();
                obj->setEstAccCOG(val);
            }
            else if (key == "EstAccOrientation") {
                float val = value.toFloat();
                obj->setEstAccOrientation(val);
            }
            else if (key == "TrackStatus") {
                int val = value.toInt();
                obj->setTrackStatus(val);
            }
            else if (key == "ROT") {
                float val = value.toFloat();
                obj->setROT(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj->setLength(val);
            }
            else if (key == "Breadth") {
                float val = value.toFloat();
                obj->setBreadth(val);
            }
            else if (key == "Altitude") {
                float val = value.toFloat();
                obj->setAltitude(val);
            }
            else if (key == "NavStatus") {
                int val = value.toInt();
                obj->setNavStatus(val);
            }
            else if (key == "UpdSensorType") {
                int val = value.toInt();
                obj->setUpdSensorType(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "PosReport" );
    }
    else if (qName == "Sensor") {
        Sensor *obj = new Sensor;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "SenId") {
                float val = value.toFloat();
                obj->setSenId(val);
            }
            else if (key == "TrkId") {
                float val = value.toFloat();
                obj->setTrkId(val);
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setUpdateTime(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Sensor" );
    }
    else if (qName == "StaticData") {
        StaticData *obj = new StaticData;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj->setSourceId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj->setSourceName(val);
            }
            else if (key == "SourceType") {
                int val = value.toInt();
                obj->setSourceType(val);
            }
            else if (key == "Class") {
                int val = value.toInt();
                obj->setClass(val);
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setUpdateTime(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "StaticData" );
    }
    else if (qName == "Identifier") {
        Identifier *obj = new Identifier;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Callsign") {
                QString val = value;
                obj->setCallsign(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "MMSI") {
                int val = value.toInt();
                obj->setMMSI(val);
            }
            else if (key == "IMO") {
                int val = value.toInt();
                obj->setIMO(val);
            }
            else if (key == "Telephone") {
                int val = value.toInt();
                obj->setTelephone(val);
            }
            else if (key == "SatCom") {
                int val = value.toInt();
                obj->setSatCom(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Identifier" );
    }
    else if (qName == "ForeignName") {
        ForeignName *obj = new ForeignName;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Lang") {
                QString val = value;
                obj->setLang(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "ForeignName" );
    }
    else if (qName == "ForeignId") {
        ForeignId *obj = new ForeignId;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                QString val = value;
                obj->setId(val);
            }
            else if (key == "Value") {
                QString val = value;
                obj->setValue(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "ForeignId" );
    }
    else if (qName == "TaggedItems") {
        TaggedItems *obj = new TaggedItems;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Key") {
                QString val = value;
                obj->setKey(val);
            }
            else if (key == "Value") {
                QString val = value;
                obj->setValue(val);
            }
            else if (key == "Key") {
                QString val = value;
                obj->setKey(val);
            }
            else if (key == "Value") {
                QString val = value;
                obj->setValue(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "TaggedItems" );
    }
    else if (qName == "Construction") {
        Construction *obj = new Construction;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Type") {
                int val = value.toInt();
                obj->setType(val);
            }
            else if (key == "LloydsShipType") {
                int val = value.toInt();
                obj->setLloydsShipType(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj->setLength(val);
            }
            else if (key == "Breadth") {
                float val = value.toFloat();
                obj->setBreadth(val);
            }
            else if (key == "MaxAirDraught") {
                float val = value.toFloat();
                obj->setMaxAirDraught(val);
            }
            else if (key == "MaxDraught") {
                float val = value.toFloat();
                obj->setMaxDraught(val);
            }
            else if (key == "DeepWater") {
                bool val = (value.toUpper() == "YES");
                obj->setDeepWater(val);
            }
            else if (key == "HullMaterial") {
                QString val = value;
                obj->setHullMaterial(val);
            }
            else if (key == "HullColor") {
                QString val = value;
                obj->setHullColor(val);
            }
            else if (key == "Constructor") {
                QString val = value;
                obj->setConstructor(val);
            }
            else if (key == "GrossWeight") {
                float val = value.toFloat();
                obj->setGrossWeight(val);
            }
            else if (key == "NetWeight") {
                float val = value.toFloat();
                obj->setNetWeight(val);
            }
            else if (key == "DeadWeight") {
                float val = value.toFloat();
                obj->setDeadWeight(val);
            }
            else if (key == "MaxPassenger") {
                float val = value.toFloat();
                obj->setMaxPassenger(val);
            }
            else if (key == "MaxCrew") {
                float val = value.toFloat();
                obj->setMaxCrew(val);
            }
            else if (key == "MaxSupport") {
                float val = value.toFloat();
                obj->setMaxSupport(val);
            }
            else if (key == "MaxSpeed") {
                float val = value.toFloat();
                obj->setMaxSpeed(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Construction" );
    }
    else if (qName == "Propulsion") {
        Propulsion *obj = new Propulsion;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Power") {
                float val = value.toFloat();
                obj->setPower(val);
            }
            else if (key == "MainEngine") {
                bool val = (value.toUpper() == "YES");
                obj->setMainEngine(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Propulsion" );
    }
    else if (qName == "Owner") {
        Owner *obj = new Owner;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "PortOfRegistry") {
                QString val = value;
                obj->setPortOfRegistry(val);
            }
            else if (key == "CountryFlag") {
                QString val = value;
                obj->setCountryFlag(val);
            }
            else if (key == "Owner") {
                QString val = value;
                obj->setOwner(val);
            }
            else if (key == "CountryOwner") {
                QString val = value;
                obj->setCountryOwner(val);
            }
            else if (key == "Company") {
                QString val = value;
                obj->setCompany(val);
            }
            else if (key == "HomePort") {
                QString val = value;
                obj->setHomePort(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Owner" );
    }
    else if (qName == "Voyage") {
        Voyage *obj = new Voyage;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                QString val = value;
                obj->setId(val);
            }
            else if (key == "SourceType") {
                int val = value.toInt();
                obj->setSourceType(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj->setSourceId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj->setSourceName(val);
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setUpdateTime(val);
            }
            else if (key == "CargoType") {
                int val = value.toInt();
                obj->setCargoType(val);
            }
            else if (key == "CargoDescr") {
                QString val = value;
                obj->setCargoDescr(val);
            }
            else if (key == "CargoWeight") {
                int val = value.toInt();
                obj->setCargoWeight(val);
            }
            else if (key == "Loaded") {
                bool val = (value.toUpper() == "YES");
                obj->setLoaded(val);
            }
            else if (key == "DestCode") {
                QString val = value;
                obj->setDestCode(val);
            }
            else if (key == "DestName") {
                QString val = value;
                obj->setDestName(val);
            }
            else if (key == "ETA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setETA(val);
            }
            else if (key == "ATA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setATA(val);
            }
            else if (key == "AirDraught") {
                float val = value.toFloat();
                obj->setAirDraught(val);
            }
            else if (key == "Draught") {
                float val = value.toFloat();
                obj->setDraught(val);
            }
            else if (key == "Route") {
                QString val = value;
                obj->setRoute(val);
            }
            else if (key == "PersonsOnBoard") {
                float val = value.toFloat();
                obj->setPersonsOnBoard(val);
            }
            else if (key == "Crew") {
                float val = value.toFloat();
                obj->setCrew(val);
            }
            else if (key == "Passengers") {
                float val = value.toFloat();
                obj->setPassengers(val);
            }
            else if (key == "Support") {
                float val = value.toFloat();
                obj->setSupport(val);
            }
            else if (key == "Tugs") {
                float val = value.toFloat();
                obj->setTugs(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Voyage" );
    }
    else if (qName == "Waypoints") {
        Waypoints *obj = new Waypoints;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "ETA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setETA(val);
            }
            else if (key == "ATA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setATA(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Waypoints" );
    }
    else if (qName == "Alert") {
        Alert *obj = new Alert;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "OffPos") {
                bool val = (value.toUpper() == "YES");
                obj->setOffPos(val);
            }
            else if (key == "PositionError") {
                bool val = (value.toUpper() == "YES");
                obj->setPositionError(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Alert" );
    }
    else if (qName == "LoginRequest") {
        LoginRequest *obj = new LoginRequest;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "Password") {
                QString val = value;
                obj->setPassword(val);
            }
            else if (key == "Encryption") {
                int val = value.toInt();
                obj->setEncryption(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "LoginRequest" );
    }
    else if (qName == "LoginResponse") {
        LoginResponse *obj = new LoginResponse;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "MsgId") {
                QString val = value;
                obj->setMsgId(val);
            }
            else if (key == "Result") {
                int val = value.toInt();
                obj->setResult(val);
            }
            else if (key == "Reason") {
                QString val = value;
                obj->setReason(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "LoginResponse" );
    }
    else if (qName == "Ping") {
        Ping *obj = new Ping;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setTimeStamp(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Ping" );
    }
    else if (qName == "Pong") {
        Pong *obj = new Pong;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setTimeStamp(val);
            }
            else if (key == "MsgId") {
                QString val = value;
                obj->setMsgId(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj->setSourceId(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Pong" );
    }
    else if (qName == "ServerStatus") {
        ServerStatus *obj = new ServerStatus;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Status") {
                QString val = value;
                obj->setStatus(val);
            }
            else if (key == "Details") {
                QString val = value;
                obj->setDetails(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "ServerStatus" );
    }
    else if (qName == "ServiceRequest") {
        ServiceRequest *obj = new ServiceRequest;
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequest" );
    }
    else if (qName == "Area") {
        Area *obj = new Area;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "Color") {
                QString val = value;
                obj->setColor(val);
            }
            else if (key == "Fill") {
                QString val = value;
                obj->setFill(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Area" );
    }
    else if (qName == "Transmission") {
        Transmission *obj = new Transmission;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Type") {
                int val = value.toInt();
                obj->setType(val);
            }
            else if (key == "Period") {
                float val = value.toFloat();
                obj->setPeriod(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Transmission" );
    }
    else if (qName == "Item") {
        Item *obj = new Item;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Element") {
                int val = value.toInt();
                obj->setElement(val);
            }
            else if (key == "Field") {
                QString val = value;
                obj->setField(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Item" );
    }
    else if (qName == "Object") {
        Object *obj = new Object;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "FilterName") {
                QString val = value;
                obj->setFilterName(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Object" );
    }
    else if (qName == "Notification") {
        Notification *obj = new Notification;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "S57Base") {
                bool val = (value.toUpper() == "YES");
                obj->setS57Base(val);
            }
            else if (key == "S57Update") {
                bool val = (value.toUpper() == "YES");
                obj->setS57Update(val);
            }
            else if (key == "XMLChart") {
                bool val = (value.toUpper() == "YES");
                obj->setXMLChart(val);
            }
            else if (key == "HyMe") {
                bool val = (value.toUpper() == "YES");
                obj->setHyMe(val);
            }
            else if (key == "Messages") {
                bool val = (value.toUpper() == "YES");
                obj->setMessages(val);
            }
            else if (key == "Forecast") {
                bool val = (value.toUpper() == "YES");
                obj->setForecast(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Notification" );
    }
    else if (qName == "ServiceRequestResponse") {
        ServiceRequestResponse *obj = new ServiceRequestResponse;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "MsgId") {
                QString val = value;
                obj->setMsgId(val);
            }
            else if (key == "Result") {
                int val = value.toInt();
                obj->setResult(val);
            }
            else if (key == "Reason") {
                QString val = value;
                obj->setReason(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequestResponse" );
    }
    else if (qName == "Chart") {
        Chart *obj = new Chart;
        m_objStack.push( obj );
        m_typeStack.push( "Chart" );
    }
    else if (qName == "S57Chart") {
        S57Chart *obj = new S57Chart;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "BaseChart") {
                bool val = (value.toUpper() == "YES");
                obj->setBaseChart(val);
            }
            else if (key == "Data") {
                obj->setData(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "S57Chart" );
    }
    else if (qName == "XMLChart") {
        XMLChart *obj = new XMLChart;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "XMLChart" );
    }
    else if (qName == "HyMe") {
        HyMe *obj = new HyMe;
        m_objStack.push( obj );
        m_typeStack.push( "HyMe" );
    }
    else if (qName == "Station") {
        Station *obj = new Station;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "Forecast") {
                bool val = (value.toUpper() == "YES");
                obj->setForecast(val);
            }
            else if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setTimeStamp(val);
            }
            else if (key == "Location") {
                QString val = value;
                obj->setLocation(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Station" );
    }
    else if (qName == "Reading") {
        Reading *obj = new Reading;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "Type") {
                int val = value.toInt();
                obj->setType(val);
            }
            else if (key == "Value") {
                float val = value.toFloat();
                obj->setValue(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Reading" );
    }
    else if (qName == "Message") {
        Message *obj = new Message;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.zzz");
                obj->setTimeStamp(val);
            }
            else if (key == "Priority") {
                int val = value.toInt();
                obj->setPriority(val);
            }
            else if (key == "Origin") {
                QString val = value;
                obj->setOrigin(val);
            }
            else if (key == "Destination") {
                QString val = value;
                obj->setDestination(val);
            }
            else if (key == "Text") {
                QString val = value;
                obj->setText(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Message" );
    }
    return true;
}

bool IVEF2Parser::endElement(const QString &,
     const QString &,
     const QString & qName) {

    // check all possible options
    if (qName == "MSG_LoginRequest") {

        m_typeStack.pop();
        MSG_LoginRequest *obj = (MSG_LoginRequest*) ( m_objStack.pop() );
        emit signalMSG_LoginRequest( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Body") {

        m_typeStack.pop();
        Body *obj = (Body*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "MSG_LoginRequest") {
                ((MSG_LoginRequest*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_LoginResponse") {
                ((MSG_LoginResponse*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_Logout") {
                ((MSG_Logout*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_ObjectData") {
                ((MSG_ObjectData*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_Notification") {
                ((MSG_Notification*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_Ping") {
                ((MSG_Ping*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_Pong") {
                ((MSG_Pong*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_ServerStatus") {
                ((MSG_ServerStatus*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_ServiceRequest") {
                ((MSG_ServiceRequest*) ( m_objStack.top() ) )->setBody( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "MSG_LoginResponse") {

        m_typeStack.pop();
        MSG_LoginResponse *obj = (MSG_LoginResponse*) ( m_objStack.pop() );
        emit signalMSG_LoginResponse( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_Logout") {

        m_typeStack.pop();
        MSG_Logout *obj = (MSG_Logout*) ( m_objStack.pop() );
        emit signalMSG_Logout( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Logout") {

        m_typeStack.pop();
        Logout *obj = (Logout*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLogout( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "MSG_ObjectData") {

        m_typeStack.pop();
        MSG_ObjectData *obj = (MSG_ObjectData*) ( m_objStack.pop() );
        emit signalMSG_ObjectData( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_Notification") {

        m_typeStack.pop();
        MSG_Notification *obj = (MSG_Notification*) ( m_objStack.pop() );
        emit signalMSG_Notification( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Forcast") {

        m_typeStack.pop();
        Forcast *obj = (Forcast*) ( m_objStack.pop() );
        emit signalForcast( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_Ping") {

        m_typeStack.pop();
        MSG_Ping *obj = (MSG_Ping*) ( m_objStack.pop() );
        emit signalMSG_Ping( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_Pong") {

        m_typeStack.pop();
        MSG_Pong *obj = (MSG_Pong*) ( m_objStack.pop() );
        emit signalMSG_Pong( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_ServerStatus") {

        m_typeStack.pop();
        MSG_ServerStatus *obj = (MSG_ServerStatus*) ( m_objStack.pop() );
        emit signalMSG_ServerStatus( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_ServiceRequest") {

        m_typeStack.pop();
        MSG_ServiceRequest *obj = (MSG_ServiceRequest*) ( m_objStack.pop() );
        emit signalMSG_ServiceRequest( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Header") {

        m_typeStack.pop();
        Header *obj = (Header*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "MSG_LoginRequest") {
                ((MSG_LoginRequest*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_LoginResponse") {
                ((MSG_LoginResponse*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_Logout") {
                ((MSG_Logout*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_ObjectData") {
                ((MSG_ObjectData*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_Notification") {
                ((MSG_Notification*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_Ping") {
                ((MSG_Ping*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_Pong") {
                ((MSG_Pong*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_ServerStatus") {
                ((MSG_ServerStatus*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_ServiceRequest") {
                ((MSG_ServiceRequest*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ObjectData") {

        m_typeStack.pop();
        ObjectData *obj = (ObjectData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->addObjectData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Pos") {

        m_typeStack.pop();
        Pos *obj = (Pos*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "PosReport") {
                ((PosReport*) ( m_objStack.top() ) )->setPos( *obj );
        }
        if ( m_typeStack.top() == "Waypoints") {
                ((Waypoints*) ( m_objStack.top() ) )->setPos( *obj );
        }
        if ( m_typeStack.top() == "Area") {
                ((Area*) ( m_objStack.top() ) )->addPos( *obj );
        }
        if ( m_typeStack.top() == "Area") {
                ((Area*) ( m_objStack.top() ) )->addPos( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "PosReport") {

        m_typeStack.pop();
        PosReport *obj = (PosReport*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addPosReport( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Sensor") {

        m_typeStack.pop();
        Sensor *obj = (Sensor*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "PosReport") {
                ((PosReport*) ( m_objStack.top() ) )->addSensor( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "StaticData") {

        m_typeStack.pop();
        StaticData *obj = (StaticData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addStaticData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Identifier") {

        m_typeStack.pop();
        Identifier *obj = (Identifier*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "StaticData") {
                ((StaticData*) ( m_objStack.top() ) )->setIdentifier( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ForeignName") {

        m_typeStack.pop();
        ForeignName *obj = (ForeignName*) ( m_objStack.pop() );
        delete( obj ); 
    }
    else if (qName == "ForeignId") {

        m_typeStack.pop();
        ForeignId *obj = (ForeignId*) ( m_objStack.pop() );
        delete( obj ); 
    }
    else if (qName == "TaggedItems") {

        m_typeStack.pop();
        TaggedItems *obj = (TaggedItems*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "StaticData") {
                ((StaticData*) ( m_objStack.top() ) )->addTaggedItems( *obj );
        }
        if ( m_typeStack.top() == "Voyage") {
                ((Voyage*) ( m_objStack.top() ) )->addTaggedItems( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Construction") {

        m_typeStack.pop();
        Construction *obj = (Construction*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "StaticData") {
                ((StaticData*) ( m_objStack.top() ) )->setConstruction( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Propulsion") {

        m_typeStack.pop();
        Propulsion *obj = (Propulsion*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "StaticData") {
                ((StaticData*) ( m_objStack.top() ) )->addPropulsion( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Owner") {

        m_typeStack.pop();
        Owner *obj = (Owner*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "StaticData") {
                ((StaticData*) ( m_objStack.top() ) )->setOwner( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Voyage") {

        m_typeStack.pop();
        Voyage *obj = (Voyage*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addVoyage( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Waypoints") {

        m_typeStack.pop();
        Waypoints *obj = (Waypoints*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Voyage") {
                ((Voyage*) ( m_objStack.top() ) )->addWaypoints( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Alert") {

        m_typeStack.pop();
        Alert *obj = (Alert*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "PosReport") {
                ((PosReport*) ( m_objStack.top() ) )->addAlert( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "LoginRequest") {

        m_typeStack.pop();
        LoginRequest *obj = (LoginRequest*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLoginRequest( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "LoginResponse") {

        m_typeStack.pop();
        LoginResponse *obj = (LoginResponse*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLoginResponse( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Ping") {

        m_typeStack.pop();
        Ping *obj = (Ping*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setPing( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Pong") {

        m_typeStack.pop();
        Pong *obj = (Pong*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setPong( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServerStatus") {

        m_typeStack.pop();
        ServerStatus *obj = (ServerStatus*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setServerStatus( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequest") {

        m_typeStack.pop();
        ServiceRequest *obj = (ServiceRequest*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setServiceRequest( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Area") {

        m_typeStack.pop();
        Area *obj = (Area*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->addArea( *obj );
        }
        if ( m_typeStack.top() == "XMLChart") {
                ((XMLChart*) ( m_objStack.top() ) )->addArea( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Transmission") {

        m_typeStack.pop();
        Transmission *obj = (Transmission*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->setTransmission( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Item") {

        m_typeStack.pop();
        Item *obj = (Item*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->addItem( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Object") {

        m_typeStack.pop();
        Object *obj = (Object*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->addObject( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Notification") {

        m_typeStack.pop();
        Notification *obj = (Notification*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->setNotification( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequestResponse") {

        m_typeStack.pop();
        ServiceRequestResponse *obj = (ServiceRequestResponse*) ( m_objStack.pop() );
        emit signalServiceRequestResponse( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Chart") {

        m_typeStack.pop();
        Chart *obj = (Chart*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->addChart( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "S57Chart") {

        m_typeStack.pop();
        S57Chart *obj = (S57Chart*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Chart") {
                ((Chart*) ( m_objStack.top() ) )->addS57Chart( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "XMLChart") {

        m_typeStack.pop();
        XMLChart *obj = (XMLChart*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Chart") {
                ((Chart*) ( m_objStack.top() ) )->addXMLChart( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "HyMe") {

        m_typeStack.pop();
        HyMe *obj = (HyMe*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->addHyMe( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Station") {

        m_typeStack.pop();
        Station *obj = (Station*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "HyMe") {
                ((HyMe*) ( m_objStack.top() ) )->addStation( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Reading") {

        m_typeStack.pop();
        Reading *obj = (Reading*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Station") {
                ((Station*) ( m_objStack.top() ) )->addReading( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Message") {

        m_typeStack.pop();
        Message *obj = (Message*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->addMessage( *obj );
        }
        delete( obj ); 
    }
    return true;
}

bool IVEF2Parser::parseXMLString(QString data, bool cont) { 

     m_dataBuffer.append(data);

     int index[11], indexMax = -1;

     // note that if a message does not exist the index will be equal to strlen(name\n) - 1 so indexMax is always > 0
     index[0] = m_dataBuffer.lastIndexOf("</MSG_LoginRequest>\n") + strlen("</MSG_LoginRequest>\n");
     index[1] = m_dataBuffer.lastIndexOf("</MSG_LoginResponse>\n") + strlen("</MSG_LoginResponse>\n");
     index[2] = m_dataBuffer.lastIndexOf("</MSG_Logout>\n") + strlen("</MSG_Logout>\n");
     index[3] = m_dataBuffer.lastIndexOf("</MSG_ObjectData>\n") + strlen("</MSG_ObjectData>\n");
     index[4] = m_dataBuffer.lastIndexOf("</MSG_Notification>\n") + strlen("</MSG_Notification>\n");
     index[5] = m_dataBuffer.lastIndexOf("</Forcast>\n") + strlen("</Forcast>\n");
     index[6] = m_dataBuffer.lastIndexOf("</MSG_Ping>\n") + strlen("</MSG_Ping>\n");
     index[7] = m_dataBuffer.lastIndexOf("</MSG_Pong>\n") + strlen("</MSG_Pong>\n");
     index[8] = m_dataBuffer.lastIndexOf("</MSG_ServerStatus>\n") + strlen("</MSG_ServerStatus>\n");
     index[9] = m_dataBuffer.lastIndexOf("</MSG_ServiceRequest>\n") + strlen("</MSG_ServiceRequest>\n");
     index[10] = m_dataBuffer.lastIndexOf("</ServiceRequestResponse>\n") + strlen("</ServiceRequestResponse>\n");
     for (int i=0; i<11; i++) {
         if (index[i] > indexMax) {
             indexMax = index[i];
         }
     }

     if (indexMax > 30) {
         QString messages = m_dataBuffer.left(indexMax);
         m_dataBuffer.remove(0, indexMax);
         QXmlInputSource inputForParser;
         inputForParser.setData(messages);
         this->parse(&inputForParser, false);
     } else {
         return false; // not enough data in string
     }
     if (!cont) {
         m_dataBuffer = "";
     }
     return true;
}


