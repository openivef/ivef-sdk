
#include "IVEFOtherId.h"

// Constructor
OtherId::OtherId() {

    // initialize empty string
    m_id = "";
    // initialize empty string
    m_value = "";
}

// copy constructor
OtherId::OtherId(const OtherId &val) : QObject() {

    m_id = val.m_id;
    m_value = val.m_value;
}

// assignement
OtherId & OtherId::operator=(const OtherId &val) {

    m_id = val.m_id;
    m_value = val.m_value;
    return *this;
}

// String encoder
QString OtherId::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for OtherId
void OtherId::setId(QString val) {

    m_id = val;
}

// getter for OtherId
QString OtherId::getId() const {

    return m_id;
}

// setter for OtherId
void OtherId::setValue(QString val) {

    m_value = val;
}

// getter for OtherId
QString OtherId::getValue() const {

    return m_value;
}

// Get XML Representation
QString OtherId::toXML() {

    QString xml = "<OtherId";
    xml.append(" Id=\"" + encode (m_id) + "\"");
    xml.append(" Value=\"" + encode (m_value) + "\"");
    xml.append(">\n");
    xml.append( "</OtherId>\n");
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

