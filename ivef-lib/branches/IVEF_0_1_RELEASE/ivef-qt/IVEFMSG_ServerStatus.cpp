
#include "IVEFMSG_ServerStatus.h"

// Constructor
MSG_ServerStatus::MSG_ServerStatus() {

}

// copy constructor
MSG_ServerStatus::MSG_ServerStatus(const MSG_ServerStatus &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// comperator
MSG_ServerStatus & MSG_ServerStatus::operator=(const MSG_ServerStatus &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_ServerStatus::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_ServerStatus
void MSG_ServerStatus::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_ServerStatus
Header MSG_ServerStatus::getHeader() const {

    return m_header;
}

// setter for MSG_ServerStatus
void MSG_ServerStatus::setBody(Body val) {

    m_body = val;
}

// getter for MSG_ServerStatus
Body MSG_ServerStatus::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_ServerStatus::toXML() {

    QString xml = "<MSG_ServerStatus";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_ServerStatus>\n");
    return xml;
}

// Get String Representation
QString MSG_ServerStatus::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_ServerStatus::toString(QString lead) {

    QString str = lead + "MSG_ServerStatus\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

