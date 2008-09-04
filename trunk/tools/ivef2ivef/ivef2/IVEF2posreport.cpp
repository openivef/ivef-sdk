
#include "IVEF2posreport.h"

PosReport::PosReport() {

    m_sourceNamePresent = false;
    m_orientationPresent = false;
    m_estAccSOGPresent = false;
    m_estAccCOGPresent = false;
    m_estAccOrientationPresent = false;
    m_ROTPresent = false;
    m_lengthPresent = false;
    m_breadthPresent = false;
    m_altitudePresent = false;
    m_navStatusPresent = false;
    m_updSensorTypePresent = false;
}

PosReport::PosReport(const PosReport &val) : QObject() {

    m_pos = val.m_pos;
    m_alerts = val.m_alerts;
    m_sensors = val.m_sensors;
    m_id = val.m_id;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_updateTime = val.m_updateTime;
    m_SOG = val.m_SOG;
    m_COG = val.m_COG;
    m_orientationPresent = val.m_orientationPresent;
    m_orientation = val.m_orientation;
    m_estAccSOGPresent = val.m_estAccSOGPresent;
    m_estAccSOG = val.m_estAccSOG;
    m_estAccCOGPresent = val.m_estAccCOGPresent;
    m_estAccCOG = val.m_estAccCOG;
    m_estAccOrientationPresent = val.m_estAccOrientationPresent;
    m_estAccOrientation = val.m_estAccOrientation;
    m_trackStatus = val.m_trackStatus;
    m_ROTPresent = val.m_ROTPresent;
    m_ROT = val.m_ROT;
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
}

PosReport & PosReport::operator=(const PosReport &val) {

    m_pos = val.m_pos;
    m_alerts = val.m_alerts;
    m_sensors = val.m_sensors;
    m_id = val.m_id;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_updateTime = val.m_updateTime;
    m_SOG = val.m_SOG;
    m_COG = val.m_COG;
    m_orientationPresent = val.m_orientationPresent;
    m_orientation = val.m_orientation;
    m_estAccSOGPresent = val.m_estAccSOGPresent;
    m_estAccSOG = val.m_estAccSOG;
    m_estAccCOGPresent = val.m_estAccCOGPresent;
    m_estAccCOG = val.m_estAccCOG;
    m_estAccOrientationPresent = val.m_estAccOrientationPresent;
    m_estAccOrientation = val.m_estAccOrientation;
    m_trackStatus = val.m_trackStatus;
    m_ROTPresent = val.m_ROTPresent;
    m_ROT = val.m_ROT;
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
    return *this;
}

void PosReport::setPos(Pos val) {

    m_pos = val;
}

Pos PosReport::getPos() const {

    return m_pos;
}

void PosReport::addAlert(Alert val) {

    m_alerts.append(val);
}

Alert PosReport::getAlertAt(int i) const {

    return m_alerts.at(i);
}

int PosReport::countOfAlerts() const {

    return m_alerts.count();
}

void PosReport::addSensor(Sensor val) {

    m_sensors.append(val);
}

Sensor PosReport::getSensorAt(int i) const {

    return m_sensors.at(i);
}

int PosReport::countOfSensors() const {

    return m_sensors.count();
}

void PosReport::setId(int val) {

    m_id = val;
}

int PosReport::getId() const {

    return m_id;
}

void PosReport::setSourceId(int val) {

    m_sourceId = val;
}

int PosReport::getSourceId() const {

    return m_sourceId;
}

void PosReport::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
}

QString PosReport::getSourceName() const {

    return m_sourceName;
}

bool PosReport::hasSourceName() {

    return m_sourceNamePresent;
}

void PosReport::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

QDateTime PosReport::getUpdateTime() const {

    return m_updateTime;
}

void PosReport::setSOG(float val) {

    m_SOG = val;
}

float PosReport::getSOG() const {

    return m_SOG;
}

void PosReport::setCOG(float val) {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_COG = val;
}

float PosReport::getCOG() const {

    return m_COG;
}

void PosReport::setOrientation(float val) {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_orientationPresent = true;
    m_orientation = val;
}

float PosReport::getOrientation() const {

    return m_orientation;
}

bool PosReport::hasOrientation() {

    return m_orientationPresent;
}

void PosReport::setEstAccSOG(float val) {

    m_estAccSOGPresent = true;
    m_estAccSOG = val;
}

float PosReport::getEstAccSOG() const {

    return m_estAccSOG;
}

bool PosReport::hasEstAccSOG() {

    return m_estAccSOGPresent;
}

void PosReport::setEstAccCOG(float val) {

    m_estAccCOGPresent = true;
    m_estAccCOG = val;
}

float PosReport::getEstAccCOG() const {

    return m_estAccCOG;
}

bool PosReport::hasEstAccCOG() {

    return m_estAccCOGPresent;
}

void PosReport::setEstAccOrientation(float val) {

    m_estAccOrientationPresent = true;
    m_estAccOrientation = val;
}

float PosReport::getEstAccOrientation() const {

    return m_estAccOrientation;
}

bool PosReport::hasEstAccOrientation() {

    return m_estAccOrientationPresent;
}

void PosReport::setTrackStatus(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_trackStatus = val;
}

int PosReport::getTrackStatus() const {

    return m_trackStatus;
}

