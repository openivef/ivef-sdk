
#include "transmission.h"

Transmission::Transmission() {

    m_periodPresent = false;
}

Transmission::Transmission(const Transmission &val) : QObject() {

    m_type = ((Transmission)val).getType();
    m_periodPresent = false;
    m_period = ((Transmission)val).getPeriod();
}

Transmission & Transmission::operator=(const Transmission &/*val*/) {

    return *this;
}

void Transmission::setType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) )
        return;
    m_type = val;
}

int Transmission::getType() {

    return m_type;
}

void Transmission::setPeriod(float val) {

    m_periodPresent = true;
    m_period = val;
}

float Transmission::getPeriod() {

    return m_period;
}

bool Transmission::hasPeriod() {

    return m_periodPresent;
}

QString Transmission::toXML() {

    QString xml = "<Transmission";
    xml.append(" Type = \"" + QString(m_type, 10) + "\"");
    if ( hasPeriod() ) {
        xml.append(" Period = \"" + QString(m_period, 10) + "\"");
    }
    xml.append(">\n");
    xml.append( "<Transmission />\n");
    return xml;
}

