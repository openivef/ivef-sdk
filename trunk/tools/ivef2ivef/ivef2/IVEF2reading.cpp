
#include "IVEF2reading.h"

Reading::Reading() {

    m_idPresent = false;
}

Reading::Reading(const Reading &val) : QObject() {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_type = val.m_type;
    m_value = val.m_value;
}

Reading & Reading::operator=(const Reading &val) {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_type = val.m_type;
    m_value = val.m_value;
    return *this;
}

void Reading::setId(int val) {

    m_idPresent = true;
    m_id = val;
}

int Reading::getId() const {

    return m_id;
}

bool Reading::hasId() {

    return m_idPresent;
}

void Reading::setType(int val) {

    m_type = val;
}

int Reading::getType() const {

    return m_type;
}

void Reading::setValue(float val) {

    m_value = val;
}

float Reading::getValue() const {

    return m_value;
}

QString Reading::toXML() {

    QString xml = "<Reading";
    if ( hasId() ) {
        xml.append(" Id=\"" + QString::number(m_id) + "\"");
    }
    xml.append(" Type=\"" + QString::number(m_type) + "\"");
    xml.append(" Value=\"" + QString::number(m_value) + "\"");
    xml.append(">\n");
    xml.append( "</Reading>\n");
    return xml;
}

QString Reading::toString(QString lead) {

    QString str = lead + "Reading\n";
    if ( hasId() ) {
        str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    }
    str.append( lead + "    Type = " + QString::number(m_type) + "\n");
    str.append( lead + "    Value = " + QString::number(m_value) + "\n");
    return str;
}

