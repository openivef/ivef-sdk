
#import "ILVoyageData.h"


@implementation ILVoyageData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_waypoints = [[NSMutableArray alloc] init];
        m_waypointPresent = NO;
        m_airDraughtPresent = NO;
        m_idPresent = NO;
        m_cargoTypeIMOPresent = NO;
        m_contactIdentityPresent = NO;
        m_destCodePresent = NO;
        m_destNamePresent = NO;
        m_departCodePresent = NO;
        m_departNamePresent = NO;
        m_draughtPresent = NO;
        m_ETAPresent = NO;
        m_ATDPresent = NO;
        m_ISPSLevelPresent = NO;
        m_overSizedLengthPresent = NO;
        m_overSizedWidthPresent = NO;
        m_personsOnBoardPresent = NO;
        m_pilotsPresent = NO;
        m_routeBoundPresent = NO;
        m_sourceIdPresent = NO;
        m_sourceNamePresent = NO;
        m_sourceTypePresent = NO;
        m_tankerStatusPresent = NO;
        m_tugsPresent = NO;
        m_updateTimePresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_waypoints release];
    [m_contactIdentity release];
    [m_destCode release];
    [m_destName release];
    [m_departCode release];
    [m_departName release];
    [m_ETA release];
    [m_ATD release];
    [m_sourceId release];
    [m_sourceName release];
    [m_updateTime release];
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

-(BOOL) removeWaypoint:(ILWaypoint *) val {

    [m_waypoints removeObject: val];
     return YES;
}

-(BOOL) addWaypoint:(ILWaypoint *) val {

    [m_waypoints addObject: val];
     return YES;
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

-(BOOL) setIdent:(int) val {

    m_idPresent = YES;
    m_id = val;
    return YES;
}

- (int) ident {

    return m_id;
}

-(BOOL) setCargoTypeIMO:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return NO;
    m_cargoTypeIMOPresent = YES;
    m_cargoTypeIMO = val;
    return YES;
}

- (int) cargoTypeIMO {

    return m_cargoTypeIMO;
}

-(BOOL) hasCargoTypeIMO {

    return m_cargoTypeIMOPresent;
}

-(BOOL) setContactIdentity:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 254)
        return NO;
    m_contactIdentityPresent = YES;
    [m_contactIdentity release];
    m_contactIdentity = val;
    [m_contactIdentity retain];
    return YES;
}

- (NSString *) contactIdentity {

    return m_contactIdentity;
}

-(BOOL) hasContactIdentity {

    return m_contactIdentityPresent;
}

-(BOOL) setDestCode:(NSString *) val {

    if ([val length] < 5)
        return NO;
    if ([val length] > 15)
        return NO;
    m_destCodePresent = YES;
    [m_destCode release];
    m_destCode = val;
    [m_destCode retain];
    return YES;
}

- (NSString *) destCode {

    return m_destCode;
}

-(BOOL) hasDestCode {

    return m_destCodePresent;
}

-(BOOL) setDestName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_destNamePresent = YES;
    [m_destName release];
    m_destName = val;
    [m_destName retain];
    return YES;
}

- (NSString *) destName {

    return m_destName;
}

-(BOOL) hasDestName {

    return m_destNamePresent;
}

-(BOOL) setDepartCode:(NSString *) val {

    if ([val length] < 5)
        return NO;
    if ([val length] > 15)
        return NO;
    m_departCodePresent = YES;
    [m_departCode release];
    m_departCode = val;
    [m_departCode retain];
    return YES;
}

- (NSString *) departCode {

    return m_departCode;
}

-(BOOL) hasDepartCode {

    return m_departCodePresent;
}

-(BOOL) setDepartName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_departNamePresent = YES;
    [m_departName release];
    m_departName = val;
    [m_departName retain];
    return YES;
}

- (NSString *) departName {

    return m_departName;
}

-(BOOL) hasDepartName {

    return m_departNamePresent;
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

-(BOOL) setATD:(NSDate *) val {

    m_ATDPresent = YES;
    [m_ATD release];
    m_ATD = val;
    [m_ATD retain];
    return YES;
}

- (NSDate *) ATD {

    return m_ATD;
}

-(BOOL) hasATD {

    return m_ATDPresent;
}

-(BOOL) setISPSLevel:(float) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_ISPSLevelPresent = YES;
    m_ISPSLevel = val;
    return YES;
}

