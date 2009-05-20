#ifndef __PARSER_H__
#define __PARSER_H__

#include <QtCore>
#include <QXmlDefaultHandler>

#include "IVEFHeader.h"
#include "IVEFMSG_VesselData.h"
#include "IVEFBody.h"
#include "IVEFVesselData.h"
#include "IVEFPosReport.h"
#include "IVEFStaticData.h"
#include "IVEFVoyage.h"
#include "IVEFMSG_LoginRequest.h"
#include "IVEFLoginRequest.h"
#include "IVEFMSG_LoginResponse.h"
#include "IVEFLoginResponse.h"
#include "IVEFMSG_Ping.h"
#include "IVEFPing.h"
#include "IVEFMSG_Pong.h"
#include "IVEFPong.h"
#include "IVEFMSG_ServerStatus.h"
#include "IVEFServerStatus.h"
#include "IVEFMSG_Logout.h"
#include "IVEFLogout.h"
#include "IVEFMSG_ServiceRequest.h"
#include "IVEFServiceRequest.h"
#include "IVEFArea.h"
#include "IVEFTransmission.h"
#include "IVEFItem.h"
#include "IVEFObject.h"
#include "IVEFPos.h"

class Parser : public QObject, QXmlDefaultHandler, QXmlSimpleReader { 
    Q_OBJECT

public:
    Parser();
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

