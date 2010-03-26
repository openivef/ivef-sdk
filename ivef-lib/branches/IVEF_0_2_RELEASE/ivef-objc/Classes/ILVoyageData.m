
#import "ILVoyageData.h"


@implementation ILVoyageData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_waypoints = [[NSMutableArray alloc] init];
        m_airDraughtPresent = false;
        m_cargoTypeIMOPresent = false;
        m_contactIdentityPresent = false;
        m_destCodePresent = false;
        m_destNamePresent = false;
        m_draughtPresent = false;
        m_ETAPresent = false;
        m_ISPSLevelPresent = false;
        m_overSizedLengthPresent = false;
        m_overSizedWidthPresent = false;
        m_nextPortPresent = false;
        m_personsOnBoardPresent = false;
        m_pilotsPresent = false;
        m_prevPortPresent = false;
        m_routeBoundPresent = false;
        m_sourceIdPresent = false;
        m_tankerStatusPresent = false;
        m_tugsPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_waypoints release];
    [m_contactIdentity release];
    [m_destCode release];
    [m_destName release];
    [m_ETA release];
    [m_nextPort release];
    [m_prevPort release];
    [m_sourceId release];
    [m_sourceName release];
    [m_updateTime release];
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

-(void) addWaypoint:(ILWaypoint *) val {

    [m_waypoints addObject: val];
}

-(ILWaypoint *) waypointAt:(int) i {

    return [m_waypoints objectAtIndex: i];
}

-(int) countOfWaypoints {

    return [m_waypoints count];
}

-(NSArray *) waypoints {

    return m_waypoints;
}

-(void) setAirDraught:(float) val {

    if (val < 0)
        return;
    m_airDraughtPresent = true;
    m_airDraught = val;
}

- (float) airDraught {

    return m_airDraught;
}

-(bool) hasAirDraught {

    return m_airDraughtPresent;
}

-(void) setIdent:(int) val {

    m_id = val;
}

- (int) ident {

    return m_id;
}

-(void) setCargoTypeIMO:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_cargoTypeIMOPresent = true;
    m_cargoTypeIMO = val;
}

- (int) cargoTypeIMO {

    return m_cargoTypeIMO;
}

-(bool) hasCargoTypeIMO {

    return m_cargoTypeIMOPresent;
}

-(void) setContactIdentity:(NSString *) val {

    m_contactIdentityPresent = true;
    [m_contactIdentity release];
    m_contactIdentity = val;
    [m_contactIdentity retain];
}

- (NSString *) contactIdentity {

    return m_contactIdentity;
}

-(bool) hasContactIdentity {

    return m_contactIdentityPresent;
}

-(void) setDestCode:(NSString *) val {

    m_destCodePresent = true;
    [m_destCode release];
    m_destCode = val;
    [m_destCode retain];
}

- (NSString *) destCode {

    return m_destCode;
}

-(bool) hasDestCode {

    return m_destCodePresent;
}

-(void) setDestName:(NSString *) val {

    m_destNamePresent = true;
    [m_destName release];
    m_destName = val;
    [m_destName retain];
}

- (NSString *) destName {

    return m_destName;
}

-(bool) hasDestName {

    return m_destNamePresent;
}

-(void) setDraught:(float) val {

    if (val < 0)
        return;
    m_draughtPresent = true;
    m_draught = val;
}

- (float) draught {

    return m_draught;
}

-(bool) hasDraught {

    return m_draughtPresent;
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

-(void) setISPSLevel:(float) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_ISPSLevelPresent = true;
    m_ISPSLevel = val;
}

- (float) ISPSLevel {

    return m_ISPSLevel;
}

-(bool) hasISPSLevel {

    return m_ISPSLevelPresent;
}

-(void) setOverSizedLength:(float) val {

    if (val < 0)
        return;
    m_overSizedLengthPresent = true;
    m_overSizedLength = val;
}

- (float) overSizedLength {

    return m_overSizedLength;
}

-(bool) hasOverSizedLength {

    return m_overSizedLengthPresent;
}

-(void) setOverSizedWidth:(float) val {

    if (val < 0)
        return;
    m_overSizedWidthPresent = true;
    m_overSizedWidth = val;
}

