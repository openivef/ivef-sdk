
#include "IVEFPing.h"

// Constructor
Ping::Ping() {

    // initialize with random value
    m_timeStamp = QDateTime();
}

// copy constructor
Ping::Ping(const Ping &val) : QObject() {

    m_timeStamp = val.m_timeStamp;
}

// comperator
Ping & Ping::operator=(const Ping &val) {

    m_timeStamp = val.m_timeStamp;
    return *this;
}

// String encoder
QString Ping::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Ping
void Ping::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

// getter for Ping
QDateTime Ping::getTimeStamp() const {

    return m_timeStamp;
}

// Get XML Representation
QString Ping::toXML() {

    QString xml = "<Ping";
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(">\n");
    xml.append( "</Ping>\n");
    return xml;
}

// Get String Representation
QString Ping::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Ping::toString(QString lead) {

    QString str = lead + "Ping\n";
    str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    return str;
}

