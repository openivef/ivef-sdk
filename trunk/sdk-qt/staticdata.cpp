
#include "staticdata.h"

StaticData::StaticData() {

    m_lengthPresent = false;
    m_breadthPresent = false;
    m_callsignPresent = false;
    m_shipNamePresent = false;
    m_objectTypePresent = false;
    m_shipTypePresent = false;
    m_IMOPresent = false;
    m_MMSIPresent = false;
    m_ATONTypePresent = false;
    m_ATONNamePresent = false;
    m_antPosDistFromFrontPresent = false;
    m_antPosDistFromLeftPresent = false;
    m_natLangShipNamePresent = false;
    m_portOfRegistryPresent = false;
    m_countryFlagPresent = false;
    m_maxAirDraughtPresent = false;
    m_maxDraughtPresent = false;
    m_deepWaterVesselindPresent = false;
}

StaticData::StaticData(const StaticData &val) : QObject() {

    m_id = ((StaticData)val).getId();
    m_sourceName = ((StaticData)val).getSourceName();
    m_source = ((StaticData)val).getSource();
    m_lengthPresent = false;
    m_length = ((StaticData)val).getLength();
    m_breadthPresent = false;
    m_breadth = ((StaticData)val).getBreadth();
    m_callsignPresent = false;
    m_callsign = ((StaticData)val).getCallsign();
    m_shipNamePresent = false;
    m_shipName = ((StaticData)val).getShipName();
    m_objectTypePresent = false;
    m_objectType = ((StaticData)val).getObjectType();
    m_shipTypePresent = false;
    m_shipType = ((StaticData)val).getShipType();
    m_IMOPresent = false;
    m_IMO = ((StaticData)val).getIMO();
    m_MMSIPresent = false;
    m_MMSI = ((StaticData)val).getMMSI();
    m_ATONTypePresent = false;
    m_ATONType = ((StaticData)val).getATONType();
    m_ATONNamePresent = false;
    m_ATONName = ((StaticData)val).getATONName();
    m_antPosDistFromFrontPresent = false;
    m_antPosDistFromFront = ((StaticData)val).getAntPosDistFromFront();
    m_antPosDistFromLeftPresent = false;
    m_antPosDistFromLeft = ((StaticData)val).getAntPosDistFromLeft();
    m_natLangShipNamePresent = false;
    m_natLangShipName = ((StaticData)val).getNatLangShipName();
    m_portOfRegistryPresent = false;
    m_portOfRegistry = ((StaticData)val).getPortOfRegistry();
    m_countryFlagPresent = false;
    m_countryFlag = ((StaticData)val).getCountryFlag();
    m_maxAirDraughtPresent = false;
    m_maxAirDraught = ((StaticData)val).getMaxAirDraught();
    m_maxDraughtPresent = false;
    m_maxDraught = ((StaticData)val).getMaxDraught();
    m_deepWaterVesselindPresent = false;
    m_deepWaterVesselind = ((StaticData)val).getDeepWaterVesselind();
}

StaticData & StaticData::operator=(const StaticData &/*val*/) {

    return *this;
}

void StaticData::setId(int val) {

    m_id = val;
}

int StaticData::getId() {

    return m_id;
}

void StaticData::setSourceName(QString val) {

    m_sourceName = val;
}

QString StaticData::getSourceName() {

    return m_sourceName;
}

void StaticData::setSource(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_source = val;
}

int StaticData::getSource() {

    return m_source;
}

void StaticData::setLength(float val) {

    m_lengthPresent = true;
    m_length = val;
}

float StaticData::getLength() {

    return m_length;
}

bool StaticData::hasLength() {

    return m_lengthPresent;
}

void StaticData::setBreadth(float val) {

    m_breadthPresent = true;
    m_breadth = val;
}

float StaticData::getBreadth() {

    return m_breadth;
}

bool StaticData::hasBreadth() {

    return m_breadthPresent;
}

void StaticData::setCallsign(QString val) {

    m_callsignPresent = true;
    m_callsign = val;
}

