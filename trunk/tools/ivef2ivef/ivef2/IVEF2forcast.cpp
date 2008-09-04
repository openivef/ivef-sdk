
#include "IVEF2forcast.h"

Forcast::Forcast() {

}

Forcast::Forcast(const Forcast &val) : QObject() {

}

Forcast & Forcast::operator=(const Forcast &val) {

    return *this;
}

QString Forcast::toXML() {

    QString xml = "<Forcast";
    xml.append(">\n");
    xml.append( "</Forcast>\n");
    return xml;
}

QString Forcast::toString(QString lead) {

    QString str = lead + "Forcast\n";
    return str;
}

