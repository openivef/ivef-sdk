
#import "ILVoyage.h"


@implementation ILVoyage

- (id) init {
    self = [super init];
    if (self != nil) {
        m_cargoTypePresent = NO;
        m_destinationPresent = NO;
        m_ETAPresent = NO;
        m_ATAPresent = NO;
        m_personsOnBoardPresent = NO;
        m_airDraughtPresent = NO;
        m_draughtPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_id release];
    [m_sourceName release];
    [m_destination release];
    [m_ETA release];
    [m_ATA release];
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

-(BOOL) setIdent:(NSString *) val {

    [m_id release];
    m_id = val;
    [m_id retain];
    return YES;
}

- (NSString *) ident {

    return m_id;
}

-(BOOL) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
    return YES;
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(BOOL) setSource:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_source = val;
    return YES;
}

- (int) source {

    return m_source;
}

-(BOOL) setCargoType:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 9 ) )
        return NO;
    m_cargoTypePresent = YES;
    m_cargoType = val;
    return YES;
}

- (int) cargoType {

    return m_cargoType;
}

-(BOOL) hasCargoType {

    return m_cargoTypePresent;
}

-(BOOL) setDestination:(NSString *) val {

    m_destinationPresent = YES;
    [m_destination release];
    m_destination = val;
    [m_destination retain];
    return YES;
}

- (NSString *) destination {

    return m_destination;
}

-(BOOL) hasDestination {

    return m_destinationPresent;
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

-(BOOL) setPersonsOnBoard:(int) val {

    if (val < 0)
        return NO;
    m_personsOnBoardPresent = YES;
    m_personsOnBoard = val;
    return YES;
}

- (int) personsOnBoard {

    return m_personsOnBoard;
}

-(BOOL) hasPersonsOnBoard {

    return m_personsOnBoardPresent;
}

-(BOOL) setAirDraught:(float) val {

    if (val < 0)
        return NO;
    m_airDraughtPresent = YES;
    m_airDraught = val;
    return YES;
}

- (float) airDraught {

    return m_airDraught;
}

-(BOOL) hasAirDraught {

    return m_airDraughtPresent;
}

-(BOOL) setDraught:(float) val {

    if (val < 0)
        return NO;
    m_draughtPresent = YES;
    m_draught = val;
    return YES;
}

- (float) draught {

    return m_draught;
}

-(BOOL) hasDraught {

    return m_draughtPresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Id"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setIdent: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Source"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setSource: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"CargoType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setCargoType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Destination"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDestination: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setETA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ATA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setATA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"PersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setPersonsOnBoard: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"AirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAirDraught: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Draught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setDraught: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Voyage"];
    [xml appendString: @" Id=\""];
    [xml appendString: [self encode: m_id]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceName=\""];
    [xml appendString: [self encode: m_sourceName]];
    [xml appendString: @"\""];
    [xml appendString: @" Source=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_source]];
    [xml appendString: @"\""];
    if ( [self hasCargoType] ) {
        [xml appendString: @" CargoType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_cargoType]];
        [xml appendString: @"\""];
    }
    if ( [self hasDestination] ) {
        [xml appendString: @" Destination=\""];
        [xml appendString: [self encode: m_destination]];
        [xml appendString: @"\""];
    }
    if ( [self hasETA] ) {
        [xml appendString: @" ETA=\""];
        [xml appendString: [self stringFromDate: m_ETA]];
        [xml appendString: @"\""];
    }
    if ( [self hasATA] ) {
        [xml appendString: @" ATA=\""];
        [xml appendString: [self stringFromDate: m_ATA]];
        [xml appendString: @"\""];
    }
    if ( [self hasPersonsOnBoard] ) {
        [xml appendString: @" PersonsOnBoard=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_personsOnBoard]];
        [xml appendString: @"\""];
    }
    if ( [self hasAirDraught] ) {
        [xml appendString: @" AirDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_airDraught]];
        [xml appendString: @"\""];
    }
    if ( [self hasDraught] ) {
        [xml appendString: @" Draught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_draught]];
        [xml appendString: @"\""];
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
    [str setString: [lead stringByAppendingString:@"Voyage\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id = "];
    [str appendString: m_id];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName = "];
    [str appendString: m_sourceName];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Source = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_source]];
    [str appendString: @"\n"];

    if ( [self hasCargoType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CargoType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_cargoType]];
        [str appendString: @"\n"];

    }
    if ( [self hasDestination] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Destination = "];
        [str appendString: m_destination];
        [str appendString: @"\n"];

    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = "];
        [str appendString: [self stringFromDate: m_ETA]];
        [str appendString: @"\n"];

    }
    if ( [self hasATA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATA = "];
        [str appendString: [self stringFromDate: m_ATA]];
        [str appendString: @"\n"];

    }
    if ( [self hasPersonsOnBoard] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PersonsOnBoard = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_personsOnBoard]];
        [str appendString: @"\n"];

    }
    if ( [self hasAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AirDraught = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_airDraught]];
        [str appendString: @"\n"];

    }
    if ( [self hasDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Draught = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_draught]];
        [str appendString: @"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_id forKey: @"Id"];
    [attr setObject: m_sourceName forKey: @"SourceName"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_source] forKey: @"Source"];
    if ( [self hasCargoType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_cargoType] forKey: @"CargoType"];
    }
    if ( [self hasDestination] ) {
        [attr setObject: m_destination forKey: @"Destination"];
    }
    if ( [self hasETA] ) {
        [attr setObject: [self stringFromDate: m_ETA] forKey: @"ETA"];
    }
    if ( [self hasATA] ) {
        [attr setObject: [self stringFromDate: m_ATA] forKey: @"ATA"];
    }
    if ( [self hasPersonsOnBoard] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_personsOnBoard] forKey: @"PersonsOnBoard"];
    }
    if ( [self hasAirDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_airDraught] forKey: @"AirDraught"];
    }
    if ( [self hasDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_draught] forKey: @"Draught"];
    }

    return attr;
}


@end


