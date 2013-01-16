
#import "TSTEvent.h"


@implementation TSTEvent

- (id) init {
    self = [super init];
    if (self != nil) {
        m_areaNamePresent = NO;
        m_namePresent = NO;
        m_idPresent = NO;
        m_speedPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_areaName release];
    [m_name release];
    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
     [formatterWithMillies setTimeZone:timeZone];
#if defined (__clang__)
     return [[formatterWithMillies stringForObjectValue:date] stringByAppendingString:@"Z"]; // always zulu time
#else
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
#endif
}

- (NSDate*) dateFromString:(NSString *)str {

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
     // new date strings can be in Zulu time
     NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
     if ([str characterAtIndex: [str length] - 1] == 'Z') {
         [formatterWithMillies setTimeZone:timeZone]; // localtime is default
         [formatterWithSeconds setTimeZone:timeZone]; // localtime is default
         [formatterWithMinutes setTimeZone:timeZone]; // localtime is default
#if defined (__clang__)
         str = [str stringByReplacingString:@"Z" withString:@""];

#else
         str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

#endif
     }
     // convert
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

-(BOOL) setAreaName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 36)
        return NO;
    m_areaNamePresent = YES;
    [m_areaName release];
    m_areaName = val;
    [m_areaName retain];
    return YES;
}

- (NSString *) areaName {

    return m_areaName;
}

-(BOOL) hasAreaName {

    return m_areaNamePresent;
}

-(BOOL) setName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 36)
        return NO;
    m_namePresent = YES;
    [m_name release];
    m_name = val;
    [m_name retain];
    return YES;
}

- (NSString *) name {

    return m_name;
}

-(BOOL) hasName {

    return m_namePresent;
}

-(BOOL) setIdent:(int) val {

    if (val <= 0)
        return NO;
    if (val >= 10000)
        return NO;
    m_idPresent = YES;
    m_id = val;
    return YES;
}

- (int) ident {

    return m_id;
}

-(BOOL) hasId {

    return m_idPresent;
}

-(BOOL) setSpeed:(float) val {

    if (val < 0)
        return NO;
    if (val > 1000.1)
        return NO;
    m_speedPresent = YES;
    m_speed = val;
    return YES;
}

- (float) speed {

    return m_speed;
}

-(BOOL) hasSpeed {

    return m_speedPresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setName: val]) {
                   return NO;
                }
                if (![self setName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIdent: val]) {
                   return NO;
                }
                if (![self setIdent: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Speed"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setSpeed: val]) {
                   return NO;
                }
                if (![self setSpeed: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Event"];
    NSString *dataMember;
    if ( [self hasName] ) {
        [xml appendString: @" Name=\""];
        [xml appendString: [self encode: m_name]];
        [xml appendString: @"\""];
    }
    if ( [self hasId] ) {
        [xml appendString: @" Id=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
        [xml appendString: @"\""];
    }
    if ( [self hasSpeed] ) {
        [xml appendString: @" Speed=\""];
        [xml appendString: [NSString stringWithFormat:@"%.2f", m_speed]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    if ( [self hasAreaName] ) {
            [xml appendString: @"<AreaName>"];
            [xml appendString: m_areaName];
            [xml appendString: @"</AreaName>"];
    }
    [xml appendString: @"</Event>\n"];
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
    [str setString: [lead stringByAppendingString:@"Event\n"]];
    if ( [self hasName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Name = "];
        [str appendString: m_name];
        [str appendString: @"\n"];

    }
    if ( [self hasId] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Id = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_id]];
        [str appendString: @"\n"];

    }
    if ( [self hasSpeed] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Speed = "];
        [str appendString: [NSString stringWithFormat:@"%.2f", m_speed]];
        [str appendString: @"\n"];

    }
    if ( [self hasAreaName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AreaName = "];
        [str appendString: m_areaName];
        [str appendString: @"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasName] ) {
        [attr setObject: m_name forKey: @"Name"];
    }
    if ( [self hasId] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_id] forKey: @"Id"];
    }
    if ( [self hasSpeed] ) {
        [attr setObject: [NSString stringWithFormat:@"%.2f", m_speed] forKey: @"Speed"];
    }

    return attr;
}


@end


