
#include "IVEFServerStatus.h"

ServerStatus::ServerStatus() {

    m_contactIdentity = "";
    m_contactIdentityPresent = false;
    m_details = "";
    m_detailsPresent = false;
    m_status = false;
}

ServerStatus::ServerStatus(const ServerStatus &val) : QObject() {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_status = val.m_status;
}

ServerStatus & ServerStatus::operator=(const ServerStatus &val) {

    m_contactIdentityPresent = val.m_contactIdentityPresent;
    m_contactIdentity = val.m_contactIdentity;
    m_detailsPresent = val.m_detailsPresent;
    m_details = val.m_details;
    m_status = val.m_status;
    return *this;
}

QString ServerStatus::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void ServerStatus::setContactIdentity(QString val) {

    m_contactIdentityPresent = true;
    m_contactIdentity = val;
}

QString ServerStatus::getContactIdentity() const {

    return m_contactIdentity;
}

bool ServerStatus::hasContactIdentity() {

    return m_contactIdentityPresent;
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

void ServerStatus::setStatus(bool val) {

    m_status = val;
}

bool ServerStatus::getStatus() const {

    return m_status;
}

QString ServerStatus::toXML() {

    QString xml = "<ServerStatus";
    if ( hasContactIdentity() ) {
        xml.append(" ContactIdentity=\"" + encode (m_contactIdentity) + "\"");
    }
    if ( hasDetails() ) {
        xml.append(" Details=\"" + encode (m_details) + "\"");
    }
    xml.append(" Status=\"" + QString(m_status ? "yes" : "no" ) + "\"");
    xml.append(">\n");
    xml.append( "</ServerStatus>\n");
    return xml;
}

QString ServerStatus::toString(QString lead) {

    QString str = lead + "ServerStatus\n";
    if ( hasContactIdentity() ) {
        str.append( lead + "    ContactIdentity = " + m_contactIdentity + "\n");
    }
    if ( hasDetails() ) {
        str.append( lead + "    Details = " + m_details + "\n");
    }
    str.append( lead + "    Status = " + QString::number(m_status) + "\n");
    return str;
}

