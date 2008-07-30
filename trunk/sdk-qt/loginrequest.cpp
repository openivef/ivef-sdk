
#include "loginrequest.h"

LoginRequest::LoginRequest() {

}

LoginRequest::LoginRequest(const LoginRequest &val) : QObject() {

    m_name = ((LoginRequest)val).getName();
    m_password = ((LoginRequest)val).getPassword();
    m_encryption = ((LoginRequest)val).getEncryption();
}

LoginRequest & LoginRequest::operator=(const LoginRequest &/*val*/) {

    return *this;
}

void LoginRequest::setName(QString val) {

    m_name = val;
}

QString LoginRequest::getName() {

    return m_name;
}

void LoginRequest::setPassword(QString val) {

    m_password = val;
}

QString LoginRequest::getPassword() {

    return m_password;
}

void LoginRequest::setEncryption(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_encryption = val;
}

int LoginRequest::getEncryption() {

    return m_encryption;
}

QString LoginRequest::toXML() {

    QString xml = "<LoginRequest";
    xml.append(" Name = \"" + m_name + "\"");
    xml.append(" Password = \"" + m_password + "\"");
    xml.append(" Encryption = \"" + QString(m_encryption, 10) + "\"");
    xml.append(">\n");
    xml.append( "<LoginRequest />\n");
    return xml;
}

