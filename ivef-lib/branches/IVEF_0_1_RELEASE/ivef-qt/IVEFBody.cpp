
#include "IVEFBody.h"

// Constructor
Body::Body() {

    m_loginRequestPresent = false;
    m_loginResponsePresent = false;
    m_logoutPresent = false;
    m_pingPresent = false;
    m_pongPresent = false;
    m_serverStatusPresent = false;
    m_serviceRequestPresent = false;
}

// copy constructor
Body::Body(const Body &val) : QObject() {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
    m_vesselDataPresent = val.m_vesselDataPresent;
    m_vesselDatas = val.m_vesselDatas;
}

// assignement
Body & Body::operator=(const Body &val) {

    m_loginRequestPresent = val.m_loginRequestPresent;
    m_loginRequest = val.m_loginRequest;
    m_loginResponsePresent = val.m_loginResponsePresent;
    m_loginResponse = val.m_loginResponse;
    m_logoutPresent = val.m_logoutPresent;
    m_logout = val.m_logout;
    m_pingPresent = val.m_pingPresent;
    m_ping = val.m_ping;
    m_pongPresent = val.m_pongPresent;
    m_pong = val.m_pong;
    m_serverStatusPresent = val.m_serverStatusPresent;
    m_serverStatus = val.m_serverStatus;
    m_serviceRequestPresent = val.m_serviceRequestPresent;
    m_serviceRequest = val.m_serviceRequest;
    m_vesselDataPresent = val.m_vesselDataPresent;
    m_vesselDatas = val.m_vesselDatas;
    return *this;
}

// String encoder
QString Body::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Body
bool Body::setLoginRequest(LoginRequest val) {

    m_loginRequestPresent = true;
    m_loginRequest = val;
      return true;
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
bool Body::setLoginResponse(LoginResponse val) {

    m_loginResponsePresent = true;
    m_loginResponse = val;
      return true;
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
bool Body::setLogout(Logout val) {

    m_logoutPresent = true;
    m_logout = val;
      return true;
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
bool Body::setPing(Ping val) {

    m_pingPresent = true;
    m_ping = val;
      return true;
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
bool Body::setPong(Pong val) {

    m_pongPresent = true;
    m_pong = val;
      return true;
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
bool Body::setServerStatus(ServerStatus val) {

    m_serverStatusPresent = true;
    m_serverStatus = val;
      return true;
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
bool Body::setServiceRequest(ServiceRequest val) {

    m_serviceRequestPresent = true;
    m_serviceRequest = val;
      return true;
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
bool Body::addVesselData(VesselData val) {

   m_vesselDatas.append(val);
      return true;
}

// getter for Body
VesselData Body::getVesselDataAt(int i) const {

    return m_vesselDatas.at(i);
}

// count for Body
int Body::countOfVesselDatas() const {

    return m_vesselDatas.count();
}

// Get XML Representation
QString Body::toXML() const {

    QString xml = "<Body";
    QString dataMember;
    xml.append(">\n");
    // add optional data if available
    if ( hasLoginRequest() ) {
        dataMember = m_loginRequest.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasLoginResponse() ) {
        dataMember = m_loginResponse.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasLogout() ) {
        dataMember = m_logout.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasPing() ) {
        dataMember = m_ping.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasPong() ) {
        dataMember = m_pong.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasServerStatus() ) {
        dataMember = m_serverStatus.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add optional data if available
    if ( hasServiceRequest() ) {
        dataMember = m_serviceRequest.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    }
    // add all included data
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
        VesselData attribute = m_vesselDatas.at(i);
        dataMember = attribute.toXML();
        if (dataMember != NULL) {
           xml.append( attribute.toXML() );
        } else {
            return NULL;
        }
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
    // add all included data
    for(int i=0; i < m_vesselDatas.count(); i++ ) {
       VesselData attribute = m_vesselDatas.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

