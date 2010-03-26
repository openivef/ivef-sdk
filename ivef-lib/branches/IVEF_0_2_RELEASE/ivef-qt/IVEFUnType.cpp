
#include "IVEFUnType.h"

// Constructor
UnType::UnType() {

    m_codeA = 0;
    m_codeB = 0;
    m_mode = 0;
}

// copy constructor
UnType::UnType(const UnType &val) : QObject() {

    m_codeA = val.m_codeA;
    m_codeB = val.m_codeB;
    m_mode = val.m_mode;
}

// assignement
UnType & UnType::operator=(const UnType &val) {

    m_codeA = val.m_codeA;
    m_codeB = val.m_codeB;
    m_mode = val.m_mode;
    return *this;
}

// String encoder
QString UnType::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for UnType
void UnType::setCodeA(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 138)
        return;
    m_codeA = val;
}

// getter for UnType
int UnType::getCodeA() const {

    return m_codeA;
}

// setter for UnType
void UnType::setCodeB(int val) {
    // check if the new value is within bounds 

    if (val < 0)
        return;    // check if the new value is within bounds 

    if (val > 9)
        return;
    m_codeB = val;
}

// getter for UnType
int UnType::getCodeB() const {

    return m_codeB;
}

// setter for UnType
void UnType::setMode(int val) {
// check if the new value is an approved value 

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return;
    m_mode = val;
}

// getter for UnType
int UnType::getMode() const {

    return m_mode;
}

// Get XML Representation
QString UnType::toXML() {

    QString xml = "<UnType";
    xml.append(" CodeA=\"" + QString::number(m_codeA) + "\"");
    xml.append(" CodeB=\"" + QString::number(m_codeB) + "\"");
    xml.append(" Mode=\"" + QString::number(m_mode) + "\"");
    xml.append(">\n");
    xml.append( "</UnType>\n");
    return xml;
}

// Get String Representation
QString UnType::toString() {

    return toString("");
}

// Get String Representation with a lead
QString UnType::toString(QString lead) {

    QString str = lead + "UnType\n";
    str.append( lead + "    CodeA = " + QString::number(m_codeA) + "\n");
    str.append( lead + "    CodeB = " + QString::number(m_codeB) + "\n");
    str.append( lead + "    Mode = " + QString::number(m_mode) + "\n");
    return str;
}

