
#import "IVEFParser.h"


@implementation IVEFParser

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dataBuffer = [[NSString alloc] init];
        m_objStack = [[NSMutableArray alloc] init];
        [self setDelegate: self]; // we are our own delegate
    }
    return self;
}

- (void)     parser:(NSXMLParser *)parser 
    didStartElement:(NSString *)elementName
       namespaceURI:(NSString *)namespaceURI
      qualifiedName:(NSString *)qualifiedName
         attributes:(NSDictionary *)attributeDict {
    // check all possible options
    if ([qualifiedName isEqualToString: @"IVEFHeader"]) {
        IVEFHeader *obj = [[IVEFHeader alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_VesselData"]) {
        IVEFMSG_VesselData *obj = [[IVEFMSG_VesselData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFBody"]) {
        IVEFBody *obj = [[IVEFBody alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFVesselData"]) {
        IVEFVesselData *obj = [[IVEFVesselData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFPosReport"]) {
        IVEFPosReport *obj = [[IVEFPosReport alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFStaticData"]) {
        IVEFStaticData *obj = [[IVEFStaticData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFVoyage"]) {
        IVEFVoyage *obj = [[IVEFVoyage alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_LoginRequest"]) {
        IVEFMSG_LoginRequest *obj = [[IVEFMSG_LoginRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFLoginRequest"]) {
        IVEFLoginRequest *obj = [[IVEFLoginRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_LoginResponse"]) {
        IVEFMSG_LoginResponse *obj = [[IVEFMSG_LoginResponse alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFLoginResponse"]) {
        IVEFLoginResponse *obj = [[IVEFLoginResponse alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_Ping"]) {
        IVEFMSG_Ping *obj = [[IVEFMSG_Ping alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFPing"]) {
        IVEFPing *obj = [[IVEFPing alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_Pong"]) {
        IVEFMSG_Pong *obj = [[IVEFMSG_Pong alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFPong"]) {
        IVEFPong *obj = [[IVEFPong alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_ServerStatus"]) {
        IVEFMSG_ServerStatus *obj = [[IVEFMSG_ServerStatus alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFServerStatus"]) {
        IVEFServerStatus *obj = [[IVEFServerStatus alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_Logout"]) {
        IVEFMSG_Logout *obj = [[IVEFMSG_Logout alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFLogout"]) {
        IVEFLogout *obj = [[IVEFLogout alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_ServiceRequest"]) {
        IVEFMSG_ServiceRequest *obj = [[IVEFMSG_ServiceRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFServiceRequest"]) {
        IVEFServiceRequest *obj = [[IVEFServiceRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFArea"]) {
        IVEFArea *obj = [[IVEFArea alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFTransmission"]) {
        IVEFTransmission *obj = [[IVEFTransmission alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFItem"]) {
        IVEFItem *obj = [[IVEFItem alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFObject"]) {
        IVEFObject *obj = [[IVEFObject alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
    else if ([qualifiedName isEqualToString: @"IVEFPos"]) {
        IVEFPos *obj = [[IVEFPos alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
    }
}

- (void)     parser:(NSXMLParser *)parser 
      didEndElement:(NSString *)elementName
       namespaceURI:(NSString *)namespaceURI
      qualifiedName:(NSString *)qualifiedName {
    // check all possible options
    if ([qualifiedName isEqualToString: @"IVEFHeader"]) {

        IVEFHeader *obj = (IVEFHeader*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_VesselData class]]) {
                [((IVEFMSG_VesselData*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_LoginRequest class]]) {
                [((IVEFMSG_LoginRequest*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_LoginResponse class]]) {
                [((IVEFMSG_LoginResponse*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_Ping class]]) {
                [((IVEFMSG_Ping*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_Pong class]]) {
                [((IVEFMSG_Pong*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_ServerStatus class]]) {
                [((IVEFMSG_ServerStatus*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_Logout class]]) {
                [((IVEFMSG_Logout*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_ServiceRequest class]]) {
                [((IVEFMSG_ServiceRequest*) [m_objStack lastObject] ) setHeader: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_VesselData"]) {

        IVEFMSG_VesselData *obj = (IVEFMSG_VesselData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_VesselData" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFBody"]) {

        IVEFBody *obj = (IVEFBody*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_VesselData class]]) {
                [((IVEFMSG_VesselData*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_LoginRequest class]]) {
                [((IVEFMSG_LoginRequest*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_LoginResponse class]]) {
                [((IVEFMSG_LoginResponse*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_Ping class]]) {
                [((IVEFMSG_Ping*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_Pong class]]) {
                [((IVEFMSG_Pong*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_ServerStatus class]]) {
                [((IVEFMSG_ServerStatus*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_Logout class]]) {
                [((IVEFMSG_Logout*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFMSG_ServiceRequest class]]) {
                [((IVEFMSG_ServiceRequest*) [m_objStack lastObject] ) setBody: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFVesselData"]) {

        IVEFVesselData *obj = (IVEFVesselData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) addVesselData: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFPosReport"]) {

        IVEFPosReport *obj = (IVEFPosReport*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFVesselData class]]) {
                [((IVEFVesselData*) [m_objStack lastObject] ) setPosReport: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFStaticData"]) {

        IVEFStaticData *obj = (IVEFStaticData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFVesselData class]]) {
                [((IVEFVesselData*) [m_objStack lastObject] ) addStaticData: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFVoyage"]) {

        IVEFVoyage *obj = (IVEFVoyage*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFVesselData class]]) {
                [((IVEFVesselData*) [m_objStack lastObject] ) addVoyage: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_LoginRequest"]) {

        IVEFMSG_LoginRequest *obj = (IVEFMSG_LoginRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_LoginRequest" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFLoginRequest"]) {

        IVEFLoginRequest *obj = (IVEFLoginRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setLoginRequest: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_LoginResponse"]) {

        IVEFMSG_LoginResponse *obj = (IVEFMSG_LoginResponse*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_LoginResponse" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFLoginResponse"]) {

        IVEFLoginResponse *obj = (IVEFLoginResponse*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setLoginResponse: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_Ping"]) {

        IVEFMSG_Ping *obj = (IVEFMSG_Ping*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_Ping" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFPing"]) {

        IVEFPing *obj = (IVEFPing*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setPing: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_Pong"]) {

        IVEFMSG_Pong *obj = (IVEFMSG_Pong*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_Pong" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFPong"]) {

        IVEFPong *obj = (IVEFPong*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setPong: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_ServerStatus"]) {

        IVEFMSG_ServerStatus *obj = (IVEFMSG_ServerStatus*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_ServerStatus" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFServerStatus"]) {

        IVEFServerStatus *obj = (IVEFServerStatus*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setServerStatus: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_Logout"]) {

        IVEFMSG_Logout *obj = (IVEFMSG_Logout*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_Logout" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFLogout"]) {

        IVEFLogout *obj = (IVEFLogout*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setLogout: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFMSG_ServiceRequest"]) {

        IVEFMSG_ServiceRequest *obj = (IVEFMSG_ServiceRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewIVEFMSG_ServiceRequest" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFServiceRequest"]) {

        IVEFServiceRequest *obj = (IVEFServiceRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFBody class]]) {
                [((IVEFBody*) [m_objStack lastObject] ) setServiceRequest: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFArea"]) {

        IVEFArea *obj = (IVEFArea*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFServiceRequest class]]) {
                [((IVEFServiceRequest*) [m_objStack lastObject] ) addArea: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFTransmission"]) {

        IVEFTransmission *obj = (IVEFTransmission*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFServiceRequest class]]) {
                [((IVEFServiceRequest*) [m_objStack lastObject] ) setTransmission: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFItem"]) {

        IVEFItem *obj = (IVEFItem*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFServiceRequest class]]) {
                [((IVEFServiceRequest*) [m_objStack lastObject] ) addItem: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFObject"]) {

        IVEFObject *obj = (IVEFObject*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFServiceRequest class]]) {
                [((IVEFServiceRequest*) [m_objStack lastObject] ) addObject: obj ];
        }
        [obj release]; 
    }
    else if ([qualifiedName isEqualToString: @"IVEFPos"]) {

        IVEFPos *obj = (IVEFPos*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFPosReport class]]) {
                [((IVEFPosReport*) [m_objStack lastObject] ) setPos: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [IVEFArea class]]) {
                [((IVEFArea*) [m_objStack lastObject] ) addPos: obj ];
        }
        [obj release]; 
    }
}

- (bool) parseXMLString:(NSString *)data andBuffer: (bool) cont {

     [m_dataBuffer appendString: data];

     int index[8], indexMax = -1;

     // note that if a message does not exist the index will be equal to strlen(name\n) - 1 so indexMax is always > 0
     index[0] = [m_dataBuffer rangeOfString:@"</MSG_VesselData>\n" options: NSBackwardsSearch].location + strlen("</MSG_VesselData>\n");
     index[1] = [m_dataBuffer rangeOfString:@"</MSG_LoginRequest>\n" options: NSBackwardsSearch].location + strlen("</MSG_LoginRequest>\n");
     index[2] = [m_dataBuffer rangeOfString:@"</MSG_LoginResponse>\n" options: NSBackwardsSearch].location + strlen("</MSG_LoginResponse>\n");
     index[3] = [m_dataBuffer rangeOfString:@"</MSG_Ping>\n" options: NSBackwardsSearch].location + strlen("</MSG_Ping>\n");
     index[4] = [m_dataBuffer rangeOfString:@"</MSG_Pong>\n" options: NSBackwardsSearch].location + strlen("</MSG_Pong>\n");
     index[5] = [m_dataBuffer rangeOfString:@"</MSG_ServerStatus>\n" options: NSBackwardsSearch].location + strlen("</MSG_ServerStatus>\n");
     index[6] = [m_dataBuffer rangeOfString:@"</MSG_Logout>\n" options: NSBackwardsSearch].location + strlen("</MSG_Logout>\n");
     index[7] = [m_dataBuffer rangeOfString:@"</MSG_ServiceRequest>\n" options: NSBackwardsSearch].location + strlen("</MSG_ServiceRequest>\n");
     for (int i=0; i<8; i++) {
         if (index[i] > indexMax) {
             indexMax = index[i];
         }
     }

     if (indexMax > 30) {
         NSString *messages = [m_dataBuffer substringToIndex: indexMax];
         [m_dataBuffer deleteCharactersInRange:NSMakeRange(0, indexMax)];
         [self initWithData: [messages dataUsingEncoding:NSASCIIStringEncoding]]; // should probably not call init more than once
         [self parse];
     } else {
         return false; // not enough data in string
     }
     if (!cont) {
         [m_dataBuffer setString: @""];
     }
     return true;
}


@end


