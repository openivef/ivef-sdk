
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

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-ddThh:mm:ss.zzz"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-ddThh:mm:ss"];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-ddThh:mm"];
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

-(void) setIdent:(NSString *) val {

    [m_id release];
    m_id = val;
    [m_id retain];
}

- (NSString *) ident {

    return m_id;
}

-(void) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(void) setSource:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_source = val;
}

- (int) source {

    return m_source;
}

-(void) setCargoType:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 9 ) )
        return;
    m_cargoTypePresent = true;
    m_cargoType = val;
}

- (int) cargoType {

    return m_cargoType;
}

-(bool) hasCargoType {

    return m_cargoTypePresent;
}

-(void) setDestination:(NSString *) val {

    m_destinationPresent = true;
    [m_destination release];
    m_destination = val;
    [m_destination retain];
}

- (NSString *) destination {

    return m_destination;
}

-(bool) hasDestination {

    return m_destinationPresent;
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

-(void) setPersonsOnBoard:(float) val {

    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
}

- (float) personsOnBoard {

    return m_personsOnBoard;
}

-(bool) hasPersonsOnBoard {

    return m_personsOnBoardPresent;
}

-(void) setAirDraught:(float) val {

    m_airDraughtPresent = true;
    m_airDraught = val;
}

- (float) airDraught {

    return m_airDraught;
}

-(bool) hasAirDraught {

    return m_airDraughtPresent;
}

-(void) setDraught:(float) val {

    m_draughtPresent = true;
    m_draught = val;
}

- (float) draught {

    return m_draught;
}

-(bool) hasDraught {

    return m_draughtPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Id"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setIdent: val];
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceName: val];
            }
            else if ([key isEqualToString:@"Source"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setSource: val];
            }
            else if ([key isEqualToString:@"CargoType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setCargoType: val];
            }
            else if ([key isEqualToString:@"Destination"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDestination: val];
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setETA: val];
            }
            else if ([key isEqualToString:@"ATA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setATA: val];
            }
            else if ([key isEqualToString:@"PersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setPersonsOnBoard: val];
            }
            else if ([key isEqualToString:@"AirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setAirDraught: val];
            }
            else if ([key isEqualToString:@"Draught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setDraught: val];
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
        [xml appendString: [m_ETA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
        [xml appendString: @"\""];
    }
    if ( [self hasATA] ) {
        [xml appendString: @" ATA=\""];
        [xml appendString: [m_ATA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
        [xml appendString: @"\""];
    }
    if ( [self hasPersonsOnBoard] ) {
        [xml appendString: @" PersonsOnBoard=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_personsOnBoard]];
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
    [xml appendString:@">\n"];
    [xml appendString: @"</Voyage>\n"];
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
    [str appendString: @"Id=\""];
    [str appendString: m_id];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName=\""];
    [str appendString: m_sourceName];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Source=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_source]];
    [str appendString: @"\"\n"];

    if ( [self hasCargoType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CargoType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_cargoType]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasDestination] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Destination = \""];
        [str appendString: m_destination];
        [str appendString: @"\"\n"];

    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = \""];
        [str appendString: [m_ETA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasATA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATA = \""];
        [str appendString: [m_ATA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasPersonsOnBoard] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PersonsOnBoard = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_personsOnBoard]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AirDraught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_airDraught]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Draught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_draught]];
        [str appendString: @"\"\n"];

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
        [attr setObject: [m_ETA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]] forKey: @"ETA"];
    }
    if ( [self hasATA] ) {
        [attr setObject: [m_ATA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]] forKey: @"ATA"];
    }
    if ( [self hasPersonsOnBoard] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_personsOnBoard] forKey: @"PersonsOnBoard"];
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


