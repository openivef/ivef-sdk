
#include "IVEF2objectdata.h"

ObjectData::ObjectData() {

}

ObjectData::ObjectData(const ObjectData &val) : QObject() {

    m_posReports = val.m_posReports;
    m_staticDatas = val.m_staticDatas;
    m_voyages = val.m_voyages;
    m_id = val.m_id;
}

ObjectData & ObjectData::operator=(const ObjectData &val) {

    m_posReports = val.m_posReports;
    m_staticDatas = val.m_staticDatas;
    m_voyages = val.m_voyages;
    m_id = val.m_id;
    return *this;
}

void ObjectData::addPosReport(PosReport val) {

    m_posReports.append(val);
}

PosReport ObjectData::getPosReportAt(int i) const {

    return m_posReports.at(i);
}

int ObjectData::countOfPosReports() const {

    return m_posReports.count();
}

void ObjectData::addStaticData(StaticData val) {

    m_staticDatas.append(val);
}

StaticData ObjectData::getStaticDataAt(int i) const {

    return m_staticDatas.at(i);
}

int ObjectData::countOfStaticDatas() const {

    return m_staticDatas.count();
}

void ObjectData::addVoyage(Voyage val) {

    m_voyages.append(val);
}

Voyage ObjectData::getVoyageAt(int i) const {

    return m_voyages.at(i);
}

int ObjectData::countOfVoyages() const {

    return m_voyages.count();
}

void ObjectData::setId(int val) {

    m_id = val;
}

int ObjectData::getId() const {

    return m_id;
}

QString ObjectData::toXML() {

    QString xml = "<ObjectData";
    xml.append(" Id=\"" + QString::number(m_id) + "\"");
    xml.append(">\n");
    for(int i=0; i < m_posReports.count(); i++ ) {
       PosReport attribute = m_posReports.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_staticDatas.count(); i++ ) {
       StaticData attribute = m_staticDatas.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_voyages.count(); i++ ) {
       Voyage attribute = m_voyages.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</ObjectData>\n");
    return xml;
}

QString ObjectData::toString(QString lead) {

    QString str = lead + "ObjectData\n";
    str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    for(int i=0; i < m_posReports.count(); i++ ) {
       PosReport attribute = m_posReports.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
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

