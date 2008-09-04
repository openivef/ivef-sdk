
#include "IVEF2body.h"

Body::Body() {

    m_loginRequestPresent = false;
    m_loginResponsePresent = false;
    m_logoutPresent = false;
    m_objectDataPresent = false;
    m_chartPresent = false;
    m_hyMePresent = false;
    m_forcastPresent = false;
    m_messagePresent = false;
    m_pingPresent = false;
    m_pongPresent = false;
    m_serverStatusPresent = false;
    m_serviceRequestPresent = false;
}

Body::Body(const Body &val) : QObject() {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDataPresent = val.m_objectDataPresent;
    m_objectDatas = val.m_objectDatas;
    m_chartPresent = val.m_chartPresent;
    m_charts = val.m_charts;
    m_hyMePresent = val.m_hyMePresent;
    m_hyMes = val.m_hyMes;
    m_forcastPresent = val.m_forcastPresent;
    m_forcasts = val.m_forcasts;
    m_messagePresent = val.m_messagePresent;
    m_messages = val.m_messages;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
}

Body & Body::operator=(const Body &val) {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_objectDataPresent = val.m_objectDataPresent;
    m_objectDatas = val.m_objectDatas;
    m_chartPresent = val.m_chartPresent;
    m_charts = val.m_charts;
    m_hyMePresent = val.m_hyMePresent;
    m_hyMes = val.m_hyMes;
    m_forcastPresent = val.m_forcastPresent;
    m_forcasts = val.m_forcasts;
    m_messagePresent = val.m_messagePresent;
    m_messages = val.m_messages;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
    return *this;
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

void Body::addObjectData(ObjectData val) {

    m_objectDatas.append(val);
}

ObjectData Body::getObjectDataAt(int i) const {

    return m_objectDatas.at(i);
}

int Body::countOfObjectDatas() const {

    return m_objectDatas.count();
}

void Body::addChart(Chart val) {

    m_charts.append(val);
}

Chart Body::getChartAt(int i) const {

    return m_charts.at(i);
}

int Body::countOfCharts() const {

    return m_charts.count();
}

void Body::addHyMe(HyMe val) {

    m_hyMes.append(val);
}

HyMe Body::getHyMeAt(int i) const {

    return m_hyMes.at(i);
}

int Body::countOfHyMes() const {

    return m_hyMes.count();
}

void Body::addForcast(QString val) {

    m_forcasts.append(val);
}

QString Body::getForcastAt(int i) const {

    return m_forcasts.at(i);
}

int Body::countOfForcasts() const {

    return m_forcasts.count();
}

void Body::addMessage(Message val) {

    m_messages.append(val);
}

Message Body::getMessageAt(int i) const {

    return m_messages.at(i);
}

int Body::countOfMessages() const {

    return m_messages.count();
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

QString Body::toXML() {

    QString xml = "<Body";
    if ( hasForcast() ) {
        xml.append(" Forcast=\"" + m_forcast + "\"");
    }
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
    for(int i=0; i < m_objectDatas.count(); i++ ) {
       ObjectData attribute = m_objectDatas.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_charts.count(); i++ ) {
       Chart attribute = m_charts.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_hyMes.count(); i++ ) {
       HyMe attribute = m_hyMes.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_messages.count(); i++ ) {
       Message attribute = m_messages.at(i);
        xml.append( attribute.toXML() );
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
    xml.append( "</Body>\n");
    return xml;
}

QString Body::toString(QString lead) {

    QString str = lead + "Body\n";
    if ( hasForcast() ) {
        str.append( lead + "    Forcast = " + m_forcast + "\n");
    }
    if ( hasLoginRequest() ) {
        str.append( m_loginRequest.toString(lead + "    ") );
    }
    if ( hasLoginResponse() ) {
        str.append( m_loginResponse.toString(lead + "    ") );
    }
    if ( hasLogout() ) {
        str.append( m_logout.toString(lead + "    ") );
    }
    for(int i=0; i < m_objectDatas.count(); i++ ) {
       ObjectData attribute = m_objectDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_charts.count(); i++ ) {
       Chart attribute = m_charts.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_hyMes.count(); i++ ) {
       HyMe attribute = m_hyMes.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_messages.count(); i++ ) {
       Message attribute = m_messages.at(i);
       str.append( attribute.toString(lead + "    ") );
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
    return str;
}

