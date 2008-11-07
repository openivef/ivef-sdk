
#include "IVEFItem.h"

Item::Item() {

}

Item::Item(const Item &val) : QObject() {

    m_element = val.m_element;
    m_field = val.m_field;
}

Item & Item::operator=(const Item &val) {

    m_element = val.m_element;
    m_field = val.m_field;
    return *this;
}

void Item::setElement(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_element = val;
}

int Item::getElement() const {

    return m_element;
}

void Item::setField(QString val) {

    m_field = val;
}

QString Item::getField() const {

    return m_field;
}

QString Item::toXML() {

    QString xml = "<Item";
    xml.append(" Element=\"" + QString::number(m_element) + "\"");
    xml.append(" Field=\"" + m_field + "\"");
    xml.append(">\n");
    xml.append( "</Item>\n");
    return xml;
}

QString Item::toString(QString lead) {

    QString str = lead + "Item\n";
    str.append( lead + "    Element = " + QString::number(m_element) + "\n");
    str.append( lead + "    Field = " + m_field + "\n");
    return str;
}

