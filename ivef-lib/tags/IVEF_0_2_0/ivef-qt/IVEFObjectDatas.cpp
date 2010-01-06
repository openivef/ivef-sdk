
#include "IVEFObjectDatas.h"

// Constructor
ObjectDatas::ObjectDatas() {

}

// copy constructor
ObjectDatas::ObjectDatas(const ObjectDatas &val) : QObject() {

    m_objectDatas = val.m_objectDatas;
}

// comperator
ObjectDatas & ObjectDatas::operator=(const ObjectDatas &val) {

    m_objectDatas = val.m_objectDatas;
    return *this;
}

// String encoder
QString ObjectDatas::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ObjectDatas
void ObjectDatas::addObjectData(ObjectData val) {

    m_objectDatas.append(val);
}

// getter for ObjectDatas
ObjectData ObjectDatas::getObjectDataAt(int i) const {

    return m_objectDatas.at(i);
}

// count for ObjectDatas
int ObjectDatas::countOfObjectDatas() const {

    return m_objectDatas.count();
}

// Get XML Representation
QString ObjectDatas::toXML() {

    QString xml = "<ObjectDatas";
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_objectDatas.count(); i++ ) {
        ObjectData attribute = m_objectDatas.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</ObjectDatas>\n");
    return xml;
}

// Get String Representation
QString ObjectDatas::toString() {

    return toString("");
}

// Get String Representation with a lead
QString ObjectDatas::toString(QString lead) {

    QString str = lead + "ObjectDatas\n";
    // add all included data
    for(int i=0; i < m_objectDatas.count(); i++ ) {
       ObjectData attribute = m_objectDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

