
#import "ILSensor.h"


@implementation ILSensor

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

- (void) dealloc {

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

-(void) setSenId:(int) val {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_senId = val;
}

- (int) senId {

    return m_senId;
}

-(void) setTrkId:(int) val {

    if (val < 0)
        return;
    if (val > 65536)
        return;
    m_trkId = val;
}

- (int) trkId {

    return m_trkId;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"SenId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setSenId: val];
            }
            else if ([key isEqualToString:@"TrkId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setTrkId: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Sensor"];
    [xml appendString: @" SenId=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_senId]];
    [xml appendString: @"\""];
    [xml appendString: @" TrkId=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_trkId]];
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
    [str setString: [lead stringByAppendingString:@"Sensor\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SenId = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_senId]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TrkId = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_trkId]];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_senId] forKey: @"SenId"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_trkId] forKey: @"TrkId"];

    return attr;
}


@end


