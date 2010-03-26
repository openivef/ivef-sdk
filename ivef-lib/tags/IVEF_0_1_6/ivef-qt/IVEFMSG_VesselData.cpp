
#include "IVEFMSG_VesselData.h"

// Constructor
MSG_VesselData::MSG_VesselData() {

}

// copy constructor
MSG_VesselData::MSG_VesselData(const MSG_VesselData &val) : QObject() {

    m_header = val.m_header;
    m_body = val.m_body;
}

// assignement
MSG_VesselData & MSG_VesselData::operator=(const MSG_VesselData &val) {

    m_header = val.m_header;
    m_body = val.m_body;
    return *this;
}

// String encoder
QString MSG_VesselData::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for MSG_VesselData
void MSG_VesselData::setHeader(Header val) {

    m_header = val;
}

// getter for MSG_VesselData
Header MSG_VesselData::getHeader() const {

    return m_header;
}

// setter for MSG_VesselData
void MSG_VesselData::setBody(Body val) {

    m_body = val;
}

// getter for MSG_VesselData
Body MSG_VesselData::getBody() const {

    return m_body;
}

// Get XML Representation
QString MSG_VesselData::toXML() {

    QString xml = "<MSG_VesselData";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
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

