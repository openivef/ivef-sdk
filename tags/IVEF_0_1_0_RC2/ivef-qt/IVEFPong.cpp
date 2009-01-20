
#include "IVEFPong.h"

Pong::Pong() {

}

Pong::Pong(const Pong &val) : QObject() {

    m_timeStamp = val.m_timeStamp;
    m_msgId = val.m_msgId;
    m_sourceId = val.m_sourceId;
}

Pong & Pong::operator=(const Pong &val) {

    m_timeStamp = val.m_timeStamp;
    m_msgId = val.m_msgId;
    m_sourceId = val.m_sourceId;
    return *this;
}

void Pong::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

QDateTime Pong::getTimeStamp() const {

    return m_timeStamp;
}

void Pong::setMsgId(QString val) {

    m_msgId = val;
}

QString Pong::getMsgId() const {

    return m_msgId;
}

void Pong::setSourceId(int val) {

    m_sourceId = val;
}

int Pong::getSourceId() const {

    return m_sourceId;
}

QString Pong::toXML() {

    QString xml = "<Pong";
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    xml.append(" MsgId=\"" + m_msgId + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    xml.append(">\n");
    xml.append( "</Pong>\n");
    return xml;
}

QString Pong::toString(QString lead) {

    QString str = lead + "Pong\n";
    str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    str.append( lead + "    MsgId = " + m_msgId + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    return str;
}

