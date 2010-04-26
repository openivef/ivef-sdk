
#include "IVEFStaticData.h"

// Constructor
StaticData::StaticData() {

    // initialize empty string
    m_id = "";
    m_idPresent = false;
    // initialize empty string
    m_sourceName = "";
    m_sourceNamePresent = false;
    m_source = 0;
    m_sourcePresent = false;
    m_length = 0.0;
    m_lengthPresent = false;
    m_breadth = 0.0;
    m_breadthPresent = false;
    // initialize empty string
    m_callsign = "";
    m_callsignPresent = false;
    // initialize empty string
    m_shipName = "";
    m_shipNamePresent = false;
    m_objectType = 0;
    m_objectTypePresent = false;
    m_shipType = 0;
    m_shipTypePresent = false;
    m_IMO = 0;
    m_IMOPresent = false;
    m_MMSI = 0;
    m_MMSIPresent = false;
    m_ATONType = 0;
    m_ATONTypePresent = false;
    // initialize empty string
    m_ATONName = "";
    m_ATONNamePresent = false;
    m_antPosDistFromFront = 0.0;
    m_antPosDistFromFrontPresent = false;
    m_antPosDistFromLeft = 0.0;
    m_antPosDistFromLeftPresent = false;
    // initialize empty string
    m_natLangShipName = "";
    m_natLangShipNamePresent = false;
    // initialize empty string
    m_portOfRegistry = "";
    m_portOfRegistryPresent = false;
    // initialize empty string
    m_countryFlag = "";
    m_countryFlagPresent = false;
    m_maxAirDraught = 0.0;
    m_maxAirDraughtPresent = false;
    m_maxDraught = 0.0;
    m_maxDraughtPresent = false;
    // initialize empty string
    m_deepWaterVesselind = "";
    m_deepWaterVesselindPresent = false;
}

// copy constructor
StaticData::StaticData(const StaticData &val) : QObject() {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourcePresent = val.m_sourcePresent;
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

// assignement
StaticData & StaticData::operator=(const StaticData &val) {

    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourcePresent = val.m_sourcePresent;
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

// String encoder
QString StaticData::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for StaticData
bool StaticData::setId(QString val) {

    m_idPresent = true;
    m_id = val;
      return true;
}

// getter for StaticData
QString StaticData::getId() const {

    return m_id;
}

// setter for StaticData
bool StaticData::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
      return true;
}

// getter for StaticData
QString StaticData::getSourceName() const {

    return m_sourceName;
}

// setter for StaticData
bool StaticData::setSource(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_sourcePresent = true;
    m_source = val;
      return true;
}

// getter for StaticData
int StaticData::getSource() const {

    return m_source;
}

// setter for StaticData
bool StaticData::setLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_lengthPresent = true;
    m_length = val;
      return true;
}

// getter for StaticData
float StaticData::getLength() const {

    return m_length;
}

// check if optional element StaticData has been set
bool StaticData::hasLength() const {

    return m_lengthPresent;
}

// setter for StaticData
bool StaticData::setBreadth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_breadthPresent = true;
    m_breadth = val;
      return true;
}

// getter for StaticData
float StaticData::getBreadth() const {

    return m_breadth;
}

// check if optional element StaticData has been set
bool StaticData::hasBreadth() const {

    return m_breadthPresent;
}

// setter for StaticData
bool StaticData::setCallsign(QString val) {

    m_callsignPresent = true;
    m_callsign = val;
      return true;
}

// getter for StaticData
QString StaticData::getCallsign() const {

    return m_callsign;
}

// check if optional element StaticData has been set
bool StaticData::hasCallsign() const {

    return m_callsignPresent;
}

// setter for StaticData
bool StaticData::setShipName(QString val) {

    m_shipNamePresent = true;
    m_shipName = val;
      return true;
}

// getter for StaticData
QString StaticData::getShipName() const {

    return m_shipName;
}

// check if optional element StaticData has been set
bool StaticData::hasShipName() const {

    return m_shipNamePresent;
}

// setter for StaticData
bool StaticData::setObjectType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) )
        return false;
    m_objectTypePresent = true;
    m_objectType = val;
      return true;
}

// getter for StaticData
int StaticData::getObjectType() const {

    return m_objectType;
}

// check if optional element StaticData has been set
bool StaticData::hasObjectType() const {

    return m_objectTypePresent;
}

// setter for StaticData
bool StaticData::setShipType(int val) {
// check if the new value is an approved value 

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
        return false;
    m_shipTypePresent = true;
    m_shipType = val;
      return true;
}

// getter for StaticData
int StaticData::getShipType() const {

    return m_shipType;
}

// check if optional element StaticData has been set
bool StaticData::hasShipType() const {

    return m_shipTypePresent;
}

// setter for StaticData
bool StaticData::setIMO(int val) {

    m_IMOPresent = true;
    m_IMO = val;
      return true;
}

// getter for StaticData
int StaticData::getIMO() const {

    return m_IMO;
}

