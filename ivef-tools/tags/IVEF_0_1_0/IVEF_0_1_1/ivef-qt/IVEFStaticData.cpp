
#include "IVEFStaticData.h"

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

    m_id = val.m_id;
    m_sourceName = val.m_sourceName;
    m_source = val.m_source;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_breadthPresent = val.m_breadthPresent;
    m_breadth = val.m_breadth;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_shipNamePresent = val.m_shipNamePresent;
    m_shipName = val.m_shipName;
    m_objectTypePresent = val.m_objectTypePresent;
    m_objectType = val.m_objectType;
    m_shipTypePresent = val.m_shipTypePresent;
    m_shipType = val.m_shipType;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_ATONTypePresent = val.m_ATONTypePresent;
    m_ATONType = val.m_ATONType;
    m_ATONNamePresent = val.m_ATONNamePresent;
    m_ATONName = val.m_ATONName;
    m_antPosDistFromFrontPresent = val.m_antPosDistFromFrontPresent;
    m_antPosDistFromFront = val.m_antPosDistFromFront;
    m_antPosDistFromLeftPresent = val.m_antPosDistFromLeftPresent;
    m_antPosDistFromLeft = val.m_antPosDistFromLeft;
    m_natLangShipNamePresent = val.m_natLangShipNamePresent;
    m_natLangShipName = val.m_natLangShipName;
    m_portOfRegistryPresent = val.m_portOfRegistryPresent;
    m_portOfRegistry = val.m_portOfRegistry;
    m_countryFlagPresent = val.m_countryFlagPresent;
    m_countryFlag = val.m_countryFlag;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_deepWaterVesselindPresent = val.m_deepWaterVesselindPresent;
    m_deepWaterVesselind = val.m_deepWaterVesselind;
}

StaticData & StaticData::operator=(const StaticData &val) {

    m_id = val.m_id;
    m_sourceName = val.m_sourceName;
    m_source = val.m_source;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_breadthPresent = val.m_breadthPresent;
    m_breadth = val.m_breadth;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_shipNamePresent = val.m_shipNamePresent;
    m_shipName = val.m_shipName;
    m_objectTypePresent = val.m_objectTypePresent;
    m_objectType = val.m_objectType;
    m_shipTypePresent = val.m_shipTypePresent;
    m_shipType = val.m_shipType;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_ATONTypePresent = val.m_ATONTypePresent;
    m_ATONType = val.m_ATONType;
    m_ATONNamePresent = val.m_ATONNamePresent;
    m_ATONName = val.m_ATONName;
    m_antPosDistFromFrontPresent = val.m_antPosDistFromFrontPresent;
    m_antPosDistFromFront = val.m_antPosDistFromFront;
    m_antPosDistFromLeftPresent = val.m_antPosDistFromLeftPresent;
    m_antPosDistFromLeft = val.m_antPosDistFromLeft;
    m_natLangShipNamePresent = val.m_natLangShipNamePresent;
    m_natLangShipName = val.m_natLangShipName;
    m_portOfRegistryPresent = val.m_portOfRegistryPresent;
    m_portOfRegistry = val.m_portOfRegistry;
    m_countryFlagPresent = val.m_countryFlagPresent;
    m_countryFlag = val.m_countryFlag;
    m_maxAirDraughtPresent = val.m_maxAirDraughtPresent;
    m_maxAirDraught = val.m_maxAirDraught;
    m_maxDraughtPresent = val.m_maxDraughtPresent;
    m_maxDraught = val.m_maxDraught;
    m_deepWaterVesselindPresent = val.m_deepWaterVesselindPresent;
    m_deepWaterVesselind = val.m_deepWaterVesselind;
    return *this;
}

QString StaticData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void StaticData::setId(QString val) {

    m_id = val;
}

QString StaticData::getId() const {

    return m_id;
}

void StaticData::setSourceName(QString val) {

    m_sourceName = val;
}

QString StaticData::getSourceName() const {

    return m_sourceName;
}

void StaticData::setSource(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_source = val;
}

int StaticData::getSource() const {

    return m_source;
}

void StaticData::setLength(float val) {

    m_lengthPresent = true;
    m_length = val;
}

float StaticData::getLength() const {

    return m_length;
}

bool StaticData::hasLength() {

    return m_lengthPresent;
}

void StaticData::setBreadth(float val) {

    m_breadthPresent = true;
    m_breadth = val;
}

float StaticData::getBreadth() const {

    return m_breadth;
}

