
#include "IVEFVoyage.h"

Voyage::Voyage() {

    m_id = "";
    m_sourceName = "";
    m_source = 0;
    m_cargoType = 0;
    m_cargoTypePresent = false;
    m_destination = "";
    m_destinationPresent = false;
    m_ETA = QDateTime();
    m_ETAPresent = false;
    m_ATA = QDateTime();
    m_ATAPresent = false;
    m_personsOnBoard = 0.0;
    m_personsOnBoardPresent = false;
    m_airDraught = 0.0;
    m_airDraughtPresent = false;
    m_draught = 0.0;
    m_draughtPresent = false;
}

Voyage::Voyage(const Voyage &val) : QObject() {

    m_id = val.m_id;
    m_sourceName = val.m_sourceName;
    m_source = val.m_source;
    m_cargoTypePresent = val.m_cargoTypePresent;
    m_cargoType = val.m_cargoType;
    m_destinationPresent = val.m_destinationPresent;
    m_destination = val.m_destination;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
}

Voyage & Voyage::operator=(const Voyage &val) {

    m_id = val.m_id;
    m_sourceName = val.m_sourceName;
    m_source = val.m_source;
    m_cargoTypePresent = val.m_cargoTypePresent;
    m_cargoType = val.m_cargoType;
    m_destinationPresent = val.m_destinationPresent;
    m_destination = val.m_destination;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    return *this;
}

QString Voyage::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
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

void Voyage::setPersonsOnBoard(float val) {

    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
}

float Voyage::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

bool Voyage::hasPersonsOnBoard() {

    return m_personsOnBoardPresent;
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
    xml.append(" Id=\"" + encode (m_id) + "\"");
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" Source=\"" + QString::number(m_source) + "\"");
    if ( hasCargoType() ) {
        xml.append(" CargoType=\"" + QString::number(m_cargoType) + "\"");
    }
    if ( hasDestination() ) {
        xml.append(" Destination=\"" + encode (m_destination) + "\"");
    }
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-ddThh:mm:ss.zzzZ") + "\"");
    }
    if ( hasATA() ) {
        xml.append(" ATA=\"" + m_ATA.toString("yyyy-MM-ddThh:mm:ss.zzzZ") + "\"");
    }
    if ( hasPersonsOnBoard() ) {
        xml.append(" PersonsOnBoard=\"" + QString::number(m_personsOnBoard) + "\"");
    }
    if ( hasAirDraught() ) {
        xml.append(" AirDraught=\"" + QString::number(m_airDraught) + "\"");
    }
    if ( hasDraught() ) {
        xml.append(" Draught=\"" + QString::number(m_draught) + "\"");
    }
    xml.append(">\n");
    xml.append( "</Voyage>\n");
    return xml;
}

QString Voyage::toString(QString lead) {

    QString str = lead + "Voyage\n";
    str.append( lead + "    Id = " + m_id + "\n");
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    Source = " + QString::number(m_source) + "\n");
    if ( hasCargoType() ) {
        str.append( lead + "    CargoType = " + QString::number(m_cargoType) + "\n");
    }
    if ( hasDestination() ) {
        str.append( lead + "    Destination = " + m_destination + "\n");
    }
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-ddThh:mm:ss.zzzZ") + "\n");
    }
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + m_ATA.toString("yyyy-MM-ddThh:mm:ss.zzzZ") + "\n");
    }
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number(m_personsOnBoard) + "\n");
    }
    if ( hasAirDraught() ) {
        str.append( lead + "    AirDraught = " + QString::number(m_airDraught) + "\n");
    }
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number(m_draught) + "\n");
    }
    return str;
}

