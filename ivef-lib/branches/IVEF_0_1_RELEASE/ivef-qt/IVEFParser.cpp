
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
    if (qName == "MSG_LoginRequest") {
        // create a placeholder
        MSG_LoginRequest *obj = new MSG_LoginRequest;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_LoginRequest" );
    }
    else if (qName == "Body") {
        // create a placeholder
        Body *obj = new Body;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Body" );
    }
    else if (qName == "MSG_LoginResponse") {
        // create a placeholder
        MSG_LoginResponse *obj = new MSG_LoginResponse;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_LoginResponse" );
    }
    else if (qName == "MSG_Logout") {
        // create a placeholder
        MSG_Logout *obj = new MSG_Logout;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Logout" );
    }
    else if (qName == "Logout") {
        // create a placeholder
        Logout *obj = new Logout;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Logout" );
    }
    else if (qName == "MSG_Ping") {
        // create a placeholder
        MSG_Ping *obj = new MSG_Ping;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Ping" );
    }
    else if (qName == "MSG_Pong") {
        // create a placeholder
        MSG_Pong *obj = new MSG_Pong;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_Pong" );
    }
    else if (qName == "MSG_ServerStatus") {
        // create a placeholder
        MSG_ServerStatus *obj = new MSG_ServerStatus;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ServerStatus" );
    }
    else if (qName == "MSG_ServiceRequest") {
        // create a placeholder
        MSG_ServiceRequest *obj = new MSG_ServiceRequest;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_ServiceRequest" );
    }
    else if (qName == "MSG_VesselData") {
        // create a placeholder
        MSG_VesselData *obj = new MSG_VesselData;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "MSG_VesselData" );
    }
    else if (qName == "Header") {
        // create a placeholder
        Header *obj = new Header;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Version") {
                QString val = value;
                if (! (obj->setVersion(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MsgRefId") {
                QString val = value;
                if (! (obj->setMsgRefId(val) )) {
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
            if (key == "Name") {
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
            else if (key == "Encryption") {
                int val = value.toInt();
                if (! (obj->setEncryption(val) )) {
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
            if (key == "MsgId") {
                QString val = value;
                if (! (obj->setMsgId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Result") {
                int val = value.toInt();
                if (! (obj->setResult(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Reason") {
                QString val = value;
                if (! (obj->setReason(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "LoginResponse" );
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
            if (key == "TimeStamp") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setTimeStamp(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MsgId") {
                QString val = value;
                if (! (obj->setMsgId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                if (! (obj->setSourceId(val) )) {
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
            if (key == "Lat") {
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
    else if (qName == "PosReport") {
        // create a placeholder
        PosReport *obj = new PosReport;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Id") {
                int val = value.toInt();
                if (! (obj->setId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SourceId") {
                int val = value.toInt();
                if (! (obj->setSourceId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTime") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTime(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTimeRadar") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTimeRadar(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTimeAIS") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTimeAIS(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdateTimeDR") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setUpdateTimeDR(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "SOG") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setSOG(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "COG") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setCOG(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Lost") {
                QString val = value;
                if (! (obj->setLost(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "RateOfTurn") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setRateOfTurn(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Orientation") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setOrientation(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Length") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setLength(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Breadth") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setBreadth(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Altitude") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setAltitude(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "NavStatus") {
                int val = value.toInt();
                if (! (obj->setNavStatus(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "UpdSensorType") {
                int val = value.toInt();
                if (! (obj->setUpdSensorType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ATONOffPos") {
                // booleans are sent as YES/NO, TRUE/FALSE or 1/0 textstrings 
                bool val = (value.toUpper() == "YES" ||
                            value.toUpper() == "TRUE" ||
                            value == "1");
                if (! (obj->setATONOffPos(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "PosReport" );
    }
    else if (qName == "Sensor") {
        // create a placeholder
        Sensor *obj = new Sensor;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "SenId") {
                int val = value.toInt();
                if (! (obj->setSenId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "TrkId") {
                int val = value.toInt();
                if (! (obj->setTrkId(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Sensor" );
    }
    else if (qName == "StaticData") {
        // create a placeholder
        StaticData *obj = new StaticData;
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
            else if (key == "SourceName") {
                QString val = value;
                if (! (obj->setSourceName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Source") {
                int val = value.toInt();
                if (! (obj->setSource(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Length") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setLength(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Breadth") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setBreadth(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Callsign") {
                QString val = value;
                if (! (obj->setCallsign(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ShipName") {
                QString val = value;
                if (! (obj->setShipName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ObjectType") {
                int val = value.toInt();
                if (! (obj->setObjectType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ShipType") {
                int val = value.toInt();
                if (! (obj->setShipType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "IMO") {
                int val = value.toInt();
                if (! (obj->setIMO(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "MMSI") {
                int val = value.toInt();
                if (! (obj->setMMSI(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ATONType") {
                int val = value.toInt();
                if (! (obj->setATONType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ATONName") {
                QString val = value;
                if (! (obj->setATONName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "AntPosDistFromFront") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setAntPosDistFromFront(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "AntPosDistFromLeft") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setAntPosDistFromLeft(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "NatLangShipName") {
                QString val = value;
                if (! (obj->setNatLangShipName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "PortOfRegistry") {
                QString val = value;
                if (! (obj->setPortOfRegistry(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "CountryFlag") {
                QString val = value;
                if (! (obj->setCountryFlag(val) )) {
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
            else if (key == "DeepWaterVesselind") {
                QString val = value;
                if (! (obj->setDeepWaterVesselind(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "StaticData" );
    }
    else if (qName == "ServerStatus") {
        // create a placeholder
        ServerStatus *obj = new ServerStatus;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "Status") {
                QString val = value;
                if (! (obj->setStatus(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Details") {
                QString val = value;
                if (! (obj->setDetails(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ServerStatus" );
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
    else if (qName == "ServiceRequest") {
        // create a placeholder
        ServiceRequest *obj = new ServiceRequest;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "ServiceRequest" );
    }
    else if (qName == "Area") {
        // create a placeholder
        Area *obj = new Area;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Area" );
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
            if (key == "Element") {
                int val = value.toInt();
                if (! (obj->setElement(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Field") {
                QString val = value;
                if (! (obj->setField(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Item" );
    }
    else if (qName == "Object") {
        // create a placeholder
        Object *obj = new Object;
        // examine all supplied attributes
        for (int i=0; i < atts.length(); i++) {
            QString key = atts.localName(i);
            QString value = atts.value(i);

            // and add them if we know them
            if (key == "FileName") {
                QString val = value;
                if (! (obj->setFileName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Object" );
    }
    else if (qName == "VesselData") {
        // create a placeholder
        VesselData *obj = new VesselData;
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "VesselData" );
    }
    else if (qName == "Voyage") {
        // create a placeholder
        Voyage *obj = new Voyage;
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
            else if (key == "SourceName") {
                QString val = value;
                if (! (obj->setSourceName(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Source") {
                int val = value.toInt();
                if (! (obj->setSource(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "CargoType") {
                int val = value.toInt();
                if (! (obj->setCargoType(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Destination") {
                QString val = value;
                if (! (obj->setDestination(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ETA") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setETA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "ATA") {
                // date encoding should end on a Z, but some suppliers may exclude it
                // we can be robust by checking for it
                if (value.right(1) != "Z") { // new time encoding
                     value.append("Z");
                }
                QDateTime val = QDateTime::fromString(value, Qt::ISODate);
                if (! (obj->setATA(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "PersonsOnBoard") {
                int val = value.toInt();
                if (! (obj->setPersonsOnBoard(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "AirDraught") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setAirDraught(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
            else if (key == "Draught") {
                float val = value.replace(",", ".").toFloat();
                if (! (obj->setDraught(val) )) {
                    emit signalValidationError( "Error for " + key + " = " + value );
                }
            }
        }
        // push the new object on the stack, on a close element we will pop it
        m_objStack.push( obj );
        m_typeStack.push( "Voyage" );
    }
    return true;
}

// Parser delegate routine
bool Parser::endElement(const QString &,
     const QString &,
     const QString & qName) {

    // check all possible options
    if (qName == "MSG_LoginRequest") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_LoginRequest *obj = (MSG_LoginRequest*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_LoginRequest( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Body") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Body *obj = (Body*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_LoginRequest") {
                if (! ((MSG_LoginRequest*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_LoginResponse") {
                if (! ((MSG_LoginResponse*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_Logout") {
                if (! ((MSG_Logout*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_Ping") {
                if (! ((MSG_Ping*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_Pong") {
                if (! ((MSG_Pong*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_ServerStatus") {
                if (! ((MSG_ServerStatus*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_ServiceRequest") {
                if (! ((MSG_ServiceRequest*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_VesselData") {
                if (! ((MSG_VesselData*) ( m_objStack.top() ) )->setBody( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "MSG_LoginResponse") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_LoginResponse *obj = (MSG_LoginResponse*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_LoginResponse( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_Logout") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_Logout *obj = (MSG_Logout*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_Logout( *obj ); 
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
    else if (qName == "MSG_Ping") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_Ping *obj = (MSG_Ping*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_Ping( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_Pong") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_Pong *obj = (MSG_Pong*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_Pong( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_ServerStatus") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_ServerStatus *obj = (MSG_ServerStatus*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_ServerStatus( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_ServiceRequest") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_ServiceRequest *obj = (MSG_ServiceRequest*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_ServiceRequest( *obj ); 
        delete( obj ); 
    }
    else if (qName == "MSG_VesselData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        MSG_VesselData *obj = (MSG_VesselData*) ( m_objStack.pop() );
        // tell the world a new object is available
        // this is only done for root level objects to avoid a storm of signals
        emit signalMSG_VesselData( *obj ); 
        delete( obj ); 
    }
    else if (qName == "Header") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Header *obj = (Header*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_LoginRequest") {
                if (! ((MSG_LoginRequest*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_LoginResponse") {
                if (! ((MSG_LoginResponse*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_Logout") {
                if (! ((MSG_Logout*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_Ping") {
                if (! ((MSG_Ping*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_Pong") {
                if (! ((MSG_Pong*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_ServerStatus") {
                if (! ((MSG_ServerStatus*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_ServiceRequest") {
                if (! ((MSG_ServiceRequest*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "MSG_VesselData") {
                if (! ((MSG_VesselData*) ( m_objStack.top() ) )->setHeader( *obj ) ) {
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
        if ( m_typeStack.top() == "PosReport") {
                if (! ((PosReport*) ( m_objStack.top() ) )->setPos( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "Area") {
                if (! ((Area*) ( m_objStack.top() ) )->addPos( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "PosReport") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        PosReport *obj = (PosReport*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                if (! ((VesselData*) ( m_objStack.top() ) )->setPosReport( *obj ) ) {
                    emit signalValidationError( "Error for " + qName );
                }
        }
        delete( obj ); 
    }
    else if (qName == "Sensor") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Sensor *obj = (Sensor*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "PosReport") {
                if (! ((PosReport*) ( m_objStack.top() ) )->addSensor( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "StaticData") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        StaticData *obj = (StaticData*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                if (! ((VesselData*) ( m_objStack.top() ) )->addStaticData( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
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
    else if (qName == "TaggedItem") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        TaggedItem *obj = (TaggedItem*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                if (! ((VesselData*) ( m_objStack.top() ) )->addTaggedItem( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
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
    else if (qName == "Object") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Object *obj = (Object*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "ServiceRequest") {
                if (! ((ServiceRequest*) ( m_objStack.top() ) )->addObject( *obj ) ) {
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
        if ( m_typeStack.top() == "Body") {
                if (! ((Body*) ( m_objStack.top() ) )->addVesselData( *obj ) ) {
                    emit signalValidationError( "Error for " + qName);
                }
        }
        delete( obj ); 
    }
    else if (qName == "Voyage") {

        // we know this tag, so we can close the top most object on the object stack
        m_typeStack.pop();
        Voyage *obj = (Voyage*) ( m_objStack.pop() );
        // check if there is a parent on the stack that needs this object as a child
        if ( m_typeStack.top() == "VesselData") {
                if (! ((VesselData*) ( m_objStack.top() ) )->addVoyage( *obj ) ) {
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
     QRegExp rx( "</MSG_([A-Za-z0-9]*)>");
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

