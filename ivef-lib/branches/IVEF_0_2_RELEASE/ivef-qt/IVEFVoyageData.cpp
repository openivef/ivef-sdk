
#include "IVEFVoyageData.h"

VoyageData::VoyageData() {

    m_airDraught = 0.0;
    m_airDraughtPresent = false;
    m_id = 0;
    m_cargoTypeIMO = 0;
    m_cargoTypeIMOPresent = false;
    m_contactIdentity = "";
    m_contactIdentityPresent = false;
    m_destCode = "";
    m_destCodePresent = false;
    m_destName = "";
    m_destNamePresent = false;
    m_draught = 0.0;
    m_draughtPresent = false;
    m_ETA = QDateTime();
    m_ETAPresent = false;
    m_ISPSLevel = 0.0;
    m_ISPSLevelPresent = false;
    m_overSizedLength = 0.0;
    m_overSizedLengthPresent = false;
    m_overSizedWidth = 0.0;
    m_overSizedWidthPresent = false;
    m_nextPort = "";
    m_nextPortPresent = false;
    m_personsOnBoard = 0.0;
    m_personsOnBoardPresent = false;
    m_pilots = 0.0;
    m_pilotsPresent = false;
    m_prevPort = "";
    m_prevPortPresent = false;
    m_routeBound = false;
    m_routeBoundPresent = false;
    m_sourceId = "";
    m_sourceIdPresent = false;
    m_sourceName = "";
    m_sourceType = 0;
    m_tankerStatus = 0;
    m_tankerStatusPresent = false;
    m_tugs = false;
    m_tugsPresent = false;
    m_updateTime = QDateTime();
}

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

QString VoyageData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void VoyageData::addWaypoint(Waypoint val) {

    m_waypoints.append(val);
}

Waypoint VoyageData::getWaypointAt(int i) const {

    return m_waypoints.at(i);
}

int VoyageData::countOfWaypoints() const {

    return m_waypoints.count();
}

void VoyageData::setAirDraught(float val) {

    m_airDraughtPresent = true;
    m_airDraught = val;
}

float VoyageData::getAirDraught() const {

    return m_airDraught;
}

bool VoyageData::hasAirDraught() {

    return m_airDraughtPresent;
}

void VoyageData::setId(int val) {

    m_id = val;
}

int VoyageData::getId() const {

    return m_id;
}

