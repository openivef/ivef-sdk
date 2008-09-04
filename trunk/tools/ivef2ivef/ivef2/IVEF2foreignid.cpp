
#include "IVEF2foreignid.h"

ForeignId::ForeignId() {

}

ForeignId::ForeignId(const ForeignId &val) : QObject() {

    m_id = val.m_id;
    m_value = val.m_value;
}

ForeignId & ForeignId::operator=(const ForeignId &val) {

    m_id = val.m_id;
    m_value = val.m_value;
    return *this;
}

void ForeignId::setId(QString val) {

    m_id = val;
}

QString ForeignId::getId() const {

    return m_id;
}

void ForeignId::setValue(QString val) {

    m_value = val;
}

QString ForeignId::getValue() const {

    return m_value;
}

QString ForeignId::toXML() {

    QString xml = "<foreignId";
    xml.append(" Id=\"" + m_id + "\"");
    xml.append(" Value=\"" + m_value + "\"");
    xml.append(">\n");
    xml.append( "</foreignId>\n");
    return xml;
}

QString ForeignId::toString(QString lead) {

    QString str = lead + "foreignId\n";
    str.append( lead + "    Id = " + m_id + "\n");
    str.append( lead + "    Value = " + m_value + "\n");
    return str;
}

