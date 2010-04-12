
#import "ILPos.h"


@implementation ILPos

- (id) init {
    self = [super init];
    if (self != nil) {
        m_altitudePresent = false;
        m_estAccAltPresent = false;
        m_estAccLatPresent = false;
        m_estAccLongPresent = false;
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

-(void) setAltitude:(float) val {

    m_altitudePresent = true;
    m_altitude = val;
}

- (float) altitude {

    return m_altitude;
}

-(bool) hasAltitude {

    return m_altitudePresent;
}

-(void) setEstAccAlt:(float) val {

    m_estAccAltPresent = true;
    m_estAccAlt = val;
}

- (float) estAccAlt {

    return m_estAccAlt;
}

-(bool) hasEstAccAlt {

    return m_estAccAltPresent;
}

-(void) setEstAccLat:(float) val {

    m_estAccLatPresent = true;
    m_estAccLat = val;
}

- (float) estAccLat {

    return m_estAccLat;
}

-(bool) hasEstAccLat {

    return m_estAccLatPresent;
}

-(void) setEstAccLong:(float) val {

    m_estAccLongPresent = true;
    m_estAccLong = val;
}

- (float) estAccLong {

    return m_estAccLong;
}

-(bool) hasEstAccLong {

    return m_estAccLongPresent;
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
            if ([key isEqualToString: @"Altitude"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setAltitude: val];
            }
            else if ([key isEqualToString:@"EstAccAlt"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setEstAccAlt: val];
            }
            else if ([key isEqualToString:@"EstAccLat"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setEstAccLat: val];
            }
            else if ([key isEqualToString:@"EstAccLong"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setEstAccLong: val];
            }
            else if ([key isEqualToString:@"Lat"]) {
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
    [xml appendString: @" Lat=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_lat]];
    [xml appendString: @"\""];
    [xml appendString: @" Long=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_long]];
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
    [str appendString: [NSString stringWithFormat:@"%f", m_lat]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Long = "];
    [str appendString: [NSString stringWithFormat:@"%f", m_long]];
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
    [attr setObject: [NSString stringWithFormat:@"%f", m_lat] forKey: @"Lat"];
    [attr setObject: [NSString stringWithFormat:@"%f", m_long] forKey: @"Long"];

    return attr;
}


@end


