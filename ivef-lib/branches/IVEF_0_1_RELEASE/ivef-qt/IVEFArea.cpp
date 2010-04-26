
#include "IVEFArea.h"

// Constructor
Area::Area() {

    m_posPresent = false;
}

// copy constructor
Area::Area(const Area &val) : QObject() {

    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
}

// assignement
Area & Area::operator=(const Area &val) {

    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
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

// Get XML Representation
QString Area::toXML() const {

    QString xml = "<Area";
    QString dataMember;
    xml.append(">\n");
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
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

