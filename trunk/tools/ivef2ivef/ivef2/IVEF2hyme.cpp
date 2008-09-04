
#include "IVEF2hyme.h"

HyMe::HyMe() {

}

HyMe::HyMe(const HyMe &val) : QObject() {

    m_stations = val.m_stations;
}

HyMe & HyMe::operator=(const HyMe &val) {

    m_stations = val.m_stations;
    return *this;
}

void HyMe::addStation(Station val) {

    m_stations.append(val);
}

Station HyMe::getStationAt(int i) const {

    return m_stations.at(i);
}

int HyMe::countOfStations() const {

    return m_stations.count();
}

QString HyMe::toXML() {

    QString xml = "<HyMe";
    xml.append(">\n");
    for(int i=0; i < m_stations.count(); i++ ) {
       Station attribute = m_stations.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</HyMe>\n");
    return xml;
}

QString HyMe::toString(QString lead) {

    QString str = lead + "HyMe\n";
    for(int i=0; i < m_stations.count(); i++ ) {
       Station attribute = m_stations.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

