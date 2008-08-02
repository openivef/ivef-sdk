
#include "loginresponse.h"

LoginResponse::LoginResponse() {

    m_reasonPresent = false;
}

LoginResponse::LoginResponse(const LoginResponse &val) : QObject() {

    m_msgId = val.getMsgId();
    m_result = val.getResult();
    m_reasonPresent = false;
    m_reason = val.getReason();
}

LoginResponse & LoginResponse::operator=(const LoginResponse &/*val*/) {

    return *this;
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
    xml.append(" MsgId = \"" + m_msgId + "\"");
    xml.append(" Result = \"" + QString(m_result, 10) + "\"");
    if ( hasReason() ) {
        xml.append(" Reason = \"" + m_reason + "\"");
    }
    xml.append(">\n");
    xml.append( "<LoginResponse />\n");
    return xml;
}

