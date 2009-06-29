
#import "IVEFPong.h"


@implementation IVEFPong

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setTimeStamp:(NSDate *) val {

    [m_timeStamp release];
    m_timeStamp = val;
    [m_timeStamp retain];
}

- (NSDate *) getTimeStamp {

    return m_timeStamp;
}

-(void) setMsgId:(NSString *) val {

    [m_msgId release];
    m_msgId = val;
    [m_msgId retain];
}

- (NSString *) getMsgId {

    return m_msgId;
}

-(void) setSourceId:(int) val {

    m_sourceId = val;
}

- (int) getSourceId {

    return m_sourceId;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"TimeStamp"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [m_dateFormatter dateFromString: value]; // assume "yyyy-MM-ddThh:mm:ss.zzz"
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
    [xml appendString: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
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

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Pong\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TimeStamp=\""];
    [str appendString: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
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


@end


