
#include "IVEF2s57chart.h"

S57Chart::S57Chart() {

}

S57Chart::S57Chart(const S57Chart &val) : QObject() {

    m_name = val.m_name;
    m_baseChart = val.m_baseChart;
    m_data = val.m_data;
}

S57Chart & S57Chart::operator=(const S57Chart &val) {

    m_name = val.m_name;
    m_baseChart = val.m_baseChart;
    m_data = val.m_data;
    return *this;
}

void S57Chart::setName(QString val) {

    m_name = val;
}

QString S57Chart::getName() const {

    return m_name;
}

void S57Chart::setBaseChart(bool val) {

    m_baseChart = val;
}

bool S57Chart::getBaseChart() const {

    return m_baseChart;
}

void S57Chart::setData(xs:hexBinary val) {

    m_data = val;
}

xs:hexBinary S57Chart::getData() const {

    return m_data;
}

QString S57Chart::toXML() {

    QString xml = "<S57Chart";
    xml.append(" Name=\"" + m_name + "\"");
    xml.append(" BaseChart=\"" + QString::number(m_baseChart) + "\"");
    xml.append(" Data=\"" + QString::number(m_data) + "\"");
    xml.append(">\n");
    xml.append( "</S57Chart>\n");
    return xml;
}

QString S57Chart::toString(QString lead) {

    QString str = lead + "S57Chart\n";
    str.append( lead + "    Name = " + m_name + "\n");
    str.append( lead + "    BaseChart = " + QString::number(m_baseChart) + "\n");
    str.append( lead + "    Data = " + QString::number(m_data) + "\n");
    return str;
}

