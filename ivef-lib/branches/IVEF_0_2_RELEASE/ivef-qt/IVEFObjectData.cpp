
#include "IVEFObjectData.h"

ObjectData::ObjectData() {

}

ObjectData::ObjectData(const ObjectData &val) : QObject() {

    m_trackData = val.m_trackData;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItems = val.m_taggedItems;
}

ObjectData & ObjectData::operator=(const ObjectData &val) {

    m_trackData = val.m_trackData;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItems = val.m_taggedItems;
    return *this;
}

QString ObjectData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void ObjectData::setTrackData(TrackData val) {

    m_trackData = val;
}

TrackData ObjectData::getTrackData() const {

    return m_trackData;
}

void ObjectData::addVesselData(VesselData val) {

    m_vesselDatas.append(val);
}

VesselData ObjectData::getVesselDataAt(int i) const {

    return m_vesselDatas.at(i);
}

int ObjectData::countOfVesselDatas() const {

    return m_vesselDatas.count();
}

void ObjectData::addVoyageData(VoyageData val) {

    m_voyageDatas.append(val);
}

VoyageData ObjectData::getVoyageDataAt(int i) const {

    return m_voyageDatas.at(i);
}

int ObjectData::countOfVoyageDatas() const {

    return m_voyageDatas.count();
}

void ObjectData::addTaggedItem(TaggedItem val) {

    m_taggedItems.append(val);
}

TaggedItem ObjectData::getTaggedItemAt(int i) const {

    return m_taggedItems.at(i);
}

int ObjectData::countOfTaggedItems() const {

    return m_taggedItems.count();
}

QString ObjectData::toXML() {

    QString xml = "<ObjectData";
    xml.append(">\n");
    xml.append( m_trackData.toXML() );
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
        VesselData attribute = m_vesselDatas.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
        VoyageData attribute = m_voyageDatas.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_taggedItems.count(); i++ ) {
        TaggedItem attribute = m_taggedItems.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</ObjectData>\n");
    return xml;
}

QString ObjectData::toString(QString lead) {

    QString str = lead + "ObjectData\n";
    str.append( m_trackData.toString(lead + "    ") );
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
       VesselData attribute = m_vesselDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
       VoyageData attribute = m_voyageDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_taggedItems.count(); i++ ) {
       TaggedItem attribute = m_taggedItems.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

