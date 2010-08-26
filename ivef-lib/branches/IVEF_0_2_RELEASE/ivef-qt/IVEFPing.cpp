
#include "IVEFPing.h"

// Constructor
Ping::Ping() {

    // initialize with random value
    m_timeStamp = QDateTime();
    m_timeStampPresent = false;
}

// copy constructor
Ping::Ping(const Ping &val) : QObject() {

    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
}

// compare
bool Ping::operator==(const Ping &val) {

    if (!(m_timeStampPresent == val.m_timeStampPresent)) return false;
    if (!(m_timeStamp == val.m_timeStamp)) return false;
    return true;
}

// assignement
Ping & Ping::operator=(const Ping &val) {

    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    return *this;
}

// String encoder
QString Ping::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Ping
bool Ping::setTimeStamp(QDateTime val) {

    m_timeStampPresent = true;
    m_timeStamp = val;
      return true;
}

// getter for Ping
QDateTime Ping::getTimeStamp() const {

    return m_timeStamp;
}

// Get XML Representation
QString Ping::toXML() const {

    QString xml = "<Ping";
    QString dataMember;
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
QString Ping::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Ping::toString(QString lead) {

    QString str = lead + "Ping\n";
     str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    return str;
}

