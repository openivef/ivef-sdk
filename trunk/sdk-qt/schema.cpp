
#include "schema.h"

Schema::Schema() {

}

Schema::Schema(const Schema &val) : QObject() {

    m_header = ((Schema)val).getHeader();
    m_MSG_VesselData = ((Schema)val).getMSG_VesselData();
    m_vesselData = ((Schema)val).getVesselData();
    m_posReport = ((Schema)val).getPosReport();
    m_staticData = ((Schema)val).getStaticData();
    m_voyage = ((Schema)val).getVoyage();
    m_MSG_LoginRequest = ((Schema)val).getMSG_LoginRequest();
    m_loginRequest = ((Schema)val).getLoginRequest();
    m_MSG_LoginResponse = ((Schema)val).getMSG_LoginResponse();
    m_loginResponse = ((Schema)val).getLoginResponse();
    m_MSG_Ping = ((Schema)val).getMSG_Ping();
    m_ping = ((Schema)val).getPing();
    m_MSG_Pong = ((Schema)val).getMSG_Pong();
    m_pong = ((Schema)val).getPong();
    m_MSG_ServerStatus = ((Schema)val).getMSG_ServerStatus();
    m_serverStatus = ((Schema)val).getServerStatus();
    m_MSG_Logout = ((Schema)val).getMSG_Logout();
    m_logout = ((Schema)val).getLogout();
    m_MSG_ServiceRequest = ((Schema)val).getMSG_ServiceRequest();
    m_serviceRequest = ((Schema)val).getServiceRequest();
    m_pos = ((Schema)val).getPos();
}

Schema & Schema::operator=(const Schema &/*val*/) {

    return *this;
}

void Schema::setHeader(Header val) {

    m_header = val;
}

Header Schema::getHeader() {

    return m_header;
}

void Schema::setMSG_VesselData(MSG_VesselData val) {

    m_MSG_VesselData = val;
}

MSG_VesselData Schema::getMSG_VesselData() {

    return m_MSG_VesselData;
}

void Schema::setVesselData(VesselData val) {

    m_vesselData = val;
}

VesselData Schema::getVesselData() {

    return m_vesselData;
}

void Schema::setPosReport(PosReport val) {

    m_posReport = val;
}

PosReport Schema::getPosReport() {

    return m_posReport;
}

void Schema::setStaticData(StaticData val) {

    m_staticData = val;
}

StaticData Schema::getStaticData() {

    return m_staticData;
}

void Schema::setVoyage(Voyage val) {

    m_voyage = val;
}

Voyage Schema::getVoyage() {

    return m_voyage;
}

void Schema::setMSG_LoginRequest(MSG_LoginRequest val) {

    m_MSG_LoginRequest = val;
}

MSG_LoginRequest Schema::getMSG_LoginRequest() {

    return m_MSG_LoginRequest;
}

void Schema::setLoginRequest(LoginRequest val) {

    m_loginRequest = val;
}

LoginRequest Schema::getLoginRequest() {

    return m_loginRequest;
}

void Schema::setMSG_LoginResponse(MSG_LoginResponse val) {

    m_MSG_LoginResponse = val;
}

MSG_LoginResponse Schema::getMSG_LoginResponse() {

    return m_MSG_LoginResponse;
}

void Schema::setLoginResponse(LoginResponse val) {

    m_loginResponse = val;
}

LoginResponse Schema::getLoginResponse() {

    return m_loginResponse;
}

void Schema::setMSG_Ping(MSG_Ping val) {

    m_MSG_Ping = val;
}

MSG_Ping Schema::getMSG_Ping() {

    return m_MSG_Ping;
}

void Schema::setPing(Ping val) {

    m_ping = val;
}

Ping Schema::getPing() {

    return m_ping;
}

void Schema::setMSG_Pong(MSG_Pong val) {

    m_MSG_Pong = val;
}

MSG_Pong Schema::getMSG_Pong() {

    return m_MSG_Pong;
}

void Schema::setPong(Pong val) {

    m_pong = val;
}

Pong Schema::getPong() {

    return m_pong;
}

void Schema::setMSG_ServerStatus(MSG_ServerStatus val) {

    m_MSG_ServerStatus = val;
}

MSG_ServerStatus Schema::getMSG_ServerStatus() {

    return m_MSG_ServerStatus;
}

void Schema::setServerStatus(ServerStatus val) {

    m_serverStatus = val;
}

ServerStatus Schema::getServerStatus() {

    return m_serverStatus;
}

void Schema::setMSG_Logout(MSG_Logout val) {

    m_MSG_Logout = val;
}

MSG_Logout Schema::getMSG_Logout() {

    return m_MSG_Logout;
}

void Schema::setLogout(Logout val) {

    m_logout = val;
}

Logout Schema::getLogout() {

    return m_logout;
}

void Schema::setMSG_ServiceRequest(MSG_ServiceRequest val) {

    m_MSG_ServiceRequest = val;
}

MSG_ServiceRequest Schema::getMSG_ServiceRequest() {

    return m_MSG_ServiceRequest;
}

void Schema::setServiceRequest(ServiceRequest val) {

    m_serviceRequest = val;
}

ServiceRequest Schema::getServiceRequest() {

    return m_serviceRequest;
}

void Schema::setPos(Pos val) {

    m_pos = val;
}

Pos Schema::getPos() {

    return m_pos;
}

QString Schema::getElementFormDefault() {

    return "qualified";
}

QString Schema::getTargetNamespace() {

    return "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1";
}

QString Schema::toXML() {

    QString xml = "<Schema";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_MSG_VesselData.toXML() );
    xml.append( m_vesselData.toXML() );
    xml.append( m_posReport.toXML() );
    xml.append( m_staticData.toXML() );
    xml.append( m_voyage.toXML() );
    xml.append( m_MSG_LoginRequest.toXML() );
    xml.append( m_loginRequest.toXML() );
    xml.append( m_MSG_LoginResponse.toXML() );
    xml.append( m_loginResponse.toXML() );
    xml.append( m_MSG_Ping.toXML() );
    xml.append( m_ping.toXML() );
    xml.append( m_MSG_Pong.toXML() );
    xml.append( m_pong.toXML() );
    xml.append( m_MSG_ServerStatus.toXML() );
    xml.append( m_serverStatus.toXML() );
    xml.append( m_MSG_Logout.toXML() );
    xml.append( m_logout.toXML() );
    xml.append( m_MSG_ServiceRequest.toXML() );
    xml.append( m_serviceRequest.toXML() );
    xml.append( m_pos.toXML() );
    xml.append( "<Schema />\n");
    return xml;
}

