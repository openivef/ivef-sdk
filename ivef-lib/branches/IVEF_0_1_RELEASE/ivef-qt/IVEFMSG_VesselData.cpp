
#include "IVEFMSG_VesselData.h"

MSG_VesselData::MSG_VesselData() {

}

MSG_VesselData::MSG_VesselData(const MSG_VesselData &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_VesselData & MSG_VesselData::operator=(const MSG_VesselData &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

QString MSG_VesselData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void MSG_VesselData::setHeader(Header val) {

    m_header = val;
}

Header MSG_VesselData::getHeader() const {

    return m_header;
}

void MSG_VesselData::setBody(Body val) {

    m_body = val;
}

Body MSG_VesselData::getBody() const {

    return m_body;
}

QString MSG_VesselData::toXML() {

    QString xml = "<MSG_VesselData";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_VesselData>\n");
    return xml;
}

QString MSG_VesselData::toString(QString lead) {

    QString str = lead + "MSG_VesselData\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

