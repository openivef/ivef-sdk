
#include "pong.h"

Pong::Pong() {

}

Pong::Pong(const Pong &val) : QObject() {

    m_timeStamp = ((Pong)val).getTimeStamp();
    m_msgId = ((Pong)val).getMsgId();
    m_sourceId = ((Pong)val).getSourceId();
}

Pong & Pong::operator=(const Pong &/*val*/) {

    return *this;
}

void Pong::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

QDateTime Pong::getTimeStamp() {

    return m_timeStamp;
}

void Pong::setMsgId(QString val) {

    m_msgId = val;
}

QString Pong::getMsgId() {

    return m_msgId;
}

void Pong::setSourceId(int val) {

    m_sourceId = val;
}

int Pong::getSourceId() {

    return m_sourceId;
}

QString Pong::toXML() {

    QString xml = "<Pong";
    xml.append(" TimeStamp = \"" + m_timeStamp.toString() + "\"");
    xml.append(" MsgId = \"" + m_msgId + "\"");
    xml.append(" SourceId = \"" + QString(m_sourceId, 10) + "\"");
    xml.append(">\n");
    xml.append( "<Pong />\n");
    return xml;
}

