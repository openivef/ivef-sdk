
#import "ILSensor.h"


@implementation ILSensor

- (id) init {
    self = [super init];
    if (self != nil) {
        m_senIdPresent = NO;
        m_trkIdPresent = NO;
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
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
#if defined (__clang__)
     return [[formatterWithMillies stringForObjectValue:date] stringByAppendingString:@"Z"]; // always zulu time
#else
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
#endif
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
#if defined (__clang__)
     str = [str stringByReplacingString:@"Z" withString:@""];

#else
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

#endif
     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M" allowNaturalLanguage:NO];
     }
#if defined (__clang__)
     NSDate *val;
     [formatterWithMillies getObjectValue: &val forString: str errorDescription: nil];
#else
     NSDate *val = [formatterWithMillies dateFromString:str];
#endif
     if (val) {
         return val;
     }
#if defined (__clang__)
     [formatterWithSeconds getObjectValue: &val forString: str errorDescription: nil];
#else
     val = [formatterWithSeconds dateFromString:str];
#endif
     if (val) {
         return val;
     }
#if defined (__clang__)
     [formatterWithMinutes getObjectValue: &val forString: str errorDescription: nil];
#else
     val = [formatterWithMinutes dateFromString:str];
#endif
     if (val) {
         return val;
     }
     return nil; // invalid date
}

-(BOOL) setSenId:(int) val {

    if (val < 0)
        return NO;
    if (val > 65536)
        return NO;
    m_senIdPresent = YES;
    m_senId = val;
    return YES;
}

- (int) senId {

    return m_senId;
}

-(BOOL) setTrkId:(int) val {

    if (val < 0)
        return NO;
    if (val > 65536)
        return NO;
    m_trkIdPresent = YES;
    m_trkId = val;
    return YES;
}

- (int) trkId {

    return m_trkId;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"SenId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setSenId: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"TrkId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setTrkId: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Sensor"];
    NSString *dataMember;
    if ( m_senIdPresent ) {
        [xml appendString: @" SenId=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_senId]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SenId" forKey: @"description"]];
        return nil;
    }
    if ( m_trkIdPresent ) {
        [xml appendString: @" TrkId=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_trkId]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"TrkId" forKey: @"description"]];
        return nil;
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


