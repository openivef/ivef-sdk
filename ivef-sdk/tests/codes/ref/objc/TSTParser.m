
#import "TSTParser.h"


@implementation TSTParser

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dataBuffer = [[NSMutableString alloc] init];
        m_characterBuffer = [[NSMutableString alloc] init];
        m_objStack = [[NSMutableArray alloc] init];
        m_closeTags = [[NSArray arrayWithObjects:@"</MSG_Notification>", @"</Argument>", @"</AreaName>", nil] retain];
    }
    return self;
}

- (void) dealloc {
        [m_dataBuffer release];
        [m_objStack release];
        [m_closeTags release];
        [super dealloc];
}

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string {
    [m_characterBuffer appendString: [string stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceAndNewlineCharacterSet]]];
}

- (void)     parser:(NSXMLParser *)parser 
    didStartElement:(NSString *)elementName
       namespaceURI:(NSString *)namespaceURI
      qualifiedName:(NSString *)qualifiedName
         attributes:(NSDictionary *)attributeDict {
    // clear the character buffer
    [m_characterBuffer setString: @""];

    // check all possible options
    if ([elementName isEqualToString: @"MSG_Notification"]) {
        TSTMSG_Notification *obj = [[TSTMSG_Notification alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Message"]) {
        TSTMessage *obj = [[TSTMessage alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"Argument"]) {
        // data will follow and end up in the m_characterBuffer
    }
    else if ([elementName isEqualToString: @"Event"]) {
        TSTEvent *obj = [[TSTEvent alloc] init];
        if (! [obj setAttributes: attributeDict] ) {
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
        };
        [m_objStack addObject: obj ];
        [obj release];
    }
    else if ([elementName isEqualToString: @"AreaName"]) {
        // data will follow and end up in the m_characterBuffer
    }
}

- (void)     parser:(NSXMLParser *)parser 
      didEndElement:(NSString *)elementName
       namespaceURI:(NSString *)namespaceURI
      qualifiedName:(NSString *)qualifiedName {
    // check all possible options
    if ([elementName isEqualToString: @"MSG_Notification"]) {

        TSTMSG_Notification *obj = (TSTMSG_Notification*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"NewTSTMSG_Notification" object: self userInfo:[NSDictionary dictionaryWithObject: obj forKey: @"Data"]]; 
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Message"]) {

        TSTMessage *obj = (TSTMessage*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [TSTMSG_Notification class]]) {
                if (! [((TSTMSG_Notification*) [m_objStack lastObject] ) addMessage: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"Argument"]) {

        if ( [[m_objStack lastObject] isKindOfClass: [TSTMessage class]]) {
            TSTMessage* parent = [m_objStack lastObject];

            // add the found characters to the parent
            [parent setArgument: m_characterBuffer];

            // clear the character buffer
            [m_characterBuffer setString: @""];
        }
    }
    else if ([elementName isEqualToString: @"Event"]) {

        TSTEvent *obj = (TSTEvent*) [m_objStack lastObject];
        [obj retain];
        [m_objStack removeLastObject];
        if ( [[m_objStack lastObject] isKindOfClass: [TSTMSG_Notification class]]) {
                if (! [((TSTMSG_Notification*) [m_objStack lastObject] ) addEvent: obj ] ) {
                   [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: elementName forKey: @"description"]];
                };
        }
        [obj release]; 
    }
    else if ([elementName isEqualToString: @"AreaName"]) {

        if ( [[m_objStack lastObject] isKindOfClass: [TSTEvent class]]) {
            TSTEvent* parent = [m_objStack lastObject];

            // add the found characters to the parent
            [parent setAreaName: m_characterBuffer];

            // clear the character buffer
            [m_characterBuffer setString: @""];
        }
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