// check if optional element StaticData has been set
bool StaticData::hasIMO() const {

    return m_IMOPresent;
}

// setter for StaticData
bool StaticData::setMMSI(int val) {

    m_MMSIPresent = true;
    m_MMSI = val;
      return true;
}

// getter for StaticData
int StaticData::getMMSI() const {

    return m_MMSI;
}

// check if optional element StaticData has been set
bool StaticData::hasMMSI() const {

    return m_MMSIPresent;
}

// setter for StaticData
bool StaticData::setATONType(int val) {
// check if the new value is an approved value 

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
        return false;
    m_ATONTypePresent = true;
    m_ATONType = val;
      return true;
}

// getter for StaticData
int StaticData::getATONType() const {

    return m_ATONType;
}

// check if optional element StaticData has been set
bool StaticData::hasATONType() const {

    return m_ATONTypePresent;
}

// setter for StaticData
bool StaticData::setATONName(QString val) {

    m_ATONNamePresent = true;
    m_ATONName = val;
      return true;
}

// getter for StaticData
QString StaticData::getATONName() const {

    return m_ATONName;
}

// check if optional element StaticData has been set
bool StaticData::hasATONName() const {

    return m_ATONNamePresent;
}

// setter for StaticData
bool StaticData::setAntPosDistFromFront(float val) {

    m_antPosDistFromFrontPresent = true;
    m_antPosDistFromFront = val;
      return true;
}

// getter for StaticData
float StaticData::getAntPosDistFromFront() const {

    return m_antPosDistFromFront;
}

// check if optional element StaticData has been set
bool StaticData::hasAntPosDistFromFront() const {

    return m_antPosDistFromFrontPresent;
}

// setter for StaticData
bool StaticData::setAntPosDistFromLeft(float val) {

    m_antPosDistFromLeftPresent = true;
    m_antPosDistFromLeft = val;
      return true;
}

// getter for StaticData
float StaticData::getAntPosDistFromLeft() const {

    return m_antPosDistFromLeft;
}

// check if optional element StaticData has been set
bool StaticData::hasAntPosDistFromLeft() const {

    return m_antPosDistFromLeftPresent;
}

// setter for StaticData
bool StaticData::setNatLangShipName(QString val) {

    m_natLangShipNamePresent = true;
    m_natLangShipName = val;
      return true;
}

// getter for StaticData
QString StaticData::getNatLangShipName() const {

    return m_natLangShipName;
}

// check if optional element StaticData has been set
bool StaticData::hasNatLangShipName() const {

    return m_natLangShipNamePresent;
}

// setter for StaticData
bool StaticData::setPortOfRegistry(QString val) {

    m_portOfRegistryPresent = true;
    m_portOfRegistry = val;
      return true;
}

// getter for StaticData
QString StaticData::getPortOfRegistry() const {

    return m_portOfRegistry;
}

// check if optional element StaticData has been set
bool StaticData::hasPortOfRegistry() const {

    return m_portOfRegistryPresent;
}

// setter for StaticData
bool StaticData::setCountryFlag(QString val) {

    m_countryFlagPresent = true;
    m_countryFlag = val;
      return true;
}

// getter for StaticData
QString StaticData::getCountryFlag() const {

    return m_countryFlag;
}

// check if optional element StaticData has been set
bool StaticData::hasCountryFlag() const {

    return m_countryFlagPresent;
}

// setter for StaticData
bool StaticData::setMaxAirDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
      return true;
}

// getter for StaticData
float StaticData::getMaxAirDraught() const {

    return m_maxAirDraught;
}

// check if optional element StaticData has been set
bool StaticData::hasMaxAirDraught() const {

    return m_maxAirDraughtPresent;
}

// setter for StaticData
bool StaticData::setMaxDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_maxDraughtPresent = true;
    m_maxDraught = val;
      return true;
}

// getter for StaticData
float StaticData::getMaxDraught() const {

    return m_maxDraught;
}

// check if optional element StaticData has been set
bool StaticData::hasMaxDraught() const {

    return m_maxDraughtPresent;
}

// setter for StaticData
bool StaticData::setDeepWaterVesselind(QString val) {
// check if the new value is an approved value 

    if ( ( val != "yes" ) &&
         ( val != "no" ) )
        return false;
    m_deepWaterVesselindPresent = true;
    m_deepWaterVesselind = val;
      return true;
}

// getter for StaticData
QString StaticData::getDeepWaterVesselind() const {

    return m_deepWaterVesselind;
}

// check if optional element StaticData has been set
bool StaticData::hasDeepWaterVesselind() const {

    return m_deepWaterVesselindPresent;
}

