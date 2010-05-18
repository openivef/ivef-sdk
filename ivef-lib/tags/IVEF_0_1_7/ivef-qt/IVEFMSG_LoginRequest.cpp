
#include "IVEFMSG_LoginRequest.h"

// Constructor
MSG_LoginRequest::MSG_LoginRequest() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_LoginRequest::MSG_LoginRequest(const MSG_LoginRequest &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// assignement
MSG_LoginRequest & MSG_LoginRequest::operator=(const MSG_LoginRequest &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_LoginRequest::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_LoginRequest
bool MSG_LoginRequest::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_LoginRequest
Header MSG_LoginRequest::getHeader() const {

    return m_header;
}

// setter for MSG_LoginRequest
bool MSG_LoginRequest::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_LoginRequest
Body MSG_LoginRequest::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_LoginRequest::toXML() const {

    QString xml = "<MSG_LoginRequest";
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

