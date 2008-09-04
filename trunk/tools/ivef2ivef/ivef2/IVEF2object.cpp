
#include "IVEF2object.h"

Object::Object() {

}

Object::Object(const Object &val) : QObject() {

    m_filterName = val.m_filterName;
}

Object & Object::operator=(const Object &val) {

    m_filterName = val.m_filterName;
    return *this;
}

void Object::setFilterName(QString val) {

    m_filterName = val;
}

QString Object::getFilterName() const {

    return m_filterName;
}

QString Object::toXML() {

    QString xml = "<Object";
    xml.append(" FilterName=\"" + m_filterName + "\"");
    xml.append(">\n");
    xml.append( "</Object>\n");
    return xml;
}

QString Object::toString(QString lead) {

    QString str = lead + "Object\n";
    str.append( lead + "    FilterName = " + m_filterName + "\n");
    return str;
}

