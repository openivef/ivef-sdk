
#include "IVEFLoginResponse.h"

// Constructor
LoginResponse::LoginResponse() {

    // initialize empty string
    m_reason = "";
    // optional attributes are by default not present
    m_reasonPresent = false;
    // initialize empty string
    m_responseOn = "";
    m_result = 0;
}

// copy constructor
LoginResponse::LoginResponse(const LoginResponse &val) : QObject() {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
}

// assignement
LoginResponse & LoginResponse::operator=(const LoginResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
    return *this;
}

// String encoder
QString LoginResponse::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for LoginResponse
void LoginResponse::setReason(QString val) {

    m_reasonPresent = true;
    m_reason = val;
}

// getter for LoginResponse
QString LoginResponse::getReason() const {

    return m_reason;
}

// check if optional element LoginResponse has been set
bool LoginResponse::hasReason() const {

    return m_reasonPresent;
}

// setter for LoginResponse
void LoginResponse::setResponseOn(QString val) {

    m_responseOn = val;
}

// getter for LoginResponse
QString LoginResponse::getResponseOn() const {

    return m_responseOn;
}

// setter for LoginResponse
void LoginResponse::setResult(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_result = val;
}

// getter for LoginResponse
int LoginResponse::getResult() const {

    return m_result;
}

// Get XML Representation
QString LoginResponse::toXML() {

    QString xml = "<LoginResponse";
    // check for presence of optional attribute
    if ( hasReason() ) {
        xml.append(" Reason=\"" + encode (m_reason) + "\"");
    }
    xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    xml.append(" Result=\"" + QString::number(m_result) + "\"");
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString LoginResponse::toString() {

    return toString("");
}

// Get String Representation with a lead
QString LoginResponse::toString(QString lead) {

    QString str = lead + "LoginResponse\n";
    // check for presence of optional attribute
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + "\n");
    }
    str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
    str.append( lead + "    Result = " + QString::number(m_result) + "\n");
    return str;
}

