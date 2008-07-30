
#include "msg_loginrequest.h"

MSG_LoginRequest::MSG_LoginRequest() {

}

MSG_LoginRequest::MSG_LoginRequest(const MSG_LoginRequest &val) : QObject() {

    m_header = ((MSG_LoginRequest)val).getHeader();
    m_body = ((MSG_LoginRequest)val).getBody();
}

MSG_LoginRequest & MSG_LoginRequest::operator=(const MSG_LoginRequest &/*val*/) {

    return *this;
}

void MSG_LoginRequest::setHeader(Header val) {

    m_header = val;
}

Header MSG_LoginRequest::getHeader() {

    return m_header;
}

void MSG_LoginRequest::setBody(Body val) {

    m_body = val;
}

Body MSG_LoginRequest::getBody() {

    return m_body;
}

QString MSG_LoginRequest::toXML() {

    QString xml = "<MSG_LoginRequest";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "<MSG_LoginRequest />\n");
    return xml;
}

