
#import "ILUnType.h"


@implementation ILUnType

- (id) init {
    self = [super init];
    if (self != nil) {
        m_codeAPresent = NO;
        m_codeBPresent = NO;
        m_modePresent = NO;
    }
    return self;
}

- (void) dealloc {

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

-(BOOL) setCodeA:(int) val {

    if (val < 0)
        return NO;
    if (val > 138)
        return NO;
    m_codeAPresent = YES;
    m_codeA = val;
    return YES;
}

- (int) codeA {

    return m_codeA;
}

-(BOOL) setCodeB:(int) val {

    if (val < 0)
        return NO;
    if (val > 9)
        return NO;
    m_codeBPresent = YES;
    m_codeB = val;
    return YES;
}

- (int) codeB {

    return m_codeB;
}

-(BOOL) setMode:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return NO;
    m_modePresent = YES;
    m_mode = val;
    return YES;
}

- (int) mode {

    return m_mode;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"CodeA"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setCodeA: val]) {
                   return NO;
                }
                if (![self setCodeA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"CodeB"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setCodeB: val]) {
                   return NO;
                }
                if (![self setCodeB: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Mode"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setMode: val]) {
                   return NO;
                }
                if (![self setMode: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<UnType"];
    if ( m_codeAPresent ) {
        [xml appendString: @" CodeA=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_codeA]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"CodeA" forKey: @"description"]];
        return nil;
    }
    if ( m_codeBPresent ) {
        [xml appendString: @" CodeB=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_codeB]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"CodeB" forKey: @"description"]];
        return nil;
    }
    if ( m_modePresent ) {
        [xml appendString: @" Mode=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_mode]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Mode" forKey: @"description"]];
        return nil;
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
    [str setString: [lead stringByAppendingString:@"UnType\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"CodeA = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_codeA]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"CodeB = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_codeB]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Mode = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_mode]];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_codeA] forKey: @"CodeA"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_codeB] forKey: @"CodeB"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_mode] forKey: @"Mode"];

    return attr;
}


@end


