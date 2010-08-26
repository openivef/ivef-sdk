
#include "IVEFServiceRequestResponse.h"

// Constructor
ServiceRequestResponse::ServiceRequestResponse() {

    // initialize empty string
    m_reason = "";
    m_reasonPresent = false;
    // initialize empty string
    m_responseOn = "";
    m_responseOnPresent = false;
    m_result = 0;
    m_resultPresent = false;
}

// copy constructor
ServiceRequestResponse::ServiceRequestResponse(const ServiceRequestResponse &val) : QObject() {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_resultPresent = val.m_resultPresent;
    m_result = val.m_result;
}

// compare
bool ServiceRequestResponse::operator==(const ServiceRequestResponse &val) {

    if (!(m_reasonPresent == val.m_reasonPresent)) return false;
    if (!(m_reason == val.m_reason)) return false;
    if (!(m_responseOnPresent == val.m_responseOnPresent)) return false;
    if (!(m_responseOn == val.m_responseOn)) return false;
    if (!(m_resultPresent == val.m_resultPresent)) return false;
    if (!(m_result == val.m_result)) return false;
    return true;
}

// assignement
ServiceRequestResponse & ServiceRequestResponse::operator=(const ServiceRequestResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_resultPresent = val.m_resultPresent;
    m_result = val.m_result;
    return *this;
}

// String encoder
QString ServiceRequestResponse::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ServiceRequestResponse
bool ServiceRequestResponse::setReason(QString val) {
    // check if the new value is within bounds 

    if (val.length() > 256)
        return false;
    m_reasonPresent = true;
    m_reason = val;
      return true;
}

// getter for ServiceRequestResponse
QString ServiceRequestResponse::getReason() const {

    return m_reason;
}

// check if optional element ServiceRequestResponse has been set
bool ServiceRequestResponse::hasReason() const {

    return m_reasonPresent;
}

// setter for ServiceRequestResponse
bool ServiceRequestResponse::setResponseOn(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 36)
        return false;    // check if the new value is within bounds 

    if (val.length() > 42)
        return false;
    m_responseOnPresent = true;
    m_responseOn = val;
      return true;
}

// getter for ServiceRequestResponse
QString ServiceRequestResponse::getResponseOn() const {

    return m_responseOn;
}

// setter for ServiceRequestResponse
bool ServiceRequestResponse::setResult(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_resultPresent = true;
    m_result = val;
      return true;
}

// getter for ServiceRequestResponse
int ServiceRequestResponse::getResult() const {

    return m_result;
}

// Get XML Representation
QString ServiceRequestResponse::toXML() const {

    QString xml = "<ServiceRequestResponse";
    QString dataMember;
    // check for presence of optional attribute
    if ( hasReason() ) {
        xml.append(" Reason=\"" + encode (m_reason) + "\"");
    }
    // check for presence of required  attribute
    if ( m_responseOnPresent) {
        xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_resultPresent) {
        xml.append(" Result=\"" + QString::number( m_result ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString ServiceRequestResponse::toString() {

    return toString("");
}

// Get String Representation with a lead
QString ServiceRequestResponse::toString(QString lead) {

    QString str = lead + "ServiceRequestResponse\n";
    // check for presence of optional attribute
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + "\n");
    }
     str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
     str.append( lead + "    Result = " + QString::number( m_result ) + "\n");
    return str;
}

