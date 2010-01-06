
#include "IVEFWaypoint.h"

// Constructor
Waypoint::Waypoint() {

    // initialize with random value
    m_ATA = QDateTime();
    // optional attributes are by default not present
    m_ATAPresent = false;
    // initialize with random value
    m_ETA = QDateTime();
    // optional attributes are by default not present
    m_ETAPresent = false;
    // initialize with random value
    m_RTA = QDateTime();
    // optional attributes are by default not present
    m_RTAPresent = false;
    // initialize empty string
    m_loCode = "";
    // optional attributes are by default not present
    m_loCodePresent = false;
    // initialize empty string
    m_name = "";
}

// copy constructor
Waypoint::Waypoint(const Waypoint &val) : QObject() {

    m_pos = val.m_pos;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_RTAPresent = val.m_RTAPresent;
    m_RTA = val.m_RTA;
    m_loCodePresent = val.m_loCodePresent;
    m_loCode = val.m_loCode;
    m_name = val.m_name;
}

// comperator
Waypoint & Waypoint::operator=(const Waypoint &val) {

    m_pos = val.m_pos;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_RTAPresent = val.m_RTAPresent;
    m_RTA = val.m_RTA;
    m_loCodePresent = val.m_loCodePresent;
    m_loCode = val.m_loCode;
    m_name = val.m_name;
    return *this;
}

// String encoder
QString Waypoint::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Waypoint
void Waypoint::setPos(Pos val) {

    m_pos = val;
}

// getter for Waypoint
Pos Waypoint::getPos() const {

    return m_pos;
}

// setter for Waypoint
void Waypoint::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
}

// getter for Waypoint
QDateTime Waypoint::getATA() const {

    return m_ATA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasATA() {

    return m_ATAPresent;
}

// setter for Waypoint
void Waypoint::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

// getter for Waypoint
QDateTime Waypoint::getETA() const {

    return m_ETA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasETA() {

    return m_ETAPresent;
}

// setter for Waypoint
void Waypoint::setRTA(QDateTime val) {

    m_RTAPresent = true;
    m_RTA = val;
}

// getter for Waypoint
QDateTime Waypoint::getRTA() const {

    return m_RTA;
}

// check if optional element Waypoint has been set
bool Waypoint::hasRTA() {

    return m_RTAPresent;
}

// setter for Waypoint
void Waypoint::setLoCode(QString val) {

    m_loCodePresent = true;
    m_loCode = val;
}

// getter for Waypoint
QString Waypoint::getLoCode() const {

    return m_loCode;
}

// check if optional element Waypoint has been set
bool Waypoint::hasLoCode() {

    return m_loCodePresent;
}

// setter for Waypoint
void Waypoint::setName(QString val) {

    m_name = val;
}

// getter for Waypoint
QString Waypoint::getName() const {

    return m_name;
}

// Get XML Representation
QString Waypoint::toXML() {

    QString xml = "<Waypoint";
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
    xml.append(" Name=\"" + encode (m_name) + "\"");
    xml.append(">\n");
    xml.append( m_pos.toXML() );
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
    str.append( m_pos.toString(lead + "    ") );
    return str;
}

