
#include "voyage.h"

Voyage::Voyage() {

    m_cargoTypePresent = false;
    m_destinationPresent = false;
    m_ETAPresent = false;
    m_ATAPresent = false;
    m_airDraughtPresent = false;
    m_draughtPresent = false;
}

Voyage::Voyage(const Voyage &val) : QObject() {

    m_id = val.getId();
    m_sourceName = val.getSourceName();
    m_source = val.getSource();
    m_cargoTypePresent = false;
    m_cargoType = val.getCargoType();
    m_destinationPresent = false;
    m_destination = val.getDestination();
    m_ETAPresent = false;
    m_ETA = val.getETA();
    m_ATAPresent = false;
    m_ATA = val.getATA();
    m_airDraughtPresent = false;
    m_airDraught = val.getAirDraught();
    m_draughtPresent = false;
    m_draught = val.getDraught();
}

Voyage & Voyage::operator=(const Voyage &/*val*/) {

    return *this;
}

void Voyage::setId(QString val) {

    m_id = val;
}

QString Voyage::getId() const {

    return m_id;
}

void Voyage::setSourceName(QString val) {

    m_sourceName = val;
}

QString Voyage::getSourceName() const {

    return m_sourceName;
}

void Voyage::setSource(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_source = val;
}

int Voyage::getSource() const {

    return m_source;
}

void Voyage::setCargoType(int val) {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 9 ) )
        return;
    m_cargoTypePresent = true;
    m_cargoType = val;
}

int Voyage::getCargoType() const {

    return m_cargoType;
}

bool Voyage::hasCargoType() {

    return m_cargoTypePresent;
}

void Voyage::setDestination(QString val) {

    m_destinationPresent = true;
    m_destination = val;
}

QString Voyage::getDestination() const {

    return m_destination;
}

bool Voyage::hasDestination() {

    return m_destinationPresent;
}

void Voyage::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

QDateTime Voyage::getETA() const {

    return m_ETA;
}

bool Voyage::hasETA() {

    return m_ETAPresent;
}

void Voyage::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
}

QDateTime Voyage::getATA() const {

    return m_ATA;
}

bool Voyage::hasATA() {

    return m_ATAPresent;
}

void Voyage::setAirDraught(float val) {

    m_airDraughtPresent = true;
    m_airDraught = val;
}

float Voyage::getAirDraught() const {

    return m_airDraught;
}

bool Voyage::hasAirDraught() {

    return m_airDraughtPresent;
}

void Voyage::setDraught(float val) {

    m_draughtPresent = true;
    m_draught = val;
}

float Voyage::getDraught() const {

    return m_draught;
}

bool Voyage::hasDraught() {

    return m_draughtPresent;
}

QString Voyage::toXML() {

    QString xml = "<Voyage";
    xml.append(" Id = \"" + m_id + "\"");
    xml.append(" SourceName = \"" + m_sourceName + "\"");
    xml.append(" Source = \"" + QString(m_source, 10) + "\"");
    if ( hasCargoType() ) {
        xml.append(" CargoType = \"" + QString(m_cargoType, 10) + "\"");
    }
    if ( hasDestination() ) {
        xml.append(" Destination = \"" + m_destination + "\"");
    }
    if ( hasETA() ) {
        xml.append(" ETA = \"" + m_ETA.toString() + "\"");
    }
    if ( hasATA() ) {
        xml.append(" ATA = \"" + m_ATA.toString() + "\"");
    }
    if ( hasAirDraught() ) {
        xml.append(" AirDraught = \"" + QString(m_airDraught, 10) + "\"");
    }
    if ( hasDraught() ) {
        xml.append(" Draught = \"" + QString(m_draught, 10) + "\"");
    }
    xml.append(">\n");
    xml.append( "<Voyage />\n");
    return xml;
}

