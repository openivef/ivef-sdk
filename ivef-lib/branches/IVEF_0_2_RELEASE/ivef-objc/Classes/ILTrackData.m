
#import "ILTrackData.h"


@implementation ILTrackData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_posPresent = NO;
        m_poss = [[NSMutableArray alloc] init];
        m_COGPresent = NO;
        m_estAccSOGPresent = NO;
        m_estAccCOGPresent = NO;
        m_idPresent = NO;
        m_lengthPresent = NO;
        m_navStatusPresent = NO;
        m_headingPresent = NO;
        m_ROTPresent = NO;
        m_SOGPresent = NO;
        m_sourceIdPresent = NO;
        m_sourceNamePresent = NO;
        m_updateTimePresent = NO;
        m_trackStatusPresent = NO;
        m_widthPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_poss release];
    [m_sourceId release];
    [m_sourceName release];
    [m_updateTime release];
    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm:ss.SSS" allowNaturalLanguage:NO];
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
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm:ss.SSS" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm:ss" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm" allowNaturalLanguage:NO];
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

-(BOOL) addPos:(ILPos *) val {

    [m_poss addObject: val];
     return YES;
}

-(ILPos *) posAt:(int) i {

    return [m_poss objectAtIndex: i];
}

-(int) countOfPoss {

    return [m_poss count];
}

-(NSArray *) poss {

    return m_poss;
}

-(BOOL) setCOG:(float) val {

    if (val < 0)
        return NO;
    if (val > 360)
        return NO;
    m_COGPresent = YES;
    m_COG = val;
    return YES;
}

- (float) COG {

    return m_COG;
}

-(BOOL) setEstAccSOG:(float) val {

    m_estAccSOGPresent = YES;
    m_estAccSOG = val;
    return YES;
}

- (float) estAccSOG {

    return m_estAccSOG;
}

-(BOOL) hasEstAccSOG {

    return m_estAccSOGPresent;
}

-(BOOL) setEstAccCOG:(float) val {

    m_estAccCOGPresent = YES;
    m_estAccCOG = val;
    return YES;
}

- (float) estAccCOG {

    return m_estAccCOG;
}

-(BOOL) hasEstAccCOG {

    return m_estAccCOGPresent;
}

-(BOOL) setIdent:(int) val {

    m_idPresent = YES;
    m_id = val;
    return YES;
}

- (int) ident {

    return m_id;
}

-(BOOL) setLength:(float) val {

    if (val < 0)
        return NO;
    m_lengthPresent = YES;
    m_length = val;
    return YES;
}

- (float) length {

    return m_length;
}

-(BOOL) hasLength {

    return m_lengthPresent;
}

-(BOOL) setNavStatus:(int) val {

    if (val < 0)
        return NO;
    if (val > 15)
        return NO;
    m_navStatusPresent = YES;
    m_navStatus = val;
    return YES;
}

- (int) navStatus {

    return m_navStatus;
}

-(BOOL) hasNavStatus {

    return m_navStatusPresent;
}

-(BOOL) setHeading:(float) val {

    if (val < 0)
        return NO;
    if (val > 360)
        return NO;
    m_headingPresent = YES;
    m_heading = val;
    return YES;
}

- (float) heading {

    return m_heading;
}

-(BOOL) hasHeading {

    return m_headingPresent;
}

-(BOOL) setROT:(float) val {

    if (val < -720)
        return NO;
    if (val > 720)
        return NO;
    m_ROTPresent = YES;
    m_ROT = val;
    return YES;
}

- (float) ROT {

    return m_ROT;
}

-(BOOL) hasROT {

    return m_ROTPresent;
}

-(BOOL) setSOG:(float) val {

    if (val < 0)
        return NO;
    m_SOGPresent = YES;
    m_SOG = val;
    return YES;
}

- (float) SOG {

    return m_SOG;
}

-(BOOL) setSourceId:(NSString *) val {

    m_sourceIdPresent = YES;
    [m_sourceId release];
    m_sourceId = val;
    [m_sourceId retain];
    return YES;
}

- (NSString *) sourceId {

    return m_sourceId;
}

-(BOOL) hasSourceId {

    return m_sourceIdPresent;
}

