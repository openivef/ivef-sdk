
#include "IVEFMSG_Pong.h"

MSG_Pong::MSG_Pong() {

}

MSG_Pong::MSG_Pong(const MSG_Pong &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_Pong & MSG_Pong::operator=(const MSG_Pong &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_Pong::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_Pong::setHeader(Header val) {

    m_header = val;
}

Header MSG_Pong::getHeader() const {

    return m_header;
}

void MSG_Pong::setBody(Body val) {

    m_body = val;
}

Body MSG_Pong::getBody() const {

    return m_body;
}

QString MSG_Pong::toXML() {

    QString xml = "<MSG_Pong";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_Pong>\n");
    return xml;
}

QString MSG_Pong::toString(QString lead) {

    QString str = lead + "MSG_Pong\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

