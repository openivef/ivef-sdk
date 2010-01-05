
#include "IVEFServiceRequestResponse.h"

ServiceRequestResponse::ServiceRequestResponse() {

    m_reason = "";
    m_reasonPresent = false;
    m_responseOn = "";
    m_result = 0;
}

ServiceRequestResponse::ServiceRequestResponse(const ServiceRequestResponse &val) : QObject() {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
}

ServiceRequestResponse & ServiceRequestResponse::operator=(const ServiceRequestResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
    return *this;
}

QString ServiceRequestResponse::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void ServiceRequestResponse::setReason(QString val) {

    m_reasonPresent = true;
    m_reason = val;
}

QString ServiceRequestResponse::getReason() const {

    return m_reason;
}

bool ServiceRequestResponse::hasReason() {

    return m_reasonPresent;
}

void ServiceRequestResponse::setResponseOn(QString val) {

    m_responseOn = val;
}

QString ServiceRequestResponse::getResponseOn() const {

    return m_responseOn;
}

void ServiceRequestResponse::setResult(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_result = val;
}

int ServiceRequestResponse::getResult() const {

    return m_result;
}

QString ServiceRequestResponse::toXML() {

    QString xml = "<ServiceRequestResponse";
    if ( hasReason() ) {
        xml.append(" Reason=\"" + encode (m_reason) + "\"");
    }
    xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    xml.append(" Result=\"" + QString::number(m_result) + "\"");
    xml.append(">\n");
    xml.append( "</ServiceRequestResponse>\n");
    return xml;
}

QString ServiceRequestResponse::toString(QString lead) {

    QString str = lead + "ServiceRequestResponse\n";
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + "\n");
    }
    str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
    str.append( lead + "    Result = " + QString::number(m_result) + "\n");
    return str;
}

