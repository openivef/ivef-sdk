
#include "IVEFVesselData.h"

// Constructor
VesselData::VesselData() {

    m_constructionPresent = false;
    m_identifierPresent = false;
    m_class = 0;
    m_classPresent = false;
    // initialize defaults to false
    m_blackListed = false;
    m_blackListedPresent = false;
    m_id = 0;
    m_idPresent = false;
    // initialize empty string
    m_specialAttention = "";
    m_specialAttentionPresent = false;
    // initialize empty string
    m_sourceId = "";
    m_sourceIdPresent = false;
    // initialize empty string
    m_sourceName = "";
    m_sourceNamePresent = false;
    m_sourceType = 0;
    m_sourceTypePresent = false;
    // initialize with random value
    m_updateTime = QDateTime();
    m_updateTimePresent = false;
}

// copy constructor
VesselData::VesselData(const VesselData &val) : QObject() {

    m_constructionPresent = val.m_constructionPresent;
    m_construction = val.m_construction;
    m_identifierPresent = val.m_identifierPresent;
    m_identifier = val.m_identifier;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_blackListedPresent = val.m_blackListedPresent;
    m_blackListed = val.m_blackListed;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_specialAttentionPresent = val.m_specialAttentionPresent;
    m_specialAttention = val.m_specialAttention;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceTypePresent = val.m_sourceTypePresent;
    m_sourceType = val.m_sourceType;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
}

// assignement
VesselData & VesselData::operator=(const VesselData &val) {

    m_constructionPresent = val.m_constructionPresent;
    m_construction = val.m_construction;
    m_identifierPresent = val.m_identifierPresent;
    m_identifier = val.m_identifier;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_blackListedPresent = val.m_blackListedPresent;
    m_blackListed = val.m_blackListed;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_specialAttentionPresent = val.m_specialAttentionPresent;
    m_specialAttention = val.m_specialAttention;
    m_sourceIdPresent = val.m_sourceIdPresent;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceTypePresent = val.m_sourceTypePresent;
    m_sourceType = val.m_sourceType;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    return *this;
}

// String encoder
QString VesselData::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for VesselData
bool VesselData::setConstruction(Construction val) {

    m_constructionPresent = true;
    m_construction = val;
      return true;
}

// getter for VesselData
Construction VesselData::getConstruction() const {

    return m_construction;
}

// check if optional element VesselData has been set
bool VesselData::hasConstruction() const {

    return m_constructionPresent;
}

// setter for VesselData
bool VesselData::setIdentifier(Identifier val) {

    m_identifierPresent = true;
    m_identifier = val;
      return true;
}

// getter for VesselData
Identifier VesselData::getIdentifier() const {

    return m_identifier;
}

// check if optional element VesselData has been set
bool VesselData::hasIdentifier() const {

    return m_identifierPresent;
}

// setter for VesselData
bool VesselData::setClass(int val) {
// check if the new value is an approved value 

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_classPresent = true;
    m_class = val;
      return true;
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
bool VesselData::setBlackListed(bool val) {

    m_blackListedPresent = true;
    m_blackListed = val;
      return true;
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
bool VesselData::setId(int val) {

    m_idPresent = true;
    m_id = val;
      return true;
}

// getter for VesselData
int VesselData::getId() const {

    return m_id;
}

// setter for VesselData
bool VesselData::setSpecialAttention(QString val) {

    m_specialAttentionPresent = true;
    m_specialAttention = val;
      return true;
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
bool VesselData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
      return true;
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
bool VesselData::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
      return true;
}

// getter for VesselData
QString VesselData::getSourceName() const {

    return m_sourceName;
}

// setter for VesselData
bool VesselData::setSourceType(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_sourceTypePresent = true;
    m_sourceType = val;
      return true;
}

// getter for VesselData
int VesselData::getSourceType() const {

    return m_sourceType;
}

// setter for VesselData
bool VesselData::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
      return true;
}

// getter for VesselData
QDateTime VesselData::getUpdateTime() const {

    return m_updateTime;
}

// Get XML Representation
QString VesselData::toXML() const {

    QString xml = "<VesselData";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasClass() ) {
        xml.append(" Class=\"" + QString::number( m_class ) + "\"");
    }
    // check for presence of optional attribute
    if ( hasBlackListed() ) {
        xml.append(" BlackListed=\"" + QString( m_blackListed ? "true" : "false" ) + "\"");
    }
    // check for presence of required  attribute
    if ( m_idPresent) {
        xml.append(" Id=\"" + QString::number( m_id ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of optional attribute
    if ( hasSpecialAttention() ) {
        xml.append(" SpecialAttention=\"" + encode (m_specialAttention) + "\"");
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
    // check for presence of required  attribute
    if ( m_updateTimePresent) {
        xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append(">\n");
    // add optional data if available
    if ( hasConstruction() ) {
        dataMember = m_construction.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasIdentifier() ) {
        dataMember = m_identifier.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
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
        str.append( lead + "    Class = " + QString::number( m_class ) + "\n");
    }
    // check for presence of optional attribute
    if ( hasBlackListed() ) {
        str.append( lead + "    BlackListed = " + QString( m_blackListed ? "true" : "false" ) + "\n");
    }
     str.append( lead + "    Id = " + QString::number( m_id ) + "\n");
    // check for presence of optional attribute
    if ( hasSpecialAttention() ) {
        str.append( lead + "    SpecialAttention = " + m_specialAttention + "\n");
    }
    // check for presence of optional attribute
    if ( hasSourceId() ) {
        str.append( lead + "    SourceId = " + m_sourceId + "\n");
    }
     str.append( lead + "    SourceName = " + m_sourceName + "\n");
     str.append( lead + "    SourceType = " + QString::number( m_sourceType ) + "\n");
     str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    // add all optional data if present
    if ( hasConstruction() ) {
        str.append( m_construction.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasIdentifier() ) {
        str.append( m_identifier.toString(lead + "    ") );
    }
    return str;
}

