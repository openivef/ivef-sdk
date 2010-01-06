
#include "IVEFMSG_Ping.h"

// Constructor
MSG_Ping::MSG_Ping() {

}

// copy constructor
MSG_Ping::MSG_Ping(const MSG_Ping &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// comperator
MSG_Ping & MSG_Ping::operator=(const MSG_Ping &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_Ping::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_Ping
void MSG_Ping::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_Ping
Header MSG_Ping::getHeader() const {

    return m_header;
}

// setter for MSG_Ping
void MSG_Ping::setBody(Body val) {

    m_body = val;
}

// getter for MSG_Ping
Body MSG_Ping::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_Ping::toXML() {

    QString xml = "<MSG_Ping";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_Ping>\n");
    return xml;
}

// Get String Representation
QString MSG_Ping::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_Ping::toString(QString lead) {

    QString str = lead + "MSG_Ping\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

