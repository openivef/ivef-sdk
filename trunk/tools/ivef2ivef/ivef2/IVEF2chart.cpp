
#include "IVEF2chart.h"

Chart::Chart() {

}

Chart::Chart(const Chart &val) : QObject() {

    m_S57Charts = val.m_S57Charts;
    m_XMLCharts = val.m_XMLCharts;
}

Chart & Chart::operator=(const Chart &val) {

    m_S57Charts = val.m_S57Charts;
    m_XMLCharts = val.m_XMLCharts;
    return *this;
}

void Chart::addS57Chart(S57Chart val) {

    m_S57Charts.append(val);
}

S57Chart Chart::getS57ChartAt(int i) const {

    return m_S57Charts.at(i);
}

int Chart::countOfS57Charts() const {

    return m_S57Charts.count();
}

void Chart::addXMLChart(XMLChart val) {

    m_XMLCharts.append(val);
}

XMLChart Chart::getXMLChartAt(int i) const {

    return m_XMLCharts.at(i);
}

int Chart::countOfXMLCharts() const {

    return m_XMLCharts.count();
}

QString Chart::toXML() {

    QString xml = "<Chart";
    xml.append(">\n");
    for(int i=0; i < m_S57Charts.count(); i++ ) {
       S57Chart attribute = m_S57Charts.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_XMLCharts.count(); i++ ) {
       XMLChart attribute = m_XMLCharts.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</Chart>\n");
    return xml;
}

QString Chart::toString(QString lead) {

    QString str = lead + "Chart\n";
    for(int i=0; i < m_S57Charts.count(); i++ ) {
       S57Chart attribute = m_S57Charts.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_XMLCharts.count(); i++ ) {
       XMLChart attribute = m_XMLCharts.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

