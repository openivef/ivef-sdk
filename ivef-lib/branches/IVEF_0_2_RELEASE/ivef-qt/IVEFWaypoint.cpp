
#include "IVEFWaypoint.h"

Waypoint::Waypoint() {

    m_ATA = QDateTime();
    m_ATAPresent = false;
    m_ETA = QDateTime();
    m_ETAPresent = false;
    m_RTA = QDateTime();
    m_RTAPresent = false;
    m_loCode = "";
    m_loCodePresent = false;
    m_name = "";
}

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

QString Waypoint::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Waypoint::setPos(Pos val) {

    m_pos = val;
}

Pos Waypoint::getPos() const {

    return m_pos;
}

void Waypoint::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
}

QDateTime Waypoint::getATA() const {

    return m_ATA;
}

bool Waypoint::hasATA() {

    return m_ATAPresent;
}

void Waypoint::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

QDateTime Waypoint::getETA() const {

    return m_ETA;
}

bool Waypoint::hasETA() {

    return m_ETAPresent;
}

void Waypoint::setRTA(QDateTime val) {

    m_RTAPresent = true;
    m_RTA = val;
}

QDateTime Waypoint::getRTA() const {

    return m_RTA;
}

bool Waypoint::hasRTA() {

    return m_RTAPresent;
}

void Waypoint::setLoCode(QString val) {

    m_loCodePresent = true;
    m_loCode = val;
}

QString Waypoint::getLoCode() const {

    return m_loCode;
}

bool Waypoint::hasLoCode() {

    return m_loCodePresent;
}

void Waypoint::setName(QString val) {

    m_name = val;
}

QString Waypoint::getName() const {

    return m_name;
}

QString Waypoint::toXML() {

    QString xml = "<Waypoint";
    if ( hasATA() ) {
        xml.append(" ATA=\"" + m_ATA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    if ( hasRTA() ) {
        xml.append(" RTA=\"" + m_RTA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    if ( hasLoCode() ) {
        xml.append(" LoCode=\"" + encode (m_loCode) + "\"");
    }
    xml.append(" Name=\"" + encode (m_name) + "\"");
    xml.append(">\n");
    xml.append( m_pos.toXML() );
    xml.append( "</Waypoint>\n");
    return xml;
}

QString Waypoint::toString(QString lead) {

    QString str = lead + "Waypoint\n";
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + m_ATA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    if ( hasRTA() ) {
        str.append( lead + "    RTA = " + m_RTA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    if ( hasLoCode() ) {
        str.append( lead + "    LoCode = " + m_loCode + "\n");
    }
    str.append( lead + "    Name = " + m_name + "\n");
    str.append( m_pos.toString(lead + "    ") );
    return str;
}

