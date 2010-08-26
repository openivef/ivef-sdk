
#import "ILServiceRequestResponse.h"


@implementation ILServiceRequestResponse

- (id) init {
    self = [super init];
    if (self != nil) {
        m_reasonPresent = NO;
        m_responseOnPresent = NO;
        m_resultPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_reason release];
    [m_responseOn release];
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

-(BOOL) setReason:(NSString *) val {

    if ([val length] > 256)
        return NO;
    m_reasonPresent = YES;
    [m_reason release];
    m_reason = val;
    [m_reason retain];
    return YES;
}

- (NSString *) reason {

    return m_reason;
}

-(BOOL) hasReason {

    return m_reasonPresent;
}

-(BOOL) setResponseOn:(NSString *) val {

    if ([val length] < 36)
        return NO;
    if ([val length] > 42)
        return NO;
    m_responseOnPresent = YES;
    [m_responseOn release];
    m_responseOn = val;
    [m_responseOn retain];
    return YES;
}

- (NSString *) responseOn {

    return m_responseOn;
}

-(BOOL) setResult:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_resultPresent = YES;
    m_result = val;
    return YES;
}

- (int) result {

    return m_result;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Reason"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setReason: val]) {
                   return NO;
                }
                if (![self setReason: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ResponseOn"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setResponseOn: val]) {
                   return NO;
                }
                if (![self setResponseOn: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Result"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setResult: val]) {
                   return NO;
                }
                if (![self setResult: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServiceRequestResponse"];
    if ( [self hasReason] ) {
        [xml appendString: @" Reason=\""];
        [xml appendString: [self encode: m_reason]];
        [xml appendString: @"\""];
    }
    if ( m_responseOnPresent ) {
        [xml appendString: @" ResponseOn=\""];
        [xml appendString: [self encode: m_responseOn]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"ResponseOn" forKey: @"description"]];
        return nil;
    }
    if ( m_resultPresent ) {
        [xml appendString: @" Result=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_result]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Result" forKey: @"description"]];
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
    [str setString: [lead stringByAppendingString:@"ServiceRequestResponse\n"]];
    if ( [self hasReason] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Reason = "];
        [str appendString: m_reason];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"ResponseOn = "];
    [str appendString: m_responseOn];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Result = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_result]];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasReason] ) {
        [attr setObject: m_reason forKey: @"Reason"];
    }
    [attr setObject: m_responseOn forKey: @"ResponseOn"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_result] forKey: @"Result"];

    return attr;
}


@end


