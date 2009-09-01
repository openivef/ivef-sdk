
#import "ILSensor.h"


@implementation ILSensor

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

- (void) dealloc {

    [m_updateTime release];
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

-(void) setSenId:(float) val {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_senId = val;
}

- (float) senId {

    return m_senId;
}

-(void) setTrkId:(float) val {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_trkId = val;
}

- (float) trkId {

    return m_trkId;
}

-(void) setUpdateTime:(NSDate *) val {

    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
}

- (NSDate *) updateTime {

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
                NSDate *val = [self dateFromString: value];
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
    [xml appendString: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Sensor>\n"];
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
    [str appendString: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [str appendString: @"\"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%f", m_senId] forKey: @"SenId"];
    [attr setObject: [NSString stringWithFormat:@"%f", m_trkId] forKey: @"TrkId"];
    [attr setObject: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]] forKey: @"UpdateTime"];

    return attr;
}


@end


