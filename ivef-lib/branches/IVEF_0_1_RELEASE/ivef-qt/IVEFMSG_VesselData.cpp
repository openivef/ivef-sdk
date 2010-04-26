
#include "IVEFMSG_VesselData.h"

// Constructor
MSG_VesselData::MSG_VesselData() {

    m_headerPresent = false;
    m_bodyPresent = false;
}

// copy constructor
MSG_VesselData::MSG_VesselData(const MSG_VesselData &val) : QObject() {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
}

// assignement
MSG_VesselData & MSG_VesselData::operator=(const MSG_VesselData &val) {

    m_headerPresent = val.m_headerPresent;
    m_header = val.m_header;
    m_bodyPresent = val.m_bodyPresent;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_VesselData::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_VesselData
bool MSG_VesselData::setHeader(Header val) {

    m_headerPresent = true;
    m_header = val;
      return true;
}

// getter for MSG_VesselData
Header MSG_VesselData::getHeader() const {

    return m_header;
}

// setter for MSG_VesselData
bool MSG_VesselData::setBody(Body val) {

    m_bodyPresent = true;
    m_body = val;
      return true;
}

// getter for MSG_VesselData
Body MSG_VesselData::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_VesselData::toXML() const {

    QString xml = "<MSG_VesselData";
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
    xml.append( "</MSG_VesselData>\n");
    return xml;
}

// Get String Representation
QString MSG_VesselData::toString() {

    return toString("");
}

// Get String Representation with a lead
QString MSG_VesselData::toString(QString lead) {

    QString str = lead + "MSG_VesselData\n";
    str.append( m_header.toString(lead + "    ") );
    str.append( m_body.toString(lead + "    ") );
    return str;
}

