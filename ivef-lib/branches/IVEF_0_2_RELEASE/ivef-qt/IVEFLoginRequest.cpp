
#include "IVEFLoginRequest.h"

// Constructor
LoginRequest::LoginRequest() {

    m_encryption = 0;
    m_encryptionPresent = false;
    // initialize empty string
    m_name = "";
    m_namePresent = false;
    // initialize empty string
    m_password = "";
    m_passwordPresent = false;
}

// copy constructor
LoginRequest::LoginRequest(const LoginRequest &val) : QObject() {

    m_encryptionPresent = val.m_encryptionPresent;
    m_encryption = val.m_encryption;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_passwordPresent = val.m_passwordPresent;
    m_password = val.m_password;
}

// compare
bool LoginRequest::operator==(const LoginRequest &val) {

    if (!(m_encryptionPresent == val.m_encryptionPresent)) return false;
    if (!(m_encryption == val.m_encryption)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    if (!(m_passwordPresent == val.m_passwordPresent)) return false;
    if (!(m_password == val.m_password)) return false;
    return true;
}

// assignement
LoginRequest & LoginRequest::operator=(const LoginRequest &val) {

    m_encryptionPresent = val.m_encryptionPresent;
    m_encryption = val.m_encryption;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_passwordPresent = val.m_passwordPresent;
    m_password = val.m_password;
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

// setter for LoginRequest
bool LoginRequest::setName(QString val) {
    // check if the new value is within bounds 

    if (val.length() > 256)
        return false;
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
    // check if the new value is within bounds 

    if (val.length() > 256)
        return false;
    m_passwordPresent = true;
    m_password = val;
      return true;
}

// getter for LoginRequest
QString LoginRequest::getPassword() const {

    return m_password;
}

// Get XML Representation
QString LoginRequest::toXML() const {

    QString xml = "<LoginRequest";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_encryptionPresent) {
        xml.append(" Encryption=\"" + QString::number( m_encryption ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_namePresent) {
        xml.append(" Name=\"" + encode (m_name) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_passwordPresent) {
        xml.append(" Password=\"" + encode (m_password) + "\"");
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
     str.append( lead + "    Encryption = " + QString::number( m_encryption ) + "\n");
     str.append( lead + "    Name = " + m_name + "\n");
     str.append( lead + "    Password = " + m_password + "\n");
    return str;
}

