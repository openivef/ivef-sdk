
#include "IVEFVesselData.h"

VesselData::VesselData() {

    m_id = 0;
}

VesselData::VesselData(const VesselData &val) : QObject() {

    m_posReport = val.m_posReport;
    m_staticDatas = val.m_staticDatas;
    m_voyages = val.m_voyages;
    m_id = val.m_id;
}

VesselData & VesselData::operator=(const VesselData &val) {

    m_posReport = val.m_posReport;
    m_staticDatas = val.m_staticDatas;
    m_voyages = val.m_voyages;
    m_id = val.m_id;
    return *this;
}

QString VesselData::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void VesselData::setPosReport(PosReport val) {

    m_posReport = val;
}

PosReport VesselData::getPosReport() const {

    return m_posReport;
}

void VesselData::addStaticData(StaticData val) {

    m_staticDatas.append(val);
}

StaticData VesselData::getStaticDataAt(int i) const {

    return m_staticDatas.at(i);
}

int VesselData::countOfStaticDatas() const {

    return m_staticDatas.count();
}

void VesselData::addVoyage(Voyage val) {

    m_voyages.append(val);
}

Voyage VesselData::getVoyageAt(int i) const {

    return m_voyages.at(i);
}

int VesselData::countOfVoyages() const {

    return m_voyages.count();
}

void VesselData::setId(int val) {

    m_id = val;
}

int VesselData::getId() const {

    return m_id;
}

QString VesselData::toXML() {

    QString xml = "<VesselData";
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
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
    xml.append( "</VesselData>\n");
    return xml;
}

QString VesselData::toString(QString lead) {

    QString str = lead + "VesselData\n";
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    str.append( m_posReport.toString(lead + "    ") );
    for(int i=0; i < m_staticDatas.count(); i++ ) {
       StaticData attribute = m_staticDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_voyages.count(); i++ ) {
       Voyage attribute = m_voyages.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

