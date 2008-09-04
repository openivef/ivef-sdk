
#include "IVEF2station.h"

Station::Station() {

    m_idPresent = false;
    m_namePresent = false;
    m_locationPresent = false;
}

Station::Station(const Station &val) : QObject() {

    m_readings = val.m_readings;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_forecast = val.m_forecast;
    m_timeStamp = val.m_timeStamp;
    m_locationPresent = val.m_locationPresent;
    m_location = val.m_location;
}

Station & Station::operator=(const Station &val) {

    m_readings = val.m_readings;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_forecast = val.m_forecast;
    m_timeStamp = val.m_timeStamp;
    m_locationPresent = val.m_locationPresent;
    m_location = val.m_location;
    return *this;
}

void Station::addReading(Reading val) {

    m_readings.append(val);
}

Reading Station::getReadingAt(int i) const {

    return m_readings.at(i);
}

int Station::countOfReadings() const {

    return m_readings.count();
}

void Station::setId(int val) {

    m_idPresent = true;
    m_id = val;
}

int Station::getId() const {

    return m_id;
}

bool Station::hasId() {

    return m_idPresent;
}

void Station::setName(QString val) {

    m_namePresent = true;
    m_name = val;
}

QString Station::getName() const {

    return m_name;
}

bool Station::hasName() {

    return m_namePresent;
}

void Station::setForecast(bool val) {

    m_forecast = val;
}

bool Station::getForecast() const {

    return m_forecast;
}

void Station::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

QDateTime Station::getTimeStamp() const {

    return m_timeStamp;
}

void Station::setLocation(QString val) {

    m_locationPresent = true;
    m_location = val;
}

QString Station::getLocation() const {

    return m_location;
}

bool Station::hasLocation() {

    return m_locationPresent;
}

QString Station::toXML() {

    QString xml = "<Station";
    if ( hasId() ) {
        xml.append(" Id=\"" + QString::number(m_id) + "\"");
    }
    if ( hasName() ) {
        xml.append(" Name=\"" + m_name + "\"");
    }
    xml.append(" Forecast=\"" + QString::number(m_forecast) + "\"");
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    if ( hasLocation() ) {
        xml.append(" Location=\"" + m_location + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_readings.count(); i++ ) {
       Reading attribute = m_readings.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</Station>\n");
    return xml;
}

QString Station::toString(QString lead) {

    QString str = lead + "Station\n";
    if ( hasId() ) {
        str.append( lead + "    Id = " + QString::number(m_id) + "\n");
    }
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + "\n");
    }
    str.append( lead + "    Forecast = " + QString::number(m_forecast) + "\n");
    str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    if ( hasLocation() ) {
        str.append( lead + "    Location = " + m_location + "\n");
    }
    for(int i=0; i < m_readings.count(); i++ ) {
       Reading attribute = m_readings.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

