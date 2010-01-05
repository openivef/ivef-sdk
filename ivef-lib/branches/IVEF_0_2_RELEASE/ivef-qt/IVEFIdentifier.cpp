
#include "IVEFIdentifier.h"

Identifier::Identifier() {

    m_callsign = "";
    m_callsignPresent = false;
    m_IMO = 0;
    m_IMOPresent = false;
    m_name = "";
    m_namePresent = false;
    m_MMSI = 0;
    m_MMSIPresent = false;
    m_LRIT = "";
    m_LRITPresent = false;
}

Identifier::Identifier(const Identifier &val) : QObject() {

    m_otherIds = val.m_otherIds;
    m_otherNames = val.m_otherNames;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_LRITPresent = val.m_LRITPresent;
    m_LRIT = val.m_LRIT;
}

Identifier & Identifier::operator=(const Identifier &val) {

    m_otherIds = val.m_otherIds;
    m_otherNames = val.m_otherNames;
    m_callsignPresent = val.m_callsignPresent;
    m_callsign = val.m_callsign;
    m_IMOPresent = val.m_IMOPresent;
    m_IMO = val.m_IMO;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_MMSIPresent = val.m_MMSIPresent;
    m_MMSI = val.m_MMSI;
    m_LRITPresent = val.m_LRITPresent;
    m_LRIT = val.m_LRIT;
    return *this;
}

QString Identifier::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Identifier::addOtherId(OtherId val) {

    m_otherIds.append(val);
}

OtherId Identifier::getOtherIdAt(int i) const {

    return m_otherIds.at(i);
}

int Identifier::countOfOtherIds() const {

    return m_otherIds.count();
}

void Identifier::addOtherName(OtherName val) {

    m_otherNames.append(val);
}

OtherName Identifier::getOtherNameAt(int i) const {

    return m_otherNames.at(i);
}

int Identifier::countOfOtherNames() const {

    return m_otherNames.count();
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

void Identifier::setLRIT(QString val) {

    m_LRITPresent = true;
    m_LRIT = val;
}

QString Identifier::getLRIT() const {

    return m_LRIT;
}

bool Identifier::hasLRIT() {

    return m_LRITPresent;
}

QString Identifier::toXML() {

    QString xml = "<Identifier";
    if ( hasCallsign() ) {
        xml.append(" Callsign=\"" + encode (m_callsign) + "\"");
    }
    if ( hasIMO() ) {
        xml.append(" IMO=\"" + QString::number(m_IMO) + "\"");
    }
    if ( hasName() ) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    }
    if ( hasMMSI() ) {
        xml.append(" MMSI=\"" + QString::number(m_MMSI) + "\"");
    }
    if ( hasLRIT() ) {
        xml.append(" LRIT=\"" + encode (m_LRIT) + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_otherIds.count(); i++ ) {
        OtherId attribute = m_otherIds.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_otherNames.count(); i++ ) {
        OtherName attribute = m_otherNames.at(i);
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
    if ( hasIMO() ) {
        str.append( lead + "    IMO = " + QString::number(m_IMO) + "\n");
    }
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + "\n");
    }
    if ( hasMMSI() ) {
        str.append( lead + "    MMSI = " + QString::number(m_MMSI) + "\n");
    }
    if ( hasLRIT() ) {
        str.append( lead + "    LRIT = " + m_LRIT + "\n");
    }
    for(int i=0; i < m_otherIds.count(); i++ ) {
       OtherId attribute = m_otherIds.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_otherNames.count(); i++ ) {
       OtherName attribute = m_otherNames.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

