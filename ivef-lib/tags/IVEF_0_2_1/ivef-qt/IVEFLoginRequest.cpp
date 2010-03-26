
#include "IVEFLoginRequest.h"

// Constructor
LoginRequest::LoginRequest() {

    m_encryption = 0;
    // initialize empty string
    m_name = "";
    // initialize empty string
    m_password = "";
}

// copy constructor
LoginRequest::LoginRequest(const LoginRequest &val) : QObject() {

    m_encryption = val.m_encryption;
    m_name = val.m_name;
    m_password = val.m_password;
}

// assignement
LoginRequest & LoginRequest::operator=(const LoginRequest &val) {

    m_encryption = val.m_encryption;
    m_name = val.m_name;
    m_password = val.m_password;
    return *this;
}

// String encoder
QString LoginRequest::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for LoginRequest
void LoginRequest::setEncryption(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_encryption = val;
}

// getter for LoginRequest
int LoginRequest::getEncryption() const {

    return m_encryption;
}

// setter for LoginRequest
void LoginRequest::setName(QString val) {

    m_name = val;
}

// getter for LoginRequest
QString LoginRequest::getName() const {

    return m_name;
}

// setter for LoginRequest
void LoginRequest::setPassword(QString val) {

    m_password = val;
}

// getter for LoginRequest
QString LoginRequest::getPassword() const {

    return m_password;
}

// Get XML Representation
QString LoginRequest::toXML() {

    QString xml = "<LoginRequest";
    xml.append(" Encryption=\"" + QString::number(m_encryption) + "\"");
    xml.append(" Name=\"" + encode (m_name) + "\"");
    xml.append(" Password=\"" + encode (m_password) + "\"");
    xml.append(">\n");
    xml.append( "</LoginRequest>\n");
    return xml;
}

// Get String Representation
QString LoginRequest::toString() {

    return toString("");
}

// Get String Representation with a lead
QString LoginRequest::toString(QString lead) {

    QString str = lead + "LoginRequest\n";
    str.append( lead + "    Encryption = " + QString::number(m_encryption) + "\n");
    str.append( lead + "    Name = " + m_name + "\n");
    str.append( lead + "    Password = " + m_password + "\n");
    return str;
}

