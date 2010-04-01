
#include "IVEFItem.h"

// Constructor
Item::Item() {

    m_element = 0;
    // initialize empty string
    m_field = "";
}

// copy constructor
Item::Item(const Item &val) : QObject() {

    m_element = val.m_element;
    m_field = val.m_field;
}

// assignement
Item & Item::operator=(const Item &val) {

    m_element = val.m_element;
    m_field = val.m_field;
    return *this;
}

// String encoder
QString Item::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Item
void Item::setElement(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_element = val;
}

// getter for Item
int Item::getElement() const {

    return m_element;
}

// setter for Item
void Item::setField(QString val) {

    m_field = val;
}

// getter for Item
QString Item::getField() const {

    return m_field;
}

// Get XML Representation
QString Item::toXML() {

    QString xml = "<Item";
    xml.append(" Element=\"" + QString::number(m_element) + "\"");
    xml.append(" Field=\"" + encode (m_field) + "\"");
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

