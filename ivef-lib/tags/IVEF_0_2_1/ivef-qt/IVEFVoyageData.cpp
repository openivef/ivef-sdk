
#include "IVEFVoyageData.h"

// Constructor
VoyageData::VoyageData() {

    m_airDraught = 0.0;
    // optional attributes are by default not present
    m_airDraughtPresent = false;
    m_id = 0;
    m_cargoTypeIMO = 0;
    // optional attributes are by default not present
    m_cargoTypeIMOPresent = false;
    // initialize empty string
    m_contactIdentity = "";
    // optional attributes are by default not present
    m_contactIdentityPresent = false;
    // initialize empty string
    m_destCode = "";
    // optional attributes are by default not present
    m_destCodePresent = false;
    // initialize empty string
    m_destName = "";
    // optional attributes are by default not present
    m_destNamePresent = false;
    m_draught = 0.0;
    // optional attributes are by default not present
    m_draughtPresent = false;
    // initialize with random value
    m_ETA = QDateTime();
    // optional attributes are by default not present
    m_ETAPresent = false;
    m_ISPSLevel = 0.0;
    // optional attributes are by default not present
    m_ISPSLevelPresent = false;
    m_overSizedLength = 0.0;
    // optional attributes are by default not present
    m_overSizedLengthPresent = false;
    m_overSizedWidth = 0.0;
    // optional attributes are by default not present
    m_overSizedWidthPresent = false;
    // initialize empty string
    m_nextPort = "";
    // optional attributes are by default not present
    m_nextPortPresent = false;
    m_personsOnBoard = 0.0;
    // optional attributes are by default not present
    m_personsOnBoardPresent = false;
    m_pilots = 0.0;
    // optional attributes are by default not present
    m_pilotsPresent = false;
    // initialize empty string
    m_prevPort = "";
    // optional attributes are by default not present
    m_prevPortPresent = false;
    // initialize defaults to false
    m_routeBound = false;
    // optional attributes are by default not present
    m_routeBoundPresent = false;
    // initialize empty string
    m_sourceId = "";
    // optional attributes are by default not present
    m_sourceIdPresent = false;
    // initialize empty string
    m_sourceName = "";
    m_sourceType = 0;
    m_tankerStatus = 0;
    // optional attributes are by default not present
    m_tankerStatusPresent = false;
    // initialize defaults to false
    m_tugs = false;
    // optional attributes are by default not present
    m_tugsPresent = false;
    // initialize with random value
    m_updateTime = QDateTime();
}

// copy constructor
VoyageData::VoyageData(const VoyageData &val) : QObject() {

    m_waypoints = val.m_waypoints;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_id = val.m_id;
    m_cargoTypeIMOPresent = val.m_cargoTypeIMOPresent;
    m_cargoTypeIMO = val.m_cargoTypeIMO;
    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ISPSLevelPresent = val.m_ISPSLevelPresent;
    m_ISPSLevel = val.m_ISPSLevel;
    m_overSizedLengthPresent = val.m_overSizedLengthPresent;
    m_overSizedLength = val.m_overSizedLength;
    m_overSizedWidthPresent = val.m_overSizedWidthPresent;
    m_overSizedWidth = val.m_overSizedWidth;
    m_nextPortPresent = val.m_nextPortPresent;
    m_nextPort = val.m_nextPort;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_pilotsPresent = val.m_pilotsPresent;
    m_pilots = val.m_pilots;
    m_prevPortPresent = val.m_prevPortPresent;
    m_prevPort = val.m_prevPort;
    m_routeBoundPresent = val.m_routeBoundPresent;
    m_routeBound = val.m_routeBound;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceName = val.m_sourceName;
    m_sourceType = val.m_sourceType;
    m_tankerStatusPresent = val.m_tankerStatusPresent;
    m_tankerStatus = val.m_tankerStatus;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
    m_updateTime = val.m_updateTime;
}

