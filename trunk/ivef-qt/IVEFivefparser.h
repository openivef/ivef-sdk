#ifndef __IVEFPARSER_H__
#define __IVEFPARSER_H__

#include <QtCore>
#include <QXmlDefaultHandler>

#include "IVEFschema.h"
#include "IVEFheader.h"
#include "IVEFmsg_vesseldata.h"
#include "IVEFbody.h"
#include "IVEFvesseldata.h"
#include "IVEFposreport.h"
#include "IVEFstaticdata.h"
#include "IVEFvoyage.h"
#include "IVEFmsg_loginrequest.h"
#include "IVEFloginrequest.h"
#include "IVEFmsg_loginresponse.h"
#include "IVEFloginresponse.h"
#include "IVEFmsg_ping.h"
#include "IVEFping.h"
#include "IVEFmsg_pong.h"
#include "IVEFpong.h"
#include "IVEFmsg_serverstatus.h"
#include "IVEFserverstatus.h"
#include "IVEFmsg_logout.h"
#include "IVEFlogout.h"
#include "IVEFmsg_servicerequest.h"
#include "IVEFservicerequest.h"
#include "IVEFarea.h"
#include "IVEFtransmission.h"
#include "IVEFitem.h"
#include "IVEFobject.h"
#include "IVEFpos.h"

class IVEFParser : public QObject, QXmlDefaultHandler, QXmlSimpleReader { 
    Q_OBJECT

public:
    IVEFParser();
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

