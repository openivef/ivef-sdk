
#include "IVEFMSG_LoginResponse.h"

// Constructor
MSG_LoginResponse::MSG_LoginResponse() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_LoginResponse::MSG_LoginResponse(const MSG_LoginResponse &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// assignement
MSG_LoginResponse & MSG_LoginResponse::operator=(const MSG_LoginResponse &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_LoginResponse::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_LoginResponse
bool MSG_LoginResponse::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_LoginResponse
Header MSG_LoginResponse::getHeader() const {

    return m_header;
}

// setter for MSG_LoginResponse
bool MSG_LoginResponse::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_LoginResponse
Body MSG_LoginResponse::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_LoginResponse::toXML() const {

    QString xml = "<MSG_LoginResponse";
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

