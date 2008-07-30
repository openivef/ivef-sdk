
#include "ping.h"

Ping::Ping() {

}

Ping::Ping(const Ping &val) : QObject() {

    m_timeStamp = ((Ping)val).getTimeStamp();
}

Ping & Ping::operator=(const Ping &/*val*/) {

    return *this;
}

void Ping::setTimeStamp(QDateTime val) {

    m_timeStamp = val;
}

QDateTime Ping::getTimeStamp() {

    return m_timeStamp;
}

QString Ping::toXML() {

    QString xml = "<Ping";
    xml.append(" TimeStamp = \"" + m_timeStamp.toString() + "\"");
    xml.append(">\n");
    xml.append( "<Ping />\n");
    return xml;
}

