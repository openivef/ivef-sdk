
#include "IVEF2owner.h"

Owner::Owner() {

    m_portOfRegistryPresent = false;
    m_countryFlagPresent = false;
    m_ownerPresent = false;
    m_countryOwnerPresent = false;
    m_companyPresent = false;
    m_homePortPresent = false;
}

Owner::Owner(const Owner &val) : QObject() {

    m_portOfRegistryPresent = val.m_portOfRegistryPresent;
    m_portOfRegistry = val.m_portOfRegistry;
    m_countryFlagPresent = val.m_countryFlagPresent;
    m_countryFlag = val.m_countryFlag;
    m_ownerPresent = val.m_ownerPresent;
    m_owner = val.m_owner;
    m_countryOwnerPresent = val.m_countryOwnerPresent;
    m_countryOwner = val.m_countryOwner;
    m_companyPresent = val.m_companyPresent;
    m_company = val.m_company;
    m_homePortPresent = val.m_homePortPresent;
    m_homePort = val.m_homePort;
}

Owner & Owner::operator=(const Owner &val) {

    m_portOfRegistryPresent = val.m_portOfRegistryPresent;
    m_portOfRegistry = val.m_portOfRegistry;
    m_countryFlagPresent = val.m_countryFlagPresent;
    m_countryFlag = val.m_countryFlag;
    m_ownerPresent = val.m_ownerPresent;
    m_owner = val.m_owner;
    m_countryOwnerPresent = val.m_countryOwnerPresent;
    m_countryOwner = val.m_countryOwner;
    m_companyPresent = val.m_companyPresent;
    m_company = val.m_company;
    m_homePortPresent = val.m_homePortPresent;
    m_homePort = val.m_homePort;
    return *this;
}

void Owner::setPortOfRegistry(QString val) {

    m_portOfRegistryPresent = true;
    m_portOfRegistry = val;
}

QString Owner::getPortOfRegistry() const {

    return m_portOfRegistry;
}

bool Owner::hasPortOfRegistry() {

    return m_portOfRegistryPresent;
}

void Owner::setCountryFlag(QString val) {

    m_countryFlagPresent = true;
    m_countryFlag = val;
}

QString Owner::getCountryFlag() const {

    return m_countryFlag;
}

bool Owner::hasCountryFlag() {

    return m_countryFlagPresent;
}

void Owner::setOwner(QString val) {

    m_ownerPresent = true;
    m_owner = val;
}

QString Owner::getOwner() const {

    return m_owner;
}

bool Owner::hasOwner() {

    return m_ownerPresent;
}

void Owner::setCountryOwner(QString val) {

    m_countryOwnerPresent = true;
    m_countryOwner = val;
}

QString Owner::getCountryOwner() const {

    return m_countryOwner;
}

bool Owner::hasCountryOwner() {

    return m_countryOwnerPresent;
}

void Owner::setCompany(QString val) {

    m_companyPresent = true;
    m_company = val;
}

QString Owner::getCompany() const {

    return m_company;
}

bool Owner::hasCompany() {

    return m_companyPresent;
}

void Owner::setHomePort(QString val) {

    m_homePortPresent = true;
    m_homePort = val;
}

QString Owner::getHomePort() const {

    return m_homePort;
}

bool Owner::hasHomePort() {

    return m_homePortPresent;
}

QString Owner::toXML() {

    QString xml = "<Owner";
    if ( hasPortOfRegistry() ) {
        xml.append(" PortOfRegistry=\"" + m_portOfRegistry + "\"");
    }
    if ( hasCountryFlag() ) {
        xml.append(" CountryFlag=\"" + m_countryFlag + "\"");
    }
    if ( hasOwner() ) {
        xml.append(" Owner=\"" + m_owner + "\"");
    }
    if ( hasCountryOwner() ) {
        xml.append(" CountryOwner=\"" + m_countryOwner + "\"");
    }
    if ( hasCompany() ) {
        xml.append(" Company=\"" + m_company + "\"");
    }
    if ( hasHomePort() ) {
        xml.append(" HomePort=\"" + m_homePort + "\"");
    }
    xml.append(">\n");
    xml.append( "</Owner>\n");
    return xml;
}

QString Owner::toString(QString lead) {

    QString str = lead + "Owner\n";
    if ( hasPortOfRegistry() ) {
        str.append( lead + "    PortOfRegistry = " + m_portOfRegistry + "\n");
    }
    if ( hasCountryFlag() ) {
        str.append( lead + "    CountryFlag = " + m_countryFlag + "\n");
    }
    if ( hasOwner() ) {
        str.append( lead + "    Owner = " + m_owner + "\n");
    }
    if ( hasCountryOwner() ) {
        str.append( lead + "    CountryOwner = " + m_countryOwner + "\n");
    }
    if ( hasCompany() ) {
        str.append( lead + "    Company = " + m_company + "\n");
    }
    if ( hasHomePort() ) {
        str.append( lead + "    HomePort = " + m_homePort + "\n");
    }
    return str;
}