-(BOOL) setSourceName:(NSString *) val {

    m_sourceNamePresent = YES;
    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
    return YES;
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(BOOL) setUpdateTime:(NSDate *) val {

    m_updateTimePresent = YES;
    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
    return YES;
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(BOOL) setTrackStatus:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_trackStatusPresent = YES;
    m_trackStatus = val;
    return YES;
}

- (int) trackStatus {

    return m_trackStatus;
}

-(BOOL) setWidth:(float) val {

    if (val < 0)
        return NO;
    m_widthPresent = YES;
    m_width = val;
    return YES;
}

- (float) width {

    return m_width;
}

-(BOOL) hasWidth {

    return m_widthPresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Pos"]) {
                ILPos * val = [attributeDict objectForKey: key];
                if (![self addPos: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"COG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setCOG: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"EstAccSOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setEstAccSOG: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"EstAccCOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setEstAccCOG: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIdent: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setLength: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"NavStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setNavStatus: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Heading"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setHeading: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ROT"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setROT: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setSOG: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceId: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTime: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"TrackStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setTrackStatus: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Width"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setWidth: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<TrackData"];
    if ( m_COGPresent ) {
        [xml appendString: @" COG=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_COG]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"COG" forKey: @"description"]];
        return nil;
    }
    if ( [self hasEstAccSOG] ) {
        [xml appendString: @" EstAccSOG=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_estAccSOG]];
        [xml appendString: @"\""];
    }
    if ( [self hasEstAccCOG] ) {
        [xml appendString: @" EstAccCOG=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_estAccCOG]];
        [xml appendString: @"\""];
    }
    if ( m_idPresent ) {
        [xml appendString: @" Id=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Id" forKey: @"description"]];
        return nil;
    }
    if ( [self hasLength] ) {
        [xml appendString: @" Length=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_length]];
        [xml appendString: @"\""];
    }
    if ( [self hasNavStatus] ) {
        [xml appendString: @" NavStatus=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_navStatus]];
        [xml appendString: @"\""];
    }
    if ( [self hasHeading] ) {
        [xml appendString: @" Heading=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_heading]];
        [xml appendString: @"\""];
    }
    if ( [self hasROT] ) {
        [xml appendString: @" ROT=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_ROT]];
        [xml appendString: @"\""];
    }
    if ( m_SOGPresent ) {
        [xml appendString: @" SOG=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_SOG]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SOG" forKey: @"description"]];
        return nil;
    }
    if ( [self hasSourceId] ) {
        [xml appendString: @" SourceId=\""];
        [xml appendString: [self encode: m_sourceId]];
        [xml appendString: @"\""];
    }
    if ( m_sourceNamePresent ) {
        [xml appendString: @" SourceName=\""];
        [xml appendString: [self encode: m_sourceName]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceName" forKey: @"description"]];
        return nil;
    }
    if ( m_updateTimePresent ) {
        [xml appendString: @" UpdateTime=\""];
        [xml appendString: [self stringFromDate: m_updateTime]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"UpdateTime" forKey: @"description"]];
        return nil;
    }
    if ( m_trackStatusPresent ) {
        [xml appendString: @" TrackStatus=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_trackStatus]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"TrackStatus" forKey: @"description"]];
        return nil;
    }
    if ( [self hasWidth] ) {
        [xml appendString: @" Width=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_width]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    for(int i=0; i < [m_poss count]; i++ ) {
        ILPos *attribute = [m_poss objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</TrackData>\n"];
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
    [str setString: [lead stringByAppendingString:@"TrackData\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"COG = "];
    [str appendString: [NSString stringWithFormat:@"%f", m_COG]];
    [str appendString: @"\n"];

    if ( [self hasEstAccSOG] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"EstAccSOG = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_estAccSOG]];
        [str appendString: @"\n"];

    }
    if ( [self hasEstAccCOG] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"EstAccCOG = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_estAccCOG]];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\n"];

    if ( [self hasLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Length = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_length]];
        [str appendString: @"\n"];

    }
    if ( [self hasNavStatus] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"NavStatus = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_navStatus]];
        [str appendString: @"\n"];

    }
    if ( [self hasHeading] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Heading = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_heading]];
        [str appendString: @"\n"];

    }
    if ( [self hasROT] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ROT = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_ROT]];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SOG = "];
    [str appendString: [NSString stringWithFormat:@"%f", m_SOG]];
    [str appendString: @"\n"];

    if ( [self hasSourceId] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SourceId = "];
        [str appendString: m_sourceId];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName = "];
    [str appendString: m_sourceName];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime = "];
    [str appendString: [self stringFromDate: m_updateTime]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TrackStatus = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_trackStatus]];
    [str appendString: @"\n"];

    if ( [self hasWidth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Width = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_width]];
        [str appendString: @"\n"];

    }
    for(int i=0; i < [m_poss count]; i++ ) {
        ILPos *attribute = [m_poss objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%f", m_COG] forKey: @"COG"];
    if ( [self hasEstAccSOG] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_estAccSOG] forKey: @"EstAccSOG"];
    }
    if ( [self hasEstAccCOG] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_estAccCOG] forKey: @"EstAccCOG"];
    }
    [attr setObject: [NSString stringWithFormat:@"%d", m_id] forKey: @"Id"];
    if ( [self hasLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_length] forKey: @"Length"];
    }
    if ( [self hasNavStatus] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_navStatus] forKey: @"NavStatus"];
    }
    if ( [self hasHeading] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_heading] forKey: @"Heading"];
    }
    if ( [self hasROT] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_ROT] forKey: @"ROT"];
    }
    [attr setObject: [NSString stringWithFormat:@"%f", m_SOG] forKey: @"SOG"];
    if ( [self hasSourceId] ) {
        [attr setObject: m_sourceId forKey: @"SourceId"];
    }
    [attr setObject: m_sourceName forKey: @"SourceName"];
    [attr setObject: [self stringFromDate: m_updateTime] forKey: @"UpdateTime"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_trackStatus] forKey: @"TrackStatus"];
    if ( [self hasWidth] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_width] forKey: @"Width"];
    }

    return attr;
}


@end


