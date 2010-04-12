
#import "ILIdentifier.h"


@implementation ILIdentifier

- (id) init {
    self = [super init];
    if (self != nil) {
        m_otherIds = [[NSMutableArray alloc] init];
        m_otherNames = [[NSMutableArray alloc] init];
        m_callsignPresent = false;
        m_IMOPresent = false;
        m_namePresent = false;
        m_MMSIPresent = false;
        m_LRITPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_otherIds release];
    [m_otherNames release];
    [m_callsign release];
    [m_name release];
    [m_LRIT release];
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

-(void) addOtherId:(ILOtherId *) val {

    [m_otherIds addObject: val];
}

-(ILOtherId *) otherIdAt:(int) i {

    return [m_otherIds objectAtIndex: i];
}

-(int) countOfOtherIds {

    return [m_otherIds count];
}

-(NSArray *) otherIds {

    return m_otherIds;
}

-(void) addOtherName:(ILOtherName *) val {

    [m_otherNames addObject: val];
}

-(ILOtherName *) otherNameAt:(int) i {

    return [m_otherNames objectAtIndex: i];
}

-(int) countOfOtherNames {

    return [m_otherNames count];
}

-(NSArray *) otherNames {

    return m_otherNames;
}

-(void) setCallsign:(NSString *) val {

    m_callsignPresent = true;
    [m_callsign release];
    m_callsign = val;
    [m_callsign retain];
}

- (NSString *) callsign {

    return m_callsign;
}

-(bool) hasCallsign {

    return m_callsignPresent;
}

-(void) setIMO:(int) val {

    m_IMOPresent = true;
    m_IMO = val;
}

- (int) IMO {

    return m_IMO;
}

-(bool) hasIMO {

    return m_IMOPresent;
}

-(void) setName:(NSString *) val {

    m_namePresent = true;
    [m_name release];
    m_name = val;
    [m_name retain];
}

- (NSString *) name {

    return m_name;
}

-(bool) hasName {

    return m_namePresent;
}

-(void) setMMSI:(int) val {

    m_MMSIPresent = true;
    m_MMSI = val;
}

- (int) MMSI {

    return m_MMSI;
}

-(bool) hasMMSI {

    return m_MMSIPresent;
}

-(void) setLRIT:(NSString *) val {

    m_LRITPresent = true;
    [m_LRIT release];
    m_LRIT = val;
    [m_LRIT retain];
}

- (NSString *) LRIT {

    return m_LRIT;
}

-(bool) hasLRIT {

    return m_LRITPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"OtherId"]) {
                ILOtherId * val = [attributeDict objectForKey: key];
                [self addOtherId: val];
            }
            else if ([key isEqualToString:@"OtherName"]) {
                ILOtherName * val = [attributeDict objectForKey: key];
                [self addOtherName: val];
            }
            else if ([key isEqualToString:@"Callsign"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setCallsign: val];
            }
            else if ([key isEqualToString:@"IMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setIMO: val];
            }
            else if ([key isEqualToString:@"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setName: val];
            }
            else if ([key isEqualToString:@"MMSI"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setMMSI: val];
            }
            else if ([key isEqualToString:@"LRIT"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setLRIT: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Identifier"];
    if ( [self hasCallsign] ) {
        [xml appendString: @" Callsign=\""];
        [xml appendString: [self encode: m_callsign]];
        [xml appendString: @"\""];
    }
    if ( [self hasIMO] ) {
        [xml appendString: @" IMO=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_IMO]];
        [xml appendString: @"\""];
    }
    if ( [self hasName] ) {
        [xml appendString: @" Name=\""];
        [xml appendString: [self encode: m_name]];
        [xml appendString: @"\""];
    }
    if ( [self hasMMSI] ) {
        [xml appendString: @" MMSI=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_MMSI]];
        [xml appendString: @"\""];
    }
    if ( [self hasLRIT] ) {
        [xml appendString: @" LRIT=\""];
        [xml appendString: [self encode: m_LRIT]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    for(int i=0; i < [m_otherIds count]; i++ ) {
        ILOtherId *attribute = [m_otherIds objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_otherNames count]; i++ ) {
        ILOtherName *attribute = [m_otherNames objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</Identifier>\n"];
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
    [str setString: [lead stringByAppendingString:@"Identifier\n"]];
    if ( [self hasCallsign] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Callsign = "];
        [str appendString: m_callsign];
        [str appendString: @"\n"];

    }
    if ( [self hasIMO] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"IMO = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_IMO]];
        [str appendString: @"\n"];

    }
    if ( [self hasName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Name = "];
        [str appendString: m_name];
        [str appendString: @"\n"];

    }
    if ( [self hasMMSI] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MMSI = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_MMSI]];
        [str appendString: @"\n"];

    }
    if ( [self hasLRIT] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"LRIT = "];
        [str appendString: m_LRIT];
        [str appendString: @"\n"];

    }
    for(int i=0; i < [m_otherIds count]; i++ ) {
        ILOtherId *attribute = [m_otherIds objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_otherNames count]; i++ ) {
        ILOtherName *attribute = [m_otherNames objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasCallsign] ) {
        [attr setObject: m_callsign forKey: @"Callsign"];
    }
    if ( [self hasIMO] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_IMO] forKey: @"IMO"];
    }
    if ( [self hasName] ) {
        [attr setObject: m_name forKey: @"Name"];
    }
    if ( [self hasMMSI] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_MMSI] forKey: @"MMSI"];
    }
    if ( [self hasLRIT] ) {
        [attr setObject: m_LRIT forKey: @"LRIT"];
    }

    return attr;
}


@end


