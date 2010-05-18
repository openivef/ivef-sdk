
#include "IVEFObjectDatas.h"

// Constructor
ObjectDatas::ObjectDatas() {

}

// copy constructor
ObjectDatas::ObjectDatas(const ObjectDatas &val) : QObject() {

    m_objectDataPresent = val.m_objectDataPresent;
    m_objectDatas = val.m_objectDatas;
}

// assignement
ObjectDatas & ObjectDatas::operator=(const ObjectDatas &val) {

    m_objectDataPresent = val.m_objectDataPresent;
    m_objectDatas = val.m_objectDatas;
    return *this;
}

// String encoder
QString ObjectDatas::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ObjectDatas
bool ObjectDatas::addObjectData(ObjectData val) {

   m_objectDatas.append(val);
      return true;
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
QString ObjectDatas::toXML() const {

    QString xml = "<ObjectDatas";
    QString dataMember;
    xml.append(">\n");
    // add all included data
    for(int i=0; i < m_objectDatas.count(); i++ ) {
        ObjectData attribute = m_objectDatas.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
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
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

