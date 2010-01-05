
#include "IVEFSchema.h"

Schema::Schema() {

}

Schema::Schema(const Schema &val) : QObject() {

}

Schema & Schema::operator=(const Schema &val) {

    return *this;
}

QString Schema::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

QString Schema::getElementFormDefault() const {

    return "qualified";
}

QString Schema::getTargetNamespace() const {

    return "http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.2";
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

