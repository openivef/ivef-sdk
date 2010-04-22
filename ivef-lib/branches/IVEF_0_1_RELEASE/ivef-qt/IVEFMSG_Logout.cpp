
#include "IVEFMSG_Logout.h"

// Constructor
MSG_Logout::MSG_Logout() {

}

// copy constructor
MSG_Logout::MSG_Logout(const MSG_Logout &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// assignement
MSG_Logout & MSG_Logout::operator=(const MSG_Logout &val) {

    m_header = val.m_header;
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

    m_header = val;
      return true;
}

// getter for MSG_Logout
Header MSG_Logout::getHeader() const {

    return m_header;
}

// setter for MSG_Logout
bool MSG_Logout::setBody(Body val) {

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
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
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

