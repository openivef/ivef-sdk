
#include "IVEFServiceRequestResponse.h"

// Constructor
ServiceRequestResponse::ServiceRequestResponse() {

    // initialize empty string
    m_reason = "";
    // optional attributes are by default not present
    m_reasonPresent = false;
    // initialize empty string
    m_responseOn = "";
    m_result = 0;
}

// copy constructor
ServiceRequestResponse::ServiceRequestResponse(const ServiceRequestResponse &val) : QObject() {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
}

// comperator
ServiceRequestResponse & ServiceRequestResponse::operator=(const ServiceRequestResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
    return *this;
}

// String encoder
QString ServiceRequestResponse::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for ServiceRequestResponse
void ServiceRequestResponse::setReason(QString val) {

    m_reasonPresent = true;
    m_reason = val;
}

// getter for ServiceRequestResponse
QString ServiceRequestResponse::getReason() const {

    return m_reason;
}

// check if optional element ServiceRequestResponse has been set
bool ServiceRequestResponse::hasReason() {

    return m_reasonPresent;
}

// setter for ServiceRequestResponse
void ServiceRequestResponse::setResponseOn(QString val) {

    m_responseOn = val;
}

// getter for ServiceRequestResponse
QString ServiceRequestResponse::getResponseOn() const {

    return m_responseOn;
}

// setter for ServiceRequestResponse
void ServiceRequestResponse::setResult(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_result = val;
}

// getter for ServiceRequestResponse
int ServiceRequestResponse::getResult() const {

    return m_result;
}

// Get XML Representation
QString ServiceRequestResponse::toXML() {

    QString xml = "<ServiceRequestResponse";
    // check for presence of optional attribute
    if ( hasReason() ) {
        xml.append(" Reason=\"" + encode (m_reason) + "\"");
    }
    xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    xml.append(" Result=\"" + QString::number(m_result) + "\"");
    xml.append(">\n");
    xml.append( "</ServiceRequestResponse>\n");
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
    str.append( lead + "    Result = " + QString::number(m_result) + "\n");
    return str;
}

