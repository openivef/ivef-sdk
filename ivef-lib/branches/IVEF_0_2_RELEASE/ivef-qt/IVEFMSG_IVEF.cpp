
#include "IVEFMSG_IVEF.h"

// Constructor
MSG_IVEF::MSG_IVEF() {

}

// copy constructor
MSG_IVEF::MSG_IVEF(const MSG_IVEF &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// assignement
MSG_IVEF & MSG_IVEF::operator=(const MSG_IVEF &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_IVEF::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_IVEF
void MSG_IVEF::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_IVEF
Header MSG_IVEF::getHeader() const {

    return m_header;
}

// setter for MSG_IVEF
void MSG_IVEF::setBody(Body val) {

    m_body = val;
}

// getter for MSG_IVEF
Body MSG_IVEF::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_IVEF::toXML() {

    QString xml = "<MSG_IVEF";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_IVEF>\n");
    return xml;
}

// Get String Representation
QString MSG_IVEF::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_IVEF::toString(QString lead) {

    QString str = lead + "MSG_IVEF\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

