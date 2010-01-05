
#include "IVEFTransmission.h"

Transmission::Transmission() {

    m_type = 0;
    m_period = 0.0;
    m_periodPresent = false;
}

Transmission::Transmission(const Transmission &val) : QObject() {

    m_type = val.m_type;
    m_periodPresent = val.m_periodPresent;
    m_period = val.m_period;
}

Transmission & Transmission::operator=(const Transmission &val) {

    m_type = val.m_type;
    m_periodPresent = val.m_periodPresent;
    m_period = val.m_period;
    return *this;
}

QString Transmission::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Transmission::setType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) )
        return;
    m_type = val;
}

int Transmission::getType() const {

    return m_type;
}

void Transmission::setPeriod(float val) {

    m_periodPresent = true;
    m_period = val;
}

float Transmission::getPeriod() const {

    return m_period;
}

bool Transmission::hasPeriod() {

    return m_periodPresent;
}

QString Transmission::toXML() {

    QString xml = "<Transmission";
    xml.append(" Type=\"" + QString::number(m_type) + "\"");
    if ( hasPeriod() ) {
        xml.append(" Period=\"" + QString::number(m_period) + "\"");
    }
    xml.append(">\n");
    xml.append( "</Transmission>\n");
    return xml;
}

QString Transmission::toString(QString lead) {

    QString str = lead + "Transmission\n";
    str.append( lead + "    Type = " + QString::number(m_type) + "\n");
    if ( hasPeriod() ) {
        str.append( lead + "    Period = " + QString::number(m_period) + "\n");
    }
    return str;
}

