
#include "IVEF2notification.h"

Notification::Notification() {

    m_S57BasePresent = false;
    m_S57UpdatePresent = false;
    m_XMLChartPresent = false;
    m_hyMePresent = false;
    m_messagesPresent = false;
    m_forecastPresent = false;
}

Notification::Notification(const Notification &val) : QObject() {

    m_S57BasePresent = val.m_S57BasePresent;
    m_S57Base = val.m_S57Base;
    m_S57UpdatePresent = val.m_S57UpdatePresent;
    m_S57Update = val.m_S57Update;
    m_XMLChartPresent = val.m_XMLChartPresent;
    m_XMLChart = val.m_XMLChart;
    m_hyMePresent = val.m_hyMePresent;
    m_hyMe = val.m_hyMe;
    m_messagesPresent = val.m_messagesPresent;
    m_messages = val.m_messages;
    m_forecastPresent = val.m_forecastPresent;
    m_forecast = val.m_forecast;
}

Notification & Notification::operator=(const Notification &val) {

    m_S57BasePresent = val.m_S57BasePresent;
    m_S57Base = val.m_S57Base;
    m_S57UpdatePresent = val.m_S57UpdatePresent;
    m_S57Update = val.m_S57Update;
    m_XMLChartPresent = val.m_XMLChartPresent;
    m_XMLChart = val.m_XMLChart;
    m_hyMePresent = val.m_hyMePresent;
    m_hyMe = val.m_hyMe;
    m_messagesPresent = val.m_messagesPresent;
    m_messages = val.m_messages;
    m_forecastPresent = val.m_forecastPresent;
    m_forecast = val.m_forecast;
    return *this;
}

void Notification::setS57Base(bool val) {

    m_S57BasePresent = true;
    m_S57Base = val;
}

bool Notification::getS57Base() const {

    return m_S57Base;
}

bool Notification::hasS57Base() {

    return m_S57BasePresent;
}

void Notification::setS57Update(bool val) {

    m_S57UpdatePresent = true;
    m_S57Update = val;
}

bool Notification::getS57Update() const {

    return m_S57Update;
}

bool Notification::hasS57Update() {

    return m_S57UpdatePresent;
}

void Notification::setXMLChart(bool val) {

    m_XMLChartPresent = true;
    m_XMLChart = val;
}

bool Notification::getXMLChart() const {

    return m_XMLChart;
}

bool Notification::hasXMLChart() {

    return m_XMLChartPresent;
}

void Notification::setHyMe(bool val) {

    m_hyMePresent = true;
    m_hyMe = val;
}

bool Notification::getHyMe() const {

    return m_hyMe;
}

bool Notification::hasHyMe() {

    return m_hyMePresent;
}

void Notification::setMessages(bool val) {

    m_messagesPresent = true;
    m_messages = val;
}

bool Notification::getMessages() const {

    return m_messages;
}

bool Notification::hasMessages() {

    return m_messagesPresent;
}

void Notification::setForecast(bool val) {

    m_forecastPresent = true;
    m_forecast = val;
}

bool Notification::getForecast() const {

    return m_forecast;
}

bool Notification::hasForecast() {

    return m_forecastPresent;
}

QString Notification::toXML() {

    QString xml = "<Notification";
    if ( hasS57Base() ) {
        xml.append(" S57Base=\"" + QString::number(m_S57Base) + "\"");
    }
    if ( hasS57Update() ) {
        xml.append(" S57Update=\"" + QString::number(m_S57Update) + "\"");
    }
    if ( hasXMLChart() ) {
        xml.append(" XMLChart=\"" + QString::number(m_XMLChart) + "\"");
    }
    if ( hasHyMe() ) {
        xml.append(" HyMe=\"" + QString::number(m_hyMe) + "\"");
    }
    if ( hasMessages() ) {
        xml.append(" Messages=\"" + QString::number(m_messages) + "\"");
    }
    if ( hasForecast() ) {
        xml.append(" Forecast=\"" + QString::number(m_forecast) + "\"");
    }
    xml.append(">\n");
    xml.append( "</Notification>\n");
    return xml;
}

QString Notification::toString(QString lead) {

    QString str = lead + "Notification\n";
    if ( hasS57Base() ) {
        str.append( lead + "    S57Base = " + QString::number(m_S57Base) + "\n");
    }
    if ( hasS57Update() ) {
        str.append( lead + "    S57Update = " + QString::number(m_S57Update) + "\n");
    }
    if ( hasXMLChart() ) {
        str.append( lead + "    XMLChart = " + QString::number(m_XMLChart) + "\n");
    }
    if ( hasHyMe() ) {
        str.append( lead + "    HyMe = " + QString::number(m_hyMe) + "\n");
    }
    if ( hasMessages() ) {
        str.append( lead + "    Messages = " + QString::number(m_messages) + "\n");
    }
    if ( hasForecast() ) {
        str.append( lead + "    Forecast = " + QString::number(m_forecast) + "\n");
    }
    return str;
}

