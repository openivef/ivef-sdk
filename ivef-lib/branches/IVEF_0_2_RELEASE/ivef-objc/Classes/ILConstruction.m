
#import "ILConstruction.h"


@implementation ILConstruction

- (id) init {
    self = [super init];
    if (self != nil) {
        m_unTypePresent = NO;
        m_hullColorPresent = NO;
        m_hullTypePresent = NO;
        m_deadWeightPresent = NO;
        m_grossWeightPresent = NO;
        m_lengthPresent = NO;
        m_lloydsShipTypePresent = NO;
        m_yearOfBuildPresent = NO;
        m_maxAirDraughtPresent = NO;
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

-(BOOL) setDeadWeight:(float) val {

    if (val < 0)
        return NO;
    m_deadWeightPresent = YES;
    m_deadWeight = val;
    return YES;
}

- (float) deadWeight {

    return m_deadWeight;
}

-(BOOL) hasDeadWeight {

    return m_deadWeightPresent;
}

-(BOOL) setGrossWeight:(float) val {

    if (val < 0)
        return NO;
    m_grossWeightPresent = YES;
    m_grossWeight = val;
    return YES;
}

- (float) grossWeight {

    return m_grossWeight;
}

-(BOOL) hasGrossWeight {

    return m_grossWeightPresent;
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

-(BOOL) setYearOfBuild:(int) val {

    m_yearOfBuildPresent = YES;
    m_yearOfBuild = val;
    return YES;
}

- (int) yearOfBuild {

    return m_yearOfBuild;
}

-(BOOL) hasYearOfBuild {

    return m_yearOfBuildPresent;
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
            if ([key isEqualToString: @"HullColor"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setHullColor: val]) {
                   return NO;
                }
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
                if (![self setHullType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"DeadWeight"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setDeadWeight: val]) {
                   return NO;
                }
                if (![self setDeadWeight: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"GrossWeight"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setGrossWeight: val]) {
                   return NO;
                }
                if (![self setGrossWeight: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Length"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setLength: val]) {
                   return NO;
                }
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
                if (![self setLloydsShipType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"YearOfBuild"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setYearOfBuild: val]) {
                   return NO;
                }
                if (![self setYearOfBuild: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"MaxAirDraught"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                if (![self setMaxAirDraught: val]) {
                   return NO;
                }
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
                if (![self setWidth: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Construction"];
    NSString *dataMember;
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
    if ( [self hasDeadWeight] ) {
        [xml appendString: @" DeadWeight=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_deadWeight]];
        [xml appendString: @"\""];
    }
    if ( [self hasGrossWeight] ) {
        [xml appendString: @" GrossWeight=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_grossWeight]];
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
    if ( [self hasYearOfBuild] ) {
        [xml appendString: @" YearOfBuild=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_yearOfBuild]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxAirDraught] ) {
        [xml appendString: @" MaxAirDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%.1f", m_maxAirDraught]];
        [xml appendString: @"\""];
    }
    if ( [self hasMaxDraught] ) {
        [xml appendString: @" MaxDraught=\""];
        [xml appendString: [NSString stringWithFormat:@"%.1f", m_maxDraught]];
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
        dataMember = [m_unType XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"UnType" forKey: @"description"]];
            return nil;
        }
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
    if ( [self hasDeadWeight] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"DeadWeight = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_deadWeight]];
        [str appendString: @"\n"];

    }
    if ( [self hasGrossWeight] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"GrossWeight = "];
        [str appendString: [NSString stringWithFormat:@"%f", m_grossWeight]];
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
    if ( [self hasYearOfBuild] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"YearOfBuild = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_yearOfBuild]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxAirDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxAirDraught = "];
        [str appendString: [NSString stringWithFormat:@"%.1f", m_maxAirDraught]];
        [str appendString: @"\n"];

    }
    if ( [self hasMaxDraught] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"MaxDraught = "];
        [str appendString: [NSString stringWithFormat:@"%.1f", m_maxDraught]];
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
    if ( [self hasDeadWeight] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_deadWeight] forKey: @"DeadWeight"];
    }
    if ( [self hasGrossWeight] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_grossWeight] forKey: @"GrossWeight"];
    }
    if ( [self hasLength] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_length] forKey: @"Length"];
    }
    if ( [self hasLloydsShipType] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_lloydsShipType] forKey: @"LloydsShipType"];
    }
    if ( [self hasYearOfBuild] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_yearOfBuild] forKey: @"YearOfBuild"];
    }
    if ( [self hasMaxAirDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%.1f", m_maxAirDraught] forKey: @"MaxAirDraught"];
    }
    if ( [self hasMaxDraught] ) {
        [attr setObject: [NSString stringWithFormat:@"%.1f", m_maxDraught] forKey: @"MaxDraught"];
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


