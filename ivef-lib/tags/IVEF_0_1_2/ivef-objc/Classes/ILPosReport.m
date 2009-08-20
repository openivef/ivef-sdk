
#import "ILPosReport.h"


@implementation ILPosReport

- (id) init {
    self = [super init];
    if (self != nil) {
        m_sensors = [[NSMutableArray alloc] init];
        m_rateOfTurnPresent = false;
        m_orientationPresent = false;
        m_lengthPresent = false;
        m_breadthPresent = false;
        m_altitudePresent = false;
        m_navStatusPresent = false;
        m_updSensorTypePresent = false;
        m_ATONOffPosPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_pos release];
    [m_sensors release];
    [m_updateTime release];
    [m_lost release];
    [super dealloc];
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [NSString stringByReplacingOccurrencesOfString:@"Z" withString:@];

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

-(void) setPos:(ILPos *) val {

    [m_pos release];
    m_pos = val;
    [m_pos retain];
}

- (ILPos *) pos {

    return m_pos;
}

-(void) addSensor:(ILSensor *) val {

    [m_sensors addObject: val];
}

-(ILSensor *) getSensorAt:(int) i {

    return [m_sensors objectAtIndex: i];
}

-(int) countOfSensors {

    return [m_sensors count];
}

-(NSArray *) Sensors {

    return m_sensors;
}

-(void) setIdent:(int) val {

    m_id = val;
}

- (int) ident {

    return m_id;
}

-(void) setSourceId:(int) val {

    m_sourceId = val;
}

- (int) sourceId {

    return m_sourceId;
}

-(void) setUpdateTime:(NSDate *) val {

    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(void) setSOG:(float) val {

    m_SOG = val;
}

- (float) sOG {

    return m_SOG;
}

-(void) setCOG:(float) val {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_COG = val;
}

- (float) cOG {

    return m_COG;
}

-(void) setLost:(NSString *) val {

    if ( ( ![val isEqualToString: @"no"] ) &&
         ( ![val isEqualToString: @"yes"] ) )
        return;
    [m_lost release];
    m_lost = val;
    [m_lost retain];
}

- (NSString *) lost {

    return m_lost;
}

-(void) setRateOfTurn:(float) val {

    m_rateOfTurnPresent = true;
    m_rateOfTurn = val;
}

- (float) rateOfTurn {

    return m_rateOfTurn;
}

-(bool) hasRateOfTurn {

    return m_rateOfTurnPresent;
}

-(void) setOrientation:(float) val {

    if (val < 0)
        return;
    if (val > 360)
        return;
    m_orientationPresent = true;
    m_orientation = val;
}

- (float) orientation {

    return m_orientation;
}

-(bool) hasOrientation {

    return m_orientationPresent;
}

-(void) setLength:(float) val {

    m_lengthPresent = true;
    m_length = val;
}

- (float) length {

    return m_length;
}

-(bool) hasLength {

    return m_lengthPresent;
}

-(void) setBreadth:(float) val {

    m_breadthPresent = true;
    m_breadth = val;
}

- (float) breadth {

    return m_breadth;
}

-(bool) hasBreadth {

    return m_breadthPresent;
}

-(void) setAltitude:(float) val {

    m_altitudePresent = true;
    m_altitude = val;
}

- (float) altitude {

    return m_altitude;
}

-(bool) hasAltitude {

    return m_altitudePresent;
}

-(void) setNavStatus:(int) val {

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
        return;
    m_navStatusPresent = true;
    m_navStatus = val;
}

- (int) navStatus {

    return m_navStatus;
}

-(bool) hasNavStatus {

    return m_navStatusPresent;
}

-(void) setUpdSensorType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 5 ) )
        return;
    m_updSensorTypePresent = true;
    m_updSensorType = val;
}

- (int) updSensorType {

    return m_updSensorType;
}

-(bool) hasUpdSensorType {

    return m_updSensorTypePresent;
}

-(void) setATONOffPos:(bool) val {

    m_ATONOffPosPresent = true;
    m_ATONOffPos = val;
}

- (bool) aTONOffPos {

    return m_ATONOffPos;
}

-(bool) hasATONOffPos {

    return m_ATONOffPosPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Pos"]) {
                ILPos * val = [attributeDict objectForKey: key];
                [self setPos: val];
            }
            else if ([key isEqualToString:@"Sensor"]) {
                ILSensor * val = [attributeDict objectForKey: key];
                [self addSensor: val];
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setId: val];
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setSourceId: val];
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setUpdateTime: val];
            }
            else if ([key isEqualToString:@"SOG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setSOG: val];
            }
            else if ([key isEqualToString:@"COG"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setCOG: val];
            }
            else if ([key isEqualToString:@"Lost"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setLost: val];
            }
            else if ([key isEqualToString:@"RateOfTurn"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setRateOfTurn: val];
            }
            else if ([key isEqualToString:@"Orientation"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setOrientation: val];
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
            else if ([key isEqualToString:@"Altitude"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setAltitude: val];
            }
            else if ([key isEqualToString:@"NavStatus"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setNavStatus: val];
            }
            else if ([key isEqualToString:@"UpdSensorType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setUpdSensorType: val];
            }
            else if ([key isEqualToString:@"ATONOffPos"]) {
                NSString *value = [attributeDict objectForKey: key];
                bool val = [[value uppercaseString] isEqualToString: @"YES"];
                [self setATONOffPos: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<PosReport"];
    [xml appendString: @" Id=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceId=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_sourceId]];
    [xml appendString: @"\""];
    [xml appendString: @" UpdateTime=\""];
    [xml appendString: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [xml appendString: @"\""];
    [xml appendString: @" SOG=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_SOG]];
    [xml appendString: @"\""];
    [xml appendString: @" COG=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_COG]];
    [xml appendString: @"\""];
    [xml appendString: @" Lost=\""];
    [xml appendString: [m_lost encode]];
    [xml appendString: @"\""];
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
        [xml appendString: (m_ATONOffPos?@"yes":@"no")];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: [m_pos XML] ];
    for(int i=0; i < [m_sensors count]; i++ ) {
        ILSensor *attribute = [m_sensors objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</PosReport>\n"];
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

-(NSString *) stringValue {

    return [self stringValueWithLead:@""];
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"PosReport\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceId=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceId]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime=\""];
    [str appendString: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SOG=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_SOG]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"COG=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_COG]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Lost=\""];
    [str appendString: m_lost];
    [str appendString: @"\"\n"];

    if ( [self hasRateOfTurn] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"RateOfTurn = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_rateOfTurn]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasOrientation] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Orientation = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_orientation]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Length = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_length]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasBreadth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Breadth = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_breadth]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasAltitude] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Altitude = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_altitude]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasNavStatus] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"NavStatus = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_navStatus]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasUpdSensorType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"UpdSensorType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_updSensorType]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasATONOffPos] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ATONOffPos = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_ATONOffPos]];
        [str appendString: @"\"\n"];

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
    [attr setObject: [m_updateTime descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%FZ" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]] forKey: @"UpdateTime"];
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


