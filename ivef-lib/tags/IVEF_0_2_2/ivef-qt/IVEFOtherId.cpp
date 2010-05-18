
#include "IVEFOtherId.h"

// Constructor
OtherId::OtherId() {

    // initialize empty string
    m_id = "";
    m_idPresent = false;
    // initialize empty string
    m_value = "";
    m_valuePresent = false;
}

// copy constructor
OtherId::OtherId(const OtherId &val) : QObject() {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
}

// assignement
OtherId & OtherId::operator=(const OtherId &val) {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_valuePresent = val.m_valuePresent;
    m_value = val.m_value;
    return *this;
}

// String encoder
QString OtherId::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for OtherId
bool OtherId::setId(QString val) {

    m_idPresent = true;
    m_id = val;
      return true;
}

// getter for OtherId
QString OtherId::getId() const {

    return m_id;
}

// setter for OtherId
bool OtherId::setValue(QString val) {

    m_valuePresent = true;
    m_value = val;
      return true;
}

// getter for OtherId
QString OtherId::getValue() const {

    return m_value;
}

// Get XML Representation
QString OtherId::toXML() const {

    QString xml = "<OtherId";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_idPresent) {
        xml.append(" Id=\"" + encode (m_id) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_valuePresent) {
        xml.append(" Value=\"" + encode (m_value) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString OtherId::toString() {

    return toString("");
}

// Get String Representation with a lead
QString OtherId::toString(QString lead) {

    QString str = lead + "OtherId\n";
     str.append( lead + "    Id = " + m_id + "\n");
     str.append( lead + "    Value = " + m_value + "\n");
    return str;
}

