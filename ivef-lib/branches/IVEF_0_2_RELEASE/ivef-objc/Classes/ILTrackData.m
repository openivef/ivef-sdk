
#import "ILTrackData.h"


@implementation ILTrackData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_poss = [[NSMutableArray alloc] init];
        m_estAccSOGPresent = false;
        m_estAccCOGPresent = false;
        m_lengthPresent = false;
        m_navStatusPresent = false;
        m_headingPresent = false;
        m_ROTPresent = false;
        m_sourceIdPresent = false;
        m_widthPresent = false;
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

-(void) addPos:(ILPos *) val {

    [m_poss addObject: val];
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

-(void) setCOG:(float) val {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_COG = val;
}

- (float) COG {

    return m_COG;
}

-(void) setEstAccSOG:(float) val {

    m_estAccSOGPresent = true;
    m_estAccSOG = val;
}

- (float) estAccSOG {

    return m_estAccSOG;
}

-(bool) hasEstAccSOG {

    return m_estAccSOGPresent;
}

-(void) setEstAccCOG:(float) val {

    m_estAccCOGPresent = true;
    m_estAccCOG = val;
}

- (float) estAccCOG {

    return m_estAccCOG;
}

-(bool) hasEstAccCOG {

    return m_estAccCOGPresent;
}

-(void) setIdent:(int) val {

    m_id = val;
}

- (int) ident {

    return m_id;
}

-(void) setLength:(float) val {

    if (val < 0)
        return;
    m_lengthPresent = true;
    m_length = val;
}

- (float) length {

    return m_length;
}

-(bool) hasLength {

    return m_lengthPresent;
}

-(void) setNavStatus:(int) val {

    if (val < 0)
        return;
    if (val > 15)
        return;
    m_navStatusPresent = true;
    m_navStatus = val;
}

- (int) navStatus {

    return m_navStatus;
}

-(bool) hasNavStatus {

    return m_navStatusPresent;
}

-(void) setHeading:(float) val {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_headingPresent = true;
    m_heading = val;
}

- (float) heading {

    return m_heading;
}

-(bool) hasHeading {

    return m_headingPresent;
}

-(void) setROT:(float) val {

    if (val < -720)
        return;
    if (val > 720)
        return;
    m_ROTPresent = true;
    m_ROT = val;
}

- (float) ROT {

    return m_ROT;
}

-(bool) hasROT {

    return m_ROTPresent;
}

-(void) setSOG:(float) val {

    if (val < 0)
        return;
    m_SOG = val;
}

- (float) SOG {

    return m_SOG;
}

-(void) setSourceId:(NSString *) val {

    m_sourceIdPresent = true;
    [m_sourceId release];
    m_sourceId = val;
    [m_sourceId retain];
}

- (NSString *) sourceId {

    return m_sourceId;
}

-(bool) hasSourceId {

    return m_sourceIdPresent;
}

-(void) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(void) setUpdateTime:(NSDate *) val {

    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(void) setTrackStatus:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_trackStatus = val;
}

- (int) trackStatus {

    return m_trackStatus;
}

-(void) setWidth:(float) val {

    if (val < 0)
        return;
    m_widthPresent = true;
    m_width = val;
}

- (float) width {

    return m_width;
}

-(bool) hasWidth {

    return m_widthPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Pos"]) {
                ILPos * val = [attributeDict objectForKey: key];
                [self addPos: val];
            }
            else if ([key isEqualToString:@"COG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setCOG: val];
            }
            else if ([key isEqualToString:@"EstAccSOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setEstAccSOG: val];
            }
            else if ([key isEqualToString:@"EstAccCOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setEstAccCOG: val];
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setIdent: val];
            }
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLength: val];
            }
            else if ([key isEqualToString:@"NavStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setNavStatus: val];
            }
            else if ([key isEqualToString:@"Heading"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setHeading: val];
            }
            else if ([key isEqualToString:@"ROT"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setROT: val];
            }
            else if ([key isEqualToString:@"SOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setSOG: val];
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceId: val];
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceName: val];
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setUpdateTime: val];
            }
            else if ([key isEqualToString:@"TrackStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setTrackStatus: val];
            }
            else if ([key isEqualToString:@"Width"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setWidth: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<TrackData"];
    [xml appendString: @" COG=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_COG]];
    [xml appendString: @"\""];
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
    [xml appendString: @" Id=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
    [xml appendString: @"\""];
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
    [xml appendString: @" SOG=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_SOG]];
    [xml appendString: @"\""];
    if ( [self hasSourceId] ) {
        [xml appendString: @" SourceId=\""];
        [xml appendString: [self encode: m_sourceId]];
        [xml appendString: @"\""];
    }
    [xml appendString: @" SourceName=\""];
    [xml appendString: [self encode: m_sourceName]];
    [xml appendString: @"\""];
    [xml appendString: @" UpdateTime=\""];
    [xml appendString: [self stringFromDate: m_updateTime]];
    [xml appendString: @"\""];
    [xml appendString: @" TrackStatus=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_trackStatus]];
    [xml appendString: @"\""];
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


