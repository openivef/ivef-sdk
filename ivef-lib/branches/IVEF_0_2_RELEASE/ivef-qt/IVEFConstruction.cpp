
#include "IVEFConstruction.h"

// Constructor
Construction::Construction() {

    m_unTypePresent = false;
    // initialize empty string
    m_hullColor = "";
    m_hullColorPresent = false;
    m_hullType = 0;
    m_hullTypePresent = false;
    m_deadWeight = 0.0;
    m_deadWeightPresent = false;
    m_grossWeight = 0.0;
    m_grossWeightPresent = false;
    m_length = 0.0;
    m_lengthPresent = false;
    m_lloydsShipType = 0;
    m_lloydsShipTypePresent = false;
    m_yearOfBuild = 0;
    m_yearOfBuildPresent = false;
    m_maxAirDraught = 0.0;
    m_maxAirDraughtPresent = false;
    m_maxDraught = 0.0;
    m_maxDraughtPresent = false;
    m_maxPersonsOnBoard = 0;
    m_maxPersonsOnBoardPresent = false;
    m_maxSpeed = 0.0;
    m_maxSpeedPresent = false;
    m_width = 0.0;
    m_widthPresent = false;
}

// copy constructor
Construction::Construction(const Construction &val) : QObject() {

    m_unTypePresent = val.m_unTypePresent;
    m_unType = val.m_unType;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_hullTypePresent = val.m_hullTypePresent;
    m_hullType = val.m_hullType;
    m_deadWeightPresent = val.m_deadWeightPresent;
    m_deadWeight = val.m_deadWeight;
    m_grossWeightPresent = val.m_grossWeightPresent;
    m_grossWeight = val.m_grossWeight;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_yearOfBuildPresent = val.m_yearOfBuildPresent;
    m_yearOfBuild = val.m_yearOfBuild;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_maxPersonsOnBoardPresent = val.m_maxPersonsOnBoardPresent;
    m_maxPersonsOnBoard = val.m_maxPersonsOnBoard;
    m_maxSpeedPresent = val.m_maxSpeedPresent;
    m_maxSpeed = val.m_maxSpeed;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
}

// assignement
Construction & Construction::operator=(const Construction &val) {

    m_unTypePresent = val.m_unTypePresent;
    m_unType = val.m_unType;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_hullTypePresent = val.m_hullTypePresent;
    m_hullType = val.m_hullType;
    m_deadWeightPresent = val.m_deadWeightPresent;
    m_deadWeight = val.m_deadWeight;
    m_grossWeightPresent = val.m_grossWeightPresent;
    m_grossWeight = val.m_grossWeight;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_yearOfBuildPresent = val.m_yearOfBuildPresent;
    m_yearOfBuild = val.m_yearOfBuild;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_maxPersonsOnBoardPresent = val.m_maxPersonsOnBoardPresent;
    m_maxPersonsOnBoard = val.m_maxPersonsOnBoard;
    m_maxSpeedPresent = val.m_maxSpeedPresent;
    m_maxSpeed = val.m_maxSpeed;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
    return *this;
}

// String encoder
QString Construction::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Construction
bool Construction::setUnType(UnType val) {

    m_unTypePresent = true;
    m_unType = val;
      return true;
}

// getter for Construction
UnType Construction::getUnType() const {

    return m_unType;
}

// check if optional element Construction has been set
bool Construction::hasUnType() const {

    return m_unTypePresent;
}

// setter for Construction
bool Construction::setHullColor(QString val) {

    m_hullColorPresent = true;
    m_hullColor = val;
      return true;
}

// getter for Construction
QString Construction::getHullColor() const {

    return m_hullColor;
}

// check if optional element Construction has been set
bool Construction::hasHullColor() const {

    return m_hullColorPresent;
}

// setter for Construction
bool Construction::setHullType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_hullTypePresent = true;
    m_hullType = val;
      return true;
}

// getter for Construction
int Construction::getHullType() const {

    return m_hullType;
}

// check if optional element Construction has been set
bool Construction::hasHullType() const {

    return m_hullTypePresent;
}

// setter for Construction
bool Construction::setDeadWeight(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_deadWeightPresent = true;
    m_deadWeight = val;
      return true;
}

// getter for Construction
float Construction::getDeadWeight() const {

    return m_deadWeight;
}

// check if optional element Construction has been set
bool Construction::hasDeadWeight() const {

    return m_deadWeightPresent;
}

// setter for Construction
bool Construction::setGrossWeight(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_grossWeightPresent = true;
    m_grossWeight = val;
      return true;
}

// getter for Construction
float Construction::getGrossWeight() const {

    return m_grossWeight;
}

// check if optional element Construction has been set
bool Construction::hasGrossWeight() const {

    return m_grossWeightPresent;
}

// setter for Construction
bool Construction::setLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_lengthPresent = true;
    m_length = val;
      return true;
}

// getter for Construction
float Construction::getLength() const {

    return m_length;
}

// check if optional element Construction has been set
bool Construction::hasLength() const {

    return m_lengthPresent;
}

// setter for Construction
bool Construction::setLloydsShipType(int val) {

    m_lloydsShipTypePresent = true;
    m_lloydsShipType = val;
      return true;
}

// getter for Construction
int Construction::getLloydsShipType() const {

    return m_lloydsShipType;
}

