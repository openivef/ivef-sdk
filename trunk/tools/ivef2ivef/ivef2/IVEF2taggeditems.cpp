
#include "IVEF2taggeditems.h"

TaggedItems::TaggedItems() {

    m_keyPresent = false;
    m_valuePresent = false;
    m_keyPresent = false;
    m_valuePresent = false;
}

TaggedItems::TaggedItems(const TaggedItems &val) : QObject() {

    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
}

TaggedItems & TaggedItems::operator=(const TaggedItems &val) {

    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    return *this;
}

void TaggedItems::setKey(QString val) {

    m_keyPresent = true;
    m_key = val;
}

QString TaggedItems::getKey() const {

    return m_key;
}

bool TaggedItems::hasKey() {

    return m_keyPresent;
}

void TaggedItems::setValue(QString val) {

    m_valuePresent = true;
    m_value = val;
}

QString TaggedItems::getValue() const {

    return m_value;
}

bool TaggedItems::hasValue() {

    return m_valuePresent;
}

void TaggedItems::setKey(QString val) {

    m_keyPresent = true;
    m_key = val;
}

QString TaggedItems::getKey() const {

    return m_key;
}

bool TaggedItems::hasKey() {

    return m_keyPresent;
}

void TaggedItems::setValue(QString val) {

    m_valuePresent = true;
    m_value = val;
}

QString TaggedItems::getValue() const {

    return m_value;
}

bool TaggedItems::hasValue() {

    return m_valuePresent;
}

QString TaggedItems::toXML() {

    QString xml = "<TaggedItems";
    if ( hasKey() ) {
        xml.append(" Key=\"" + m_key + "\"");
    }
    if ( hasValue() ) {
        xml.append(" Value=\"" + m_value + "\"");
    }
    if ( hasKey() ) {
        xml.append(" Key=\"" + m_key + "\"");
    }
    if ( hasValue() ) {
        xml.append(" Value=\"" + m_value + "\"");
    }
    xml.append(">\n");
    xml.append( "</TaggedItems>\n");
    return xml;
}

QString TaggedItems::toString(QString lead) {

    QString str = lead + "TaggedItems\n";
    if ( hasKey() ) {
        str.append( lead + "    Key = " + m_key + "\n");
    }
    if ( hasValue() ) {
        str.append( lead + "    Value = " + m_value + "\n");
    }
    if ( hasKey() ) {
        str.append( lead + "    Key = " + m_key + "\n");
    }
    if ( hasValue() ) {
        str.append( lead + "    Value = " + m_value + "\n");
    }
    return str;
}