- (float) overSizedWidth {

    return m_overSizedWidth;
}

-(bool) hasOverSizedWidth {

    return m_overSizedWidthPresent;
}

-(void) setNextPort:(NSString *) val {

    m_nextPortPresent = true;
    [m_nextPort release];
    m_nextPort = val;
    [m_nextPort retain];
}

- (NSString *) nextPort {

    return m_nextPort;
}

-(bool) hasNextPort {

    return m_nextPortPresent;
}

-(void) setPersonsOnBoard:(float) val {

    if (val < 0)
        return;
    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
}

- (float) personsOnBoard {

    return m_personsOnBoard;
}

-(bool) hasPersonsOnBoard {

    return m_personsOnBoardPresent;
}

-(void) setPilots:(float) val {

    if (val < 0)
        return;
    m_pilotsPresent = true;
    m_pilots = val;
}

- (float) pilots {

    return m_pilots;
}

-(bool) hasPilots {

    return m_pilotsPresent;
}

-(void) setPrevPort:(NSString *) val {

    m_prevPortPresent = true;
    [m_prevPort release];
    m_prevPort = val;
    [m_prevPort retain];
}

- (NSString *) prevPort {

    return m_prevPort;
}

-(bool) hasPrevPort {

    return m_prevPortPresent;
}

-(void) setRouteBound:(bool) val {

    m_routeBoundPresent = true;
    m_routeBound = val;
}

- (bool) routeBound {

    return m_routeBound;
}

-(bool) hasRouteBound {

    return m_routeBoundPresent;
}

-(void) setSourceId:(NSString *) val {

    m_sourceIdPresent = true;
    [m_sourceId release];
    m_sourceId = val;
    [m_sourceId retain];
}

- (NSString *) sourceId {

    return m_sourceId;
}

-(bool) hasSourceId {

    return m_sourceIdPresent;
}

-(void) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(void) setSourceType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_sourceType = val;
}

- (int) sourceType {

    return m_sourceType;
}

-(void) setTankerStatus:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_tankerStatusPresent = true;
    m_tankerStatus = val;
}

- (int) tankerStatus {

    return m_tankerStatus;
}

-(bool) hasTankerStatus {

    return m_tankerStatusPresent;
}

-(void) setTugs:(bool) val {

    m_tugsPresent = true;
    m_tugs = val;
}

- (bool) tugs {

    return m_tugs;
}

-(bool) hasTugs {

    return m_tugsPresent;
}

