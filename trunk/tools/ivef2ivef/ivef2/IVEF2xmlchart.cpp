
#include "IVEF2xmlchart.h"

XMLChart::XMLChart() {

}

XMLChart::XMLChart(const XMLChart &val) : QObject() {

    m_areas = val.m_areas;
    m_name = val.m_name;
}

XMLChart & XMLChart::operator=(const XMLChart &val) {

    m_areas = val.m_areas;
    m_name = val.m_name;
    return *this;
}

void XMLChart::addArea(Area val) {

    m_areas.append(val);
}

Area XMLChart::getAreaAt(int i) const {

    return m_areas.at(i);
}

int XMLChart::countOfAreas() const {

    return m_areas.count();
}

void XMLChart::setName(QString val) {

    m_name = val;
}

QString XMLChart::getName() const {

    return m_name;
}

QString XMLChart::toXML() {

    QString xml = "<XMLChart";
    xml.append(" Name=\"" + m_name + "\"");
    xml.append(">\n");
    for(int i=0; i < m_areas.count(); i++ ) {
       Area attribute = m_areas.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</XMLChart>\n");
    return xml;
}

QString XMLChart::toString(QString lead) {

    QString str = lead + "XMLChart\n";
    str.append( lead + "    Name = " + m_name + "\n");
    for(int i=0; i < m_areas.count(); i++ ) {
       Area attribute = m_areas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

