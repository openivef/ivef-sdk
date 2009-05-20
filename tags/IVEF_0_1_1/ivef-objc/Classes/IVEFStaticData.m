
#import "IVEFStaticData.h"


@implementation IVEFStaticData

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

-(void) setLength:(float) val {

    m_lengthPresent = true;
    m_length = val;
}

- (float) getLength {

    return m_length;
}

-(bool) hasLength {

    return m_lengthPresent;
}

-(void) setBreadth:(float) val {

    m_breadthPresent = true;
    m_breadth = val;
}

- (float) getBreadth {

    return m_breadth;
}

-(bool) hasBreadth {

    return m_breadthPresent;
}

-(void) setCallsign:(NSString *) val {

    m_callsignPresent = true;
    [m_callsign release];
    m_callsign = val;
    [m_callsign retain];
}

- (NSString *) getCallsign {

    return m_callsign;
}

-(bool) hasCallsign {

    return m_callsignPresent;
}

-(void) setShipName:(NSString *) val {

    m_shipNamePresent = true;
    [m_shipName release];
    m_shipName = val;
    [m_shipName retain];
}

- (NSString *) getShipName {

    return m_shipName;
}

-(bool) hasShipName {

    return m_shipNamePresent;
}

-(void) setObjectType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) &&
         ( val != 6 ) &&
         ( val != 7 ) )
        return;
    m_objectTypePresent = true;
    m_objectType = val;
}

- (int) getObjectType {

    return m_objectType;
}

-(bool) hasObjectType {

    return m_objectTypePresent;
}

-(void) setShipType:(int) val {

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
        return;
    m_shipTypePresent = true;
    m_shipType = val;
}

- (int) getShipType {

    return m_shipType;
}

-(bool) hasShipType {

    return m_shipTypePresent;
}

-(void) setIMO:(int) val {

    m_IMOPresent = true;
    m_IMO = val;
}

- (int) getIMO {

    return m_IMO;
}

-(bool) hasIMO {

    return m_IMOPresent;
}

-(void) setMMSI:(int) val {

    m_MMSIPresent = true;
    m_MMSI = val;
}

- (int) getMMSI {

    return m_MMSI;
}

-(bool) hasMMSI {

    return m_MMSIPresent;
}

-(void) setATONType:(int) val {

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
        return;
    m_ATONTypePresent = true;
    m_ATONType = val;
}

- (int) getATONType {

    return m_ATONType;
}

-(bool) hasATONType {

    return m_ATONTypePresent;
}

-(void) setATONName:(NSString *) val {

    m_ATONNamePresent = true;
    [m_ATONName release];
    m_ATONName = val;
    [m_ATONName retain];
}

- (NSString *) getATONName {

    return m_ATONName;
}

-(bool) hasATONName {

    return m_ATONNamePresent;
}

-(void) setAntPosDistFromFront:(float) val {

    m_antPosDistFromFrontPresent = true;
    m_antPosDistFromFront = val;
}

- (float) getAntPosDistFromFront {

    return m_antPosDistFromFront;
}

-(bool) hasAntPosDistFromFront {

    return m_antPosDistFromFrontPresent;
}

-(void) setAntPosDistFromLeft:(float) val {

    m_antPosDistFromLeftPresent = true;
    m_antPosDistFromLeft = val;
}

- (float) getAntPosDistFromLeft {

    return m_antPosDistFromLeft;
}

-(bool) hasAntPosDistFromLeft {

    return m_antPosDistFromLeftPresent;
}

-(void) setNatLangShipName:(NSString *) val {

    m_natLangShipNamePresent = true;
    [m_natLangShipName release];
    m_natLangShipName = val;
    [m_natLangShipName retain];
}

- (NSString *) getNatLangShipName {

    return m_natLangShipName;
}

-(bool) hasNatLangShipName {

    return m_natLangShipNamePresent;
}

-(void) setPortOfRegistry:(NSString *) val {

    m_portOfRegistryPresent = true;
    [m_portOfRegistry release];
    m_portOfRegistry = val;
    [m_portOfRegistry retain];
}

- (NSString *) getPortOfRegistry {

    return m_portOfRegistry;
}

-(bool) hasPortOfRegistry {

    return m_portOfRegistryPresent;
}

-(void) setCountryFlag:(NSString *) val {

    m_countryFlagPresent = true;
    [m_countryFlag release];
    m_countryFlag = val;
    [m_countryFlag retain];
}

- (NSString *) getCountryFlag {

    return m_countryFlag;
}

-(bool) hasCountryFlag {

    return m_countryFlagPresent;
}

-(void) setMaxAirDraught:(float) val {

    m_maxAirDraughtPresent = true;
    m_maxAirDraught = val;
}

- (float) getMaxAirDraught {

    return m_maxAirDraught;
}

-(bool) hasMaxAirDraught {

    return m_maxAirDraughtPresent;
}

-(void) setMaxDraught:(float) val {

    m_maxDraughtPresent = true;
    m_maxDraught = val;
}

- (float) getMaxDraught {

    return m_maxDraught;
}

-(bool) hasMaxDraught {

    return m_maxDraughtPresent;
}

