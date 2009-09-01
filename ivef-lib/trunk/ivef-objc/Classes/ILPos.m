
#import "ILPos.h"


@implementation ILPos

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

- (void) dealloc {

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

-(void) setLat:(float) val {

    if (val < -90)
        return;
    if (val > 90)
        return;
    m_lat = val;
}

- (float) lat {

    return m_lat;
}

-(void) setLong:(float) val {

    if (val < -180)
        return;
    if (val > 180)
        return;
    m_long = val;
}

- (float) long {

    return m_long;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Lat"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLat: val];
            }
            else if ([key isEqualToString:@"Long"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLong: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Pos"];
    [xml appendString: @" Lat=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_lat]];
    [xml appendString: @"\""];
    [xml appendString: @" Long=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_long]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Pos>\n"];
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
    [str setString: [lead stringByAppendingString:@"Pos\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Lat=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_lat]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Long=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_long]];
    [str appendString: @"\"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%f", m_lat] forKey: @"Lat"];
    [attr setObject: [NSString stringWithFormat:@"%f", m_long] forKey: @"Long"];

    return attr;
}


@end


