
#include "IVEFBody.h"

Body::Body() {

    m_loginRequestPresent = false;
    m_loginResponsePresent = false;
    m_logoutPresent = false;
    m_objectDataPresent = false;
    m_pingPresent = false;
    m_pongPresent = false;
    m_serverStatusPresent = false;
    m_serviceRequestPresent = false;
    m_serviceRequestResponsePresent = false;
}

Body::Body(const Body &val) : QObject() {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDataPresent = val.m_objectDataPresent;
    m_objectData = val.m_objectData;
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

Body & Body::operator=(const Body &val) {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDataPresent = val.m_objectDataPresent;
    m_objectData = val.m_objectData;
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

QString Body::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Body::setLoginRequest(LoginRequest val) {

    m_loginRequestPresent = true;
    m_loginRequest = val;
}

LoginRequest Body::getLoginRequest() const {

    return m_loginRequest;
}

bool Body::hasLoginRequest() {

    return m_loginRequestPresent;
}

void Body::setLoginResponse(LoginResponse val) {

    m_loginResponsePresent = true;
    m_loginResponse = val;
}

LoginResponse Body::getLoginResponse() const {

    return m_loginResponse;
}

bool Body::hasLoginResponse() {

    return m_loginResponsePresent;
}

void Body::setLogout(Logout val) {

    m_logoutPresent = true;
    m_logout = val;
}

Logout Body::getLogout() const {

    return m_logout;
}

bool Body::hasLogout() {

    return m_logoutPresent;
}

void Body::setObjectData(ObjectData val) {

    m_objectDataPresent = true;
    m_objectData = val;
}

ObjectData Body::getObjectData() const {

    return m_objectData;
}

bool Body::hasObjectData() {

    return m_objectDataPresent;
}

void Body::setPing(Ping val) {

    m_pingPresent = true;
    m_ping = val;
}

Ping Body::getPing() const {

    return m_ping;
}

bool Body::hasPing() {

    return m_pingPresent;
}

void Body::setPong(Pong val) {

    m_pongPresent = true;
    m_pong = val;
}

Pong Body::getPong() const {

    return m_pong;
}

bool Body::hasPong() {

    return m_pongPresent;
}

void Body::setServerStatus(ServerStatus val) {

    m_serverStatusPresent = true;
    m_serverStatus = val;
}

ServerStatus Body::getServerStatus() const {

    return m_serverStatus;
}

bool Body::hasServerStatus() {

    return m_serverStatusPresent;
}

void Body::setServiceRequest(ServiceRequest val) {

    m_serviceRequestPresent = true;
    m_serviceRequest = val;
}

ServiceRequest Body::getServiceRequest() const {

    return m_serviceRequest;
}

bool Body::hasServiceRequest() {

    return m_serviceRequestPresent;
}

void Body::setServiceRequestResponse(ServiceRequestResponse val) {

    m_serviceRequestResponsePresent = true;
    m_serviceRequestResponse = val;
}

ServiceRequestResponse Body::getServiceRequestResponse() const {

    return m_serviceRequestResponse;
}

bool Body::hasServiceRequestResponse() {

    return m_serviceRequestResponsePresent;
}

QString Body::toXML() {

    QString xml = "<Body";
    xml.append(">\n");
    if ( hasLoginRequest() ) {
        xml.append( m_loginRequest.toXML() );
    }
    if ( hasLoginResponse() ) {
        xml.append( m_loginResponse.toXML() );
    }
    if ( hasLogout() ) {
        xml.append( m_logout.toXML() );
    }
    if ( hasObjectData() ) {
        xml.append( m_objectData.toXML() );
    }
    if ( hasPing() ) {
        xml.append( m_ping.toXML() );
    }
    if ( hasPong() ) {
        xml.append( m_pong.toXML() );
    }
    if ( hasServerStatus() ) {
        xml.append( m_serverStatus.toXML() );
    }
    if ( hasServiceRequest() ) {
        xml.append( m_serviceRequest.toXML() );
    }
    if ( hasServiceRequestResponse() ) {
        xml.append( m_serviceRequestResponse.toXML() );
    }
    xml.append( "</Body>\n");
    return xml;
}

QString Body::toString(QString lead) {

    QString str = lead + "Body\n";
    if ( hasLoginRequest() ) {
        str.append( m_loginRequest.toString(lead + "    ") );
    }
    if ( hasLoginResponse() ) {
        str.append( m_loginResponse.toString(lead + "    ") );
    }
    if ( hasLogout() ) {
        str.append( m_logout.toString(lead + "    ") );
    }
    if ( hasObjectData() ) {
        str.append( m_objectData.toString(lead + "    ") );
    }
    if ( hasPing() ) {
        str.append( m_ping.toString(lead + "    ") );
    }
    if ( hasPong() ) {
        str.append( m_pong.toString(lead + "    ") );
    }
    if ( hasServerStatus() ) {
        str.append( m_serverStatus.toString(lead + "    ") );
    }
    if ( hasServiceRequest() ) {
        str.append( m_serviceRequest.toString(lead + "    ") );
    }
    if ( hasServiceRequestResponse() ) {
        str.append( m_serviceRequestResponse.toString(lead + "    ") );
    }
    return str;
}

