
#include "IVEFLoginResponse.h"

LoginResponse::LoginResponse() {

    m_msgId = "";
    m_result = 0;
    m_reason = "";
    m_reasonPresent = false;
}

LoginResponse::LoginResponse(const LoginResponse &val) : QObject() {

    m_msgId = val.m_msgId;
    m_result = val.m_result;
    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
}

LoginResponse & LoginResponse::operator=(const LoginResponse &val) {

    m_msgId = val.m_msgId;
    m_result = val.m_result;
    m_reasonPresent = val.m_reasonPresent;
    m_reason = val.m_reason;
    return *this;
}

QString LoginResponse::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void LoginResponse::setMsgId(QString val) {

    m_msgId = val;
}

QString LoginResponse::getMsgId() const {

    return m_msgId;
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

QString LoginResponse::toXML() {

    QString xml = "<LoginResponse";
    xml.append(" MsgId=\"" + encode (m_msgId) + "\"");
    xml.append(" Result=\"" + QString::number(m_result) + "\"");
    if ( hasReason() ) {
        xml.append(" Reason=\"" + encode (m_reason) + "\"");
    }
    xml.append(">\n");
    xml.append( "</LoginResponse>\n");
    return xml;
}

QString LoginResponse::toString(QString lead) {

    QString str = lead + "LoginResponse\n";
    str.append( lead + "    MsgId = " + m_msgId + "\n");
    str.append( lead + "    Result = " + QString::number(m_result) + "\n");
    if ( hasReason() ) {
        str.append( lead + "    Reason = " + m_reason + "\n");
    }
    return str;
}

