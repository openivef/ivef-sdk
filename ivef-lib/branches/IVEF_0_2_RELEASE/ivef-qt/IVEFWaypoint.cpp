
#include "IVEFWaypoint.h"

// Constructor
Waypoint::Waypoint() {

    m_posPresent = false;
    // initialize with random value
    m_ATA = QDateTime();
    m_ATAPresent = false;
    // initialize with random value
    m_ETA = QDateTime();
    m_ETAPresent = false;
    // initialize with random value
    m_RTA = QDateTime();
    m_RTAPresent = false;
    // initialize empty string
    m_loCode = "";
    m_loCodePresent = false;
    // initialize empty string
    m_name = "";
    m_namePresent = false;
}

// copy constructor
Waypoint::Waypoint(const Waypoint &val) : QObject() {

    m_posPresent = val.m_posPresent;
    m_pos = val.m_pos;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_RTAPresent = val.m_RTAPresent;
    m_RTA = val.m_RTA;
    m_loCodePresent = val.m_loCodePresent;
    m_loCode = val.m_loCode;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
}

// compare
bool Waypoint::operator==(const Waypoint &val) {

    if (!(m_posPresent == val.m_posPresent)) return false;
    if (!(m_pos == val.m_pos)) return false;
    if (!(m_ATAPresent == val.m_ATAPresent)) return false;
    if (!(m_ATA == val.m_ATA)) return false;
    if (!(m_ETAPresent == val.m_ETAPresent)) return false;
    if (!(m_ETA == val.m_ETA)) return false;
    if (!(m_RTAPresent == val.m_RTAPresent)) return false;
    if (!(m_RTA == val.m_RTA)) return false;
    if (!(m_loCodePresent == val.m_loCodePresent)) return false;
    if (!(m_loCode == val.m_loCode)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    return true;
}

// assignement
Waypoint & Waypoint::operator=(const Waypoint &val) {

    m_posPresent = val.m_posPresent;
    m_pos = val.m_pos;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_RTAPresent = val.m_RTAPresent;
    m_RTA = val.m_RTA;
    m_loCodePresent = val.m_loCodePresent;
    m_loCode = val.m_loCode;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    return *this;
}

// String encoder
QString Waypoint::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Waypoint
bool Waypoint::setPos(Pos val) {

    m_posPresent = true;
    m_pos = val;
      return true;
}

// getter for Waypoint
Pos Waypoint::getPos() const {

    return m_pos;
}

// check if optional element Waypoint has been set
bool Waypoint::hasPos() const {

    return m_posPresent;
}

// setter for Waypoint
bool Waypoint::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
      return true;
}

// getter for Waypoint
QDateTime Waypoint::getATA() const {

    return m_ATA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasATA() const {

    return m_ATAPresent;
}

// setter for Waypoint
bool Waypoint::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
      return true;
}

// getter for Waypoint
QDateTime Waypoint::getETA() const {

    return m_ETA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasETA() const {

    return m_ETAPresent;
}

// setter for Waypoint
bool Waypoint::setRTA(QDateTime val) {

    m_RTAPresent = true;
    m_RTA = val;
      return true;
}

// getter for Waypoint
QDateTime Waypoint::getRTA() const {

    return m_RTA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasRTA() const {

    return m_RTAPresent;
}

// setter for Waypoint
bool Waypoint::setLoCode(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 5)
        return false;    // check if the new value is within bounds 

    if (val.length() > 15)
        return false;
    m_loCodePresent = true;
    m_loCode = val;
      return true;
}

// getter for Waypoint
QString Waypoint::getLoCode() const {

    return m_loCode;
}

// check if optional element Waypoint has been set
bool Waypoint::hasLoCode() const {

    return m_loCodePresent;
}

// setter for Waypoint
bool Waypoint::setName(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 1)
        return false;    // check if the new value is within bounds 

    if (val.length() > 42)
        return false;
    m_namePresent = true;
    m_name = val;
      return true;
}

// getter for Waypoint
QString Waypoint::getName() const {

    return m_name;
}

// Get XML Representation
QString Waypoint::toXML() const {

    QString xml = "<Waypoint";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasATA() ) {
        xml.append(" ATA=\"" + m_ATA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasRTA() ) {
        xml.append(" RTA=\"" + m_RTA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasLoCode() ) {
        xml.append(" LoCode=\"" + encode (m_loCode) + "\"");
    }
    // check for presence of required  attribute
    if ( m_namePresent) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append(">\n");
    // add optional data if available
    if ( hasPos() ) {
        dataMember = m_pos.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    xml.append( "</Waypoint>\n");
    return xml;
}

// Get String Representation
QString Waypoint::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Waypoint::toString(QString lead) {

    QString str = lead + "Waypoint\n";
    // check for presence of optional attribute
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + m_ATA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasRTA() ) {
        str.append( lead + "    RTA = " + m_RTA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasLoCode() ) {
        str.append( lead + "    LoCode = " + m_loCode + "\n");
    }
     str.append( lead + "    Name = " + m_name + "\n");
    // add all optional data if present
    if ( hasPos() ) {
        str.append( m_pos.toString(lead + "    ") );
    }
    return str;
}

