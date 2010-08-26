
#include "IVEFArea.h"

// Constructor
Area::Area() {

    // initialize empty string
    m_name = "";
    m_namePresent = false;
}

// copy constructor
Area::Area(const Area &val) : QObject() {

    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
}

// compare
bool Area::operator==(const Area &val) {

    if (!(m_posPresent == val.m_posPresent)) return false;
    if (!(m_poss == val.m_poss)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    return true;
}

// assignement
Area & Area::operator=(const Area &val) {

    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    return *this;
}

// String encoder
QString Area::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// remover for Area
bool Area::removePos(Pos val) {

    if (m_poss.count() <= 3) {
        return false; // scalar already at minOccurs
    }
    return m_poss.removeOne(val);
}

// setter for Area
bool Area::addPos(Pos val) {

   m_poss.append(val);
      return true;
}

// getter for Area
Pos Area::getPosAt(int i) const {

    return m_poss.at(i);
}

// count for Area
int Area::countOfPoss() const {

    return m_poss.count();
}

// setter for Area
bool Area::setName(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 1)
        return false;    // check if the new value is within bounds 

    if (val.length() > 42)
        return false;
    m_namePresent = true;
    m_name = val;
      return true;
}

// getter for Area
QString Area::getName() const {

    return m_name;
}

// check if optional element Area has been set
bool Area::hasName() const {

    return m_namePresent;
}

// Get XML Representation
QString Area::toXML() const {

    QString xml = "<Area";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasName() ) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    }
    xml.append(">\n");
    if (m_poss.count() < 3) {
        return NULL; // not enough values
    }
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
    }
    xml.append( "</Area>\n");
    return xml;
}

// Get String Representation
QString Area::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Area::toString(QString lead) {

    QString str = lead + "Area\n";
    // check for presence of optional attribute
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + "\n");
    }
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

