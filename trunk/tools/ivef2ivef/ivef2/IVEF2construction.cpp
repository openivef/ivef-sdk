
#include "IVEF2construction.h"

Construction::Construction() {

    m_typePresent = false;
    m_lloydsShipTypePresent = false;
    m_lengthPresent = false;
    m_breadthPresent = false;
    m_maxAirDraughtPresent = false;
    m_maxDraughtPresent = false;
    m_deepWaterPresent = false;
    m_hullMaterialPresent = false;
    m_hullColorPresent = false;
    m_constructorPresent = false;
    m_grossWeightPresent = false;
    m_netWeightPresent = false;
    m_deadWeightPresent = false;
    m_maxPassengerPresent = false;
    m_maxCrewPresent = false;
    m_maxSupportPresent = false;
    m_maxSpeedPresent = false;
}

Construction::Construction(const Construction &val) : QObject() {

    m_typePresent = val.m_typePresent;
    m_type = val.m_type;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_breadthPresent = val.m_breadthPresent;
    m_breadth = val.m_breadth;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_deepWaterPresent = val.m_deepWaterPresent;
    m_deepWater = val.m_deepWater;
    m_hullMaterialPresent = val.m_hullMaterialPresent;
    m_hullMaterial = val.m_hullMaterial;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_constructorPresent = val.m_constructorPresent;
    m_constructor = val.m_constructor;
    m_grossWeightPresent = val.m_grossWeightPresent;
    m_grossWeight = val.m_grossWeight;
    m_netWeightPresent = val.m_netWeightPresent;
    m_netWeight = val.m_netWeight;
    m_deadWeightPresent = val.m_deadWeightPresent;
    m_deadWeight = val.m_deadWeight;
    m_maxPassengerPresent = val.m_maxPassengerPresent;
    m_maxPassenger = val.m_maxPassenger;
    m_maxCrewPresent = val.m_maxCrewPresent;
    m_maxCrew = val.m_maxCrew;
    m_maxSupportPresent = val.m_maxSupportPresent;
    m_maxSupport = val.m_maxSupport;
    m_maxSpeedPresent = val.m_maxSpeedPresent;
    m_maxSpeed = val.m_maxSpeed;
}

Construction & Construction::operator=(const Construction &val) {

    m_typePresent = val.m_typePresent;
    m_type = val.m_type;
    m_lloydsShipTypePresent = val.m_lloydsShipTypePresent;
    m_lloydsShipType = val.m_lloydsShipType;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_breadthPresent = val.m_breadthPresent;
    m_breadth = val.m_breadth;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_deepWaterPresent = val.m_deepWaterPresent;
    m_deepWater = val.m_deepWater;
    m_hullMaterialPresent = val.m_hullMaterialPresent;
    m_hullMaterial = val.m_hullMaterial;
    m_hullColorPresent = val.m_hullColorPresent;
    m_hullColor = val.m_hullColor;
    m_constructorPresent = val.m_constructorPresent;
    m_constructor = val.m_constructor;
    m_grossWeightPresent = val.m_grossWeightPresent;
    m_grossWeight = val.m_grossWeight;
    m_netWeightPresent = val.m_netWeightPresent;
    m_netWeight = val.m_netWeight;
    m_deadWeightPresent = val.m_deadWeightPresent;
    m_deadWeight = val.m_deadWeight;
    m_maxPassengerPresent = val.m_maxPassengerPresent;
    m_maxPassenger = val.m_maxPassenger;
    m_maxCrewPresent = val.m_maxCrewPresent;
    m_maxCrew = val.m_maxCrew;
    m_maxSupportPresent = val.m_maxSupportPresent;
    m_maxSupport = val.m_maxSupport;
    m_maxSpeedPresent = val.m_maxSpeedPresent;
    m_maxSpeed = val.m_maxSpeed;
    return *this;
}

