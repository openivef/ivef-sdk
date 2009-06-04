
#include "IVEFMSG_Ping.h"

MSG_Ping::MSG_Ping() {

}

MSG_Ping::MSG_Ping(const MSG_Ping &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_Ping & MSG_Ping::operator=(const MSG_Ping &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

void MSG_Ping::setHeader(Header val) {

    m_header = val;
}

Header MSG_Ping::getHeader() const {

    return m_header;
}

void MSG_Ping::setBody(Body val) {

    m_body = val;
}

Body MSG_Ping::getBody() const {

    return m_body;
}

QString MSG_Ping::toXML() {

    QString xml = "<MSG_Ping";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_Ping>\n");
    return xml;
}

QString MSG_Ping::toString(QString lead) {

    QString str = lead + "MSG_Ping\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

