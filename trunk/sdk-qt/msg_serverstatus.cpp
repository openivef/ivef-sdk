
#include "msg_serverstatus.h"

MSG_ServerStatus::MSG_ServerStatus() {

}

MSG_ServerStatus::MSG_ServerStatus(const MSG_ServerStatus &val) : QObject() {

    m_header = ((MSG_ServerStatus)val).getHeader();
    m_body = ((MSG_ServerStatus)val).getBody();
}

MSG_ServerStatus & MSG_ServerStatus::operator=(const MSG_ServerStatus &/*val*/) {

    return *this;
}

void MSG_ServerStatus::setHeader(Header val) {

    m_header = val;
}

Header MSG_ServerStatus::getHeader() {

    return m_header;
}

void MSG_ServerStatus::setBody(Body val) {

    m_body = val;
}

Body MSG_ServerStatus::getBody() {

    return m_body;
}

QString MSG_ServerStatus::toXML() {

    QString xml = "<MSG_ServerStatus";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "<MSG_ServerStatus />\n");
    return xml;
}

