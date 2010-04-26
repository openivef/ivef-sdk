
#import "ILConstruction.h"


@implementation ILConstruction

- (id) init {
    self = [super init];
    if (self != nil) {
        m_unTypePresent = NO;
        m_hullColorPresent = NO;
        m_hullTypePresent = NO;
        m_lengthPresent = NO;
        m_lloydsShipTypePresent = NO;
        m_maxKeelHeightPresent = NO;
        m_maxDraughtPresent = NO;
        m_maxPersonsOnBoardPresent = NO;
        m_maxSpeedPresent = NO;
        m_widthPresent = NO;
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

-(BOOL) setUnType:(ILUnType *) val {

    m_unTypePresent = YES;
    [m_unType release];
    m_unType = val;
    [m_unType retain];
    return YES;
}

- (ILUnType *) unType {

    return m_unType;
}

-(BOOL) hasUnType {

    return m_unTypePresent;
}

-(BOOL) setHullColor:(NSString *) val {

    m_hullColorPresent = YES;
    [m_hullColor release];
    m_hullColor = val;
    [m_hullColor retain];
    return YES;
}

- (NSString *) hullColor {

    return m_hullColor;
}

-(BOOL) hasHullColor {

    return m_hullColorPresent;
}

-(BOOL) setHullType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_hullTypePresent = YES;
    m_hullType = val;
    return YES;
}

- (int) hullType {

    return m_hullType;
}

-(BOOL) hasHullType {

    return m_hullTypePresent;
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

-(BOOL) setLloydsShipType:(int) val {

    m_lloydsShipTypePresent = YES;
    m_lloydsShipType = val;
    return YES;
}

- (int) lloydsShipType {

    return m_lloydsShipType;
}

-(BOOL) hasLloydsShipType {

    return m_lloydsShipTypePresent;
}

-(BOOL) setMaxKeelHeight:(float) val {

    if (val < 0)
        return NO;
    m_maxKeelHeightPresent = YES;
    m_maxKeelHeight = val;
    return YES;
}

- (float) maxKeelHeight {

    return m_maxKeelHeight;
}

-(BOOL) hasMaxKeelHeight {

    return m_maxKeelHeightPresent;
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

-(BOOL) setMaxPersonsOnBoard:(int) val {

    if (val < 0)
        return NO;
    m_maxPersonsOnBoardPresent = YES;
    m_maxPersonsOnBoard = val;
    return YES;
}

- (int) maxPersonsOnBoard {

    return m_maxPersonsOnBoard;
}

-(BOOL) hasMaxPersonsOnBoard {

    return m_maxPersonsOnBoardPresent;
}

-(BOOL) setMaxSpeed:(float) val {

    if (val < 0)
        return NO;
    m_maxSpeedPresent = YES;
    m_maxSpeed = val;
    return YES;
}

- (float) maxSpeed {

    return m_maxSpeed;
}

-(BOOL) hasMaxSpeed {

    return m_maxSpeedPresent;
}

-(BOOL) setWidth:(float) val {

    if (val < 0)
        return NO;
    m_widthPresent = YES;
    m_width = val;
    return YES;
}

- (float) width {

    return m_width;
}

-(BOOL) hasWidth {

    return m_widthPresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"UnType"]) {
                ILUnType * val = [attributeDict objectForKey: key];
                if (![self setUnType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"HullColor"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setHullColor: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"HullType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setHullType: val]) {
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
            else if ([key isEqualToString:@"LloydsShipType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setLloydsShipType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MaxKeelHeight"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxKeelHeight: val]) {
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
            else if ([key isEqualToString:@"MaxPersonsOnBoard"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setMaxPersonsOnBoard: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MaxSpeed"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxSpeed: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Width"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setWidth: val]) {
                   return NO;
                }
            }
        }
        return YES;
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
        [xml appendString: [NSString stringWithFormat:@"%d", m_maxPersonsOnBoard]];
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
    if ( [self hasUnType] ) {
        [xml appendString: [m_unType XML] ];
    }
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
        [str appendString: @"HullColor = "];
        [str appendString: m_hullColor];
        [str appendString: @"\n"];

    }
    if ( [self hasHullType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"HullType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_hullType]];
        [str appendString: @"\n"];

    }
    if ( [self hasLength] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Length = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_length]];
        [str appendString: @"\n"];

    }
    if ( [self hasLloydsShipType] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"LloydsShipType = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_lloydsShipType]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxKeelHeight] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxKeelHeight = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxKeelHeight]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxDraught = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxDraught]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxPersonsOnBoard] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxPersonsOnBoard = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_maxPersonsOnBoard]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxSpeed] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxSpeed = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_maxSpeed]];
        [str appendString: @"\n"];

    }
    if ( [self hasWidth] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Width = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_width]];
        [str appendString: @"\n"];

    }
    if ( [self hasUnType] ) {
        [str appendString: [m_unType stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
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
        [attr setObject: [NSString stringWithFormat:@"%d", m_maxPersonsOnBoard] forKey: @"MaxPersonsOnBoard"];
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


