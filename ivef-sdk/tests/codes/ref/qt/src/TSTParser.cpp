#include <QtGlobal>
#include <QStringList>

#include "TSTFunctions.h"


#include "TSTParser.h"

namespace tst {

// Constructor
Parser::Parser() {

    m_xml = new XmlStreamReader;
    m_searchFrom = 0;
    connect( m_xml, SIGNAL(signalValidationError(const QString&)),
             this,  SIGNAL(signalValidationError(const QString&)) );
}

// the actual parsing routine
bool Parser::parseXMLString(QString data, bool cont) {

    // add the data to what was left over from a previous parse run
    static const QStringList closeTags = QStringList() << "</MSG_Notification>" << "</Argument>" << "</AreaName>";
    m_dataBuffer.append( data );
    int consumed = 0;
    while ( true )
    {
        // Regex matching can validate the entire subject again at every offset.
        const int index = m_dataBuffer.indexOf( "</", m_searchFrom );
        if ( index < 0 )
        {
            // Revisit only the possible split tag, not the entire incomplete message.
            m_searchFrom = qMax(consumed, int(m_dataBuffer.size()) - 19 + 1);
            break;
        }
        int end = -1;
        for (const QString& tag : closeTags)
        {
            if ( m_dataBuffer.mid(index, tag.size()) == tag )
            {
                end = index + tag.size();
                break;
            }
        }
        if ( end < 0 )
        {
            m_searchFrom = index + 2;
            continue;
        }
        // Feed only this message: copying/re-feeding the remaining batch is quadratic.
        m_xml->clear();
        m_xml->addData( m_dataBuffer.mid(consumed, end - consumed) );
        parse();
        consumed = end;
        m_searchFrom = end;
    }
    // Compact once per call, never once per message in a burst.
    m_dataBuffer.remove( 0, consumed );
    m_searchFrom -= consumed;

    if (!cont) {
        m_xml->clear();
        m_dataBuffer.clear();
        m_searchFrom = 0;
    }
    return true;
}

QString composeMessage( const QXmlStreamReader& xml ) {
    QString errorstr( xml.errorString() );
    errorstr += " at line " + QString::number(xml.lineNumber());
    errorstr += " (column " + QString::number(xml.columnNumber());
    errorstr += ")";
    return errorstr;
}

void Parser::parse() {

    bool stop( false );
    while(!m_xml->atEnd() && !stop)
    {
        QXmlStreamReader::TokenType token = m_xml->readNext();
        if ( token == QXmlStreamReader::StartElement )
        {
            if( m_xml->name()==QStringLiteral("MSG_Notification") )
            {
                MSG_Notification obj( *m_xml );
                if ( m_xml->name() != QStringLiteral("MSG_Notification") )
                    m_xml->raiseError( "tag mismatch MSG_Notification" );
                else
                {
                    emit signalMSG_Notification( obj );
                    stop = true;
                }
            }
        }
    }

    if ( m_xml->hasError() )
    {
        switch ( m_xml->error() )
        {
        case QXmlStreamReader::CustomError:
            emit( signalValidationError( composeMessage( *m_xml ) ) );
            break;
        case QXmlStreamReader::PrematureEndOfDocumentError:
            emit( signalWarning( composeMessage( *m_xml ) ) );
            break;
        case QXmlStreamReader::NotWellFormedError:
        case QXmlStreamReader::UnexpectedElementError:
            emit( signalError( composeMessage( *m_xml ) ) );
            break;
        case QXmlStreamReader::NoError:
            break;
        }
    }
}

} //end ns
