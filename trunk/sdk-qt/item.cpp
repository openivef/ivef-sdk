
#include "item.h"

Item::Item() {

}

Item::Item(const Item &val) : QObject() {

    m_element = ((Item)val).getElement();
    m_field = ((Item)val).getField();
}

Item & Item::operator=(const Item &/*val*/) {

    return *this;
}

void Item::setElement(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_element = val;
}

int Item::getElement() {

    return m_element;
}

void Item::setField(QString val) {

    m_field = val;
}

QString Item::getField() {

    return m_field;
}

QString Item::toXML() {

    QString xml = "<Item";
    xml.append(" Element = \"" + QString(m_element, 10) + "\"");
    xml.append(" Field = \"" + m_field + "\"");
    xml.append(">\n");
    xml.append( "<Item />\n");
    return xml;
}

