
#import "ILWaypoint.h"


@implementation ILWaypoint

- (id) init {
    self = [super init];
    if (self != nil) {
        m_ATAPresent = false;
        m_ETAPresent = false;
        m_RTAPresent = false;
        m_loCodePresent = false;
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

-(void) setPos:(ILPos *) val {

    [m_pos release];
    m_pos = val;
    [m_pos retain];
}

- (ILPos *) pos {

    return m_pos;
}

-(void) setATA:(NSDate *) val {

    m_ATAPresent = true;
    [m_ATA release];
    m_ATA = val;
    [m_ATA retain];
}

- (NSDate *) ATA {

    return m_ATA;
}

-(bool) hasATA {

    return m_ATAPresent;
}

-(void) setETA:(NSDate *) val {

    m_ETAPresent = true;
    [m_ETA release];
    m_ETA = val;
    [m_ETA retain];
}

- (NSDate *) ETA {

    return m_ETA;
}

-(bool) hasETA {

    return m_ETAPresent;
}

-(void) setRTA:(NSDate *) val {

    m_RTAPresent = true;
    [m_RTA release];
    m_RTA = val;
    [m_RTA retain];
}

- (NSDate *) RTA {

    return m_RTA;
}

-(bool) hasRTA {

    return m_RTAPresent;
}

-(void) setLoCode:(NSString *) val {

    m_loCodePresent = true;
    [m_loCode release];
    m_loCode = val;
    [m_loCode retain];
}

- (NSString *) loCode {

    return m_loCode;
}

-(bool) hasLoCode {

    return m_loCodePresent;
}

-(void) setName:(NSString *) val {

    [m_name release];
    m_name = val;
    [m_name retain];
}

- (NSString *) name {

    return m_name;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Pos"]) {
                ILPos * val = [attributeDict objectForKey: key];
                [self setPos: val];
            }
            else if ([key isEqualToString:@"ATA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setATA: val];
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setETA: val];
            }
            else if ([key isEqualToString:@"RTA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setRTA: val];
            }
            else if ([key isEqualToString:@"LoCode"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setLoCode: val];
            }
            else if ([key isEqualToString:@"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setName: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Waypoint"];
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
    [xml appendString: @" Name=\""];
    [xml appendString: [self encode: m_name]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: [m_pos XML] ];
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
        [str appendString: @"ATA = \""];
        [str appendString: [self stringFromDate: m_ATA]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = \""];
        [str appendString: [self stringFromDate: m_ETA]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasRTA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"RTA = \""];
        [str appendString: [self stringFromDate: m_RTA]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasLoCode] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"LoCode = \""];
        [str appendString: m_loCode];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Name=\""];
    [str appendString: m_name];
    [str appendString: @"\"\n"];

    [str appendString: [m_pos stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
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


