
#include "msg_ping.h"

MSG_Ping::MSG_Ping() {

}

MSG_Ping::MSG_Ping(const MSG_Ping &val) : QObject() {

    m_header = ((MSG_Ping)val).getHeader();
    m_body = ((MSG_Ping)val).getBody();
}

MSG_Ping & MSG_Ping::operator=(const MSG_Ping &/*val*/) {

    return *this;
}

void MSG_Ping::setHeader(Header val) {

    m_header = val;
}

Header MSG_Ping::getHeader() {

    return m_header;
}

void MSG_Ping::setBody(Body val) {

    m_body = val;
}

Body MSG_Ping::getBody() {

    return m_body;
}

QString MSG_Ping::toXML() {

    QString xml = "<MSG_Ping";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "<MSG_Ping />\n");
    return xml;
}

