
#include "IVEFPosReport.h"

// Constructor
PosReport::PosReport() {

    m_id = 0;
    m_sourceId = 0;
    // initialize with random value
    m_updateTime = QDateTime();
    // initialize with random value
    m_updateTimeRadar = QDateTime();
    // optional attributes are by default not present
    m_updateTimeRadarPresent = false;
    // initialize with random value
    m_updateTimeAIS = QDateTime();
    // optional attributes are by default not present
    m_updateTimeAISPresent = false;
    // initialize with random value
    m_updateTimeDR = QDateTime();
    // optional attributes are by default not present
    m_updateTimeDRPresent = false;
    m_SOG = 0.0;
    m_COG = 0.0;
    // initialize empty string
    m_lost = "";
    m_rateOfTurn = 0.0;
    // optional attributes are by default not present
    m_rateOfTurnPresent = false;
    m_orientation = 0.0;
    // optional attributes are by default not present
    m_orientationPresent = false;
    m_length = 0.0;
    // optional attributes are by default not present
    m_lengthPresent = false;
    m_breadth = 0.0;
    // optional attributes are by default not present
    m_breadthPresent = false;
    m_altitude = 0.0;
    // optional attributes are by default not present
    m_altitudePresent = false;
    m_navStatus = 0;
    // optional attributes are by default not present
    m_navStatusPresent = false;
    m_updSensorType = 0;
    // optional attributes are by default not present
    m_updSensorTypePresent = false;
    // initialize defaults to false
    m_ATONOffPos = false;
    // optional attributes are by default not present
    m_ATONOffPosPresent = false;
}

// copy constructor
PosReport::PosReport(const PosReport &val) : QObject() {

    m_pos = val.m_pos;
    m_sensors = val.m_sensors;
    m_id = val.m_id;
    m_sourceId = val.m_sourceId;
    m_updateTime = val.m_updateTime;
    m_updateTimeRadarPresent = val.m_updateTimeRadarPresent;
    m_updateTimeRadar = val.m_updateTimeRadar;
    m_updateTimeAISPresent = val.m_updateTimeAISPresent;
    m_updateTimeAIS = val.m_updateTimeAIS;
    m_updateTimeDRPresent = val.m_updateTimeDRPresent;
    m_updateTimeDR = val.m_updateTimeDR;
    m_SOG = val.m_SOG;
    m_COG = val.m_COG;
    m_lost = val.m_lost;
    m_rateOfTurnPresent = val.m_rateOfTurnPresent;
    m_rateOfTurn = val.m_rateOfTurn;
    m_orientationPresent = val.m_orientationPresent;
    m_orientation = val.m_orientation;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_breadthPresent = val.m_breadthPresent;
    m_breadth = val.m_breadth;
    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_navStatusPresent = val.m_navStatusPresent;
    m_navStatus = val.m_navStatus;
    m_updSensorTypePresent = val.m_updSensorTypePresent;
    m_updSensorType = val.m_updSensorType;
    m_ATONOffPosPresent = val.m_ATONOffPosPresent;
    m_ATONOffPos = val.m_ATONOffPos;
}

// comperator
PosReport & PosReport::operator=(const PosReport &val) {

    m_pos = val.m_pos;
    m_sensors = val.m_sensors;
    m_id = val.m_id;
    m_sourceId = val.m_sourceId;
    m_updateTime = val.m_updateTime;
    m_updateTimeRadarPresent = val.m_updateTimeRadarPresent;
    m_updateTimeRadar = val.m_updateTimeRadar;
    m_updateTimeAISPresent = val.m_updateTimeAISPresent;
    m_updateTimeAIS = val.m_updateTimeAIS;
    m_updateTimeDRPresent = val.m_updateTimeDRPresent;
    m_updateTimeDR = val.m_updateTimeDR;
    m_SOG = val.m_SOG;
    m_COG = val.m_COG;
    m_lost = val.m_lost;
    m_rateOfTurnPresent = val.m_rateOfTurnPresent;
    m_rateOfTurn = val.m_rateOfTurn;
    m_orientationPresent = val.m_orientationPresent;
    m_orientation = val.m_orientation;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_breadthPresent = val.m_breadthPresent;
    m_breadth = val.m_breadth;
    m_altitudePresent = val.m_altitudePresent;
    m_altitude = val.m_altitude;
    m_navStatusPresent = val.m_navStatusPresent;
    m_navStatus = val.m_navStatus;
    m_updSensorTypePresent = val.m_updSensorTypePresent;
    m_updSensorType = val.m_updSensorType;
    m_ATONOffPosPresent = val.m_ATONOffPosPresent;
    m_ATONOffPos = val.m_ATONOffPos;
    return *this;
}

// String encoder
QString PosReport::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for PosReport
void PosReport::setPos(Pos val) {

    m_pos = val;
}

// getter for PosReport
Pos PosReport::getPos() const {

    return m_pos;
}

