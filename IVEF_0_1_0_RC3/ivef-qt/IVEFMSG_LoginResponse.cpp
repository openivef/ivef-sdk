
#include "IVEFMSG_LoginResponse.h"

MSG_LoginResponse::MSG_LoginResponse() {

}

MSG_LoginResponse::MSG_LoginResponse(const MSG_LoginResponse &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_LoginResponse & MSG_LoginResponse::operator=(const MSG_LoginResponse &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

void MSG_LoginResponse::setHeader(Header val) {

    m_header = val;
}

Header MSG_LoginResponse::getHeader() const {

    return m_header;
}

void MSG_LoginResponse::setBody(Body val) {

    m_body = val;
}

Body MSG_LoginResponse::getBody() const {

    return m_body;
}

QString MSG_LoginResponse::toXML() {

    QString xml = "<MSG_LoginResponse";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_LoginResponse>\n");
    return xml;
}

QString MSG_LoginResponse::toString(QString lead) {

    QString str = lead + "MSG_LoginResponse\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

