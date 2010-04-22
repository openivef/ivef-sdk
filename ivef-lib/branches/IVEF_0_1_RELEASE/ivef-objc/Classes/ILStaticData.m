
#import "ILStaticData.h"


@implementation ILStaticData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_lengthPresent = false;
        m_breadthPresent = false;
        m_callsignPresent = false;
        m_shipNamePresent = false;
        m_objectTypePresent = false;
        m_shipTypePresent = false;
        m_IMOPresent = false;
        m_MMSIPresent = false;
        m_ATONTypePresent = false;
        m_ATONNamePresent = false;
        m_antPosDistFromFrontPresent = false;
        m_antPosDistFromLeftPresent = false;
        m_natLangShipNamePresent = false;
        m_portOfRegistryPresent = false;
        m_countryFlagPresent = false;
        m_maxAirDraughtPresent = false;
        m_maxDraughtPresent = false;
        m_deepWaterVesselindPresent = false;
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

-(bool) setLength:(float) val {

    if (val < 0)
        return NO;
    m_lengthPresent = true;
    m_length = val;
      return YES;
}

- (float) length {

    return m_length;
}

-(bool) hasLength {

    return m_lengthPresent;
}

-(bool) setBreadth:(float) val {

    if (val < 0)
        return NO;
    m_breadthPresent = true;
    m_breadth = val;
      return YES;
}

- (float) breadth {

    return m_breadth;
}

-(bool) hasBreadth {

    return m_breadthPresent;
}

-(bool) setCallsign:(NSString *) val {

    m_callsignPresent = true;
    [m_callsign release];
    m_callsign = val;
    [m_callsign retain];
      return YES;
}

- (NSString *) callsign {

    return m_callsign;
}

-(bool) hasCallsign {

    return m_callsignPresent;
}

-(bool) setShipName:(NSString *) val {

    m_shipNamePresent = true;
    [m_shipName release];
    m_shipName = val;
    [m_shipName retain];
      return YES;
}

- (NSString *) shipName {

    return m_shipName;
}

-(bool) hasShipName {

    return m_shipNamePresent;
}

-(bool) setObjectType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) )
        return NO;
    m_objectTypePresent = true;
    m_objectType = val;
      return YES;
}

- (int) objectType {

    return m_objectType;
}

-(bool) hasObjectType {

    return m_objectTypePresent;
}

-(bool) setShipType:(int) val {

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
    m_shipTypePresent = true;
    m_shipType = val;
      return YES;
}

- (int) shipType {

    return m_shipType;
}

-(bool) hasShipType {

    return m_shipTypePresent;
}

-(bool) setIMO:(int) val {

    m_IMOPresent = true;
    m_IMO = val;
      return YES;
}

- (int) IMO {

    return m_IMO;
}

-(bool) hasIMO {

    return m_IMOPresent;
}

-(bool) setMMSI:(int) val {

    m_MMSIPresent = true;
    m_MMSI = val;
      return YES;
}

- (int) MMSI {

    return m_MMSI;
}

-(bool) hasMMSI {

    return m_MMSIPresent;
}

-(bool) setATONType:(int) val {

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
    m_ATONTypePresent = true;
    m_ATONType = val;
      return YES;
}

- (int) ATONType {

    return m_ATONType;
}

-(bool) hasATONType {

    return m_ATONTypePresent;
}

-(bool) setATONName:(NSString *) val {

    m_ATONNamePresent = true;
    [m_ATONName release];
    m_ATONName = val;
    [m_ATONName retain];
      return YES;
}

- (NSString *) ATONName {

    return m_ATONName;
}

-(bool) hasATONName {

    return m_ATONNamePresent;
}

-(bool) setAntPosDistFromFront:(float) val {

    m_antPosDistFromFrontPresent = true;
    m_antPosDistFromFront = val;
      return YES;
}

- (float) antPosDistFromFront {

    return m_antPosDistFromFront;
}

-(bool) hasAntPosDistFromFront {

    return m_antPosDistFromFrontPresent;
}

-(bool) setAntPosDistFromLeft:(float) val {

    m_antPosDistFromLeftPresent = true;
    m_antPosDistFromLeft = val;
      return YES;
}

- (float) antPosDistFromLeft {

    return m_antPosDistFromLeft;
}

-(bool) hasAntPosDistFromLeft {

    return m_antPosDistFromLeftPresent;
}

-(bool) setNatLangShipName:(NSString *) val {

    m_natLangShipNamePresent = true;
    [m_natLangShipName release];
    m_natLangShipName = val;
    [m_natLangShipName retain];
      return YES;
}

- (NSString *) natLangShipName {

    return m_natLangShipName;
}

-(bool) hasNatLangShipName {

    return m_natLangShipNamePresent;
}

-(bool) setPortOfRegistry:(NSString *) val {

    m_portOfRegistryPresent = true;
    [m_portOfRegistry release];
    m_portOfRegistry = val;
    [m_portOfRegistry retain];
      return YES;
}

- (NSString *) portOfRegistry {

    return m_portOfRegistry;
}

-(bool) hasPortOfRegistry {

    return m_portOfRegistryPresent;
}

-(bool) setCountryFlag:(NSString *) val {

    m_countryFlagPresent = true;
    [m_countryFlag release];
    m_countryFlag = val;
    [m_countryFlag retain];
      return YES;
}

- (NSString *) countryFlag {

    return m_countryFlag;
}

-(bool) hasCountryFlag {

    return m_countryFlagPresent;
}

-(bool) setMaxAirDraught:(float) val {

    if (val < 0)
        return NO;
    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
      return YES;
}

- (float) maxAirDraught {

    return m_maxAirDraught;
}

-(bool) hasMaxAirDraught {

    return m_maxAirDraughtPresent;
}

-(bool) setMaxDraught:(float) val {

    if (val < 0)
        return NO;
    m_maxDraughtPresent = true;
    m_maxDraught = val;
      return YES;
}

- (float) maxDraught {

    return m_maxDraught;
}

-(bool) hasMaxDraught {

    return m_maxDraughtPresent;
}

-(bool) setDeepWaterVesselind:(NSString *) val {

    if ( ( ![val isEqualToString: @"yes"] ) &&
         ( ![val isEqualToString: @"no"] ) )
        return NO;
    m_deepWaterVesselindPresent = true;
    [m_deepWaterVesselind release];
    m_deepWaterVesselind = val;
    [m_deepWaterVesselind retain];
      return YES;
}

- (NSString *) deepWaterVesselind {

    return m_deepWaterVesselind;
}

-(bool) hasDeepWaterVesselind {

    return m_deepWaterVesselindPresent;
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
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setLength: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Breadth"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setBreadth: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Callsign"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCallsign: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ShipName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setShipName: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ObjectType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setObjectType: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ShipType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setShipType: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"IMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIMO: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"MMSI"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setMMSI: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ATONType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setATONType: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"ATONName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setATONName: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"AntPosDistFromFront"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAntPosDistFromFront: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"AntPosDistFromLeft"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAntPosDistFromLeft: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"NatLangShipName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setNatLangShipName: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"PortOfRegistry"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setPortOfRegistry: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"CountryFlag"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCountryFlag: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"MaxAirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxAirDraught: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"MaxDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxDraught: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"DeepWaterVesselind"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDeepWaterVesselind: val]) {
                   return false;
                }
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<StaticData"];
    [xml appendString: @" Id=\""];
    [xml appendString: [self encode: m_id]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceName=\""];
    [xml appendString: [self encode: m_sourceName]];
    [xml appendString: @"\""];
    [xml appendString: @" Source=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_source]];
    [xml appendString: @"\""];
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


