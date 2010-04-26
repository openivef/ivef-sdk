
#import "ILStaticData.h"


@implementation ILStaticData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_idPresent = NO;
        m_sourceNamePresent = NO;
        m_sourcePresent = NO;
        m_lengthPresent = NO;
        m_breadthPresent = NO;
        m_callsignPresent = NO;
        m_shipNamePresent = NO;
        m_objectTypePresent = NO;
        m_shipTypePresent = NO;
        m_IMOPresent = NO;
        m_MMSIPresent = NO;
        m_ATONTypePresent = NO;
        m_ATONNamePresent = NO;
        m_antPosDistFromFrontPresent = NO;
        m_antPosDistFromLeftPresent = NO;
        m_natLangShipNamePresent = NO;
        m_portOfRegistryPresent = NO;
        m_countryFlagPresent = NO;
        m_maxAirDraughtPresent = NO;
        m_maxDraughtPresent = NO;
        m_deepWaterVesselindPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_id release];
    [m_sourceName release];
    [m_callsign release];
    [m_shipName release];
    [m_ATONName release];
    [m_natLangShipName release];
    [m_portOfRegistry release];
    [m_countryFlag release];
    [m_deepWaterVesselind release];
    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
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

    m_idPresent = YES;
    [m_id release];
    m_id = val;
    [m_id retain];
    return YES;
}

- (NSString *) ident {

    return m_id;
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

-(BOOL) setSource:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_sourcePresent = YES;
    m_source = val;
    return YES;
}

- (int) source {

    return m_source;
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

-(BOOL) setBreadth:(float) val {

    if (val < 0)
        return NO;
    m_breadthPresent = YES;
    m_breadth = val;
    return YES;
}

- (float) breadth {

    return m_breadth;
}

-(BOOL) hasBreadth {

    return m_breadthPresent;
}

-(BOOL) setCallsign:(NSString *) val {

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

-(BOOL) setShipName:(NSString *) val {

    m_shipNamePresent = YES;
    [m_shipName release];
    m_shipName = val;
    [m_shipName retain];
    return YES;
}

- (NSString *) shipName {

    return m_shipName;
}

-(BOOL) hasShipName {

    return m_shipNamePresent;
}

-(BOOL) setObjectType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) )
        return NO;
    m_objectTypePresent = YES;
    m_objectType = val;
    return YES;
}

- (int) objectType {

    return m_objectType;
}

-(BOOL) hasObjectType {

    return m_objectTypePresent;
}

-(BOOL) setShipType:(int) val {

    if ( ( val != 20 ) &&
         ( val != 30 ) &&
         ( val != 31 ) &&
         ( val != 32 ) &&
         ( val != 33 ) &&
         ( val != 34 ) &&
         ( val != 35 ) &&
         ( val != 36 ) &&
         ( val != 37 ) &&
         ( val != 40 ) &&
         ( val != 50 ) &&
         ( val != 51 ) &&
         ( val != 52 ) &&
         ( val != 53 ) &&
         ( val != 54 ) &&
         ( val != 55 ) &&
         ( val != 58 ) &&
         ( val != 59 ) &&
         ( val != 60 ) &&
         ( val != 70 ) &&
         ( val != 80 ) &&
         ( val != 90 ) )
        return NO;
    m_shipTypePresent = YES;
    m_shipType = val;
    return YES;
}

- (int) shipType {

    return m_shipType;
}

-(BOOL) hasShipType {

    return m_shipTypePresent;
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

-(BOOL) setATONType:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) &&
         ( val != 9 ) &&
         ( val != 10 ) &&
         ( val != 11 ) &&
         ( val != 12 ) &&
         ( val != 13 ) &&
         ( val != 14 ) &&
         ( val != 15 ) &&
         ( val != 16 ) &&
         ( val != 17 ) &&
         ( val != 18 ) &&
         ( val != 19 ) &&
         ( val != 20 ) &&
         ( val != 21 ) &&
         ( val != 22 ) &&
         ( val != 23 ) &&
         ( val != 24 ) &&
         ( val != 25 ) &&
         ( val != 26 ) &&
         ( val != 27 ) &&
         ( val != 28 ) &&
         ( val != 29 ) &&
         ( val != 30 ) &&
         ( val != 31 ) &&
         ( val != 32 ) &&
         ( val != 33 ) )
        return NO;
    m_ATONTypePresent = YES;
    m_ATONType = val;
    return YES;
}