// assignement
VoyageData & VoyageData::operator=(const VoyageData &val) {

    m_waypoints = val.m_waypoints;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_id = val.m_id;
    m_cargoTypeIMOPresent = val.m_cargoTypeIMOPresent;
    m_cargoTypeIMO = val.m_cargoTypeIMO;
    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ISPSLevelPresent = val.m_ISPSLevelPresent;
    m_ISPSLevel = val.m_ISPSLevel;
    m_overSizedLengthPresent = val.m_overSizedLengthPresent;
    m_overSizedLength = val.m_overSizedLength;
    m_overSizedWidthPresent = val.m_overSizedWidthPresent;
    m_overSizedWidth = val.m_overSizedWidth;
    m_nextPortPresent = val.m_nextPortPresent;
    m_nextPort = val.m_nextPort;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_pilotsPresent = val.m_pilotsPresent;
    m_pilots = val.m_pilots;
    m_prevPortPresent = val.m_prevPortPresent;
    m_prevPort = val.m_prevPort;
    m_routeBoundPresent = val.m_routeBoundPresent;
    m_routeBound = val.m_routeBound;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceName = val.m_sourceName;
    m_sourceType = val.m_sourceType;
    m_tankerStatusPresent = val.m_tankerStatusPresent;
    m_tankerStatus = val.m_tankerStatus;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
    m_updateTime = val.m_updateTime;
    return *this;
}

// String encoder
QString VoyageData::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for VoyageData
void VoyageData::addWaypoint(Waypoint val) {

    m_waypoints.append(val);
}

// getter for VoyageData
Waypoint VoyageData::getWaypointAt(int i) const {

    return m_waypoints.at(i);
}

// count for VoyageData
int VoyageData::countOfWaypoints() const {

    return m_waypoints.count();
}

// setter for VoyageData
void VoyageData::setAirDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_airDraughtPresent = true;
    m_airDraught = val;
}

// getter for VoyageData
float VoyageData::getAirDraught() const {

    return m_airDraught;
}

// check if optional element VoyageData has been set
bool VoyageData::hasAirDraught() const {

    return m_airDraughtPresent;
}

// setter for VoyageData
void VoyageData::setId(int val) {

    m_id = val;
}

// getter for VoyageData
int VoyageData::getId() const {

    return m_id;
}

// setter for VoyageData
void VoyageData::setCargoTypeIMO(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_cargoTypeIMOPresent = true;
    m_cargoTypeIMO = val;
}

// getter for VoyageData
int VoyageData::getCargoTypeIMO() const {

    return m_cargoTypeIMO;
}

// check if optional element VoyageData has been set
bool VoyageData::hasCargoTypeIMO() const {

    return m_cargoTypeIMOPresent;
}

// setter for VoyageData
void VoyageData::setContactIdentity(QString val) {

    m_contactIdentityPresent = true;
    m_contactIdentity = val;
}

// getter for VoyageData
QString VoyageData::getContactIdentity() const {

    return m_contactIdentity;
}

// check if optional element VoyageData has been set
bool VoyageData::hasContactIdentity() const {

    return m_contactIdentityPresent;
}

// setter for VoyageData
void VoyageData::setDestCode(QString val) {

    m_destCodePresent = true;
    m_destCode = val;
}

// getter for VoyageData
QString VoyageData::getDestCode() const {

    return m_destCode;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDestCode() const {

    return m_destCodePresent;
}

// setter for VoyageData
void VoyageData::setDestName(QString val) {

    m_destNamePresent = true;
    m_destName = val;
}

// getter for VoyageData
QString VoyageData::getDestName() const {

    return m_destName;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDestName() const {

    return m_destNamePresent;
}

// setter for VoyageData
void VoyageData::setDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_draughtPresent = true;
    m_draught = val;
}

// getter for VoyageData
float VoyageData::getDraught() const {

    return m_draught;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDraught() const {

    return m_draughtPresent;
}

// setter for VoyageData
void VoyageData::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

// getter for VoyageData
QDateTime VoyageData::getETA() const {

    return m_ETA;
}

// check if optional element VoyageData has been set
bool VoyageData::hasETA() const {

    return m_ETAPresent;
}

// setter for VoyageData
void VoyageData::setISPSLevel(float val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_ISPSLevelPresent = true;
    m_ISPSLevel = val;
}

// getter for VoyageData
float VoyageData::getISPSLevel() const {

    return m_ISPSLevel;
}

// check if optional element VoyageData has been set
bool VoyageData::hasISPSLevel() const {

    return m_ISPSLevelPresent;
}

// setter for VoyageData
void VoyageData::setOverSizedLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_overSizedLengthPresent = true;
    m_overSizedLength = val;
}

// getter for VoyageData
float VoyageData::getOverSizedLength() const {

    return m_overSizedLength;
}

// check if optional element VoyageData has been set
bool VoyageData::hasOverSizedLength() const {

    return m_overSizedLengthPresent;
}

// setter for VoyageData
void VoyageData::setOverSizedWidth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_overSizedWidthPresent = true;
    m_overSizedWidth = val;
}

