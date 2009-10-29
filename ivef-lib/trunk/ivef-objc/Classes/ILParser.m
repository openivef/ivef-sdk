
#import "ILParser.h"


@implementation ILParser

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dataBuffer = [[NSMutableString alloc] init];
        m_objStack = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void) dealloc {
        [m_dataBuffer release];
        [m_objStack release];
        [super dealloc];
}

- (void)     parser:(NSXMLParser *)parser 
    didStartElement:(NSString *)elementName
       namespaceURI:(NSString *)namespaceURI
      qualifiedName:(NSString *)qualifiedName
         attributes:(NSDictionary *)attributeDict {
    // check all possible options
    if ([elementName isEqualToString: @"MSG_LoginRequest"]) {
        ILMSG_LoginRequest *obj = [[ILMSG_LoginRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Body"]) {
        ILBody *obj = [[ILBody alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_LoginResponse"]) {
        ILMSG_LoginResponse *obj = [[ILMSG_LoginResponse alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_Logout"]) {
        ILMSG_Logout *obj = [[ILMSG_Logout alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Logout"]) {
        ILLogout *obj = [[ILLogout alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_Ping"]) {
        ILMSG_Ping *obj = [[ILMSG_Ping alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_Pong"]) {
        ILMSG_Pong *obj = [[ILMSG_Pong alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_ServerStatus"]) {
        ILMSG_ServerStatus *obj = [[ILMSG_ServerStatus alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_ServiceRequest"]) {
        ILMSG_ServiceRequest *obj = [[ILMSG_ServiceRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_VesselData"]) {
        ILMSG_VesselData *obj = [[ILMSG_VesselData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Header"]) {
        ILHeader *obj = [[ILHeader alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"LoginRequest"]) {
        ILLoginRequest *obj = [[ILLoginRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"LoginResponse"]) {
        ILLoginResponse *obj = [[ILLoginResponse alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Ping"]) {
        ILPing *obj = [[ILPing alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Pong"]) {
        ILPong *obj = [[ILPong alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Pos"]) {
        ILPos *obj = [[ILPos alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"PosReport"]) {
        ILPosReport *obj = [[ILPosReport alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Sensor"]) {
        ILSensor *obj = [[ILSensor alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"StaticData"]) {
        ILStaticData *obj = [[ILStaticData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"ServerStatus"]) {
        ILServerStatus *obj = [[ILServerStatus alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"TaggedItem"]) {
        ILTaggedItem *obj = [[ILTaggedItem alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"ServiceRequest"]) {
        ILServiceRequest *obj = [[ILServiceRequest alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Area"]) {
        ILArea *obj = [[ILArea alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Transmission"]) {
        ILTransmission *obj = [[ILTransmission alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Item"]) {
        ILItem *obj = [[ILItem alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Object"]) {
        ILObject *obj = [[ILObject alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"VesselData"]) {
        ILVesselData *obj = [[ILVesselData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Voyage"]) {
        ILVoyage *obj = [[ILVoyage alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
}

- (void)     parser:(NSXMLParser *)parser 
      didEndElement:(NSString *)elementName
       namespaceURI:(NSString *)namespaceURI
      qualifiedName:(NSString *)qualifiedName {
    // check all possible options
    if ([elementName isEqualToString: @"MSG_LoginRequest"]) {

        ILMSG_LoginRequest *obj = (ILMSG_LoginRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_LoginRequest" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Body"]) {

        ILBody *obj = (ILBody*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_LoginRequest class]]) {
                [((ILMSG_LoginRequest*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_LoginResponse class]]) {
                [((ILMSG_LoginResponse*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Logout class]]) {
                [((ILMSG_Logout*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Ping class]]) {
                [((ILMSG_Ping*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Pong class]]) {
                [((ILMSG_Pong*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServerStatus class]]) {
                [((ILMSG_ServerStatus*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServiceRequest class]]) {
                [((ILMSG_ServiceRequest*) [m_objStack lastObject] ) setBody: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_VesselData class]]) {
                [((ILMSG_VesselData*) [m_objStack lastObject] ) setBody: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_LoginResponse"]) {

        ILMSG_LoginResponse *obj = (ILMSG_LoginResponse*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_LoginResponse" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_Logout"]) {

        ILMSG_Logout *obj = (ILMSG_Logout*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_Logout" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Logout"]) {

        ILLogout *obj = (ILLogout*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setLogout: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_Ping"]) {

        ILMSG_Ping *obj = (ILMSG_Ping*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_Ping" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_Pong"]) {

        ILMSG_Pong *obj = (ILMSG_Pong*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_Pong" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_ServerStatus"]) {

        ILMSG_ServerStatus *obj = (ILMSG_ServerStatus*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_ServerStatus" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_ServiceRequest"]) {

        ILMSG_ServiceRequest *obj = (ILMSG_ServiceRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_ServiceRequest" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"MSG_VesselData"]) {

        ILMSG_VesselData *obj = (ILMSG_VesselData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_VesselData" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Header"]) {

        ILHeader *obj = (ILHeader*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_LoginRequest class]]) {
                [((ILMSG_LoginRequest*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_LoginResponse class]]) {
                [((ILMSG_LoginResponse*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Logout class]]) {
                [((ILMSG_Logout*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Ping class]]) {
                [((ILMSG_Ping*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Pong class]]) {
                [((ILMSG_Pong*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServerStatus class]]) {
                [((ILMSG_ServerStatus*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServiceRequest class]]) {
                [((ILMSG_ServiceRequest*) [m_objStack lastObject] ) setHeader: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_VesselData class]]) {
                [((ILMSG_VesselData*) [m_objStack lastObject] ) setHeader: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"LoginRequest"]) {

        ILLoginRequest *obj = (ILLoginRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setLoginRequest: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"LoginResponse"]) {

        ILLoginResponse *obj = (ILLoginResponse*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setLoginResponse: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Ping"]) {

        ILPing *obj = (ILPing*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setPing: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Pong"]) {

        ILPong *obj = (ILPong*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setPong: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Pos"]) {

        ILPos *obj = (ILPos*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILPosReport class]]) {
                [((ILPosReport*) [m_objStack lastObject] ) setPos: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILArea class]]) {
                [((ILArea*) [m_objStack lastObject] ) addPos: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"PosReport"]) {

        ILPosReport *obj = (ILPosReport*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                [((ILVesselData*) [m_objStack lastObject] ) setPosReport: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Sensor"]) {

        ILSensor *obj = (ILSensor*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILPosReport class]]) {
                [((ILPosReport*) [m_objStack lastObject] ) addSensor: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"StaticData"]) {

        ILStaticData *obj = (ILStaticData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                [((ILVesselData*) [m_objStack lastObject] ) addStaticData: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"ServerStatus"]) {

        ILServerStatus *obj = (ILServerStatus*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setServerStatus: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"TaggedItem"]) {

        ILTaggedItem *obj = (ILTaggedItem*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                [((ILVesselData*) [m_objStack lastObject] ) addTaggedItem: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"ServiceRequest"]) {

        ILServiceRequest *obj = (ILServiceRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setServiceRequest: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Area"]) {

        ILArea *obj = (ILArea*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                [((ILServiceRequest*) [m_objStack lastObject] ) addArea: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Transmission"]) {

        ILTransmission *obj = (ILTransmission*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                [((ILServiceRequest*) [m_objStack lastObject] ) setTransmission: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Item"]) {

        ILItem *obj = (ILItem*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                [((ILServiceRequest*) [m_objStack lastObject] ) addItem: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Object"]) {

        ILObject *obj = (ILObject*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                [((ILServiceRequest*) [m_objStack lastObject] ) addObject: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"VesselData"]) {

        ILVesselData *obj = (ILVesselData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) addVesselData: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Voyage"]) {

        ILVoyage *obj = (ILVoyage*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                [((ILVesselData*) [m_objStack lastObject] ) addVoyage: obj ];
        }
        [obj release]; 
    }
}

- (bool) parseXMLString:(NSString *)data andBuffer: (bool) cont {

     [m_dataBuffer appendString: data];

     int index[8], indexMax = -1;

     // note that if a message does not exist the index will be equal to strlen(name\n) - 1 so indexMax is always > 0
     index[0] = [m_dataBuffer rangeOfString:@"</MSG_LoginRequest>" options: NSBackwardsSearch].location + strlen("</MSG_LoginRequest>");
     index[1] = [m_dataBuffer rangeOfString:@"</MSG_LoginResponse>" options: NSBackwardsSearch].location + strlen("</MSG_LoginResponse>");
     index[2] = [m_dataBuffer rangeOfString:@"</MSG_Logout>" options: NSBackwardsSearch].location + strlen("</MSG_Logout>");
     index[3] = [m_dataBuffer rangeOfString:@"</MSG_Ping>" options: NSBackwardsSearch].location + strlen("</MSG_Ping>");
     index[4] = [m_dataBuffer rangeOfString:@"</MSG_Pong>" options: NSBackwardsSearch].location + strlen("</MSG_Pong>");
     index[5] = [m_dataBuffer rangeOfString:@"</MSG_ServerStatus>" options: NSBackwardsSearch].location + strlen("</MSG_ServerStatus>");
     index[6] = [m_dataBuffer rangeOfString:@"</MSG_ServiceRequest>" options: NSBackwardsSearch].location + strlen("</MSG_ServiceRequest>");
     index[7] = [m_dataBuffer rangeOfString:@"</MSG_VesselData>" options: NSBackwardsSearch].location + strlen("</MSG_VesselData>");
     for (int i=0; i<8; i++) {
         if (index[i] > indexMax) {
             indexMax = index[i];
         }
     }

     if (indexMax > 30) {
         NSString *messages = [m_dataBuffer substringToIndex: indexMax];
         [m_dataBuffer deleteCharactersInRange:NSMakeRange(0, indexMax)];
         // create a seperate memory pool, so we can quickly deallocate temp objects generated by the parser
         NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
         NSXMLParser *tempParser = [[NSXMLParser alloc] initWithData:[messages dataUsingEncoding:NSASCIIStringEncoding]];
         [tempParser setDelegate:self];
         [tempParser parse];
         [tempParser release];
         [pool release];
     } else {
         return false; // not enough data in string
     }
     if (!cont) {
         [m_dataBuffer setString: @""];
     }
     return true;
}


@end


