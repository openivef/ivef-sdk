#ifndef __PARSER_H__
#define __PARSER_H__

#include <QtCore>
#include <QXmlDefaultHandler>

#include "schema.h"
#include "header.h"
#include "msg_vesseldata.h"
#include "body.h"
#include "vesseldata.h"
#include "posreport.h"
#include "staticdata.h"
#include "voyage.h"
#include "msg_loginrequest.h"
#include "loginrequest.h"
#include "msg_loginresponse.h"
#include "loginresponse.h"
#include "msg_ping.h"
#include "ping.h"
#include "msg_pong.h"
#include "pong.h"
#include "msg_serverstatus.h"
#include "serverstatus.h"
#include "msg_logout.h"
#include "logout.h"
#include "msg_servicerequest.h"
#include "servicerequest.h"
#include "area.h"
#include "transmission.h"
#include "item.h"
#include "object.h"
#include "pos.h"

class Parser : QXmlDefaultHandler { 
    Q_OBJECT

public:
    Parser();
    bool startElement(const QString &,
                      const QString &,
                      const QString & qName,
                      const QXmlAttributes & atts);
    bool parse(QString data, bool cont);

signals:
    void signalSchema( Schema obj );
    void signalHeader( Header obj );
    void signalMSG_VesselData( MSG_VesselData obj );
    void signalBody( Body obj );
    void signalVesselData( VesselData obj );
    void signalPosReport( PosReport obj );
    void signalStaticData( StaticData obj );
    void signalVoyage( Voyage obj );
    void signalMSG_LoginRequest( MSG_LoginRequest obj );
    void signalLoginRequest( LoginRequest obj );
    void signalMSG_LoginResponse( MSG_LoginResponse obj );
    void signalLoginResponse( LoginResponse obj );
    void signalMSG_Ping( MSG_Ping obj );
    void signalPing( Ping obj );
    void signalMSG_Pong( MSG_Pong obj );
    void signalPong( Pong obj );
    void signalMSG_ServerStatus( MSG_ServerStatus obj );
    void signalServerStatus( ServerStatus obj );
    void signalMSG_Logout( MSG_Logout obj );
    void signalLogout( Logout obj );
    void signalMSG_ServiceRequest( MSG_ServiceRequest obj );
    void signalServiceRequest( ServiceRequest obj );
    void signalArea( Area obj );
    void signalTransmission( Transmission obj );
    void signalItem( Item obj );
    void signalObject( Object obj );
    void signalPos( Pos obj );

private:
    QString m_dataBuffer;

}; 

#endif

