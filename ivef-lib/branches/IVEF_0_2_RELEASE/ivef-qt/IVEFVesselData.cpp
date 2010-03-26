
#include "IVEFVesselData.h"

// Constructor
VesselData::VesselData() {

    m_class = 0;
    // optional attributes are by default not present
    m_classPresent = false;
    // initialize defaults to false
    m_blackListed = false;
    // optional attributes are by default not present
    m_blackListedPresent = false;
    m_id = 0;
    // initialize empty string
    m_specialAttention = "";
    // optional attributes are by default not present
    m_specialAttentionPresent = false;
    // initialize empty string
    m_sourceId = "";
    // optional attributes are by default not present
    m_sourceIdPresent = false;
    // initialize empty string
    m_sourceName = "";
    m_sourceType = 0;
    // initialize with random value
    m_updateTime = QDateTime();
}

// copy constructor
VesselData::VesselData(const VesselData &val) : QObject() {

    m_construction = val.m_construction;
    m_identifier = val.m_identifier;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_blackListedPresent = val.m_blackListedPresent;
    m_blackListed = val.m_blackListed;
    m_id = val.m_id;
    m_specialAttentionPresent = val.m_specialAttentionPresent;
    m_specialAttention = val.m_specialAttention;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceName = val.m_sourceName;
    m_sourceType = val.m_sourceType;
    m_updateTime = val.m_updateTime;
}

// assignement
VesselData & VesselData::operator=(const VesselData &val) {

    m_construction = val.m_construction;
    m_identifier = val.m_identifier;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_blackListedPresent = val.m_blackListedPresent;
    m_blackListed = val.m_blackListed;
    m_id = val.m_id;
    m_specialAttentionPresent = val.m_specialAttentionPresent;
    m_specialAttention = val.m_specialAttention;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceName = val.m_sourceName;
    m_sourceType = val.m_sourceType;
    m_updateTime = val.m_updateTime;
    return *this;
}

// String encoder
QString VesselData::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for VesselData
void VesselData::setConstruction(Construction val) {

    m_construction = val;
}

// getter for VesselData
Construction VesselData::getConstruction() const {

    return m_construction;
}

// setter for VesselData
void VesselData::setIdentifier(Identifier val) {

    m_identifier = val;
}

// getter for VesselData
Identifier VesselData::getIdentifier() const {

    return m_identifier;
}

// setter for VesselData
void VesselData::setClass(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_classPresent = true;
    m_class = val;
}

// getter for VesselData
int VesselData::getClass() const {

    return m_class;
}

// check if optional element VesselData has been set
bool VesselData::hasClass() const {

    return m_classPresent;
}

// setter for VesselData
void VesselData::setBlackListed(bool val) {

    m_blackListedPresent = true;
    m_blackListed = val;
}

// getter for VesselData
bool VesselData::getBlackListed() const {

    return m_blackListed;
}

// check if optional element VesselData has been set
bool VesselData::hasBlackListed() const {

    return m_blackListedPresent;
}

// setter for VesselData
void VesselData::setId(int val) {

    m_id = val;
}

// getter for VesselData
int VesselData::getId() const {

    return m_id;
}

// setter for VesselData
void VesselData::setSpecialAttention(QString val) {

    m_specialAttentionPresent = true;
    m_specialAttention = val;
}

// getter for VesselData
QString VesselData::getSpecialAttention() const {

    return m_specialAttention;
}

// check if optional element VesselData has been set
bool VesselData::hasSpecialAttention() const {

    return m_specialAttentionPresent;
}

// setter for VesselData
void VesselData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
}

// getter for VesselData
QString VesselData::getSourceId() const {

    return m_sourceId;
}

// check if optional element VesselData has been set
bool VesselData::hasSourceId() const {

    return m_sourceIdPresent;
}

// setter for VesselData
void VesselData::setSourceName(QString val) {

    m_sourceName = val;
}

// getter for VesselData
QString VesselData::getSourceName() const {

    return m_sourceName;
}

// setter for VesselData
void VesselData::setSourceType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_sourceType = val;
}

// getter for VesselData
int VesselData::getSourceType() const {

    return m_sourceType;
}

// setter for VesselData
void VesselData::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

// getter for VesselData
QDateTime VesselData::getUpdateTime() const {

    return m_updateTime;
}

// Get XML Representation
QString VesselData::toXML() {

    QString xml = "<VesselData";
    // check for presence of optional attribute
    if ( hasClass() ) {
        xml.append(" Class=\"" + QString::number(m_class) + "\"");
    }
    // check for presence of optional attribute
    if ( hasBlackListed() ) {
        xml.append(" BlackListed=\"" + QString(m_blackListed ? "true" : "false" ) + "\"");
    }
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    // check for presence of optional attribute
    if ( hasSpecialAttention() ) {
        xml.append(" SpecialAttention=\"" + encode (m_specialAttention) + "\"");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        xml.append(" SourceId=\"" + encode (m_sourceId) + "\"");
    }
    xml.append(" SourceName=\"" + encode (m_sourceName) + "\"");
    xml.append(" SourceType=\"" + QString::number(m_sourceType) + "\"");
    xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(">\n");
    xml.append( m_construction.toXML() );
    xml.append( m_identifier.toXML() );
    xml.append( "</VesselData>\n");
    return xml;
}

// Get String Representation
QString VesselData::toString() {

    return toString("");
}

// Get String Representation with a lead
QString VesselData::toString(QString lead) {

    QString str = lead + "VesselData\n";
    // check for presence of optional attribute
    if ( hasClass() ) {
        str.append( lead + "    Class = " + QString::number(m_class) + "\n");
    }
    // check for presence of optional attribute
    if ( hasBlackListed() ) {
        str.append( lead + "    BlackListed = " + QString::number(m_blackListed) + "\n");
    }
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    // check for presence of optional attribute
    if ( hasSpecialAttention() ) {
        str.append( lead + "    SpecialAttention = " + m_specialAttention + "\n");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
    str.append( lead + "    SourceName = " + m_sourceName + "\n");
    str.append( lead + "    SourceType = " + QString::number(m_sourceType) + "\n");
    str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    str.append( m_construction.toString(lead + "    ") );
    str.append( m_identifier.toString(lead + "    ") );
    return str;
}

