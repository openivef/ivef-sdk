
#include "IVEFTrackData.h"

TrackData::TrackData() {

    m_COG = 0.0;
    m_estAccSOG = 0.0;
    m_estAccSOGPresent = false;
    m_estAccCOG = 0.0;
    m_estAccCOGPresent = false;
    m_id = 0;
    m_length = 0.0;
    m_lengthPresent = false;
    m_navStatus = 0;
    m_navStatusPresent = false;
    m_heading = 0.0;
    m_headingPresent = false;
    m_ROT = 0.0;
    m_ROTPresent = false;
    m_SOG = 0.0;
    m_sourceId = "";
    m_sourceIdPresent = false;
    m_sourceName = "";
    m_updateTime = QDateTime();
    m_trackStatus = 0;
    m_width = 0.0;
    m_widthPresent = false;
}

TrackData::TrackData(const TrackData &val) : QObject() {

    m_poss = val.m_poss;
    m_COG = val.m_COG;
    m_estAccSOGPresent = val.m_estAccSOGPresent;
    m_estAccSOG = val.m_estAccSOG;
    m_estAccCOGPresent = val.m_estAccCOGPresent;
    m_estAccCOG = val.m_estAccCOG;
    m_id = val.m_id;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_navStatusPresent = val.m_navStatusPresent;
    m_navStatus = val.m_navStatus;
    m_headingPresent = val.m_headingPresent;
    m_heading = val.m_heading;
    m_ROTPresent = val.m_ROTPresent;
    m_ROT = val.m_ROT;
    m_SOG = val.m_SOG;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceName = val.m_sourceName;
    m_updateTime = val.m_updateTime;
    m_trackStatus = val.m_trackStatus;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
}

TrackData & TrackData::operator=(const TrackData &val) {

    m_poss = val.m_poss;
    m_COG = val.m_COG;
    m_estAccSOGPresent = val.m_estAccSOGPresent;
    m_estAccSOG = val.m_estAccSOG;
    m_estAccCOGPresent = val.m_estAccCOGPresent;
    m_estAccCOG = val.m_estAccCOG;
    m_id = val.m_id;
    m_lengthPresent = val.m_lengthPresent;
    m_length = val.m_length;
    m_navStatusPresent = val.m_navStatusPresent;
    m_navStatus = val.m_navStatus;
    m_headingPresent = val.m_headingPresent;
    m_heading = val.m_heading;
    m_ROTPresent = val.m_ROTPresent;
    m_ROT = val.m_ROT;
    m_SOG = val.m_SOG;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceName = val.m_sourceName;
    m_updateTime = val.m_updateTime;
    m_trackStatus = val.m_trackStatus;
    m_widthPresent = val.m_widthPresent;
    m_width = val.m_width;
    return *this;
}

QString TrackData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void TrackData::addPos(Pos val) {

    m_poss.append(val);
}

Pos TrackData::getPosAt(int i) const {

    return m_poss.at(i);
}

int TrackData::countOfPoss() const {

    return m_poss.count();
}

void TrackData::setCOG(float val) {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_COG = val;
}

float TrackData::getCOG() const {

    return m_COG;
}

void TrackData::setEstAccSOG(float val) {

    m_estAccSOGPresent = true;
    m_estAccSOG = val;
}

float TrackData::getEstAccSOG() const {

    return m_estAccSOG;
}

bool TrackData::hasEstAccSOG() {

    return m_estAccSOGPresent;
}

void TrackData::setEstAccCOG(float val) {

    m_estAccCOGPresent = true;
    m_estAccCOG = val;
}

float TrackData::getEstAccCOG() const {

    return m_estAccCOG;
}

bool TrackData::hasEstAccCOG() {

    return m_estAccCOGPresent;
}

void TrackData::setId(int val) {

    m_id = val;
}

int TrackData::getId() const {

    return m_id;
}

void TrackData::setLength(float val) {

    m_lengthPresent = true;
    m_length = val;
}

float TrackData::getLength() const {

    return m_length;
}

bool TrackData::hasLength() {

    return m_lengthPresent;
}

