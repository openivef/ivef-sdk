
#include "IVEFOtherName.h"

OtherName::OtherName() {

    m_lang = "";
    m_name = "";
}

OtherName::OtherName(const OtherName &val) : QObject() {

    m_lang = val.m_lang;
    m_name = val.m_name;
}

OtherName & OtherName::operator=(const OtherName &val) {

    m_lang = val.m_lang;
    m_name = val.m_name;
    return *this;
}

QString OtherName::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void OtherName::setLang(QString val) {

    m_lang = val;
}

QString OtherName::getLang() const {

    return m_lang;
}

void OtherName::setName(QString val) {

    m_name = val;
}

QString OtherName::getName() const {

    return m_name;
}

QString OtherName::toXML() {

    QString xml = "<OtherName";
    xml.append(" Lang=\"" + encode (m_lang) + "\"");
    xml.append(" Name=\"" + encode (m_name) + "\"");
    xml.append(">\n");
    xml.append( "</OtherName>\n");
    return xml;
}

QString OtherName::toString(QString lead) {

    QString str = lead + "OtherName\n";
    str.append( lead + "    Lang = " + m_lang + "\n");
    str.append( lead + "    Name = " + m_name + "\n");
    return str;
}

