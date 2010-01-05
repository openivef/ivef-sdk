
#include "IVEFArea.h"

Area::Area() {

    m_name = "";
    m_namePresent = false;
}

Area::Area(const Area &val) : QObject() {

    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
}

Area & Area::operator=(const Area &val) {

    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    return *this;
}

QString Area::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Area::addPos(Pos val) {

    m_poss.append(val);
}

Pos Area::getPosAt(int i) const {

    return m_poss.at(i);
}

int Area::countOfPoss() const {

    return m_poss.count();
}

void Area::setName(QString val) {

    m_namePresent = true;
    m_name = val;
}

QString Area::getName() const {

    return m_name;
}

bool Area::hasName() {

    return m_namePresent;
}

QString Area::toXML() {

    QString xml = "<Area";
    if ( hasName() ) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_poss.count(); i++ ) {
        Pos attribute = m_poss.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</Area>\n");
    return xml;
}

QString Area::toString(QString lead) {

    QString str = lead + "Area\n";
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + "\n");
    }
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

