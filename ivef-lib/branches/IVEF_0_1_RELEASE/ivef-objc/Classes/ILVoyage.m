
#import "ILVoyage.h"


@implementation ILVoyage

- (id) init {
    self = [super init];
    if (self != nil) {
        m_cargoTypePresent = false;
        m_destinationPresent = false;
        m_ETAPresent = false;
        m_ATAPresent = false;
        m_personsOnBoardPresent = false;
        m_airDraughtPresent = false;
        m_draughtPresent = false;
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

-(bool) setIdent:(NSString *) val {

    [m_id release];
    m_id = val;
    [m_id retain];
      return YES;
}

- (NSString *) ident {

    return m_id;
}

-(bool) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
      return YES;
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(bool) setSource:(int) val {

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

-(bool) setCargoType:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 9 ) )
        return NO;
    m_cargoTypePresent = true;
    m_cargoType = val;
      return YES;
}

- (int) cargoType {

    return m_cargoType;
}

-(bool) hasCargoType {

    return m_cargoTypePresent;
}

-(bool) setDestination:(NSString *) val {

    m_destinationPresent = true;
    [m_destination release];
    m_destination = val;
    [m_destination retain];
      return YES;
}

- (NSString *) destination {

    return m_destination;
}

-(bool) hasDestination {

    return m_destinationPresent;
}

-(bool) setETA:(NSDate *) val {

    m_ETAPresent = true;
    [m_ETA release];
    m_ETA = val;
    [m_ETA retain];
      return YES;
}

- (NSDate *) ETA {

    return m_ETA;
}

-(bool) hasETA {

    return m_ETAPresent;
}

-(bool) setATA:(NSDate *) val {

    m_ATAPresent = true;
    [m_ATA release];
    m_ATA = val;
    [m_ATA retain];
      return YES;
}

- (NSDate *) ATA {

    return m_ATA;
}

-(bool) hasATA {

    return m_ATAPresent;
}

-(bool) setPersonsOnBoard:(int) val {

    if (val < 0)
        return NO;
    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
      return YES;
}

- (int) personsOnBoard {

    return m_personsOnBoard;
}

-(bool) hasPersonsOnBoard {

    return m_personsOnBoardPresent;
}

-(bool) setAirDraught:(float) val {

    if (val < 0)
        return NO;
    m_airDraughtPresent = true;
    m_airDraught = val;
      return YES;
}

- (float) airDraught {

    return m_airDraught;
}

-(bool) hasAirDraught {

    return m_airDraughtPresent;
}

-(bool) setDraught:(float) val {

    if (val < 0)
        return NO;
    m_draughtPresent = true;
    m_draught = val;
      return YES;
}

- (float) draught {

    return m_draught;
}

-(bool) hasDraught {

    return m_draughtPresent;
}

-(bool) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Id"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setIdent: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceName: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Source"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setSource: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"CargoType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setCargoType: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Destination"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDestination: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setETA: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ATA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setATA: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"PersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setPersonsOnBoard: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"AirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAirDraught: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Draught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setDraught: val]) {
                   return false;
                }
            }
        }
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