-(void) setDeepWaterVesselind:(NSString *) val {

    if ( ( ![val isEqualToString: @"yes"] ) &&
         ( ![val isEqualToString: @"no"] ) )
        return;
    m_deepWaterVesselindPresent = true;
    [m_deepWaterVesselind release];
    m_deepWaterVesselind = val;
    [m_deepWaterVesselind retain];
}

- (NSString *) getDeepWaterVesselind {

    return m_deepWaterVesselind;
}

-(bool) hasDeepWaterVesselind {

    return m_deepWaterVesselindPresent;
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
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLength: val];
            }
            else if ([key isEqualToString:@"Breadth"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setBreadth: val];
            }
            else if ([key isEqualToString:@"Callsign"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setCallsign: val];
            }
            else if ([key isEqualToString:@"ShipName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setShipName: val];
            }
            else if ([key isEqualToString:@"ObjectType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setObjectType: val];
            }
            else if ([key isEqualToString:@"ShipType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setShipType: val];
            }
            else if ([key isEqualToString:@"IMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setIMO: val];
            }
            else if ([key isEqualToString:@"MMSI"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setMMSI: val];
            }
            else if ([key isEqualToString:@"ATONType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setATONType: val];
            }
            else if ([key isEqualToString:@"ATONName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setATONName: val];
            }
            else if ([key isEqualToString:@"AntPosDistFromFront"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setAntPosDistFromFront: val];
            }
            else if ([key isEqualToString:@"AntPosDistFromLeft"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setAntPosDistFromLeft: val];
            }
            else if ([key isEqualToString:@"NatLangShipName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setNatLangShipName: val];
            }
            else if ([key isEqualToString:@"PortOfRegistry"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setPortOfRegistry: val];
            }
            else if ([key isEqualToString:@"CountryFlag"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setCountryFlag: val];
            }
            else if ([key isEqualToString:@"MaxAirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setMaxAirDraught: val];
            }
            else if ([key isEqualToString:@"MaxDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setMaxDraught: val];
            }
            else if ([key isEqualToString:@"DeepWaterVesselind"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDeepWaterVesselind: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<StaticData"];
    [xml appendString: @" Id=\""];
    [xml appendString: [m_id encode]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceName=\""];
    [xml appendString: [m_sourceName encode]];
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
        [xml appendString: [m_callsign encode]];
        [xml appendString: @"\""];
    }
    if ( [self hasShipName] ) {
        [xml appendString: @" ShipName=\""];
        [xml appendString: [m_shipName encode]];
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
        [xml appendString: [m_ATONName encode]];
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
        [xml appendString: [m_natLangShipName encode]];
        [xml appendString: @"\""];
    }
    if ( [self hasPortOfRegistry] ) {
        [xml appendString: @" PortOfRegistry=\""];
        [xml appendString: [m_portOfRegistry encode]];
        [xml appendString: @"\""];
    }
    if ( [self hasCountryFlag] ) {
        [xml appendString: @" CountryFlag=\""];
        [xml appendString: [m_countryFlag encode]];
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
        [xml appendString: [m_deepWaterVesselind encode]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: @"</StaticData>\n"];
    return xml;
}

-(NSString *) encode: (NSString *) input {

    NSMutableString *str = [[[NSMutableString alloc] initWithString: input] autorelease];

    [str replaceOccurrencesOfString: @"&" withString: "&amp;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: "&lt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: "&gt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: "&quot;") options: nil searchRange: NSMakeRange(0, [str length])];

    return str;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"StaticData\n"]];
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

    if ( [self hasLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Length = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_length]];
    }
    if ( [self hasBreadth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Breadth = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_breadth]];
    }
    if ( [self hasCallsign] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Callsign = \""];
        [str appendString: m_callsign];
    }
    if ( [self hasShipName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ShipName = \""];
        [str appendString: m_shipName];
    }
    if ( [self hasObjectType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ObjectType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_objectType]];
    }
    if ( [self hasShipType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ShipType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_shipType]];
    }
    if ( [self hasIMO] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"IMO = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_IMO]];
    }
    if ( [self hasMMSI] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MMSI = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_MMSI]];
    }
    if ( [self hasATONType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATONType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_ATONType]];
    }
    if ( [self hasATONName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATONName = \""];
        [str appendString: m_ATONName];
    }
    if ( [self hasAntPosDistFromFront] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AntPosDistFromFront = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_antPosDistFromFront]];
    }
    if ( [self hasAntPosDistFromLeft] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AntPosDistFromLeft = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_antPosDistFromLeft]];
    }
    if ( [self hasNatLangShipName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"NatLangShipName = \""];
        [str appendString: m_natLangShipName];
    }
    if ( [self hasPortOfRegistry] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PortOfRegistry = \""];
        [str appendString: m_portOfRegistry];
    }
    if ( [self hasCountryFlag] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CountryFlag = \""];
        [str appendString: m_countryFlag];
    }
    if ( [self hasMaxAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxAirDraught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxAirDraught]];
    }
    if ( [self hasMaxDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxDraught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxDraught]];
    }
    if ( [self hasDeepWaterVesselind] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DeepWaterVesselind = \""];
        [str appendString: m_deepWaterVesselind];
    }
    return str;
}


@end


