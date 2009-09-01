
#import "ILServerStatus.h"


@implementation ILServerStatus

- (id) init {
    self = [super init];
    if (self != nil) {
        m_detailsPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_status release];
    [m_details release];
    [super dealloc];
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

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
     static NSDateFormatter *formatterWithMinutes = nil;
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

-(void) setStatus:(NSString *) val {

    if ( ( ![val isEqualToString: @"queuefull"] ) &&
         ( ![val isEqualToString: @"ok"] ) )
        return;
    [m_status release];
    m_status = val;
    [m_status retain];
}

- (NSString *) status {

    return m_status;
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

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Status"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setStatus: val];
            }
            else if ([key isEqualToString:@"Details"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDetails: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServerStatus"];
    [xml appendString: @" Status=\""];
    [xml appendString: [self encode: m_status]];
    [xml appendString: @"\""];
    if ( [self hasDetails] ) {
        [xml appendString: @" Details=\""];
        [xml appendString: [self encode: m_details]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: @"</ServerStatus>\n"];
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
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Status=\""];
    [str appendString: m_status];
    [str appendString: @"\"\n"];

    if ( [self hasDetails] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Details = \""];
        [str appendString: m_details];
        [str appendString: @"\"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_status forKey: @"Status"];
    if ( [self hasDetails] ) {
        [attr setObject: m_details forKey: @"Details"];
    }

    return attr;
}


@end


