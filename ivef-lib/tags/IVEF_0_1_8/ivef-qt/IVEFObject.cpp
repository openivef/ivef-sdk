
#include "IVEFObject.h"

// Constructor
Object::Object() {

    // initialize empty string
    m_fileName = "";
    m_fileNamePresent = false;
}

// copy constructor
Object::Object(const Object &val) : QObject() {

    m_fileNamePresent = val.m_fileNamePresent;
    m_fileName = val.m_fileName;
}

// compare
bool Object::operator==(const Object &val) {

    if (!(m_fileNamePresent == val.m_fileNamePresent)) return false;
    if (!(m_fileName == val.m_fileName)) return false;
    return true;
}

// assignement
Object & Object::operator=(const Object &val) {

    m_fileNamePresent = val.m_fileNamePresent;
    m_fileName = val.m_fileName;
    return *this;
}

// String encoder
QString Object::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Object
bool Object::setFileName(QString val) {

    m_fileNamePresent = true;
    m_fileName = val;
      return true;
}

// getter for Object
QString Object::getFileName() const {

    return m_fileName;
}

// Get XML Representation
QString Object::toXML() const {

    QString xml = "<Object";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_fileNamePresent) {
        xml.append(" FileName=\"" + encode (m_fileName) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Object::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Object::toString(QString lead) {

    QString str = lead + "Object\n";
     str.append( lead + "    FileName = " + m_fileName + "\n");
    return str;
}

