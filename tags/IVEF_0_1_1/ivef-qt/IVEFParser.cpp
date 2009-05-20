
#include "IVEFParser.h"

Parser::Parser() {

    setContentHandler(this);
}

bool Parser::startElement(const QString &,
     const QString &,
     const QString & qName,
     const QXmlAttributes & atts) {

    // check all possible options
    if (qName == "Header") {
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
    else if (qName == "MSG_VesselData") {
        MSG_VesselData *obj = new MSG_VesselData;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_VesselData" );
    }
    else if (qName == "Body") {
        Body *obj = new Body;
        m_objStack.push( obj );
        m_typeStack.push( "Body" );
    }
    else if (qName == "VesselData") {
        VesselData *obj = new VesselData;
        m_objStack.push( obj );
        m_typeStack.push( "VesselData" );
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
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss");
                }
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
            else if (key == "Lost") {
                QString val = value;
                obj->setLost(val);
            }
            else if (key == "RateOfTurn") {
                float val = value.toFloat();
                obj->setRateOfTurn(val);
            }
            else if (key == "Orientation") {
                float val = value.toFloat();
                obj->setOrientation(val);
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
            else if (key == "ATONOffPos") {
                bool val = (value.toUpper() == "YES");
                obj->setATONOffPos(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "PosReport" );
    }
    else if (qName == "StaticData") {
        StaticData *obj = new StaticData;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Id") {
                QString val = value;
                obj->setId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj->setSourceName(val);
            }
            else if (key == "Source") {
                int val = value.toInt();
                obj->setSource(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj->setLength(val);
            }
            else if (key == "Breadth") {
                float val = value.toFloat();
                obj->setBreadth(val);
            }
            else if (key == "Callsign") {
                QString val = value;
                obj->setCallsign(val);
            }
            else if (key == "ShipName") {
                QString val = value;
                obj->setShipName(val);
            }
            else if (key == "ObjectType") {
                int val = value.toInt();
                obj->setObjectType(val);
            }
            else if (key == "ShipType") {
                int val = value.toInt();
                obj->setShipType(val);
            }
            else if (key == "IMO") {
                int val = value.toInt();
                obj->setIMO(val);
            }
            else if (key == "MMSI") {
                int val = value.toInt();
                obj->setMMSI(val);
            }
            else if (key == "ATONType") {
                int val = value.toInt();
                obj->setATONType(val);
            }
            else if (key == "ATONName") {
                QString val = value;
                obj->setATONName(val);
            }
            else if (key == "AntPosDistFromFront") {
                float val = value.toFloat();
                obj->setAntPosDistFromFront(val);
            }
            else if (key == "AntPosDistFromLeft") {
                float val = value.toFloat();
                obj->setAntPosDistFromLeft(val);
            }
            else if (key == "NatLangShipName") {
                QString val = value;
                obj->setNatLangShipName(val);
            }
            else if (key == "PortOfRegistry") {
                QString val = value;
                obj->setPortOfRegistry(val);
            }
            else if (key == "CountryFlag") {
                QString val = value;
                obj->setCountryFlag(val);
            }
            else if (key == "MaxAirDraught") {
                float val = value.toFloat();
                obj->setMaxAirDraught(val);
            }
            else if (key == "MaxDraught") {
                float val = value.toFloat();
                obj->setMaxDraught(val);
            }
            else if (key == "DeepWaterVesselind") {
                QString val = value;
                obj->setDeepWaterVesselind(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "StaticData" );
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
            else if (key == "SourceName") {
                QString val = value;
                obj->setSourceName(val);
            }
            else if (key == "Source") {
                int val = value.toInt();
                obj->setSource(val);
            }
            else if (key == "CargoType") {
                int val = value.toInt();
                obj->setCargoType(val);
            }
            else if (key == "Destination") {
                QString val = value;
                obj->setDestination(val);
            }
            else if (key == "ETA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss");
                }
                obj->setETA(val);
            }
            else if (key == "ATA") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss");
                }
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
        }
        m_objStack.push( obj );
        m_typeStack.push( "Voyage" );
    }
    else if (qName == "MSG_LoginRequest") {
        MSG_LoginRequest *obj = new MSG_LoginRequest;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_LoginRequest" );
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
    else if (qName == "MSG_LoginResponse") {
        MSG_LoginResponse *obj = new MSG_LoginResponse;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_LoginResponse" );
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
    else if (qName == "MSG_Ping") {
        MSG_Ping *obj = new MSG_Ping;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Ping" );
    }
    else if (qName == "Ping") {
        Ping *obj = new Ping;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss");
                }
                obj->setTimeStamp(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Ping" );
    }
    else if (qName == "MSG_Pong") {
        MSG_Pong *obj = new MSG_Pong;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Pong" );
    }
    else if (qName == "Pong") {
        Pong *obj = new Pong;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-ddThh:mm:ss");
                }
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
    else if (qName == "MSG_ServerStatus") {
        MSG_ServerStatus *obj = new MSG_ServerStatus;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ServerStatus" );
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
    else if (qName == "MSG_ServiceRequest") {
        MSG_ServiceRequest *obj = new MSG_ServiceRequest;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ServiceRequest" );
    }
    else if (qName == "ServiceRequest") {
        ServiceRequest *obj = new ServiceRequest;
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequest" );
    }
    else if (qName == "Area") {
        Area *obj = new Area;
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

            if (key == "FileName") {
                QString val = value;
                obj->setFileName(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Object" );
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
        }
        m_objStack.push( obj );
        m_typeStack.push( "Pos" );
    }
    return true;
}

bool Parser::endElement(const QString &,
     const QString &,
     const QString & qName) {

    // check all possible options
    if (qName == "Header") {

        m_typeStack.pop();
        Header *obj = (Header*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "MSG_VesselData") {
                ((MSG_VesselData*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_LoginRequest") {
                ((MSG_LoginRequest*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_LoginResponse") {
                ((MSG_LoginResponse*) ( m_objStack.top() ) )->setHeader( *obj );
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
        if ( m_typeStack.top() == "MSG_Logout") {
                ((MSG_Logout*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        if ( m_typeStack.top() == "MSG_ServiceRequest") {
                ((MSG_ServiceRequest*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "MSG_VesselData") {

        m_typeStack.pop();
        MSG_VesselData *obj = (MSG_VesselData*) ( m_objStack.pop() );
        emit signalMSG_VesselData( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Body") {

        m_typeStack.pop();
        Body *obj = (Body*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "MSG_VesselData") {
                ((MSG_VesselData*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_LoginRequest") {
                ((MSG_LoginRequest*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_LoginResponse") {
                ((MSG_LoginResponse*) ( m_objStack.top() ) )->setBody( *obj );
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
        if ( m_typeStack.top() == "MSG_Logout") {
                ((MSG_Logout*) ( m_objStack.top() ) )->setBody( *obj );
        }
        if ( m_typeStack.top() == "MSG_ServiceRequest") {
                ((MSG_ServiceRequest*) ( m_objStack.top() ) )->setBody( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "VesselData") {

        m_typeStack.pop();
        VesselData *obj = (VesselData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->addVesselData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "PosReport") {

        m_typeStack.pop();
        PosReport *obj = (PosReport*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->setPosReport( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "StaticData") {

        m_typeStack.pop();
        StaticData *obj = (StaticData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->addStaticData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Voyage") {

        m_typeStack.pop();
        Voyage *obj = (Voyage*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->addVoyage( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "MSG_LoginRequest") {

        m_typeStack.pop();
        MSG_LoginRequest *obj = (MSG_LoginRequest*) ( m_objStack.pop() );
        emit signalMSG_LoginRequest( *obj ); 
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
    else if (qName == "MSG_LoginResponse") {

        m_typeStack.pop();
        MSG_LoginResponse *obj = (MSG_LoginResponse*) ( m_objStack.pop() );
        emit signalMSG_LoginResponse( *obj ); 
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
    else if (qName == "MSG_Ping") {

        m_typeStack.pop();
        MSG_Ping *obj = (MSG_Ping*) ( m_objStack.pop() );
        emit signalMSG_Ping( *obj ); 
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
    else if (qName == "MSG_Pong") {

        m_typeStack.pop();
        MSG_Pong *obj = (MSG_Pong*) ( m_objStack.pop() );
        emit signalMSG_Pong( *obj ); 
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
    else if (qName == "MSG_ServerStatus") {

        m_typeStack.pop();
        MSG_ServerStatus *obj = (MSG_ServerStatus*) ( m_objStack.pop() );
        emit signalMSG_ServerStatus( *obj ); 
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
    else if (qName == "MSG_ServiceRequest") {

        m_typeStack.pop();
        MSG_ServiceRequest *obj = (MSG_ServiceRequest*) ( m_objStack.pop() );
        emit signalMSG_ServiceRequest( *obj ); 
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
    else if (qName == "Pos") {

        m_typeStack.pop();
        Pos *obj = (Pos*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "PosReport") {
                ((PosReport*) ( m_objStack.top() ) )->setPos( *obj );
        }
        if ( m_typeStack.top() == "Area") {
                ((Area*) ( m_objStack.top() ) )->addPos( *obj );
        }
        delete( obj ); 
    }
    return true;
}

bool Parser::parseXMLString(QString data, bool cont) { 

     m_dataBuffer.append(data);

     int index[8], indexMax = -1;

     // note that if a message does not exist the index will be equal to strlen(name\n) - 1 so indexMax is always > 0
     index[0] = m_dataBuffer.lastIndexOf("</MSG_VesselData>") + strlen("</MSG_VesselData>");
     index[1] = m_dataBuffer.lastIndexOf("</MSG_LoginRequest>") + strlen("</MSG_LoginRequest>");
     index[2] = m_dataBuffer.lastIndexOf("</MSG_LoginResponse>") + strlen("</MSG_LoginResponse>");
     index[3] = m_dataBuffer.lastIndexOf("</MSG_Ping>") + strlen("</MSG_Ping>");
     index[4] = m_dataBuffer.lastIndexOf("</MSG_Pong>") + strlen("</MSG_Pong>");
     index[5] = m_dataBuffer.lastIndexOf("</MSG_ServerStatus>") + strlen("</MSG_ServerStatus>");
     index[6] = m_dataBuffer.lastIndexOf("</MSG_Logout>") + strlen("</MSG_Logout>");
     index[7] = m_dataBuffer.lastIndexOf("</MSG_ServiceRequest>") + strlen("</MSG_ServiceRequest>");
     for (int i=0; i<8; i++) {
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


