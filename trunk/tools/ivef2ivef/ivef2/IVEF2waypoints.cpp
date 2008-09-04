
#include "IVEF2waypoints.h"

Waypoints::Waypoints() {

    m_ETAPresent = false;
    m_ATAPresent = false;
}

Waypoints::Waypoints(const Waypoints &val) : QObject() {

    m_pos = val.m_pos;
    m_name = val.m_name;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
}

Waypoints & Waypoints::operator=(const Waypoints &val) {

    m_pos = val.m_pos;
    m_name = val.m_name;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    return *this;
}

void Waypoints::setPos(Pos val) {

    m_pos = val;
}

Pos Waypoints::getPos() const {

    return m_pos;
}

void Waypoints::setName(QString val) {

    m_name = val;
}

QString Waypoints::getName() const {

    return m_name;
}

void Waypoints::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

QDateTime Waypoints::getETA() const {

    return m_ETA;
}

bool Waypoints::hasETA() {

    return m_ETAPresent;
}

void Waypoints::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
}

QDateTime Waypoints::getATA() const {

    return m_ATA;
}

bool Waypoints::hasATA() {

    return m_ATAPresent;
}

QString Waypoints::toXML() {

    QString xml = "<Waypoints";
    xml.append(" Name=\"" + m_name + "\"");
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    }
    if ( hasATA() ) {
        xml.append(" ATA=\"" + m_ATA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    }
    xml.append(">\n");
    xml.append( m_pos.toXML() );
    xml.append( "</Waypoints>\n");
    return xml;
}

QString Waypoints::toString(QString lead) {

    QString str = lead + "Waypoints\n";
    str.append( lead + "    Name = " + m_name + "\n");
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    }
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + m_ATA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    }
    str.append( m_pos.toString(lead + "    ") );
    return str;
}

