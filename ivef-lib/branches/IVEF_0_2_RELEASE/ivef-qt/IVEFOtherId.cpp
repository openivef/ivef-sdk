
#include "IVEFOtherId.h"

OtherId::OtherId() {

    m_id = "";
    m_value = "";
}

OtherId::OtherId(const OtherId &val) : QObject() {

    m_id = val.m_id;
    m_value = val.m_value;
}

OtherId & OtherId::operator=(const OtherId &val) {

    m_id = val.m_id;
    m_value = val.m_value;
    return *this;
}

QString OtherId::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void OtherId::setId(QString val) {

    m_id = val;
}

QString OtherId::getId() const {

    return m_id;
}

void OtherId::setValue(QString val) {

    m_value = val;
}

QString OtherId::getValue() const {

    return m_value;
}

QString OtherId::toXML() {

    QString xml = "<OtherId";
    xml.append(" Id=\"" + encode (m_id) + "\"");
    xml.append(" Value=\"" + encode (m_value) + "\"");
    xml.append(">\n");
    xml.append( "</OtherId>\n");
    return xml;
}

QString OtherId::toString(QString lead) {

    QString str = lead + "OtherId\n";
    str.append( lead + "    Id = " + m_id + "\n");
    str.append( lead + "    Value = " + m_value + "\n");
    return str;
}

