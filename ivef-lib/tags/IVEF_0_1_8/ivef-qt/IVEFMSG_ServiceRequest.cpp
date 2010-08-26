
#include "IVEFMSG_ServiceRequest.h"

// Constructor
MSG_ServiceRequest::MSG_ServiceRequest() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_ServiceRequest::MSG_ServiceRequest(const MSG_ServiceRequest &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// compare
bool MSG_ServiceRequest::operator==(const MSG_ServiceRequest &val) {

    if (!(m_headerPresent == val.m_headerPresent)) return false;
    if (!(m_header == val.m_header)) return false;
    if (!(m_bodyPresent == val.m_bodyPresent)) return false;
    if (!(m_body == val.m_body)) return false;
    return true;
}

// assignement
MSG_ServiceRequest & MSG_ServiceRequest::operator=(const MSG_ServiceRequest &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_ServiceRequest::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_ServiceRequest
bool MSG_ServiceRequest::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_ServiceRequest
Header MSG_ServiceRequest::getHeader() const {

    return m_header;
}

// setter for MSG_ServiceRequest
bool MSG_ServiceRequest::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_ServiceRequest
Body MSG_ServiceRequest::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_ServiceRequest::toXML() const {

    QString xml = "<MSG_ServiceRequest";
    QString dataMember;
    xml.append(">\n");
    // check for presence of required data member
    if ( m_headerPresent) {
        dataMember = m_header.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
    // check for presence of required data member
    if ( m_bodyPresent) {
        dataMember = m_body.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
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

