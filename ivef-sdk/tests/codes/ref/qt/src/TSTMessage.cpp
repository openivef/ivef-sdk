#include <cstdlib>
#include <iostream>
#include "TSTFunctions.h"

#include "TSTMessage.h"

namespace tst {

// Constructor
Message::Message()
 :  QObject(),
    m_timeStamp(),
    m_timeStampPresent( false ),
    m_codePresent( false ),
    m_version( "1.0.0" ), // initialize fixed value
    m_versionPresent( true ),
    m_changed(true)
{
}

// Constructor for parser function
Message::Message(XmlStreamReader& xml)
 :  QObject(),
    m_timeStamp(),
    m_timeStampPresent( false ),
    m_codePresent( false ),
    m_version( "1.0.0" ), // initialize fixed value
    m_versionPresent( true ),
    m_changed(true)
{
    QXmlStreamAttributes attr = xml.attributes();
    if ( attr.hasAttribute( "TimeStamp" ) )
    {
        if ( !setTimeStamp( QDateTime::fromString(attr.value( "TimeStamp" ).toString(), Qt::ISODate)) )
            xml.validationError( "error set TimeStamp = " + attr.value( "TimeStamp" ).toString() );
    }
    if ( attr.hasAttribute( "Code" ) )
    {
        if ( !setCode( attr.value( "Code" ).toString().toLongLong() ) )
            xml.validationError( "error set Code = " + attr.value( "Code" ).toString() );
    }
    if ( attr.hasAttribute( "Version" ) )
    {
        if ( !setVersion( attr.value( "Version" ).toString() ) )
            xml.validationError( "error set Version = " + attr.value( "Version" ).toString() );
    }
    bool stop(false);
    while(!xml.atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        switch ( token )
        {
        case QXmlStreamReader::EndElement:
            if (  xml.name() == QStringLiteral("Message") )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == QStringLiteral("Argument") )
            {
                QString val = xml.readElementText();
                if ( xml.name() != QStringLiteral("Argument") )
                    xml.raiseError( "tag mismatch Argument" );
                else if ( !addArgument( val ) )
                    xml.validationError( "error add Argument"  );
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
Message::Message(const Message &val)
 :  QObject(),
    m_arguments( val.m_arguments ),
    m_timeStamp( val.m_timeStamp ),
    m_timeStampPresent( val.m_timeStampPresent ),
    m_code( val.m_code ),
    m_codePresent( val.m_codePresent ),
    m_version( val.m_version ),
    m_versionPresent( val.m_versionPresent ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool Message::operator==(const Message &val) const {

    if (!(m_arguments == val.m_arguments)) return false;
    if (!(m_timeStampPresent == val.m_timeStampPresent)) return false;
    if (!(m_timeStamp == val.m_timeStamp)) return false;
    if (!(m_codePresent == val.m_codePresent)) return false;
    if (!(m_code == val.m_code)) return false;
    if (!(m_versionPresent == val.m_versionPresent)) return false;
    if (!(m_version == val.m_version)) return false;
    return true;
}

// assignement
Message & Message::operator=(const Message &val) {

    m_arguments = val.m_arguments;
    m_timeStampPresent = val.m_timeStampPresent;
    m_timeStamp = val.m_timeStamp;
    m_codePresent = val.m_codePresent;
    m_code = val.m_code;
    m_versionPresent = val.m_versionPresent;
    m_version = val.m_version;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for Message
bool Message::removeArgument(const QString& val) {

    if (m_arguments.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_arguments.removeOne(val);
}

// setter for Message
bool Message::addArgument(const QString& val) {

    if (m_arguments.count() >= 10) {
        return false; // scalar already at maxOccurs
    }
    if (val.length() < 1) {
        return false; // value is too small
    }
    if (val.length() > 1024) {
        return false; // value is too long
    }
    m_arguments.append(val);
    m_changed = true;
    return true;
}

// getter for Message
const QString& Message::getArgumentAt(int i) const {

    return m_arguments.at(i);
}

// count for Message
int Message::countOfArguments() const {

    return m_arguments.count();
}

// setter for Message
bool Message::setTimeStamp(QDateTime val) {

    m_timeStampPresent = true;
    m_timeStamp = val;
    m_changed = true;
    return true;
}

// getter for Message
QDateTime Message::getTimeStamp() const {

    return m_timeStamp;
}

// setter for Message
bool Message::setCode(long long val) {

    // check if the new value is an approved value
    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return false;
    m_codePresent = true;
    m_code = val;
    m_changed = true;
    return true;
}

// getter for Message
long long Message::getCode() const {

    return m_code;
}

// setter for Message
bool Message::setVersion(QString val) {

    m_versionPresent = true;
    m_version = val;
    m_changed = true;
    return true;
}

// getter for Message
QString Message::getVersion() const {

    return m_version;
}

// Get XML Representation
const QString& Message::toXML(bool outputNamespace) {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<Message";
        if (outputNamespace)
        {
            xml.append(" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"");
            xml.append(" xmlns=\"http://www.mvi.org/XMLSchema/mvi/2.0\"");
        }
        QString dataMember;
            // check for presence of required  attribute
        if ( m_timeStampPresent) {
            xml.append(" TimeStamp=\"" + dateToString( m_timeStamp) + endAttr);
        } else { // required attribute not present
            m_lastError = "TimeStamp not set";
            m_store  = QString();
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_codePresent) {
            xml.append(" Code=\"" + QString::number( m_code ) + endAttr);
        } else { // required attribute not present
            m_lastError = "Code not set";
            m_store  = QString();
            return m_store;
        }
            // check for presence of required  attribute
        if ( m_versionPresent) {
            xml.append(" Version=\"" + m_version + endAttr);
        } else { // required attribute not present
            m_lastError = "Version not set";
            m_store  = QString();
            return m_store;
        }
        xml.append(">\n");
        if (m_arguments.count() < 0) {
            m_lastError = "not enough Argument values";
            m_store  = QString();
            return m_store;
        }
        if (m_arguments.count() > 10) {
            m_lastError = "too much Argument values";
            m_store  = QString();
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_arguments.count(); i++ ) {
            QString attribute = m_arguments.at(i);
            xml.append( "<Argument>" + encode (attribute) +  "</Argument>" );
        }
        xml.append( "</Message>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString Message::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString Message::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "Message\n";
    str.append( lead + "    TimeStamp = " + dateToString( m_timeStamp) + endAttr);
    str.append( lead + "    Code = " + QString::number( m_code ) + endAttr);
    str.append( lead + "    Version = " + m_version + endAttr);
    // add all included data
    for(int i=0; i < m_arguments.count(); i++ ) {
        QString attribute = m_arguments.at(i);
        str.append( lead + "    " + attribute );
    }
    return str;
}

const QString& Message::lastError() const {
    return m_lastError;
}

const bool& Message::changed() const {
    return m_changed;
}

const QString& Message::store() const {
    return m_store;
}


} //end ns
