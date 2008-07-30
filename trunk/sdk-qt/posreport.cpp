
#include "posreport.h"

PosReport::PosReport() {

    m_rateOfTurnPresent = false;
    m_orientationPresent = false;
    m_lengthPresent = false;
    m_breadthPresent = false;
    m_altitudePresent = false;
    m_navStatusPresent = false;
    m_updSensorTypePresent = false;
    m_ATONOffPosPresent = false;
}

PosReport::PosReport(const PosReport &val) : QObject() {

    m_pos = ((PosReport)val).getPos();
    m_id = ((PosReport)val).getId();
    m_sourceId = ((PosReport)val).getSourceId();
    m_updateTime = ((PosReport)val).getUpdateTime();
    m_SOG = ((PosReport)val).getSOG();
    m_COG = ((PosReport)val).getCOG();
    m_lost = ((PosReport)val).getLost();
    m_rateOfTurnPresent = false;
    m_rateOfTurn = ((PosReport)val).getRateOfTurn();
    m_orientationPresent = false;
    m_orientation = ((PosReport)val).getOrientation();
    m_lengthPresent = false;
    m_length = ((PosReport)val).getLength();
    m_breadthPresent = false;
    m_breadth = ((PosReport)val).getBreadth();
    m_altitudePresent = false;
    m_altitude = ((PosReport)val).getAltitude();
    m_navStatusPresent = false;
    m_navStatus = ((PosReport)val).getNavStatus();
    m_updSensorTypePresent = false;
    m_updSensorType = ((PosReport)val).getUpdSensorType();
    m_ATONOffPosPresent = false;
    m_ATONOffPos = ((PosReport)val).getATONOffPos();
}

PosReport & PosReport::operator=(const PosReport &/*val*/) {

    return *this;
}

void PosReport::setPos(Pos val) {

    m_pos = val;
}

Pos PosReport::getPos() {

    return m_pos;
}

void PosReport::setId(int val) {

    m_id = val;
}

int PosReport::getId() {

    return m_id;
}

void PosReport::setSourceId(int val) {

    m_sourceId = val;
}

int PosReport::getSourceId() {

    return m_sourceId;
}

void PosReport::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

QDateTime PosReport::getUpdateTime() {

    return m_updateTime;
}

void PosReport::setSOG(float val) {

    m_SOG = val;
}

float PosReport::getSOG() {

    return m_SOG;
}

void PosReport::setCOG(float val) {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_COG = val;
}

float PosReport::getCOG() {

    return m_COG;
}

void PosReport::setLost(QString val) {

    if ( ( val != "no" ) &&
         ( val != "yes" ) )
        return;
    m_lost = val;
}

QString PosReport::getLost() {

    return m_lost;
}

void PosReport::setRateOfTurn(float val) {

    m_rateOfTurnPresent = true;
    m_rateOfTurn = val;
}

float PosReport::getRateOfTurn() {

    return m_rateOfTurn;
}

bool PosReport::hasRateOfTurn() {

    return m_rateOfTurnPresent;
}

void PosReport::setOrientation(float val) {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_orientationPresent = true;
    m_orientation = val;
}

float PosReport::getOrientation() {

    return m_orientation;
}

bool PosReport::hasOrientation() {

    return m_orientationPresent;
}

void PosReport::setLength(float val) {

    m_lengthPresent = true;
    m_length = val;
}

float PosReport::getLength() {

    return m_length;
}

bool PosReport::hasLength() {

    return m_lengthPresent;
}

void PosReport::setBreadth(float val) {

    m_breadthPresent = true;
    m_breadth = val;
}

float PosReport::getBreadth() {

    return m_breadth;
}

bool PosReport::hasBreadth() {

    return m_breadthPresent;
}

void PosReport::setAltitude(float val) {

    m_altitudePresent = true;
    m_altitude = val;
}

float PosReport::getAltitude() {

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

int PosReport::getNavStatus() {

    return m_navStatus;
}

bool PosReport::hasNavStatus() {

    return m_navStatusPresent;
}

void PosReport::setUpdSensorType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) )
        return;
    m_updSensorTypePresent = true;
    m_updSensorType = val;
}

int PosReport::getUpdSensorType() {

    return m_updSensorType;
}

bool PosReport::hasUpdSensorType() {

    return m_updSensorTypePresent;
}

void PosReport::setATONOffPos(bool val) {

    m_ATONOffPosPresent = true;
    m_ATONOffPos = val;
}

bool PosReport::getATONOffPos() {

    return m_ATONOffPos;
}

bool PosReport::hasATONOffPos() {

    return m_ATONOffPosPresent;
}

QString PosReport::toXML() {

    QString xml = "<PosReport";
    xml.append(" Id = \"" + QString(m_id, 10) + "\"");
    xml.append(" SourceId = \"" + QString(m_sourceId, 10) + "\"");
    xml.append(" UpdateTime = \"" + m_updateTime.toString() + "\"");
    xml.append(" SOG = \"" + QString(m_SOG, 10) + "\"");
    xml.append(" COG = \"" + QString(m_COG, 10) + "\"");
    xml.append(" Lost = \"" + m_lost + "\"");
    if ( hasRateOfTurn() ) {
        xml.append(" RateOfTurn = \"" + QString(m_rateOfTurn, 10) + "\"");
    }
    if ( hasOrientation() ) {
        xml.append(" Orientation = \"" + QString(m_orientation, 10) + "\"");
    }
    if ( hasLength() ) {
        xml.append(" Length = \"" + QString(m_length, 10) + "\"");
    }
    if ( hasBreadth() ) {
        xml.append(" Breadth = \"" + QString(m_breadth, 10) + "\"");
    }
    if ( hasAltitude() ) {
        xml.append(" Altitude = \"" + QString(m_altitude, 10) + "\"");
    }
    if ( hasNavStatus() ) {
        xml.append(" NavStatus = \"" + QString(m_navStatus, 10) + "\"");
    }
    if ( hasUpdSensorType() ) {
        xml.append(" UpdSensorType = \"" + QString(m_updSensorType, 10) + "\"");
    }
    if ( hasATONOffPos() ) {
        xml.append(" ATONOffPos = \"" + QString(m_ATONOffPos, 10) + "\"");
    }
    xml.append(">\n");
    xml.append( m_pos.toXML() );
    xml.append( "<PosReport />\n");
    return xml;
}

