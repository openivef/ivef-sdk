
#include "IVEFPos.h"

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
    m_long = 0.0;
}

Pos::Pos(const Pos &val) : QObject() {

    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_estAccAltPresent = val.m_estAccAltPresent;
    m_estAccAlt = val.m_estAccAlt;
    m_estAccLatPresent = val.m_estAccLatPresent;
    m_estAccLat = val.m_estAccLat;
    m_estAccLongPresent = val.m_estAccLongPresent;
    m_estAccLong = val.m_estAccLong;
    m_lat = val.m_lat;
    m_long = val.m_long;
}

Pos & Pos::operator=(const Pos &val) {

    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_estAccAltPresent = val.m_estAccAltPresent;
    m_estAccAlt = val.m_estAccAlt;
    m_estAccLatPresent = val.m_estAccLatPresent;
    m_estAccLat = val.m_estAccLat;
    m_estAccLongPresent = val.m_estAccLongPresent;
    m_estAccLong = val.m_estAccLong;
    m_lat = val.m_lat;
    m_long = val.m_long;
    return *this;
}

QString Pos::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Pos::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
}

float Pos::getAltitude() const {

    return m_altitude;
}

bool Pos::hasAltitude() {

    return m_altitudePresent;
}

void Pos::setEstAccAlt(float val) {

    m_estAccAltPresent = true;
    m_estAccAlt = val;
}

float Pos::getEstAccAlt() const {

    return m_estAccAlt;
}

bool Pos::hasEstAccAlt() {

    return m_estAccAltPresent;
}

void Pos::setEstAccLat(float val) {

    m_estAccLatPresent = true;
    m_estAccLat = val;
}

float Pos::getEstAccLat() const {

    return m_estAccLat;
}

bool Pos::hasEstAccLat() {

    return m_estAccLatPresent;
}

void Pos::setEstAccLong(float val) {

    m_estAccLongPresent = true;
    m_estAccLong = val;
}

float Pos::getEstAccLong() const {

    return m_estAccLong;
}

bool Pos::hasEstAccLong() {

    return m_estAccLongPresent;
}

void Pos::setLat(float val) {

    if (val < -90)
        return;
    if (val > 90)
        return;
    m_lat = val;
}

float Pos::getLat() const {

    return m_lat;
}

void Pos::setLong(float val) {

    if (val < -180)
        return;
    if (val > 180)
        return;
    m_long = val;
}

float Pos::getLong() const {

    return m_long;
}

QString Pos::toXML() {

    QString xml = "<Pos";
    if ( hasAltitude() ) {
        xml.append(" Altitude=\"" + QString::number(m_altitude) + "\"");
    }
    if ( hasEstAccAlt() ) {
        xml.append(" EstAccAlt=\"" + QString::number(m_estAccAlt) + "\"");
    }
    if ( hasEstAccLat() ) {
        xml.append(" EstAccLat=\"" + QString::number(m_estAccLat) + "\"");
    }
    if ( hasEstAccLong() ) {
        xml.append(" EstAccLong=\"" + QString::number(m_estAccLong) + "\"");
    }
    xml.append(" Lat=\"" + QString::number(m_lat) + "\"");
    xml.append(" Long=\"" + QString::number(m_long) + "\"");
    xml.append(">\n");
    xml.append( "</Pos>\n");
    return xml;
}

QString Pos::toString(QString lead) {

    QString str = lead + "Pos\n";
    if ( hasAltitude() ) {
        str.append( lead + "    Altitude = " + QString::number(m_altitude) + "\n");
    }
    if ( hasEstAccAlt() ) {
        str.append( lead + "    EstAccAlt = " + QString::number(m_estAccAlt) + "\n");
    }
    if ( hasEstAccLat() ) {
        str.append( lead + "    EstAccLat = " + QString::number(m_estAccLat) + "\n");
    }
    if ( hasEstAccLong() ) {
        str.append( lead + "    EstAccLong = " + QString::number(m_estAccLong) + "\n");
    }
    str.append( lead + "    Lat = " + QString::number(m_lat) + "\n");
    str.append( lead + "    Long = " + QString::number(m_long) + "\n");
    return str;
}

