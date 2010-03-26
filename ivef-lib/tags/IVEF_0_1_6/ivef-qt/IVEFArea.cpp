
#include "IVEFArea.h"

// Constructor
Area::Area() {

}

// copy constructor
Area::Area(const Area &val) : QObject() {

    m_poss = val.m_poss;
}

// assignement
Area & Area::operator=(const Area &val) {

    m_poss = val.m_poss;
    return *this;
}

// String encoder
QString Area::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Area
void Area::addPos(Pos val) {

    m_poss.append(val);
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
QString Area::toXML() {

    QString xml = "<Area";
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        xml.append( attribute.toXML() );
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

