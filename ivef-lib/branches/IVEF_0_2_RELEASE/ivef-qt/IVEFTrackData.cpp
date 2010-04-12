
#include "IVEFTrackData.h"

// Constructor
TrackData::TrackData() {

    m_COG = 0.0;
    m_estAccSOG = 0.0;
    // optional attributes are by default not present
    m_estAccSOGPresent = false;
    m_estAccCOG = 0.0;
    // optional attributes are by default not present
    m_estAccCOGPresent = false;
    m_id = 0;
    m_length = 0.0;
    // optional attributes are by default not present
    m_lengthPresent = false;
    m_navStatus = 0;
    // optional attributes are by default not present
    m_navStatusPresent = false;
    m_heading = 0.0;
    // optional attributes are by default not present
    m_headingPresent = false;
    m_ROT = 0.0;
    // optional attributes are by default not present
    m_ROTPresent = false;
    m_SOG = 0.0;
    // initialize empty string
    m_sourceId = "";
    // optional attributes are by default not present
    m_sourceIdPresent = false;
    // initialize empty string
    m_sourceName = "";
    // initialize with random value
    m_updateTime = QDateTime();
    m_trackStatus = 0;
    m_width = 0.0;
    // optional attributes are by default not present
    m_widthPresent = false;
}

// copy constructor
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

// assignement
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

// String encoder
QString TrackData::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for TrackData
void TrackData::addPos(Pos val) {

    m_poss.append(val);
}

// getter for TrackData
Pos TrackData::getPosAt(int i) const {

    return m_poss.at(i);
}

// count for TrackData
int TrackData::countOfPoss() const {

    return m_poss.count();
}

// setter for TrackData
void TrackData::setCOG(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 360)
        return;
    m_COG = val;
}

// getter for TrackData
float TrackData::getCOG() const {

    return m_COG;
}

// setter for TrackData
void TrackData::setEstAccSOG(float val) {

    m_estAccSOGPresent = true;
    m_estAccSOG = val;
}

// getter for TrackData
float TrackData::getEstAccSOG() const {

    return m_estAccSOG;
}

// check if optional element TrackData has been set
bool TrackData::hasEstAccSOG() const {

    return m_estAccSOGPresent;
}

// setter for TrackData
void TrackData::setEstAccCOG(float val) {

    m_estAccCOGPresent = true;
    m_estAccCOG = val;
}

// getter for TrackData
float TrackData::getEstAccCOG() const {

    return m_estAccCOG;
}

// check if optional element TrackData has been set
bool TrackData::hasEstAccCOG() const {

    return m_estAccCOGPresent;
}

// setter for TrackData
void TrackData::setId(int val) {

    m_id = val;
}

// getter for TrackData
int TrackData::getId() const {

    return m_id;
}

// setter for TrackData
void TrackData::setLength(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_lengthPresent = true;
    m_length = val;
}

// getter for TrackData
float TrackData::getLength() const {

    return m_length;
}

// check if optional element TrackData has been set
bool TrackData::hasLength() const {

    return m_lengthPresent;
}

// setter for TrackData
void TrackData::setNavStatus(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 15)
        return;
    m_navStatusPresent = true;
    m_navStatus = val;
}

// getter for TrackData
int TrackData::getNavStatus() const {

    return m_navStatus;
}

// check if optional element TrackData has been set
bool TrackData::hasNavStatus() const {

    return m_navStatusPresent;
}

// setter for TrackData
void TrackData::setHeading(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 360)
        return;
    m_headingPresent = true;
    m_heading = val;
}

// getter for TrackData
float TrackData::getHeading() const {

    return m_heading;
}

// check if optional element TrackData has been set
bool TrackData::hasHeading() const {

    return m_headingPresent;
}

// setter for TrackData
void TrackData::setROT(float val) {
    // check if the new value is within bounds 

    if (val < -720)
        return;    // check if the new value is within bounds 

    if (val > 720)
        return;
    m_ROTPresent = true;
    m_ROT = val;
}

// getter for TrackData
float TrackData::getROT() const {

    return m_ROT;
}

// check if optional element TrackData has been set
bool TrackData::hasROT() const {

    return m_ROTPresent;
}

// setter for TrackData
void TrackData::setSOG(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_SOG = val;
}