// Get XML Representation
QString StaticData::toXML() const {

    QString xml = "<StaticData";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_idPresent) {
        xml.append(" Id=\"" + encode (m_id) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourceNamePresent) {
        xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourcePresent) {
        xml.append(" Source=\"" + QString::number(m_source) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasBreadth() ) {
        xml.append(" Breadth=\"" + QString::number(m_breadth, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasCallsign() ) {
        xml.append(" Callsign=\"" + encode (m_callsign) + "\"");
    }
    // check for presence of optional attribute
    if ( hasShipName() ) {
        xml.append(" ShipName=\"" + encode (m_shipName) + "\"");
    }
    // check for presence of optional attribute
    if ( hasObjectType() ) {
        xml.append(" ObjectType=\"" + QString::number(m_objectType) + "\"");
    }
    // check for presence of optional attribute
    if ( hasShipType() ) {
        xml.append(" ShipType=\"" + QString::number(m_shipType) + "\"");
    }
    // check for presence of optional attribute
    if ( hasIMO() ) {
        xml.append(" IMO=\"" + QString::number(m_IMO) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMMSI() ) {
        xml.append(" MMSI=\"" + QString::number(m_MMSI) + "\"");
    }
    // check for presence of optional attribute
    if ( hasATONType() ) {
        xml.append(" ATONType=\"" + QString::number(m_ATONType) + "\"");
    }
    // check for presence of optional attribute
    if ( hasATONName() ) {
        xml.append(" ATONName=\"" + encode (m_ATONName) + "\"");
    }
    // check for presence of optional attribute
    if ( hasAntPosDistFromFront() ) {
        xml.append(" AntPosDistFromFront=\"" + QString::number(m_antPosDistFromFront, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasAntPosDistFromLeft() ) {
        xml.append(" AntPosDistFromLeft=\"" + QString::number(m_antPosDistFromLeft, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasNatLangShipName() ) {
        xml.append(" NatLangShipName=\"" + encode (m_natLangShipName) + "\"");
    }
    // check for presence of optional attribute
    if ( hasPortOfRegistry() ) {
        xml.append(" PortOfRegistry=\"" + encode (m_portOfRegistry) + "\"");
    }
    // check for presence of optional attribute
    if ( hasCountryFlag() ) {
        xml.append(" CountryFlag=\"" + encode (m_countryFlag) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxAirDraught() ) {
        xml.append(" MaxAirDraught=\"" + QString::number(m_maxAirDraught, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        xml.append(" MaxDraught=\"" + QString::number(m_maxDraught, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasDeepWaterVesselind() ) {
        xml.append(" DeepWaterVesselind=\"" + encode (m_deepWaterVesselind) + "\"");
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString StaticData::toString() {

    return toString("");
}

// Get String Representation with a lead
QString StaticData::toString(QString lead) {

    QString str = lead + "StaticData\n";
    str.append( lead + "    Id = " + m_id + "\n");
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    Source = " + QString::number(m_source) + "\n");
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasBreadth() ) {
        str.append( lead + "    Breadth = " + QString::number(m_breadth, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasCallsign() ) {
        str.append( lead + "    Callsign = " + m_callsign + "\n");
    }
    // check for presence of optional attribute
    if ( hasShipName() ) {
        str.append( lead + "    ShipName = " + m_shipName + "\n");
    }
    // check for presence of optional attribute
    if ( hasObjectType() ) {
        str.append( lead + "    ObjectType = " + QString::number(m_objectType) + "\n");
    }
    // check for presence of optional attribute
    if ( hasShipType() ) {
        str.append( lead + "    ShipType = " + QString::number(m_shipType) + "\n");
    }
    // check for presence of optional attribute
    if ( hasIMO() ) {
        str.append( lead + "    IMO = " + QString::number(m_IMO) + "\n");
    }
    // check for presence of optional attribute
    if ( hasMMSI() ) {
        str.append( lead + "    MMSI = " + QString::number(m_MMSI) + "\n");
    }
    // check for presence of optional attribute
    if ( hasATONType() ) {
        str.append( lead + "    ATONType = " + QString::number(m_ATONType) + "\n");
    }
    // check for presence of optional attribute
    if ( hasATONName() ) {
        str.append( lead + "    ATONName = " + m_ATONName + "\n");
    }
    // check for presence of optional attribute
    if ( hasAntPosDistFromFront() ) {
        str.append( lead + "    AntPosDistFromFront = " + QString::number(m_antPosDistFromFront, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasAntPosDistFromLeft() ) {
        str.append( lead + "    AntPosDistFromLeft = " + QString::number(m_antPosDistFromLeft, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasNatLangShipName() ) {
        str.append( lead + "    NatLangShipName = " + m_natLangShipName + "\n");
    }
    // check for presence of optional attribute
    if ( hasPortOfRegistry() ) {
        str.append( lead + "    PortOfRegistry = " + m_portOfRegistry + "\n");
    }
    // check for presence of optional attribute
    if ( hasCountryFlag() ) {
        str.append( lead + "    CountryFlag = " + m_countryFlag + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxAirDraught() ) {
        str.append( lead + "    MaxAirDraught = " + QString::number(m_maxAirDraught, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasMaxDraught() ) {
        str.append( lead + "    MaxDraught = " + QString::number(m_maxDraught, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasDeepWaterVesselind() ) {
        str.append( lead + "    DeepWaterVesselind = " + m_deepWaterVesselind + "\n");
    }
    return str;
}

