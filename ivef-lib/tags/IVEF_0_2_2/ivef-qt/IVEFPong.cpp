
#include "IVEFPong.h"

// Constructor
Pong::Pong() {

    // initialize empty string
    m_responseOn = "";
    m_responseOnPresent = false;
    m_sourceId = 0;
    m_sourceIdPresent = false;
    // initialize with random value
    m_timeStamp = QDateTime();
    m_timeStampPresent = false;
}

// copy constructor
Pong::Pong(const Pong &val) : QObject() {

    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
}

// assignement
Pong & Pong::operator=(const Pong &val) {

    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    return *this;
}

// String encoder
QString Pong::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Pong
bool Pong::setResponseOn(QString val) {

    m_responseOnPresent = true;
    m_responseOn = val;
      return true;
}

// getter for Pong
QString Pong::getResponseOn() const {

    return m_responseOn;
}

// setter for Pong
bool Pong::setSourceId(int val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
      return true;
}

// getter for Pong
int Pong::getSourceId() const {

    return m_sourceId;
}

// setter for Pong
bool Pong::setTimeStamp(QDateTime val) {

    m_timeStampPresent = true;
    m_timeStamp = val;
      return true;
}

// getter for Pong
QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

// Get XML Representation
QString Pong::toXML() const {

    QString xml = "<Pong";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_responseOnPresent) {
        xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourceIdPresent) {
        xml.append(" SourceId=\"" + QString::number( m_sourceId ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_timeStampPresent) {
        xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Pong::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Pong::toString(QString lead) {

    QString str = lead + "Pong\n";
     str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
     str.append( lead + "    SourceId = " + QString::number( m_sourceId ) + "\n");
     str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    return str;
}

