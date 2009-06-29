
#include "IVEFMSG_Logout.h"

MSG_Logout::MSG_Logout() {

}

MSG_Logout::MSG_Logout(const MSG_Logout &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_Logout & MSG_Logout::operator=(const MSG_Logout &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_Logout::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_Logout::setHeader(Header val) {

    m_header = val;
}

Header MSG_Logout::getHeader() const {

    return m_header;
}

void MSG_Logout::setBody(Body val) {

    m_body = val;
}

Body MSG_Logout::getBody() const {

    return m_body;
}

QString MSG_Logout::toXML() {

    QString xml = "<MSG_Logout";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_Logout>\n");
    return xml;
}

QString MSG_Logout::toString(QString lead) {

    QString str = lead + "MSG_Logout\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

