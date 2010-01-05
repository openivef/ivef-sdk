
#include "IVEFFilter.h"

Filter::Filter() {

    m_predicate = "";
}

Filter::Filter(const Filter &val) : QObject() {

    m_predicate = val.m_predicate;
}

Filter & Filter::operator=(const Filter &val) {

    m_predicate = val.m_predicate;
    return *this;
}

QString Filter::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Filter::setPredicate(QString val) {

    m_predicate = val;
}

QString Filter::getPredicate() const {

    return m_predicate;
}

QString Filter::toXML() {

    QString xml = "<Filter";
    xml.append(" Predicate=\"" + encode (m_predicate) + "\"");
    xml.append(">\n");
    xml.append( "</Filter>\n");
    return xml;
}

QString Filter::toString(QString lead) {

    QString str = lead + "Filter\n";
    str.append( lead + "    Predicate = " + m_predicate + "\n");
    return str;
}

