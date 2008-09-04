
#include "IVEF2area.h"

Area::Area() {

    m_posPresent = false;
    m_posPresent = false;
    m_namePresent = false;
    m_colorPresent = false;
    m_fillPresent = false;
}

Area::Area(const Area &val) : QObject() {

    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_colorPresent = val.m_colorPresent;
    m_color = val.m_color;
    m_fillPresent = val.m_fillPresent;
    m_fill = val.m_fill;
}

Area & Area::operator=(const Area &val) {

    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
    m_posPresent = val.m_posPresent;
    m_poss = val.m_poss;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_colorPresent = val.m_colorPresent;
    m_color = val.m_color;
    m_fillPresent = val.m_fillPresent;
    m_fill = val.m_fill;
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

void Area::setColor(QString val) {

    m_colorPresent = true;
    m_color = val;
}

QString Area::getColor() const {

    return m_color;
}

bool Area::hasColor() {

    return m_colorPresent;
}

void Area::setFill(QString val) {

    if ( ( val != "dots" ) &&
         ( val != "plain" ) &&
         ( val != "horizontal" ) &&
         ( val != "vertical" ) &&
         ( val != "diagonal" ) &&
         ( val != "mesh" ) )
        return;
    m_fillPresent = true;
    m_fill = val;
}

QString Area::getFill() const {

    return m_fill;
}

bool Area::hasFill() {

    return m_fillPresent;
}

QString Area::toXML() {

    QString xml = "<Area";
    if ( hasName() ) {
        xml.append(" Name=\"" + m_name + "\"");
    }
    if ( hasColor() ) {
        xml.append(" Color=\"" + m_color + "\"");
    }
    if ( hasFill() ) {
        xml.append(" Fill=\"" + m_fill + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
        xml.append( attribute.toXML() );
    }
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
    if ( hasColor() ) {
        str.append( lead + "    Color = " + m_color + "\n");
    }
    if ( hasFill() ) {
        str.append( lead + "    Fill = " + m_fill + "\n");
    }
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_poss.count(); i++ ) {
       Pos attribute = m_poss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

