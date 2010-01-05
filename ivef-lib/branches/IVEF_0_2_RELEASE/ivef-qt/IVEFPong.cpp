
#include "IVEFPong.h"

Pong::Pong() {

    m_responseOn = "";
    m_sourceId = 0;
    m_timeStamp = QDateTime();
}

Pong::Pong(const Pong &val) : QObject() {

    m_responseOn = val.m_responseOn;
    m_sourceId = val.m_sourceId;
    m_timeStamp = val.m_timeStamp;
}

Pong & Pong::operator=(const Pong &val) {

    m_responseOn = val.m_responseOn;
    m_sourceId = val.m_sourceId;
    m_timeStamp = val.m_timeStamp;
    return *this;
}

QString Pong::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Pong::setResponseOn(QString val) {

    m_responseOn = val;
}

QString Pong::getResponseOn() const {

    return m_responseOn;
}

void Pong::setSourceId(int val) {

    m_sourceId = val;
}

int Pong::getSourceId() const {

    return m_sourceId;
}

void Pong::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

QString Pong::toXML() {

    QString xml = "<Pong";
    xml.append(" ResponseOn=\"" + encode (m_responseOn) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\"");
    xml.append(">\n");
    xml.append( "</Pong>\n");
    return xml;
}

QString Pong::toString(QString lead) {

    QString str = lead + "Pong\n";
    str.append( lead + "    ResponseOn = " + m_responseOn + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-dd'T'HH:mm:ss.zzzZ") + "\n");
    return str;
}

