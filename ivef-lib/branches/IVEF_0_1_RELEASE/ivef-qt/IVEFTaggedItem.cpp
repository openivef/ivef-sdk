
#include "IVEFTaggedItem.h"

// Constructor
TaggedItem::TaggedItem() {

    // initialize empty string
    m_key = "";
    m_keyPresent = false;
    m_keyPresent = false;
    m_keyPresent = false;
    // initialize empty string
    m_value = "";
    m_valuePresent = false;
    m_valuePresent = false;
    m_valuePresent = false;
}

// copy constructor
TaggedItem::TaggedItem(const TaggedItem &val) : QObject() {

    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
}

// assignement
TaggedItem & TaggedItem::operator=(const TaggedItem &val) {

    m_keyPresent = val.m_keyPresent;
    m_key = val.m_key;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    return *this;
}

// String encoder
QString TaggedItem::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for TaggedItem
bool TaggedItem::setKey(QString val) {

    m_keyPresent = true;
    m_key = val;
      return true;
}

// getter for TaggedItem
QString TaggedItem::getKey() const {

    return m_key;
}

// setter for TaggedItem
bool TaggedItem::setValue(QString val) {

    m_valuePresent = true;
    m_value = val;
      return true;
}

// getter for TaggedItem
QString TaggedItem::getValue() const {

    return m_value;
}

// Get XML Representation
QString TaggedItem::toXML() const {

    QString xml = "<TaggedItem";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_keyPresent) {
        xml.append(" Key=\"" + m_key + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_valuePresent) {
        xml.append(" Value=\"" + m_value + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
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

