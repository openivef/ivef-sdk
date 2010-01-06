
#include "IVEFMSG_ServiceRequest.h"

// Constructor
MSG_ServiceRequest::MSG_ServiceRequest() {

}

// copy constructor
MSG_ServiceRequest::MSG_ServiceRequest(const MSG_ServiceRequest &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// comperator
MSG_ServiceRequest & MSG_ServiceRequest::operator=(const MSG_ServiceRequest &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_ServiceRequest::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_ServiceRequest
void MSG_ServiceRequest::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_ServiceRequest
Header MSG_ServiceRequest::getHeader() const {

    return m_header;
}

// setter for MSG_ServiceRequest
void MSG_ServiceRequest::setBody(Body val) {

    m_body = val;
}

// getter for MSG_ServiceRequest
Body MSG_ServiceRequest::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_ServiceRequest::toXML() {

    QString xml = "<MSG_ServiceRequest";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_ServiceRequest>\n");
    return xml;
}

// Get String Representation
QString MSG_ServiceRequest::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_ServiceRequest::toString(QString lead) {

    QString str = lead + "MSG_ServiceRequest\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

