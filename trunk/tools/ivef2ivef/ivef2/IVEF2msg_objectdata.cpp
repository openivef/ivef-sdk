
#include "IVEF2msg_objectdata.h"

MSG_ObjectData::MSG_ObjectData() {

}

MSG_ObjectData::MSG_ObjectData(const MSG_ObjectData &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

MSG_ObjectData & MSG_ObjectData::operator=(const MSG_ObjectData &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

void MSG_ObjectData::setHeader(Header val) {

    m_header = val;
}

Header MSG_ObjectData::getHeader() const {

    return m_header;
}

void MSG_ObjectData::setBody(Body val) {

    m_body = val;
}

Body MSG_ObjectData::getBody() const {

    return m_body;
}

QString MSG_ObjectData::toXML() {

    QString xml = "<MSG_ObjectData";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "</MSG_ObjectData>\n");
    return xml;
}

QString MSG_ObjectData::toString(QString lead) {

    QString str = lead + "MSG_ObjectData\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

