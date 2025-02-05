#include <cstdlib>
#include <iostream>
#include "TSTFunctions.h"

#include "TSTEvent.h"

namespace tst {

// Constructor
Event::Event()
 :  QObject(),
    m_areaName(),
    m_areaNamePresent( false ),
    m_name(),
    m_namePresent( false ),
    m_idPresent( false ),
    m_speed( 0.0 ),
    m_speedPresent( false ),
    m_changed(true)
{
}

// Constructor for parser function
Event::Event(XmlStreamReader& xml)
 :  QObject(),
    m_areaName(),
    m_areaNamePresent( false ),
    m_name(),
    m_namePresent( false ),
    m_idPresent( false ),
    m_speed( 0.0 ),
    m_speedPresent( false ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "Name" ) )
    {
        if ( !setName( attr.value( "Name" ).toString() ) )
            xml.validationError( "error set Name = " + attr.value( "Name" ).toString() );
    }
    if ( attr.hasAttribute( "Id" ) )
    {
        if ( !setId( attr.value( "Id" ).toString().toLongLong() ) )
            xml.validationError( "error set Id = " + attr.value( "Id" ).toString() );
    }
    if ( attr.hasAttribute( "Speed" ) )
    {
        if ( !setSpeed( attr.value( "Speed" ).toString().replace(",", ".").toFloat() ) )
            xml.validationError( "error set Speed = " + attr.value( "Speed" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == QStringLiteral("Event") )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == QStringLiteral("AreaName") )
            {
                QString val = xml.readElementText();
                if ( xml.name() != QStringLiteral("AreaName") )
                    xml.raiseError( "tag mismatch AreaName" );
                else if ( !setAreaName( val ) )
                    xml.validationError( "error set AreaName"  );
            }
            else
            {
                xml.validationError( "unexpected element " + xml.name().toString() );
            }
            break;
        default:
            break;
        }
    }
}

// copy constructor
Event::Event(const Event &val)
 :  QObject(),
    m_areaName( val.m_areaName ),
    m_areaNamePresent( val.m_areaNamePresent ),
    m_name( val.m_name ),
    m_namePresent( val.m_namePresent ),
    m_id( val.m_id ),
    m_idPresent( val.m_idPresent ),
    m_speed( val.m_speed ),
    m_speedPresent( val.m_speedPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Event::operator==(const Event &val) const {

    if (!(m_areaNamePresent == val.m_areaNamePresent)) return false;
    if (!(m_areaName == val.m_areaName)) return false;
    if (!(m_namePresent == val.m_namePresent)) return false;
    if (!(m_name == val.m_name)) return false;
    if (!(m_idPresent == val.m_idPresent)) return false;
    if (!(m_id == val.m_id)) return false;
    if (!(m_speedPresent == val.m_speedPresent)) return false;
    if (!(m_speed == val.m_speed)) return false;
    return true;
}

// assignement
Event & Event::operator=(const Event &val) {

    m_areaNamePresent = val.m_areaNamePresent;
    m_areaName = val.m_areaName;
    m_namePresent = val.m_namePresent;
    m_name = val.m_name;
    m_idPresent = val.m_idPresent;
    m_id = val.m_id;
    m_speedPresent = val.m_speedPresent;
    m_speed = val.m_speed;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// setter for Event
bool Event::setAreaName(const QString& val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 36)
        return false;
    m_areaNamePresent = true;
    m_areaName = val;
    m_changed = true;
    return true;
}

// getter for Event
const QString& Event::getAreaName() const {

    return m_areaName;
}

// check if optional element Event has been set
bool Event::hasAreaName() const {

    return m_areaNamePresent;
}

// setter for Event
bool Event::setName(QString val) {

    // check if the new value is within min length
    if (val.length() < 1)
        return false;
    // check if the new value is within max length
    if (val.length() > 36)
        return false;
    m_namePresent = true;
    m_name = val;
    m_changed = true;
    return true;
}

// getter for Event
QString Event::getName() const {

    return m_name;
}

// check if optional element Event has been set
bool Event::hasName() const {

    return m_namePresent;
}

// setter for Event
bool Event::setId(long long val) {

    // check if the new value is within min exclusive
    if (val <= 0)
        return false;
    // check if the new value is within max exclusive
    if (val >= 10000)
        return false;
    m_idPresent = true;
    m_id = val;
    m_changed = true;
    return true;
}

// getter for Event
long long Event::getId() const {

    return m_id;
}

// check if optional element Event has been set
bool Event::hasId() const {

    return m_idPresent;
}

// setter for Event
bool Event::setSpeed(float val) {

    // check if the new value is within min inclusive
    if (val < 0)
        return false;
    // check if the new value is within max inclusive
    if (val > 1000.1)
        return false;
    m_speedPresent = true;
    m_speed = val;
    m_changed = true;
    return true;
}

// getter for Event
float Event::getSpeed() const {

    return m_speed;
}

// check if optional element Event has been set
bool Event::hasSpeed() const {

    return m_speedPresent;
}

// Get XML Representation
const QString& Event::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Event";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"");
        }
        QString dataMember;
            // check for presence of optional attribute
            if ( hasName() ) {
                xml.append(" Name=\"" + encode (m_name) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasId() ) {
                xml.append(" Id=\"" + QString::number( m_id ) + endAttr);
        }
            // check for presence of optional attribute
            if ( hasSpeed() ) {
                xml.append(" Speed=\"" + QString::number(m_speed, 'f', 2) + endAttr);
        }
        xml.append(">\n");
        // add optional data if available
        if ( hasAreaName() ) {
            xml.append( "<AreaName>" );
            xml.append( m_areaName );
            xml.append( "</AreaName>\n" );
        }
        xml.append( "</Event>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Event::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Event::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Event\n";
    // check for presence of optional attribute
    if ( hasName() ) {
        str.append( lead + "    Name = " + m_name + endAttr);
    }
    // check for presence of optional attribute
    if ( hasId() ) {
        str.append( lead + "    Id = " + QString::number( m_id ) + endAttr);
    }
    // check for presence of optional attribute
    if ( hasSpeed() ) {
        str.append( lead + "    Speed = " + QString::number(m_speed, 'f', 2) + endAttr);
    }
    // add all optional data if present
    if ( hasAreaName() ) {
        str.append( lead + " " );
        str.append( "AreaName = " );
        str.append( m_areaName );
        str.append( "\n" );
    }
    return str;
}

const QString& Event::lastError() const {
    return m_lastError;
}

const bool& Event::changed() const {
    return m_changed;
}

const QString& Event::store() const {
    return m_store;
}


} //end ns
