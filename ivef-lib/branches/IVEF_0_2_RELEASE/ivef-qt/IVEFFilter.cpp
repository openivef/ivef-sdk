
#include "IVEFFilter.h"

// Constructor
Filter::Filter() {

    // initialize empty string
    m_predicate = "";
}

// copy constructor
Filter::Filter(const Filter &val) : QObject() {

    m_predicate = val.m_predicate;
}

// assignement
Filter & Filter::operator=(const Filter &val) {

    m_predicate = val.m_predicate;
    return *this;
}

// String encoder
QString Filter::encode( QString str) {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Filter
void Filter::setPredicate(QString val) {

    m_predicate = val;
}

// getter for Filter
QString Filter::getPredicate() const {

    return m_predicate;
}

// Get XML Representation
QString Filter::toXML() {

    QString xml = "<Filter";
    xml.append(" Predicate=\"" + encode (m_predicate) + "\"");
    xml.append("/>\n");
    return xml;
}

// Get String Representation
QString Filter::toString() {

    return toString("");
}

// Get String Representation with a lead
QString Filter::toString(QString lead) {

    QString str = lead + "Filter\n";
    str.append( lead + "    Predicate = " + m_predicate + "\n");
    return str;
}

