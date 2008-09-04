
#include "IVEF2pos.h"

Pos::Pos() {

    m_estAccPresent = false;
}

Pos::Pos(const Pos &val) : QObject() {

    m_lat = val.m_lat;
    m_long = val.m_long;
    m_estAccPresent = val.m_estAccPresent;
    m_estAcc = val.m_estAcc;
}

Pos & Pos::operator=(const Pos &val) {

    m_lat = val.m_lat;
    m_long = val.m_long;
    m_estAccPresent = val.m_estAccPresent;
    m_estAcc = val.m_estAcc;
    return *this;
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

void Pos::setEstAcc(float val) {

    m_estAccPresent = true;
    m_estAcc = val;
}

float Pos::getEstAcc() const {

    return m_estAcc;
}

bool Pos::hasEstAcc() {

    return m_estAccPresent;
}

QString Pos::toXML() {

    QString xml = "<Pos";
    xml.append(" Lat=\"" + QString::number(m_lat) + "\"");
    xml.append(" Long=\"" + QString::number(m_long) + "\"");
    if ( hasEstAcc() ) {
        xml.append(" EstAcc=\"" + QString::number(m_estAcc) + "\"");
    }
    xml.append(">\n");
    xml.append( "</Pos>\n");
    return xml;
}

QString Pos::toString(QString lead) {

    QString str = lead + "Pos\n";
    str.append( lead + "    Lat = " + QString::number(m_lat) + "\n");
    str.append( lead + "    Long = " + QString::number(m_long) + "\n");
    if ( hasEstAcc() ) {
        str.append( lead + "    EstAcc = " + QString::number(m_estAcc) + "\n");
    }
    return str;
}

