
#include "servicerequest.h"

ServiceRequest::ServiceRequest() {

}

ServiceRequest::ServiceRequest(const ServiceRequest &val) : QObject() {

    for(int i=0; i < val.countOfAreas(); i++) { 
        m_areas.append( val.getAreaAt(i) );
    }
    m_transmission = val.getTransmission();
    for(int i=0; i < val.countOfItems(); i++) { 
        m_items.append( val.getItemAt(i) );
    }
    for(int i=0; i < val.countOfObjects(); i++) { 
        m_objects.append( val.getObjectAt(i) );
    }
}

ServiceRequest & ServiceRequest::operator=(const ServiceRequest &/*val*/) {

    return *this;
}

void ServiceRequest::addArea(Area val) {

    m_areas.append(val);
}

Area ServiceRequest::getAreaAt(int i) const {

    return m_areas.at(i);
}

int ServiceRequest::countOfAreas() const {

    return m_areas.count();
}

void ServiceRequest::setTransmission(Transmission val) {

    m_transmission = val;
}

Transmission ServiceRequest::getTransmission() const {

    return m_transmission;
}

void ServiceRequest::addItem(Item val) {

    m_items.append(val);
}

Item ServiceRequest::getItemAt(int i) const {

    return m_items.at(i);
}

int ServiceRequest::countOfItems() const {

    return m_items.count();
}

void ServiceRequest::addObject(Object val) {

    m_objects.append(val);
}

Object ServiceRequest::getObjectAt(int i) const {

    return m_objects.at(i);
}

int ServiceRequest::countOfObjects() const {

    return m_objects.count();
}

QString ServiceRequest::toXML() {

    QString xml = "<ServiceRequest";
    xml.append(">\n");
    for(int i=0; i < m_areas.count(); i++ ) {
       Area attribute = m_areas.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( m_transmission.toXML() );
    for(int i=0; i < m_items.count(); i++ ) {
       Item attribute = m_items.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_objects.count(); i++ ) {
       Object attribute = m_objects.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "<ServiceRequest />\n");
    return xml;
}

