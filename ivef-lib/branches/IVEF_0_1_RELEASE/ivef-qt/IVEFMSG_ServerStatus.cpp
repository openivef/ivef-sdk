
#include "IVEFMSG_ServerStatus.h"

// Constructor
MSG_ServerStatus::MSG_ServerStatus() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_ServerStatus::MSG_ServerStatus(const MSG_ServerStatus &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// assignement
MSG_ServerStatus & MSG_ServerStatus::operator=(const MSG_ServerStatus &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_ServerStatus::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_ServerStatus
bool MSG_ServerStatus::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_ServerStatus
Header MSG_ServerStatus::getHeader() const {

    return m_header;
}

// setter for MSG_ServerStatus
bool MSG_ServerStatus::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_ServerStatus
Body MSG_ServerStatus::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_ServerStatus::toXML() const {

    QString xml = "<MSG_ServerStatus";
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

