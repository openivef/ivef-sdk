
#include "serverstatus.h"

ServerStatus::ServerStatus() {

    m_detailsPresent = false;
}

ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_status = ((ServerStatus)val).getStatus();
    m_detailsPresent = false;
    m_details = ((ServerStatus)val).getDetails();
}

ServerStatus & ServerStatus::operator=(const ServerStatus &/*val*/) {

    return *this;
}

void ServerStatus::setStatus(QString val) {

    if ( ( val != "queuefull" ) &&
         ( val != "ok" ) )
        return;
    m_status = val;
}

QString ServerStatus::getStatus() {

    return m_status;
}

void ServerStatus::setDetails(QString val) {

    m_detailsPresent = true;
    m_details = val;
}

QString ServerStatus::getDetails() {

    return m_details;
}

bool ServerStatus::hasDetails() {

    return m_detailsPresent;
}

QString ServerStatus::toXML() {

    QString xml = "<ServerStatus";
    xml.append(" Status = \"" + m_status + "\"");
    if ( hasDetails() ) {
        xml.append(" Details = \"" + m_details + "\"");
    }
    xml.append(">\n");
    xml.append( "<ServerStatus />\n");
    return xml;
}

