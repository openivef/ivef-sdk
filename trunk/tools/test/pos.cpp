
#include "pos.h"

Pos::Pos() {

}

Pos::Pos(const Pos &val) : QObject() {

    m_lat = val.getLat();
    m_long = val.getLong();
}

Pos & Pos::operator=(const Pos &/*val*/) {

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
    xml.append(" Lat = \"" + QString(m_lat, 10) + "\"");
    xml.append(" Long = \"" + QString(m_long, 10) + "\"");
    xml.append(">\n");
    xml.append( "<Pos />\n");
    return xml;
}

