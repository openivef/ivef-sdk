
#include "IVEFParser.h"

// Constructor
Parser::Parser() {

    // we are a subclass of the parser, and our own delegate
    setContentHandler(this);
    setErrorHandler(this);
}

// Parser delegate routine
bool Parser::startElement(const QString &,
     const QString &,
     const QString & qName,
     const QXmlAttributes & atts) {

    // check all possible options
    if (qName == "MSG_IVEF") {
        // create a placeholder
        MSG_IVEF *obj = new MSG_IVEF;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_IVEF" );
    }
    else if (qName == "Body") {
        // create a placeholder
        Body *obj = new Body;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Body" );
    }
    else if (qName == "ObjectDatas") {
        // create a placeholder
        ObjectDatas *obj = new ObjectDatas;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ObjectDatas" );
    }
    else if (qName == "Area") {
        // create a placeholder
        Area *obj = new Area;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Area" );
    }
    else if (qName == "OtherId") {
        // create a placeholder
        OtherId *obj = new OtherId;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Id") {
                QString val = value;
                obj->setId(val);
            }
            else if (key == "Value") {
                QString val = value;
                obj->setValue(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "OtherId" );
    }
    else if (qName == "OtherName") {
        // create a placeholder
        OtherName *obj = new OtherName;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Lang") {
                QString val = value;
                obj->setLang(val);
            }
            else if (key == "Name") {
                QString val = value;
                obj->setName(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "OtherName" );
    }
    else if (qName == "Header") {
        // create a placeholder
        Header *obj = new Header;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "MsgRefId") {
                QString val = value;
                obj->setMsgRefId(val);
            }
            else if (key == "Version") {
                QString val = value;
                obj->setVersion(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Header" );
    }
    else if (qName == "LoginRequest") {
        // create a placeholder
        LoginRequest *obj = new LoginRequest;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "LoginRequest" );
    }
    else if (qName == "LoginResponse") {
        // create a placeholder
        LoginResponse *obj = new LoginResponse;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "LoginResponse" );
    }
    else if (qName == "Logout") {
        // create a placeholder
        Logout *obj = new Logout;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Logout" );
    }
    else if (qName == "ObjectData") {
        // create a placeholder
        ObjectData *obj = new ObjectData;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ObjectData" );
    }
    else if (qName == "Ping") {
        // create a placeholder
        Ping *obj = new Ping;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "TimeStamp") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                obj->setTimeStamp(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Ping" );
    }
    else if (qName == "Pong") {
        // create a placeholder
        Pong *obj = new Pong;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "ResponseOn") {
                QString val = value;
                obj->setResponseOn(val);
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                obj->setSourceId(val);
            }
            else if (key == "TimeStamp") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                obj->setTimeStamp(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Pong" );
    }
    else if (qName == "Pos") {
        // create a placeholder
        Pos *obj = new Pos;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Pos" );
    }
    else if (qName == "ServerStatus") {
        // create a placeholder
        ServerStatus *obj = new ServerStatus;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "ContactIdentity") {
                QString val = value;
                obj->setContactIdentity(val);
            }
            else if (key == "Details") {
                QString val = value;
                obj->setDetails(val);
            }
            else if (key == "Status") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                obj->setStatus(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ServerStatus" );
    }
    else if (qName == "ServiceRequest") {
        // create a placeholder
        ServiceRequest *obj = new ServiceRequest;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequest" );
    }
    else if (qName == "Transmission") {
        // create a placeholder
        Transmission *obj = new Transmission;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Type") {
                int val = value.toInt();
                obj->setType(val);
            }
            else if (key == "Period") {
                float val = value.toFloat();
                obj->setPeriod(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Transmission" );
    }
    else if (qName == "Item") {
        // create a placeholder
        Item *obj = new Item;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "DataSelector") {
                int val = value.toInt();
                obj->setDataSelector(val);
            }
            else if (key == "FieldSelector") {
                QString val = value;
                obj->setFieldSelector(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Item" );
    }
    else if (qName == "Filter") {
        // create a placeholder
        Filter *obj = new Filter;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Predicate") {
                QString val = value;
                obj->setPredicate(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Filter" );
    }
    else if (qName == "ServiceRequestResponse") {
        // create a placeholder
        ServiceRequestResponse *obj = new ServiceRequestResponse;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequestResponse" );
    }
    else if (qName == "TaggedItem") {
        // create a placeholder
        TaggedItem *obj = new TaggedItem;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Key") {
                QString val = value;
                obj->setKey(val);
            }
            else if (key == "Value") {
                QString val = value;
                obj->setValue(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "TaggedItem" );
    }
    else if (qName == "TrackData") {
        // create a placeholder
        TrackData *obj = new TrackData;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "TrackData" );
    }
    else if (qName == "VesselData") {
        // create a placeholder
        VesselData *obj = new VesselData;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Class") {
                int val = value.toInt();
                obj->setClass(val);
            }
            else if (key == "BlackListed") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
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
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                obj->setUpdateTime(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "VesselData" );
    }
    else if (qName == "Construction") {
        // create a placeholder
        Construction *obj = new Construction;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Construction" );
    }
    else if (qName == "UnType") {
        // create a placeholder
        UnType *obj = new UnType;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "UnType" );
    }
    else if (qName == "Identifier") {
        // create a placeholder
        Identifier *obj = new Identifier;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Identifier" );
    }
    else if (qName == "VoyageData") {
        // create a placeholder
        VoyageData *obj = new VoyageData;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
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
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
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
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
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
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                obj->setTugs(val);
            }
            else if (key == "UpdateTime") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                obj->setUpdateTime(val);
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "VoyageData" );
    }
    else if (qName == "Waypoint") {
        // create a placeholder
        Waypoint *obj = new Waypoint;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "ATA") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                obj->setATA(val);
            }
            else if (key == "ETA") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                obj->setETA(val);
            }
            else if (key == "RTA") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
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
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Waypoint" );
    }
    return true;
}

