
#include "IVEFParser.h"

Parser::Parser() {

    setContentHandler(this);
    setErrorHandler(this);
}

bool Parser::startElement(const QString &,
     const QString &,
     const QString & qName,
     const QXmlAttributes & atts) {

    // check all possible options
    if (qName == "MSG_IVEF") {
        MSG_IVEF *obj = new MSG_IVEF;
        m_objStack.push( obj );
        m_typeStack.push( "MSG_IVEF" );
    }
    else if (qName == "Body") {
        Body *obj = new Body;
        m_objStack.push( obj );
        m_typeStack.push( "Body" );
    }
    else if (qName == "ObjectDatas") {
        ObjectDatas *obj = new ObjectDatas;
        m_objStack.push( obj );
        m_typeStack.push( "ObjectDatas" );
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
        }
        m_objStack.push( obj );
        m_typeStack.push( "Area" );
    }
    else if (qName == "OtherId") {
        OtherId *obj = new OtherId;
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
        m_typeStack.push( "OtherId" );
    }
    else if (qName == "OtherName") {
        OtherName *obj = new OtherName;
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
        m_typeStack.push( "OtherName" );
    }
    else if (qName == "Header") {
        Header *obj = new Header;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "MsgRefId") {
                QString val = value;
                obj->setMsgRefId(val);
            }
            else if (key == "Version") {
                QString val = value;
                obj->setVersion(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Header" );
    }
    else if (qName == "LoginRequest") {
        LoginRequest *obj = new LoginRequest;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Encryption") {
                int val = value.toInt();
                obj->setEncryption(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "Password") {
                QString val = value;
                obj->setPassword(val);
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

            if (key == "Reason") {
                QString val = value;
                obj->setReason(val);
            }
            else if (key == "ResponseOn") {
                QString val = value;
                obj->setResponseOn(val);
            }
            else if (key == "Result") {
                int val = value.toInt();
                obj->setResult(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "LoginResponse" );
    }
    else if (qName == "Logout") {
        Logout *obj = new Logout;
        m_objStack.push( obj );
        m_typeStack.push( "Logout" );
    }
    else if (qName == "ObjectData") {
        ObjectData *obj = new ObjectData;
        m_objStack.push( obj );
        m_typeStack.push( "ObjectData" );
    }
    else if (qName == "Ping") {
        Ping *obj = new Ping;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "TimeStamp") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
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

            if (key == "ResponseOn") {
                QString val = value;
                obj->setResponseOn(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj->setSourceId(val);
            }
            else if (key == "TimeStamp") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setTimeStamp(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Pong" );
    }
    else if (qName == "Pos") {
        Pos *obj = new Pos;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Altitude") {
                float val = value.toFloat();
                obj->setAltitude(val);
            }
            else if (key == "EstAccAlt") {
                float val = value.toFloat();
                obj->setEstAccAlt(val);
            }
            else if (key == "EstAccLat") {
                float val = value.toFloat();
                obj->setEstAccLat(val);
            }
            else if (key == "EstAccLong") {
                float val = value.toFloat();
                obj->setEstAccLong(val);
            }
            else if (key == "Lat") {
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
    else if (qName == "ServerStatus") {
        ServerStatus *obj = new ServerStatus;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "ContactIdentity") {
                QString val = value;
                obj->setContactIdentity(val);
            }
            else if (key == "Details") {
                QString val = value;
                obj->setDetails(val);
            }
            else if (key == "Status") {
                bool val = (value.toUpper() == "YES");
                obj->setStatus(val);
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

            if (key == "DataSelector") {
                int val = value.toInt();
                obj->setDataSelector(val);
            }
            else if (key == "FieldSelector") {
                QString val = value;
                obj->setFieldSelector(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Item" );
    }
    else if (qName == "Filter") {
        Filter *obj = new Filter;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Predicate") {
                QString val = value;
                obj->setPredicate(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Filter" );
    }
    else if (qName == "ServiceRequestResponse") {
        ServiceRequestResponse *obj = new ServiceRequestResponse;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Reason") {
                QString val = value;
                obj->setReason(val);
            }
            else if (key == "ResponseOn") {
                QString val = value;
                obj->setResponseOn(val);
            }
            else if (key == "Result") {
                int val = value.toInt();
                obj->setResult(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequestResponse" );
    }
    else if (qName == "TaggedItem") {
        TaggedItem *obj = new TaggedItem;
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
        }
        m_objStack.push( obj );
        m_typeStack.push( "TaggedItem" );
    }
    else if (qName == "TrackData") {
        TrackData *obj = new TrackData;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "COG") {
                float val = value.toFloat();
                obj->setCOG(val);
            }
            else if (key == "EstAccSOG") {
                float val = value.toFloat();
                obj->setEstAccSOG(val);
            }
            else if (key == "EstAccCOG") {
                float val = value.toFloat();
                obj->setEstAccCOG(val);
            }
            else if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj->setLength(val);
            }
            else if (key == "NavStatus") {
                int val = value.toInt();
                obj->setNavStatus(val);
            }
            else if (key == "Heading") {
                float val = value.toFloat();
                obj->setHeading(val);
            }
            else if (key == "ROT") {
                float val = value.toFloat();
                obj->setROT(val);
            }
            else if (key == "SOG") {
                float val = value.toFloat();
                obj->setSOG(val);
            }
            else if (key == "SourceId") {
                QString val = value;
                obj->setSourceId(val);
            }
            else if (key == "SourceName") {
                QString val = value;
                obj->setSourceName(val);
            }
            else if (key == "UpdateTime") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setUpdateTime(val);
            }
            else if (key == "TrackStatus") {
                int val = value.toInt();
                obj->setTrackStatus(val);
            }
            else if (key == "Width") {
                float val = value.toFloat();
                obj->setWidth(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "TrackData" );
    }
    else if (qName == "VesselData") {
        VesselData *obj = new VesselData;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "Class") {
                int val = value.toInt();
                obj->setClass(val);
            }
            else if (key == "BlackListed") {
                bool val = (value.toUpper() == "YES");
                obj->setBlackListed(val);
            }
            else if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "SpecialAttention") {
                QString val = value;
                obj->setSpecialAttention(val);
            }
            else if (key == "SourceId") {
                QString val = value;
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
            else if (key == "UpdateTime") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setUpdateTime(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "VesselData" );
    }
    else if (qName == "Construction") {
        Construction *obj = new Construction;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "HullColor") {
                QString val = value;
                obj->setHullColor(val);
            }
            else if (key == "HullType") {
                int val = value.toInt();
                obj->setHullType(val);
            }
            else if (key == "Length") {
                float val = value.toFloat();
                obj->setLength(val);
            }
            else if (key == "LloydsShipType") {
                int val = value.toInt();
                obj->setLloydsShipType(val);
            }
            else if (key == "MaxKeelHeight") {
                float val = value.toFloat();
                obj->setMaxKeelHeight(val);
            }
            else if (key == "MaxDraught") {
                float val = value.toFloat();
                obj->setMaxDraught(val);
            }
            else if (key == "MaxPersonsOnBoard") {
                float val = value.toFloat();
                obj->setMaxPersonsOnBoard(val);
            }
            else if (key == "MaxSpeed") {
                float val = value.toFloat();
                obj->setMaxSpeed(val);
            }
            else if (key == "Width") {
                float val = value.toFloat();
                obj->setWidth(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Construction" );
    }
    else if (qName == "UnType") {
        UnType *obj = new UnType;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "CodeA") {
                int val = value.toInt();
                obj->setCodeA(val);
            }
            else if (key == "CodeB") {
                int val = value.toInt();
                obj->setCodeB(val);
            }
            else if (key == "Mode") {
                int val = value.toInt();
                obj->setMode(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "UnType" );
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
            else if (key == "IMO") {
                int val = value.toInt();
                obj->setIMO(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
            else if (key == "MMSI") {
                int val = value.toInt();
                obj->setMMSI(val);
            }
            else if (key == "LRIT") {
                QString val = value;
                obj->setLRIT(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Identifier" );
    }
    else if (qName == "VoyageData") {
        VoyageData *obj = new VoyageData;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "AirDraught") {
                float val = value.toFloat();
                obj->setAirDraught(val);
            }
            else if (key == "Id") {
                int val = value.toInt();
                obj->setId(val);
            }
            else if (key == "CargoTypeIMO") {
                int val = value.toInt();
                obj->setCargoTypeIMO(val);
            }
            else if (key == "ContactIdentity") {
                QString val = value;
                obj->setContactIdentity(val);
            }
            else if (key == "DestCode") {
                QString val = value;
                obj->setDestCode(val);
            }
            else if (key == "DestName") {
                QString val = value;
                obj->setDestName(val);
            }
            else if (key == "Draught") {
                float val = value.toFloat();
                obj->setDraught(val);
            }
            else if (key == "ETA") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setETA(val);
            }
            else if (key == "ISPSLevel") {
                float val = value.toFloat();
                obj->setISPSLevel(val);
            }
            else if (key == "OverSizedLength") {
                float val = value.toFloat();
                obj->setOverSizedLength(val);
            }
            else if (key == "OverSizedWidth") {
                float val = value.toFloat();
                obj->setOverSizedWidth(val);
            }
            else if (key == "NextPort") {
                QString val = value;
                obj->setNextPort(val);
            }
            else if (key == "PersonsOnBoard") {
                float val = value.toFloat();
                obj->setPersonsOnBoard(val);
            }
            else if (key == "Pilots") {
                float val = value.toFloat();
                obj->setPilots(val);
            }
            else if (key == "PrevPort") {
                QString val = value;
                obj->setPrevPort(val);
            }
            else if (key == "RouteBound") {
                bool val = (value.toUpper() == "YES");
                obj->setRouteBound(val);
            }
            else if (key == "SourceId") {
                QString val = value;
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
            else if (key == "TankerStatus") {
                int val = value.toInt();
                obj->setTankerStatus(val);
            }
            else if (key == "Tugs") {
                bool val = (value.toUpper() == "YES");
                obj->setTugs(val);
            }
            else if (key == "UpdateTime") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setUpdateTime(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "VoyageData" );
    }
    else if (qName == "Waypoint") {
        Waypoint *obj = new Waypoint;
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            if (key == "ATA") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setATA(val);
            }
            else if (key == "ETA") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setETA(val);
            }
            else if (key == "RTA") {
                if (value.right(1) == "Z") { // new time encoding
                     value = value.left(value.length() - 1);
                }
                QDateTime val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss.z");
                if (!val.isValid()) { 
                     val = QDateTime::fromString(value, "yyyy-MM-dd'T'HH:mm:ss");
                }
                obj->setRTA(val);
            }
            else if (key == "LoCode") {
                QString val = value;
                obj->setLoCode(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
        }
        m_objStack.push( obj );
        m_typeStack.push( "Waypoint" );
    }
    return true;
}

bool Parser::endElement(const QString &,
     const QString &,
     const QString & qName) {

    // check all possible options
    if (qName == "MSG_IVEF") {

        m_typeStack.pop();
        MSG_IVEF *obj = (MSG_IVEF*) ( m_objStack.pop() );
        emit signalMSG_IVEF( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Body") {

        m_typeStack.pop();
        Body *obj = (Body*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "MSG_IVEF") {
                ((MSG_IVEF*) ( m_objStack.top() ) )->setBody( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ObjectDatas") {

        m_typeStack.pop();
        ObjectDatas *obj = (ObjectDatas*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setObjectDatas( *obj );
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
    else if (qName == "OtherId") {

        m_typeStack.pop();
        OtherId *obj = (OtherId*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Identifier") {
                ((Identifier*) ( m_objStack.top() ) )->addOtherId( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "OtherName") {

        m_typeStack.pop();
        OtherName *obj = (OtherName*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Identifier") {
                ((Identifier*) ( m_objStack.top() ) )->addOtherName( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Header") {

        m_typeStack.pop();
        Header *obj = (Header*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "MSG_IVEF") {
                ((MSG_IVEF*) ( m_objStack.top() ) )->setHeader( *obj );
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
    else if (qName == "Logout") {

        m_typeStack.pop();
        Logout *obj = (Logout*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLogout( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ObjectData") {

        m_typeStack.pop();
        ObjectData *obj = (ObjectData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectDatas") {
                ((ObjectDatas*) ( m_objStack.top() ) )->addObjectData( *obj );
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
    else if (qName == "Pos") {

        m_typeStack.pop();
        Pos *obj = (Pos*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Area") {
                ((Area*) ( m_objStack.top() ) )->addPos( *obj );
        }
        if ( m_typeStack.top() == "TrackData") {
                ((TrackData*) ( m_objStack.top() ) )->addPos( *obj );
        }
        if ( m_typeStack.top() == "Waypoint") {
                ((Waypoint*) ( m_objStack.top() ) )->setPos( *obj );
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
    else if (qName == "Filter") {

        m_typeStack.pop();
        Filter *obj = (Filter*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->setFilter( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequestResponse") {

        m_typeStack.pop();
        ServiceRequestResponse *obj = (ServiceRequestResponse*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setServiceRequestResponse( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "TaggedItem") {

        m_typeStack.pop();
        TaggedItem *obj = (TaggedItem*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addTaggedItem( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "TrackData") {

        m_typeStack.pop();
        TrackData *obj = (TrackData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->setTrackData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "VesselData") {

        m_typeStack.pop();
        VesselData *obj = (VesselData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addVesselData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Construction") {

        m_typeStack.pop();
        Construction *obj = (Construction*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->setConstruction( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "UnType") {

        m_typeStack.pop();
        UnType *obj = (UnType*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "Construction") {
                ((Construction*) ( m_objStack.top() ) )->setUnType( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Identifier") {

        m_typeStack.pop();
        Identifier *obj = (Identifier*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->setIdentifier( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "VoyageData") {

        m_typeStack.pop();
        VoyageData *obj = (VoyageData*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addVoyageData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Waypoint") {

        m_typeStack.pop();
        Waypoint *obj = (Waypoint*) ( m_objStack.pop() );
        if ( m_typeStack.top() == "VoyageData") {
                ((VoyageData*) ( m_objStack.top() ) )->addWaypoint( *obj );
        }
        delete( obj ); 
    }
    return true;
}

bool Parser::parseXMLString(QString data, bool cont) { 

     m_dataBuffer.append(data);

     int index = 0;
     QRegExp rx( "</MSG_IVEF([A-Za-z0-9]+)>");
     while ( (index = rx.indexIn( m_dataBuffer )) != -1 ) {
          int len = index + rx.matchedLength();
          QString message = m_dataBuffer.left(len);
          m_dataBuffer.remove(0, len);
          m_inputForParser.setData(message);
          this->parse(&m_inputForParser, false);
     }
     if (!cont) {
         m_dataBuffer = "";
     }
     return true;
}

QString Parser::composeMessage( const QXmlParseException& exception ) {
    QString errorstr( exception.message() );
    errorstr += " at line " + QString::number(exception.lineNumber());
    errorstr += " (column " + QString::number(exception.columnNumber());
    errorstr += "): " + m_inputForParser.data().section('\n', exception.lineNumber()-1, exception.lineNumber()-1);
    return errorstr;
}

bool Parser::error( const QXmlParseException& exception ) {
    emit signalError( composeMessage( exception ) );
    return QXmlDefaultHandler::error( exception );
}

bool Parser::fatalError( const QXmlParseException& exception ) {
    emit signalError( composeMessage( exception ) );
    return QXmlDefaultHandler::fatalError( exception );
}

bool Parser::warning( const QXmlParseException& exception ) {
    emit signalWarning( composeMessage( exception ) );
    return QXmlDefaultHandler::warning( exception );
}