// getter for VoyageData
float VoyageData::getOverSizedWidth() const {

    return m_overSizedWidth;
}

// check if optional element VoyageData has been set
bool VoyageData::hasOverSizedWidth() const {

    return m_overSizedWidthPresent;
}

// setter for VoyageData
void VoyageData::setNextPort(QString val) {

    m_nextPortPresent = true;
    m_nextPort = val;
}

// getter for VoyageData
QString VoyageData::getNextPort() const {

    return m_nextPort;
}

// check if optional element VoyageData has been set
bool VoyageData::hasNextPort() const {

    return m_nextPortPresent;
}

// setter for VoyageData
void VoyageData::setPersonsOnBoard(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
}

// getter for VoyageData
float VoyageData::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

// check if optional element VoyageData has been set
bool VoyageData::hasPersonsOnBoard() const {

    return m_personsOnBoardPresent;
}

// setter for VoyageData
void VoyageData::setPilots(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_pilotsPresent = true;
    m_pilots = val;
}

// getter for VoyageData
float VoyageData::getPilots() const {

    return m_pilots;
}

// check if optional element VoyageData has been set
bool VoyageData::hasPilots() const {

    return m_pilotsPresent;
}

// setter for VoyageData
void VoyageData::setPrevPort(QString val) {

    m_prevPortPresent = true;
    m_prevPort = val;
}

// getter for VoyageData
QString VoyageData::getPrevPort() const {

    return m_prevPort;
}

// check if optional element VoyageData has been set
bool VoyageData::hasPrevPort() const {

    return m_prevPortPresent;
}

// setter for VoyageData
void VoyageData::setRouteBound(bool val) {

    m_routeBoundPresent = true;
    m_routeBound = val;
}

// getter for VoyageData
bool VoyageData::getRouteBound() const {

    return m_routeBound;
}

// check if optional element VoyageData has been set
bool VoyageData::hasRouteBound() const {

    return m_routeBoundPresent;
}

// setter for VoyageData
void VoyageData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
}

// getter for VoyageData
QString VoyageData::getSourceId() const {

    return m_sourceId;
}

// check if optional element VoyageData has been set
bool VoyageData::hasSourceId() const {

    return m_sourceIdPresent;
}

// setter for VoyageData
void VoyageData::setSourceName(QString val) {

    m_sourceName = val;
}

// getter for VoyageData
QString VoyageData::getSourceName() const {

    return m_sourceName;
}

// setter for VoyageData
void VoyageData::setSourceType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_sourceType = val;
}

// getter for VoyageData
int VoyageData::getSourceType() const {

    return m_sourceType;
}

// setter for VoyageData
void VoyageData::setTankerStatus(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_tankerStatusPresent = true;
    m_tankerStatus = val;
}

// getter for VoyageData
int VoyageData::getTankerStatus() const {

    return m_tankerStatus;
}

// check if optional element VoyageData has been set
bool VoyageData::hasTankerStatus() const {

    return m_tankerStatusPresent;
}

// setter for VoyageData
void VoyageData::setTugs(bool val) {

    m_tugsPresent = true;
    m_tugs = val;
}

// getter for VoyageData
bool VoyageData::getTugs() const {

    return m_tugs;
}

// check if optional element VoyageData has been set
bool VoyageData::hasTugs() const {

    return m_tugsPresent;
}

// setter for VoyageData
void VoyageData::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

// getter for VoyageData
QDateTime VoyageData::getUpdateTime() const {

    return m_updateTime;
}

