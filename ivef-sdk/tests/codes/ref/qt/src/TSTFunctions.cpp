#include "TSTFunctions.h"

namespace tst {

QString encode( const QString& str ) {

    QString result( str );
    const static QString  amp("&amp;");
    const static QString   lt("&lt;");
    const static QString   gt("&gt;");
    const static QString quot("&quot;");
    result.replace('&',  amp);
    result.replace('<',  lt);
    result.replace('>',  gt);
    result.replace('"', quot);
    return result;
}

inline QString nrToString( int nr, int width ) {

    if ( width == 2 && nr < 10 )
        return QString::number( nr ).rightJustified( 2, '0' );
    else if ( width == 3 && nr < 100 )
        return QString::number( nr ).rightJustified( 3, '0' );
    else
        return QString::number( nr );
}

QString dateToString( const QDateTime& dateTime ) {

    if ( !dateTime.isValid() ) return QString::null;

    // make string yyyy-MM-ddTHH:mm:ss.zzzZ
    QString result( QString::number( dateTime.date().year() ) );
    result += '-';
    result += nrToString( dateTime.date().month(), 2 );
    result += '-';
    result += nrToString( dateTime.date().day(), 2 );
    result += 'T';
    result += nrToString( dateTime.time().hour(), 2 );
    result += ':';
    result += nrToString( dateTime.time().minute(), 2 );
    result += ':';
    result += nrToString( dateTime.time().second(), 2 );
    result += '.';
    result += nrToString( dateTime.time().msec(), 3 );
    result += 'Z';
    return result;
}

void XmlStreamReader::validationError(const QString& errorStr) {

    QString error( errorStr );
    error += " at line " + QString::number(lineNumber());
    error += " (column " + QString::number(columnNumber());
    error += ")";
    emit( signalValidationError( error ) );
}

} //end ns
