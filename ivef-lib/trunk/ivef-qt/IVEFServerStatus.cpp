
#include "IVEFServerStatus.h"

ServerStatus::ServerStatus() {

    m_status = "";
    m_details = "";
    m_detailsPresent = false;
}

ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_status = val.m_status;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
}

ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_status = val.m_status;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    return *this;
}

QString ServerStatus::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void ServerStatus::setStatus(QString val) {

    if ( ( val != "queuefull" ) &&
         ( val != "ok" ) )
        return;
    m_status = val;
}

QString ServerStatus::getStatus() const {

    return m_status;
}

void ServerStatus::setDetails(QString val) {

    m_detailsPresent = true;
    m_details = val;
}

QString ServerStatus::getDetails() const {

    return m_details;
}

bool ServerStatus::hasDetails() {

    return m_detailsPresent;
}

QString ServerStatus::toXML() {

    QString xml = "<ServerStatus";
    xml.append(" Status=\"" + encode (m_status) + "\"");
    if ( hasDetails() ) {
        xml.append(" Details=\"" + encode (m_details) + "\"");
    }
    xml.append(">\n");
    xml.append( "</ServerStatus>\n");
    return xml;
}

QString ServerStatus::toString(QString lead) {

    QString str = lead + "ServerStatus\n";
    str.append( lead + "    Status = " + m_status + "\n");
    if ( hasDetails() ) {
        str.append( lead + "    Details = " + m_details + "\n");
    }
    return str;
}

