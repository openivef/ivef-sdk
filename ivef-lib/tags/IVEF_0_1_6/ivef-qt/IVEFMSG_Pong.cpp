
#include "IVEFMSG_Pong.h"

// Constructor
MSG_Pong::MSG_Pong() {

}

// copy constructor
MSG_Pong::MSG_Pong(const MSG_Pong &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// assignement
MSG_Pong & MSG_Pong::operator=(const MSG_Pong &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_Pong::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_Pong
void MSG_Pong::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_Pong
Header MSG_Pong::getHeader() const {

    return m_header;
}

// setter for MSG_Pong
void MSG_Pong::setBody(Body val) {

    m_body = val;
}

// getter for MSG_Pong
Body MSG_Pong::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_Pong::toXML() {

    QString xml = "<MSG_Pong";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_Pong>\n");
    return xml;
}

// Get String Representation
QString MSG_Pong::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_Pong::toString(QString lead) {

    QString str = lead + "MSG_Pong\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

