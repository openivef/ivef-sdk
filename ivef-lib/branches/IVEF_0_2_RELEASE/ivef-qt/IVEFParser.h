#ifndef __PARSER_H__
#define __PARSER_H__

#include <QtCore>
#include <QXmlInputSource>
#include <QXmlDefaultHandler>

#include "IVEFMSG_IVEF.h"
#include "IVEFBody.h"
#include "IVEFObjectDatas.h"
#include "IVEFArea.h"
#include "IVEFOtherId.h"
#include "IVEFOtherName.h"
#include "IVEFHeader.h"
#include "IVEFLoginRequest.h"
#include "IVEFLoginResponse.h"
#include "IVEFLogout.h"
#include "IVEFObjectData.h"
#include "IVEFPing.h"
#include "IVEFPong.h"
#include "IVEFPos.h"
#include "IVEFServerStatus.h"
#include "IVEFServiceRequest.h"
#include "IVEFTransmission.h"
#include "IVEFItem.h"
#include "IVEFFilter.h"
#include "IVEFServiceRequestResponse.h"
#include "IVEFTaggedItem.h"
#include "IVEFTrackData.h"
#include "IVEFVesselData.h"
#include "IVEFConstruction.h"
#include "IVEFUnType.h"
#include "IVEFIdentifier.h"
#include "IVEFVoyageData.h"
#include "IVEFWaypoint.h"

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
    void signalMSG_IVEF( MSG_IVEF obj );
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

