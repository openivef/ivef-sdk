
#include "IVEF2sensor.h"

Sensor::Sensor() {

}

Sensor::Sensor(const Sensor &val) : QObject() {

    m_senId = val.m_senId;
    m_trkId = val.m_trkId;
    m_updateTime = val.m_updateTime;
}

Sensor & Sensor::operator=(const Sensor &val) {

    m_senId = val.m_senId;
    m_trkId = val.m_trkId;
    m_updateTime = val.m_updateTime;
    return *this;
}

void Sensor::setSenId(float val) {

    if (val < -90)
        return;
    if (val > 90)
        return;
    m_senId = val;
}

float Sensor::getSenId() const {

    return m_senId;
}

void Sensor::setTrkId(float val) {

    if (val < -90)
        return;
    if (val > 90)
        return;
    m_trkId = val;
}

float Sensor::getTrkId() const {

    return m_trkId;
}

void Sensor::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

QDateTime Sensor::getUpdateTime() const {

    return m_updateTime;
}

QString Sensor::toXML() {

    QString xml = "<Sensor";
    xml.append(" SenId=\"" + QString::number(m_senId) + "\"");
    xml.append(" TrkId=\"" + QString::number(m_trkId) + "\"");
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    xml.append(">\n");
    xml.append( "</Sensor>\n");
    return xml;
}

QString Sensor::toString(QString lead) {

    QString str = lead + "Sensor\n";
    str.append( lead + "    SenId = " + QString::number(m_senId) + "\n");
    str.append( lead + "    TrkId = " + QString::number(m_trkId) + "\n");
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    return str;
}

