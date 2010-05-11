
#include "IVEFServiceRequest.h"

// Constructor
ServiceRequest::ServiceRequest() {

    m_transmissionPresent = false;
}

// copy constructor
ServiceRequest::ServiceRequest(const ServiceRequest &val) : QObject() {

    m_areaPresent = val.m_areaPresent;
    m_areas = val.m_areas;
    m_transmissionPresent = val.m_transmissionPresent;
    m_transmission = val.m_transmission;
    m_itemPresent = val.m_itemPresent;
    m_items = val.m_items;
    m_objectPresent = val.m_objectPresent;
    m_objects = val.m_objects;
}

// assignement
ServiceRequest & ServiceRequest::operator=(const ServiceRequest &val) {

    m_areaPresent = val.m_areaPresent;
    m_areas = val.m_areas;
    m_transmissionPresent = val.m_transmissionPresent;
    m_transmission = val.m_transmission;
    m_itemPresent = val.m_itemPresent;
    m_items = val.m_items;
    m_objectPresent = val.m_objectPresent;
    m_objects = val.m_objects;
    return *this;
}

// String encoder
QString ServiceRequest::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ServiceRequest
bool ServiceRequest::addArea(Area val) {

   m_areas.append(val);
      return true;
}

// getter for ServiceRequest
Area ServiceRequest::getAreaAt(int i) const {

    return m_areas.at(i);
}

// count for ServiceRequest
int ServiceRequest::countOfAreas() const {

    return m_areas.count();
}

// setter for ServiceRequest
bool ServiceRequest::setTransmission(Transmission val) {

    m_transmissionPresent = true;
    m_transmission = val;
      return true;
}

// getter for ServiceRequest
Transmission ServiceRequest::getTransmission() const {

    return m_transmission;
}

// setter for ServiceRequest
bool ServiceRequest::addItem(Item val) {

   m_items.append(val);
      return true;
}

// getter for ServiceRequest
Item ServiceRequest::getItemAt(int i) const {

    return m_items.at(i);
}

// count for ServiceRequest
int ServiceRequest::countOfItems() const {

    return m_items.count();
}

// setter for ServiceRequest
bool ServiceRequest::addObject(Object val) {

   m_objects.append(val);
      return true;
}

// getter for ServiceRequest
Object ServiceRequest::getObjectAt(int i) const {

    return m_objects.at(i);
}

// count for ServiceRequest
int ServiceRequest::countOfObjects() const {

    return m_objects.count();
}

// Get XML Representation
QString ServiceRequest::toXML() const {

    QString xml = "<ServiceRequest";
    QString dataMember;
    xml.append(">\n");
    if (m_areas.count() < 0) {
        return NULL; // not enough values
    }
    // add all included data
    for(int i=0; i < m_areas.count(); i++ ) {
        Area attribute = m_areas.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
    }
    // check for presence of required data member
    if ( m_transmissionPresent) {
        dataMember = m_transmission.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
    // add all included data
    for(int i=0; i < m_items.count(); i++ ) {
        Item attribute = m_items.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
    }
    // add all included data
    for(int i=0; i < m_objects.count(); i++ ) {
        Object attribute = m_objects.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
    }
    xml.append( "</ServiceRequest>\n");
    return xml;
}

// Get String Representation
QString ServiceRequest::toString() {

    return toString("");
}

// Get String Representation with a lead
QString ServiceRequest::toString(QString lead) {

    QString str = lead + "ServiceRequest\n";
    // add all included data
    for(int i=0; i < m_areas.count(); i++ ) {
        Area attribute = m_areas.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    str.append( m_transmission.toString(lead + "    ") );
    // add all included data
    for(int i=0; i < m_items.count(); i++ ) {
        Item attribute = m_items.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_objects.count(); i++ ) {
        Object attribute = m_objects.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

