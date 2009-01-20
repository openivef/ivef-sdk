
#include "IVEFArea.h"

Area::Area() {

}

Area::Area(const Area &val) : QObject() {

    m_poss = val.m_poss;
}

Area & Area::operator=(const Area &val) {

    m_poss = val.m_poss;
    return *this;
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

QString Area::toXML() {

    QString xml = "<Area";
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
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

