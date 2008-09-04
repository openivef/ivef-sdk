
#include "IVEF2staticdata.h"

StaticData::StaticData() {

    m_sourceNamePresent = false;
    m_classPresent = false;
    m_updateTimePresent = false;
}

StaticData::StaticData(const StaticData &val) : QObject() {

    m_identifier = val.m_identifier;
    m_taggedItemss = val.m_taggedItemss;
    m_construction = val.m_construction;
    m_propulsions = val.m_propulsions;
    m_owner = val.m_owner;
    m_id = val.m_id;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceType = val.m_sourceType;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
}

StaticData & StaticData::operator=(const StaticData &val) {

    m_identifier = val.m_identifier;
    m_taggedItemss = val.m_taggedItemss;
    m_construction = val.m_construction;
    m_propulsions = val.m_propulsions;
    m_owner = val.m_owner;
    m_id = val.m_id;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_sourceType = val.m_sourceType;
    m_classPresent = val.m_classPresent;
    m_class = val.m_class;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    return *this;
}

void StaticData::setIdentifier(Identifier val) {

    m_identifier = val;
}

Identifier StaticData::getIdentifier() const {

    return m_identifier;
}

void StaticData::addTaggedItems(TaggedItems val) {

    m_taggedItemss.append(val);
}

TaggedItems StaticData::getTaggedItemsAt(int i) const {

    return m_taggedItemss.at(i);
}

int StaticData::countOfTaggedItemss() const {

    return m_taggedItemss.count();
}

void StaticData::setConstruction(Construction val) {

    m_construction = val;
}

Construction StaticData::getConstruction() const {

    return m_construction;
}

void StaticData::addPropulsion(Propulsion val) {

    m_propulsions.append(val);
}

Propulsion StaticData::getPropulsionAt(int i) const {

    return m_propulsions.at(i);
}

int StaticData::countOfPropulsions() const {

    return m_propulsions.count();
}

void StaticData::setOwner(Owner val) {

    m_owner = val;
}

Owner StaticData::getOwner() const {

    return m_owner;
}

void StaticData::setId(int val) {

    m_id = val;
}

int StaticData::getId() const {

    return m_id;
}

void StaticData::setSourceId(int val) {

    m_sourceId = val;
}

int StaticData::getSourceId() const {

    return m_sourceId;
}

void StaticData::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
}

QString StaticData::getSourceName() const {

    return m_sourceName;
}

bool StaticData::hasSourceName() {

    return m_sourceNamePresent;
}

void StaticData::setSourceType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_sourceType = val;
}

int StaticData::getSourceType() const {

    return m_sourceType;
}

void StaticData::setClass(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) )
        return;
    m_classPresent = true;
    m_class = val;
}

int StaticData::getClass() const {

    return m_class;
}

bool StaticData::hasClass() {

    return m_classPresent;
}

void StaticData::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
}

QDateTime StaticData::getUpdateTime() const {

    return m_updateTime;
}

bool StaticData::hasUpdateTime() {

    return m_updateTimePresent;
}

QString StaticData::toXML() {

    QString xml = "<StaticData";
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    if ( hasSourceName() ) {
        xml.append(" SourceName=\"" + m_sourceName + "\"");
    }
    xml.append(" SourceType=\"" + QString::number(m_sourceType) + "\"");
    if ( hasClass() ) {
        xml.append(" Class=\"" + QString::number(m_class) + "\"");
    }
    if ( hasUpdateTime() ) {
        xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    }
    xml.append(">\n");
    xml.append( m_identifier.toXML() );
    for(int i=0; i < m_taggedItemss.count(); i++ ) {
       TaggedItems attribute = m_taggedItemss.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( m_construction.toXML() );
    for(int i=0; i < m_propulsions.count(); i++ ) {
       Propulsion attribute = m_propulsions.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( m_owner.toXML() );
    xml.append( "</StaticData>\n");
    return xml;
}

QString StaticData::toString(QString lead) {

    QString str = lead + "StaticData\n";
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    if ( hasSourceName() ) {
        str.append( lead + "    SourceName = " + m_sourceName + "\n");
    }
    str.append( lead + "    SourceType = " + QString::number(m_sourceType) + "\n");
    if ( hasClass() ) {
        str.append( lead + "    Class = " + QString::number(m_class) + "\n");
    }
    if ( hasUpdateTime() ) {
        str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    }
    str.append( m_identifier.toString(lead + "    ") );
    for(int i=0; i < m_taggedItemss.count(); i++ ) {
       TaggedItems attribute = m_taggedItemss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    str.append( m_construction.toString(lead + "    ") );
    for(int i=0; i < m_propulsions.count(); i++ ) {
       Propulsion attribute = m_propulsions.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    str.append( m_owner.toString(lead + "    ") );
    return str;
}

