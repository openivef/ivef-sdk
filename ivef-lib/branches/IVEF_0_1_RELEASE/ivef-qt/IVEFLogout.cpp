
#include "IVEFLogout.h"

// Constructor
Logout::Logout() {

}

// copy constructor
Logout::Logout(const Logout &val) : QObject() {

}

// assignement
Logout & Logout::operator=(const Logout &val) {

    return *this;
}

// String encoder
QString Logout::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// Get XML Representation
QString Logout::toXML() const {

    QString xml = "<Logout";
    QString dataMember;
    xml.append("/>\n");
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

