
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

    [m_reason release];
    [m_responseOn release];
    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
     }
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss"];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-dd'T'HH:mm"];
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

-(void) setResponseOn:(NSString *) val {

    [m_responseOn release];
    m_responseOn = val;
    [m_responseOn retain];
}

- (NSString *) responseOn {

    return m_responseOn;
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

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Reason"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setReason: val];
            }
            else if ([key isEqualToString:@"ResponseOn"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setResponseOn: val];
            }
            else if ([key isEqualToString:@"Result"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setResult: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<LoginResponse"];
    if ( [self hasReason] ) {
        [xml appendString: @" Reason=\""];
        [xml appendString: [self encode: m_reason]];
        [xml appendString: @"\""];
    }
    [xml appendString: @" ResponseOn=\""];
    [xml appendString: [self encode: m_responseOn]];
    [xml appendString: @"\""];
    [xml appendString: @" Result=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_result]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</LoginResponse>\n"];
    return xml;
}

-(NSString *) encode: (NSString *) input {

    NSMutableString *str = [[[NSMutableString alloc] initWithString: input] autorelease];

    [str replaceOccurrencesOfString: @"&" withString: @"&amp;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: @"&lt;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: @"&gt;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: @"&quot;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];

    return str;
}

-(NSString *) stringValue {

    return [self stringValueWithLead:@""];
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"LoginResponse\n"]];
    if ( [self hasReason] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Reason = \""];
        [str appendString: m_reason];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"ResponseOn=\""];
    [str appendString: m_responseOn];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Result=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_result]];
    [str appendString: @"\"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasReason] ) {
        [attr setObject: m_reason forKey: @"Reason"];
    }
    [attr setObject: m_responseOn forKey: @"ResponseOn"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_result] forKey: @"Result"];

    return attr;
}


@end


