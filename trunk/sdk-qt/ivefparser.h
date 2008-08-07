#ifndef __IVEFPARSER_H__
#define __IVEFPARSER_H__

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

class IVEFparser : public QObject, QXmlDefaultHandler, QXmlSimpleReader { 
    Q_OBJECT

public:
    IVEFparser();
    bool startElement(const QString &,
                      const QString &,
                      const QString & qName,
                      const QXmlAttributes & atts);
    bool endElement(const QString &,
                      const QString &,
                      const QString & qName);
    bool parseXMLString(QString data, bool cont);

signals:
    void signalMSG_VesselData( MSG_VesselData obj );
    void signalMSG_LoginRequest( MSG_LoginRequest obj );
    void signalMSG_LoginResponse( MSG_LoginResponse obj );
    void signalMSG_Ping( MSG_Ping obj );
    void signalMSG_Pong( MSG_Pong obj );
    void signalMSG_ServerStatus( MSG_ServerStatus obj );
    void signalMSG_Logout( MSG_Logout obj );
    void signalMSG_ServiceRequest( MSG_ServiceRequest obj );

private:
    QString m_dataBuffer;
    QStack<QObject *> m_objStack;
    QStack<QString> m_typeStack;

}; 

#endif

