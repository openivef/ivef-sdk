
#include "area.h"

Area::Area() {

}

Area::Area(const Area &val) : QObject() {

    for(int i=0; i < val.countOfPoss(); i++) { 
        m_poss.append( val.getPosAt(i) );
    }
}

Area & Area::operator=(const Area &/*val*/) {

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
    xml.append( "<Area />\n");
    return xml;
}

