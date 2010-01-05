
#include "IVEFLoginResponse.h"

LoginResponse::LoginResponse() {

    m_reason = "";
    m_reasonPresent = false;
    m_responseOn = "";
    m_result = 0;
}

LoginResponse::LoginResponse(const LoginResponse &val) : QObject() {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
}

LoginResponse & LoginResponse::operator=(const LoginResponse &val) {

    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    m_responseOn = val.m_responseOn;
    m_result = val.m_result;
    return *this;
}

QString LoginResponse::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void LoginResponse::setReason(QString val) {

    m_reasonPresent = true;
    m_reason = val;
}

QString LoginResponse::getReason() const {

    return m_reason;
}

bool LoginResponse::hasReason() {

    return m_reasonPresent;
}

void LoginResponse::setResponseOn(QString val) {

    m_responseOn = val;
}

QString LoginResponse::getResponseOn() const {

    return m_responseOn;
}

void LoginResponse::setResult(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_result = val;
}

int LoginResponse::getResult() const {

    return m_result;
}

QString LoginResponse::toXML() {

    QString xml = "<LoginResponse";
    if ( hasReason() ) {
        xml.append(" Reason=\"" + encode (m_reason) + "\"");
    }
    xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    xml.append(" Result=\"" + QString::number(m_result) + "\"");
    xml.append(">\n");
    xml.append( "</LoginResponse>\n");
    return xml;
}

QString LoginResponse::toString(QString lead) {

    QString str = lead + "LoginResponse\n";
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + "\n");
    }
    str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
    str.append( lead + "    Result = " + QString::number(m_result) + "\n");
    return str;
}

