
#include "IVEFVesselData.h"

VesselData::VesselData() {

    m_class = 0;
    m_classPresent = false;
    m_blackListed = false;
    m_blackListedPresent = false;
    m_id = 0;
    m_specialAttention = "";
    m_specialAttentionPresent = false;
    m_sourceId = "";
    m_sourceIdPresent = false;
    m_sourceName = "";
    m_sourceType = 0;
    m_updateTime = QDateTime();
}

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

QString VesselData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void VesselData::setConstruction(Construction val) {

    m_construction = val;
}

Construction VesselData::getConstruction() const {

    return m_construction;
}

void VesselData::setIdentifier(Identifier val) {

    m_identifier = val;
}

Identifier VesselData::getIdentifier() const {

    return m_identifier;
}

void VesselData::setClass(int val) {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_classPresent = true;
    m_class = val;
}

int VesselData::getClass() const {

    return m_class;
}

bool VesselData::hasClass() {

    return m_classPresent;
}

void VesselData::setBlackListed(bool val) {

    m_blackListedPresent = true;
    m_blackListed = val;
}

bool VesselData::getBlackListed() const {

    return m_blackListed;
}

bool VesselData::hasBlackListed() {

    return m_blackListedPresent;
}

void VesselData::setId(int val) {

    m_id = val;
}

int VesselData::getId() const {

    return m_id;
}

void VesselData::setSpecialAttention(QString val) {

    m_specialAttentionPresent = true;
    m_specialAttention = val;
}

QString VesselData::getSpecialAttention() const {

    return m_specialAttention;
}

bool VesselData::hasSpecialAttention() {

    return m_specialAttentionPresent;
}

void VesselData::setSourceId(QString val) {

    m_sourceIdPresent = true;
    m_sourceId = val;
}

QString VesselData::getSourceId() const {

    return m_sourceId;
}

bool VesselData::hasSourceId() {

    return m_sourceIdPresent;
}

void VesselData::setSourceName(QString val) {

    m_sourceName = val;
}

QString VesselData::getSourceName() const {

    return m_sourceName;
}

void VesselData::setSourceType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_sourceType = val;
}

int VesselData::getSourceType() const {

    return m_sourceType;
}

void VesselData::setUpdateTime(QDateTime val) {

    m_updateTime = val;
}

QDateTime VesselData::getUpdateTime() const {

    return m_updateTime;
}

QString VesselData::toXML() {

    QString xml = "<VesselData";
    if ( hasClass() ) {
        xml.append(" Class=\"" + QString::number(m_class) + "\"");
    }
    if ( hasBlackListed() ) {
        xml.append(" BlackListed=\"" + QString(m_blackListed ? "yes" : "no" ) + "\"");
    }
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    if ( hasSpecialAttention() ) {
        xml.append(" SpecialAttention=\"" + encode (m_specialAttention) + "\"");
    }
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

QString VesselData::toString(QString lead) {

    QString str = lead + "VesselData\n";
    if ( hasClass() ) {
        str.append( lead + "    Class = " + QString::number(m_class) + "\n");
    }
    if ( hasBlackListed() ) {
        str.append( lead + "    BlackListed = " + QString::number(m_blackListed) + "\n");
    }
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    if ( hasSpecialAttention() ) {
        str.append( lead + "    SpecialAttention = " + m_specialAttention + "\n");
    }
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

