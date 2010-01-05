
#import "ILParser.h"


@implementation ILParser

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dataBuffer = [[NSMutableString alloc] init];
        m_objStack = [[NSMutableArray alloc] init];
        m_closeTags = [[NSArray arrayWithObjects:@"</MSG_IVEF>", nil] retain];
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
    if ([elementName isEqualToString: @"MSG_IVEF"]) {
        ILMSG_IVEF *obj = [[ILMSG_IVEF alloc] init];
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
    else if ([elementName isEqualToString: @"Area"]) {
        ILArea *obj = [[ILArea alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"OtherId"]) {
        ILOtherId *obj = [[ILOtherId alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"OtherName"]) {
        ILOtherName *obj = [[ILOtherName alloc] init];
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
    else if ([elementName isEqualToString: @"Logout"]) {
        ILLogout *obj = [[ILLogout alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"ObjectData"]) {
        ILObjectData *obj = [[ILObjectData alloc] init];
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
    else if ([elementName isEqualToString: @"ServerStatus"]) {
        ILServerStatus *obj = [[ILServerStatus alloc] init];
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
    else if ([elementName isEqualToString: @"Filter"]) {
        ILFilter *obj = [[ILFilter alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"ServiceRequestResponse"]) {
        ILServiceRequestResponse *obj = [[ILServiceRequestResponse alloc] init];
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
    else if ([elementName isEqualToString: @"TrackData"]) {
        ILTrackData *obj = [[ILTrackData alloc] init];
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
    else if ([elementName isEqualToString: @"Construction"]) {
        ILConstruction *obj = [[ILConstruction alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"UnType"]) {
        ILUnType *obj = [[ILUnType alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Identifier"]) {
        ILIdentifier *obj = [[ILIdentifier alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"VoyageData"]) {
        ILVoyageData *obj = [[ILVoyageData alloc] init];
        [obj setAttributes: attributeDict];
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Waypoint"]) {
        ILWaypoint *obj = [[ILWaypoint alloc] init];
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
    if ([elementName isEqualToString: @"MSG_IVEF"]) {

        ILMSG_IVEF *obj = (ILMSG_IVEF*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewILMSG_IVEF" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Body"]) {

        ILBody *obj = (ILBody*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_IVEF class]]) {
                [((ILMSG_IVEF*) [m_objStack lastObject] ) setBody: obj ];
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
    else if ([elementName isEqualToString: @"OtherId"]) {

        ILOtherId *obj = (ILOtherId*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILIdentifier class]]) {
                [((ILIdentifier*) [m_objStack lastObject] ) addOtherId: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"OtherName"]) {

        ILOtherName *obj = (ILOtherName*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILIdentifier class]]) {
                [((ILIdentifier*) [m_objStack lastObject] ) addOtherName: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Header"]) {

        ILHeader *obj = (ILHeader*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILMSG_IVEF class]]) {
                [((ILMSG_IVEF*) [m_objStack lastObject] ) setHeader: obj ];
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
    else if ([elementName isEqualToString: @"Logout"]) {

        ILLogout *obj = (ILLogout*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setLogout: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"ObjectData"]) {

        ILObjectData *obj = (ILObjectData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setObjectData: obj ];
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
        if ( [[m_objStack lastObject] isKindOfClass: [ILArea class]]) {
                [((ILArea*) [m_objStack lastObject] ) addPos: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILTrackData class]]) {
                [((ILTrackData*) [m_objStack lastObject] ) addPos: obj ];
        }
        if ( [[m_objStack lastObject] isKindOfClass: [ILWaypoint class]]) {
                [((ILWaypoint*) [m_objStack lastObject] ) setPos: obj ];
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
    else if ([elementName isEqualToString: @"ServiceRequest"]) {

        ILServiceRequest *obj = (ILServiceRequest*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setServiceRequest: obj ];
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
    else if ([elementName isEqualToString: @"Filter"]) {

        ILFilter *obj = (ILFilter*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILServiceRequest class]]) {
                [((ILServiceRequest*) [m_objStack lastObject] ) setFilter: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"ServiceRequestResponse"]) {

        ILServiceRequestResponse *obj = (ILServiceRequestResponse*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILBody class]]) {
                [((ILBody*) [m_objStack lastObject] ) setServiceRequestResponse: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"TaggedItem"]) {

        ILTaggedItem *obj = (ILTaggedItem*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILObjectData class]]) {
                [((ILObjectData*) [m_objStack lastObject] ) addTaggedItem: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"TrackData"]) {

        ILTrackData *obj = (ILTrackData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILObjectData class]]) {
                [((ILObjectData*) [m_objStack lastObject] ) setTrackData: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"VesselData"]) {

        ILVesselData *obj = (ILVesselData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILObjectData class]]) {
                [((ILObjectData*) [m_objStack lastObject] ) addVesselData: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Construction"]) {

        ILConstruction *obj = (ILConstruction*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                [((ILVesselData*) [m_objStack lastObject] ) setConstruction: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"UnType"]) {

        ILUnType *obj = (ILUnType*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILConstruction class]]) {
                [((ILConstruction*) [m_objStack lastObject] ) setUnType: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Identifier"]) {

        ILIdentifier *obj = (ILIdentifier*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVesselData class]]) {
                [((ILVesselData*) [m_objStack lastObject] ) setIdentifier: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"VoyageData"]) {

        ILVoyageData *obj = (ILVoyageData*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILObjectData class]]) {
                [((ILObjectData*) [m_objStack lastObject] ) addVoyageData: obj ];
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Waypoint"]) {

        ILWaypoint *obj = (ILWaypoint*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [ILVoyageData class]]) {
                [((ILVoyageData*) [m_objStack lastObject] ) addWaypoint: obj ];
        }
        [obj release]; 
    }
}

- (void)parser:(NSXMLParser *)parser parseErrorOccurred:(NSError *)parseError {
    NSLog(@"ILParser.parseErrorOccured: %@", parseError);
    [[NSNotificationCenter defaultCenter] postNotificationName:@"ILParserError" object: self userInfo:parseError];
}

- (bool) parseXMLString:(NSString *)data andBuffer: (bool) cont {

     // create a seperate memory pool, so we can quickly deallocate temp objects generated by the parser
     NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	  // data may or may not be lead by xml definitions, but we need them before each message
	  data = [data stringByReplacingOccurrencesOfString:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n" withString:@""];
     data = [data stringByReplacingOccurrencesOfString:@"<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n" withString:@""];
     [m_dataBuffer appendString: data];

     NSRange firstTagRange;
     do {
         // search if a message is in the buffer
        firstTagRange = NSMakeRange(NSNotFound , 0);
         for (NSString *tag in m_closeTags) {
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

     return true;
}


@end


