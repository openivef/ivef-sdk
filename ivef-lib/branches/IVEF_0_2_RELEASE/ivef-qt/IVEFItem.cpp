
#include "IVEFItem.h"

Item::Item() {

    m_dataSelector = 0;
    m_fieldSelector = "";
}

Item::Item(const Item &val) : QObject() {

    m_dataSelector = val.m_dataSelector;
    m_fieldSelector = val.m_fieldSelector;
}

Item & Item::operator=(const Item &val) {

    m_dataSelector = val.m_dataSelector;
    m_fieldSelector = val.m_fieldSelector;
    return *this;
}

QString Item::encode( QString str) {

    str.replace('&', "&amp;");
    str.replace('<', "&lt;");
    str.replace('>', "&gt;");
    str.replace('"', "&quot;");
    return str;
}

void Item::setDataSelector(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_dataSelector = val;
}

int Item::getDataSelector() const {

    return m_dataSelector;
}

void Item::setFieldSelector(QString val) {

    m_fieldSelector = val;
}

QString Item::getFieldSelector() const {

    return m_fieldSelector;
}

QString Item::toXML() {

    QString xml = "<Item";
    xml.append(" DataSelector=\"" + QString::number(m_dataSelector) + "\"");
    xml.append(" FieldSelector=\"" + encode (m_fieldSelector) + "\"");
    xml.append(">\n");
    xml.append( "</Item>\n");
    return xml;
}

QString Item::toString(QString lead) {

    QString str = lead + "Item\n";
    str.append( lead + "    DataSelector = " + QString::number(m_dataSelector) + "\n");
    str.append( lead + "    FieldSelector = " + m_fieldSelector + "\n");
    return str;
}

