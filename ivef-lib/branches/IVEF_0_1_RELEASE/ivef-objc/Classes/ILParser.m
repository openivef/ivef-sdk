
#import "ILParser.h"


@implementation ILParser

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dataBuffer = [[NSMutableString alloc] init];
        m_objStack = [[NSMutableArray alloc] init];
        m_closeTags = [[NSArray arrayWithObjects:@"</MSG_LoginRequest>", @"</MSG_LoginResponse>", @"</MSG_Logout>", @"</MSG_Ping>", @"</MSG_Pong>", @"</MSG_ServerStatus>", @"</MSG_ServiceRequest>", @"</MSG_VesselData>", nil] retain];
    }
    return self;
}

- (void) dealloc {
        [m_dataBuffer release];
        [m_objStack release];
        [m_closeTags release];
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
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Body"]) {
        ILBody *obj = [[ILBody alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_LoginResponse"]) {
        ILMSG_LoginResponse *obj = [[ILMSG_LoginResponse alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_Logout"]) {
        ILMSG_Logout *obj = [[ILMSG_Logout alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Logout"]) {
        ILLogout *obj = [[ILLogout alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_Ping"]) {
        ILMSG_Ping *obj = [[ILMSG_Ping alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_Pong"]) {
        ILMSG_Pong *obj = [[ILMSG_Pong alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_ServerStatus"]) {
        ILMSG_ServerStatus *obj = [[ILMSG_ServerStatus alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_ServiceRequest"]) {
        ILMSG_ServiceRequest *obj = [[ILMSG_ServiceRequest alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"MSG_VesselData"]) {
        ILMSG_VesselData *obj = [[ILMSG_VesselData alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Header"]) {
        ILHeader *obj = [[ILHeader alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"LoginRequest"]) {
        ILLoginRequest *obj = [[ILLoginRequest alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"LoginResponse"]) {
        ILLoginResponse *obj = [[ILLoginResponse alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Ping"]) {
        ILPing *obj = [[ILPing alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Pong"]) {
        ILPong *obj = [[ILPong alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Pos"]) {
        ILPos *obj = [[ILPos alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"PosReport"]) {
        ILPosReport *obj = [[ILPosReport alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Sensor"]) {
        ILSensor *obj = [[ILSensor alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"StaticData"]) {
        ILStaticData *obj = [[ILStaticData alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"ServerStatus"]) {
        ILServerStatus *obj = [[ILServerStatus alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"TaggedItem"]) {
        ILTaggedItem *obj = [[ILTaggedItem alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"ServiceRequest"]) {
        ILServiceRequest *obj = [[ILServiceRequest alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Area"]) {
        ILArea *obj = [[ILArea alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Transmission"]) {
        ILTransmission *obj = [[ILTransmission alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Item"]) {
        ILItem *obj = [[ILItem alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Object"]) {
        ILObject *obj = [[ILObject alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"VesselData"]) {
        ILVesselData *obj = [[ILVesselData alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Voyage"]) {
        ILVoyage *obj = [[ILVoyage alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
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
                if (! [((ILMSG_LoginRequest*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_LoginResponse class]]) {
                if (! [((ILMSG_LoginResponse*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Logout class]]) {
                if (! [((ILMSG_Logout*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Ping class]]) {
                if (! [((ILMSG_Ping*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Pong class]]) {
                if (! [((ILMSG_Pong*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServerStatus class]]) {
                if (! [((ILMSG_ServerStatus*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServiceRequest class]]) {
                if (! [((ILMSG_ServiceRequest*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_VesselData class]]) {
                if (! [((ILMSG_VesselData*) [m_objStack lastObject] ) setBody: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
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
                if (! [((ILBody*) [m_objStack lastObject] ) setLogout: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
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
                if (! [((ILMSG_LoginRequest*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_LoginResponse class]]) {
                if (! [((ILMSG_LoginResponse*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Logout class]]) {
                if (! [((ILMSG_Logout*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Ping class]]) {
                if (! [((ILMSG_Ping*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_Pong class]]) {
                if (! [((ILMSG_Pong*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServerStatus class]]) {
                if (! [((ILMSG_ServerStatus*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_ServiceRequest class]]) {
                if (! [((ILMSG_ServiceRequest*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_VesselData class]]) {
                if (! [((ILMSG_VesselData*) [m_objStack lastObject] ) setHeader: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"LoginRequest"]) {

        ILLoginRequest *obj = (ILLoginRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) setLoginRequest: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"LoginResponse"]) {

        ILLoginResponse *obj = (ILLoginResponse*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) setLoginResponse: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Ping"]) {

        ILPing *obj = (ILPing*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) setPing: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Pong"]) {

        ILPong *obj = (ILPong*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) setPong: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Pos"]) {

        ILPos *obj = (ILPos*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILPosReport class]]) {
                if (! [((ILPosReport*) [m_objStack lastObject] ) setPos: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILArea class]]) {
                if (! [((ILArea*) [m_objStack lastObject] ) addPos: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"PosReport"]) {

        ILPosReport *obj = (ILPosReport*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                if (! [((ILVesselData*) [m_objStack lastObject] ) setPosReport: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Sensor"]) {

        ILSensor *obj = (ILSensor*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILPosReport class]]) {
                if (! [((ILPosReport*) [m_objStack lastObject] ) addSensor: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"StaticData"]) {

        ILStaticData *obj = (ILStaticData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                if (! [((ILVesselData*) [m_objStack lastObject] ) addStaticData: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"ServerStatus"]) {

        ILServerStatus *obj = (ILServerStatus*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) setServerStatus: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"TaggedItem"]) {

        ILTaggedItem *obj = (ILTaggedItem*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                if (! [((ILVesselData*) [m_objStack lastObject] ) addTaggedItem: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"ServiceRequest"]) {

        ILServiceRequest *obj = (ILServiceRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) setServiceRequest: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Area"]) {

        ILArea *obj = (ILArea*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                if (! [((ILServiceRequest*) [m_objStack lastObject] ) addArea: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Transmission"]) {

        ILTransmission *obj = (ILTransmission*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                if (! [((ILServiceRequest*) [m_objStack lastObject] ) setTransmission: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Item"]) {

        ILItem *obj = (ILItem*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                if (! [((ILServiceRequest*) [m_objStack lastObject] ) addItem: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Object"]) {

        ILObject *obj = (ILObject*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                if (! [((ILServiceRequest*) [m_objStack lastObject] ) addObject: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"VesselData"]) {

        ILVesselData *obj = (ILVesselData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                if (! [((ILBody*) [m_objStack lastObject] ) addVesselData: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Voyage"]) {

        ILVoyage *obj = (ILVoyage*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                if (! [((ILVesselData*) [m_objStack lastObject] ) addVoyage: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
}

- (void)parser:(NSXMLParser *)parser parseErrorOccurred:(NSError *)parseError {
    NSLog(@"ILParser.parseErrorOccured: %@", parseError);
    [[NSNotificationCenter defaultCenter] postNotificationName:@"ILParserError" object: self userInfo:[NSDictionary dictionaryWithObject: parseError forKey: @"Error"]];
}

- (BOOL) parseXMLString:(NSString *)data andBuffer: (BOOL) cont {

     // create a seperate memory pool, so we can quickly deallocate temp objects generated by the parser
     NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	  // data may or may not be lead by xml definitions, but we need them before each message
#if defined (__clang__)
	  data = [data stringByReplacingString:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" withString:@""];
     data = [data stringByReplacingString:@"<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n" withString:@""];
#else
	  data = [data stringByReplacingOccurrencesOfString:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" withString:@""];
     data = [data stringByReplacingOccurrencesOfString:@"<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n" withString:@""];
#endif
     [m_dataBuffer appendString: data];

     NSRange firstTagRange;
     do {
         // search if a message is in the buffer
         firstTagRange = NSMakeRange(NSNotFound , 0);
#if defined (__clang__)
         for (int i=0; i < [m_closeTags count]; i++) {
             NSString *tag = [m_closeTags objectAtIndex: i];
#else
         for (NSString *tag in m_closeTags) {
#endif
             NSRange rangeOfTag = [m_dataBuffer rangeOfString:tag];
             if (rangeOfTag.location != NSNotFound) {
                 if (firstTagRange.location != NSNotFound) {
                     if (rangeOfTag.location < firstTagRange.location) {
                         firstTagRange = rangeOfTag;
                     }
                 } else {
                     firstTagRange = rangeOfTag;
                 }
             }
         }
         // process a message if found
         if (firstTagRange.location != NSNotFound) {
             NSRange firstMessageRange = NSMakeRange(0, firstTagRange.location + firstTagRange.length);
             NSString *messages = [NSString stringWithFormat:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<xml>\n%@\n</xml>", [m_dataBuffer substringWithRange:firstMessageRange]];
             [m_dataBuffer deleteCharactersInRange:firstMessageRange];
             NSXMLParser *tempParser = [[NSXMLParser alloc] initWithData:[messages dataUsingEncoding:NSUnicodeStringEncoding]];
             [tempParser setDelegate:self];
             [tempParser parse];
             [tempParser release];
         }        
     } while (firstTagRange.location != NSNotFound);

    if (!cont) {
         [m_dataBuffer setString: @""];
     }

     // free temp memory
     [pool release];

     return YES;
}


@end


