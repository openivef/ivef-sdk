
#include "IVEFUnType.h"

// Constructor
UnType::UnType() {

    m_codeA = 0;
    m_codeAPresent = false;
    m_codeB = 0;
    m_codeBPresent = false;
    m_mode = 0;
    m_modePresent = false;
}

// copy constructor
UnType::UnType(const UnType &val) : QObject() {

    m_codeAPresent = val.m_codeAPresent;
    m_codeA = val.m_codeA;
    m_codeBPresent = val.m_codeBPresent;
    m_codeB = val.m_codeB;
    m_modePresent = val.m_modePresent;
    m_mode = val.m_mode;
}

// assignement
UnType & UnType::operator=(const UnType &val) {

    m_codeAPresent = val.m_codeAPresent;
    m_codeA = val.m_codeA;
    m_codeBPresent = val.m_codeBPresent;
    m_codeB = val.m_codeB;
    m_modePresent = val.m_modePresent;
    m_mode = val.m_mode;
    return *this;
}

// String encoder
QString UnType::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for UnType
bool UnType::setCodeA(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;    // check if the new value is within bounds 

    if (val > 138)
        return false;
    m_codeAPresent = true;
    m_codeA = val;
      return true;
}

// getter for UnType
int UnType::getCodeA() const {

    return m_codeA;
}

// setter for UnType
bool UnType::setCodeB(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return false;    // check if the new value is within bounds 

    if (val > 9)
        return false;
    m_codeBPresent = true;
    m_codeB = val;
      return true;
}

// getter for UnType
int UnType::getCodeB() const {

    return m_codeB;
}

// setter for UnType
bool UnType::setMode(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return false;
    m_modePresent = true;
    m_mode = val;
      return true;
}

// getter for UnType
int UnType::getMode() const {

    return m_mode;
}

// Get XML Representation
QString UnType::toXML() const {

    QString xml = "<UnType";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_codeAPresent) {
        xml.append(" CodeA=\"" + QString::number( m_codeA ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_codeBPresent) {
        xml.append(" CodeB=\"" + QString::number( m_codeB ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    // check for presence of required  attribute
    if ( m_modePresent) {
        xml.append(" Mode=\"" + QString::number( m_mode ) + "\"");
    } else { // required attribute not present
        return NULL;
    }
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString UnType::toString() {

    return toString("");
}

// Get String Representation with a lead
QString UnType::toString(QString lead) {

    QString str = lead + "UnType\n";
     str.append( lead + "    CodeA = " + QString::number( m_codeA ) + "\n");
     str.append( lead + "    CodeB = " + QString::number( m_codeB ) + "\n");
     str.append( lead + "    Mode = " + QString::number( m_mode ) + "\n");
    return str;
}

