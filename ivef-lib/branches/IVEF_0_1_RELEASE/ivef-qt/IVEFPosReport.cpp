
#include "IVEFPosReport.h"

// Constructor
PosReport::PosReport() {

    m_posPresent = false;
    m_sensorPresent = false;
    m_id = 0;
    m_idPresent = false;
    m_sourceId = 0;
    m_sourceIdPresent = false;
    // initialize with random value
    m_updateTime = QDateTime();
    m_updateTimePresent = false;
    // initialize with random value
    m_updateTimeRadar = QDateTime();
    m_updateTimeRadarPresent = false;
    // initialize with random value
    m_updateTimeAIS = QDateTime();
    m_updateTimeAISPresent = false;
    // initialize with random value
    m_updateTimeDR = QDateTime();
    m_updateTimeDRPresent = false;
    m_SOG = 0.0;
    m_SOGPresent = false;
    m_COG = 0.0;
    m_COGPresent = false;
    // initialize empty string
    m_lost = "";
    m_lostPresent = false;
    m_rateOfTurn = 0.0;
    m_rateOfTurnPresent = false;
    m_orientation = 0.0;
    m_orientationPresent = false;
    m_length = 0.0;
    m_lengthPresent = false;
    m_breadth = 0.0;
    m_breadthPresent = false;
    m_altitude = 0.0;
    m_altitudePresent = false;
    m_navStatus = 0;
    m_navStatusPresent = false;
    m_updSensorType = 0;
    m_updSensorTypePresent = false;
    // initialize defaults to false
    m_ATONOffPos = false;
    m_ATONOffPosPresent = false;
}

