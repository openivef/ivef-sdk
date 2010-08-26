
#include "IVEFPos.h"

// Constructor
Pos::Pos() {

    m_lat = 0.0;
    m_latPresent = false;
    m_long = 0.0;
    m_longPresent = false;
}

// copy constructor
Pos::Pos(const Pos &val) : QObject() {

    m_latPresent = val.m_latPresent;
    m_lat = val.m_lat;
    m_longPresent = val.m_longPresent;
    m_long = val.m_long;
}

// compare
bool Pos::operator==(const Pos &val) {

    if (!(m_latPresent == val.m_latPresent)) return false;
    if (!(m_lat == val.m_lat)) return false;
    if (!(m_longPresent == val.m_longPresent)) return false;
    if (!(m_long == val.m_long)) return false;
    return true;
}

// assignement
Pos & Pos::operator=(const Pos &val) {

    m_latPresent = val.m_latPresent;
    m_lat = val.m_lat;
    m_longPresent = val.m_longPresent;
    m_long = val.m_long;
    return *this;
}

// String encoder
QString Pos::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Pos
bool Pos::setLat(float val) {
    // check if the new value is within bounds 

    if (val < -90)
        return false;    // check if the new value is within bounds 

    if (val > 90)
        return false;
    m_latPresent = true;
    m_lat = val;
      return true;
}

// getter for Pos
float Pos::getLat() const {

    return m_lat;
}

// setter for Pos
bool Pos::setLong(float val) {
    // check if the new value is within bounds 

    if (val < -180)
        return false;    // check if the new value is within bounds 

    if (val > 180)
        return false;
    m_longPresent = true;
    m_long = val;
      return true;
}

// getter for Pos
float Pos::getLong() const {

    return m_long;
}

// Get XML Representation
QString Pos::toXML() const {

    QString xml = "<Pos";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_latPresent) {
        xml.append(" Lat=\"" + QString::number( m_lat, 'f') + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_longPresent) {
        xml.append(" Long=\"" + QString::number( m_long, 'f') + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Pos::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Pos::toString(QString lead) {

    QString str = lead + "Pos\n";
     str.append( lead + "    Lat = " + QString::number( m_lat, 'f') + "\n");
     str.append( lead + "    Long = " + QString::number( m_long, 'f') + "\n");
    return str;
}

