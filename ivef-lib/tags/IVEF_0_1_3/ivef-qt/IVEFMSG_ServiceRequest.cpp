
#include "IVEFMSG_ServiceRequest.h"

MSG_ServiceRequest::MSG_ServiceRequest() {

}

MSG_ServiceRequest::MSG_ServiceRequest(const MSG_ServiceRequest &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_ServiceRequest & MSG_ServiceRequest::operator=(const MSG_ServiceRequest &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_ServiceRequest::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_ServiceRequest::setHeader(Header val) {

    m_header = val;
}

Header MSG_ServiceRequest::getHeader() const {

    return m_header;
}

void MSG_ServiceRequest::setBody(Body val) {

    m_body = val;
}

Body MSG_ServiceRequest::getBody() const {

    return m_body;
}

QString MSG_ServiceRequest::toXML() {

    QString xml = "<MSG_ServiceRequest";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_ServiceRequest>\n");
    return xml;
}

QString MSG_ServiceRequest::toString(QString lead) {

    QString str = lead + "MSG_ServiceRequest\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

