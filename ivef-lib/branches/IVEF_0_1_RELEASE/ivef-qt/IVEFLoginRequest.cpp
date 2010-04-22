
#include "IVEFLoginRequest.h"

// Constructor
LoginRequest::LoginRequest() {

    // initialize empty string
    m_name = "";
    // initialize empty string
    m_password = "";
    m_encryption = 0;
}

// copy constructor
LoginRequest::LoginRequest(const LoginRequest &val) : QObject() {

    m_name = val.m_name;
    m_password = val.m_password;
    m_encryption = val.m_encryption;
}

// assignement
LoginRequest & LoginRequest::operator=(const LoginRequest &val) {

    m_name = val.m_name;
    m_password = val.m_password;
    m_encryption = val.m_encryption;
    return *this;
}

// String encoder
QString LoginRequest::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for LoginRequest
bool LoginRequest::setName(QString val) {

    m_name = val;
      return true;
}

// getter for LoginRequest
QString LoginRequest::getName() const {

    return m_name;
}

// setter for LoginRequest
bool LoginRequest::setPassword(QString val) {

    m_password = val;
      return true;
}

// getter for LoginRequest
QString LoginRequest::getPassword() const {

    return m_password;
}

// setter for LoginRequest
bool LoginRequest::setEncryption(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return false;
    m_encryption = val;
      return true;
}

// getter for LoginRequest
int LoginRequest::getEncryption() const {

    return m_encryption;
}

// Get XML Representation
QString LoginRequest::toXML() const {

    QString xml = "<LoginRequest";
    xml.append(" Name=\"" + encode (m_name) + "\"");
    xml.append(" Password=\"" + encode (m_password) + "\"");
    xml.append(" Encryption=\"" + QString::number(m_encryption) + "\"");
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString LoginRequest::toString() {

    return toString("");
}

// Get String Representation with a lead
QString LoginRequest::toString(QString lead) {

    QString str = lead + "LoginRequest\n";
    str.append( lead + "    Name = " + m_name + "\n");
    str.append( lead + "    Password = " + m_password + "\n");
    str.append( lead + "    Encryption = " + QString::number(m_encryption) + "\n");
    return str;
}

