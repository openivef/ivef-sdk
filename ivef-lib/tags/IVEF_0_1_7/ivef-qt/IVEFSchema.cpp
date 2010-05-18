
#include "IVEFSchema.h"

// Constructor
Schema::Schema() {

}

// copy constructor
Schema::Schema(const Schema &val) : QObject() {

}

// assignement
Schema & Schema::operator=(const Schema &val) {

    return *this;
}

// String encoder
QString Schema::encode( QString str) const {

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

    return "urn:http://www.ivef.org/XMLSchema/IVEF/0.1.6";
}

// Get XML Representation
QString Schema::toXML() const {

    QString xml = "<Schema";
    QString dataMember;
    xml.append("/>\n");
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

