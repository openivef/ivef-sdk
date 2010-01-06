
#include "IVEFTaggedItem.h"

// Constructor
TaggedItem::TaggedItem() {

    // initialize empty string
    m_key = "";
    // initialize empty string
    m_value = "";
}

// copy constructor
TaggedItem::TaggedItem(const TaggedItem &val) : QObject() {

    m_key = val.m_key;
    m_value = val.m_value;
}

// comperator
TaggedItem & TaggedItem::operator=(const TaggedItem &val) {

    m_key = val.m_key;
    m_value = val.m_value;
    return *this;
}

// String encoder
QString TaggedItem::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for TaggedItem
void TaggedItem::setKey(QString val) {

    m_key = val;
}

// getter for TaggedItem
QString TaggedItem::getKey() const {

    return m_key;
}

// setter for TaggedItem
void TaggedItem::setValue(QString val) {

    m_value = val;
}

// getter for TaggedItem
QString TaggedItem::getValue() const {

    return m_value;
}

// Get XML Representation
QString TaggedItem::toXML() {

    QString xml = "<TaggedItem";
    xml.append(" Key=\"" + encode (m_key) + "\"");
    xml.append(" Value=\"" + encode (m_value) + "\"");
    xml.append(">\n");
    xml.append( "</TaggedItem>\n");
    return xml;
}

// Get String Representation
QString TaggedItem::toString() {

    return toString("");
}

// Get String Representation with a lead
QString TaggedItem::toString(QString lead) {

    QString str = lead + "TaggedItem\n";
    str.append( lead + "    Key = " + m_key + "\n");
    str.append( lead + "    Value = " + m_value + "\n");
    return str;
}

