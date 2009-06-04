
#include "IVEFMSG_ServerStatus.h"

MSG_ServerStatus::MSG_ServerStatus() {

}

MSG_ServerStatus::MSG_ServerStatus(const MSG_ServerStatus &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_ServerStatus & MSG_ServerStatus::operator=(const MSG_ServerStatus &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_ServerStatus::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_ServerStatus::setHeader(Header val) {

    m_header = val;
}

Header MSG_ServerStatus::getHeader() const {

    return m_header;
}

void MSG_ServerStatus::setBody(Body val) {

    m_body = val;
}

Body MSG_ServerStatus::getBody() const {

    return m_body;
}

QString MSG_ServerStatus::toXML() {

    QString xml = "<MSG_ServerStatus";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_ServerStatus>\n");
    return xml;
}

QString MSG_ServerStatus::toString(QString lead) {

    QString str = lead + "MSG_ServerStatus\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

