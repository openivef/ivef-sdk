
#include "IVEF2servicerequestresponse.h"

ServiceRequestResponse::ServiceRequestResponse() {

    m_reasonPresent = false;
}

ServiceRequestResponse::ServiceRequestResponse(const ServiceRequestResponse &val) : QObject() {

    m_msgId = val.m_msgId;
    m_result = val.m_result;
    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
}

ServiceRequestResponse & ServiceRequestResponse::operator=(const ServiceRequestResponse &val) {

    m_msgId = val.m_msgId;
    m_result = val.m_result;
    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    return *this;
}

void ServiceRequestResponse::setMsgId(QString val) {

    m_msgId = val;
}

QString ServiceRequestResponse::getMsgId() const {

    return m_msgId;
}

void ServiceRequestResponse::setResult(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_result = val;
}

int ServiceRequestResponse::getResult() const {

    return m_result;
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

QString ServiceRequestResponse::toXML() {

    QString xml = "<ServiceRequestResponse";
    xml.append(" MsgId=\"" + m_msgId + "\"");
    xml.append(" Result=\"" + QString::number(m_result) + "\"");
    if ( hasReason() ) {
        xml.append(" Reason=\"" + m_reason + "\"");
    }
    xml.append(">\n");
    xml.append( "</ServiceRequestResponse>\n");
    return xml;
}

QString ServiceRequestResponse::toString(QString lead) {

    QString str = lead + "ServiceRequestResponse\n";
    str.append( lead + "    MsgId = " + m_msgId + "\n");
    str.append( lead + "    Result = " + QString::number(m_result) + "\n");
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + "\n");
    }
    return str;
}

