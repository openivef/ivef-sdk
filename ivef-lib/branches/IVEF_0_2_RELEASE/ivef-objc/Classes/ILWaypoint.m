
#import "ILWaypoint.h"


@implementation ILWaypoint

- (id) init {
    self = [super init];
    if (self != nil) {
        m_posPresent = NO;
        m_ATAPresent = NO;
        m_ETAPresent = NO;
        m_RTAPresent = NO;
        m_loCodePresent = NO;
        m_namePresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_pos release];
    [m_ATA release];
    [m_ETA release];
    [m_RTA release];
    [m_loCode release];
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

-(BOOL) setPos:(ILPos *) val {

    m_posPresent = YES;
    [m_pos release];
    m_pos = val;
    [m_pos retain];
    return YES;
}

- (ILPos *) pos {

    return m_pos;
}

-(BOOL) hasPos {

    return m_posPresent;
}

-(BOOL) setATA:(NSDate *) val {

    m_ATAPresent = YES;
    [m_ATA release];
    m_ATA = val;
    [m_ATA retain];
    return YES;
}

- (NSDate *) ATA {

    return m_ATA;
}

-(BOOL) hasATA {

    return m_ATAPresent;
}

-(BOOL) setETA:(NSDate *) val {

    m_ETAPresent = YES;
    [m_ETA release];
    m_ETA = val;
    [m_ETA retain];
    return YES;
}

- (NSDate *) ETA {

    return m_ETA;
}

-(BOOL) hasETA {

    return m_ETAPresent;
}

-(BOOL) setRTA:(NSDate *) val {

    m_RTAPresent = YES;
    [m_RTA release];
    m_RTA = val;
    [m_RTA retain];
    return YES;
}

- (NSDate *) RTA {

    return m_RTA;
}

-(BOOL) hasRTA {

    return m_RTAPresent;
}

-(BOOL) setLoCode:(NSString *) val {

    if ([val length] < 5)
        return NO;
    if ([val length] > 15)
        return NO;
    m_loCodePresent = YES;
    [m_loCode release];
    m_loCode = val;
    [m_loCode retain];
    return YES;
}

- (NSString *) loCode {

    return m_loCode;
}

-(BOOL) hasLoCode {

    return m_loCodePresent;
}

-(BOOL) setName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
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

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"ATA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setATA: val]) {
                   return NO;
                }
                if (![self setATA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setETA: val]) {
                   return NO;
                }
                if (![self setETA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"RTA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setRTA: val]) {
                   return NO;
                }
                if (![self setRTA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"LoCode"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setLoCode: val]) {
                   return NO;
                }
                if (![self setLoCode: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setName: val]) {
                   return NO;
                }
                if (![self setName: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Waypoint"];
    NSString *dataMember;
    if ( [self hasATA] ) {
        [xml appendString: @" ATA=\""];
        [xml appendString: [self stringFromDate: m_ATA]];
        [xml appendString: @"\""];
    }
    if ( [self hasETA] ) {
        [xml appendString: @" ETA=\""];
        [xml appendString: [self stringFromDate: m_ETA]];
        [xml appendString: @"\""];
    }
    if ( [self hasRTA] ) {
        [xml appendString: @" RTA=\""];
        [xml appendString: [self stringFromDate: m_RTA]];
        [xml appendString: @"\""];
    }
    if ( [self hasLoCode] ) {
        [xml appendString: @" LoCode=\""];
        [xml appendString: [self encode: m_loCode]];
        [xml appendString: @"\""];
    }
    if ( m_namePresent ) {
        [xml appendString: @" Name=\""];
        [xml appendString: [self encode: m_name]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Name" forKey: @"description"]];
        return nil;
    }
    [xml appendString:@">\n"];
    if ( [self hasPos] ) {
        dataMember = [m_pos XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Pos" forKey: @"description"]];
            return nil;
        }
    }
    [xml appendString: @"</Waypoint>\n"];
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
    [str setString: [lead stringByAppendingString:@"Waypoint\n"]];
    if ( [self hasATA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATA = "];
        [str appendString: [self stringFromDate: m_ATA]];
        [str appendString: @"\n"];

    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = "];
        [str appendString: [self stringFromDate: m_ETA]];
        [str appendString: @"\n"];

    }
    if ( [self hasRTA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"RTA = "];
        [str appendString: [self stringFromDate: m_RTA]];
        [str appendString: @"\n"];

    }
    if ( [self hasLoCode] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"LoCode = "];
        [str appendString: m_loCode];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Name = "];
    [str appendString: m_name];
    [str appendString: @"\n"];

    if ( [self hasPos] ) {
        [str appendString: [m_pos stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasATA] ) {
        [attr setObject: [self stringFromDate: m_ATA] forKey: @"ATA"];
    }
    if ( [self hasETA] ) {
        [attr setObject: [self stringFromDate: m_ETA] forKey: @"ETA"];
    }
    if ( [self hasRTA] ) {
        [attr setObject: [self stringFromDate: m_RTA] forKey: @"RTA"];
    }
    if ( [self hasLoCode] ) {
        [attr setObject: m_loCode forKey: @"LoCode"];
    }
    [attr setObject: m_name forKey: @"Name"];

    return attr;
}


@end


