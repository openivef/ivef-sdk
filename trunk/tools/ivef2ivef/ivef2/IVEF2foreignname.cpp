
#include "IVEF2foreignname.h"

ForeignName::ForeignName() {

}

ForeignName::ForeignName(const ForeignName &val) : QObject() {

    m_lang = val.m_lang;
    m_name = val.m_name;
}

ForeignName & ForeignName::operator=(const ForeignName &val) {

    m_lang = val.m_lang;
    m_name = val.m_name;
    return *this;
}

void ForeignName::setLang(QString val) {

    m_lang = val;
}

QString ForeignName::getLang() const {

    return m_lang;
}

void ForeignName::setName(QString val) {

    m_name = val;
}

QString ForeignName::getName() const {

    return m_name;
}

QString ForeignName::toXML() {

    QString xml = "<foreignName";
    xml.append(" Lang=\"" + m_lang + "\"");
    xml.append(" Name=\"" + m_name + "\"");
    xml.append(">\n");
    xml.append( "</foreignName>\n");
    return xml;
}

QString ForeignName::toString(QString lead) {

    QString str = lead + "foreignName\n";
    str.append( lead + "    Lang = " + m_lang + "\n");
    str.append( lead + "    Name = " + m_name + "\n");
    return str;
}

