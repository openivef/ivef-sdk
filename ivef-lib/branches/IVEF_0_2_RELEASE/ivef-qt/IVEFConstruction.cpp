
#include "IVEFConstruction.h"

Construction::Construction() {

    m_hullColor = "";
    m_hullColorPresent = false;
    m_hullType = 0;
    m_hullTypePresent = false;
    m_length = 0.0;
    m_lengthPresent = false;
    m_lloydsShipType = 0;
    m_lloydsShipTypePresent = false;
    m_maxKeelHeight = 0.0;
    m_maxKeelHeightPresent = false;
    m_maxDraught = 0.0;
    m_maxDraughtPresent = false;
    m_maxPersonsOnBoard = 0.0;
    m_maxPersonsOnBoardPresent = false;
    m_maxSpeed = 0.0;
    m_maxSpeedPresent = false;
    m_width = 0.0;
    m_widthPresent = false;
}

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

QString Construction::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Construction::setUnType(UnType val) {

    m_unType = val;
}

UnType Construction::getUnType() const {

    return m_unType;
}

void Construction::setHullColor(QString val) {

    m_hullColorPresent = true;
    m_hullColor = val;
}

QString Construction::getHullColor() const {

    return m_hullColor;
}

bool Construction::hasHullColor() {

    return m_hullColorPresent;
}

void Construction::setHullType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_hullTypePresent = true;
    m_hullType = val;
}

int Construction::getHullType() const {

    return m_hullType;
}

bool Construction::hasHullType() {

    return m_hullTypePresent;
}

void Construction::setLength(float val) {

    m_lengthPresent = true;
    m_length = val;
}

float Construction::getLength() const {

    return m_length;
}

bool Construction::hasLength() {

    return m_lengthPresent;
}

void Construction::setLloydsShipType(int val) {

    m_lloydsShipTypePresent = true;
    m_lloydsShipType = val;
}

int Construction::getLloydsShipType() const {

    return m_lloydsShipType;
}

bool Construction::hasLloydsShipType() {

    return m_lloydsShipTypePresent;
}

void Construction::setMaxKeelHeight(float val) {

    m_maxKeelHeightPresent = true;
    m_maxKeelHeight = val;
}

float Construction::getMaxKeelHeight() const {

    return m_maxKeelHeight;
}

bool Construction::hasMaxKeelHeight() {

    return m_maxKeelHeightPresent;
}

void Construction::setMaxDraught(float val) {

    m_maxDraughtPresent = true;
    m_maxDraught = val;
}

float Construction::getMaxDraught() const {

    return m_maxDraught;
}

bool Construction::hasMaxDraught() {

    return m_maxDraughtPresent;
}

void Construction::setMaxPersonsOnBoard(float val) {

    m_maxPersonsOnBoardPresent = true;
    m_maxPersonsOnBoard = val;
}

float Construction::getMaxPersonsOnBoard() const {

    return m_maxPersonsOnBoard;
}

bool Construction::hasMaxPersonsOnBoard() {

    return m_maxPersonsOnBoardPresent;
}

void Construction::setMaxSpeed(float val) {

    m_maxSpeedPresent = true;
    m_maxSpeed = val;
}

float Construction::getMaxSpeed() const {

    return m_maxSpeed;
}

bool Construction::hasMaxSpeed() {

    return m_maxSpeedPresent;
}

void Construction::setWidth(float val) {

    m_widthPresent = true;
    m_width = val;
}

float Construction::getWidth() const {

    return m_width;
}

bool Construction::hasWidth() {

    return m_widthPresent;
}

QString Construction::toXML() {

    QString xml = "<Construction";
    if ( hasHullColor() ) {
        xml.append(" HullColor=\"" + encode (m_hullColor) + "\"");
    }
    if ( hasHullType() ) {
        xml.append(" HullType=\"" + QString::number(m_hullType) + "\"");
    }
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    if ( hasLloydsShipType() ) {
        xml.append(" LloydsShipType=\"" + QString::number(m_lloydsShipType) + "\"");
    }
    if ( hasMaxKeelHeight() ) {
        xml.append(" MaxKeelHeight=\"" + QString::number(m_maxKeelHeight) + "\"");
    }
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught=\"" + QString::number(m_maxDraught) + "\"");
    }
    if ( hasMaxPersonsOnBoard() ) {
        xml.append(" MaxPersonsOnBoard=\"" + QString::number(m_maxPersonsOnBoard) + "\"");
    }
    if ( hasMaxSpeed() ) {
        xml.append(" MaxSpeed=\"" + QString::number(m_maxSpeed) + "\"");
    }
    if ( hasWidth() ) {
        xml.append(" Width=\"" + QString::number(m_width) + "\"");
    }
    xml.append(">\n");
    xml.append( m_unType.toXML() );
    xml.append( "</Construction>\n");
    return xml;
}

QString Construction::toString(QString lead) {

    QString str = lead + "Construction\n";
    if ( hasHullColor() ) {
        str.append( lead + "    HullColor = " + m_hullColor + "\n");
    }
    if ( hasHullType() ) {
        str.append( lead + "    HullType = " + QString::number(m_hullType) + "\n");
    }
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    if ( hasLloydsShipType() ) {
        str.append( lead + "    LloydsShipType = " + QString::number(m_lloydsShipType) + "\n");
    }
    if ( hasMaxKeelHeight() ) {
        str.append( lead + "    MaxKeelHeight = " + QString::number(m_maxKeelHeight) + "\n");
    }
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught) + "\n");
    }
    if ( hasMaxPersonsOnBoard() ) {
        str.append( lead + "    MaxPersonsOnBoard = " + QString::number(m_maxPersonsOnBoard) + "\n");
    }
    if ( hasMaxSpeed() ) {
        str.append( lead + "    MaxSpeed = " + QString::number(m_maxSpeed) + "\n");
    }
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number(m_width) + "\n");
    }
    str.append( m_unType.toString(lead + "    ") );
    return str;
}

