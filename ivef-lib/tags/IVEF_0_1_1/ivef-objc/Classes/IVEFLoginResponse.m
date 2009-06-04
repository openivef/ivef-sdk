
#import "IVEFLoginResponse.h"


@implementation IVEFLoginResponse

- (id) init {
    self = [super init];
    if (self != nil) {
        m_reasonPresent = false;
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setMsgId:(NSString *) val {

    [m_msgId release];
    m_msgId = val;
    [m_msgId retain];
}

- (NSString *) getMsgId {

    return m_msgId;
}

-(void) setResult:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_result = val;
}

- (int) getResult {

    return m_result;
}

-(void) setReason:(NSString *) val {

    m_reasonPresent = true;
    [m_reason release];
    m_reason = val;
    [m_reason retain];
}

- (NSString *) getReason {

    return m_reason;
}

-(bool) hasReason {

    return m_reasonPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"MsgId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setMsgId: val];
            }
            else if ([key isEqualToString:@"Result"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setResult: val];
            }
            else if ([key isEqualToString:@"Reason"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setReason: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<LoginResponse"];
    [xml appendString: @" MsgId=\""];
    [xml appendString: [m_msgId encode]];
    [xml appendString: @"\""];
    [xml appendString: @" Result=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_result]];
    [xml appendString: @"\""];
    if ( [self hasReason] ) {
        [xml appendString: @" Reason=\""];
        [xml appendString: [m_reason encode]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: @"</LoginResponse>\n"];
    return xml;
}

-(NSString *) encode: (NSString *) input {

    NSMutableString *str = [[[NSMutableString alloc] initWithString: input] autorelease];

    [str replaceOccurrencesOfString: @"&" withString: "&amp;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: "&lt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: "&gt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: "&quot;") options: nil searchRange: NSMakeRange(0, [str length])];

    return str;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"LoginResponse\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"MsgId=\""];
    [str appendString: m_msgId];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Result=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_result]];
    [str appendString: @"\"\n"];

    if ( [self hasReason] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Reason = \""];
        [str appendString: m_reason];
    }
    return str;
}


@end


