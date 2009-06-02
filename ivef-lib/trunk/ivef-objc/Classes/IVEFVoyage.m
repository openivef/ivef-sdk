
#import "IVEFVoyage.h"


@implementation IVEFVoyage

- (id) init {
    self = [super init];
    if (self != nil) {
        m_cargoTypePresent = false;
        m_destinationPresent = false;
        m_ETAPresent = false;
        m_ATAPresent = false;
        m_airDraughtPresent = false;
        m_draughtPresent = false;
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setId:(NSString *) val {

    [m_id release];
    m_id = val;
    [m_id retain];
}

- (NSString *) getId {

    return m_id;
}

-(void) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
}

- (NSString *) getSourceName {

    return m_sourceName;
}

-(void) setSource:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_source = val;
}

- (int) getSource {

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

- (int) getCargoType {

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

- (NSString *) getDestination {

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

- (NSDate *) getETA {

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

- (NSDate *) getATA {

    return m_ATA;
}

-(bool) hasATA {

    return m_ATAPresent;
}

-(void) setAirDraught:(float) val {

    m_airDraughtPresent = true;
    m_airDraught = val;
}

- (float) getAirDraught {

    return m_airDraught;
}

-(bool) hasAirDraught {

    return m_airDraughtPresent;
}

-(void) setDraught:(float) val {

    m_draughtPresent = true;
    m_draught = val;
}

- (float) getDraught {

    return m_draught;
}

-(bool) hasDraught {

    return m_draughtPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Id"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setId: val];
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
                NSDate *val = [m_dateFormatter dateFromString: value]; // assume "yyyy-MM-ddThh:mm:ss.zzz"
                [self setETA: val];
            }
            else if ([key isEqualToString:@"ATA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [m_dateFormatter dateFromString: value]; // assume "yyyy-MM-ddThh:mm:ss.zzz"
                [self setATA: val];
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
    [xml appendString: m_id];
    [xml appendString: @"\""];
    [xml appendString: @" SourceName=\""];
    [xml appendString: m_sourceName];
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
        [xml appendString: m_destination];
        [xml appendString: @"\""];
    }
    if ( [self hasETA] ) {
        [xml appendString: @" ETA=\""];
        [xml appendString: [m_ETA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
        [xml appendString: @"\""];
    }
    if ( [self hasATA] ) {
        [xml appendString: @" ATA=\""];
        [xml appendString: [m_ATA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
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
    }
    if ( [self hasDestination] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Destination = \""];
        [str appendString: m_destination];
    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = \""];
        [str appendString: [m_ETA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    }
    if ( [self hasATA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATA = \""];
        [str appendString: [m_ATA descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    }
    if ( [self hasAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AirDraught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_airDraught]];
    }
    if ( [self hasDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Draught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_draught]];
    }
    return str;
}


@end


