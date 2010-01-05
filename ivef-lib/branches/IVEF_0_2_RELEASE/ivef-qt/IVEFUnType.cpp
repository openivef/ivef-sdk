
#include "IVEFUnType.h"

UnType::UnType() {

    m_codeA = 0;
    m_codeB = 0;
    m_mode = 0;
}

UnType::UnType(const UnType &val) : QObject() {

    m_codeA = val.m_codeA;
    m_codeB = val.m_codeB;
    m_mode = val.m_mode;
}

UnType & UnType::operator=(const UnType &val) {

    m_codeA = val.m_codeA;
    m_codeB = val.m_codeB;
    m_mode = val.m_mode;
    return *this;
}

QString UnType::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void UnType::setCodeA(int val) {

    if (val < 0)
        return;
    if (val > 138)
        return;
    m_codeA = val;
}

int UnType::getCodeA() const {

    return m_codeA;
}

void UnType::setCodeB(int val) {

    if (val < 0)
        return;
    if (val > 9)
        return;
    m_codeB = val;
}

int UnType::getCodeB() const {

    return m_codeB;
}

void UnType::setMode(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return;
    m_mode = val;
}

int UnType::getMode() const {

    return m_mode;
}

QString UnType::toXML() {

    QString xml = "<UnType";
    xml.append(" CodeA=\"" + QString::number(m_codeA) + "\"");
    xml.append(" CodeB=\"" + QString::number(m_codeB) + "\"");
    xml.append(" Mode=\"" + QString::number(m_mode) + "\"");
    xml.append(">\n");
    xml.append( "</UnType>\n");
    return xml;
}

QString UnType::toString(QString lead) {

    QString str = lead + "UnType\n";
    str.append( lead + "    CodeA = " + QString::number(m_codeA) + "\n");
    str.append( lead + "    CodeB = " + QString::number(m_codeB) + "\n");
    str.append( lead + "    Mode = " + QString::number(m_mode) + "\n");
    return str;
}