void VoyageData::setCargoTypeIMO(int val) {

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

int VoyageData::getCargoTypeIMO() const {

    return m_cargoTypeIMO;
}

bool VoyageData::hasCargoTypeIMO() {

    return m_cargoTypeIMOPresent;
}

void VoyageData::setContactIdentity(QString val) {

    m_contactIdentityPresent = true;
    m_contactIdentity = val;
}

QString VoyageData::getContactIdentity() const {

    return m_contactIdentity;
}

bool VoyageData::hasContactIdentity() {

    return m_contactIdentityPresent;
}

void VoyageData::setDestCode(QString val) {

    m_destCodePresent = true;
    m_destCode = val;
}

QString VoyageData::getDestCode() const {

    return m_destCode;
}

bool VoyageData::hasDestCode() {

    return m_destCodePresent;
}

void VoyageData::setDestName(QString val) {

    m_destNamePresent = true;
    m_destName = val;
}

QString VoyageData::getDestName() const {

    return m_destName;
}

bool VoyageData::hasDestName() {

    return m_destNamePresent;
}

void VoyageData::setDraught(float val) {

    m_draughtPresent = true;
    m_draught = val;
}

float VoyageData::getDraught() const {

    return m_draught;
}

bool VoyageData::hasDraught() {

    return m_draughtPresent;
}

void VoyageData::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

QDateTime VoyageData::getETA() const {

    return m_ETA;
}

bool VoyageData::hasETA() {

    return m_ETAPresent;
}

void VoyageData::setISPSLevel(float val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_ISPSLevelPresent = true;
    m_ISPSLevel = val;
}

float VoyageData::getISPSLevel() const {

    return m_ISPSLevel;
}

bool VoyageData::hasISPSLevel() {

    return m_ISPSLevelPresent;
}

void VoyageData::setOverSizedLength(float val) {

    m_overSizedLengthPresent = true;
    m_overSizedLength = val;
}

float VoyageData::getOverSizedLength() const {

    return m_overSizedLength;
}

bool VoyageData::hasOverSizedLength() {

    return m_overSizedLengthPresent;
}

void VoyageData::setOverSizedWidth(float val) {

    m_overSizedWidthPresent = true;
    m_overSizedWidth = val;
}

float VoyageData::getOverSizedWidth() const {

    return m_overSizedWidth;
}

bool VoyageData::hasOverSizedWidth() {

    return m_overSizedWidthPresent;
}

void VoyageData::setNextPort(QString val) {

    m_nextPortPresent = true;
    m_nextPort = val;
}

QString VoyageData::getNextPort() const {

    return m_nextPort;
}

bool VoyageData::hasNextPort() {

    return m_nextPortPresent;
}

void VoyageData::setPersonsOnBoard(float val) {

    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
}

float VoyageData::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

bool VoyageData::hasPersonsOnBoard() {

    return m_personsOnBoardPresent;
}

void VoyageData::setPilots(float val) {

    m_pilotsPresent = true;
    m_pilots = val;
}

float VoyageData::getPilots() const {

    return m_pilots;
}

bool VoyageData::hasPilots() {

    return m_pilotsPresent;
}

void VoyageData::setPrevPort(QString val) {

    m_prevPortPresent = true;
    m_prevPort = val;
}

QString VoyageData::getPrevPort() const {

    return m_prevPort;
}

bool VoyageData::hasPrevPort() {

    return m_prevPortPresent;
}

void VoyageData::setRouteBound(bool val) {

    m_routeBoundPresent = true;
    m_routeBound = val;
}

bool VoyageData::getRouteBound() const {

    return m_routeBound;
}

bool VoyageData::hasRouteBound() {

    return m_routeBoundPresent;
}

void VoyageData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
}

QString VoyageData::getSourceId() const {

    return m_sourceId;
}

bool VoyageData::hasSourceId() {

    return m_sourceIdPresent;
}

void VoyageData::setSourceName(QString val) {

    m_sourceName = val;
}

QString VoyageData::getSourceName() const {

    return m_sourceName;
}

void VoyageData::setSourceType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_sourceType = val;
}

int VoyageData::getSourceType() const {

    return m_sourceType;
}

void VoyageData::setTankerStatus(int val) {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_tankerStatusPresent = true;
    m_tankerStatus = val;
}

int VoyageData::getTankerStatus() const {

    return m_tankerStatus;
}

bool VoyageData::hasTankerStatus() {

    return m_tankerStatusPresent;
}

void VoyageData::setTugs(bool val) {

    m_tugsPresent = true;
    m_tugs = val;
}

bool VoyageData::getTugs() const {

    return m_tugs;
}

bool VoyageData::hasTugs() {

    return m_tugsPresent;
}

void VoyageData::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

QDateTime VoyageData::getUpdateTime() const {

    return m_updateTime;
}

