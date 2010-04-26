
#import "ILPosReport.h"


@implementation ILPosReport

- (id) init {
    self = [super init];
    if (self != nil) {
        m_posPresent = NO;
        m_sensors = [[NSMutableArray alloc] init];
        m_sensorPresent = NO;
        m_idPresent = NO;
        m_sourceIdPresent = NO;
        m_updateTimePresent = NO;
        m_updateTimeRadarPresent = NO;
        m_updateTimeAISPresent = NO;
        m_updateTimeDRPresent = NO;
        m_SOGPresent = NO;
        m_COGPresent = NO;
        m_lostPresent = NO;
        m_rateOfTurnPresent = NO;
        m_orientationPresent = NO;
        m_lengthPresent = NO;
        m_breadthPresent = NO;
        m_altitudePresent = NO;
        m_navStatusPresent = NO;
        m_updSensorTypePresent = NO;
        m_ATONOffPosPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_pos release];
    [m_sensors release];
    [m_updateTime release];
    [m_updateTimeRadar release];
    [m_updateTimeAIS release];
    [m_updateTimeDR release];
    [m_lost release];
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

-(BOOL) setPos:(ILPos *) val {

    m_posPresent = YES;
    [m_pos release];
    m_pos = val;
    [m_pos retain];
    return YES;
}

- (ILPos *) pos {

    return m_pos;
}

-(BOOL) addSensor:(ILSensor *) val {

    [m_sensors addObject: val];
     return YES;
}

-(ILSensor *) sensorAt:(int) i {

    return [m_sensors objectAtIndex: i];
}

-(int) countOfSensors {

    return [m_sensors count];
}

-(NSArray *) sensors {

    return m_sensors;
}

-(BOOL) setIdent:(int) val {

    m_idPresent = YES;
    m_id = val;
    return YES;
}

- (int) ident {

    return m_id;
}

-(BOOL) setSourceId:(int) val {

    m_sourceIdPresent = YES;
    m_sourceId = val;
    return YES;
}

- (int) sourceId {

    return m_sourceId;
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

-(BOOL) setUpdateTimeRadar:(NSDate *) val {

    m_updateTimeRadarPresent = YES;
    [m_updateTimeRadar release];
    m_updateTimeRadar = val;
    [m_updateTimeRadar retain];
    return YES;
}

- (NSDate *) updateTimeRadar {

    return m_updateTimeRadar;
}

-(BOOL) hasUpdateTimeRadar {

    return m_updateTimeRadarPresent;
}

-(BOOL) setUpdateTimeAIS:(NSDate *) val {

    m_updateTimeAISPresent = YES;
    [m_updateTimeAIS release];
    m_updateTimeAIS = val;
    [m_updateTimeAIS retain];
    return YES;
}

- (NSDate *) updateTimeAIS {

    return m_updateTimeAIS;
}

-(BOOL) hasUpdateTimeAIS {

    return m_updateTimeAISPresent;
}

-(BOOL) setUpdateTimeDR:(NSDate *) val {

    m_updateTimeDRPresent = YES;
    [m_updateTimeDR release];
    m_updateTimeDR = val;
    [m_updateTimeDR retain];
    return YES;
}

- (NSDate *) updateTimeDR {

    return m_updateTimeDR;
}

-(BOOL) hasUpdateTimeDR {

    return m_updateTimeDRPresent;
}

-(BOOL) setSOG:(float) val {

    if (val < 0)
        return NO;
    m_SOGPresent = YES;
    m_SOG = val;
    return YES;
}

- (float) SOG {

    return m_SOG;
}

-(BOOL) setCOG:(float) val {

    if (val < 0)
        return NO;
    if (val > 360)
        return NO;
    m_COGPresent = YES;
    m_COG = val;
    return YES;
}

- (float) COG {

    return m_COG;
}

-(BOOL) setLost:(NSString *) val {

    if ( ( ![val isEqualToString: @"no"] ) &&
         ( ![val isEqualToString: @"yes"] ) )
        return NO;
    m_lostPresent = YES;
    [m_lost release];
    m_lost = val;
    [m_lost retain];
    return YES;
}

- (NSString *) lost {

    return m_lost;
}

-(BOOL) setRateOfTurn:(float) val {

    m_rateOfTurnPresent = YES;
    m_rateOfTurn = val;
    return YES;
}

- (float) rateOfTurn {

    return m_rateOfTurn;
}

-(BOOL) hasRateOfTurn {

    return m_rateOfTurnPresent;
}

-(BOOL) setOrientation:(float) val {

    if (val < 0)
        return NO;
    if (val > 360)
        return NO;
    m_orientationPresent = YES;
    m_orientation = val;
    return YES;
}

- (float) orientation {

    return m_orientation;
}

-(BOOL) hasOrientation {

    return m_orientationPresent;
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

-(BOOL) setAltitude:(float) val {

    m_altitudePresent = YES;
    m_altitude = val;
    return YES;
}

- (float) altitude {

    return m_altitude;
}

-(BOOL) hasAltitude {

    return m_altitudePresent;
}

-(BOOL) setNavStatus:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
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
         ( val != 15 ) )
        return NO;
    m_navStatusPresent = YES;
    m_navStatus = val;
    return YES;
}

- (int) navStatus {

    return m_navStatus;
}

-(BOOL) hasNavStatus {

    return m_navStatusPresent;
}

-(BOOL) setUpdSensorType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return NO;
    m_updSensorTypePresent = YES;
    m_updSensorType = val;
    return YES;
}

