
#include "IVEFPong.h"

// Constructor
Pong::Pong() {

    // initialize with random value
    m_timeStamp = QDateTime();
    // initialize empty string
    m_msgId = "";
    m_sourceId = 0;
}

// copy constructor
Pong::Pong(const Pong &val) : QObject() {

    m_timeStamp = val.m_timeStamp;
    m_msgId = val.m_msgId;
    m_sourceId = val.m_sourceId;
}

// comperator
Pong & Pong::operator=(const Pong &val) {

    m_timeStamp = val.m_timeStamp;
    m_msgId = val.m_msgId;
    m_sourceId = val.m_sourceId;
    return *this;
}

// String encoder
QString Pong::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Pong
void Pong::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

// getter for Pong
QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

// setter for Pong
void Pong::setMsgId(QString val) {

    m_msgId = val;
}

// getter for Pong
QString Pong::getMsgId() const {

    return m_msgId;
}

// setter for Pong
void Pong::setSourceId(int val) {

    m_sourceId = val;
}

// getter for Pong
int Pong::getSourceId() const {

    return m_sourceId;
}

// Get XML Representation
QString Pong::toXML() {

    QString xml = "<Pong";
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(" MsgId=\"" + encode (m_msgId) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    xml.append(">\n");
    xml.append( "</Pong>\n");
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
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    return str;
}

