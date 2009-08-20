
#import "ILLoginResponse.h"


@implementation ILLoginResponse

- (id) init {
    self = [super init];
    if (self != nil) {
        m_reasonPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_msgId release];
    [m_reason release];
    [super dealloc];
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [NSString stringByReplacingOccurrencesOfString:@"Z" withString:@];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-ddThh:mm:ss.zzz"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-ddThh:mm:ss"];
     }
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-ddThh:mm"];
     }
     NSDate *val = [formatterWithMillies dateFromString:str];
     if (val) {
         return val;
     }
     val = [formatterWithSeconds dateFromString:str];
     if (val) {
         return val;
     }
     val = [formatterWithMinutes dateFromString:str];
     if (val) {
         return val;
     }
     return nil; // invalid date
}

-(void) setMsgId:(NSString *) val {

    [m_msgId release];
    m_msgId = val;
    [m_msgId retain];
}

- (NSString *) msgId {

    return m_msgId;
}

-(void) setResult:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_result = val;
}

- (int) result {

    return m_result;
}

-(void) setReason:(NSString *) val {

    m_reasonPresent = true;
    [m_reason release];
    m_reason = val;
    [m_reason retain];
}

- (NSString *) reason {

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

-(NSString *) stringValue {

    return [self stringValueWithLead:@""];
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
        [str appendString: @"\"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_msgId forKey: @"MsgId"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_result] forKey: @"Result"];
    if ( [self hasReason] ) {
        [attr setObject: m_reason forKey: @"Reason"];
    }

    return attr;
}


@end


