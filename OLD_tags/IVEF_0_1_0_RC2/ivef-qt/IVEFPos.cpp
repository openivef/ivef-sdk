
#include "IVEFPos.h"

Pos::Pos() {

}

Pos::Pos(const Pos &val) : QObject() {

    m_lat = val.m_lat;
    m_long = val.m_long;
}

Pos & Pos::operator=(const Pos &val) {

    m_lat = val.m_lat;
    m_long = val.m_long;
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

QString Pos::toXML() {

    QString xml = "<Pos";
    xml.append(" Lat=\"" + QString::number(m_lat) + "\"");
    xml.append(" Long=\"" + QString::number(m_long) + "\"");
    xml.append(">\n");
    xml.append( "</Pos>\n");
    return xml;
}

QString Pos::toString(QString lead) {

    QString str = lead + "Pos\n";
    str.append( lead + "    Lat = " + QString::number(m_lat) + "\n");
    str.append( lead + "    Long = " + QString::number(m_long) + "\n");
    return str;
}

