
#include "IVEFPos.h"

// Constructor
Pos::Pos() {

    m_altitude = 0.0;
    m_altitudePresent = false;
    m_estAccAlt = 0.0;
    m_estAccAltPresent = false;
    m_estAccLat = 0.0;
    m_estAccLatPresent = false;
    m_estAccLong = 0.0;
    m_estAccLongPresent = false;
    m_lat = 0.0;
    m_latPresent = false;
    m_long = 0.0;
    m_longPresent = false;
}

// copy constructor
Pos::Pos(const Pos &val) : QObject() {

    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_estAccAltPresent = val.m_estAccAltPresent;
    m_estAccAlt = val.m_estAccAlt;
    m_estAccLatPresent = val.m_estAccLatPresent;
    m_estAccLat = val.m_estAccLat;
    m_estAccLongPresent = val.m_estAccLongPresent;
    m_estAccLong = val.m_estAccLong;
    m_latPresent = val.m_latPresent;
    m_lat = val.m_lat;
    m_longPresent = val.m_longPresent;
    m_long = val.m_long;
}

// assignement
Pos & Pos::operator=(const Pos &val) {

    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_estAccAltPresent = val.m_estAccAltPresent;
    m_estAccAlt = val.m_estAccAlt;
    m_estAccLatPresent = val.m_estAccLatPresent;
    m_estAccLat = val.m_estAccLat;
    m_estAccLongPresent = val.m_estAccLongPresent;
    m_estAccLong = val.m_estAccLong;
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
bool Pos::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
      return true;
}

// getter for Pos
float Pos::getAltitude() const {

    return m_altitude;
}

// check if optional element Pos has been set
bool Pos::hasAltitude() const {

    return m_altitudePresent;
}

// setter for Pos
bool Pos::setEstAccAlt(float val) {

    m_estAccAltPresent = true;
    m_estAccAlt = val;
      return true;
}

// getter for Pos
float Pos::getEstAccAlt() const {

    return m_estAccAlt;
}

// check if optional element Pos has been set
bool Pos::hasEstAccAlt() const {

    return m_estAccAltPresent;
}

// setter for Pos
bool Pos::setEstAccLat(float val) {

    m_estAccLatPresent = true;
    m_estAccLat = val;
      return true;
}

// getter for Pos
float Pos::getEstAccLat() const {

    return m_estAccLat;
}

// check if optional element Pos has been set
bool Pos::hasEstAccLat() const {

    return m_estAccLatPresent;
}

// setter for Pos
bool Pos::setEstAccLong(float val) {

    m_estAccLongPresent = true;
    m_estAccLong = val;
      return true;
}

// getter for Pos
float Pos::getEstAccLong() const {

    return m_estAccLong;
}

// check if optional element Pos has been set
bool Pos::hasEstAccLong() const {

    return m_estAccLongPresent;
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
    // check for presence of optional attribute
    if ( hasAltitude() ) {
        xml.append(" Altitude=\"" + QString::number( m_altitude, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasEstAccAlt() ) {
        xml.append(" EstAccAlt=\"" + QString::number( m_estAccAlt, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasEstAccLat() ) {
        xml.append(" EstAccLat=\"" + QString::number( m_estAccLat, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasEstAccLong() ) {
        xml.append(" EstAccLong=\"" + QString::number( m_estAccLong, 'f') + "\"");
    }
    // check for presence of required  attribute
    if ( m_latPresent) {
        xml.append(" Lat=\"" + QString::number(m_lat, 'f', 5) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_longPresent) {
        xml.append(" Long=\"" + QString::number(m_long, 'f', 5) + "\"");
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
    // check for presence of optional attribute
    if ( hasAltitude() ) {
        str.append( lead + "    Altitude = " + QString::number( m_altitude, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasEstAccAlt() ) {
        str.append( lead + "    EstAccAlt = " + QString::number( m_estAccAlt, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasEstAccLat() ) {
        str.append( lead + "    EstAccLat = " + QString::number( m_estAccLat, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasEstAccLong() ) {
        str.append( lead + "    EstAccLong = " + QString::number( m_estAccLong, 'f') + "\n");
    }
     str.append( lead + "    Lat = " + QString::number(m_lat, 'f', 5) + "\n");
     str.append( lead + "    Long = " + QString::number(m_long, 'f', 5) + "\n");
    return str;
}