QString StaticData::getCallsign() {

    return m_callsign;
}

bool StaticData::hasCallsign() {

    return m_callsignPresent;
}

void StaticData::setShipName(QString val) {

    m_shipNamePresent = true;
    m_shipName = val;
}

QString StaticData::getShipName() {

    return m_shipName;
}

bool StaticData::hasShipName() {

    return m_shipNamePresent;
}

void StaticData::setObjectType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) )
        return;
    m_objectTypePresent = true;
    m_objectType = val;
}

int StaticData::getObjectType() {

    return m_objectType;
}

bool StaticData::hasObjectType() {

    return m_objectTypePresent;
}

void StaticData::setShipType(int val) {

    if ( ( val != 20 ) &&
         ( val != 30 ) &&
         ( val != 31 ) &&
         ( val != 32 ) &&
         ( val != 33 ) &&
         ( val != 34 ) &&
         ( val != 35 ) &&
         ( val != 36 ) &&
         ( val != 37 ) &&
         ( val != 40 ) &&
         ( val != 50 ) &&
         ( val != 51 ) &&
         ( val != 52 ) &&
         ( val != 53 ) &&
         ( val != 54 ) &&
         ( val != 55 ) &&
         ( val != 58 ) &&
         ( val != 59 ) &&
         ( val != 60 ) &&
         ( val != 70 ) &&
         ( val != 80 ) &&
         ( val != 90 ) )
        return;
    m_shipTypePresent = true;
    m_shipType = val;
}

int StaticData::getShipType() {

    return m_shipType;
}

bool StaticData::hasShipType() {

    return m_shipTypePresent;
}

void StaticData::setIMO(int val) {

    m_IMOPresent = true;
    m_IMO = val;
}

int StaticData::getIMO() {

    return m_IMO;
}

bool StaticData::hasIMO() {

    return m_IMOPresent;
}

void StaticData::setMMSI(int val) {

    m_MMSIPresent = true;
    m_MMSI = val;
}

int StaticData::getMMSI() {

    return m_MMSI;
}

bool StaticData::hasMMSI() {

    return m_MMSIPresent;
}

void StaticData::setATONType(int val) {

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
         ( val != 33 ) )
        return;
    m_ATONTypePresent = true;
    m_ATONType = val;
}

int StaticData::getATONType() {

    return m_ATONType;
}

bool StaticData::hasATONType() {

    return m_ATONTypePresent;
}

void StaticData::setATONName(QString val) {

    m_ATONNamePresent = true;
    m_ATONName = val;
}

QString StaticData::getATONName() {

    return m_ATONName;
}

bool StaticData::hasATONName() {

    return m_ATONNamePresent;
}

void StaticData::setAntPosDistFromFront(float val) {

    m_antPosDistFromFrontPresent = true;
    m_antPosDistFromFront = val;
}

float StaticData::getAntPosDistFromFront() {

    return m_antPosDistFromFront;
}

bool StaticData::hasAntPosDistFromFront() {

    return m_antPosDistFromFrontPresent;
}

void StaticData::setAntPosDistFromLeft(float val) {

    m_antPosDistFromLeftPresent = true;
    m_antPosDistFromLeft = val;
}

float StaticData::getAntPosDistFromLeft() {

    return m_antPosDistFromLeft;
}

bool StaticData::hasAntPosDistFromLeft() {

    return m_antPosDistFromLeftPresent;
}

void StaticData::setNatLangShipName(QString val) {

    m_natLangShipNamePresent = true;
    m_natLangShipName = val;
}

QString StaticData::getNatLangShipName() {

    return m_natLangShipName;
}

bool StaticData::hasNatLangShipName() {

    return m_natLangShipNamePresent;
}

void StaticData::setPortOfRegistry(QString val) {

    m_portOfRegistryPresent = true;
    m_portOfRegistry = val;
}

QString StaticData::getPortOfRegistry() {

    return m_portOfRegistry;
}

bool StaticData::hasPortOfRegistry() {

    return m_portOfRegistryPresent;
}

