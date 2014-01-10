#include <cstdlib>
#include <iostream>
#include "TSTFunctions.h"

#include "TSTMSG_Notification.h"

namespace tst {

// Constructor
MSG_Notification::MSG_Notification()
 :  QObject(),
    m_changed(true)
{
}

// Constructor for parser function
MSG_Notification::MSG_Notification(XmlStreamReader& xml)
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
            if (  xml.name() == "MSG_Notification" )
                stop = true;
            break;
        case QXmlStreamReader::StartElement:
            if ( xml.name() == "Event" )
            {
                Event val( xml );
                if ( xml.name() != "Event" )
                    xml.raiseError( "tag mismatch Event" );
                else if ( !addEvent( val ) )
                    xml.validationError( "error add Event"  );
            }
            else if ( xml.name() == "Message" )
            {
                Message val( xml );
                if ( xml.name() != "Message" )
                    xml.raiseError( "tag mismatch Message" );
                else if ( !addMessage( val ) )
                    xml.validationError( "error add Message"  );
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
MSG_Notification::MSG_Notification(const MSG_Notification &val)
 :  QObject(),
    m_events( val.m_events ),
    m_messages( val.m_messages ),
    m_lastError(),
    m_changed(val.m_changed ),
    m_store(val.m_store )
{
}

// compare
bool MSG_Notification::operator==(const MSG_Notification &val) {

    if (!(m_events == val.m_events)) return false;
    if (!(m_messages == val.m_messages)) return false;
    return true;
}

// assignement
MSG_Notification & MSG_Notification::operator=(const MSG_Notification &val) {

    m_events = val.m_events;
    m_messages = val.m_messages;
    m_changed = val.m_changed;
    m_store = val.m_store;
    return *this;
}

// remover for MSG_Notification
bool MSG_Notification::removeEvent(const Event& val) {

    if (m_events.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_events.removeOne(val);
}

// setter for MSG_Notification
bool MSG_Notification::addEvent(const Event& val) {

    m_events.append(val);
    m_changed = true;
    return true;
}

// getter for MSG_Notification
const Event& MSG_Notification::getEventAt(int i) const {

    return m_events.at(i);
}

// count for MSG_Notification
int MSG_Notification::countOfEvents() const {

    return m_events.count();
}

// remover for MSG_Notification
bool MSG_Notification::removeMessage(const Message& val) {

    if (m_messages.count() <= 0) {
        return false; // scalar already at minOccurs
    }
    m_changed = true;
    return m_messages.removeOne(val);
}

// setter for MSG_Notification
bool MSG_Notification::addMessage(const Message& val) {

    m_messages.append(val);
    m_changed = true;
    return true;
}

// getter for MSG_Notification
const Message& MSG_Notification::getMessageAt(int i) const {

    return m_messages.at(i);
}

// count for MSG_Notification
int MSG_Notification::countOfMessages() const {

    return m_messages.count();
}

// Get XML Representation
const QString& MSG_Notification::toXML() {

    if ( m_changed ) {
        const static QString endAttr( "\"" );
        QString xml = "<MSG_Notification";
        QString dataMember;
        xml.append(">\n");
        if (m_events.count() < 0) {
            m_lastError = "not enough Event values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_events.count(); i++ ) {
            Event attribute = m_events.at(i);
            dataMember = attribute.toXML();
            if (dataMember != QString::null) {
               xml.append( attribute.toXML() );
            } else {
                m_lastError = "Event:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        if (m_messages.count() < 0) {
            m_lastError = "not enough Message values";
            m_store  = QString::null;
            return m_store;
        }
        // add all included data
        for(int i=0; i < m_messages.count(); i++ ) {
            Message attribute = m_messages.at(i);
            dataMember = attribute.toXML();
            if (dataMember != QString::null) {
               xml.append( attribute.toXML() );
            } else {
                m_lastError = "Message:" + attribute.lastError();
                m_store  = QString::null;
                return m_store;
            }
        }
        xml.append( "</MSG_Notification>\n");
        m_store = xml;
        m_changed = false;
    }
    return m_store;
}

// Get String Representation
QString MSG_Notification::toString() const{

    return toString("");
}

// Get String Representation with a lead
QString MSG_Notification::toString(QString lead) const{

    const static QString endAttr( "\n" );
    QString str = lead + "MSG_Notification\n";
    // add all included data
    for(int i=0; i < m_events.count(); i++ ) {
        Event attribute = m_events.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    // add all included data
    for(int i=0; i < m_messages.count(); i++ ) {
        Message attribute = m_messages.at(i);
        str.append( attribute.toString( lead + "    " ) );
    }
    return str;
}

const QString& MSG_Notification::lastError() const {
    return m_lastError;
}

const bool& MSG_Notification::changed() const {
    return m_changed;
}

const QString& MSG_Notification::store() const {
    return m_store;
}


} //end ns
