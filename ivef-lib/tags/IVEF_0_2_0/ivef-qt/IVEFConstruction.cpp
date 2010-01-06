
#include "IVEFConstruction.h"

// Constructor
Construction::Construction() {

    // initialize empty string
    m_hullColor = "";
    // optional attributes are by default not present
    m_hullColorPresent = false;
    m_hullType = 0;
    // optional attributes are by default not present
    m_hullTypePresent = false;
    m_length = 0.0;
    // optional attributes are by default not present
    m_lengthPresent = false;
    m_lloydsShipType = 0;
    // optional attributes are by default not present
    m_lloydsShipTypePresent = false;
    m_maxKeelHeight = 0.0;
    // optional attributes are by default not present
    m_maxKeelHeightPresent = false;
    m_maxDraught = 0.0;
    // optional attributes are by default not present
    m_maxDraughtPresent = false;
    m_maxPersonsOnBoard = 0.0;
    // optional attributes are by default not present
    m_maxPersonsOnBoardPresent = false;
    m_maxSpeed = 0.0;
    // optional attributes are by default not present
    m_maxSpeedPresent = false;
    m_width = 0.0;
    // optional attributes are by default not present
    m_widthPresent = false;
}

// copy constructor
Construction::Construction(const Construction &val) : QObject() {

    m_unType = val.m_unType;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_hullTypePresent = val.m_hullTypePresent;
    m_hullType = val.m_hullType;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_maxKeelHeightPresent = val.m_maxKeelHeightPresent;
    m_maxKeelHeight = val.m_maxKeelHeight;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_maxPersonsOnBoardPresent = val.m_maxPersonsOnBoardPresent;
    m_maxPersonsOnBoard = val.m_maxPersonsOnBoard;
    m_maxSpeedPresent = val.m_maxSpeedPresent;
    m_maxSpeed = val.m_maxSpeed;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
}

// comperator
Construction & Construction::operator=(const Construction &val) {

    m_unType = val.m_unType;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_hullTypePresent = val.m_hullTypePresent;
    m_hullType = val.m_hullType;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_maxKeelHeightPresent = val.m_maxKeelHeightPresent;
    m_maxKeelHeight = val.m_maxKeelHeight;
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
QString Construction::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Construction
void Construction::setUnType(UnType val) {

    m_unType = val;
}

// getter for Construction
UnType Construction::getUnType() const {

    return m_unType;
}

// setter for Construction
void Construction::setHullColor(QString val) {

    m_hullColorPresent = true;
    m_hullColor = val;
}

// getter for Construction
QString Construction::getHullColor() const {

    return m_hullColor;
}

// check if optional element Construction has been set
bool Construction::hasHullColor() {

    return m_hullColorPresent;
}

// setter for Construction
void Construction::setHullType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_hullTypePresent = true;
    m_hullType = val;
}

// getter for Construction
int Construction::getHullType() const {

    return m_hullType;
}

// check if optional element Construction has been set
bool Construction::hasHullType() {

    return m_hullTypePresent;
}

// setter for Construction
void Construction::setLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_lengthPresent = true;
    m_length = val;
}

// getter for Construction
float Construction::getLength() const {

    return m_length;
}

// check if optional element Construction has been set
bool Construction::hasLength() {

    return m_lengthPresent;
}

// setter for Construction
void Construction::setLloydsShipType(int val) {

    m_lloydsShipTypePresent = true;
    m_lloydsShipType = val;
}

// getter for Construction
int Construction::getLloydsShipType() const {

    return m_lloydsShipType;
}

// check if optional element Construction has been set
bool Construction::hasLloydsShipType() {

    return m_lloydsShipTypePresent;
}

// setter for Construction
void Construction::setMaxKeelHeight(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_maxKeelHeightPresent = true;
    m_maxKeelHeight = val;
}

// getter for Construction
float Construction::getMaxKeelHeight() const {

    return m_maxKeelHeight;
}

// check if optional element Construction has been set
bool Construction::hasMaxKeelHeight() {

    return m_maxKeelHeightPresent;
}

// setter for Construction
void Construction::setMaxDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_maxDraughtPresent = true;
    m_maxDraught = val;
}

// getter for Construction
float Construction::getMaxDraught() const {

    return m_maxDraught;
}

// check if optional element Construction has been set
bool Construction::hasMaxDraught() {

    return m_maxDraughtPresent;
}

// setter for Construction
void Construction::setMaxPersonsOnBoard(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_maxPersonsOnBoardPresent = true;
    m_maxPersonsOnBoard = val;
}

// getter for Construction
float Construction::getMaxPersonsOnBoard() const {

    return m_maxPersonsOnBoard;
}

// check if optional element Construction has been set
bool Construction::hasMaxPersonsOnBoard() {

    return m_maxPersonsOnBoardPresent;
}

// setter for Construction
void Construction::setMaxSpeed(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_maxSpeedPresent = true;
    m_maxSpeed = val;
}

// getter for Construction
float Construction::getMaxSpeed() const {

    return m_maxSpeed;
}

// check if optional element Construction has been set
bool Construction::hasMaxSpeed() {

    return m_maxSpeedPresent;
}

// setter for Construction
void Construction::setWidth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_widthPresent = true;
    m_width = val;
}

// getter for Construction
float Construction::getWidth() const {

    return m_width;
}

// check if optional element Construction has been set
bool Construction::hasWidth() {

    return m_widthPresent;
}

// Get XML Representation
QString Construction::toXML() {

    QString xml = "<Construction";
    // check for presence of optional attribute
    if ( hasHullColor() ) {
        xml.append(" HullColor=\"" + encode (m_hullColor) + "\"");
    }
    // check for presence of optional attribute
    if ( hasHullType() ) {
        xml.append(" HullType=\"" + QString::number(m_hullType) + "\"");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    // check for presence of optional attribute
    if ( hasLloydsShipType() ) {
        xml.append(" LloydsShipType=\"" + QString::number(m_lloydsShipType) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxKeelHeight() ) {
        xml.append(" MaxKeelHeight=\"" + QString::number(m_maxKeelHeight) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught=\"" + QString::number(m_maxDraught) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxPersonsOnBoard() ) {
        xml.append(" MaxPersonsOnBoard=\"" + QString::number(m_maxPersonsOnBoard) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxSpeed() ) {
        xml.append(" MaxSpeed=\"" + QString::number(m_maxSpeed) + "\"");
    }
    // check for presence of optional attribute
    if ( hasWidth() ) {
        xml.append(" Width=\"" + QString::number(m_width) + "\"");
    }
    xml.append(">\n");
    xml.append( m_unType.toXML() );
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
        str.append( lead + "    HullType = " + QString::number(m_hullType) + "\n");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    // check for presence of optional attribute
    if ( hasLloydsShipType() ) {
        str.append( lead + "    LloydsShipType = " + QString::number(m_lloydsShipType) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxKeelHeight() ) {
        str.append( lead + "    MaxKeelHeight = " + QString::number(m_maxKeelHeight) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxPersonsOnBoard() ) {
        str.append( lead + "    MaxPersonsOnBoard = " + QString::number(m_maxPersonsOnBoard) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxSpeed() ) {
        str.append( lead + "    MaxSpeed = " + QString::number(m_maxSpeed) + "\n");
    }
    // check for presence of optional attribute
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number(m_width) + "\n");
    }
    str.append( m_unType.toString(lead + "    ") );
    return str;
}

