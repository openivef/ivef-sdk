
#import "IVEFSensor.h"


@implementation IVEFSensor

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setSenId:(float) val {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_senId = val;
}

- (float) getSenId {

    return m_senId;
}

-(void) setTrkId:(float) val {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_trkId = val;
}

- (float) getTrkId {

    return m_trkId;
}

-(void) setUpdateTime:(NSDate *) val {

    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
}

- (NSDate *) getUpdateTime {

    return m_updateTime;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"SenId"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setSenId: val];
            }
            else if ([key isEqualToString:@"TrkId"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setTrkId: val];
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [m_dateFormatter dateFromString: value]; // assume "yyyy-MM-ddThh:mm:ss.zzz"
                [self setUpdateTime: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Sensor"];
    [xml appendString: @" SenId=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_senId]];
    [xml appendString: @"\""];
    [xml appendString: @" TrkId=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_trkId]];
    [xml appendString: @"\""];
    [xml appendString: @" UpdateTime=\""];
    [xml appendString: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Sensor>\n"];
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
    [str setString: [lead stringByAppendingString:@"Sensor\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SenId=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_senId]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TrkId=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_trkId]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime=\""];
    [str appendString: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [str appendString: @"\"\n"];

    return str;
}


@end


