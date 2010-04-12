
#include "IVEFSensor.h"

// Constructor
Sensor::Sensor() {

    m_senId = 0;
    m_trkId = 0;
}

// copy constructor
Sensor::Sensor(const Sensor &val) : QObject() {

    m_senId = val.m_senId;
    m_trkId = val.m_trkId;
}

// assignement
Sensor & Sensor::operator=(const Sensor &val) {

    m_senId = val.m_senId;
    m_trkId = val.m_trkId;
    return *this;
}

// String encoder
QString Sensor::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Sensor
void Sensor::setSenId(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 65536)
        return;
    m_senId = val;
}

// getter for Sensor
int Sensor::getSenId() const {

    return m_senId;
}

// setter for Sensor
void Sensor::setTrkId(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 65536)
        return;
    m_trkId = val;
}

// getter for Sensor
int Sensor::getTrkId() const {

    return m_trkId;
}

// Get XML Representation
QString Sensor::toXML() {

    QString xml = "<Sensor";
    xml.append(" SenId=\"" + QString::number(m_senId) + "\"");
    xml.append(" TrkId=\"" + QString::number(m_trkId) + "\"");
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Sensor::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Sensor::toString(QString lead) {

    QString str = lead + "Sensor\n";
    str.append( lead + "    SenId = " + QString::number(m_senId) + "\n");
    str.append( lead + "    TrkId = " + QString::number(m_trkId) + "\n");
    return str;
}

