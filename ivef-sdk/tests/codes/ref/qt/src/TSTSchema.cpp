#include <cstdlib>
#include <iostream>
#include "TSTFunctions.h"

#include "TSTSchema.h"

namespace tst {

// Constructor
Schema::Schema()
 :  QObject(),
    m_changed(true)
{
}

// Constructor for parser function
Schema::Schema(XmlStreamReader& xml)
 :  QObject(),
    m_changed(true)
{
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == "Schema" )
                stop = true;
            break;
        default:
            break;
        }
    }
}

// copy constructor
Schema::Schema(const Schema &val)
 :  QObject(),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Schema::operator==(const Schema &val) {

    return true;
}

// assignement
Schema & Schema::operator=(const Schema &val) {

    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// getter for Schema
QString Schema::getElementFormDefault() const {

    return "qualified";
}

// getter for Schema
QString Schema::getTargetNamespace() const {

    return "http://www.mvi.org/XMLSchema/mvi/2.0";
}

// Get XML Representation
const QString& Schema::toXML() {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Schema";
        QString dataMember;
        xml.append("/>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Schema::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Schema::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Schema\n";
    return str;
}

const QString& Schema::lastError() const {
    return m_lastError;
}

const bool& Schema::changed() const {
    return m_changed;
}

const QString& Schema::store() const {
    return m_store;
}


} //end ns
