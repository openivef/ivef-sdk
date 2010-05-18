
#include "IVEFVoyageData.h"

// Constructor
VoyageData::VoyageData() {

    m_airDraught = 0.0;
    m_airDraughtPresent = false;
    m_id = 0;
    m_idPresent = false;
    m_cargoTypeIMO = 0;
    m_cargoTypeIMOPresent = false;
    // initialize empty string
    m_contactIdentity = "";
    m_contactIdentityPresent = false;
    // initialize empty string
    m_destCode = "";
    m_destCodePresent = false;
    // initialize empty string
    m_destName = "";
    m_destNamePresent = false;
    // initialize empty string
    m_departCode = "";
    m_departCodePresent = false;
    // initialize empty string
    m_departName = "";
    m_departNamePresent = false;
    m_draught = 0.0;
    m_draughtPresent = false;
    // initialize with random value
    m_ETA = QDateTime();
    m_ETAPresent = false;
    // initialize with random value
    m_ATD = QDateTime();
    m_ATDPresent = false;
    m_ISPSLevel = 0.0;
    m_ISPSLevelPresent = false;
    m_overSizedLength = 0.0;
    m_overSizedLengthPresent = false;
    m_overSizedWidth = 0.0;
    m_overSizedWidthPresent = false;
    m_personsOnBoard = 0;
    m_personsOnBoardPresent = false;
    m_pilots = 0.0;
    m_pilotsPresent = false;
    // initialize defaults to false
    m_routeBound = false;
    m_routeBoundPresent = false;
    // initialize empty string
    m_sourceId = "";
    m_sourceIdPresent = false;
    // initialize empty string
    m_sourceName = "";
    m_sourceNamePresent = false;
    m_sourceType = 0;
    m_sourceTypePresent = false;
    m_tankerStatus = 0;
    m_tankerStatusPresent = false;
    // initialize defaults to false
    m_tugs = false;
    m_tugsPresent = false;
    // initialize with random value
    m_updateTime = QDateTime();
    m_updateTimePresent = false;
}

// copy constructor
VoyageData::VoyageData(const VoyageData &val) : QObject() {

    m_waypointPresent = val.m_waypointPresent;
    m_waypoints = val.m_waypoints;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_cargoTypeIMOPresent = val.m_cargoTypeIMOPresent;
    m_cargoTypeIMO = val.m_cargoTypeIMO;
    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_departCodePresent = val.m_departCodePresent;
    m_departCode = val.m_departCode;
    m_departNamePresent = val.m_departNamePresent;
    m_departName = val.m_departName;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATDPresent = val.m_ATDPresent;
    m_ATD = val.m_ATD;
    m_ISPSLevelPresent = val.m_ISPSLevelPresent;
    m_ISPSLevel = val.m_ISPSLevel;
    m_overSizedLengthPresent = val.m_overSizedLengthPresent;
    m_overSizedLength = val.m_overSizedLength;
    m_overSizedWidthPresent = val.m_overSizedWidthPresent;
    m_overSizedWidth = val.m_overSizedWidth;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_pilotsPresent = val.m_pilotsPresent;
    m_pilots = val.m_pilots;
    m_routeBoundPresent = val.m_routeBoundPresent;
    m_routeBound = val.m_routeBound;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceTypePresent = val.m_sourceTypePresent;
    m_sourceType = val.m_sourceType;
    m_tankerStatusPresent = val.m_tankerStatusPresent;
    m_tankerStatus = val.m_tankerStatus;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
}

// assignement
VoyageData & VoyageData::operator=(const VoyageData &val) {

    m_waypointPresent = val.m_waypointPresent;
    m_waypoints = val.m_waypoints;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_cargoTypeIMOPresent = val.m_cargoTypeIMOPresent;
    m_cargoTypeIMO = val.m_cargoTypeIMO;
    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_departCodePresent = val.m_departCodePresent;
    m_departCode = val.m_departCode;
    m_departNamePresent = val.m_departNamePresent;
    m_departName = val.m_departName;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATDPresent = val.m_ATDPresent;
    m_ATD = val.m_ATD;
    m_ISPSLevelPresent = val.m_ISPSLevelPresent;
    m_ISPSLevel = val.m_ISPSLevel;
    m_overSizedLengthPresent = val.m_overSizedLengthPresent;
    m_overSizedLength = val.m_overSizedLength;
    m_overSizedWidthPresent = val.m_overSizedWidthPresent;
    m_overSizedWidth = val.m_overSizedWidth;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_pilotsPresent = val.m_pilotsPresent;
    m_pilots = val.m_pilots;
    m_routeBoundPresent = val.m_routeBoundPresent;
    m_routeBound = val.m_routeBound;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceTypePresent = val.m_sourceTypePresent;
    m_sourceType = val.m_sourceType;
    m_tankerStatusPresent = val.m_tankerStatusPresent;
    m_tankerStatus = val.m_tankerStatus;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    return *this;
}

