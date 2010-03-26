
#include "IVEFMSG_LoginRequest.h"

// Constructor
MSG_LoginRequest::MSG_LoginRequest() {

}

// copy constructor
MSG_LoginRequest::MSG_LoginRequest(const MSG_LoginRequest &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// assignement
MSG_LoginRequest & MSG_LoginRequest::operator=(const MSG_LoginRequest &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_LoginRequest::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_LoginRequest
void MSG_LoginRequest::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_LoginRequest
Header MSG_LoginRequest::getHeader() const {

    return m_header;
}

// setter for MSG_LoginRequest
void MSG_LoginRequest::setBody(Body val) {

    m_body = val;
}

// getter for MSG_LoginRequest
Body MSG_LoginRequest::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_LoginRequest::toXML() {

    QString xml = "<MSG_LoginRequest";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_LoginRequest>\n");
    return xml;
}

// Get String Representation
QString MSG_LoginRequest::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_LoginRequest::toString(QString lead) {

    QString str = lead + "MSG_LoginRequest\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