// Get XML Representation
QString VoyageData::toXML() {

    QString xml = "<VoyageData";
    // check for presence of optional attribute
    if ( hasAirDraught() ) {
        xml.append(" AirDraught=\"" + QString::number(m_airDraught, 'f') + "\"");
    }
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    // check for presence of optional attribute
    if ( hasCargoTypeIMO() ) {
        xml.append(" CargoTypeIMO=\"" + QString::number(m_cargoTypeIMO) + "\"");
    }
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDestCode() ) {
        xml.append(" DestCode=\"" + encode (m_destCode) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDestName() ) {
        xml.append(" DestName=\"" + encode (m_destName) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        xml.append(" Draught=\"" + QString::number(m_draught, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasISPSLevel() ) {
        xml.append(" ISPSLevel=\"" + QString::number(m_ISPSLevel, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasOverSizedLength() ) {
        xml.append(" OverSizedLength=\"" + QString::number(m_overSizedLength, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasOverSizedWidth() ) {
        xml.append(" OverSizedWidth=\"" + QString::number(m_overSizedWidth, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasNextPort() ) {
        xml.append(" NextPort=\"" + encode (m_nextPort) + "\"");
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        xml.append(" PersonsOnBoard=\"" + QString::number(m_personsOnBoard, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasPilots() ) {
        xml.append(" Pilots=\"" + QString::number(m_pilots, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasPrevPort() ) {
        xml.append(" PrevPort=\"" + encode (m_prevPort) + "\"");
    }
    // check for presence of optional attribute
    if ( hasRouteBound() ) {
        xml.append(" RouteBound=\"" + QString(m_routeBound ? "true" : "false" ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        xml.append(" SourceId=\"" + encode (m_sourceId) + "\"");
    }
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" SourceType=\"" + QString::number(m_sourceType) + "\"");
    // check for presence of optional attribute
    if ( hasTankerStatus() ) {
        xml.append(" TankerStatus=\"" + QString::number(m_tankerStatus) + "\"");
    }
    // check for presence of optional attribute
    if ( hasTugs() ) {
        xml.append(" Tugs=\"" + QString(m_tugs ? "true" : "false" ) + "\"");
    }
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_waypoints.count(); i++ ) {
        Waypoint attribute = m_waypoints.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</VoyageData>\n");
    return xml;
}

// Get String Representation
QString VoyageData::toString() {

    return toString("");
}

// Get String Representation with a lead
QString VoyageData::toString(QString lead) {

    QString str = lead + "VoyageData\n";
    // check for presence of optional attribute
    if ( hasAirDraught() ) {
        str.append( lead + "    AirDraught = " + QString::number(m_airDraught) + "\n");
    }
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    // check for presence of optional attribute
    if ( hasCargoTypeIMO() ) {
        str.append( lead + "    CargoTypeIMO = " + QString::number(m_cargoTypeIMO) + "\n");
    }
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        str.append( lead + "    ContactIdentity = " + m_contactIdentity + "\n");
    }
    // check for presence of optional attribute
    if ( hasDestCode() ) {
        str.append( lead + "    DestCode = " + m_destCode + "\n");
    }
    // check for presence of optional attribute
    if ( hasDestName() ) {
        str.append( lead + "    DestName = " + m_destName + "\n");
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number(m_draught) + "\n");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasISPSLevel() ) {
        str.append( lead + "    ISPSLevel = " + QString::number(m_ISPSLevel) + "\n");
    }
    // check for presence of optional attribute
    if ( hasOverSizedLength() ) {
        str.append( lead + "    OverSizedLength = " + QString::number(m_overSizedLength) + "\n");
    }
    // check for presence of optional attribute
    if ( hasOverSizedWidth() ) {
        str.append( lead + "    OverSizedWidth = " + QString::number(m_overSizedWidth) + "\n");
    }
    // check for presence of optional attribute
    if ( hasNextPort() ) {
        str.append( lead + "    NextPort = " + m_nextPort + "\n");
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number(m_personsOnBoard) + "\n");
    }
    // check for presence of optional attribute
    if ( hasPilots() ) {
        str.append( lead + "    Pilots = " + QString::number(m_pilots) + "\n");
    }
    // check for presence of optional attribute
    if ( hasPrevPort() ) {
        str.append( lead + "    PrevPort = " + m_prevPort + "\n");
    }
    // check for presence of optional attribute
    if ( hasRouteBound() ) {
        str.append( lead + "    RouteBound = " + QString::number(m_routeBound) + "\n");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    SourceType = " + QString::number(m_sourceType) + "\n");
    // check for presence of optional attribute
    if ( hasTankerStatus() ) {
        str.append( lead + "    TankerStatus = " + QString::number(m_tankerStatus) + "\n");
    }
    // check for presence of optional attribute
    if ( hasTugs() ) {
        str.append( lead + "    Tugs = " + QString::number(m_tugs) + "\n");
    }
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    // add all included data
    for(int i=0; i < m_waypoints.count(); i++ ) {
       Waypoint attribute = m_waypoints.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

