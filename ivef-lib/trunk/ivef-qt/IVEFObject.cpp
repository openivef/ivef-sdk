
#include "IVEFObject.h"

Object::Object() {

    m_fileName = "";
}

Object::Object(const Object &val) : QObject() {

    m_fileName = val.m_fileName;
}

Object & Object::operator=(const Object &val) {

    m_fileName = val.m_fileName;
    return *this;
}

QString Object::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Object::setFileName(QString val) {

    m_fileName = val;
}

QString Object::getFileName() const {

    return m_fileName;
}

QString Object::toXML() {

    QString xml = "<Object";
    xml.append(" FileName=\"" + encode (m_fileName) + "\"");
    xml.append(">\n");
    xml.append( "</Object>\n");
    return xml;
}

QString Object::toString(QString lead) {

    QString str = lead + "Object\n";
    str.append( lead + "    FileName = " + m_fileName + "\n");
    return str;
}