void Construction::setType(int val) {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) &&
         ( val != 9 ) &&
         ( val != 10 ) &&
         ( val != 11 ) &&
         ( val != 12 ) &&
         ( val != 13 ) &&
         ( val != 14 ) &&
         ( val != 15 ) &&
         ( val != 16 ) &&
         ( val != 17 ) &&
         ( val != 18 ) &&
         ( val != 19 ) &&
         ( val != 20 ) &&
         ( val != 21 ) &&
         ( val != 22 ) &&
         ( val != 23 ) &&
         ( val != 24 ) &&
         ( val != 25 ) &&
         ( val != 26 ) &&
         ( val != 27 ) &&
         ( val != 28 ) &&
         ( val != 29 ) &&
         ( val != 30 ) &&
         ( val != 31 ) &&
         ( val != 32 ) &&
         ( val != 33 ) &&
         ( val != 120 ) &&
         ( val != 130 ) &&
         ( val != 131 ) &&
         ( val != 132 ) &&
         ( val != 133 ) &&
         ( val != 134 ) &&
         ( val != 135 ) &&
         ( val != 136 ) &&
         ( val != 137 ) &&
         ( val != 140 ) &&
         ( val != 150 ) &&
         ( val != 151 ) &&
         ( val != 152 ) &&
         ( val != 153 ) &&
         ( val != 154 ) &&
         ( val != 155 ) &&
         ( val != 158 ) &&
         ( val != 159 ) &&
         ( val != 160 ) &&
         ( val != 170 ) &&
         ( val != 180 ) &&
         ( val != 190 ) &&
         ( val != 191 ) )
        return;
    m_typePresent = true;
    m_type = val;
}

int Construction::getType() const {

    return m_type;
}

