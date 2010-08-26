
#include "IVEFOtherName.h"

// Constructor
OtherName::OtherName() {

    // initialize empty string
    m_lang = "";
    m_langPresent = false;
    // initialize empty string
    m_name = "";
    m_namePresent = false;
}

// copy constructor
OtherName::OtherName(const OtherName &val) : QObject() {

    m_langPresent = val.m_langPresent;
    m_lang = val.m_lang;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
}

// compare
bool OtherName::operator==(const OtherName &val) {

    if (!(m_langPresent == val.m_langPresent)) return false;
    if (!(m_lang == val.m_lang)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    return true;
}

// assignement
OtherName & OtherName::operator=(const OtherName &val) {

    m_langPresent = val.m_langPresent;
    m_lang = val.m_lang;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    return *this;
}

// String encoder
QString OtherName::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for OtherName
bool OtherName::setLang(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 2)
        return false;    // check if the new value is within bounds 

    if (val.length() > 2)
        return false;
    m_langPresent = true;
    m_lang = val;
      return true;
}

// getter for OtherName
QString OtherName::getLang() const {

    return m_lang;
}

// setter for OtherName
bool OtherName::setName(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 1)
        return false;    // check if the new value is within bounds 

    if (val.length() > 42)
        return false;
    m_namePresent = true;
    m_name = val;
      return true;
}

// getter for OtherName
QString OtherName::getName() const {

    return m_name;
}

// Get XML Representation
QString OtherName::toXML() const {

    QString xml = "<OtherName";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_langPresent) {
        xml.append(" Lang=\"" + encode (m_lang) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_namePresent) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString OtherName::toString() {

    return toString("");
}

// Get String Representation with a lead
QString OtherName::toString(QString lead) {

    QString str = lead + "OtherName\n";
     str.append( lead + "    Lang = " + m_lang + "\n");
     str.append( lead + "    Name = " + m_name + "\n");
    return str;
}

