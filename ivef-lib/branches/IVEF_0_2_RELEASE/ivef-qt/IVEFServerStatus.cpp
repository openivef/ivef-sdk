
#include "IVEFServerStatus.h"

// Constructor
ServerStatus::ServerStatus() {

    // initialize empty string
    m_contactIdentity = "";
    m_contactIdentityPresent = false;
    // initialize empty string
    m_details = "";
    m_detailsPresent = false;
    // initialize defaults to false
    m_status = false;
    m_statusPresent = false;
}

// copy constructor
ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_statusPresent = val.m_statusPresent;
    m_status = val.m_status;
}

// compare
bool ServerStatus::operator==(const ServerStatus &val) {

    if (!(m_contactIdentityPresent == val.m_contactIdentityPresent)) return false;
    if (!(m_contactIdentity == val.m_contactIdentity)) return false;
    if (!(m_detailsPresent == val.m_detailsPresent)) return false;
    if (!(m_details == val.m_details)) return false;
    if (!(m_statusPresent == val.m_statusPresent)) return false;
    if (!(m_status == val.m_status)) return false;
    return true;
}

// assignement
ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_statusPresent = val.m_statusPresent;
    m_status = val.m_status;
    return *this;
}

// String encoder
QString ServerStatus::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ServerStatus
bool ServerStatus::setContactIdentity(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 1)
        return false;    // check if the new value is within bounds 

    if (val.length() > 254)
        return false;
    m_contactIdentityPresent = true;
    m_contactIdentity = val;
      return true;
}

// getter for ServerStatus
QString ServerStatus::getContactIdentity() const {

    return m_contactIdentity;
}

// check if optional element ServerStatus has been set
bool ServerStatus::hasContactIdentity() const {

    return m_contactIdentityPresent;
}

// setter for ServerStatus
bool ServerStatus::setDetails(QString val) {
    // check if the new value is within bounds 

    if (val.length() > 50)
        return false;
    m_detailsPresent = true;
    m_details = val;
      return true;
}

// getter for ServerStatus
QString ServerStatus::getDetails() const {

    return m_details;
}

// check if optional element ServerStatus has been set
bool ServerStatus::hasDetails() const {

    return m_detailsPresent;
}

// setter for ServerStatus
bool ServerStatus::setStatus(bool val) {

    m_statusPresent = true;
    m_status = val;
      return true;
}

// getter for ServerStatus
bool ServerStatus::getStatus() const {

    return m_status;
}

// Get XML Representation
QString ServerStatus::toXML() const {

    QString xml = "<ServerStatus";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDetails() ) {
        xml.append(" Details=\"" + encode (m_details) + "\"");
    }
    // check for presence of required  attribute
    if ( m_statusPresent) {
        xml.append(" Status=\"" + QString( m_status ? "true" : "false" ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString ServerStatus::toString() {

    return toString("");
}

// Get String Representation with a lead
QString ServerStatus::toString(QString lead) {

    QString str = lead + "ServerStatus\n";
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        str.append( lead + "    ContactIdentity = " + m_contactIdentity + "\n");
    }
    // check for presence of optional attribute
    if ( hasDetails() ) {
        str.append( lead + "    Details = " + m_details + "\n");
    }
     str.append( lead + "    Status = " + QString( m_status ? "true" : "false" ) + "\n");
    return str;
}