- (int) updSensorType {

    return m_updSensorType;
}

-(BOOL) hasUpdSensorType {

    return m_updSensorTypePresent;
}

-(BOOL) setATONOffPos:(BOOL) val {

    m_ATONOffPosPresent = YES;
    m_ATONOffPos = val;
    return YES;
}

- (BOOL) ATONOffPos {

    return m_ATONOffPos;
}

-(BOOL) hasATONOffPos {

    return m_ATONOffPosPresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Pos"]) {
                ILPos * val = [attributeDict objectForKey: key];
                if (![self setPos: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Sensor"]) {
                ILSensor * val = [attributeDict objectForKey: key];
                if (![self addSensor: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIdent: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setSourceId: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTime: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTimeRadar"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTimeRadar: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTimeAIS"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTimeAIS: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTimeDR"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTimeDR: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setSOG: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"COG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setCOG: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Lost"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setLost: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"RateOfTurn"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setRateOfTurn: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Orientation"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setOrientation: val]) {
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
            else if ([key isEqualToString:@"Altitude"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setAltitude: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"NavStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setNavStatus: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdSensorType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setUpdSensorType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ATONOffPos"]) {
                NSString *value = [attributeDict objectForKey: key];
                BOOL val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                if (![self setATONOffPos: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<PosReport"];
    if ( m_idPresent ) {
        [xml appendString: @" Id=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Id" forKey: @"description"]];
        return nil;
    }
    if ( m_sourceIdPresent ) {
        [xml appendString: @" SourceId=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_sourceId]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceId" forKey: @"description"]];
        return nil;
    }
    if ( m_updateTimePresent ) {
        [xml appendString: @" UpdateTime=\""];
        [xml appendString: [self stringFromDate: m_updateTime]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"UpdateTime" forKey: @"description"]];
        return nil;
    }
    if ( [self hasUpdateTimeRadar] ) {
        [xml appendString: @" UpdateTimeRadar=\""];
        [xml appendString: [self stringFromDate: m_updateTimeRadar]];
        [xml appendString: @"\""];
    }
    if ( [self hasUpdateTimeAIS] ) {
        [xml appendString: @" UpdateTimeAIS=\""];
        [xml appendString: [self stringFromDate: m_updateTimeAIS]];
        [xml appendString: @"\""];
    }
    if ( [self hasUpdateTimeDR] ) {
        [xml appendString: @" UpdateTimeDR=\""];
        [xml appendString: [self stringFromDate: m_updateTimeDR]];
        [xml appendString: @"\""];
    }
    if ( m_SOGPresent ) {
        [xml appendString: @" SOG=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_SOG]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SOG" forKey: @"description"]];
        return nil;
    }
    if ( m_COGPresent ) {
        [xml appendString: @" COG=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_COG]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"COG" forKey: @"description"]];
        return nil;
    }
    if ( m_lostPresent ) {
        [xml appendString: @" Lost=\""];
        [xml appendString: [self encode: m_lost]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Lost" forKey: @"description"]];
        return nil;
    }
    if ( [self hasRateOfTurn] ) {
        [xml appendString: @" RateOfTurn=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_rateOfTurn]];
        [xml appendString: @"\""];
    }
    if ( [self hasOrientation] ) {
        [xml appendString: @" Orientation=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_orientation]];
        [xml appendString: @"\""];
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
    if ( [self hasAltitude] ) {
        [xml appendString: @" Altitude=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_altitude]];
        [xml appendString: @"\""];
    }
    if ( [self hasNavStatus] ) {
        [xml appendString: @" NavStatus=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_navStatus]];
        [xml appendString: @"\""];
    }
    if ( [self hasUpdSensorType] ) {
        [xml appendString: @" UpdSensorType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_updSensorType]];
        [xml appendString: @"\""];
    }
    if ( [self hasATONOffPos] ) {
        [xml appendString: @" ATONOffPos=\""];
        [xml appendString: (m_ATONOffPos?@"true":@"false")];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    if ( m_posPresent ) {
        [xml appendString: [m_pos XML] ];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Pos" forKey: @"description"]];
        return nil;
    }
    if ([m_sensors count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of Sensor" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_sensors count]; i++ ) {
        ILSensor *attribute = [m_sensors objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</PosReport>\n"];
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
    [str setString: [lead stringByAppendingString:@"PosReport\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceId = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceId]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime = "];
    [str appendString: [self stringFromDate: m_updateTime]];
    [str appendString: @"\n"];

    if ( [self hasUpdateTimeRadar] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"UpdateTimeRadar = "];
        [str appendString: [self stringFromDate: m_updateTimeRadar]];
        [str appendString: @"\n"];

    }
    if ( [self hasUpdateTimeAIS] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"UpdateTimeAIS = "];
        [str appendString: [self stringFromDate: m_updateTimeAIS]];
        [str appendString: @"\n"];

    }
    if ( [self hasUpdateTimeDR] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"UpdateTimeDR = "];
        [str appendString: [self stringFromDate: m_updateTimeDR]];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SOG = "];
    [str appendString: [NSString stringWithFormat:@"%f", m_SOG]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"COG = "];
    [str appendString: [NSString stringWithFormat:@"%f", m_COG]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Lost = "];
    [str appendString: m_lost];
    [str appendString: @"\n"];

    if ( [self hasRateOfTurn] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"RateOfTurn = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_rateOfTurn]];
        [str appendString: @"\n"];

    }
    if ( [self hasOrientation] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Orientation = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_orientation]];
        [str appendString: @"\n"];

    }
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
    if ( [self hasAltitude] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Altitude = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_altitude]];
        [str appendString: @"\n"];

    }
    if ( [self hasNavStatus] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"NavStatus = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_navStatus]];
        [str appendString: @"\n"];

    }
    if ( [self hasUpdSensorType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"UpdSensorType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_updSensorType]];
        [str appendString: @"\n"];

    }
    if ( [self hasATONOffPos] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATONOffPos = "];
        [str appendString: (m_ATONOffPos?@"true":@"false")];
        [str appendString: @"\n"];

    }
    [str appendString: [m_pos stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    for(int i=0; i < [m_sensors count]; i++ ) {
        ILSensor *attribute = [m_sensors objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_id] forKey: @"Id"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_sourceId] forKey: @"SourceId"];
    [attr setObject: [self stringFromDate: m_updateTime] forKey: @"UpdateTime"];
    if ( [self hasUpdateTimeRadar] ) {
        [attr setObject: [self stringFromDate: m_updateTimeRadar] forKey: @"UpdateTimeRadar"];
    }
    if ( [self hasUpdateTimeAIS] ) {
        [attr setObject: [self stringFromDate: m_updateTimeAIS] forKey: @"UpdateTimeAIS"];
    }
    if ( [self hasUpdateTimeDR] ) {
        [attr setObject: [self stringFromDate: m_updateTimeDR] forKey: @"UpdateTimeDR"];
    }
    [attr setObject: [NSString stringWithFormat:@"%f", m_SOG] forKey: @"SOG"];
    [attr setObject: [NSString stringWithFormat:@"%f", m_COG] forKey: @"COG"];
    [attr setObject: m_lost forKey: @"Lost"];
    if ( [self hasRateOfTurn] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_rateOfTurn] forKey: @"RateOfTurn"];
    }
    if ( [self hasOrientation] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_orientation] forKey: @"Orientation"];
    }
    if ( [self hasLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_length] forKey: @"Length"];
    }
    if ( [self hasBreadth] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_breadth] forKey: @"Breadth"];
    }
    if ( [self hasAltitude] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_altitude] forKey: @"Altitude"];
    }
    if ( [self hasNavStatus] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_navStatus] forKey: @"NavStatus"];
    }
    if ( [self hasUpdSensorType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_updSensorType] forKey: @"UpdSensorType"];
    }
    if ( [self hasATONOffPos] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_ATONOffPos] forKey: @"ATONOffPos"];
    }

    return attr;
}


@end


