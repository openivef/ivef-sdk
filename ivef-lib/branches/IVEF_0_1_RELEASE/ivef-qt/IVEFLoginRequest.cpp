
#include "IVEFLoginRequest.h"

// Constructor
LoginRequest::LoginRequest() {

    // initialize empty string
    m_name = "";
    m_namePresent = false;
    m_namePresent = false;
    m_namePresent = false;
    // initialize empty string
    m_password = "";
    m_passwordPresent = false;
    m_passwordPresent = false;
    m_passwordPresent = false;
    m_encryption = 0;
    m_encryptionPresent = false;
}

// copy constructor
LoginRequest::LoginRequest(const LoginRequest &val) : QObject() {

    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_passwordPresent = val.m_passwordPresent;
    m_password = val.m_password;
    m_encryptionPresent = val.m_encryptionPresent;
    m_encryption = val.m_encryption;
}

// assignement
LoginRequest & LoginRequest::operator=(const LoginRequest &val) {

    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_passwordPresent = val.m_passwordPresent;
    m_password = val.m_password;
    m_encryptionPresent = val.m_encryptionPresent;
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

    m_namePresent = true;
    m_name = val;
      return true;
}

// getter for LoginRequest
QString LoginRequest::getName() const {

    return m_name;
}

// setter for LoginRequest
bool LoginRequest::setPassword(QString val) {

    m_passwordPresent = true;
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
    m_encryptionPresent = true;
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
    QString dataMember;
    // check for presence of required  attribute
    if ( m_namePresent) {
        xml.append(" Name=\"" + m_name + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_passwordPresent) {
        xml.append(" Password=\"" + m_password + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_encryptionPresent) {
        xml.append(" Encryption=\"" + QString::number( m_encryption ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
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
     str.append( lead + "    Encryption = " + QString::number( m_encryption ) + "\n");
    return str;
}