// String encoder
QString VoyageData::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for VoyageData
bool VoyageData::addWaypoint(Waypoint val) {

   m_waypoints.append(val);
      return true;
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
bool VoyageData::setAirDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_airDraughtPresent = true;
    m_airDraught = val;
      return true;
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
bool VoyageData::setId(int val) {

    m_idPresent = true;
    m_id = val;
      return true;
}

// getter for VoyageData
int VoyageData::getId() const {

    return m_id;
}

// setter for VoyageData
bool VoyageData::setCargoTypeIMO(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return false;
    m_cargoTypeIMOPresent = true;
    m_cargoTypeIMO = val;
      return true;
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
bool VoyageData::setContactIdentity(QString val) {

    m_contactIdentityPresent = true;
    m_contactIdentity = val;
      return true;
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
bool VoyageData::setDestCode(QString val) {

    m_destCodePresent = true;
    m_destCode = val;
      return true;
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
bool VoyageData::setDestName(QString val) {

    m_destNamePresent = true;
    m_destName = val;
      return true;
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
bool VoyageData::setDepartCode(QString val) {

    m_departCodePresent = true;
    m_departCode = val;
      return true;
}

// getter for VoyageData
QString VoyageData::getDepartCode() const {

    return m_departCode;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDepartCode() const {

    return m_departCodePresent;
}

// setter for VoyageData
bool VoyageData::setDepartName(QString val) {

    m_departNamePresent = true;
    m_departName = val;
      return true;
}

// getter for VoyageData
QString VoyageData::getDepartName() const {

    return m_departName;
}

// check if optional element VoyageData has been set
bool VoyageData::hasDepartName() const {

    return m_departNamePresent;
}

// setter for VoyageData
bool VoyageData::setDraught(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_draughtPresent = true;
    m_draught = val;
      return true;
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
bool VoyageData::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
      return true;
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
bool VoyageData::setATD(QDateTime val) {

    m_ATDPresent = true;
    m_ATD = val;
      return true;
}

// getter for VoyageData
QDateTime VoyageData::getATD() const {

    return m_ATD;
}

// check if optional element VoyageData has been set
bool VoyageData::hasATD() const {

    return m_ATDPresent;
}

// setter for VoyageData
bool VoyageData::setISPSLevel(float val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_ISPSLevelPresent = true;
    m_ISPSLevel = val;
      return true;
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
bool VoyageData::setOverSizedLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_overSizedLengthPresent = true;
    m_overSizedLength = val;
      return true;
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
bool VoyageData::setOverSizedWidth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_overSizedWidthPresent = true;
    m_overSizedWidth = val;
      return true;
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
bool VoyageData::setPersonsOnBoard(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
      return true;
}

// getter for VoyageData
int VoyageData::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

// check if optional element VoyageData has been set
bool VoyageData::hasPersonsOnBoard() const {

    return m_personsOnBoardPresent;
}

// setter for VoyageData
bool VoyageData::setPilots(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_pilotsPresent = true;
    m_pilots = val;
      return true;
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
bool VoyageData::setRouteBound(bool val) {

    m_routeBoundPresent = true;
    m_routeBound = val;
      return true;
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
bool VoyageData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
      return true;
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
bool VoyageData::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
      return true;
}

// getter for VoyageData
QString VoyageData::getSourceName() const {

    return m_sourceName;
}

// setter for VoyageData
bool VoyageData::setSourceType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return false;
    m_sourceTypePresent = true;
    m_sourceType = val;
      return true;
}

// getter for VoyageData
int VoyageData::getSourceType() const {

    return m_sourceType;
}

// setter for VoyageData
bool VoyageData::setTankerStatus(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_tankerStatusPresent = true;
    m_tankerStatus = val;
      return true;
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
bool VoyageData::setTugs(bool val) {

    m_tugsPresent = true;
    m_tugs = val;
      return true;
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
bool VoyageData::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
      return true;
}

// getter for VoyageData
QDateTime VoyageData::getUpdateTime() const {

    return m_updateTime;
}

// Get XML Representation
QString VoyageData::toXML() const {

    QString xml = "<VoyageData";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasAirDraught() ) {
        xml.append(" AirDraught=\"" + QString::number(m_airDraught, 'f', 2) + "\"");
    }
    // check for presence of required  attribute
    if ( m_idPresent) {
        xml.append(" Id=\"" + QString::number( m_id ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasCargoTypeIMO() ) {
        xml.append(" CargoTypeIMO=\"" + QString::number( m_cargoTypeIMO ) + "\"");
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
    if ( hasDepartCode() ) {
        xml.append(" DepartCode=\"" + encode (m_departCode) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDepartName() ) {
        xml.append(" DepartName=\"" + encode (m_departName) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        xml.append(" Draught=\"" + QString::number(m_draught, 'f', 2) + "\"");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasATD() ) {
        xml.append(" ATD=\"" + m_ATD.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasISPSLevel() ) {
        xml.append(" ISPSLevel=\"" + QString::number( m_ISPSLevel, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasOverSizedLength() ) {
        xml.append(" OverSizedLength=\"" + QString::number(m_overSizedLength, 'f', 1) + "\"");
    }
    // check for presence of optional attribute
    if ( hasOverSizedWidth() ) {
        xml.append(" OverSizedWidth=\"" + QString::number(m_overSizedWidth, 'f', 1) + "\"");
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        xml.append(" PersonsOnBoard=\"" + QString::number( m_personsOnBoard ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasPilots() ) {
        xml.append(" Pilots=\"" + QString::number( m_pilots, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasRouteBound() ) {
        xml.append(" RouteBound=\"" + QString( m_routeBound ? "true" : "false" ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        xml.append(" SourceId=\"" + encode (m_sourceId) + "\"");
    }
    // check for presence of required  attribute
    if ( m_sourceNamePresent) {
        xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourceTypePresent) {
        xml.append(" SourceType=\"" + QString::number( m_sourceType ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasTankerStatus() ) {
        xml.append(" TankerStatus=\"" + QString::number( m_tankerStatus ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasTugs() ) {
        xml.append(" Tugs=\"" + QString( m_tugs ? "true" : "false" ) + "\"");
    }
    // check for presence of required  attribute
    if ( m_updateTimePresent) {
        xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append(">\n");
    if (m_waypoints.count() < 0) {
        return NULL; // not enough values
    }
    // add all included data
    for(int i=0; i < m_waypoints.count(); i++ ) {
        Waypoint attribute = m_waypoints.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
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
        str.append( lead + "    AirDraught = " + QString::number(m_airDraught, 'f', 2) + "\n");
    }
     str.append( lead + "    Id = " + QString::number( m_id ) + "\n");
    // check for presence of optional attribute
    if ( hasCargoTypeIMO() ) {
        str.append( lead + "    CargoTypeIMO = " + QString::number( m_cargoTypeIMO ) + "\n");
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
    if ( hasDepartCode() ) {
        str.append( lead + "    DepartCode = " + m_departCode + "\n");
    }
    // check for presence of optional attribute
    if ( hasDepartName() ) {
        str.append( lead + "    DepartName = " + m_departName + "\n");
    }
    // check for presence of optional attribute
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number(m_draught, 'f', 2) + "\n");
    }
    // check for presence of optional attribute
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasATD() ) {
        str.append( lead + "    ATD = " + m_ATD.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasISPSLevel() ) {
        str.append( lead + "    ISPSLevel = " + QString::number( m_ISPSLevel, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasOverSizedLength() ) {
        str.append( lead + "    OverSizedLength = " + QString::number(m_overSizedLength, 'f', 1) + "\n");
    }
    // check for presence of optional attribute
    if ( hasOverSizedWidth() ) {
        str.append( lead + "    OverSizedWidth = " + QString::number(m_overSizedWidth, 'f', 1) + "\n");
    }
    // check for presence of optional attribute
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number( m_personsOnBoard ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasPilots() ) {
        str.append( lead + "    Pilots = " + QString::number( m_pilots, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasRouteBound() ) {
        str.append( lead + "    RouteBound = " + QString( m_routeBound ? "true" : "false" ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
     str.append( lead + "    SourceName = " + m_sourceName + "\n");
     str.append( lead + "    SourceType = " + QString::number( m_sourceType ) + "\n");
    // check for presence of optional attribute
    if ( hasTankerStatus() ) {
        str.append( lead + "    TankerStatus = " + QString::number( m_tankerStatus ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasTugs() ) {
        str.append( lead + "    Tugs = " + QString( m_tugs ? "true" : "false" ) + "\n");
    }
     str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    // add all included data
    for(int i=0; i < m_waypoints.count(); i++ ) {
        Waypoint attribute = m_waypoints.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