// setter for PosReport
void PosReport::addSensor(Sensor val) {

    m_sensors.append(val);
}

// getter for PosReport
Sensor PosReport::getSensorAt(int i) const {

    return m_sensors.at(i);
}

// count for PosReport
int PosReport::countOfSensors() const {

    return m_sensors.count();
}

// setter for PosReport
void PosReport::setId(int val) {

    m_id = val;
}

// getter for PosReport
int PosReport::getId() const {

    return m_id;
}

// setter for PosReport
void PosReport::setSourceId(int val) {

    m_sourceId = val;
}

// getter for PosReport
int PosReport::getSourceId() const {

    return m_sourceId;
}

// setter for PosReport
void PosReport::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

// getter for PosReport
QDateTime PosReport::getUpdateTime() const {

    return m_updateTime;
}

// setter for PosReport
void PosReport::setUpdateTimeRadar(QDateTime val) {

    m_updateTimeRadarPresent = true;
    m_updateTimeRadar = val;
}

// getter for PosReport
QDateTime PosReport::getUpdateTimeRadar() const {

    return m_updateTimeRadar;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdateTimeRadar() {

    return m_updateTimeRadarPresent;
}

// setter for PosReport
void PosReport::setUpdateTimeAIS(QDateTime val) {

    m_updateTimeAISPresent = true;
    m_updateTimeAIS = val;
}

// getter for PosReport
QDateTime PosReport::getUpdateTimeAIS() const {

    return m_updateTimeAIS;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdateTimeAIS() {

    return m_updateTimeAISPresent;
}

// setter for PosReport
void PosReport::setUpdateTimeDR(QDateTime val) {

    m_updateTimeDRPresent = true;
    m_updateTimeDR = val;
}

// getter for PosReport
QDateTime PosReport::getUpdateTimeDR() const {

    return m_updateTimeDR;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdateTimeDR() {

    return m_updateTimeDRPresent;
}

// setter for PosReport
void PosReport::setSOG(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_SOG = val;
}

// getter for PosReport
float PosReport::getSOG() const {

    return m_SOG;
}

// setter for PosReport
void PosReport::setCOG(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 360)
        return;
    m_COG = val;
}

// getter for PosReport
float PosReport::getCOG() const {

    return m_COG;
}

// setter for PosReport
void PosReport::setLost(QString val) {
// check if the new value is an approved value 

    if ( ( val != "no" ) &&
         ( val != "yes" ) )
        return;
    m_lost = val;
}

// getter for PosReport
QString PosReport::getLost() const {

    return m_lost;
}

// setter for PosReport
void PosReport::setRateOfTurn(float val) {

    m_rateOfTurnPresent = true;
    m_rateOfTurn = val;
}

// getter for PosReport
float PosReport::getRateOfTurn() const {

    return m_rateOfTurn;
}

// check if optional element PosReport has been set
bool PosReport::hasRateOfTurn() {

    return m_rateOfTurnPresent;
}

// setter for PosReport
void PosReport::setOrientation(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 360)
        return;
    m_orientationPresent = true;
    m_orientation = val;
}

// getter for PosReport
float PosReport::getOrientation() const {

    return m_orientation;
}

// check if optional element PosReport has been set
bool PosReport::hasOrientation() {

    return m_orientationPresent;
}

// setter for PosReport
void PosReport::setLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_lengthPresent = true;
    m_length = val;
}

// getter for PosReport
float PosReport::getLength() const {

    return m_length;
}

// check if optional element PosReport has been set
bool PosReport::hasLength() {

    return m_lengthPresent;
}

// setter for PosReport
void PosReport::setBreadth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_breadthPresent = true;
    m_breadth = val;
}

// getter for PosReport
float PosReport::getBreadth() const {

    return m_breadth;
}

// check if optional element PosReport has been set
bool PosReport::hasBreadth() {

    return m_breadthPresent;
}

// setter for PosReport
void PosReport::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
}

// getter for PosReport
float PosReport::getAltitude() const {

    return m_altitude;
}

// check if optional element PosReport has been set
bool PosReport::hasAltitude() {

    return m_altitudePresent;
}

// setter for PosReport
void PosReport::setNavStatus(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
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
         ( val != 15 ) )
        return;
    m_navStatusPresent = true;
    m_navStatus = val;
}

// getter for PosReport
int PosReport::getNavStatus() const {

    return m_navStatus;
}

// check if optional element PosReport has been set
bool PosReport::hasNavStatus() {

    return m_navStatusPresent;
}

// setter for PosReport
void PosReport::setUpdSensorType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_updSensorTypePresent = true;
    m_updSensorType = val;
}

