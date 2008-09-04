
#include "IVEF2identifier.h"

Identifier::Identifier() {

    m_callsignPresent = false;
    m_namePresent = false;
    m_MMSIPresent = false;
    m_IMOPresent = false;
    m_telephonePresent = false;
    m_satComPresent = false;
}

Identifier::Identifier(const Identifier &val) : QObject() {

    m_foreignNames = val.m_foreignNames;
    m_foreignIds = val.m_foreignIds;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_telephonePresent = val.m_telephonePresent;
    m_telephone = val.m_telephone;
    m_satComPresent = val.m_satComPresent;
    m_satCom = val.m_satCom;
}

Identifier & Identifier::operator=(const Identifier &val) {

    m_foreignNames = val.m_foreignNames;
    m_foreignIds = val.m_foreignIds;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_telephonePresent = val.m_telephonePresent;
    m_telephone = val.m_telephone;
    m_satComPresent = val.m_satComPresent;
    m_satCom = val.m_satCom;
    return *this;
}

void Identifier::addForeignName(foreignName val) {

    m_foreignNames.append(val);
}

foreignName Identifier::getForeignNameAt(int i) const {

    return m_foreignNames.at(i);
}

int Identifier::countOfForeignNames() const {

    return m_foreignNames.count();
}

void Identifier::addForeignId(foreignId val) {

    m_foreignIds.append(val);
}

foreignId Identifier::getForeignIdAt(int i) const {

    return m_foreignIds.at(i);
}

int Identifier::countOfForeignIds() const {

    return m_foreignIds.count();
}

void Identifier::setCallsign(QString val) {

    m_callsignPresent = true;
    m_callsign = val;
}

QString Identifier::getCallsign() const {

    return m_callsign;
}

bool Identifier::hasCallsign() {

    return m_callsignPresent;
}

void Identifier::setName(QString val) {

    m_namePresent = true;
    m_name = val;
}

QString Identifier::getName() const {

    return m_name;
}

bool Identifier::hasName() {

    return m_namePresent;
}

void Identifier::setMMSI(int val) {

    m_MMSIPresent = true;
    m_MMSI = val;
}

int Identifier::getMMSI() const {

    return m_MMSI;
}

bool Identifier::hasMMSI() {

    return m_MMSIPresent;
}

void Identifier::setIMO(int val) {

    m_IMOPresent = true;
    m_IMO = val;
}

int Identifier::getIMO() const {

    return m_IMO;
}

bool Identifier::hasIMO() {

    return m_IMOPresent;
}

void Identifier::setTelephone(int val) {

    m_telephonePresent = true;
    m_telephone = val;
}

int Identifier::getTelephone() const {

    return m_telephone;
}

bool Identifier::hasTelephone() {

    return m_telephonePresent;
}

void Identifier::setSatCom(int val) {

    m_satComPresent = true;
    m_satCom = val;
}

int Identifier::getSatCom() const {

    return m_satCom;
}

bool Identifier::hasSatCom() {

    return m_satComPresent;
}

QString Identifier::toXML() {

    QString xml = "<Identifier";
    if ( hasCallsign() ) {
        xml.append(" Callsign=\"" + m_callsign + "\"");
    }
    if ( hasName() ) {
        xml.append(" Name=\"" + m_name + "\"");
    }
    if ( hasMMSI() ) {
        xml.append(" MMSI=\"" + QString::number(m_MMSI) + "\"");
    }
    if ( hasIMO() ) {
        xml.append(" IMO=\"" + QString::number(m_IMO) + "\"");
    }
    if ( hasTelephone() ) {
        xml.append(" Telephone=\"" + QString::number(m_telephone) + "\"");
    }
    if ( hasSatCom() ) {
        xml.append(" SatCom=\"" + QString::number(m_satCom) + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_foreignNames.count(); i++ ) {
       foreignName attribute = m_foreignNames.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_foreignIds.count(); i++ ) {
       foreignId attribute = m_foreignIds.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</Identifier>\n");
    return xml;
}

QString Identifier::toString(QString lead) {

    QString str = lead + "Identifier\n";
    if ( hasCallsign() ) {
        str.append( lead + "    Callsign = " + m_callsign + "\n");
    }
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + "\n");
    }
    if ( hasMMSI() ) {
        str.append( lead + "    MMSI = " + QString::number(m_MMSI) + "\n");
    }
    if ( hasIMO() ) {
        str.append( lead + "    IMO = " + QString::number(m_IMO) + "\n");
    }
    if ( hasTelephone() ) {
        str.append( lead + "    Telephone = " + QString::number(m_telephone) + "\n");
    }
    if ( hasSatCom() ) {
        str.append( lead + "    SatCom = " + QString::number(m_satCom) + "\n");
    }
    for(int i=0; i < m_foreignNames.count(); i++ ) {
       foreignName attribute = m_foreignNames.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_foreignIds.count(); i++ ) {
       foreignId attribute = m_foreignIds.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

