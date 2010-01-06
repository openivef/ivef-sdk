
#include "IVEFSchema.h"

// Constructor
Schema::Schema() {

}

// copy constructor
Schema::Schema(const Schema &val) : QObject() {

}

// comperator
Schema & Schema::operator=(const Schema &val) {

    return *this;
}

// String encoder
QString Schema::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// getter for Schema
QString Schema::getElementFormDefault() const {

    return "qualified";
}

// getter for Schema
QString Schema::getTargetNamespace() const {

    return "http://www.iala-to-be-confirmed.org/XMLSchema/IVEF/0.2.2";
}

// Get XML Representation
QString Schema::toXML() {

    QString xml = "<Schema";
    xml.append(">\n");
    xml.append( "</Schema>\n");
    return xml;
}

// Get String Representation
QString Schema::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Schema::toString(QString lead) {

    QString str = lead + "Schema\n";
    return str;
}