// copy constructor
PosReport::PosReport(const PosReport &val) : QObject() {

    m_posPresent = val.m_posPresent;
    m_pos = val.m_pos;
    m_sensorPresent = val.m_sensorPresent;
    m_sensors = val.m_sensors;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_updateTimeRadarPresent = val.m_updateTimeRadarPresent;
    m_updateTimeRadar = val.m_updateTimeRadar;
    m_updateTimeAISPresent = val.m_updateTimeAISPresent;
    m_updateTimeAIS = val.m_updateTimeAIS;
    m_updateTimeDRPresent = val.m_updateTimeDRPresent;
    m_updateTimeDR = val.m_updateTimeDR;
    m_SOGPresent = val.m_SOGPresent;
    m_SOG = val.m_SOG;
    m_COGPresent = val.m_COGPresent;
    m_COG = val.m_COG;
    m_lostPresent = val.m_lostPresent;
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

// assignement
PosReport & PosReport::operator=(const PosReport &val) {

    m_posPresent = val.m_posPresent;
    m_pos = val.m_pos;
    m_sensorPresent = val.m_sensorPresent;
    m_sensors = val.m_sensors;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_updateTimeRadarPresent = val.m_updateTimeRadarPresent;
    m_updateTimeRadar = val.m_updateTimeRadar;
    m_updateTimeAISPresent = val.m_updateTimeAISPresent;
    m_updateTimeAIS = val.m_updateTimeAIS;
    m_updateTimeDRPresent = val.m_updateTimeDRPresent;
    m_updateTimeDR = val.m_updateTimeDR;
    m_SOGPresent = val.m_SOGPresent;
    m_SOG = val.m_SOG;
    m_COGPresent = val.m_COGPresent;
    m_COG = val.m_COG;
    m_lostPresent = val.m_lostPresent;
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
QString PosReport::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for PosReport
bool PosReport::setPos(Pos val) {

    m_posPresent = true;
    m_pos = val;
      return true;
}

// getter for PosReport
Pos PosReport::getPos() const {

    return m_pos;
}

// setter for PosReport
bool PosReport::addSensor(Sensor val) {

   m_sensors.append(val);
      return true;
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
bool PosReport::setId(int val) {

    m_idPresent = true;
    m_id = val;
      return true;
}

// getter for PosReport
int PosReport::getId() const {

    return m_id;
}

// setter for PosReport
bool PosReport::setSourceId(int val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
      return true;
}

// getter for PosReport
int PosReport::getSourceId() const {

    return m_sourceId;
}

// setter for PosReport
bool PosReport::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
      return true;
}

// getter for PosReport
QDateTime PosReport::getUpdateTime() const {

    return m_updateTime;
}

// setter for PosReport
bool PosReport::setUpdateTimeRadar(QDateTime val) {

    m_updateTimeRadarPresent = true;
    m_updateTimeRadar = val;
      return true;
}

// getter for PosReport
QDateTime PosReport::getUpdateTimeRadar() const {

    return m_updateTimeRadar;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdateTimeRadar() const {

    return m_updateTimeRadarPresent;
}

// setter for PosReport
bool PosReport::setUpdateTimeAIS(QDateTime val) {

    m_updateTimeAISPresent = true;
    m_updateTimeAIS = val;
      return true;
}

// getter for PosReport
QDateTime PosReport::getUpdateTimeAIS() const {

    return m_updateTimeAIS;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdateTimeAIS() const {

    return m_updateTimeAISPresent;
}

// setter for PosReport
bool PosReport::setUpdateTimeDR(QDateTime val) {

    m_updateTimeDRPresent = true;
    m_updateTimeDR = val;
      return true;
}

// getter for PosReport
QDateTime PosReport::getUpdateTimeDR() const {

    return m_updateTimeDR;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdateTimeDR() const {

    return m_updateTimeDRPresent;
}

// setter for PosReport
bool PosReport::setSOG(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_SOGPresent = true;
    m_SOG = val;
      return true;
}

// getter for PosReport
float PosReport::getSOG() const {

    return m_SOG;
}

// setter for PosReport
bool PosReport::setCOG(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;    // check if the new value is within bounds 

    if (val > 360)
        return false;
    m_COGPresent = true;
    m_COG = val;
      return true;
}

// getter for PosReport
float PosReport::getCOG() const {

    return m_COG;
}

// setter for PosReport
bool PosReport::setLost(QString val) {
// check if the new value is an approved value 

    if ( ( val != "no" ) &&
         ( val != "yes" ) )
        return false;
    m_lostPresent = true;
    m_lost = val;
      return true;
}

// getter for PosReport
QString PosReport::getLost() const {

    return m_lost;
}

// setter for PosReport
bool PosReport::setRateOfTurn(float val) {

    m_rateOfTurnPresent = true;
    m_rateOfTurn = val;
      return true;
}

// getter for PosReport
float PosReport::getRateOfTurn() const {

    return m_rateOfTurn;
}

// check if optional element PosReport has been set
bool PosReport::hasRateOfTurn() const {

    return m_rateOfTurnPresent;
}

// setter for PosReport
bool PosReport::setOrientation(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;    // check if the new value is within bounds 

    if (val > 360)
        return false;
    m_orientationPresent = true;
    m_orientation = val;
      return true;
}

// getter for PosReport
float PosReport::getOrientation() const {

    return m_orientation;
}

// check if optional element PosReport has been set
bool PosReport::hasOrientation() const {

    return m_orientationPresent;
}

// setter for PosReport
bool PosReport::setLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_lengthPresent = true;
    m_length = val;
      return true;
}

// getter for PosReport
float PosReport::getLength() const {

    return m_length;
}

// check if optional element PosReport has been set
bool PosReport::hasLength() const {

    return m_lengthPresent;
}

// setter for PosReport
bool PosReport::setBreadth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;
    m_breadthPresent = true;
    m_breadth = val;
      return true;
}

// getter for PosReport
float PosReport::getBreadth() const {

    return m_breadth;
}

// check if optional element PosReport has been set
bool PosReport::hasBreadth() const {

    return m_breadthPresent;
}

// setter for PosReport
bool PosReport::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
      return true;
}

// getter for PosReport
float PosReport::getAltitude() const {

    return m_altitude;
}

// check if optional element PosReport has been set
bool PosReport::hasAltitude() const {

    return m_altitudePresent;
}

// setter for PosReport
bool PosReport::setNavStatus(int val) {
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
        return false;
    m_navStatusPresent = true;
    m_navStatus = val;
      return true;
}

// getter for PosReport
int PosReport::getNavStatus() const {

    return m_navStatus;
}

// check if optional element PosReport has been set
bool PosReport::hasNavStatus() const {

    return m_navStatusPresent;
}

// setter for PosReport
bool PosReport::setUpdSensorType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return false;
    m_updSensorTypePresent = true;
    m_updSensorType = val;
      return true;
}

// getter for PosReport
int PosReport::getUpdSensorType() const {

    return m_updSensorType;
}

// check if optional element PosReport has been set
bool PosReport::hasUpdSensorType() const {

    return m_updSensorTypePresent;
}

// setter for PosReport
bool PosReport::setATONOffPos(bool val) {

    m_ATONOffPosPresent = true;
    m_ATONOffPos = val;
      return true;
}

// getter for PosReport
bool PosReport::getATONOffPos() const {

    return m_ATONOffPos;
}

// check if optional element PosReport has been set
bool PosReport::hasATONOffPos() const {

    return m_ATONOffPosPresent;
}

// Get XML Representation
QString PosReport::toXML() const {

    QString xml = "<PosReport";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_idPresent) {
        xml.append(" Id=\"" + QString::number(m_id) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_sourceIdPresent) {
        xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_updateTimePresent) {
        xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    } else { // required attribute not present
        return NULL;
    }
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
    // check for presence of required  attribute
    if ( m_SOGPresent) {
        xml.append(" SOG=\"" + QString::number(m_SOG, 'f') + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_COGPresent) {
        xml.append(" COG=\"" + QString::number(m_COG, 'f') + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_lostPresent) {
        xml.append(" Lost=\"" + encode (m_lost) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasRateOfTurn() ) {
        xml.append(" RateOfTurn=\"" + QString::number(m_rateOfTurn, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasOrientation() ) {
        xml.append(" Orientation=\"" + QString::number(m_orientation, 'f') + "\"");
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
    if ( hasAltitude() ) {
        xml.append(" Altitude=\"" + QString::number(m_altitude, 'f') + "\"");
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
        xml.append(" ATONOffPos=\"" + QString(m_ATONOffPos ? "true" : "false" ) + "\"");
    }
    xml.append(">\n");
    // check for presence of required data member
    if ( m_posPresent) {
        dataMember = m_pos.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
    // add all included data
    for(int i=0; i < m_sensors.count(); i++ ) {
        Sensor attribute = m_sensors.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
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
    str.append( lead + "    SOG = " + QString::number(m_SOG, 'f') + "\n");
    str.append( lead + "    COG = " + QString::number(m_COG, 'f') + "\n");
    str.append( lead + "    Lost = " + m_lost + "\n");
    // check for presence of optional attribute
    if ( hasRateOfTurn() ) {
        str.append( lead + "    RateOfTurn = " + QString::number(m_rateOfTurn, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasOrientation() ) {
        str.append( lead + "    Orientation = " + QString::number(m_orientation, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasBreadth() ) {
        str.append( lead + "    Breadth = " + QString::number(m_breadth, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasAltitude() ) {
        str.append( lead + "    Altitude = " + QString::number(m_altitude, 'f') + "\n");
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
        str.append( lead + "    ATONOffPos = " + QString(m_ATONOffPos ? "true" : "false" ) + "\n");
    }
    str.append( m_pos.toString(lead + "    ") );
    // add all included data
    for(int i=0; i < m_sensors.count(); i++ ) {
       Sensor attribute = m_sensors.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

