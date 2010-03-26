
#include "IVEFPong.h"

// Constructor
Pong::Pong() {

    // initialize empty string
    m_responseOn = "";
    m_sourceId = 0;
    // initialize with random value
    m_timeStamp = QDateTime();
}

// copy constructor
Pong::Pong(const Pong &val) : QObject() {

    m_responseOn = val.m_responseOn;
    m_sourceId = val.m_sourceId;
    m_timeStamp = val.m_timeStamp;
}

// assignement
Pong & Pong::operator=(const Pong &val) {

    m_responseOn = val.m_responseOn;
    m_sourceId = val.m_sourceId;
    m_timeStamp = val.m_timeStamp;
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
void Pong::setResponseOn(QString val) {

    m_responseOn = val;
}

// getter for Pong
QString Pong::getResponseOn() const {

    return m_responseOn;
}

// setter for Pong
void Pong::setSourceId(int val) {

    m_sourceId = val;
}

// getter for Pong
int Pong::getSourceId() const {

    return m_sourceId;
}

// setter for Pong
void Pong::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

// getter for Pong
QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

// Get XML Representation
QString Pong::toXML() {

    QString xml = "<Pong";
    xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
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
    str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    return str;
}

