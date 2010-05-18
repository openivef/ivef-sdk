
#include "IVEFMSG_IVEF.h"

// Constructor
MSG_IVEF::MSG_IVEF() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_IVEF::MSG_IVEF(const MSG_IVEF &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// assignement
MSG_IVEF & MSG_IVEF::operator=(const MSG_IVEF &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_IVEF::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_IVEF
bool MSG_IVEF::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_IVEF
Header MSG_IVEF::getHeader() const {

    return m_header;
}

// setter for MSG_IVEF
bool MSG_IVEF::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_IVEF
Body MSG_IVEF::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_IVEF::toXML() const {

    QString xml = "<MSG_IVEF";
    QString dataMember;
    xml.append(">\n");
    // check for presence of required data member
    if ( m_headerPresent) {
        dataMember = m_header.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
    // check for presence of required data member
    if ( m_bodyPresent) {
        dataMember = m_body.toXML();
        if (dataMember != NULL) {
            xml.append( dataMember );
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
    xml.append( "</MSG_IVEF>\n");
    return xml;
}

// Get String Representation
QString MSG_IVEF::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_IVEF::toString(QString lead) {

    QString str = lead + "MSG_IVEF\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

