
#include "IVEFLoginRequest.h"

LoginRequest::LoginRequest() {

    m_encryption = 0;
    m_name = "";
    m_password = "";
}

LoginRequest::LoginRequest(const LoginRequest &val) : QObject() {

    m_encryption = val.m_encryption;
    m_name = val.m_name;
    m_password = val.m_password;
}

LoginRequest & LoginRequest::operator=(const LoginRequest &val) {

    m_encryption = val.m_encryption;
    m_name = val.m_name;
    m_password = val.m_password;
    return *this;
}

QString LoginRequest::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void LoginRequest::setEncryption(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_encryption = val;
}

int LoginRequest::getEncryption() const {

    return m_encryption;
}

void LoginRequest::setName(QString val) {

    m_name = val;
}

QString LoginRequest::getName() const {

    return m_name;
}

void LoginRequest::setPassword(QString val) {

    m_password = val;
}

QString LoginRequest::getPassword() const {

    return m_password;
}

QString LoginRequest::toXML() {

    QString xml = "<LoginRequest";
    xml.append(" Encryption=\"" + QString::number(m_encryption) + "\"");
    xml.append(" Name=\"" + encode (m_name) + "\"");
    xml.append(" Password=\"" + encode (m_password) + "\"");
    xml.append(">\n");
    xml.append( "</LoginRequest>\n");
    return xml;
}

QString LoginRequest::toString(QString lead) {

    QString str = lead + "LoginRequest\n";
    str.append( lead + "    Encryption = " + QString::number(m_encryption) + "\n");
    str.append( lead + "    Name = " + m_name + "\n");
    str.append( lead + "    Password = " + m_password + "\n");
    return str;
}

