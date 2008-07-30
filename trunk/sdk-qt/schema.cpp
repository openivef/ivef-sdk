
#include "schema.h"

Schema::Schema() {

}

Schema::Schema(const Schema &val) : QObject() {

}

Schema & Schema::operator=(const Schema &/*val*/) {

    return *this;
}

QString Schema::getElementFormDefault() {

    return "qualified";
}

QString Schema::getTargetNamespace() {

    return "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1";
}

QString Schema::toXML() {

    QString xml = "<Schema";
    xml.append(">\n");
    xml.append( "<Schema />\n");
    return xml;
}

