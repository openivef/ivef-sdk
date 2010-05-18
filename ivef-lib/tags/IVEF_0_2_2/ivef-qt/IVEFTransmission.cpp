
#include "IVEFTransmission.h"

// Constructor
Transmission::Transmission() {

    m_type = 0;
    m_typePresent = false;
    m_period = 0.0;
    m_periodPresent = false;
}

// copy constructor
Transmission::Transmission(const Transmission &val) : QObject() {

    m_typePresent = val.m_typePresent;
    m_type = val.m_type;
    m_periodPresent = val.m_periodPresent;
    m_period = val.m_period;
}

// assignement
Transmission & Transmission::operator=(const Transmission &val) {

    m_typePresent = val.m_typePresent;
    m_type = val.m_type;
    m_periodPresent = val.m_periodPresent;
    m_period = val.m_period;
    return *this;
}

// String encoder
QString Transmission::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Transmission
bool Transmission::setType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_typePresent = true;
    m_type = val;
      return true;
}

// getter for Transmission
int Transmission::getType() const {

    return m_type;
}

// setter for Transmission
bool Transmission::setPeriod(float val) {

    m_periodPresent = true;
    m_period = val;
      return true;
}

// getter for Transmission
float Transmission::getPeriod() const {

    return m_period;
}

// check if optional element Transmission has been set
bool Transmission::hasPeriod() const {

    return m_periodPresent;
}

// Get XML Representation
QString Transmission::toXML() const {

    QString xml = "<Transmission";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_typePresent) {
        xml.append(" Type=\"" + QString::number( m_type ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasPeriod() ) {
        xml.append(" Period=\"" + QString::number( m_period, 'f') + "\"");
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Transmission::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Transmission::toString(QString lead) {

    QString str = lead + "Transmission\n";
     str.append( lead + "    Type = " + QString::number( m_type ) + "\n");
    // check for presence of optional attribute
    if ( hasPeriod() ) {
        str.append( lead + "    Period = " + QString::number( m_period, 'f') + "\n");
    }
    return str;
}

