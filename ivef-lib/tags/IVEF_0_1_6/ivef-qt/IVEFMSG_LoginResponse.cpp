
#include "IVEFMSG_LoginResponse.h"

// Constructor
MSG_LoginResponse::MSG_LoginResponse() {

}

// copy constructor
MSG_LoginResponse::MSG_LoginResponse(const MSG_LoginResponse &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// assignement
MSG_LoginResponse & MSG_LoginResponse::operator=(const MSG_LoginResponse &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_LoginResponse::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_LoginResponse
void MSG_LoginResponse::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_LoginResponse
Header MSG_LoginResponse::getHeader() const {

    return m_header;
}

// setter for MSG_LoginResponse
void MSG_LoginResponse::setBody(Body val) {

    m_body = val;
}

// getter for MSG_LoginResponse
Body MSG_LoginResponse::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_LoginResponse::toXML() {

    QString xml = "<MSG_LoginResponse";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_LoginResponse>\n");
    return xml;
}

// Get String Representation
QString MSG_LoginResponse::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_LoginResponse::toString(QString lead) {

    QString str = lead + "MSG_LoginResponse\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