// getter for PosReport
int PosReport::getUpdSensorType() const {

    return m_updSensorType;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdSensorType() {

    return m_updSensorTypePresent;
}

// setter for PosReport
void PosReport::setATONOffPos(bool val) {

    m_ATONOffPosPresent = true;
    m_ATONOffPos = val;
}

// getter for PosReport
bool PosReport::getATONOffPos() const {

    return m_ATONOffPos;
}

// check if optional element PosReport has been set
bool PosReport::hasATONOffPos() {

    return m_ATONOffPosPresent;
}

// Get XML Representation
QString PosReport::toXML() {

    QString xml = "<PosReport";
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    // check for presence of optional attribute
    if ( hasUpdateTimeRadar() ) {
        xml.append(" UpdateTimeRadar=\"" + m_updateTimeRadar.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasUpdateTimeAIS() ) {
        xml.append(" UpdateTimeAIS=\"" + m_updateTimeAIS.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    // check for presence of optional attribute
    if ( hasUpdateTimeDR() ) {
        xml.append(" UpdateTimeDR=\"" + m_updateTimeDR.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    }
    xml.append(" SOG=\"" + QString::number(m_SOG) + "\"");
    xml.append(" COG=\"" + QString::number(m_COG) + "\"");
    xml.append(" Lost=\"" + encode (m_lost) + "\"");
    // check for presence of optional attribute
    if ( hasRateOfTurn() ) {
        xml.append(" RateOfTurn=\"" + QString::number(m_rateOfTurn) + "\"");
    }
    // check for presence of optional attribute
    if ( hasOrientation() ) {
        xml.append(" Orientation=\"" + QString::number(m_orientation) + "\"");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    // check for presence of optional attribute
    if ( hasBreadth() ) {
        xml.append(" Breadth=\"" + QString::number(m_breadth) + "\"");
    }
    // check for presence of optional attribute
    if ( hasAltitude() ) {
        xml.append(" Altitude=\"" + QString::number(m_altitude) + "\"");
    }
    // check for presence of optional attribute
    if ( hasNavStatus() ) {
        xml.append(" NavStatus=\"" + QString::number(m_navStatus) + "\"");
    }
    // check for presence of optional attribute
    if ( hasUpdSensorType() ) {
        xml.append(" UpdSensorType=\"" + QString::number(m_updSensorType) + "\"");
    }
    // check for presence of optional attribute
    if ( hasATONOffPos() ) {
        xml.append(" ATONOffPos=\"" + QString(m_ATONOffPos ? "yes" : "no" ) + "\"");
    }
    xml.append(">\n");
    xml.append( m_pos.toXML() );
    // add all included data
    for(int i=0; i < m_sensors.count(); i++ ) {
        Sensor attribute = m_sensors.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</PosReport>\n");
    return xml;
}

// Get String Representation
QString PosReport::toString() {

    return toString("");
}

// Get String Representation with a lead
QString PosReport::toString(QString lead) {

    QString str = lead + "PosReport\n";
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    // check for presence of optional attribute
    if ( hasUpdateTimeRadar() ) {
        str.append( lead + "    UpdateTimeRadar = " + m_updateTimeRadar.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasUpdateTimeAIS() ) {
        str.append( lead + "    UpdateTimeAIS = " + m_updateTimeAIS.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    // check for presence of optional attribute
    if ( hasUpdateTimeDR() ) {
        str.append( lead + "    UpdateTimeDR = " + m_updateTimeDR.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    }
    str.append( lead + "    SOG = " + QString::number(m_SOG) + "\n");
    str.append( lead + "    COG = " + QString::number(m_COG) + "\n");
    str.append( lead + "    Lost = " + m_lost + "\n");
    // check for presence of optional attribute
    if ( hasRateOfTurn() ) {
        str.append( lead + "    RateOfTurn = " + QString::number(m_rateOfTurn) + "\n");
    }
    // check for presence of optional attribute
    if ( hasOrientation() ) {
        str.append( lead + "    Orientation = " + QString::number(m_orientation) + "\n");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    // check for presence of optional attribute
    if ( hasBreadth() ) {
        str.append( lead + "    Breadth = " + QString::number(m_breadth) + "\n");
    }
    // check for presence of optional attribute
    if ( hasAltitude() ) {
        str.append( lead + "    Altitude = " + QString::number(m_altitude) + "\n");
    }
    // check for presence of optional attribute
    if ( hasNavStatus() ) {
        str.append( lead + "    NavStatus = " + QString::number(m_navStatus) + "\n");
    }
    // check for presence of optional attribute
    if ( hasUpdSensorType() ) {
        str.append( lead + "    UpdSensorType = " + QString::number(m_updSensorType) + "\n");
    }
    // check for presence of optional attribute
    if ( hasATONOffPos() ) {
        str.append( lead + "    ATONOffPos = " + QString::number(m_ATONOffPos) + "\n");
    }
    str.append( m_pos.toString(lead + "    ") );
    // add all included data
    for(int i=0; i < m_sensors.count(); i++ ) {
       Sensor attribute = m_sensors.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