void TrackData::setNavStatus(int val) {

    if (val < 0)
        return;
    if (val > 15)
        return;
    m_navStatusPresent = true;
    m_navStatus = val;
}

int TrackData::getNavStatus() const {

    return m_navStatus;
}

bool TrackData::hasNavStatus() {

    return m_navStatusPresent;
}

void TrackData::setHeading(float val) {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_headingPresent = true;
    m_heading = val;
}

float TrackData::getHeading() const {

    return m_heading;
}

bool TrackData::hasHeading() {

    return m_headingPresent;
}

void TrackData::setROT(float val) {

    if (val < -720)
        return;
    if (val > 720)
        return;
    m_ROTPresent = true;
    m_ROT = val;
}

float TrackData::getROT() const {

    return m_ROT;
}

bool TrackData::hasROT() {

    return m_ROTPresent;
}

void TrackData::setSOG(float val) {

    m_SOG = val;
}

float TrackData::getSOG() const {

    return m_SOG;
}

void TrackData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
}

QString TrackData::getSourceId() const {

    return m_sourceId;
}

bool TrackData::hasSourceId() {

    return m_sourceIdPresent;
}

void TrackData::setSourceName(QString val) {

    m_sourceName = val;
}

QString TrackData::getSourceName() const {

    return m_sourceName;
}

void TrackData::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

QDateTime TrackData::getUpdateTime() const {

    return m_updateTime;
}

void TrackData::setTrackStatus(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_trackStatus = val;
}

int TrackData::getTrackStatus() const {

    return m_trackStatus;
}

void TrackData::setWidth(float val) {

    m_widthPresent = true;
    m_width = val;
}

float TrackData::getWidth() const {

    return m_width;
}

bool TrackData::hasWidth() {

    return m_widthPresent;
}

QString TrackData::toXML() {

    QString xml = "<TrackData";
    xml.append(" COG=\"" + QString::number(m_COG) + "\"");
    if ( hasEstAccSOG() ) {
        xml.append(" EstAccSOG=\"" + QString::number(m_estAccSOG) + "\"");
    }
    if ( hasEstAccCOG() ) {
        xml.append(" EstAccCOG=\"" + QString::number(m_estAccCOG) + "\"");
    }
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length) + "\"");
    }
    if ( hasNavStatus() ) {
        xml.append(" NavStatus=\"" + QString::number(m_navStatus) + "\"");
    }
    if ( hasHeading() ) {
        xml.append(" Heading=\"" + QString::number(m_heading) + "\"");
    }
    if ( hasROT() ) {
        xml.append(" ROT=\"" + QString::number(m_ROT) + "\"");
    }
    xml.append(" SOG=\"" + QString::number(m_SOG) + "\"");
    if ( hasSourceId() ) {
        xml.append(" SourceId=\"" + encode (m_sourceId) + "\"");
    }
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(" TrackStatus=\"" + QString::number(m_trackStatus) + "\"");
    if ( hasWidth() ) {
        xml.append(" Width=\"" + QString::number(m_width) + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</TrackData>\n");
    return xml;
}

QString TrackData::toString(QString lead) {

    QString str = lead + "TrackData\n";
    str.append( lead + "    COG = " + QString::number(m_COG) + "\n");
    if ( hasEstAccSOG() ) {
        str.append( lead + "    EstAccSOG = " + QString::number(m_estAccSOG) + "\n");
    }
    if ( hasEstAccCOG() ) {
        str.append( lead + "    EstAccCOG = " + QString::number(m_estAccCOG) + "\n");
    }
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length) + "\n");
    }
    if ( hasNavStatus() ) {
        str.append( lead + "    NavStatus = " + QString::number(m_navStatus) + "\n");
    }
    if ( hasHeading() ) {
        str.append( lead + "    Heading = " + QString::number(m_heading) + "\n");
    }
    if ( hasROT() ) {
        str.append( lead + "    ROT = " + QString::number(m_ROT) + "\n");
    }
    str.append( lead + "    SOG = " + QString::number(m_SOG) + "\n");
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    str.append( lead + "    TrackStatus = " + QString::number(m_trackStatus) + "\n");
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number(m_width) + "\n");
    }
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