- (int) ATONType {

    return m_ATONType;
}

-(BOOL) hasATONType {

    return m_ATONTypePresent;
}

-(BOOL) setATONName:(NSString *) val {

    m_ATONNamePresent = YES;
    [m_ATONName release];
    m_ATONName = val;
    [m_ATONName retain];
    return YES;
}

- (NSString *) ATONName {

    return m_ATONName;
}

-(BOOL) hasATONName {

    return m_ATONNamePresent;
}

-(BOOL) setAntPosDistFromFront:(float) val {

    m_antPosDistFromFrontPresent = YES;
    m_antPosDistFromFront = val;
    return YES;
}

- (float) antPosDistFromFront {

    return m_antPosDistFromFront;
}

-(BOOL) hasAntPosDistFromFront {

    return m_antPosDistFromFrontPresent;
}

-(BOOL) setAntPosDistFromLeft:(float) val {

    m_antPosDistFromLeftPresent = YES;
    m_antPosDistFromLeft = val;
    return YES;
}

- (float) antPosDistFromLeft {

    return m_antPosDistFromLeft;
}

-(BOOL) hasAntPosDistFromLeft {

    return m_antPosDistFromLeftPresent;
}

-(BOOL) setNatLangShipName:(NSString *) val {

    m_natLangShipNamePresent = YES;
    [m_natLangShipName release];
    m_natLangShipName = val;
    [m_natLangShipName retain];
    return YES;
}

- (NSString *) natLangShipName {

    return m_natLangShipName;
}

-(BOOL) hasNatLangShipName {

    return m_natLangShipNamePresent;
}

-(BOOL) setPortOfRegistry:(NSString *) val {

    m_portOfRegistryPresent = YES;
    [m_portOfRegistry release];
    m_portOfRegistry = val;
    [m_portOfRegistry retain];
    return YES;
}

- (NSString *) portOfRegistry {

    return m_portOfRegistry;
}

-(BOOL) hasPortOfRegistry {

    return m_portOfRegistryPresent;
}

-(BOOL) setCountryFlag:(NSString *) val {

    m_countryFlagPresent = YES;
    [m_countryFlag release];
    m_countryFlag = val;
    [m_countryFlag retain];
    return YES;
}

- (NSString *) countryFlag {

    return m_countryFlag;
}

-(BOOL) hasCountryFlag {

    return m_countryFlagPresent;
}

-(BOOL) setMaxAirDraught:(float) val {

    if (val < 0)
        return NO;
    m_maxAirDraughtPresent = YES;
    m_maxAirDraught = val;
    return YES;
}

- (float) maxAirDraught {

    return m_maxAirDraught;
}

-(BOOL) hasMaxAirDraught {

    return m_maxAirDraughtPresent;
}

-(BOOL) setMaxDraught:(float) val {

    if (val < 0)
        return NO;
    m_maxDraughtPresent = YES;
    m_maxDraught = val;
    return YES;
}

- (float) maxDraught {

    return m_maxDraught;
}

-(BOOL) hasMaxDraught {

    return m_maxDraughtPresent;
}

-(BOOL) setDeepWaterVesselind:(NSString *) val {

    if ( ( ![val isEqualToString: @"yes"] ) &&
         ( ![val isEqualToString: @"no"] ) )
        return NO;
    m_deepWaterVesselindPresent = YES;
    [m_deepWaterVesselind release];
    m_deepWaterVesselind = val;
    [m_deepWaterVesselind retain];
    return YES;
}

- (NSString *) deepWaterVesselind {

    return m_deepWaterVesselind;
}