bool Construction::hasType() {

    return m_typePresent;
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

void Construction::setBreadth(float val) {

    m_breadthPresent = true;
    m_breadth = val;
}

float Construction::getBreadth() const {

    return m_breadth;
}

bool Construction::hasBreadth() {

    return m_breadthPresent;
}

void Construction::setMaxAirDraught(float val) {

    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
}

float Construction::getMaxAirDraught() const {

    return m_maxAirDraught;
}

bool Construction::hasMaxAirDraught() {

    return m_maxAirDraughtPresent;
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

void Construction::setDeepWater(bool val) {

    m_deepWaterPresent = true;
    m_deepWater = val;
}

bool Construction::getDeepWater() const {

    return m_deepWater;
}

bool Construction::hasDeepWater() {

    return m_deepWaterPresent;
}

void Construction::setHullMaterial(QString val) {

    m_hullMaterialPresent = true;
    m_hullMaterial = val;
}

QString Construction::getHullMaterial() const {

    return m_hullMaterial;
}

bool Construction::hasHullMaterial() {

    return m_hullMaterialPresent;
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

void Construction::setConstructor(QString val) {

    m_constructorPresent = true;
    m_constructor = val;
}

QString Construction::getConstructor() const {

    return m_constructor;
}

bool Construction::hasConstructor() {

    return m_constructorPresent;
}

void Construction::setGrossWeight(float val) {

    m_grossWeightPresent = true;
    m_grossWeight = val;
}

float Construction::getGrossWeight() const {

    return m_grossWeight;
}

bool Construction::hasGrossWeight() {

    return m_grossWeightPresent;
}

void Construction::setNetWeight(float val) {

    m_netWeightPresent = true;
    m_netWeight = val;
}

float Construction::getNetWeight() const {

    return m_netWeight;
}

bool Construction::hasNetWeight() {

    return m_netWeightPresent;
}

void Construction::setDeadWeight(float val) {

    m_deadWeightPresent = true;
    m_deadWeight = val;
}

float Construction::getDeadWeight() const {

    return m_deadWeight;
}

bool Construction::hasDeadWeight() {

    return m_deadWeightPresent;
}

void Construction::setMaxPassenger(float val) {

    m_maxPassengerPresent = true;
    m_maxPassenger = val;
}

float Construction::getMaxPassenger() const {

    return m_maxPassenger;
}

bool Construction::hasMaxPassenger() {

    return m_maxPassengerPresent;
}

void Construction::setMaxCrew(float val) {

    m_maxCrewPresent = true;
    m_maxCrew = val;
}

float Construction::getMaxCrew() const {

    return m_maxCrew;
}

bool Construction::hasMaxCrew() {

    return m_maxCrewPresent;
}

void Construction::setMaxSupport(float val) {

    m_maxSupportPresent = true;
    m_maxSupport = val;
}

float Construction::getMaxSupport() const {

    return m_maxSupport;
}

bool Construction::hasMaxSupport() {

    return m_maxSupportPresent;
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

QString Construction::toXML() {

    QString xml = "<Construction";
    if ( hasType() ) {
        xml.append(" Type=\"" + QString::number(m_type) + "\"");
    }
    if ( hasLloydsShipType() ) {
        xml.append(" LloydsShipType=\"" + QString::number(m_lloydsShipType) + "\"");
    }
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    if ( hasBreadth() ) {
        xml.append(" Breadth=\"" + QString::number(m_breadth) + "\"");
    }
    if ( hasMaxAirDraught() ) {
        xml.append(" MaxAirDraught=\"" + QString::number(m_maxAirDraught) + "\"");
    }
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught=\"" + QString::number(m_maxDraught) + "\"");
    }
    if ( hasDeepWater() ) {
        xml.append(" DeepWater=\"" + QString::number(m_deepWater) + "\"");
    }
    if ( hasHullMaterial() ) {
        xml.append(" HullMaterial=\"" + m_hullMaterial + "\"");
    }
    if ( hasHullColor() ) {
        xml.append(" HullColor=\"" + m_hullColor + "\"");
    }
    if ( hasConstructor() ) {
        xml.append(" Constructor=\"" + m_constructor + "\"");
    }
    if ( hasGrossWeight() ) {
        xml.append(" GrossWeight=\"" + QString::number(m_grossWeight) + "\"");
    }
    if ( hasNetWeight() ) {
        xml.append(" NetWeight=\"" + QString::number(m_netWeight) + "\"");
    }
    if ( hasDeadWeight() ) {
        xml.append(" DeadWeight=\"" + QString::number(m_deadWeight) + "\"");
    }
    if ( hasMaxPassenger() ) {
        xml.append(" MaxPassenger=\"" + QString::number(m_maxPassenger) + "\"");
    }
    if ( hasMaxCrew() ) {
        xml.append(" MaxCrew=\"" + QString::number(m_maxCrew) + "\"");
    }
    if ( hasMaxSupport() ) {
        xml.append(" MaxSupport=\"" + QString::number(m_maxSupport) + "\"");
    }
    if ( hasMaxSpeed() ) {
        xml.append(" MaxSpeed=\"" + QString::number(m_maxSpeed) + "\"");
    }
    xml.append(">\n");
    xml.append( "</Construction>\n");
    return xml;
}

QString Construction::toString(QString lead) {

    QString str = lead + "Construction\n";
    if ( hasType() ) {
        str.append( lead + "    Type = " + QString::number(m_type) + "\n");
    }
    if ( hasLloydsShipType() ) {
        str.append( lead + "    LloydsShipType = " + QString::number(m_lloydsShipType) + "\n");
    }
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    if ( hasBreadth() ) {
        str.append( lead + "    Breadth = " + QString::number(m_breadth) + "\n");
    }
    if ( hasMaxAirDraught() ) {
        str.append( lead + "    MaxAirDraught = " + QString::number(m_maxAirDraught) + "\n");
    }
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught) + "\n");
    }
    if ( hasDeepWater() ) {
        str.append( lead + "    DeepWater = " + QString::number(m_deepWater) + "\n");
    }
    if ( hasHullMaterial() ) {
        str.append( lead + "    HullMaterial = " + m_hullMaterial + "\n");
    }
    if ( hasHullColor() ) {
        str.append( lead + "    HullColor = " + m_hullColor + "\n");
    }
    if ( hasConstructor() ) {
        str.append( lead + "    Constructor = " + m_constructor + "\n");
    }
    if ( hasGrossWeight() ) {
        str.append( lead + "    GrossWeight = " + QString::number(m_grossWeight) + "\n");
    }
    if ( hasNetWeight() ) {
        str.append( lead + "    NetWeight = " + QString::number(m_netWeight) + "\n");
    }
    if ( hasDeadWeight() ) {
        str.append( lead + "    DeadWeight = " + QString::number(m_deadWeight) + "\n");
    }
    if ( hasMaxPassenger() ) {
        str.append( lead + "    MaxPassenger = " + QString::number(m_maxPassenger) + "\n");
    }
    if ( hasMaxCrew() ) {
        str.append( lead + "    MaxCrew = " + QString::number(m_maxCrew) + "\n");
    }
    if ( hasMaxSupport() ) {
        str.append( lead + "    MaxSupport = " + QString::number(m_maxSupport) + "\n");
    }
    if ( hasMaxSpeed() ) {
        str.append( lead + "    MaxSpeed = " + QString::number(m_maxSpeed) + "\n");
    }
    return str;
}