QString VoyageData::toXML() {

    QString xml = "<VoyageData";
    if ( hasAirDraught() ) {
        xml.append(" AirDraught=\"" + QString::number(m_airDraught) + "\"");
    }
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    if ( hasCargoTypeIMO() ) {
        xml.append(" CargoTypeIMO=\"" + QString::number(m_cargoTypeIMO) + "\"");
    }
    if ( hasContactIdentity() ) {
        xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + "\"");
    }
    if ( hasDestCode() ) {
        xml.append(" DestCode=\"" + encode (m_destCode) + "\"");
    }
    if ( hasDestName() ) {
        xml.append(" DestName=\"" + encode (m_destName) + "\"");
    }
    if ( hasDraught() ) {
        xml.append(" Draught=\"" + QString::number(m_draught) + "\"");
    }
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    if ( hasISPSLevel() ) {
        xml.append(" ISPSLevel=\"" + QString::number(m_ISPSLevel) + "\"");
    }
    if ( hasOverSizedLength() ) {
        xml.append(" OverSizedLength=\"" + QString::number(m_overSizedLength) + "\"");
    }
    if ( hasOverSizedWidth() ) {
        xml.append(" OverSizedWidth=\"" + QString::number(m_overSizedWidth) + "\"");
    }
    if ( hasNextPort() ) {
        xml.append(" NextPort=\"" + encode (m_nextPort) + "\"");
    }
    if ( hasPersonsOnBoard() ) {
        xml.append(" PersonsOnBoard=\"" + QString::number(m_personsOnBoard) + "\"");
    }
    if ( hasPilots() ) {
        xml.append(" Pilots=\"" + QString::number(m_pilots) + "\"");
    }
    if ( hasPrevPort() ) {
        xml.append(" PrevPort=\"" + encode (m_prevPort) + "\"");
    }
    if ( hasRouteBound() ) {
        xml.append(" RouteBound=\"" + QString(m_routeBound ? "yes" : "no" ) + "\"");
    }
    if ( hasSourceId() ) {
        xml.append(" SourceId=\"" + encode (m_sourceId) + "\"");
    }
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" SourceType=\"" + QString::number(m_sourceType) + "\"");
    if ( hasTankerStatus() ) {
        xml.append(" TankerStatus=\"" + QString::number(m_tankerStatus) + "\"");
    }
    if ( hasTugs() ) {
        xml.append(" Tugs=\"" + QString(m_tugs ? "yes" : "no" ) + "\"");
    }
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(">\n");
    for(int i=0; i < m_waypoints.count(); i++ ) {
        Waypoint attribute = m_waypoints.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</VoyageData>\n");
    return xml;
}

QString VoyageData::toString(QString lead) {

    QString str = lead + "VoyageData\n";
    if ( hasAirDraught() ) {
        str.append( lead + "    AirDraught = " + QString::number(m_airDraught) + "\n");
    }
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    if ( hasCargoTypeIMO() ) {
        str.append( lead + "    CargoTypeIMO = " + QString::number(m_cargoTypeIMO) + "\n");
    }
    if ( hasContactIdentity() ) {
        str.append( lead + "    ContactIdentity = " + m_contactIdentity + "\n");
    }
    if ( hasDestCode() ) {
        str.append( lead + "    DestCode = " + m_destCode + "\n");
    }
    if ( hasDestName() ) {
        str.append( lead + "    DestName = " + m_destName + "\n");
    }
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number(m_draught) + "\n");
    }
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    if ( hasISPSLevel() ) {
        str.append( lead + "    ISPSLevel = " + QString::number(m_ISPSLevel) + "\n");
    }
    if ( hasOverSizedLength() ) {
        str.append( lead + "    OverSizedLength = " + QString::number(m_overSizedLength) + "\n");
    }
    if ( hasOverSizedWidth() ) {
        str.append( lead + "    OverSizedWidth = " + QString::number(m_overSizedWidth) + "\n");
    }
    if ( hasNextPort() ) {
        str.append( lead + "    NextPort = " + m_nextPort + "\n");
    }
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number(m_personsOnBoard) + "\n");
    }
    if ( hasPilots() ) {
        str.append( lead + "    Pilots = " + QString::number(m_pilots) + "\n");
    }
    if ( hasPrevPort() ) {
        str.append( lead + "    PrevPort = " + m_prevPort + "\n");
    }
    if ( hasRouteBound() ) {
        str.append( lead + "    RouteBound = " + QString::number(m_routeBound) + "\n");
    }
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    SourceType = " + QString::number(m_sourceType) + "\n");
    if ( hasTankerStatus() ) {
        str.append( lead + "    TankerStatus = " + QString::number(m_tankerStatus) + "\n");
    }
    if ( hasTugs() ) {
        str.append( lead + "    Tugs = " + QString::number(m_tugs) + "\n");
    }
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    for(int i=0; i < m_waypoints.count(); i++ ) {
       Waypoint attribute = m_waypoints.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

