
#include "IVEFParser.h"

// Constructor
Parser::Parser() {

    // we are a subclass of the parser, and our own delegate
    setContentHandler(this);
    setErrorHandler(this);
}

// Character buffer routine
bool Parser::characters(const QString &ch) {
     m_characterBuffer.append(ch);
     return true;
};
// Parser delegate routine
bool Parser::startElement(const QString &,
     const QString &,
     const QString & qName,
     const QXmlAttributes & atts) {

    m_characterBuffer.clear();

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
                if (! (obj->setName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Value") {
                QString val = value;
                if (! (obj->setValue(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setLang(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Name") {
                QString val = value;
                if (! (obj->setName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setMsgRefId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Version") {
                QString val = value;
                if (! (obj->setVersion(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setEncryption(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Name") {
                QString val = value;
                if (! (obj->setName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Password") {
                QString val = value;
                if (! (obj->setPassword(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setReason(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ResponseOn") {
                QString val = value;
                if (! (obj->setResponseOn(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Result") {
                int val = value.toInt();
                if (! (obj->setResult(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setTimeStamp(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setResponseOn(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                if (! (obj->setSourceId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "TimeStamp") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setTimeStamp(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setAltitude(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "EstAccAlt") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setEstAccAlt(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "EstAccLat") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setEstAccLat(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "EstAccLong") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setEstAccLong(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Lat") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setLat(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Long") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setLong(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setContactIdentity(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Details") {
                QString val = value;
                if (! (obj->setDetails(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Status") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                if (! (obj->setStatus(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Period") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setPeriod(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setDataSelector(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "FieldSelector") {
                QString val = value;
                if (! (obj->setFieldSelector(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setPredicate(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setReason(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ResponseOn") {
                QString val = value;
                if (! (obj->setResponseOn(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Result") {
                int val = value.toInt();
                if (! (obj->setResult(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setKey(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Value") {
                QString val = value;
                if (! (obj->setValue(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setCOG(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "EstAccSOG") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setEstAccSOG(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "EstAccCOG") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setEstAccCOG(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Id") {
                int val = value.toInt();
                if (! (obj->setId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Length") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setLength(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Heading") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setHeading(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ROT") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setROT(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SOG") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setSOG(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceId") {
                QString val = value;
                if (! (obj->setSourceId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceName") {
                QString val = value;
                if (! (obj->setSourceName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTime(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "TrackStatus") {
                int val = value.toInt();
                if (! (obj->setTrackStatus(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Width") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setWidth(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "TrackData" );
    }
    else if (qName == "NavStatus") {
        // create a placeholder
        NavStatus *obj = new NavStatus;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Value") {
                int val = value.toInt();
                if (! (obj->setValue(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "NavStatus" );
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
                if (! (obj->setClass(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "BlackListed") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                if (! (obj->setBlackListed(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Id") {
                int val = value.toInt();
                if (! (obj->setId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SpecialAttention") {
                QString val = value;
                if (! (obj->setSpecialAttention(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceId") {
                QString val = value;
                if (! (obj->setSourceId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceName") {
                QString val = value;
                if (! (obj->setSourceName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceType") {
                int val = value.toInt();
                if (! (obj->setSourceType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTime(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setHullColor(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "HullType") {
                int val = value.toInt();
                if (! (obj->setHullType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "DeadWeight") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setDeadWeight(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "GrossWeight") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setGrossWeight(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Length") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setLength(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "LloydsShipType") {
                int val = value.toInt();
                if (! (obj->setLloydsShipType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "YearOfBuild") {
                int val = value.toInt();
                if (! (obj->setYearOfBuild(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MaxAirDraught") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setMaxAirDraught(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MaxDraught") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setMaxDraught(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MaxPersonsOnBoard") {
                int val = value.toInt();
                if (! (obj->setMaxPersonsOnBoard(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MaxSpeed") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setMaxSpeed(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Width") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setWidth(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setCodeA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "CodeB") {
                int val = value.toInt();
                if (! (obj->setCodeB(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Mode") {
                int val = value.toInt();
                if (! (obj->setMode(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! (obj->setCallsign(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "IMO") {
                int val = value.toInt();
                if (! (obj->setIMO(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Name") {
                QString val = value;
                if (! (obj->setName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "FormerName") {
                QString val = value;
                if (! (obj->setFormerName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Flag") {
                QString val = value;
                if (! (obj->setFlag(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Owner") {
                QString val = value;
                if (! (obj->setOwner(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MMSI") {
                int val = value.toInt();
                if (! (obj->setMMSI(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "LRIT") {
                QString val = value;
                if (! (obj->setLRIT(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setAirDraught(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Id") {
                int val = value.toInt();
                if (! (obj->setId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "CargoTypeIMO") {
                int val = value.toInt();
                if (! (obj->setCargoTypeIMO(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ContactIdentity") {
                QString val = value;
                if (! (obj->setContactIdentity(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "DestCode") {
                QString val = value;
                if (! (obj->setDestCode(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "DestName") {
                QString val = value;
                if (! (obj->setDestName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "DepartCode") {
                QString val = value;
                if (! (obj->setDepartCode(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "DepartName") {
                QString val = value;
                if (! (obj->setDepartName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Draught") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setDraught(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ETA") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setETA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ATD") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setATD(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ISPSLevel") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setISPSLevel(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "OverSizedLength") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setOverSizedLength(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "OverSizedWidth") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setOverSizedWidth(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "PersonsOnBoard") {
                int val = value.toInt();
                if (! (obj->setPersonsOnBoard(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Pilots") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setPilots(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "RouteBound") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                if (! (obj->setRouteBound(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceId") {
                QString val = value;
                if (! (obj->setSourceId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceName") {
                QString val = value;
                if (! (obj->setSourceName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceType") {
                int val = value.toInt();
                if (! (obj->setSourceType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "TankerStatus") {
                int val = value.toInt();
                if (! (obj->setTankerStatus(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Tugs") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                if (! (obj->setTugs(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTime") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTime(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setATA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ETA") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setETA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "RTA") {
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setRTA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "LoCode") {
                QString val = value;
                if (! (obj->setLoCode(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Name") {
                QString val = value;
                if (! (obj->setName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
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
                if (! ((MSG_IVEF*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "ObjectDatas") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ObjectDatas *obj = (ObjectDatas*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setObjectDatas( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Area") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Area *obj = (Area*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                if (! ((ServiceRequest*) ( m_objStack.top() ) )->addArea( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "OtherId") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        OtherId *obj = (OtherId*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Identifier") {
                if (! ((Identifier*) ( m_objStack.top() ) )->addOtherId( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "OtherName") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        OtherName *obj = (OtherName*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Identifier") {
                if (! ((Identifier*) ( m_objStack.top() ) )->addOtherName( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "Header") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Header *obj = (Header*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_IVEF") {
                if (! ((MSG_IVEF*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "LoginRequest") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        LoginRequest *obj = (LoginRequest*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setLoginRequest( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "LoginResponse") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        LoginResponse *obj = (LoginResponse*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setLoginResponse( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Logout") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Logout *obj = (Logout*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setLogout( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "ObjectData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ObjectData *obj = (ObjectData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectDatas") {
                if (! ((ObjectDatas*) ( m_objStack.top() ) )->addObjectData( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "Ping") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Ping *obj = (Ping*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setPing( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Pong") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Pong *obj = (Pong*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setPong( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Pos") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Pos *obj = (Pos*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Area") {
                if (! ((Area*) ( m_objStack.top() ) )->addPos( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "TrackData") {
                if (! ((TrackData*) ( m_objStack.top() ) )->addPos( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Waypoint") {
                if (! ((Waypoint*) ( m_objStack.top() ) )->setPos( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "ServerStatus") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ServerStatus *obj = (ServerStatus*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setServerStatus( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequest") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ServiceRequest *obj = (ServiceRequest*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setServiceRequest( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Transmission") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Transmission *obj = (Transmission*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                if (! ((ServiceRequest*) ( m_objStack.top() ) )->setTransmission( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Item") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Item *obj = (Item*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                if (! ((ServiceRequest*) ( m_objStack.top() ) )->addItem( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "Filter") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Filter *obj = (Filter*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                if (! ((ServiceRequest*) ( m_objStack.top() ) )->setFilter( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "ServiceRequestResponse") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        ServiceRequestResponse *obj = (ServiceRequestResponse*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->setServiceRequestResponse( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "TaggedItem") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        TaggedItem *obj = (TaggedItem*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                if (! ((ObjectData*) ( m_objStack.top() ) )->addTaggedItem( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "TrackData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        TrackData *obj = (TrackData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                if (! ((ObjectData*) ( m_objStack.top() ) )->setTrackData( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "NavStatus") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        NavStatus *obj = (NavStatus*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "TrackData") {
                if (! ((TrackData*) ( m_objStack.top() ) )->addNavStatus( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "VesselData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        VesselData *obj = (VesselData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                if (! ((ObjectData*) ( m_objStack.top() ) )->addVesselData( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "Construction") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Construction *obj = (Construction*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                if (! ((VesselData*) ( m_objStack.top() ) )->setConstruction( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "UnType") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        UnType *obj = (UnType*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Construction") {
                if (! ((Construction*) ( m_objStack.top() ) )->setUnType( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Identifier") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Identifier *obj = (Identifier*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                if (! ((VesselData*) ( m_objStack.top() ) )->setIdentifier( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "VoyageData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        VoyageData *obj = (VoyageData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ObjectData") {
                if (! ((ObjectData*) ( m_objStack.top() ) )->addVoyageData( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "Waypoint") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Waypoint *obj = (Waypoint*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VoyageData") {
                if (! ((VoyageData*) ( m_objStack.top() ) )->addWaypoint( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
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

