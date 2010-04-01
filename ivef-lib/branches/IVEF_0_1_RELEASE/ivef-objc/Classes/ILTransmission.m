
#import "ILTransmission.h"


@implementation ILTransmission

- (id) init {
    self = [super init];
    if (self != nil) {
        m_periodPresent = false;
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

-(void) setType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) )
        return;
    m_type = val;
}

- (int) type {

    return m_type;
}

-(void) setPeriod:(float) val {

    m_periodPresent = true;
    m_period = val;
}

- (float) period {

    return m_period;
}

-(bool) hasPeriod {

    return m_periodPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Type"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setType: val];
            }
            else if ([key isEqualToString:@"Period"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setPeriod: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Transmission"];
    [xml appendString: @" Type=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_type]];
    [xml appendString: @"\""];
    if ( [self hasPeriod] ) {
        [xml appendString: @" Period=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_period]];
        [xml appendString: @"\""];
    }
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
    [str setString: [lead stringByAppendingString:@"Transmission\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Type=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_type]];
    [str appendString: @"\"\n"];

    if ( [self hasPeriod] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Period = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_period]];
        [str appendString: @"\"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_type] forKey: @"Type"];
    if ( [self hasPeriod] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_period] forKey: @"Period"];
    }

    return attr;
}


@end


