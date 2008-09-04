#ifndef __IVEF1PARSER_H__
#define __IVEF1PARSER_H__

#include <QtCore>
#include <QXmlDefaultHandler>

#include "IVEF1schema.h"
#include "IVEF1header.h"
#include "IVEF1msg_vesseldata.h"
#include "IVEF1body.h"
#include "IVEF1vesseldata.h"
#include "IVEF1posreport.h"
#include "IVEF1staticdata.h"
#include "IVEF1voyage.h"
#include "IVEF1msg_loginrequest.h"
#include "IVEF1loginrequest.h"
#include "IVEF1msg_loginresponse.h"
#include "IVEF1loginresponse.h"
#include "IVEF1msg_ping.h"
#include "IVEF1ping.h"
#include "IVEF1msg_pong.h"
#include "IVEF1pong.h"
#include "IVEF1msg_serverstatus.h"
#include "IVEF1serverstatus.h"
#include "IVEF1msg_logout.h"
#include "IVEF1logout.h"
#include "IVEF1msg_servicerequest.h"
#include "IVEF1servicerequest.h"
#include "IVEF1area.h"
#include "IVEF1transmission.h"
#include "IVEF1item.h"
#include "IVEF1object.h"
#include "IVEF1pos.h"

class IVEF1Parser : public QObject, QXmlDefaultHandler, QXmlSimpleReader { 
    Q_OBJECT

public:
    IVEF1Parser();
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

