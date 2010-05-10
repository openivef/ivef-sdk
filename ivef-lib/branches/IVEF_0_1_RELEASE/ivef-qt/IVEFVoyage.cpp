
#include "IVEFVoyage.h"

// Constructor
Voyage::Voyage() {

    // initialize empty string
    m_id = "";
    m_idPresent = false;
    m_idPresent = false;
    m_idPresent = false;
    // initialize empty string
    m_sourceName = "";
    m_sourceNamePresent = false;
    m_sourceNamePresent = false;
    m_sourceNamePresent = false;
    m_source = 0;
    m_sourcePresent = false;
    m_cargoType = 0;
    m_cargoTypePresent = false;
    // initialize empty string
    m_destination = "";
    m_destinationPresent = false;
    m_destinationPresent = false;
    m_destinationPresent = false;
    // initialize with random value
    m_ETA = QDateTime();
    m_ETAPresent = false;
    // initialize with random value
    m_ATA = QDateTime();
    m_ATAPresent = false;
    m_personsOnBoard = 0;
    m_personsOnBoardPresent = false;
    m_airDraught = 0.0;
    m_airDraughtPresent = false;
    m_draught = 0.0;
    m_draughtPresent = false;
}

// copy constructor
Voyage::Voyage(const Voyage &val) : QObject() {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourcePresent = val.m_sourcePresent;
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

// assignement
Voyage & Voyage::operator=(const Voyage &val) {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourcePresent = val.m_sourcePresent;
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

// String encoder
QString Voyage::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Voyage
bool Voyage::setId(QString val) {

    m_idPresent = true;
    m_id = val;
      return true;
}

// getter for Voyage
QString Voyage::getId() const {

    return m_id;
}

// setter for Voyage
bool Voyage::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
      return true;
}

// getter for Voyage
QString Voyage::getSourceName() const {

    return m_sourceName;
}

// setter for Voyage
bool Voyage::setSource(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_sourcePresent = true;
    m_source = val;
      return true;
}

// getter for Voyage
int Voyage::getSource() const {

    return m_source;
}

// setter for Voyage
bool Voyage::setCargoType(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 9 ) )
        return false;
    m_cargoTypePresent = true;
    m_cargoType = val;
      return true;
}

// getter for Voyage
int Voyage::getCargoType() const {

    return m_cargoType;
}

// check if optional element Voyage has been set
bool Voyage::hasCargoType() const {

    return m_cargoTypePresent;
}

// setter for Voyage
bool Voyage::setDestination(QString val) {

    m_destinationPresent = true;
    m_destination = val;
      return true;
}

// getter for Voyage
QString Voyage::getDestination() const {

    return m_destination;
}

// check if optional element Voyage has been set
bool Voyage::hasDestination() const {

    return m_destinationPresent;
}

// setter for Voyage
bool Voyage::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
      return true;
}

// getter for Voyage
QDateTime Voyage::getETA() const {

    return m_ETA;
}

// check if optional element Voyage has been set
bool Voyage::hasETA() const {

    return m_ETAPresent;
}

// setter for Voyage
bool Voyage::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
      return true;
}

// getter for Voyage
QDateTime Voyage::getATA() const {

    return m_ATA;
}

// check if optional element Voyage has been set
bool Voyage::hasATA() const {

    return m_ATAPresent;
}

// setter for Voyage
bool Voyage::setPersonsOnBoard(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
      return true;
}

// getter for Voyage
int Voyage::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

// check if optional element Voyage has been set
bool Voyage::hasPersonsOnBoard() const {

    return m_personsOnBoardPresent;
}

// setter for Voyage
bool Voyage::setAirDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_airDraughtPresent = true;
    m_airDraught = val;
      return true;
}

// getter for Voyage
float Voyage::getAirDraught() const {

    return m_airDraught;
}

// check if optional element Voyage has been set
bool Voyage::hasAirDraught() const {

    return m_airDraughtPresent;
}

// setter for Voyage
bool Voyage::setDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_draughtPresent = true;
    m_draught = val;
      return true;
}

// getter for Voyage
float Voyage::getDraught() const {

    return m_draught;
}

// check if optional element Voyage has been set
bool Voyage::hasDraught() const {

    return m_draughtPresent;
}

// Get XML Representation
QString Voyage::toXML() const {

    QString xml = "<Voyage";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_idPresent) {
        xml.append(" Id=\"" + m_id + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourceNamePresent) {
        xml.append(" SourceName=\"" + m_sourceName + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourcePresent) {
        xml.append(" Source=\"" + QString::number( m_source ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasCargoType() ) {
        xml.append(" CargoType=\"" + QString::number( m_cargoType ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDestination() ) {
        xml.append(" Destination=\"" + m_destination + "\"");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasATA() ) {
        xml.append(" ATA=\"" + m_ATA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        xml.append(" PersonsOnBoard=\"" + QString::number( m_personsOnBoard ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasAirDraught() ) {
        xml.append(" AirDraught=\"" + QString::number( m_airDraught, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        xml.append(" Draught=\"" + QString::number( m_draught, 'f') + "\"");
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Voyage::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Voyage::toString(QString lead) {

    QString str = lead + "Voyage\n";
     str.append( lead + "    Id = " + m_id + "\n");
     str.append( lead + "    SourceName = " + m_sourceName + "\n");
     str.append( lead + "    Source = " + QString::number( m_source ) + "\n");
    // check for presence of optional attribute
    if ( hasCargoType() ) {
        str.append( lead + "    CargoType = " + QString::number( m_cargoType ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasDestination() ) {
        str.append( lead + "    Destination = " + m_destination + "\n");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + m_ATA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number( m_personsOnBoard ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasAirDraught() ) {
        str.append( lead + "    AirDraught = " + QString::number( m_airDraught, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number( m_draught, 'f') + "\n");
    }
    return str;
}

