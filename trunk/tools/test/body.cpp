
#include "body.h"

Body::Body() {

    m_vesselDataPresent = false;
    m_loginRequestPresent = false;
    m_loginResponsePresent = false;
    m_pingPresent = false;
    m_pongPresent = false;
    m_serverStatusPresent = false;
    m_logoutPresent = false;
    m_serviceRequestPresent = false;
}

Body::Body(const Body &val) : QObject() {

    m_vesselDataPresent = false;
    for(int i=0; i < val.countOfVesselDatas(); i++) { 
        m_vesselDatas.append( val.getVesselDataAt(i) );
    }
    m_loginRequestPresent = false;
    m_loginRequest = val.getLoginRequest();
    m_loginResponsePresent = false;
    m_loginResponse = val.getLoginResponse();
    m_pingPresent = false;
    m_ping = val.getPing();
    m_pongPresent = false;
    m_pong = val.getPong();
    m_serverStatusPresent = false;
    m_serverStatus = val.getServerStatus();
    m_logoutPresent = false;
    m_logout = val.getLogout();
    m_serviceRequestPresent = false;
    m_serviceRequest = val.getServiceRequest();
}

Body & Body::operator=(const Body &/*val*/) {

    return *this;
}

void Body::addVesselData(VesselData val) {

    m_vesselDatas.append(val);
}

VesselData Body::getVesselDataAt(int i) const {

    return m_vesselDatas.at(i);
}

int Body::countOfVesselDatas() const {

    return m_vesselDatas.count();
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

QString Body::toXML() {

    QString xml = "<Body";
    xml.append(">\n");
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
       VesselData attribute = m_vesselDatas.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( m_loginRequest.toXML() );
    xml.append( m_loginResponse.toXML() );
    xml.append( m_ping.toXML() );
    xml.append( m_pong.toXML() );
    xml.append( m_serverStatus.toXML() );
    xml.append( m_logout.toXML() );
    xml.append( m_serviceRequest.toXML() );
    xml.append( "<Body />\n");
    return xml;
}