// Parser delegate routine
bool Parser::endElement(const QString &,
     const QString &,
     const QString & qName) {

    // check all possible options
    if (qName == "MSG_IVEF") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_IVEF *obj = (MSG_IVEF*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_IVEF( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Body") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Body *obj = (Body*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_IVEF") {
                ((MSG_IVEF*) ( m_objStack.top() ) )->setBody( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ObjectDatas") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ObjectDatas *obj = (ObjectDatas*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setObjectDatas( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Area") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Area *obj = (Area*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->addArea( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "OtherId") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        OtherId *obj = (OtherId*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Identifier") {
                ((Identifier*) ( m_objStack.top() ) )->addOtherId( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "OtherName") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        OtherName *obj = (OtherName*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Identifier") {
                ((Identifier*) ( m_objStack.top() ) )->addOtherName( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Header") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Header *obj = (Header*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_IVEF") {
                ((MSG_IVEF*) ( m_objStack.top() ) )->setHeader( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "LoginRequest") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        LoginRequest *obj = (LoginRequest*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLoginRequest( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "LoginResponse") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        LoginResponse *obj = (LoginResponse*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLoginResponse( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Logout") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Logout *obj = (Logout*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setLogout( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ObjectData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ObjectData *obj = (ObjectData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectDatas") {
                ((ObjectDatas*) ( m_objStack.top() ) )->addObjectData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Ping") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Ping *obj = (Ping*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setPing( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Pong") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Pong *obj = (Pong*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setPong( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Pos") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Pos *obj = (Pos*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Area") {
                ((Area*) ( m_objStack.top() ) )->addPos( *obj );
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "TrackData") {
                ((TrackData*) ( m_objStack.top() ) )->addPos( *obj );
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Waypoint") {
                ((Waypoint*) ( m_objStack.top() ) )->setPos( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServerStatus") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ServerStatus *obj = (ServerStatus*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setServerStatus( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequest") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ServiceRequest *obj = (ServiceRequest*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setServiceRequest( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Transmission") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Transmission *obj = (Transmission*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->setTransmission( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Item") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Item *obj = (Item*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->addItem( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Filter") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Filter *obj = (Filter*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                ((ServiceRequest*) ( m_objStack.top() ) )->setFilter( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequestResponse") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ServiceRequestResponse *obj = (ServiceRequestResponse*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                ((Body*) ( m_objStack.top() ) )->setServiceRequestResponse( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "TaggedItem") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        TaggedItem *obj = (TaggedItem*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addTaggedItem( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "TrackData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        TrackData *obj = (TrackData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->setTrackData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "VesselData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        VesselData *obj = (VesselData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addVesselData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Construction") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Construction *obj = (Construction*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->setConstruction( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "UnType") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        UnType *obj = (UnType*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Construction") {
                ((Construction*) ( m_objStack.top() ) )->setUnType( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Identifier") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Identifier *obj = (Identifier*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                ((VesselData*) ( m_objStack.top() ) )->setIdentifier( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "VoyageData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        VoyageData *obj = (VoyageData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                ((ObjectData*) ( m_objStack.top() ) )->addVoyageData( *obj );
        }
        delete( obj ); 
    }
    else if (qName == "Waypoint") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Waypoint *obj = (Waypoint*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VoyageData") {
                ((VoyageData*) ( m_objStack.top() ) )->addWaypoint( *obj );
        }
        delete( obj ); 
    }
    return true;
}

// the actual parsing routine
bool Parser::parseXMLString(QString data, bool cont) { 

     // add the data to what was left over from a previous parse run
     m_dataBuffer.append(data);

     // search the buffer for the nearest closetag
     int index = 0;
     QRegExp rx( "</MSG_IVEF([A-Za-z0-9]*)>");
     // parse the messages in the buffer one by one
     while ( (index = rx.indexIn( m_dataBuffer )) != -1 ) {
          int len = index + rx.matchedLength();
          QString message = m_dataBuffer.left(len);
          m_dataBuffer.remove(0, len);
          m_inputForParser.setData(message);
          this->parse(&m_inputForParser, false);
     }
     // we finished parsing, check if we should keep possible
     // partial messages in the buffer
     if (!cont) {
         m_dataBuffer = "";
     }
     return true;
}

// helper routine to make a readable error report
QString Parser::composeMessage( const QXmlParseException& exception ) {
    QString errorstr( exception.message() );
    errorstr += " at line " + QString::number(exception.lineNumber());
    errorstr += " (column " + QString::number(exception.columnNumber());
    errorstr += "): " + m_inputForParser.data().section('\n', exception.lineNumber()-1, exception.lineNumber()-1);
    return errorstr;
}

// parser delegate method to turn parser errors in readable messages
bool Parser::error( const QXmlParseException& exception ) {
    emit signalError( composeMessage( exception ) );
    return QXmlDefaultHandler::error( exception );
}

// parser delegate method to turn parser errors in readable messages
bool Parser::fatalError( const QXmlParseException& exception ) {
    emit signalError( composeMessage( exception ) );
    return QXmlDefaultHandler::fatalError( exception );
}

// parser delegate method to turn parser errors in readable messages
bool Parser::warning( const QXmlParseException& exception ) {
    emit signalWarning( composeMessage( exception ) );
    return QXmlDefaultHandler::warning( exception );
}

