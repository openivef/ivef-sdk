
#include "IVEFHeader.h"

Header::Header() {

    m_version = "0.1.3";
    m_msgRefId = "";
}

Header::Header(const Header &val) : QObject() {

    m_version = val.m_version;
    m_msgRefId = val.m_msgRefId;
}

Header & Header::operator=(const Header &val) {

    m_version = val.m_version;
    m_msgRefId = val.m_msgRefId;
    return *this;
}

QString Header::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Header::setVersion(QString val) {

    m_version = val;
}

QString Header::getVersion() const {

    return m_version;
}

void Header::setMsgRefId(QString val) {

    m_msgRefId = val;
}

QString Header::getMsgRefId() const {

    return m_msgRefId;
}

QString Header::toXML() {

    QString xml = "<Header";
    xml.append(" Version=\"" + encode (m_version) + "\"");
    xml.append(" MsgRefId=\"" + encode (m_msgRefId) + "\"");
    xml.append(">\n");
    xml.append( "</Header>\n");
    return xml;
}

QString Header::toString(QString lead) {

    QString str = lead + "Header\n";
    str.append( lead + "    Version = " + m_version + "\n");
    str.append( lead + "    MsgRefId = " + m_msgRefId + "\n");
    return str;
}

