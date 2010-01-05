
#include "IVEFHeader.h"

Header::Header() {

    m_msgRefId = "";
    m_version = "0.2.2";
}

Header::Header(const Header &val) : QObject() {

    m_msgRefId = val.m_msgRefId;
    m_version = val.m_version;
}

Header & Header::operator=(const Header &val) {

    m_msgRefId = val.m_msgRefId;
    m_version = val.m_version;
    return *this;
}

QString Header::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Header::setMsgRefId(QString val) {

    m_msgRefId = val;
}

QString Header::getMsgRefId() const {

    return m_msgRefId;
}

void Header::setVersion(QString val) {

    m_version = val;
}

QString Header::getVersion() const {

    return m_version;
}

QString Header::toXML() {

    QString xml = "<Header";
    xml.append(" MsgRefId=\"" + encode (m_msgRefId) + "\"");
    xml.append(" Version=\"" + encode (m_version) + "\"");
    xml.append(">\n");
    xml.append( "</Header>\n");
    return xml;
}

QString Header::toString(QString lead) {

    QString str = lead + "Header\n";
    str.append( lead + "    MsgRefId = " + m_msgRefId + "\n");
    str.append( lead + "    Version = " + m_version + "\n");
    return str;
}

