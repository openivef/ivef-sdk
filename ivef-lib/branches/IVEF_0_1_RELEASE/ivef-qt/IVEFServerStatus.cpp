
#include "IVEFServerStatus.h"

// Constructor
ServerStatus::ServerStatus() {

    // initialize empty string
    m_status = "";
    // initialize empty string
    m_details = "";
    // optional attributes are by default not present
    m_detailsPresent = false;
}

// copy constructor
ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_status = val.m_status;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
}

// assignement
ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_status = val.m_status;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
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
bool ServerStatus::setStatus(QString val) {
// check if the new value is an approved value 

    if ( ( val != "queuefull" ) &&
         ( val != "ok" ) )
        return false;
    m_status = val;
      return true;
}

// getter for ServerStatus
QString ServerStatus::getStatus() const {

    return m_status;
}

// setter for ServerStatus
bool ServerStatus::setDetails(QString val) {

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

// Get XML Representation
QString ServerStatus::toXML() const {

    QString xml = "<ServerStatus";
    xml.append(" Status=\"" + encode (m_status) + "\"");
    // check for presence of optional attribute
    if ( hasDetails() ) {
        xml.append(" Details=\"" + encode (m_details) + "\"");
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
    str.append( lead + "    Status = " + m_status + "\n");
    // check for presence of optional attribute
    if ( hasDetails() ) {
        str.append( lead + "    Details = " + m_details + "\n");
    }
    return str;
}

