
#include "IVEFServiceRequest.h"

// Constructor
ServiceRequest::ServiceRequest() {

}

// copy constructor
ServiceRequest::ServiceRequest(const ServiceRequest &val) : QObject() {

    m_areas = val.m_areas;
    m_transmission = val.m_transmission;
    m_items = val.m_items;
    m_objects = val.m_objects;
}

// comperator
ServiceRequest & ServiceRequest::operator=(const ServiceRequest &val) {

    m_areas = val.m_areas;
    m_transmission = val.m_transmission;
    m_items = val.m_items;
    m_objects = val.m_objects;
    return *this;
}

// String encoder
QString ServiceRequest::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ServiceRequest
void ServiceRequest::addArea(Area val) {

    m_areas.append(val);
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
void ServiceRequest::setTransmission(Transmission val) {

    m_transmission = val;
}

// getter for ServiceRequest
Transmission ServiceRequest::getTransmission() const {

    return m_transmission;
}

// setter for ServiceRequest
void ServiceRequest::addItem(Item val) {

    m_items.append(val);
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
void ServiceRequest::addObject(Object val) {

    m_objects.append(val);
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
QString ServiceRequest::toXML() {

    QString xml = "<ServiceRequest";
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_areas.count(); i++ ) {
        Area attribute = m_areas.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( m_transmission.toXML() );
    // add all included data
    for(int i=0; i < m_items.count(); i++ ) {
        Item attribute = m_items.at(i);
        xml.append( attribute.toXML() );
    }
    // add all included data
    for(int i=0; i < m_objects.count(); i++ ) {
        Object attribute = m_objects.at(i);
        xml.append( attribute.toXML() );
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
       str.append( attribute.toString(lead + "    ") );
    }
    str.append( m_transmission.toString(lead + "    ") );
    // add all included data
    for(int i=0; i < m_items.count(); i++ ) {
       Item attribute = m_items.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    // add all included data
    for(int i=0; i < m_objects.count(); i++ ) {
       Object attribute = m_objects.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

