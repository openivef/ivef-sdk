
#include "IVEFPos.h"

// Constructor
Pos::Pos() {

    m_lat = 0.0;
    m_long = 0.0;
}

// copy constructor
Pos::Pos(const Pos &val) : QObject() {

    m_lat = val.m_lat;
    m_long = val.m_long;
}

// assignement
Pos & Pos::operator=(const Pos &val) {

    m_lat = val.m_lat;
    m_long = val.m_long;
    return *this;
}

// String encoder
QString Pos::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Pos
void Pos::setLat(float val) {
    // check if the new value is within bounds 

    if (val < -90)
        return;    // check if the new value is within bounds 

    if (val > 90)
        return;
    m_lat = val;
}

// getter for Pos
float Pos::getLat() const {

    return m_lat;
}

// setter for Pos
void Pos::setLong(float val) {
    // check if the new value is within bounds 

    if (val < -180)
        return;    // check if the new value is within bounds 

    if (val > 180)
        return;
    m_long = val;
}

// getter for Pos
float Pos::getLong() const {

    return m_long;
}

// Get XML Representation
QString Pos::toXML() {

    QString xml = "<Pos";
    xml.append(" Lat=\"" + QString::number(m_lat, 'f') + "\"");
    xml.append(" Long=\"" + QString::number(m_long, 'f') + "\"");
    xml.append(">\n");
    xml.append( "</Pos>\n");
    return xml;
}

// Get String Representation
QString Pos::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Pos::toString(QString lead) {

    QString str = lead + "Pos\n";
    str.append( lead + "    Lat = " + QString::number(m_lat) + "\n");
    str.append( lead + "    Long = " + QString::number(m_long) + "\n");
    return str;
}

