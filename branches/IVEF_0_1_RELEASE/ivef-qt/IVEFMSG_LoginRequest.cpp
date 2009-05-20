
#include "IVEFMSG_LoginRequest.h"

MSG_LoginRequest::MSG_LoginRequest() {

}

MSG_LoginRequest::MSG_LoginRequest(const MSG_LoginRequest &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_LoginRequest & MSG_LoginRequest::operator=(const MSG_LoginRequest &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_LoginRequest::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_LoginRequest::setHeader(Header val) {

    m_header = val;
}

Header MSG_LoginRequest::getHeader() const {

    return m_header;
}

void MSG_LoginRequest::setBody(Body val) {

    m_body = val;
}

Body MSG_LoginRequest::getBody() const {

    return m_body;
}

QString MSG_LoginRequest::toXML() {

    QString xml = "<MSG_LoginRequest";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_LoginRequest>\n");
    return xml;
}

QString MSG_LoginRequest::toString(QString lead) {

    QString str = lead + "MSG_LoginRequest\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

