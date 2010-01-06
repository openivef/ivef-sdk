
#include "IVEFLogout.h"

// Constructor
Logout::Logout() {

}

// copy constructor
Logout::Logout(const Logout &val) : QObject() {

}

// comperator
Logout & Logout::operator=(const Logout &val) {

    return *this;
}

// String encoder
QString Logout::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// Get XML Representation
QString Logout::toXML() {

    QString xml = "<Logout";
    xml.append(">\n");
    xml.append( "</Logout>\n");
    return xml;
}

// Get String Representation
QString Logout::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Logout::toString(QString lead) {

    QString str = lead + "Logout\n";
    return str;
}

