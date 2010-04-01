
#include "IVEFOtherName.h"

// Constructor
OtherName::OtherName() {

    // initialize empty string
    m_lang = "";
    // initialize empty string
    m_name = "";
}

// copy constructor
OtherName::OtherName(const OtherName &val) : QObject() {

    m_lang = val.m_lang;
    m_name = val.m_name;
}

// assignement
OtherName & OtherName::operator=(const OtherName &val) {

    m_lang = val.m_lang;
    m_name = val.m_name;
    return *this;
}

// String encoder
QString OtherName::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for OtherName
void OtherName::setLang(QString val) {

    m_lang = val;
}

// getter for OtherName
QString OtherName::getLang() const {

    return m_lang;
}

// setter for OtherName
void OtherName::setName(QString val) {

    m_name = val;
}

// getter for OtherName
QString OtherName::getName() const {

    return m_name;
}

// Get XML Representation
QString OtherName::toXML() {

    QString xml = "<OtherName";
    xml.append(" Lang=\"" + encode (m_lang) + "\"");
    xml.append(" Name=\"" + encode (m_name) + "\"");
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

