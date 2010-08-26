
#include "IVEFObjectData.h"

// Constructor
ObjectData::ObjectData() {

    m_trackDataPresent = false;
}

// copy constructor
ObjectData::ObjectData(const ObjectData &val) : QObject() {

    m_trackDataPresent = val.m_trackDataPresent;
    m_trackData = val.m_trackData;
    m_vesselDataPresent = val.m_vesselDataPresent;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDataPresent = val.m_voyageDataPresent;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItemPresent = val.m_taggedItemPresent;
    m_taggedItems = val.m_taggedItems;
}

// compare
bool ObjectData::operator==(const ObjectData &val) {

    if (!(m_trackDataPresent == val.m_trackDataPresent)) return false;
    if (!(m_trackData == val.m_trackData)) return false;
    if (!(m_vesselDataPresent == val.m_vesselDataPresent)) return false;
    if (!(m_vesselDatas == val.m_vesselDatas)) return false;
    if (!(m_voyageDataPresent == val.m_voyageDataPresent)) return false;
    if (!(m_voyageDatas == val.m_voyageDatas)) return false;
    if (!(m_taggedItemPresent == val.m_taggedItemPresent)) return false;
    if (!(m_taggedItems == val.m_taggedItems)) return false;
    return true;
}

// assignement
ObjectData & ObjectData::operator=(const ObjectData &val) {

    m_trackDataPresent = val.m_trackDataPresent;
    m_trackData = val.m_trackData;
    m_vesselDataPresent = val.m_vesselDataPresent;
    m_vesselDatas = val.m_vesselDatas;
    m_voyageDataPresent = val.m_voyageDataPresent;
    m_voyageDatas = val.m_voyageDatas;
    m_taggedItemPresent = val.m_taggedItemPresent;
    m_taggedItems = val.m_taggedItems;
    return *this;
}

// String encoder
QString ObjectData::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ObjectData
bool ObjectData::setTrackData(TrackData val) {

    m_trackDataPresent = true;
    m_trackData = val;
      return true;
}

// getter for ObjectData
TrackData ObjectData::getTrackData() const {

    return m_trackData;
}

// check if optional element ObjectData has been set
bool ObjectData::hasTrackData() const {

    return m_trackDataPresent;
}

// remover for ObjectData
bool ObjectData::removeVesselData(VesselData val) {

    if (m_vesselDatas.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    return m_vesselDatas.removeOne(val);
}

// setter for ObjectData
bool ObjectData::addVesselData(VesselData val) {

   m_vesselDatas.append(val);
      return true;
}

// getter for ObjectData
VesselData ObjectData::getVesselDataAt(int i) const {

    return m_vesselDatas.at(i);
}

// count for ObjectData
int ObjectData::countOfVesselDatas() const {

    return m_vesselDatas.count();
}

// remover for ObjectData
bool ObjectData::removeVoyageData(VoyageData val) {

    if (m_voyageDatas.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    return m_voyageDatas.removeOne(val);
}

// setter for ObjectData
bool ObjectData::addVoyageData(VoyageData val) {

   m_voyageDatas.append(val);
      return true;
}

// getter for ObjectData
VoyageData ObjectData::getVoyageDataAt(int i) const {

    return m_voyageDatas.at(i);
}

// count for ObjectData
int ObjectData::countOfVoyageDatas() const {

    return m_voyageDatas.count();
}

// remover for ObjectData
bool ObjectData::removeTaggedItem(TaggedItem val) {

    if (m_taggedItems.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    return m_taggedItems.removeOne(val);
}

// setter for ObjectData
bool ObjectData::addTaggedItem(TaggedItem val) {

   m_taggedItems.append(val);
      return true;
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
QString ObjectData::toXML() const {

    QString xml = "<ObjectData";
    QString dataMember;
    xml.append(">\n");
    // add optional data if available
    if ( hasTrackData() ) {
        dataMember = m_trackData.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    if (m_vesselDatas.count() < 0) {
        return NULL; // not enough values
    }
    // add all included data
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
        VesselData attribute = m_vesselDatas.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
    }
    if (m_voyageDatas.count() < 0) {
        return NULL; // not enough values
    }
    // add all included data
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
        VoyageData attribute = m_voyageDatas.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
    }
    if (m_taggedItems.count() < 0) {
        return NULL; // not enough values
    }
    // add all included data
    for(int i=0; i < m_taggedItems.count(); i++ ) {
        TaggedItem attribute = m_taggedItems.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
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
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_voyageDatas.count(); i++ ) {
        VoyageData attribute = m_voyageDatas.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_taggedItems.count(); i++ ) {
        TaggedItem attribute = m_taggedItems.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

