
#include "IVEFHeader.h"

// Constructor
Header::Header() {

    // initialize fixed value
    m_version = "0.1.5";
    // initialize empty string
    m_msgRefId = "";
}

// copy constructor
Header::Header(const Header &val) : QObject() {

    m_version = val.m_version;
    m_msgRefId = val.m_msgRefId;
}

// comperator
Header & Header::operator=(const Header &val) {

    m_version = val.m_version;
    m_msgRefId = val.m_msgRefId;
    return *this;
}

// String encoder
QString Header::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Header
void Header::setVersion(QString val) {

    m_version = val;
}

// getter for Header
QString Header::getVersion() const {

    return m_version;
}

// setter for Header
void Header::setMsgRefId(QString val) {

    m_msgRefId = val;
}

// getter for Header
QString Header::getMsgRefId() const {

    return m_msgRefId;
}

// Get XML Representation
QString Header::toXML() {

    QString xml = "<Header";
    xml.append(" Version=\"" + encode (m_version) + "\"");
    xml.append(" MsgRefId=\"" + encode (m_msgRefId) + "\"");
    xml.append(">\n");
    xml.append( "</Header>\n");
    return xml;
}

// Get String Representation
QString Header::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Header::toString(QString lead) {

    QString str = lead + "Header\n";
    str.append( lead + "    Version = " + m_version + "\n");
    str.append( lead + "    MsgRefId = " + m_msgRefId + "\n");
    return str;
}

