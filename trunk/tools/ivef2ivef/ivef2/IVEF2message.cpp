
#include "IVEF2message.h"

Message::Message() {

    m_priorityPresent = false;
    m_destinationPresent = false;
}

Message::Message(const Message &val) : QObject() {

    m_timeStamp = val.m_timeStamp;
    m_priorityPresent = val.m_priorityPresent;
    m_priority = val.m_priority;
    m_origin = val.m_origin;
    m_destinationPresent = val.m_destinationPresent;
    m_destination = val.m_destination;
    m_text = val.m_text;
}

Message & Message::operator=(const Message &val) {

    m_timeStamp = val.m_timeStamp;
    m_priorityPresent = val.m_priorityPresent;
    m_priority = val.m_priority;
    m_origin = val.m_origin;
    m_destinationPresent = val.m_destinationPresent;
    m_destination = val.m_destination;
    m_text = val.m_text;
    return *this;
}

void Message::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

QDateTime Message::getTimeStamp() const {

    return m_timeStamp;
}

void Message::setPriority(int val) {

    m_priorityPresent = true;
    m_priority = val;
}

int Message::getPriority() const {

    return m_priority;
}

bool Message::hasPriority() {

    return m_priorityPresent;
}

void Message::setOrigin(QString val) {

    m_origin = val;
}

QString Message::getOrigin() const {

    return m_origin;
}

void Message::setDestination(QString val) {

    m_destinationPresent = true;
    m_destination = val;
}

QString Message::getDestination() const {

    return m_destination;
}

bool Message::hasDestination() {

    return m_destinationPresent;
}

void Message::setText(QString val) {

    m_text = val;
}

QString Message::getText() const {

    return m_text;
}

QString Message::toXML() {

    QString xml = "<Message";
    xml.append(" TimeStamp=\"" + m_timeStamp.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    if ( hasPriority() ) {
        xml.append(" Priority=\"" + QString::number(m_priority) + "\"");
    }
    xml.append(" Origin=\"" + m_origin + "\"");
    if ( hasDestination() ) {
        xml.append(" Destination=\"" + m_destination + "\"");
    }
    xml.append(" Text=\"" + m_text + "\"");
    xml.append(">\n");
    xml.append( "</Message>\n");
    return xml;
}

QString Message::toString(QString lead) {

    QString str = lead + "Message\n";
    str.append( lead + "    TimeStamp = " + m_timeStamp.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    if ( hasPriority() ) {
        str.append( lead + "    Priority = " + QString::number(m_priority) + "\n");
    }
    str.append( lead + "    Origin = " + m_origin + "\n");
    if ( hasDestination() ) {
        str.append( lead + "    Destination = " + m_destination + "\n");
    }
    str.append( lead + "    Text = " + m_text + "\n");
    return str;
}

