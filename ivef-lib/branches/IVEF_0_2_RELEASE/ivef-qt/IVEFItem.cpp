
#include "IVEFItem.h"

// Constructor
Item::Item() {

    m_dataSelector = 0;
    m_dataSelectorPresent = false;
    // initialize empty string
    m_fieldSelector = "";
    m_fieldSelectorPresent = false;
}

// copy constructor
Item::Item(const Item &val) : QObject() {

    m_dataSelectorPresent = val.m_dataSelectorPresent;
    m_dataSelector = val.m_dataSelector;
    m_fieldSelectorPresent = val.m_fieldSelectorPresent;
    m_fieldSelector = val.m_fieldSelector;
}

// compare
bool Item::operator==(const Item &val) {

    if (!(m_dataSelectorPresent == val.m_dataSelectorPresent)) return false;
    if (!(m_dataSelector == val.m_dataSelector)) return false;
    if (!(m_fieldSelectorPresent == val.m_fieldSelectorPresent)) return false;
    if (!(m_fieldSelector == val.m_fieldSelector)) return false;
    return true;
}

// assignement
Item & Item::operator=(const Item &val) {

    m_dataSelectorPresent = val.m_dataSelectorPresent;
    m_dataSelector = val.m_dataSelector;
    m_fieldSelectorPresent = val.m_fieldSelectorPresent;
    m_fieldSelector = val.m_fieldSelector;
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
bool Item::setDataSelector(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_dataSelectorPresent = true;
    m_dataSelector = val;
      return true;
}

// getter for Item
int Item::getDataSelector() const {

    return m_dataSelector;
}

// setter for Item
bool Item::setFieldSelector(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 1)
        return false;    // check if the new value is within bounds 

    if (val.length() > 42)
        return false;
    m_fieldSelectorPresent = true;
    m_fieldSelector = val;
      return true;
}

// getter for Item
QString Item::getFieldSelector() const {

    return m_fieldSelector;
}

// Get XML Representation
QString Item::toXML() const {

    QString xml = "<Item";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_dataSelectorPresent) {
        xml.append(" DataSelector=\"" + QString::number( m_dataSelector ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_fieldSelectorPresent) {
        xml.append(" FieldSelector=\"" + encode (m_fieldSelector) + "\"");
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
     str.append( lead + "    DataSelector = " + QString::number( m_dataSelector ) + "\n");
     str.append( lead + "    FieldSelector = " + m_fieldSelector + "\n");
    return str;
}

