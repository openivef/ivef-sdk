
#include "IVEFServerStatus.h"

// Constructor
ServerStatus::ServerStatus() {

    // initialize empty string
    m_contactIdentity = "";
    // optional attributes are by default not present
    m_contactIdentityPresent = false;
    // initialize empty string
    m_details = "";
    // optional attributes are by default not present
    m_detailsPresent = false;
    // initialize defaults to false
    m_status = false;
}

// copy constructor
ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_status = val.m_status;
}

// assignement
ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_status = val.m_status;
    return *this;
}

// String encoder
QString ServerStatus::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ServerStatus
void ServerStatus::setContactIdentity(QString val) {

    m_contactIdentityPresent = true;
    m_contactIdentity = val;
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
void ServerStatus::setDetails(QString val) {

    m_detailsPresent = true;
    m_details = val;
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
void ServerStatus::setStatus(bool val) {

    m_status = val;
}

// getter for ServerStatus
bool ServerStatus::getStatus() const {

    return m_status;
}

// Get XML Representation
QString ServerStatus::toXML() {

    QString xml = "<ServerStatus";
    // check for presence of optional attribute
    if ( hasContactIdentity() ) {
        xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + "\"");
    }
    // check for presence of optional attribute
    if ( hasDetails() ) {
        xml.append(" Details=\"" + encode (m_details) + "\"");
    }
    xml.append(" Status=\"" + QString(m_status ? "true" : "false" ) + "\"");
    xml.append(">\n");
    xml.append( "</ServerStatus>\n");
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
    str.append( lead + "    Status = " + QString::number(m_status) + "\n");
    return str;
}

