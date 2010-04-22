
#include "IVEFServiceRequest.h"

// Constructor
ServiceRequest::ServiceRequest() {

    // optional attributes are by default not present
    m_filterPresent = false;
}

// copy constructor
ServiceRequest::ServiceRequest(const ServiceRequest &val) : QObject() {

    m_areas = val.m_areas;
    m_transmission = val.m_transmission;
    m_items = val.m_items;
    m_filterPresent = val.m_filterPresent;
    m_filter = val.m_filter;
}

// assignement
ServiceRequest & ServiceRequest::operator=(const ServiceRequest &val) {

    m_areas = val.m_areas;
    m_transmission = val.m_transmission;
    m_items = val.m_items;
    m_filterPresent = val.m_filterPresent;
    m_filter = val.m_filter;
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
void ServiceRequest::setFilter(Filter val) {

    m_filterPresent = true;
    m_filter = val;
}

// getter for ServiceRequest
Filter ServiceRequest::getFilter() const {

    return m_filter;
}

// check if optional element ServiceRequest has been set
bool ServiceRequest::hasFilter() const {

    return m_filterPresent;
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
    // add optional data if available
    if ( hasFilter() ) {
        xml.append( m_filter.toXML() );
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
    // add all optional data if present
    if ( hasFilter() ) {
        str.append( m_filter.toString(lead + "    ") );
    }
    return str;
}

