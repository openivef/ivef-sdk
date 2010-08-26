
#import "ILPos.h"


@implementation ILPos

- (id) init {
    self = [super init];
    if (self != nil) {
        m_altitudePresent = NO;
        m_estAccAltPresent = NO;
        m_estAccLatPresent = NO;
        m_estAccLongPresent = NO;
        m_latPresent = NO;
        m_longPresent = NO;
    }
    return self;
}

- (void) dealloc {

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

-(BOOL) setAltitude:(float) val {

    m_altitudePresent = YES;
    m_altitude = val;
    return YES;
}

- (float) altitude {

    return m_altitude;
}

-(BOOL) hasAltitude {

    return m_altitudePresent;
}

-(BOOL) setEstAccAlt:(float) val {

    m_estAccAltPresent = YES;
    m_estAccAlt = val;
    return YES;
}

- (float) estAccAlt {

    return m_estAccAlt;
}

-(BOOL) hasEstAccAlt {

    return m_estAccAltPresent;
}

-(BOOL) setEstAccLat:(float) val {

    m_estAccLatPresent = YES;
    m_estAccLat = val;
    return YES;
}

- (float) estAccLat {

    return m_estAccLat;
}

-(BOOL) hasEstAccLat {

    return m_estAccLatPresent;
}

-(BOOL) setEstAccLong:(float) val {

    m_estAccLongPresent = YES;
    m_estAccLong = val;
    return YES;
}

- (float) estAccLong {

    return m_estAccLong;
}

-(BOOL) hasEstAccLong {

    return m_estAccLongPresent;
}

-(BOOL) setLat:(float) val {

    if (val < -90)
        return NO;
    if (val > 90)
        return NO;
    m_latPresent = YES;
    m_lat = val;
    return YES;
}

- (float) lat {

    return m_lat;
}

-(BOOL) setLong:(float) val {

    if (val < -180)
        return NO;
    if (val > 180)
        return NO;
    m_longPresent = YES;
    m_long = val;
    return YES;
}

- (float) long {

    return m_long;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Altitude"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAltitude: val]) {
                   return NO;
                }
                if (![self setAltitude: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"EstAccAlt"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setEstAccAlt: val]) {
                   return NO;
                }
                if (![self setEstAccAlt: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"EstAccLat"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setEstAccLat: val]) {
                   return NO;
                }
                if (![self setEstAccLat: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"EstAccLong"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setEstAccLong: val]) {
                   return NO;
                }
                if (![self setEstAccLong: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Lat"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setLat: val]) {
                   return NO;
                }
                if (![self setLat: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Long"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setLong: val]) {
                   return NO;
                }
                if (![self setLong: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Pos"];
    if ( [self hasAltitude] ) {
        [xml appendString: @" Altitude=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_altitude]];
        [xml appendString: @"\""];
    }
    if ( [self hasEstAccAlt] ) {
        [xml appendString: @" EstAccAlt=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_estAccAlt]];
        [xml appendString: @"\""];
    }
    if ( [self hasEstAccLat] ) {
        [xml appendString: @" EstAccLat=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_estAccLat]];
        [xml appendString: @"\""];
    }
    if ( [self hasEstAccLong] ) {
        [xml appendString: @" EstAccLong=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_estAccLong]];
        [xml appendString: @"\""];
    }
    if ( m_latPresent ) {
        [xml appendString: @" Lat=\""];
        [xml appendString: [NSString stringWithFormat:@"%.5f", m_lat]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Lat" forKey: @"description"]];
        return nil;
    }
    if ( m_longPresent ) {
        [xml appendString: @" Long=\""];
        [xml appendString: [NSString stringWithFormat:@"%.5f", m_long]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Long" forKey: @"description"]];
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
    [str setString: [lead stringByAppendingString:@"Pos\n"]];
    if ( [self hasAltitude] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Altitude = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_altitude]];
        [str appendString: @"\n"];

    }
    if ( [self hasEstAccAlt] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"EstAccAlt = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_estAccAlt]];
        [str appendString: @"\n"];

    }
    if ( [self hasEstAccLat] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"EstAccLat = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_estAccLat]];
        [str appendString: @"\n"];

    }
    if ( [self hasEstAccLong] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"EstAccLong = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_estAccLong]];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Lat = "];
    [str appendString: [NSString stringWithFormat:@"%.5f", m_lat]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Long = "];
    [str appendString: [NSString stringWithFormat:@"%.5f", m_long]];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasAltitude] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_altitude] forKey: @"Altitude"];
    }
    if ( [self hasEstAccAlt] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_estAccAlt] forKey: @"EstAccAlt"];
    }
    if ( [self hasEstAccLat] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_estAccLat] forKey: @"EstAccLat"];
    }
    if ( [self hasEstAccLong] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_estAccLong] forKey: @"EstAccLong"];
    }
    [attr setObject: [NSString stringWithFormat:@"%.5f", m_lat] forKey: @"Lat"];
    [attr setObject: [NSString stringWithFormat:@"%.5f", m_long] forKey: @"Long"];

    return attr;
}


@end