bool StaticData::hasBreadth() {

    return m_breadthPresent;
}

void StaticData::setCallsign(QString val) {

    m_callsignPresent = true;
    m_callsign = val;
}

QString StaticData::getCallsign() const {

    return m_callsign;
}

bool StaticData::hasCallsign() {

    return m_callsignPresent;
}

void StaticData::setShipName(QString val) {

    m_shipNamePresent = true;
    m_shipName = val;
}

QString StaticData::getShipName() const {

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

int StaticData::getObjectType() const {

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

int StaticData::getShipType() const {

    return m_shipType;
}

bool StaticData::hasShipType() {

    return m_shipTypePresent;
}

void StaticData::setIMO(int val) {

    m_IMOPresent = true;
    m_IMO = val;
}

int StaticData::getIMO() const {

    return m_IMO;
}

bool StaticData::hasIMO() {

    return m_IMOPresent;
}

void StaticData::setMMSI(int val) {

    m_MMSIPresent = true;
    m_MMSI = val;
}

int StaticData::getMMSI() const {

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

int StaticData::getATONType() const {

    return m_ATONType;
}

bool StaticData::hasATONType() {

    return m_ATONTypePresent;
}

void StaticData::setATONName(QString val) {

    m_ATONNamePresent = true;
    m_ATONName = val;
}

QString StaticData::getATONName() const {

    return m_ATONName;
}

bool StaticData::hasATONName() {

    return m_ATONNamePresent;
}

void StaticData::setAntPosDistFromFront(float val) {

    m_antPosDistFromFrontPresent = true;
    m_antPosDistFromFront = val;
}

float StaticData::getAntPosDistFromFront() const {

    return m_antPosDistFromFront;
}

bool StaticData::hasAntPosDistFromFront() {

    return m_antPosDistFromFrontPresent;
}

void StaticData::setAntPosDistFromLeft(float val) {

    m_antPosDistFromLeftPresent = true;
    m_antPosDistFromLeft = val;
}

float StaticData::getAntPosDistFromLeft() const {

    return m_antPosDistFromLeft;
}

bool StaticData::hasAntPosDistFromLeft() {

    return m_antPosDistFromLeftPresent;
}

void StaticData::setNatLangShipName(QString val) {

    m_natLangShipNamePresent = true;
    m_natLangShipName = val;
}

QString StaticData::getNatLangShipName() const {

    return m_natLangShipName;
}

bool StaticData::hasNatLangShipName() {

    return m_natLangShipNamePresent;
}

void StaticData::setPortOfRegistry(QString val) {

    m_portOfRegistryPresent = true;
    m_portOfRegistry = val;
}

QString StaticData::getPortOfRegistry() const {

    return m_portOfRegistry;
}

bool StaticData::hasPortOfRegistry() {

    return m_portOfRegistryPresent;
}

void StaticData::setCountryFlag(QString val) {

    m_countryFlagPresent = true;
    m_countryFlag = val;
}

QString StaticData::getCountryFlag() const {

    return m_countryFlag;
}

bool StaticData::hasCountryFlag() {

    return m_countryFlagPresent;
}

void StaticData::setMaxAirDraught(float val) {

    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
}

float StaticData::getMaxAirDraught() const {

    return m_maxAirDraught;
}

bool StaticData::hasMaxAirDraught() {

    return m_maxAirDraughtPresent;
}

void StaticData::setMaxDraught(float val) {

    m_maxDraughtPresent = true;
    m_maxDraught = val;
}

float StaticData::getMaxDraught() const {

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

QString StaticData::getDeepWaterVesselind() const {

    return m_deepWaterVesselind;
}

bool StaticData::hasDeepWaterVesselind() {

    return m_deepWaterVesselindPresent;
}

QString StaticData::toXML() {

    QString xml = "<StaticData";
    xml.append(" Id=\"" + encode (m_id) + "\"");
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" Source=\"" + QString::number(m_source) + "\"");
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    if ( hasBreadth() ) {
        xml.append(" Breadth=\"" + QString::number(m_breadth) + "\"");
    }
    if ( hasCallsign() ) {
        xml.append(" Callsign=\"" + encode (m_callsign) + "\"");
    }
    if ( hasShipName() ) {
        xml.append(" ShipName=\"" + encode (m_shipName) + "\"");
    }
    if ( hasObjectType() ) {
        xml.append(" ObjectType=\"" + QString::number(m_objectType) + "\"");
    }
    if ( hasShipType() ) {
        xml.append(" ShipType=\"" + QString::number(m_shipType) + "\"");
    }
    if ( hasIMO() ) {
        xml.append(" IMO=\"" + QString::number(m_IMO) + "\"");
    }
    if ( hasMMSI() ) {
        xml.append(" MMSI=\"" + QString::number(m_MMSI) + "\"");
    }
    if ( hasATONType() ) {
        xml.append(" ATONType=\"" + QString::number(m_ATONType) + "\"");
    }
    if ( hasATONName() ) {
        xml.append(" ATONName=\"" + encode (m_ATONName) + "\"");
    }
    if ( hasAntPosDistFromFront() ) {
        xml.append(" AntPosDistFromFront=\"" + QString::number(m_antPosDistFromFront) + "\"");
    }
    if ( hasAntPosDistFromLeft() ) {
        xml.append(" AntPosDistFromLeft=\"" + QString::number(m_antPosDistFromLeft) + "\"");
    }
    if ( hasNatLangShipName() ) {
        xml.append(" NatLangShipName=\"" + encode (m_natLangShipName) + "\"");
    }
    if ( hasPortOfRegistry() ) {
        xml.append(" PortOfRegistry=\"" + encode (m_portOfRegistry) + "\"");
    }
    if ( hasCountryFlag() ) {
        xml.append(" CountryFlag=\"" + encode (m_countryFlag) + "\"");
    }
    if ( hasMaxAirDraught() ) {
        xml.append(" MaxAirDraught=\"" + QString::number(m_maxAirDraught) + "\"");
    }
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught=\"" + QString::number(m_maxDraught) + "\"");
    }
    if ( hasDeepWaterVesselind() ) {
        xml.append(" DeepWaterVesselind=\"" + encode (m_deepWaterVesselind) + "\"");
    }
    xml.append(">\n");
    xml.append( "</StaticData>\n");
    return xml;
}

QString StaticData::toString(QString lead) {

    QString str = lead + "StaticData\n";
    str.append( lead + "    Id = " + m_id + "\n");
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    Source = " + QString::number(m_source) + "\n");
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    if ( hasBreadth() ) {
        str.append( lead + "    Breadth = " + QString::number(m_breadth) + "\n");
    }
    if ( hasCallsign() ) {
        str.append( lead + "    Callsign = " + m_callsign + "\n");
    }
    if ( hasShipName() ) {
        str.append( lead + "    ShipName = " + m_shipName + "\n");
    }
    if ( hasObjectType() ) {
        str.append( lead + "    ObjectType = " + QString::number(m_objectType) + "\n");
    }
    if ( hasShipType() ) {
        str.append( lead + "    ShipType = " + QString::number(m_shipType) + "\n");
    }
    if ( hasIMO() ) {
        str.append( lead + "    IMO = " + QString::number(m_IMO) + "\n");
    }
    if ( hasMMSI() ) {
        str.append( lead + "    MMSI = " + QString::number(m_MMSI) + "\n");
    }
    if ( hasATONType() ) {
        str.append( lead + "    ATONType = " + QString::number(m_ATONType) + "\n");
    }
    if ( hasATONName() ) {
        str.append( lead + "    ATONName = " + m_ATONName + "\n");
    }
    if ( hasAntPosDistFromFront() ) {
        str.append( lead + "    AntPosDistFromFront = " + QString::number(m_antPosDistFromFront) + "\n");
    }
    if ( hasAntPosDistFromLeft() ) {
        str.append( lead + "    AntPosDistFromLeft = " + QString::number(m_antPosDistFromLeft) + "\n");
    }
    if ( hasNatLangShipName() ) {
        str.append( lead + "    NatLangShipName = " + m_natLangShipName + "\n");
    }
    if ( hasPortOfRegistry() ) {
        str.append( lead + "    PortOfRegistry = " + m_portOfRegistry + "\n");
    }
    if ( hasCountryFlag() ) {
        str.append( lead + "    CountryFlag = " + m_countryFlag + "\n");
    }
    if ( hasMaxAirDraught() ) {
        str.append( lead + "    MaxAirDraught = " + QString::number(m_maxAirDraught) + "\n");
    }
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught) + "\n");
    }
    if ( hasDeepWaterVesselind() ) {
        str.append( lead + "    DeepWaterVesselind = " + m_deepWaterVesselind + "\n");
    }
    return str;
}

