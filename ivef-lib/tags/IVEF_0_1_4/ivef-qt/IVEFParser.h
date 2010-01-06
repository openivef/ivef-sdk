#ifndef __PARSER_H__
#define __PARSER_H__

#include <QtCore>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>

#include "IVEFMSG_LoginRequest.h"
#include "IVEFBody.h"
#include "IVEFMSG_LoginResponse.h"
#include "IVEFMSG_Logout.h"
#include "IVEFLogout.h"
#include "IVEFMSG_Ping.h"
#include "IVEFMSG_Pong.h"
#include "IVEFMSG_ServerStatus.h"
#include "IVEFMSG_ServiceRequest.h"
#include "IVEFMSG_VesselData.h"
#include "IVEFHeader.h"
#include "IVEFLoginRequest.h"
#include "IVEFLoginResponse.h"
#include "IVEFPing.h"
#include "IVEFPong.h"
#include "IVEFPos.h"
#include "IVEFPosReport.h"
#include "IVEFSensor.h"
#include "IVEFStaticData.h"
#include "IVEFServerStatus.h"
#include "IVEFTaggedItem.h"
#include "IVEFServiceRequest.h"
#include "IVEFArea.h"
#include "IVEFTransmission.h"
#include "IVEFItem.h"
#include "IVEFObject.h"
#include "IVEFVesselData.h"
#include "IVEFVoyage.h"

//-----------------------------------------------------------
//! \brief       Class definition of Parser
//!

class Parser : public QObject, QXmlDefaultHandler, QXmlSimpleReader { 
    Q_OBJECT

public:
    //!constructor
    //!
    Parser();
    //!delegate methods for QXmlDefaultHandler
    //!
    bool startElement(const QString &,
                      const QString &,
                      const QString & qName,
                      const QXmlAttributes & atts);
    bool endElement(const QString &,
                      const QString &,
                      const QString & qName);
    //!the actual parse routine
    //!
    bool parseXMLString(QString data, bool cont);

signals:
    //!signals fired by the parser when a new object has been parsed
    //!
    void signalMSG_LoginRequest( MSG_LoginRequest obj );
    void signalMSG_LoginResponse( MSG_LoginResponse obj );
    void signalMSG_Logout( MSG_Logout obj );
    void signalMSG_Ping( MSG_Ping obj );
    void signalMSG_Pong( MSG_Pong obj );
    void signalMSG_ServerStatus( MSG_ServerStatus obj );
    void signalMSG_ServiceRequest( MSG_ServiceRequest obj );
    void signalMSG_VesselData( MSG_VesselData obj );
    //!signals fired by the parser when a parser problem occured
    //!
    void signalError(QString errorStr);
    void signalWarning(QString errorStr);
protected:
    virtual QString composeMessage( const QXmlParseException& exception );
    virtual bool    error( const QXmlParseException& exception );
    virtual bool    fatalError( const QXmlParseException& exception );
    virtual bool    warning( const QXmlParseException& exception );

private:
    QString m_dataBuffer;
    QXmlInputSource m_inputForParser;
    QStack<QObject *> m_objStack;
    QStack<QString> m_typeStack;

}; 

#endif

