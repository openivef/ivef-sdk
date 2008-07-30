
#include "header.h"

Header::Header() {

}

Header::Header(const Header &val) : QObject() {

    m_version = ((Header)val).getVersion();
    m_msgRefId = ((Header)val).getMsgRefId();
}

Header & Header::operator=(const Header &/*val*/) {

    return *this;
}

void Header::setVersion(QString val) {

    m_version = val;
}

QString Header::getVersion() {

    return m_version;
}

void Header::setMsgRefId(QString val) {

    m_msgRefId = val;
}

QString Header::getMsgRefId() {

    return m_msgRefId;
}

QString Header::toXML() {

    QString xml = "<Header";
    xml.append(" Version = \"" + m_version + "\"");
    xml.append(" MsgRefId = \"" + m_msgRefId + "\"");
    xml.append(">\n");
    xml.append( "<Header />\n");
    return xml;
}