// getter for TrackData
float TrackData::getSOG() const {

    return m_SOG;
}

// setter for TrackData
void TrackData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
}

// getter for TrackData
QString TrackData::getSourceId() const {

    return m_sourceId;
}

// check if optional element TrackData has been set
bool TrackData::hasSourceId() const {

    return m_sourceIdPresent;
}

// setter for TrackData
void TrackData::setSourceName(QString val) {

    m_sourceName = val;
}

// getter for TrackData
QString TrackData::getSourceName() const {

    return m_sourceName;
}

// setter for TrackData
void TrackData::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

// getter for TrackData
QDateTime TrackData::getUpdateTime() const {

    return m_updateTime;
}

// setter for TrackData
void TrackData::setTrackStatus(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_trackStatus = val;
}

// getter for TrackData
int TrackData::getTrackStatus() const {

    return m_trackStatus;
}

// setter for TrackData
void TrackData::setWidth(float val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;
    m_widthPresent = true;
    m_width = val;
}

// getter for TrackData
float TrackData::getWidth() const {

    return m_width;
}

// check if optional element TrackData has been set
bool TrackData::hasWidth() const {

    return m_widthPresent;
}

// Get XML Representation
QString TrackData::toXML() {

    QString xml = "<TrackData";
    xml.append(" COG=\"" + QString::number(m_COG, 'f') + "\"");
    // check for presence of optional attribute
    if ( hasEstAccSOG() ) {
        xml.append(" EstAccSOG=\"" + QString::number(m_estAccSOG, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasEstAccCOG() ) {
        xml.append(" EstAccCOG=\"" + QString::number(m_estAccCOG, 'f') + "\"");
    }
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    // check for presence of optional attribute
    if ( hasLength() ) {
        xml.append(" Length=\"" + QString::number(m_length, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasNavStatus() ) {
        xml.append(" NavStatus=\"" + QString::number(m_navStatus) + "\"");
    }
    // check for presence of optional attribute
    if ( hasHeading() ) {
        xml.append(" Heading=\"" + QString::number(m_heading, 'f') + "\"");
    }
    // check for presence of optional attribute
    if ( hasROT() ) {
        xml.append(" ROT=\"" + QString::number(m_ROT, 'f') + "\"");
    }
    xml.append(" SOG=\"" + QString::number(m_SOG, 'f') + "\"");
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        xml.append(" SourceId=\"" + encode (m_sourceId) + "\"");
    }
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(" TrackStatus=\"" + QString::number(m_trackStatus) + "\"");
    // check for presence of optional attribute
    if ( hasWidth() ) {
        xml.append(" Width=\"" + QString::number(m_width, 'f') + "\"");
    }
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</TrackData>\n");
    return xml;
}

// Get String Representation
QString TrackData::toString() {

    return toString("");
}

// Get String Representation with a lead
QString TrackData::toString(QString lead) {

    QString str = lead + "TrackData\n";
    str.append( lead + "    COG = " + QString::number(m_COG, 'f') + "\n");
    // check for presence of optional attribute
    if ( hasEstAccSOG() ) {
        str.append( lead + "    EstAccSOG = " + QString::number(m_estAccSOG, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasEstAccCOG() ) {
        str.append( lead + "    EstAccCOG = " + QString::number(m_estAccCOG, 'f') + "\n");
    }
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    // check for presence of optional attribute
    if ( hasLength() ) {
        str.append( lead + "    Length = " + QString::number(m_length, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasNavStatus() ) {
        str.append( lead + "    NavStatus = " + QString::number(m_navStatus) + "\n");
    }
    // check for presence of optional attribute
    if ( hasHeading() ) {
        str.append( lead + "    Heading = " + QString::number(m_heading, 'f') + "\n");
    }
    // check for presence of optional attribute
    if ( hasROT() ) {
        str.append( lead + "    ROT = " + QString::number(m_ROT, 'f') + "\n");
    }
    str.append( lead + "    SOG = " + QString::number(m_SOG, 'f') + "\n");
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    str.append( lead + "    TrackStatus = " + QString::number(m_trackStatus) + "\n");
    // check for presence of optional attribute
    if ( hasWidth() ) {
        str.append( lead + "    Width = " + QString::number(m_width, 'f') + "\n");
    }
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