- (float) ISPSLevel {

    return m_ISPSLevel;
}

-(BOOL) hasISPSLevel {

    return m_ISPSLevelPresent;
}

-(BOOL) setOverSizedLength:(float) val {

    if (val < 0)
        return NO;
    m_overSizedLengthPresent = YES;
    m_overSizedLength = val;
    return YES;
}

- (float) overSizedLength {

    return m_overSizedLength;
}

-(BOOL) hasOverSizedLength {

    return m_overSizedLengthPresent;
}

-(BOOL) setOverSizedWidth:(float) val {

    if (val < 0)
        return NO;
    m_overSizedWidthPresent = YES;
    m_overSizedWidth = val;
    return YES;
}

- (float) overSizedWidth {

    return m_overSizedWidth;
}

-(BOOL) hasOverSizedWidth {

    return m_overSizedWidthPresent;
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

-(BOOL) setPilots:(float) val {

    if (val < 0)
        return NO;
    m_pilotsPresent = YES;
    m_pilots = val;
    return YES;
}

- (float) pilots {

    return m_pilots;
}

-(BOOL) hasPilots {

    return m_pilotsPresent;
}

-(BOOL) setRouteBound:(BOOL) val {

    m_routeBoundPresent = YES;
    m_routeBound = val;
    return YES;
}

- (BOOL) routeBound {

    return m_routeBound;
}

-(BOOL) hasRouteBound {

    return m_routeBoundPresent;
}

-(BOOL) setSourceId:(NSString *) val {

    if ([val length] < 5)
        return NO;
    if ([val length] > 15)
        return NO;
    m_sourceIdPresent = YES;
    [m_sourceId release];
    m_sourceId = val;
    [m_sourceId retain];
    return YES;
}

- (NSString *) sourceId {

    return m_sourceId;
}

-(BOOL) hasSourceId {

    return m_sourceIdPresent;
}

-(BOOL) setSourceName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_sourceNamePresent = YES;
    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
    return YES;
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(BOOL) setSourceType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return NO;
    m_sourceTypePresent = YES;
    m_sourceType = val;
    return YES;
}

- (int) sourceType {

    return m_sourceType;
}

-(BOOL) setTankerStatus:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return NO;
    m_tankerStatusPresent = YES;
    m_tankerStatus = val;
    return YES;
}

- (int) tankerStatus {

    return m_tankerStatus;
}

-(BOOL) hasTankerStatus {

    return m_tankerStatusPresent;
}

-(BOOL) setTugs:(BOOL) val {

    m_tugsPresent = YES;
    m_tugs = val;
    return YES;
}

- (BOOL) tugs {

    return m_tugs;
}

-(BOOL) hasTugs {

    return m_tugsPresent;
}