void PosReport::setROT(float val) {

    m_ROTPresent = true;
    m_ROT = val;
}

float PosReport::getROT() const {

    return m_ROT;
}

bool PosReport::hasROT() {

    return m_ROTPresent;
}

void PosReport::setLength(float val) {

    m_lengthPresent = true;
    m_length = val;
}

float PosReport::getLength() const {

    return m_length;
}

bool PosReport::hasLength() {

    return m_lengthPresent;
}

void PosReport::setBreadth(float val) {

    m_breadthPresent = true;
    m_breadth = val;
}

float PosReport::getBreadth() const {

    return m_breadth;
}

bool PosReport::hasBreadth() {

    return m_breadthPresent;
}

void PosReport::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
}

float PosReport::getAltitude() const {

    return m_altitude;
}

bool PosReport::hasAltitude() {

    return m_altitudePresent;
}

void PosReport::setNavStatus(int val) {

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

int PosReport::getNavStatus() const {

    return m_navStatus;
}

bool PosReport::hasNavStatus() {

    return m_navStatusPresent;
}

void PosReport::setUpdSensorType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_updSensorTypePresent = true;
    m_updSensorType = val;
}

int PosReport::getUpdSensorType() const {

    return m_updSensorType;
}

bool PosReport::hasUpdSensorType() {

    return m_updSensorTypePresent;
}

QString PosReport::toXML() {

    QString xml = "<PosReport";
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    if ( hasSourceName() ) {
        xml.append(" SourceName=\"" + m_sourceName + "\"");
    }
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    xml.append(" SOG=\"" + QString::number(m_SOG) + "\"");
    xml.append(" COG=\"" + QString::number(m_COG) + "\"");
    if ( hasOrientation() ) {
        xml.append(" Orientation=\"" + QString::number(m_orientation) + "\"");
    }
    if ( hasEstAccSOG() ) {
        xml.append(" EstAccSOG=\"" + QString::number(m_estAccSOG) + "\"");
    }
    if ( hasEstAccCOG() ) {
        xml.append(" EstAccCOG=\"" + QString::number(m_estAccCOG) + "\"");
    }
    if ( hasEstAccOrientation() ) {
        xml.append(" EstAccOrientation=\"" + QString::number(m_estAccOrientation) + "\"");
    }
    xml.append(" TrackStatus=\"" + QString::number(m_trackStatus) + "\"");
    if ( hasROT() ) {
        xml.append(" ROT=\"" + QString::number(m_ROT) + "\"");
    }
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    if ( hasBreadth() ) {
        xml.append(" Breadth=\"" + QString::number(m_breadth) + "\"");
    }
    if ( hasAltitude() ) {
        xml.append(" Altitude=\"" + QString::number(m_altitude) + "\"");
    }
    if ( hasNavStatus() ) {
        xml.append(" NavStatus=\"" + QString::number(m_navStatus) + "\"");
    }
    if ( hasUpdSensorType() ) {
        xml.append(" UpdSensorType=\"" + QString::number(m_updSensorType) + "\"");
    }
    xml.append(">\n");
    xml.append( m_pos.toXML() );
    for(int i=0; i < m_alerts.count(); i++ ) {
       Alert attribute = m_alerts.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_sensors.count(); i++ ) {
       Sensor attribute = m_sensors.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</PosReport>\n");
    return xml;
}

QString PosReport::toString(QString lead) {

    QString str = lead + "PosReport\n";
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    if ( hasSourceName() ) {
        str.append( lead + "    SourceName = " + m_sourceName + "\n");
    }
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    str.append( lead + "    SOG = " + QString::number(m_SOG) + "\n");
    str.append( lead + "    COG = " + QString::number(m_COG) + "\n");
    if ( hasOrientation() ) {
        str.append( lead + "    Orientation = " + QString::number(m_orientation) + "\n");
    }
    if ( hasEstAccSOG() ) {
        str.append( lead + "    EstAccSOG = " + QString::number(m_estAccSOG) + "\n");
    }
    if ( hasEstAccCOG() ) {
        str.append( lead + "    EstAccCOG = " + QString::number(m_estAccCOG) + "\n");
    }
    if ( hasEstAccOrientation() ) {
        str.append( lead + "    EstAccOrientation = " + QString::number(m_estAccOrientation) + "\n");
    }
    str.append( lead + "    TrackStatus = " + QString::number(m_trackStatus) + "\n");
    if ( hasROT() ) {
        str.append( lead + "    ROT = " + QString::number(m_ROT) + "\n");
    }
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    if ( hasBreadth() ) {
        str.append( lead + "    Breadth = " + QString::number(m_breadth) + "\n");
    }
    if ( hasAltitude() ) {
        str.append( lead + "    Altitude = " + QString::number(m_altitude) + "\n");
    }
    if ( hasNavStatus() ) {
        str.append( lead + "    NavStatus = " + QString::number(m_navStatus) + "\n");
    }
    if ( hasUpdSensorType() ) {
        str.append( lead + "    UpdSensorType = " + QString::number(m_updSensorType) + "\n");
    }
    str.append( m_pos.toString(lead + "    ") );
    for(int i=0; i < m_alerts.count(); i++ ) {
       Alert attribute = m_alerts.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_sensors.count(); i++ ) {
       Sensor attribute = m_sensors.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