-(void) setUpdateTime:(NSDate *) val {

    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Waypoint"]) {
                ILWaypoint * val = [attributeDict objectForKey: key];
                [self addWaypoint: val];
            }
            else if ([key isEqualToString:@"AirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setAirDraught: val];
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setIdent: val];
            }
            else if ([key isEqualToString:@"CargoTypeIMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setCargoTypeIMO: val];
            }
            else if ([key isEqualToString:@"ContactIdentity"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setContactIdentity: val];
            }
            else if ([key isEqualToString:@"DestCode"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDestCode: val];
            }
            else if ([key isEqualToString:@"DestName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDestName: val];
            }
            else if ([key isEqualToString:@"Draught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setDraught: val];
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setETA: val];
            }
            else if ([key isEqualToString:@"ISPSLevel"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setISPSLevel: val];
            }
            else if ([key isEqualToString:@"OverSizedLength"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setOverSizedLength: val];
            }
            else if ([key isEqualToString:@"OverSizedWidth"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setOverSizedWidth: val];
            }
            else if ([key isEqualToString:@"NextPort"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setNextPort: val];
            }
            else if ([key isEqualToString:@"PersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setPersonsOnBoard: val];
            }
            else if ([key isEqualToString:@"Pilots"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setPilots: val];
            }
            else if ([key isEqualToString:@"PrevPort"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setPrevPort: val];
            }
            else if ([key isEqualToString:@"RouteBound"]) {
                NSString *value = [attributeDict objectForKey: key];
                bool val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                [self setRouteBound: val];
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceId: val];
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceName: val];
            }
            else if ([key isEqualToString:@"SourceType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setSourceType: val];
            }
            else if ([key isEqualToString:@"TankerStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setTankerStatus: val];
            }
            else if ([key isEqualToString:@"Tugs"]) {
                NSString *value = [attributeDict objectForKey: key];
                bool val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                [self setTugs: val];
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setUpdateTime: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<VoyageData"];
    if ( [self hasAirDraught] ) {
        [xml appendString: @" AirDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_airDraught]];
        [xml appendString: @"\""];
    }
    [xml appendString: @" Id=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
    [xml appendString: @"\""];
    if ( [self hasCargoTypeIMO] ) {
        [xml appendString: @" CargoTypeIMO=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_cargoTypeIMO]];
        [xml appendString: @"\""];
    }
    if ( [self hasContactIdentity] ) {
        [xml appendString: @" ContactIdentity=\""];
        [xml appendString: [self encode: m_contactIdentity]];
        [xml appendString: @"\""];
    }
    if ( [self hasDestCode] ) {
        [xml appendString: @" DestCode=\""];
        [xml appendString: [self encode: m_destCode]];
        [xml appendString: @"\""];
    }
    if ( [self hasDestName] ) {
        [xml appendString: @" DestName=\""];
        [xml appendString: [self encode: m_destName]];
        [xml appendString: @"\""];
    }
    if ( [self hasDraught] ) {
        [xml appendString: @" Draught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_draught]];
        [xml appendString: @"\""];
    }
    if ( [self hasETA] ) {
        [xml appendString: @" ETA=\""];
        [xml appendString: [self stringFromDate: m_ETA]];
        [xml appendString: @"\""];
    }
    if ( [self hasISPSLevel] ) {
        [xml appendString: @" ISPSLevel=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_ISPSLevel]];
        [xml appendString: @"\""];
    }
    if ( [self hasOverSizedLength] ) {
        [xml appendString: @" OverSizedLength=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_overSizedLength]];
        [xml appendString: @"\""];
    }
    if ( [self hasOverSizedWidth] ) {
        [xml appendString: @" OverSizedWidth=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_overSizedWidth]];
        [xml appendString: @"\""];
    }
    if ( [self hasNextPort] ) {
        [xml appendString: @" NextPort=\""];
        [xml appendString: [self encode: m_nextPort]];
        [xml appendString: @"\""];
    }
    if ( [self hasPersonsOnBoard] ) {
        [xml appendString: @" PersonsOnBoard=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_personsOnBoard]];
        [xml appendString: @"\""];
    }
    if ( [self hasPilots] ) {
        [xml appendString: @" Pilots=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_pilots]];
        [xml appendString: @"\""];
    }
    if ( [self hasPrevPort] ) {
        [xml appendString: @" PrevPort=\""];
        [xml appendString: [self encode: m_prevPort]];
        [xml appendString: @"\""];
    }
    if ( [self hasRouteBound] ) {
        [xml appendString: @" RouteBound=\""];
        [xml appendString: (m_routeBound?@"true":@"false")];
        [xml appendString: @"\""];
    }
    if ( [self hasSourceId] ) {
        [xml appendString: @" SourceId=\""];
        [xml appendString: [self encode: m_sourceId]];
        [xml appendString: @"\""];
    }
    [xml appendString: @" SourceName=\""];
    [xml appendString: [self encode: m_sourceName]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceType=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
    [xml appendString: @"\""];
    if ( [self hasTankerStatus] ) {
        [xml appendString: @" TankerStatus=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_tankerStatus]];
        [xml appendString: @"\""];
    }
    if ( [self hasTugs] ) {
        [xml appendString: @" Tugs=\""];
        [xml appendString: (m_tugs?@"true":@"false")];
        [xml appendString: @"\""];
    }
    [xml appendString: @" UpdateTime=\""];
    [xml appendString: [self stringFromDate: m_updateTime]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    for(int i=0; i < [m_waypoints count]; i++ ) {
        ILWaypoint *attribute = [m_waypoints objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</VoyageData>\n"];
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
    [str setString: [lead stringByAppendingString:@"VoyageData\n"]];
    if ( [self hasAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"AirDraught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_airDraught]];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\"\n"];

    if ( [self hasCargoTypeIMO] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CargoTypeIMO = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_cargoTypeIMO]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasContactIdentity] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ContactIdentity = \""];
        [str appendString: m_contactIdentity];
        [str appendString: @"\"\n"];

    }
    if ( [self hasDestCode] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DestCode = \""];
        [str appendString: m_destCode];
        [str appendString: @"\"\n"];

    }
    if ( [self hasDestName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DestName = \""];
        [str appendString: m_destName];
        [str appendString: @"\"\n"];

    }
    if ( [self hasDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Draught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_draught]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = \""];
        [str appendString: [self stringFromDate: m_ETA]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasISPSLevel] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ISPSLevel = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_ISPSLevel]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasOverSizedLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"OverSizedLength = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_overSizedLength]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasOverSizedWidth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"OverSizedWidth = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_overSizedWidth]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasNextPort] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"NextPort = \""];
        [str appendString: m_nextPort];
        [str appendString: @"\"\n"];

    }
    if ( [self hasPersonsOnBoard] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PersonsOnBoard = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_personsOnBoard]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasPilots] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Pilots = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_pilots]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasPrevPort] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PrevPort = \""];
        [str appendString: m_prevPort];
        [str appendString: @"\"\n"];

    }
    if ( [self hasRouteBound] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"RouteBound = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_routeBound]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasSourceId] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SourceId = \""];
        [str appendString: m_sourceId];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName=\""];
    [str appendString: m_sourceName];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceType=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
    [str appendString: @"\"\n"];

    if ( [self hasTankerStatus] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"TankerStatus = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_tankerStatus]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasTugs] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Tugs = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_tugs]];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime=\""];
    [str appendString: [self stringFromDate: m_updateTime]];
    [str appendString: @"\"\n"];

    for(int i=0; i < [m_waypoints count]; i++ ) {
        ILWaypoint *attribute = [m_waypoints objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasAirDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_airDraught] forKey: @"AirDraught"];
    }
    [attr setObject: [NSString stringWithFormat:@"%d", m_id] forKey: @"Id"];
    if ( [self hasCargoTypeIMO] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_cargoTypeIMO] forKey: @"CargoTypeIMO"];
    }
    if ( [self hasContactIdentity] ) {
        [attr setObject: m_contactIdentity forKey: @"ContactIdentity"];
    }
    if ( [self hasDestCode] ) {
        [attr setObject: m_destCode forKey: @"DestCode"];
    }
    if ( [self hasDestName] ) {
        [attr setObject: m_destName forKey: @"DestName"];
    }
    if ( [self hasDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_draught] forKey: @"Draught"];
    }
    if ( [self hasETA] ) {
        [attr setObject: [self stringFromDate: m_ETA] forKey: @"ETA"];
    }
    if ( [self hasISPSLevel] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_ISPSLevel] forKey: @"ISPSLevel"];
    }
    if ( [self hasOverSizedLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_overSizedLength] forKey: @"OverSizedLength"];
    }
    if ( [self hasOverSizedWidth] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_overSizedWidth] forKey: @"OverSizedWidth"];
    }
    if ( [self hasNextPort] ) {
        [attr setObject: m_nextPort forKey: @"NextPort"];
    }
    if ( [self hasPersonsOnBoard] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_personsOnBoard] forKey: @"PersonsOnBoard"];
    }
    if ( [self hasPilots] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_pilots] forKey: @"Pilots"];
    }
    if ( [self hasPrevPort] ) {
        [attr setObject: m_prevPort forKey: @"PrevPort"];
    }
    if ( [self hasRouteBound] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_routeBound] forKey: @"RouteBound"];
    }
    if ( [self hasSourceId] ) {
        [attr setObject: m_sourceId forKey: @"SourceId"];
    }
    [attr setObject: m_sourceName forKey: @"SourceName"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_sourceType] forKey: @"SourceType"];
    if ( [self hasTankerStatus] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_tankerStatus] forKey: @"TankerStatus"];
    }
    if ( [self hasTugs] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_tugs] forKey: @"Tugs"];
    }
    [attr setObject: [self stringFromDate: m_updateTime] forKey: @"UpdateTime"];

    return attr;
}


@end