void StaticData::setCountryFlag(QString val) {

    m_countryFlagPresent = true;
    m_countryFlag = val;
}

QString StaticData::getCountryFlag() {

    return m_countryFlag;
}

bool StaticData::hasCountryFlag() {

    return m_countryFlagPresent;
}

void StaticData::setMaxAirDraught(float val) {

    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
}

float StaticData::getMaxAirDraught() {

    return m_maxAirDraught;
}

bool StaticData::hasMaxAirDraught() {

    return m_maxAirDraughtPresent;
}

void StaticData::setMaxDraught(float val) {

    m_maxDraughtPresent = true;
    m_maxDraught = val;
}

float StaticData::getMaxDraught() {

    return m_maxDraught;
}

bool StaticData::hasMaxDraught() {

    return m_maxDraughtPresent;
}

void StaticData::setDeepWaterVesselind(QString val) {

    if ( ( val != "yes" ) &&
         ( val != "no" ) )
        return;
    m_deepWaterVesselindPresent = true;
    m_deepWaterVesselind = val;
}

QString StaticData::getDeepWaterVesselind() {

    return m_deepWaterVesselind;
}

bool StaticData::hasDeepWaterVesselind() {

    return m_deepWaterVesselindPresent;
}

QString StaticData::toXML() {

    QString xml = "<StaticData";
    xml.append(" Id = \"" + QString(m_id, 10) + "\"");
    xml.append(" SourceName = \"" + m_sourceName + "\"");
    xml.append(" Source = \"" + QString(m_source, 10) + "\"");
    if ( hasLength() ) {
        xml.append(" Length = \"" + QString(m_length, 10) + "\"");
    }
    if ( hasBreadth() ) {
        xml.append(" Breadth = \"" + QString(m_breadth, 10) + "\"");
    }
    if ( hasCallsign() ) {
        xml.append(" Callsign = \"" + m_callsign + "\"");
    }
    if ( hasShipName() ) {
        xml.append(" ShipName = \"" + m_shipName + "\"");
    }
    if ( hasObjectType() ) {
        xml.append(" ObjectType = \"" + QString(m_objectType, 10) + "\"");
    }
    if ( hasShipType() ) {
        xml.append(" ShipType = \"" + QString(m_shipType, 10) + "\"");
    }
    if ( hasIMO() ) {
        xml.append(" IMO = \"" + QString(m_IMO, 10) + "\"");
    }
    if ( hasMMSI() ) {
        xml.append(" MMSI = \"" + QString(m_MMSI, 10) + "\"");
    }
    if ( hasATONType() ) {
        xml.append(" ATONType = \"" + QString(m_ATONType, 10) + "\"");
    }
    if ( hasATONName() ) {
        xml.append(" ATONName = \"" + m_ATONName + "\"");
    }
    if ( hasAntPosDistFromFront() ) {
        xml.append(" AntPosDistFromFront = \"" + QString(m_antPosDistFromFront, 10) + "\"");
    }
    if ( hasAntPosDistFromLeft() ) {
        xml.append(" AntPosDistFromLeft = \"" + QString(m_antPosDistFromLeft, 10) + "\"");
    }
    if ( hasNatLangShipName() ) {
        xml.append(" NatLangShipName = \"" + m_natLangShipName + "\"");
    }
    if ( hasPortOfRegistry() ) {
        xml.append(" PortOfRegistry = \"" + m_portOfRegistry + "\"");
    }
    if ( hasCountryFlag() ) {
        xml.append(" CountryFlag = \"" + m_countryFlag + "\"");
    }
    if ( hasMaxAirDraught() ) {
        xml.append(" MaxAirDraught = \"" + QString(m_maxAirDraught, 10) + "\"");
    }
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught = \"" + QString(m_maxDraught, 10) + "\"");
    }
    if ( hasDeepWaterVesselind() ) {
        xml.append(" DeepWaterVesselind = \"" + m_deepWaterVesselind + "\"");
    }
    xml.append(">\n");
    xml.append( "<StaticData />\n");
    return xml;
}

