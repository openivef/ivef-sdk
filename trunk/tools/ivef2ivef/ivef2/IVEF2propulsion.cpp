
#include "IVEF2propulsion.h"

Propulsion::Propulsion() {

}

Propulsion::Propulsion(const Propulsion &val) : QObject() {

    m_power = val.m_power;
    m_mainEngine = val.m_mainEngine;
}

Propulsion & Propulsion::operator=(const Propulsion &val) {

    m_power = val.m_power;
    m_mainEngine = val.m_mainEngine;
    return *this;
}

void Propulsion::setPower(float val) {

    m_power = val;
}

float Propulsion::getPower() const {

    return m_power;
}

void Propulsion::setMainEngine(bool val) {

    m_mainEngine = val;
}

bool Propulsion::getMainEngine() const {

    return m_mainEngine;
}

QString Propulsion::toXML() {

    QString xml = "<Propulsion";
    xml.append(" Power=\"" + QString::number(m_power) + "\"");
    xml.append(" MainEngine=\"" + QString::number(m_mainEngine) + "\"");
    xml.append(">\n");
    xml.append( "</Propulsion>\n");
    return xml;
}

QString Propulsion::toString(QString lead) {

    QString str = lead + "Propulsion\n";
    str.append( lead + "    Power = " + QString::number(m_power) + "\n");
    str.append( lead + "    MainEngine = " + QString::number(m_mainEngine) + "\n");
    return str;
}

