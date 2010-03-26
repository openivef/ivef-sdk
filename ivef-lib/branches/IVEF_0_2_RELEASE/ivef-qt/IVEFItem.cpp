
#include "IVEFItem.h"

// Constructor
Item::Item() {

    m_dataSelector = 0;
    // initialize empty string
    m_fieldSelector = "";
}

// copy constructor
Item::Item(const Item &val) : QObject() {

    m_dataSelector = val.m_dataSelector;
    m_fieldSelector = val.m_fieldSelector;
}

// assignement
Item & Item::operator=(const Item &val) {

    m_dataSelector = val.m_dataSelector;
    m_fieldSelector = val.m_fieldSelector;
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
void Item::setDataSelector(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_dataSelector = val;
}

// getter for Item
int Item::getDataSelector() const {

    return m_dataSelector;
}

// setter for Item
void Item::setFieldSelector(QString val) {

    m_fieldSelector = val;
}

// getter for Item
QString Item::getFieldSelector() const {

    return m_fieldSelector;
}

// Get XML Representation
QString Item::toXML() {

    QString xml = "<Item";
    xml.append(" DataSelector=\"" + QString::number(m_dataSelector) + "\"");
    xml.append(" FieldSelector=\"" + encode (m_fieldSelector) + "\"");
    xml.append(">\n");
    xml.append( "</Item>\n");
    return xml;
}

// Get String Representation
QString Item::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Item::toString(QString lead) {

    QString str = lead + "Item\n";
    str.append( lead + "    DataSelector = " + QString::number(m_dataSelector) + "\n");
    str.append( lead + "    FieldSelector = " + m_fieldSelector + "\n");
    return str;
}

