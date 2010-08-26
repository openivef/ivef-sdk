
#include "IVEFServerStatus.h"

// Constructor
ServerStatus::ServerStatus() {

    // initialize empty string
    m_status = "";
    m_statusPresent = false;
    // initialize empty string
    m_details = "";
    m_detailsPresent = false;
}

// copy constructor
ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_statusPresent = val.m_statusPresent;
    m_status = val.m_status;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
}

// compare
bool ServerStatus::operator==(const ServerStatus &val) {

    if (!(m_statusPresent == val.m_statusPresent)) return false;
    if (!(m_status == val.m_status)) return false;
    if (!(m_detailsPresent == val.m_detailsPresent)) return false;
    if (!(m_details == val.m_details)) return false;
    return true;
}

// assignement
ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_statusPresent = val.m_statusPresent;
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
    m_statusPresent = true;
    m_status = val;
      return true;
}

// getter for ServerStatus
QString ServerStatus::getStatus() const {

    return m_status;
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

// Get XML Representation
QString ServerStatus::toXML() const {

    QString xml = "<ServerStatus";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_statusPresent) {
        xml.append(" Status=\"" + encode (m_status) + "\"");
    } else { // required attribute not present
        return NULL;
    }
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

