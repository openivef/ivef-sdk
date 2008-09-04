
#include "IVEF2msg_notification.h"

MSG_Notification::MSG_Notification() {

}

MSG_Notification::MSG_Notification(const MSG_Notification &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_Notification & MSG_Notification::operator=(const MSG_Notification &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

void MSG_Notification::setHeader(Header val) {

    m_header = val;
}

Header MSG_Notification::getHeader() const {

    return m_header;
}

void MSG_Notification::setBody(Body val) {

    m_body = val;
}

Body MSG_Notification::getBody() const {

    return m_body;
}

QString MSG_Notification::toXML() {

    QString xml = "<MSG_Notification";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_Notification>\n");
    return xml;
}

QString MSG_Notification::toString(QString lead) {

    QString str = lead + "MSG_Notification\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

