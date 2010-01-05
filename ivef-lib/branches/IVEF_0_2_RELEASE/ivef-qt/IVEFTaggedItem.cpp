
#include "IVEFTaggedItem.h"

TaggedItem::TaggedItem() {

    m_key = "";
    m_value = "";
}

TaggedItem::TaggedItem(const TaggedItem &val) : QObject() {

    m_key = val.m_key;
    m_value = val.m_value;
}

TaggedItem & TaggedItem::operator=(const TaggedItem &val) {

    m_key = val.m_key;
    m_value = val.m_value;
    return *this;
}

QString TaggedItem::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void TaggedItem::setKey(QString val) {

    m_key = val;
}

QString TaggedItem::getKey() const {

    return m_key;
}

void TaggedItem::setValue(QString val) {

    m_value = val;
}

QString TaggedItem::getValue() const {

    return m_value;
}

QString TaggedItem::toXML() {

    QString xml = "<TaggedItem";
    xml.append(" Key=\"" + encode (m_key) + "\"");
    xml.append(" Value=\"" + encode (m_value) + "\"");
    xml.append(">\n");
    xml.append( "</TaggedItem>\n");
    return xml;
}

QString TaggedItem::toString(QString lead) {

    QString str = lead + "TaggedItem\n";
    str.append( lead + "    Key = " + m_key + "\n");
    str.append( lead + "    Value = " + m_value + "\n");
    return str;
}

