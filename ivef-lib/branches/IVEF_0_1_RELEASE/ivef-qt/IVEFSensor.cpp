
#include "IVEFSensor.h"

Sensor::Sensor() {

    m_senId = 0.0;
    m_trkId = 0.0;
}

Sensor::Sensor(const Sensor &val) : QObject() {

    m_senId = val.m_senId;
    m_trkId = val.m_trkId;
}

Sensor & Sensor::operator=(const Sensor &val) {

    m_senId = val.m_senId;
    m_trkId = val.m_trkId;
    return *this;
}

QString Sensor::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Sensor::setSenId(float val) {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_senId = val;
}

float Sensor::getSenId() const {

    return m_senId;
}

void Sensor::setTrkId(float val) {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_trkId = val;
}

float Sensor::getTrkId() const {

    return m_trkId;
}

QString Sensor::toXML() {

    QString xml = "<Sensor";
    xml.append(" SenId=\"" + QString::number(m_senId) + "\"");
    xml.append(" TrkId=\"" + QString::number(m_trkId) + "\"");
    xml.append(">\n");
    xml.append( "</Sensor>\n");
    return xml;
}

QString Sensor::toString(QString lead) {

    QString str = lead + "Sensor\n";
    str.append( lead + "    SenId = " + QString::number(m_senId) + "\n");
    str.append( lead + "    TrkId = " + QString::number(m_trkId) + "\n");
    return str;
}

