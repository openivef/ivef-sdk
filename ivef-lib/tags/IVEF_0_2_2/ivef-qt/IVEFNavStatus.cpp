
#include "IVEFNavStatus.h"

// Constructor
NavStatus::NavStatus() {

    m_value = 0;
    m_valuePresent = false;
}

// copy constructor
NavStatus::NavStatus(const NavStatus &val) : QObject() {

    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
}

// assignement
NavStatus & NavStatus::operator=(const NavStatus &val) {

    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    return *this;
}

// String encoder
QString NavStatus::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for NavStatus
bool NavStatus::setValue(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;    // check if the new value is within bounds 

    if (val > 15)
        return false;
    m_valuePresent = true;
    m_value = val;
      return true;
}

// getter for NavStatus
int NavStatus::getValue() const {

    return m_value;
}

// Get XML Representation
QString NavStatus::toXML() const {

    QString xml = "<NavStatus";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_valuePresent) {
        xml.append(" Value=\"" + QString::number( m_value ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString NavStatus::toString() {

    return toString("");
}

// Get String Representation with a lead
QString NavStatus::toString(QString lead) {

    QString str = lead + "NavStatus\n";
     str.append( lead + "    Value = " + QString::number( m_value ) + "\n");
    return str;
}

