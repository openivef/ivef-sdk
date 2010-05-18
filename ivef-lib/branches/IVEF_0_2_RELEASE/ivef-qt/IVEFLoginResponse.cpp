
#include "IVEFLoginResponse.h"

// Constructor
LoginResponse::LoginResponse() {

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
LoginResponse::LoginResponse(const LoginResponse &val) : QObject() {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_resultPresent = val.m_resultPresent;
    m_result = val.m_result;
}

// assignement
LoginResponse & LoginResponse::operator=(const LoginResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOnPresent = val.m_responseOnPresent;
    m_responseOn = val.m_responseOn;
    m_resultPresent = val.m_resultPresent;
    m_result = val.m_result;
    return *this;
}

// String encoder
QString LoginResponse::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for LoginResponse
bool LoginResponse::setReason(QString val) {

    m_reasonPresent = true;
    m_reason = val;
      return true;
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
bool LoginResponse::setResponseOn(QString val) {

    m_responseOnPresent = true;
    m_responseOn = val;
      return true;
}

// getter for LoginResponse
QString LoginResponse::getResponseOn() const {

    return m_responseOn;
}

// setter for LoginResponse
bool LoginResponse::setResult(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_resultPresent = true;
    m_result = val;
      return true;
}

// getter for LoginResponse
int LoginResponse::getResult() const {

    return m_result;
}

// Get XML Representation
QString LoginResponse::toXML() const {

    QString xml = "<LoginResponse";
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
     str.append( lead + "    Result = " + QString::number( m_result ) + "\n");
    return str;
}

