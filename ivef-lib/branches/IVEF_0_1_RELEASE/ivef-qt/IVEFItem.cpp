
#include "IVEFItem.h"

// Constructor
Item::Item() {

    m_element = 0;
    m_elementPresent = false;
    // initialize empty string
    m_field = "";
    m_fieldPresent = false;
}

// copy constructor
Item::Item(const Item &val) : QObject() {

    m_elementPresent = val.m_elementPresent;
    m_element = val.m_element;
    m_fieldPresent = val.m_fieldPresent;
    m_field = val.m_field;
}

// assignement
Item & Item::operator=(const Item &val) {

    m_elementPresent = val.m_elementPresent;
    m_element = val.m_element;
    m_fieldPresent = val.m_fieldPresent;
    m_field = val.m_field;
    return *this;
}

// String encoder
QString Item::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Item
bool Item::setElement(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_elementPresent = true;
    m_element = val;
      return true;
}

// getter for Item
int Item::getElement() const {

    return m_element;
}

// setter for Item
bool Item::setField(QString val) {

    m_fieldPresent = true;
    m_field = val;
      return true;
}

// getter for Item
QString Item::getField() const {

    return m_field;
}

// Get XML Representation
QString Item::toXML() const {

    QString xml = "<Item";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_elementPresent) {
        xml.append(" Element=\"" + QString::number(m_element) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_fieldPresent) {
        xml.append(" Field=\"" + encode (m_field) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Item::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Item::toString(QString lead) {

    QString str = lead + "Item\n";
    str.append( lead + "    Element = " + QString::number(m_element) + "\n");
    str.append( lead + "    Field = " + m_field + "\n");
    return str;
}

