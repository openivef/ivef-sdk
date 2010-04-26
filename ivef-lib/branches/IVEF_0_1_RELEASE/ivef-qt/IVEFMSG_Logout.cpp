
#include "IVEFMSG_Logout.h"

// Constructor
MSG_Logout::MSG_Logout() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_Logout::MSG_Logout(const MSG_Logout &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// assignement
MSG_Logout & MSG_Logout::operator=(const MSG_Logout &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_Logout::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_Logout
bool MSG_Logout::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_Logout
Header MSG_Logout::getHeader() const {

    return m_header;
}

// setter for MSG_Logout
bool MSG_Logout::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_Logout
Body MSG_Logout::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_Logout::toXML() const {

    QString xml = "<MSG_Logout";
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
    xml.append( "</MSG_Logout>\n");
    return xml;
}

// Get String Representation
QString MSG_Logout::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_Logout::toString(QString lead) {

    QString str = lead + "MSG_Logout\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

