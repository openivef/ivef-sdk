#ifndef __IVEF2PARSER_H__
#define __IVEF2PARSER_H__

#include <QtCore>
#include <QXmlDefaultHandler>

#include "IVEF2schema.h"
#include "IVEF2msg_loginrequest.h"
#include "IVEF2body.h"
#include "IVEF2msg_loginresponse.h"
#include "IVEF2msg_logout.h"
#include "IVEF2logout.h"
#include "IVEF2msg_objectdata.h"
#include "IVEF2msg_notification.h"
#include "IVEF2forcast.h"
#include "IVEF2msg_ping.h"
#include "IVEF2msg_pong.h"
#include "IVEF2msg_serverstatus.h"
#include "IVEF2msg_servicerequest.h"
#include "IVEF2header.h"
#include "IVEF2objectdata.h"
#include "IVEF2pos.h"
#include "IVEF2posreport.h"
#include "IVEF2sensor.h"
#include "IVEF2staticdata.h"
#include "IVEF2identifier.h"
#include "IVEF2foreignname.h"
#include "IVEF2foreignid.h"
#include "IVEF2taggeditems.h"
#include "IVEF2construction.h"
#include "IVEF2propulsion.h"
#include "IVEF2owner.h"
#include "IVEF2voyage.h"
#include "IVEF2waypoints.h"
#include "IVEF2alert.h"
#include "IVEF2loginrequest.h"
#include "IVEF2loginresponse.h"
#include "IVEF2ping.h"
#include "IVEF2pong.h"
#include "IVEF2serverstatus.h"
#include "IVEF2servicerequest.h"
#include "IVEF2area.h"
#include "IVEF2transmission.h"
#include "IVEF2item.h"
#include "IVEF2object.h"
#include "IVEF2notification.h"
#include "IVEF2servicerequestresponse.h"
#include "IVEF2chart.h"
#include "IVEF2s57chart.h"
#include "IVEF2xmlchart.h"
#include "IVEF2hyme.h"
#include "IVEF2station.h"
#include "IVEF2reading.h"
#include "IVEF2message.h"

class IVEF2Parser : public QObject, QXmlDefaultHandler, QXmlSimpleReader { 
    Q_OBJECT

public:
    IVEF2Parser();
    bool startElement(const QString &,
                      const QString &,
                      const QString & qName,
                      const QXmlAttributes & atts);
    bool endElement(const QString &,
                      const QString &,
                      const QString & qName);
    bool parseXMLString(QString data, bool cont);

signals:
    void signalMSG_LoginRequest( MSG_LoginRequest obj );
    void signalMSG_LoginResponse( MSG_LoginResponse obj );
    void signalMSG_Logout( MSG_Logout obj );
    void signalMSG_ObjectData( MSG_ObjectData obj );
    void signalMSG_Notification( MSG_Notification obj );
    void signalForcast( Forcast obj );
    void signalMSG_Ping( MSG_Ping obj );
    void signalMSG_Pong( MSG_Pong obj );
    void signalMSG_ServerStatus( MSG_ServerStatus obj );
    void signalMSG_ServiceRequest( MSG_ServiceRequest obj );
    void signalServiceRequestResponse( ServiceRequestResponse obj );

private:
    QString m_dataBuffer;
    QStack<QObject *> m_objStack;
    QStack<QString> m_typeStack;

}; 

#endif

