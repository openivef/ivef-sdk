
#include "IVEFBody.h"

// Constructor
Body::Body() {

    // optional attributes are by default not present
    m_loginRequestPresent = false;
    // optional attributes are by default not present
    m_loginResponsePresent = false;
    // optional attributes are by default not present
    m_logoutPresent = false;
    // optional attributes are by default not present
    m_objectDatasPresent = false;
    // optional attributes are by default not present
    m_pingPresent = false;
    // optional attributes are by default not present
    m_pongPresent = false;
    // optional attributes are by default not present
    m_serverStatusPresent = false;
    // optional attributes are by default not present
    m_serviceRequestPresent = false;
    // optional attributes are by default not present
    m_serviceRequestResponsePresent = false;
}

// copy constructor
Body::Body(const Body &val) : QObject() {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDatasPresent = val.m_objectDatasPresent;
    m_objectDatas = val.m_objectDatas;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
    m_serviceRequestResponsePresent = val.m_serviceRequestResponsePresent;
    m_serviceRequestResponse = val.m_serviceRequestResponse;
}

// assignement
Body & Body::operator=(const Body &val) {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDatasPresent = val.m_objectDatasPresent;
    m_objectDatas = val.m_objectDatas;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
    m_serviceRequestResponsePresent = val.m_serviceRequestResponsePresent;
    m_serviceRequestResponse = val.m_serviceRequestResponse;
    return *this;
}

// String encoder
QString Body::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Body
void Body::setLoginRequest(LoginRequest val) {

    m_loginRequestPresent = true;
    m_loginRequest = val;
}

// getter for Body
LoginRequest Body::getLoginRequest() const {

    return m_loginRequest;
}

// check if optional element Body has been set
bool Body::hasLoginRequest() const {

    return m_loginRequestPresent;
}

// setter for Body
void Body::setLoginResponse(LoginResponse val) {

    m_loginResponsePresent = true;
    m_loginResponse = val;
}

// getter for Body
LoginResponse Body::getLoginResponse() const {

    return m_loginResponse;
}

// check if optional element Body has been set
bool Body::hasLoginResponse() const {

    return m_loginResponsePresent;
}

// setter for Body
void Body::setLogout(Logout val) {

    m_logoutPresent = true;
    m_logout = val;
}

// getter for Body
Logout Body::getLogout() const {

    return m_logout;
}

// check if optional element Body has been set
bool Body::hasLogout() const {

    return m_logoutPresent;
}

// setter for Body
void Body::setObjectDatas(ObjectDatas val) {

    m_objectDatasPresent = true;
    m_objectDatas = val;
}

// getter for Body
ObjectDatas Body::getObjectDatas() const {

    return m_objectDatas;
}

// check if optional element Body has been set
bool Body::hasObjectDatas() const {

    return m_objectDatasPresent;
}

// setter for Body
void Body::setPing(Ping val) {

    m_pingPresent = true;
    m_ping = val;
}

// getter for Body
Ping Body::getPing() const {

    return m_ping;
}

// check if optional element Body has been set
bool Body::hasPing() const {

    return m_pingPresent;
}

// setter for Body
void Body::setPong(Pong val) {

    m_pongPresent = true;
    m_pong = val;
}

// getter for Body
Pong Body::getPong() const {

    return m_pong;
}

// check if optional element Body has been set
bool Body::hasPong() const {

    return m_pongPresent;
}

// setter for Body
void Body::setServerStatus(ServerStatus val) {

    m_serverStatusPresent = true;
    m_serverStatus = val;
}

// getter for Body
ServerStatus Body::getServerStatus() const {

    return m_serverStatus;
}

// check if optional element Body has been set
bool Body::hasServerStatus() const {

    return m_serverStatusPresent;
}

// setter for Body
void Body::setServiceRequest(ServiceRequest val) {

    m_serviceRequestPresent = true;
    m_serviceRequest = val;
}

// getter for Body
ServiceRequest Body::getServiceRequest() const {

    return m_serviceRequest;
}

// check if optional element Body has been set
bool Body::hasServiceRequest() const {

    return m_serviceRequestPresent;
}

// setter for Body
void Body::setServiceRequestResponse(ServiceRequestResponse val) {

    m_serviceRequestResponsePresent = true;
    m_serviceRequestResponse = val;
}

// getter for Body
ServiceRequestResponse Body::getServiceRequestResponse() const {

    return m_serviceRequestResponse;
}

// check if optional element Body has been set
bool Body::hasServiceRequestResponse() const {

    return m_serviceRequestResponsePresent;
}

// Get XML Representation
QString Body::toXML() {

    QString xml = "<Body";
    xml.append(">\n");
    // add optional data if available
    if ( hasLoginRequest() ) {
        xml.append( m_loginRequest.toXML() );
    }
    // add optional data if available
    if ( hasLoginResponse() ) {
        xml.append( m_loginResponse.toXML() );
    }
    // add optional data if available
    if ( hasLogout() ) {
        xml.append( m_logout.toXML() );
    }
    // add optional data if available
    if ( hasObjectDatas() ) {
        xml.append( m_objectDatas.toXML() );
    }
    // add optional data if available
    if ( hasPing() ) {
        xml.append( m_ping.toXML() );
    }
    // add optional data if available
    if ( hasPong() ) {
        xml.append( m_pong.toXML() );
    }
    // add optional data if available
    if ( hasServerStatus() ) {
        xml.append( m_serverStatus.toXML() );
    }
    // add optional data if available
    if ( hasServiceRequest() ) {
        xml.append( m_serviceRequest.toXML() );
    }
    // add optional data if available
    if ( hasServiceRequestResponse() ) {
        xml.append( m_serviceRequestResponse.toXML() );
    }
    xml.append( "</Body>\n");
    return xml;
}

// Get String Representation
QString Body::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Body::toString(QString lead) {

    QString str = lead + "Body\n";
    // add all optional data if present
    if ( hasLoginRequest() ) {
        str.append( m_loginRequest.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasLoginResponse() ) {
        str.append( m_loginResponse.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasLogout() ) {
        str.append( m_logout.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasObjectDatas() ) {
        str.append( m_objectDatas.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasPing() ) {
        str.append( m_ping.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasPong() ) {
        str.append( m_pong.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasServerStatus() ) {
        str.append( m_serverStatus.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasServiceRequest() ) {
        str.append( m_serviceRequest.toString(lead + "    ") );
    }
    // add all optional data if present
    if ( hasServiceRequestResponse() ) {
        str.append( m_serviceRequestResponse.toString(lead + "    ") );
    }
    return str;
}

