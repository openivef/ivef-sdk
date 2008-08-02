
#include "msg_vesseldata.h"

MSG_VesselData::MSG_VesselData() {

}

MSG_VesselData::MSG_VesselData(const MSG_VesselData &val) : QObject() {

    m_header = val.getHeader();
    m_body = val.getBody();
}

MSG_VesselData & MSG_VesselData::operator=(const MSG_VesselData &/*val*/) {

    return *this;
}

void MSG_VesselData::setHeader(Header val) {

    m_header = val;
}

Header MSG_VesselData::getHeader() const {

    return m_header;
}

void MSG_VesselData::setBody(Body val) {

    m_body = val;
}

Body MSG_VesselData::getBody() const {

    return m_body;
}

QString MSG_VesselData::toXML() {

    QString xml = "<MSG_VesselData";
    xml.append(">\n");
    xml.append( m_header.toXML() );
    xml.append( m_body.toXML() );
    xml.append( "<MSG_VesselData />\n");
    return xml;
}

