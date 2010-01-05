
#include "IVEFMSG_IVEF.h"

MSG_IVEF::MSG_IVEF() {

}

MSG_IVEF::MSG_IVEF(const MSG_IVEF &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_IVEF & MSG_IVEF::operator=(const MSG_IVEF &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_IVEF::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_IVEF::setHeader(Header val) {

    m_header = val;
}

Header MSG_IVEF::getHeader() const {

    return m_header;
}

void MSG_IVEF::setBody(Body val) {

    m_body = val;
}

Body MSG_IVEF::getBody() const {

    return m_body;
}

QString MSG_IVEF::toXML() {

    QString xml = "<MSG_IVEF";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_IVEF>\n");
    return xml;
}

QString MSG_IVEF::toString(QString lead) {

    QString str = lead + "MSG_IVEF\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

