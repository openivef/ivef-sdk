
#include "IVEFObjectData.h"

// Constructor
ObjectData::ObjectData() {

    // optional attributes are by default not present
    m_trackDataPresent = false;
}

// copy constructor
ObjectData::ObjectData(const ObjectData &val) : QObject() {

    m_trackDataPresent = val.m_trackDataPresent;
    m_trackData = val.m_trackData;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItems = val.m_taggedItems;
}

// assignement
ObjectData & ObjectData::operator=(const ObjectData &val) {

    m_trackDataPresent = val.m_trackDataPresent;
    m_trackData = val.m_trackData;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItems = val.m_taggedItems;
    return *this;
}

// String encoder
QString ObjectData::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ObjectData
void ObjectData::setTrackData(TrackData val) {

    m_trackDataPresent = true;
    m_trackData = val;
}

// getter for ObjectData
TrackData ObjectData::getTrackData() const {

    return m_trackData;
}

// check if optional element ObjectData has been set
bool ObjectData::hasTrackData() const {

    return m_trackDataPresent;
}

// setter for ObjectData
void ObjectData::addVesselData(VesselData val) {

    m_vesselDatas.append(val);
}

// getter for ObjectData
VesselData ObjectData::getVesselDataAt(int i) const {

    return m_vesselDatas.at(i);
}

// count for ObjectData
int ObjectData::countOfVesselDatas() const {

    return m_vesselDatas.count();
}

// setter for ObjectData
void ObjectData::addVoyageData(VoyageData val) {

    m_voyageDatas.append(val);
}

// getter for ObjectData
VoyageData ObjectData::getVoyageDataAt(int i) const {

    return m_voyageDatas.at(i);
}

// count for ObjectData
int ObjectData::countOfVoyageDatas() const {

    return m_voyageDatas.count();
}

// setter for ObjectData
void ObjectData::addTaggedItem(TaggedItem val) {

    m_taggedItems.append(val);
}

// getter for ObjectData
TaggedItem ObjectData::getTaggedItemAt(int i) const {

    return m_taggedItems.at(i);
}

// count for ObjectData
int ObjectData::countOfTaggedItems() const {

    return m_taggedItems.count();
}

// Get XML Representation
QString ObjectData::toXML() {

    QString xml = "<ObjectData";
    xml.append(">\n");
    // add optional data if available
    if ( hasTrackData() ) {
        xml.append( m_trackData.toXML() );
    }
    // add all included data
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
        VesselData attribute = m_vesselDatas.at(i);
        xml.append( attribute.toXML() );
    }
    // add all included data
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
        VoyageData attribute = m_voyageDatas.at(i);
        xml.append( attribute.toXML() );
    }
    // add all included data
    for(int i=0; i < m_taggedItems.count(); i++ ) {
        TaggedItem attribute = m_taggedItems.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</ObjectData>\n");
    return xml;
}

// Get String Representation
QString ObjectData::toString() {

    return toString("");
}

// Get String Representation with a lead
QString ObjectData::toString(QString lead) {

    QString str = lead + "ObjectData\n";
    // add all optional data if present
    if ( hasTrackData() ) {
        str.append( m_trackData.toString(lead + "    ") );
    }
    // add all included data
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
       VesselData attribute = m_vesselDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    // add all included data
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
       VoyageData attribute = m_voyageDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    // add all included data
    for(int i=0; i < m_taggedItems.count(); i++ ) {
       TaggedItem attribute = m_taggedItems.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

