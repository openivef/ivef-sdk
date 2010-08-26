
#import "ILIdentifier.h"


@implementation ILIdentifier

- (id) init {
    self = [super init];
    if (self != nil) {
        m_otherIds = [[NSMutableArray alloc] init];
        m_otherIdPresent = NO;
        m_otherNames = [[NSMutableArray alloc] init];
        m_otherNamePresent = NO;
        m_callsignPresent = NO;
        m_IMOPresent = NO;
        m_namePresent = NO;
        m_formerNamePresent = NO;
        m_flagPresent = NO;
        m_ownerPresent = NO;
        m_MMSIPresent = NO;
        m_LRITPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_otherIds release];
    [m_otherNames release];
    [m_callsign release];
    [m_name release];
    [m_formerName release];
    [m_flag release];
    [m_owner release];
    [m_LRIT release];
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

-(BOOL) removeOtherId:(ILOtherId *) val {

    [m_otherIds removeObject: val];
     return YES;
}

-(BOOL) addOtherId:(ILOtherId *) val {

    [m_otherIds addObject: val];
     return YES;
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

-(BOOL) removeOtherName:(ILOtherName *) val {

    [m_otherNames removeObject: val];
     return YES;
}

-(BOOL) addOtherName:(ILOtherName *) val {

    [m_otherNames addObject: val];
     return YES;
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

-(BOOL) setCallsign:(NSString *) val {

    if ([val length] < 0)
        return NO;
    if ([val length] > 9)
        return NO;
    m_callsignPresent = YES;
    [m_callsign release];
    m_callsign = val;
    [m_callsign retain];
    return YES;
}

- (NSString *) callsign {

    return m_callsign;
}

-(BOOL) hasCallsign {

    return m_callsignPresent;
}

-(BOOL) setIMO:(int) val {

    m_IMOPresent = YES;
    m_IMO = val;
    return YES;
}

- (int) IMO {

    return m_IMO;
}

-(BOOL) hasIMO {

    return m_IMOPresent;
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

-(BOOL) hasName {

    return m_namePresent;
}

-(BOOL) setFormerName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_formerNamePresent = YES;
    [m_formerName release];
    m_formerName = val;
    [m_formerName retain];
    return YES;
}

- (NSString *) formerName {

    return m_formerName;
}

-(BOOL) hasFormerName {

    return m_formerNamePresent;
}

-(BOOL) setFlag:(NSString *) val {

    if ([val length] < 2)
        return NO;
    if ([val length] > 2)
        return NO;
    m_flagPresent = YES;
    [m_flag release];
    m_flag = val;
    [m_flag retain];
    return YES;
}

- (NSString *) flag {

    return m_flag;
}

-(BOOL) hasFlag {

    return m_flagPresent;
}

-(BOOL) setOwner:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_ownerPresent = YES;
    [m_owner release];
    m_owner = val;
    [m_owner retain];
    return YES;
}

- (NSString *) owner {

    return m_owner;
}

-(BOOL) hasOwner {

    return m_ownerPresent;
}

-(BOOL) setMMSI:(int) val {

    m_MMSIPresent = YES;
    m_MMSI = val;
    return YES;
}

- (int) MMSI {

    return m_MMSI;
}

-(BOOL) hasMMSI {

    return m_MMSIPresent;
}

-(BOOL) setLRIT:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_LRITPresent = YES;
    [m_LRIT release];
    m_LRIT = val;
    [m_LRIT retain];
    return YES;
}

- (NSString *) LRIT {

    return m_LRIT;
}

-(BOOL) hasLRIT {

    return m_LRITPresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Callsign"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCallsign: val]) {
                   return NO;
                }
                if (![self setCallsign: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"IMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIMO: val]) {
                   return NO;
                }
                if (![self setIMO: val]) {
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
            else if ([key isEqualToString:@"FormerName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setFormerName: val]) {
                   return NO;
                }
                if (![self setFormerName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Flag"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setFlag: val]) {
                   return NO;
                }
                if (![self setFlag: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Owner"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setOwner: val]) {
                   return NO;
                }
                if (![self setOwner: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MMSI"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setMMSI: val]) {
                   return NO;
                }
                if (![self setMMSI: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"LRIT"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setLRIT: val]) {
                   return NO;
                }
                if (![self setLRIT: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Identifier"];
    NSString *dataMember;
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
    if ( [self hasFormerName] ) {
        [xml appendString: @" FormerName=\""];
        [xml appendString: [self encode: m_formerName]];
        [xml appendString: @"\""];
    }
    if ( [self hasFlag] ) {
        [xml appendString: @" Flag=\""];
        [xml appendString: [self encode: m_flag]];
        [xml appendString: @"\""];
    }
    if ( [self hasOwner] ) {
        [xml appendString: @" Owner=\""];
        [xml appendString: [self encode: m_owner]];
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
    if ([m_otherIds count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of OtherId" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_otherIds count]; i++ ) {
        ILOtherId *attribute = [m_otherIds objectAtIndex:i];
        dataMember = [attribute XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"OtherId" forKey: @"description"]];
            return nil;
        }
    }
    if ([m_otherNames count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of OtherName" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_otherNames count]; i++ ) {
        ILOtherName *attribute = [m_otherNames objectAtIndex:i];
        dataMember = [attribute XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"OtherName" forKey: @"description"]];
            return nil;
        }
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
    if ( [self hasFormerName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"FormerName = "];
        [str appendString: m_formerName];
        [str appendString: @"\n"];

    }
    if ( [self hasFlag] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Flag = "];
        [str appendString: m_flag];
        [str appendString: @"\n"];

    }
    if ( [self hasOwner] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Owner = "];
        [str appendString: m_owner];
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
    if ( [self hasFormerName] ) {
        [attr setObject: m_formerName forKey: @"FormerName"];
    }
    if ( [self hasFlag] ) {
        [attr setObject: m_flag forKey: @"Flag"];
    }
    if ( [self hasOwner] ) {
        [attr setObject: m_owner forKey: @"Owner"];
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


