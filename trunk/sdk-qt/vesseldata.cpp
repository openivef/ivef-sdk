
#include "vesseldata.h"

VesselData::VesselData() {

}

VesselData::VesselData(const VesselData &val) : QObject() {

    m_posReport = ((VesselData)val).getPosReport();
    for(int i=0; i < ((VesselData)val).countOfStaticDatas(); i++) { 
        m_staticDatas.append( ((VesselData)val).getStaticDataAt(i) );
    }
    for(int i=0; i < ((VesselData)val).countOfVoyages(); i++) { 
        m_voyages.append( ((VesselData)val).getVoyageAt(i) );
    }
}

VesselData & VesselData::operator=(const VesselData &/*val*/) {

    return *this;
}

void VesselData::setPosReport(PosReport val) {

    m_posReport = val;
}

PosReport VesselData::getPosReport() {

    return m_posReport;
}

void VesselData::addStaticData(StaticData val) {

    m_staticDatas.append(val);
}

StaticData VesselData::getStaticDataAt(int i) {

    return m_staticDatas.at(i);
}

int VesselData::countOfStaticDatas() {

    return m_staticDatas.count();
}

void VesselData::addVoyage(Voyage val) {

    m_voyages.append(val);
}

Voyage VesselData::getVoyageAt(int i) {

    return m_voyages.at(i);
}

int VesselData::countOfVoyages() {

    return m_voyages.count();
}

QString VesselData::toXML() {

    QString xml = "<VesselData";
    xml.append(">\n");
    xml.append( m_posReport.toXML() );
    for(int i=0; i < m_staticDatas.count(); i++ ) {
       StaticData attribute = m_staticDatas.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_voyages.count(); i++ ) {
       Voyage attribute = m_voyages.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "<VesselData />\n");
    return xml;
}

