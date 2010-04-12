
#import "ILServerStatus.h"


@implementation ILServerStatus

- (id) init {
    self = [super init];
    if (self != nil) {
        m_contactIdentityPresent = false;
        m_detailsPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_contactIdentity release];
    [m_details release];
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

-(void) setContactIdentity:(NSString *) val {

    m_contactIdentityPresent = true;
    [m_contactIdentity release];
    m_contactIdentity = val;
    [m_contactIdentity retain];
}

- (NSString *) contactIdentity {

    return m_contactIdentity;
}

-(bool) hasContactIdentity {

    return m_contactIdentityPresent;
}

-(void) setDetails:(NSString *) val {

    m_detailsPresent = true;
    [m_details release];
    m_details = val;
    [m_details retain];
}

- (NSString *) details {

    return m_details;
}

-(bool) hasDetails {

    return m_detailsPresent;
}

-(void) setStatus:(bool) val {

    m_status = val;
}

- (bool) status {

    return m_status;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"ContactIdentity"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setContactIdentity: val];
            }
            else if ([key isEqualToString:@"Details"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDetails: val];
            }
            else if ([key isEqualToString:@"Status"]) {
                NSString *value = [attributeDict objectForKey: key];
                bool val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                [self setStatus: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServerStatus"];
    if ( [self hasContactIdentity] ) {
        [xml appendString: @" ContactIdentity=\""];
        [xml appendString: [self encode: m_contactIdentity]];
        [xml appendString: @"\""];
    }
    if ( [self hasDetails] ) {
        [xml appendString: @" Details=\""];
        [xml appendString: [self encode: m_details]];
        [xml appendString: @"\""];
    }
    [xml appendString: @" Status=\""];
    [xml appendString: (m_status?@"true":@"false")];
    [xml appendString: @"\""];
    [xml appendString:@"/>\n"];
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
    [str setString: [lead stringByAppendingString:@"ServerStatus\n"]];
    if ( [self hasContactIdentity] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ContactIdentity = "];
        [str appendString: m_contactIdentity];
        [str appendString: @"\n"];

    }
    if ( [self hasDetails] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Details = "];
        [str appendString: m_details];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Status = "];
    [str appendString: (m_status?@"true":@"false")];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasContactIdentity] ) {
        [attr setObject: m_contactIdentity forKey: @"ContactIdentity"];
    }
    if ( [self hasDetails] ) {
        [attr setObject: m_details forKey: @"Details"];
    }
    [attr setObject: [NSString stringWithFormat:@"%f", m_status] forKey: @"Status"];

    return attr;
}


@end


