
#include "IVEFIdentifier.h"

// Constructor
Identifier::Identifier() {

    // initialize empty string
    m_callsign = "";
    // optional attributes are by default not present
    m_callsignPresent = false;
    m_IMO = 0;
    // optional attributes are by default not present
    m_IMOPresent = false;
    // initialize empty string
    m_name = "";
    // optional attributes are by default not present
    m_namePresent = false;
    m_MMSI = 0;
    // optional attributes are by default not present
    m_MMSIPresent = false;
    // initialize empty string
    m_LRIT = "";
    // optional attributes are by default not present
    m_LRITPresent = false;
}

// copy constructor
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

// assignement
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

// String encoder
QString Identifier::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Identifier
void Identifier::addOtherId(OtherId val) {

    m_otherIds.append(val);
}

// getter for Identifier
OtherId Identifier::getOtherIdAt(int i) const {

    return m_otherIds.at(i);
}

// count for Identifier
int Identifier::countOfOtherIds() const {

    return m_otherIds.count();
}

// setter for Identifier
void Identifier::addOtherName(OtherName val) {

    m_otherNames.append(val);
}

// getter for Identifier
OtherName Identifier::getOtherNameAt(int i) const {

    return m_otherNames.at(i);
}

// count for Identifier
int Identifier::countOfOtherNames() const {

    return m_otherNames.count();
}

// setter for Identifier
void Identifier::setCallsign(QString val) {

    m_callsignPresent = true;
    m_callsign = val;
}

// getter for Identifier
QString Identifier::getCallsign() const {

    return m_callsign;
}

// check if optional element Identifier has been set
bool Identifier::hasCallsign() const {

    return m_callsignPresent;
}

// setter for Identifier
void Identifier::setIMO(int val) {

    m_IMOPresent = true;
    m_IMO = val;
}

// getter for Identifier
int Identifier::getIMO() const {

    return m_IMO;
}

// check if optional element Identifier has been set
bool Identifier::hasIMO() const {

    return m_IMOPresent;
}

// setter for Identifier
void Identifier::setName(QString val) {

    m_namePresent = true;
    m_name = val;
}

// getter for Identifier
QString Identifier::getName() const {

    return m_name;
}

// check if optional element Identifier has been set
bool Identifier::hasName() const {

    return m_namePresent;
}

// setter for Identifier
void Identifier::setMMSI(int val) {

    m_MMSIPresent = true;
    m_MMSI = val;
}

// getter for Identifier
int Identifier::getMMSI() const {

    return m_MMSI;
}

// check if optional element Identifier has been set
bool Identifier::hasMMSI() const {

    return m_MMSIPresent;
}

// setter for Identifier
void Identifier::setLRIT(QString val) {

    m_LRITPresent = true;
    m_LRIT = val;
}

// getter for Identifier
QString Identifier::getLRIT() const {

    return m_LRIT;
}

// check if optional element Identifier has been set
bool Identifier::hasLRIT() const {

    return m_LRITPresent;
}

// Get XML Representation
QString Identifier::toXML() {

    QString xml = "<Identifier";
    // check for presence of optional attribute
    if ( hasCallsign() ) {
        xml.append(" Callsign=\"" + encode (m_callsign) + "\"");
    }
    // check for presence of optional attribute
    if ( hasIMO() ) {
        xml.append(" IMO=\"" + QString::number(m_IMO) + "\"");
    }
    // check for presence of optional attribute
    if ( hasName() ) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    }
    // check for presence of optional attribute
    if ( hasMMSI() ) {
        xml.append(" MMSI=\"" + QString::number(m_MMSI) + "\"");
    }
    // check for presence of optional attribute
    if ( hasLRIT() ) {
        xml.append(" LRIT=\"" + encode (m_LRIT) + "\"");
    }
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_otherIds.count(); i++ ) {
        OtherId attribute = m_otherIds.at(i);
        xml.append( attribute.toXML() );
    }
    // add all included data
    for(int i=0; i < m_otherNames.count(); i++ ) {
        OtherName attribute = m_otherNames.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</Identifier>\n");
    return xml;
}

// Get String Representation
QString Identifier::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Identifier::toString(QString lead) {

    QString str = lead + "Identifier\n";
    // check for presence of optional attribute
    if ( hasCallsign() ) {
        str.append( lead + "    Callsign = " + m_callsign + "\n");
    }
    // check for presence of optional attribute
    if ( hasIMO() ) {
        str.append( lead + "    IMO = " + QString::number(m_IMO) + "\n");
    }
    // check for presence of optional attribute
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + "\n");
    }
    // check for presence of optional attribute
    if ( hasMMSI() ) {
        str.append( lead + "    MMSI = " + QString::number(m_MMSI) + "\n");
    }
    // check for presence of optional attribute
    if ( hasLRIT() ) {
        str.append( lead + "    LRIT = " + m_LRIT + "\n");
    }
    // add all included data
    for(int i=0; i < m_otherIds.count(); i++ ) {
       OtherId attribute = m_otherIds.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    // add all included data
    for(int i=0; i < m_otherNames.count(); i++ ) {
       OtherName attribute = m_otherNames.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