-(BOOL) setUpdateTime:(NSDate *) val {

    m_updateTimePresent = YES;
    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
    return YES;
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"AirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAirDraught: val]) {
                   return NO;
                }
                if (![self setAirDraught: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIdent: val]) {
                   return NO;
                }
                if (![self setIdent: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"CargoTypeIMO"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setCargoTypeIMO: val]) {
                   return NO;
                }
                if (![self setCargoTypeIMO: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ContactIdentity"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setContactIdentity: val]) {
                   return NO;
                }
                if (![self setContactIdentity: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"DestCode"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDestCode: val]) {
                   return NO;
                }
                if (![self setDestCode: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"DestName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDestName: val]) {
                   return NO;
                }
                if (![self setDestName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"DepartCode"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDepartCode: val]) {
                   return NO;
                }
                if (![self setDepartCode: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"DepartName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDepartName: val]) {
                   return NO;
                }
                if (![self setDepartName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Draught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setDraught: val]) {
                   return NO;
                }
                if (![self setDraught: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ETA"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setETA: val]) {
                   return NO;
                }
                if (![self setETA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ATD"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setATD: val]) {
                   return NO;
                }
                if (![self setATD: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ISPSLevel"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setISPSLevel: val]) {
                   return NO;
                }
                if (![self setISPSLevel: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"OverSizedLength"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setOverSizedLength: val]) {
                   return NO;
                }
                if (![self setOverSizedLength: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"OverSizedWidth"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setOverSizedWidth: val]) {
                   return NO;
                }
                if (![self setOverSizedWidth: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"PersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setPersonsOnBoard: val]) {
                   return NO;
                }
                if (![self setPersonsOnBoard: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Pilots"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setPilots: val]) {
                   return NO;
                }
                if (![self setPilots: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"RouteBound"]) {
                NSString *value = [attributeDict objectForKey: key];
                BOOL val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                if (![self setRouteBound: val]) {
                   return NO;
                }
                if (![self setRouteBound: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceId: val]) {
                   return NO;
                }
                if (![self setSourceId: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceName: val]) {
                   return NO;
                }
                if (![self setSourceName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setSourceType: val]) {
                   return NO;
                }
                if (![self setSourceType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"TankerStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setTankerStatus: val]) {
                   return NO;
                }
                if (![self setTankerStatus: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Tugs"]) {
                NSString *value = [attributeDict objectForKey: key];
                BOOL val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                if (![self setTugs: val]) {
                   return NO;
                }
                if (![self setTugs: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTime: val]) {
                   return NO;
                }
                if (![self setUpdateTime: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<VoyageData"];
    NSString *dataMember;
    if ( [self hasAirDraught] ) {
        [xml appendString: @" AirDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%.2f", m_airDraught]];
        [xml appendString: @"\""];
    }
    if ( m_idPresent ) {
        [xml appendString: @" Id=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Id" forKey: @"description"]];
        return nil;
    }
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
    if ( [self hasDepartCode] ) {
        [xml appendString: @" DepartCode=\""];
        [xml appendString: [self encode: m_departCode]];
        [xml appendString: @"\""];
    }
    if ( [self hasDepartName] ) {
        [xml appendString: @" DepartName=\""];
        [xml appendString: [self encode: m_departName]];
        [xml appendString: @"\""];
    }
    if ( [self hasDraught] ) {
        [xml appendString: @" Draught=\""];
        [xml appendString: [NSString stringWithFormat:@"%.2f", m_draught]];
        [xml appendString: @"\""];
    }
    if ( [self hasETA] ) {
        [xml appendString: @" ETA=\""];
        [xml appendString: [self stringFromDate: m_ETA]];
        [xml appendString: @"\""];
    }
    if ( [self hasATD] ) {
        [xml appendString: @" ATD=\""];
        [xml appendString: [self stringFromDate: m_ATD]];
        [xml appendString: @"\""];
    }
    if ( [self hasISPSLevel] ) {
        [xml appendString: @" ISPSLevel=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_ISPSLevel]];
        [xml appendString: @"\""];
    }
    if ( [self hasOverSizedLength] ) {
        [xml appendString: @" OverSizedLength=\""];
        [xml appendString: [NSString stringWithFormat:@"%.1f", m_overSizedLength]];
        [xml appendString: @"\""];
    }
    if ( [self hasOverSizedWidth] ) {
        [xml appendString: @" OverSizedWidth=\""];
        [xml appendString: [NSString stringWithFormat:@"%.1f", m_overSizedWidth]];
        [xml appendString: @"\""];
    }
    if ( [self hasPersonsOnBoard] ) {
        [xml appendString: @" PersonsOnBoard=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_personsOnBoard]];
        [xml appendString: @"\""];
    }
    if ( [self hasPilots] ) {
        [xml appendString: @" Pilots=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_pilots]];
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
    if ( m_sourceNamePresent ) {
        [xml appendString: @" SourceName=\""];
        [xml appendString: [self encode: m_sourceName]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceName" forKey: @"description"]];
        return nil;
    }
    if ( m_sourceTypePresent ) {
        [xml appendString: @" SourceType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceType" forKey: @"description"]];
        return nil;
    }
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
    if ( m_updateTimePresent ) {
        [xml appendString: @" UpdateTime=\""];
        [xml appendString: [self stringFromDate: m_updateTime]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"UpdateTime" forKey: @"description"]];
        return nil;
    }
    [xml appendString:@">\n"];
    if ([m_waypoints count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of Waypoint" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_waypoints count]; i++ ) {
        ILWaypoint *attribute = [m_waypoints objectAtIndex:i];
        dataMember = [attribute XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Waypoint" forKey: @"description"]];
            return nil;
        }
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
        [str appendString: @"AirDraught = "];
        [str appendString: [NSString stringWithFormat:@"%.2f", m_airDraught]];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\n"];

    if ( [self hasCargoTypeIMO] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CargoTypeIMO = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_cargoTypeIMO]];
        [str appendString: @"\n"];

    }
    if ( [self hasContactIdentity] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ContactIdentity = "];
        [str appendString: m_contactIdentity];
        [str appendString: @"\n"];

    }
    if ( [self hasDestCode] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DestCode = "];
        [str appendString: m_destCode];
        [str appendString: @"\n"];

    }
    if ( [self hasDestName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DestName = "];
        [str appendString: m_destName];
        [str appendString: @"\n"];

    }
    if ( [self hasDepartCode] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DepartCode = "];
        [str appendString: m_departCode];
        [str appendString: @"\n"];

    }
    if ( [self hasDepartName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DepartName = "];
        [str appendString: m_departName];
        [str appendString: @"\n"];

    }
    if ( [self hasDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Draught = "];
        [str appendString: [NSString stringWithFormat:@"%.2f", m_draught]];
        [str appendString: @"\n"];

    }
    if ( [self hasETA] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ETA = "];
        [str appendString: [self stringFromDate: m_ETA]];
        [str appendString: @"\n"];

    }
    if ( [self hasATD] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATD = "];
        [str appendString: [self stringFromDate: m_ATD]];
        [str appendString: @"\n"];

    }
    if ( [self hasISPSLevel] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ISPSLevel = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_ISPSLevel]];
        [str appendString: @"\n"];

    }
    if ( [self hasOverSizedLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"OverSizedLength = "];
        [str appendString: [NSString stringWithFormat:@"%.1f", m_overSizedLength]];
        [str appendString: @"\n"];

    }
    if ( [self hasOverSizedWidth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"OverSizedWidth = "];
        [str appendString: [NSString stringWithFormat:@"%.1f", m_overSizedWidth]];
        [str appendString: @"\n"];

    }
    if ( [self hasPersonsOnBoard] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"PersonsOnBoard = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_personsOnBoard]];
        [str appendString: @"\n"];

    }
    if ( [self hasPilots] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Pilots = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_pilots]];
        [str appendString: @"\n"];

    }
    if ( [self hasRouteBound] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"RouteBound = "];
        [str appendString: (m_routeBound?@"true":@"false")];
        [str appendString: @"\n"];

    }
    if ( [self hasSourceId] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SourceId = "];
        [str appendString: m_sourceId];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName = "];
    [str appendString: m_sourceName];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceType = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
    [str appendString: @"\n"];

    if ( [self hasTankerStatus] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"TankerStatus = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_tankerStatus]];
        [str appendString: @"\n"];

    }
    if ( [self hasTugs] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Tugs = "];
        [str appendString: (m_tugs?@"true":@"false")];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime = "];
    [str appendString: [self stringFromDate: m_updateTime]];
    [str appendString: @"\n"];

    for(int i=0; i < [m_waypoints count]; i++ ) {
        ILWaypoint *attribute = [m_waypoints objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasAirDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%.2f", m_airDraught] forKey: @"AirDraught"];
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
    if ( [self hasDepartCode] ) {
        [attr setObject: m_departCode forKey: @"DepartCode"];
    }
    if ( [self hasDepartName] ) {
        [attr setObject: m_departName forKey: @"DepartName"];
    }
    if ( [self hasDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%.2f", m_draught] forKey: @"Draught"];
    }
    if ( [self hasETA] ) {
        [attr setObject: [self stringFromDate: m_ETA] forKey: @"ETA"];
    }
    if ( [self hasATD] ) {
        [attr setObject: [self stringFromDate: m_ATD] forKey: @"ATD"];
    }
    if ( [self hasISPSLevel] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_ISPSLevel] forKey: @"ISPSLevel"];
    }
    if ( [self hasOverSizedLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%.1f", m_overSizedLength] forKey: @"OverSizedLength"];
    }
    if ( [self hasOverSizedWidth] ) {
        [attr setObject: [NSString stringWithFormat:@"%.1f", m_overSizedWidth] forKey: @"OverSizedWidth"];
    }
    if ( [self hasPersonsOnBoard] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_personsOnBoard] forKey: @"PersonsOnBoard"];
    }
    if ( [self hasPilots] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_pilots] forKey: @"Pilots"];
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


