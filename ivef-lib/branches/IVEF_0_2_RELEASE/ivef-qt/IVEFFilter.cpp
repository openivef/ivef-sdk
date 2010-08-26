
#include "IVEFFilter.h"

// Constructor
Filter::Filter() {

    // initialize empty string
    m_predicate = "";
    m_predicatePresent = false;
}

// copy constructor
Filter::Filter(const Filter &val) : QObject() {

    m_predicatePresent = val.m_predicatePresent;
    m_predicate = val.m_predicate;
}

// compare
bool Filter::operator==(const Filter &val) {

    if (!(m_predicatePresent == val.m_predicatePresent)) return false;
    if (!(m_predicate == val.m_predicate)) return false;
    return true;
}

// assignement
Filter & Filter::operator=(const Filter &val) {

    m_predicatePresent = val.m_predicatePresent;
    m_predicate = val.m_predicate;
    return *this;
}

// String encoder
QString Filter::encode( QString str) const {

    // replace characters that are illigal in XML with their encodings
    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

// setter for Filter
bool Filter::setPredicate(QString val) {
    // check if the new value is within bounds 

    if (val.length() < 1)
        return false;    // check if the new value is within bounds 

    if (val.length() > 1024)
        return false;
    m_predicatePresent = true;
    m_predicate = val;
      return true;
}

// getter for Filter
QString Filter::getPredicate() const {

    return m_predicate;
}

// Get XML Representation
QString Filter::toXML() const {

    QString xml = "<Filter";
    QString dataMember;
    // check for presence of required  attribute
    if ( m_predicatePresent) {
        xml.append(" Predicate=\"" + encode (m_predicate) + "\"");
    } else { // required attribute not present
        return NULL;
    }
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