-(BOOL) hasDeepWaterVesselind {

    return m_deepWaterVesselindPresent;
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
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setLength: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Breadth"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setBreadth: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Callsign"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCallsign: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ShipName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setShipName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ObjectType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setObjectType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ShipType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setShipType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"IMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIMO: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MMSI"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setMMSI: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ATONType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setATONType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ATONName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setATONName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"AntPosDistFromFront"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAntPosDistFromFront: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"AntPosDistFromLeft"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAntPosDistFromLeft: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"NatLangShipName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setNatLangShipName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"PortOfRegistry"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setPortOfRegistry: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"CountryFlag"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCountryFlag: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MaxAirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxAirDraught: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MaxDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxDraught: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"DeepWaterVesselind"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDeepWaterVesselind: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<StaticData"];
    if ( m_idPresent ) {
        [xml appendString: @" Id=\""];
        [xml appendString: [self encode: m_id]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Id" forKey: @"description"]];
        return nil;
    }
    if ( m_sourceNamePresent ) {
        [xml appendString: @" SourceName=\""];
        [xml appendString: [self encode: m_sourceName]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceName" forKey: @"description"]];
        return nil;
    }
    if ( m_sourcePresent ) {
        [xml appendString: @" Source=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_source]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Source" forKey: @"description"]];
        return nil;
    }
    if ( [self hasLength] ) {
        [xml appendString: @" Length=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_length]];
        [xml appendString: @"\""];
    }
    if ( [self hasBreadth] ) {
        [xml appendString: @" Breadth=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_breadth]];
        [xml appendString: @"\""];
    }
    if ( [self hasCallsign] ) {
        [xml appendString: @" Callsign=\""];
        [xml appendString: [self encode: m_callsign]];
        [xml appendString: @"\""];
    }
    if ( [self hasShipName] ) {
        [xml appendString: @" ShipName=\""];
        [xml appendString: [self encode: m_shipName]];
        [xml appendString: @"\""];
    }
    if ( [self hasObjectType] ) {
        [xml appendString: @" ObjectType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_objectType]];
        [xml appendString: @"\""];
    }
    if ( [self hasShipType] ) {
        [xml appendString: @" ShipType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_shipType]];
        [xml appendString: @"\""];
    }
    if ( [self hasIMO] ) {
        [xml appendString: @" IMO=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_IMO]];
        [xml appendString: @"\""];
    }
    if ( [self hasMMSI] ) {
        [xml appendString: @" MMSI=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_MMSI]];
        [xml appendString: @"\""];
    }
    if ( [self hasATONType] ) {
        [xml appendString: @" ATONType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_ATONType]];
        [xml appendString: @"\""];
    }
    if ( [self hasATONName] ) {
        [xml appendString: @" ATONName=\""];
        [xml appendString: [self encode: m_ATONName]];
        [xml appendString: @"\""];
    }
    if ( [self hasAntPosDistFromFront] ) {
        [xml appendString: @" AntPosDistFromFront=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_antPosDistFromFront]];
        [xml appendString: @"\""];
    }
    if ( [self hasAntPosDistFromLeft] ) {
        [xml appendString: @" AntPosDistFromLeft=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_antPosDistFromLeft]];
        [xml appendString: @"\""];
    }
    if ( [self hasNatLangShipName] ) {
        [xml appendString: @" NatLangShipName=\""];
        [xml appendString: [self encode: m_natLangShipName]];
        [xml appendString: @"\""];
    }
    if ( [self hasPortOfRegistry] ) {
        [xml appendString: @" PortOfRegistry=\""];
        [xml appendString: [self encode: m_portOfRegistry]];
        [xml appendString: @"\""];
    }
    if ( [self hasCountryFlag] ) {
        [xml appendString: @" CountryFlag=\""];
        [xml appendString: [self encode: m_countryFlag]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxAirDraught] ) {
        [xml appendString: @" MaxAirDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_maxAirDraught]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxDraught] ) {
        [xml appendString: @" MaxDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_maxDraught]];
        [xml appendString: @"\""];
    }
    if ( [self hasDeepWaterVesselind] ) {
        [xml appendString: @" DeepWaterVesselind=\""];
        [xml appendString: [self encode: m_deepWaterVesselind]];
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
    [str setString: [lead stringByAppendingString:@"StaticData\n"]];
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

    if ( [self hasLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Length = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_length]];
        [str appendString: @"\n"];

    }
    if ( [self hasBreadth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Breadth = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_breadth]];
        [str appendString: @"\n"];

    }
    if ( [self hasCallsign] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Callsign = "];
        [str appendString: m_callsign];
        [str appendString: @"\n"];

    }
    if ( [self hasShipName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ShipName = "];
        [str appendString: m_shipName];
        [str appendString: @"\n"];

    }
    if ( [self hasObjectType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ObjectType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_objectType]];
        [str appendString: @"\n"];

    }
    if ( [self hasShipType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ShipType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_shipType]];
        [str appendString: @"\n"];

    }
    if ( [self hasIMO] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"IMO = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_IMO]];
        [str appendString: @"\n"];

    }
    if ( [self hasMMSI] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MMSI = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_MMSI]];
        [str appendString: @"\n"];

    }
    if ( [self hasATONType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATONType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_ATONType]];
        [str appendString: @"\n"];

    }
    if ( [self hasATONName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATONName = "];
        [str appendString: m_ATONName];
        [str appendString: @"\n"];

    }
    if ( [self hasAntPosDistFromFront] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AntPosDistFromFront = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_antPosDistFromFront]];
        [str appendString: @"\n"];

    }
    if ( [self hasAntPosDistFromLeft] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AntPosDistFromLeft = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_antPosDistFromLeft]];
        [str appendString: @"\n"];

    }
    if ( [self hasNatLangShipName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"NatLangShipName = "];
        [str appendString: m_natLangShipName];
        [str appendString: @"\n"];

    }
    if ( [self hasPortOfRegistry] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PortOfRegistry = "];
        [str appendString: m_portOfRegistry];
        [str appendString: @"\n"];

    }
    if ( [self hasCountryFlag] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CountryFlag = "];
        [str appendString: m_countryFlag];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxAirDraught = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxAirDraught]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxDraught = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxDraught]];
        [str appendString: @"\n"];

    }
    if ( [self hasDeepWaterVesselind] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DeepWaterVesselind = "];
        [str appendString: m_deepWaterVesselind];
        [str appendString: @"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_id forKey: @"Id"];
    [attr setObject: m_sourceName forKey: @"SourceName"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_source] forKey: @"Source"];
    if ( [self hasLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_length] forKey: @"Length"];
    }
    if ( [self hasBreadth] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_breadth] forKey: @"Breadth"];
    }
    if ( [self hasCallsign] ) {
        [attr setObject: m_callsign forKey: @"Callsign"];
    }
    if ( [self hasShipName] ) {
        [attr setObject: m_shipName forKey: @"ShipName"];
    }
    if ( [self hasObjectType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_objectType] forKey: @"ObjectType"];
    }
    if ( [self hasShipType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_shipType] forKey: @"ShipType"];
    }
    if ( [self hasIMO] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_IMO] forKey: @"IMO"];
    }
    if ( [self hasMMSI] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_MMSI] forKey: @"MMSI"];
    }
    if ( [self hasATONType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_ATONType] forKey: @"ATONType"];
    }
    if ( [self hasATONName] ) {
        [attr setObject: m_ATONName forKey: @"ATONName"];
    }
    if ( [self hasAntPosDistFromFront] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_antPosDistFromFront] forKey: @"AntPosDistFromFront"];
    }
    if ( [self hasAntPosDistFromLeft] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_antPosDistFromLeft] forKey: @"AntPosDistFromLeft"];
    }
    if ( [self hasNatLangShipName] ) {
        [attr setObject: m_natLangShipName forKey: @"NatLangShipName"];
    }
    if ( [self hasPortOfRegistry] ) {
        [attr setObject: m_portOfRegistry forKey: @"PortOfRegistry"];
    }
    if ( [self hasCountryFlag] ) {
        [attr setObject: m_countryFlag forKey: @"CountryFlag"];
    }
    if ( [self hasMaxAirDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_maxAirDraught] forKey: @"MaxAirDraught"];
    }
    if ( [self hasMaxDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_maxDraught] forKey: @"MaxDraught"];
    }
    if ( [self hasDeepWaterVesselind] ) {
        [attr setObject: m_deepWaterVesselind forKey: @"DeepWaterVesselind"];
    }

    return attr;
}


@end


