
#include "IVEFschema.h"

Schema::Schema() {

}

Schema::Schema(const Schema &val) : QObject() {

}

Schema & Schema::operator=(const Schema &val) {

    return *this;
}

QString Schema::getElementFormDefault() const {

    return "qualified";
}

QString Schema::getTargetNamespace() const {

    return "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1";
}

QString Schema::toXML() {

    QString xml = "<Schema";
    xml.append(">\n");
    xml.append( "</Schema>\n");
    return xml;
}

QString Schema::toString(QString lead) {

    QString str = lead + "Schema\n";
    return str;
}

