#include <QtCore>
#include "ivef1/IVEF1msg_loginrequest.h"
#include "ivef1/IVEF1msg_loginresponse.h"
#include "ivef1/IVEF1msg_logout.h"
#include "ivef1/IVEF1msg_ping.h"
#include "ivef1/IVEF1msg_pong.h"
#include "ivef1/IVEF1msg_serverstatus.h"
#include "ivef1/IVEF1msg_servicerequest.h"
#include "ivef1/IVEF1msg_vesseldata.h"
#include "ivef2/IVEF2msg_loginrequest.h"
#include "ivef2/IVEF2msg_loginresponse.h"
#include "ivef2/IVEF2msg_logout.h"
#include "ivef2/IVEF2msg_notification.h"
#include "ivef2/IVEF2msg_objectdata.h"
#include "ivef2/IVEF2msg_ping.h"
#include "ivef2/IVEF2msg_pong.h"
#include "ivef2/IVEF2msg_serverstatus.h"
#include "ivef2/IVEF2msg_servicerequest.h"
class Convert : public QObject {
    Q_OBJECT

public:
    Convert();

    IVEF2msg_loginrequest convert(IVEF1msg_loginrequest *msg);
    IVEF2msg_loginresponse convert(IVEF1msg_loginresponse *msg);
    IVEF2msg_logout convert(IVEF1msg_logout *msg);
    IVEF2msg_ping convert(IVEF1msg_ping *msg);
    IVEF2msg_pong convert(IVEF1msg_pong *msg);
    IVEF2msg_serverstatus convert(IVEF1msg_serverstatus *msg);
    IVEF2msg_servicerequest convert(IVEF1msg_servicerequest *msg);
    IVEF1msg_loginrequest convert(IVEF2msg_loginrequest *msg);
    IVEF1msg_loginresponse convert(IVEF2msg_loginresponse *msg);
    IVEF1msg_logout convert(IVEF2msg_logout *msg);
    IVEF1msg_ping convert(IVEF2msg_ping *msg);
    IVEF1msg_pong convert(IVEF2msg_pong *msg);
    IVEF1msg_serverstatus convert(IVEF2msg_serverstatus *msg);
    IVEF1msg_servicerequest convert(IVEF2msg_servicerequest *msg);

 }; 
