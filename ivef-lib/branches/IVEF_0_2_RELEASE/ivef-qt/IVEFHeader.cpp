
#include "IVEFHeader.h"

// Constructor
Header::Header() {

    // initialize empty string
    m_msgRefId = "";
    m_msgRefIdPresent = false;
    // initialize fixed value
    m_version = "0.2.3";
    m_versionPresent = true;
}

// copy constructor
Header::Header(const Header &val) : QObject() {

    m_msgRefIdPresent = val.m_msgRefIdPresent;
    m_msgRefId = val.m_msgRefId;
    m_versionPresent = val.m_versionPresent;
    m_version = val.m_version;
}

// compare
bool Header::operator==(const Header &val) {

    if (!(m_msgRefIdPresent == val.m_msgRefIdPresent)) return false;
    if (!(m_msgRefId == val.m_msgRefId)) return false;
    if (!(m_versionPresent == val.m_versionPresent)) return false;
    if (!(m_version == val.m_version)) return false;
    return true;
}

// assignement
Header & Header::operator=(const Header &val) {

    m_msgRefIdPresent = val.m_msgRefIdPresent;
    m_msgRefId = val.m_msgRefId;
    m_versionPresent = val.m_versionPresent;
    m_version = val.m_version;
    return *this;
}

// String encoder
QString Header::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Header
bool Header::setMsgRefId(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 36)
        return false;    // check if the new value is within bounds 

    if (val.length() > 42)
        return false;
    m_msgRefIdPresent = true;
    m_msgRefId = val;
      return true;
}

// getter for Header
QString Header::getMsgRefId() const {

    return m_msgRefId;
}

// setter for Header
bool Header::setVersion(QString val) {

    m_versionPresent = true;
    m_version = val;
      return true;
}

// getter for Header
QString Header::getVersion() const {

    return m_version;
}

// Get XML Representation
QString Header::toXML() const {

    QString xml = "<Header";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_msgRefIdPresent) {
        xml.append(" MsgRefId=\"" + encode (m_msgRefId) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_versionPresent) {
        xml.append(" Version=\"" + encode (m_version) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Header::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Header::toString(QString lead) {

    QString str = lead + "Header\n";
     str.append( lead + "    MsgRefId = " + m_msgRefId + "\n");
     str.append( lead + "    Version = " + m_version + "\n");
    return str;
}

