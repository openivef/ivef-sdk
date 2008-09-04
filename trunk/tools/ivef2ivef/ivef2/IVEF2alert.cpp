
#include "IVEF2alert.h"

Alert::Alert() {

}

Alert::Alert(const Alert &val) : QObject() {

    m_offPos = val.m_offPos;
    m_positionError = val.m_positionError;
}

Alert & Alert::operator=(const Alert &val) {

    m_offPos = val.m_offPos;
    m_positionError = val.m_positionError;
    return *this;
}

void Alert::setOffPos(bool val) {

    m_offPos = val;
}

bool Alert::getOffPos() const {

    return m_offPos;
}

void Alert::setPositionError(bool val) {

    m_positionError = val;
}

bool Alert::getPositionError() const {

    return m_positionError;
}

QString Alert::toXML() {

    QString xml = "<Alert";
    xml.append(" OffPos=\"" + QString::number(m_offPos) + "\"");
    xml.append(" PositionError=\"" + QString::number(m_positionError) + "\"");
    xml.append(">\n");
    xml.append( "</Alert>\n");
    return xml;
}

QString Alert::toString(QString lead) {

    QString str = lead + "Alert\n";
    str.append( lead + "    OffPos = " + QString::number(m_offPos) + "\n");
    str.append( lead + "    PositionError = " + QString::number(m_positionError) + "\n");
    return str;
}

