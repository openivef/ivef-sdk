
#import "ILHeader.h"


@implementation ILHeader

- (id) init {
    self = [super init];
    if (self != nil) {
        m_version = @"0.1.3";
    }
    return self;
}

- (void) dealloc {

    [m_version release];
    [m_msgRefId release];
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

- (NSString *) version {

    return m_version;
}

-(void) setMsgRefId:(NSString *) val {

    [m_msgRefId release];
    m_msgRefId = val;
    [m_msgRefId retain];
}

- (NSString *) msgRefId {

    return m_msgRefId;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Version"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setVersion: val];
            }
            else if ([key isEqualToString:@"MsgRefId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setMsgRefId: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Header"];
    [xml appendString: @" Version=\""];
    [xml appendString: [m_version encode]];
    [xml appendString: @"\""];
    [xml appendString: @" MsgRefId=\""];
    [xml appendString: [m_msgRefId encode]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Header>\n"];
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
    [str setString: [lead stringByAppendingString:@"Header\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Version=\""];
    [str appendString: m_version];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"MsgRefId=\""];
    [str appendString: m_msgRefId];
    [str appendString: @"\"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_version forKey: @"Version"];
    [attr setObject: m_msgRefId forKey: @"MsgRefId"];

    return attr;
}


@end