// check if optional element Construction has been set
bool Construction::hasLloydsShipType() const {

    return m_lloydsShipTypePresent;
}

// setter for Construction
bool Construction::setYearOfBuild(int val) {

    m_yearOfBuildPresent = true;
    m_yearOfBuild = val;
      return true;
}

// getter for Construction
int Construction::getYearOfBuild() const {

    return m_yearOfBuild;
}

// check if optional element Construction has been set
bool Construction::hasYearOfBuild() const {

    return m_yearOfBuildPresent;
}

// setter for Construction
bool Construction::setMaxAirDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
      return true;
}

// getter for Construction
float Construction::getMaxAirDraught() const {

    return m_maxAirDraught;
}

// check if optional element Construction has been set
bool Construction::hasMaxAirDraught() const {

    return m_maxAirDraughtPresent;
}

// setter for Construction
bool Construction::setMaxDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_maxDraughtPresent = true;
    m_maxDraught = val;
      return true;
}

// getter for Construction
float Construction::getMaxDraught() const {

    return m_maxDraught;
}

// check if optional element Construction has been set
bool Construction::hasMaxDraught() const {

    return m_maxDraughtPresent;
}

// setter for Construction
bool Construction::setMaxPersonsOnBoard(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_maxPersonsOnBoardPresent = true;
    m_maxPersonsOnBoard = val;
      return true;
}

// getter for Construction
int Construction::getMaxPersonsOnBoard() const {

    return m_maxPersonsOnBoard;
}

// check if optional element Construction has been set
bool Construction::hasMaxPersonsOnBoard() const {

    return m_maxPersonsOnBoardPresent;
}

// setter for Construction
bool Construction::setMaxSpeed(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_maxSpeedPresent = true;
    m_maxSpeed = val;
      return true;
}

// getter for Construction
float Construction::getMaxSpeed() const {

    return m_maxSpeed;
}

// check if optional element Construction has been set
bool Construction::hasMaxSpeed() const {

    return m_maxSpeedPresent;
}

// setter for Construction
bool Construction::setWidth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_widthPresent = true;
    m_width = val;
      return true;
}

// getter for Construction
float Construction::getWidth() const {

    return m_width;
}

// check if optional element Construction has been set
bool Construction::hasWidth() const {

    return m_widthPresent;
}

// Get XML Representation
QString Construction::toXML() const {

    QString xml = "<Construction";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasHullColor() ) {
        xml.append(" HullColor=\"" + encode (m_hullColor) + "\"");
    }
    // check for presence of optional attribute
    if ( hasHullType() ) {
        xml.append(" HullType=\"" + QString::number( m_hullType ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDeadWeight() ) {
        xml.append(" DeadWeight=\"" + QString::number( m_deadWeight, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasGrossWeight() ) {
        xml.append(" GrossWeight=\"" + QString::number( m_grossWeight, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number( m_length, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasLloydsShipType() ) {
        xml.append(" LloydsShipType=\"" + QString::number( m_lloydsShipType ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasYearOfBuild() ) {
        xml.append(" YearOfBuild=\"" + QString::number( m_yearOfBuild ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxAirDraught() ) {
        xml.append(" MaxAirDraught=\"" + QString::number(m_maxAirDraught, 'f', 1) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught=\"" + QString::number(m_maxDraught, 'f', 1) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxPersonsOnBoard() ) {
        xml.append(" MaxPersonsOnBoard=\"" + QString::number( m_maxPersonsOnBoard ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxSpeed() ) {
        xml.append(" MaxSpeed=\"" + QString::number( m_maxSpeed, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasWidth() ) {
        xml.append(" Width=\"" + QString::number( m_width, 'f') + "\"");
    }
    xml.append(">\n");
    // add optional data if available
    if ( hasUnType() ) {
        dataMember = m_unType.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    xml.append( "</Construction>\n");
    return xml;
}

// Get String Representation
QString Construction::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Construction::toString(QString lead) {

    QString str = lead + "Construction\n";
    // check for presence of optional attribute
    if ( hasHullColor() ) {
        str.append( lead + "    HullColor = " + m_hullColor + "\n");
    }
    // check for presence of optional attribute
    if ( hasHullType() ) {
        str.append( lead + "    HullType = " + QString::number( m_hullType ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasDeadWeight() ) {
        str.append( lead + "    DeadWeight = " + QString::number( m_deadWeight, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasGrossWeight() ) {
        str.append( lead + "    GrossWeight = " + QString::number( m_grossWeight, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number( m_length, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasLloydsShipType() ) {
        str.append( lead + "    LloydsShipType = " + QString::number( m_lloydsShipType ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasYearOfBuild() ) {
        str.append( lead + "    YearOfBuild = " + QString::number( m_yearOfBuild ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxAirDraught() ) {
        str.append( lead + "    MaxAirDraught = " + QString::number(m_maxAirDraught, 'f', 1) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught, 'f', 1) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxPersonsOnBoard() ) {
        str.append( lead + "    MaxPersonsOnBoard = " + QString::number( m_maxPersonsOnBoard ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxSpeed() ) {
        str.append( lead + "    MaxSpeed = " + QString::number( m_maxSpeed, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number( m_width, 'f') + "\n");
    }
    // add all optional data if present
    if ( hasUnType() ) {
        str.append( m_unType.toString(lead + "    ") );
    }
    return str;
}

