
#import "ILPong.h"


@implementation ILPong

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

- (void) dealloc {

    [m_timeStamp release];
    [m_msgId release];
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

-(void) setTimeStamp:(NSDate *) val {

    [m_timeStamp release];
    m_timeStamp = val;
    [m_timeStamp retain];
}

- (NSDate *) timeStamp {

    return m_timeStamp;
}

-(void) setMsgId:(NSString *) val {

    [m_msgId release];
    m_msgId = val;
    [m_msgId retain];
}

- (NSString *) msgId {

    return m_msgId;
}

-(void) setSourceId:(int) val {

    m_sourceId = val;
}

- (int) sourceId {

    return m_sourceId;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"TimeStamp"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setTimeStamp: val];
            }
            else if ([key isEqualToString:@"MsgId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setMsgId: val];
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setSourceId: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Pong"];
    [xml appendString: @" TimeStamp=\""];
    [xml appendString: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [xml appendString: @"\""];
    [xml appendString: @" MsgId=\""];
    [xml appendString: [m_msgId encode]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceId=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_sourceId]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Pong>\n"];
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
    [str setString: [lead stringByAppendingString:@"Pong\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TimeStamp=\""];
    [str appendString: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"MsgId=\""];
    [str appendString: m_msgId];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceId=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceId]];
    [str appendString: @"\"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]] forKey: @"TimeStamp"];
    [attr setObject: m_msgId forKey: @"MsgId"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_sourceId] forKey: @"SourceId"];

    return attr;
}


@end


