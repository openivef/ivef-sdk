
#include "IVEFObjectDatas.h"

ObjectDatas::ObjectDatas() {

}

ObjectDatas::ObjectDatas(const ObjectDatas &val) : QObject() {

    m_objectDatas = val.m_objectDatas;
}

ObjectDatas & ObjectDatas::operator=(const ObjectDatas &val) {

    m_objectDatas = val.m_objectDatas;
    return *this;
}

QString ObjectDatas::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void ObjectDatas::addObjectData(ObjectData val) {

    m_objectDatas.append(val);
}

ObjectData ObjectDatas::getObjectDataAt(int i) const {

    return m_objectDatas.at(i);
}

int ObjectDatas::countOfObjectDatas() const {

    return m_objectDatas.count();
}

QString ObjectDatas::toXML() {

    QString xml = "<ObjectDatas";
    xml.append(">\n");
    for(int i=0; i < m_objectDatas.count(); i++ ) {
        ObjectData attribute = m_objectDatas.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</ObjectDatas>\n");
    return xml;
}

QString ObjectDatas::toString(QString lead) {

    QString str = lead + "ObjectDatas\n";
    for(int i=0; i < m_objectDatas.count(); i++ ) {
       ObjectData attribute = m_objectDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

