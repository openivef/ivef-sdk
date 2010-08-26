
#include "IVEFPong.h"

// Constructor
Pong::Pong() {

    // initialize with random value
    m_timeStamp = QDateTime();
    m_timeStampPresent = false;
    // initialize empty string
    m_msgId = "";
    m_msgIdPresent = false;
    m_sourceId = 0;
    m_sourceIdPresent = false;
}

// copy constructor
Pong::Pong(const Pong &val) : QObject() {

    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    m_msgIdPresent = val.m_msgIdPresent;
    m_msgId = val.m_msgId;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
}

// compare
bool Pong::operator==(const Pong &val) {

    if (!(m_timeStampPresent == val.m_timeStampPresent)) return false;
    if (!(m_timeStamp == val.m_timeStamp)) return false;
    if (!(m_msgIdPresent == val.m_msgIdPresent)) return false;
    if (!(m_msgId == val.m_msgId)) return false;
    if (!(m_sourceIdPresent == val.m_sourceIdPresent)) return false;
    if (!(m_sourceId == val.m_sourceId)) return false;
    return true;
}

// assignement
Pong & Pong::operator=(const Pong &val) {

    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    m_msgIdPresent = val.m_msgIdPresent;
    m_msgId = val.m_msgId;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
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
bool Pong::setTimeStamp(QDateTime val) {

    m_timeStampPresent = true;
    m_timeStamp = val;
      return true;
}

// getter for Pong
QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

// setter for Pong
bool Pong::setMsgId(QString val) {
    // check if the new value is within bounds 

    if (val.length() > 36)
        return false;
    m_msgIdPresent = true;
    m_msgId = val;
      return true;
}

// getter for Pong
QString Pong::getMsgId() const {

    return m_msgId;
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

// Get XML Representation
QString Pong::toXML() const {

    QString xml = "<Pong";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_timeStampPresent) {
        xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_msgIdPresent) {
        xml.append(" MsgId=\"" + encode (m_msgId) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourceIdPresent) {
        xml.append(" SourceId=\"" + QString::number( m_sourceId ) + "\"");
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
     str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
     str.append( lead + "    MsgId = " + m_msgId + "\n");
     str.append( lead + "    SourceId = " + QString::number( m_sourceId ) + "\n");
    return str;
}

