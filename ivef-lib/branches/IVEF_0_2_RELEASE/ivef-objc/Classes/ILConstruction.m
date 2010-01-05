
#import "ILConstruction.h"


@implementation ILConstruction

- (id) init {
    self = [super init];
    if (self != nil) {
        m_hullColorPresent = false;
        m_hullTypePresent = false;
        m_lengthPresent = false;
        m_lloydsShipTypePresent = false;
        m_maxKeelHeightPresent = false;
        m_maxDraughtPresent = false;
        m_maxPersonsOnBoardPresent = false;
        m_maxSpeedPresent = false;
        m_widthPresent = false;
    }
    return self;
}

- (void) dealloc {

    [m_unType release];
    [m_hullColor release];
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

-(void) setUnType:(ILUnType *) val {

    [m_unType release];
    m_unType = val;
    [m_unType retain];
}

- (ILUnType *) unType {

    return m_unType;
}

-(void) setHullColor:(NSString *) val {

    m_hullColorPresent = true;
    [m_hullColor release];
    m_hullColor = val;
    [m_hullColor retain];
}

- (NSString *) hullColor {

    return m_hullColor;
}

-(bool) hasHullColor {

    return m_hullColorPresent;
}

-(void) setHullType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_hullTypePresent = true;
    m_hullType = val;
}

- (int) hullType {

    return m_hullType;
}

-(bool) hasHullType {

    return m_hullTypePresent;
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

-(void) setLloydsShipType:(int) val {

    m_lloydsShipTypePresent = true;
    m_lloydsShipType = val;
}

- (int) lloydsShipType {

    return m_lloydsShipType;
}

-(bool) hasLloydsShipType {

    return m_lloydsShipTypePresent;
}

-(void) setMaxKeelHeight:(float) val {

    m_maxKeelHeightPresent = true;
    m_maxKeelHeight = val;
}

- (float) maxKeelHeight {

    return m_maxKeelHeight;
}

-(bool) hasMaxKeelHeight {

    return m_maxKeelHeightPresent;
}

-(void) setMaxDraught:(float) val {

    m_maxDraughtPresent = true;
    m_maxDraught = val;
}

- (float) maxDraught {

    return m_maxDraught;
}

-(bool) hasMaxDraught {

    return m_maxDraughtPresent;
}

-(void) setMaxPersonsOnBoard:(float) val {

    m_maxPersonsOnBoardPresent = true;
    m_maxPersonsOnBoard = val;
}

- (float) maxPersonsOnBoard {

    return m_maxPersonsOnBoard;
}

-(bool) hasMaxPersonsOnBoard {

    return m_maxPersonsOnBoardPresent;
}

-(void) setMaxSpeed:(float) val {

    m_maxSpeedPresent = true;
    m_maxSpeed = val;
}

- (float) maxSpeed {

    return m_maxSpeed;
}

-(bool) hasMaxSpeed {

    return m_maxSpeedPresent;
}

-(void) setWidth:(float) val {

    m_widthPresent = true;
    m_width = val;
}

- (float) width {

    return m_width;
}

-(bool) hasWidth {

    return m_widthPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"UnType"]) {
                ILUnType * val = [attributeDict objectForKey: key];
                [self setUnType: val];
            }
            else if ([key isEqualToString:@"HullColor"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setHullColor: val];
            }
            else if ([key isEqualToString:@"HullType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setHullType: val];
            }
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLength: val];
            }
            else if ([key isEqualToString:@"LloydsShipType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setLloydsShipType: val];
            }
            else if ([key isEqualToString:@"MaxKeelHeight"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setMaxKeelHeight: val];
            }
            else if ([key isEqualToString:@"MaxDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setMaxDraught: val];
            }
            else if ([key isEqualToString:@"MaxPersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setMaxPersonsOnBoard: val];
            }
            else if ([key isEqualToString:@"MaxSpeed"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setMaxSpeed: val];
            }
            else if ([key isEqualToString:@"Width"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setWidth: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Construction"];
    if ( [self hasHullColor] ) {
        [xml appendString: @" HullColor=\""];
        [xml appendString: [self encode: m_hullColor]];
        [xml appendString: @"\""];
    }
    if ( [self hasHullType] ) {
        [xml appendString: @" HullType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_hullType]];
        [xml appendString: @"\""];
    }
    if ( [self hasLength] ) {
        [xml appendString: @" Length=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_length]];
        [xml appendString: @"\""];
    }
    if ( [self hasLloydsShipType] ) {
        [xml appendString: @" LloydsShipType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_lloydsShipType]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxKeelHeight] ) {
        [xml appendString: @" MaxKeelHeight=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_maxKeelHeight]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxDraught] ) {
        [xml appendString: @" MaxDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_maxDraught]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxPersonsOnBoard] ) {
        [xml appendString: @" MaxPersonsOnBoard=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_maxPersonsOnBoard]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxSpeed] ) {
        [xml appendString: @" MaxSpeed=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_maxSpeed]];
        [xml appendString: @"\""];
    }
    if ( [self hasWidth] ) {
        [xml appendString: @" Width=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_width]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: [m_unType XML] ];
    [xml appendString: @"</Construction>\n"];
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
    [str setString: [lead stringByAppendingString:@"Construction\n"]];
    if ( [self hasHullColor] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"HullColor = \""];
        [str appendString: m_hullColor];
        [str appendString: @"\"\n"];

    }
    if ( [self hasHullType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"HullType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_hullType]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Length = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_length]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasLloydsShipType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"LloydsShipType = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_lloydsShipType]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasMaxKeelHeight] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxKeelHeight = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxKeelHeight]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasMaxDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxDraught = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxDraught]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasMaxPersonsOnBoard] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxPersonsOnBoard = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxPersonsOnBoard]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasMaxSpeed] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxSpeed = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxSpeed]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasWidth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Width = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_width]];
        [str appendString: @"\"\n"];

    }
    [str appendString: [m_unType stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasHullColor] ) {
        [attr setObject: m_hullColor forKey: @"HullColor"];
    }
    if ( [self hasHullType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_hullType] forKey: @"HullType"];
    }
    if ( [self hasLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_length] forKey: @"Length"];
    }
    if ( [self hasLloydsShipType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_lloydsShipType] forKey: @"LloydsShipType"];
    }
    if ( [self hasMaxKeelHeight] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_maxKeelHeight] forKey: @"MaxKeelHeight"];
    }
    if ( [self hasMaxDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_maxDraught] forKey: @"MaxDraught"];
    }
    if ( [self hasMaxPersonsOnBoard] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_maxPersonsOnBoard] forKey: @"MaxPersonsOnBoard"];
    }
    if ( [self hasMaxSpeed] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_maxSpeed] forKey: @"MaxSpeed"];
    }
    if ( [self hasWidth] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_width] forKey: @"Width"];
    }

    return attr;
}


@end


