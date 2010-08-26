
#import "ILServerStatus.h"


@implementation ILServerStatus

- (id) init {
    self = [super init];
    if (self != nil) {
        m_contactIdentityPresent = NO;
        m_detailsPresent = NO;
        m_statusPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_contactIdentity release];
    [m_details release];
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

-(BOOL) setDetails:(NSString *) val {

    if ([val length] > 50)
        return NO;
    m_detailsPresent = YES;
    [m_details release];
    m_details = val;
    [m_details retain];
    return YES;
}

- (NSString *) details {

    return m_details;
}

-(BOOL) hasDetails {

    return m_detailsPresent;
}

-(BOOL) setStatus:(BOOL) val {

    m_statusPresent = YES;
    m_status = val;
    return YES;
}

- (BOOL) status {

    return m_status;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"ContactIdentity"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setContactIdentity: val]) {
                   return NO;
                }
                if (![self setContactIdentity: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Details"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setDetails: val]) {
                   return NO;
                }
                if (![self setDetails: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Status"]) {
                NSString *value = [attributeDict objectForKey: key];
                BOOL val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                if (![self setStatus: val]) {
                   return NO;
                }
                if (![self setStatus: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServerStatus"];
    if ( [self hasContactIdentity] ) {
        [xml appendString: @" ContactIdentity=\""];
        [xml appendString: [self encode: m_contactIdentity]];
        [xml appendString: @"\""];
    }
    if ( [self hasDetails] ) {
        [xml appendString: @" Details=\""];
        [xml appendString: [self encode: m_details]];
        [xml appendString: @"\""];
    }
    if ( m_statusPresent ) {
        [xml appendString: @" Status=\""];
        [xml appendString: (m_status?@"true":@"false")];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Status" forKey: @"description"]];
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
    [str setString: [lead stringByAppendingString:@"ServerStatus\n"]];
    if ( [self hasContactIdentity] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"ContactIdentity = "];
        [str appendString: m_contactIdentity];
        [str appendString: @"\n"];

    }
    if ( [self hasDetails] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Details = "];
        [str appendString: m_details];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Status = "];
    [str appendString: (m_status?@"true":@"false")];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasContactIdentity] ) {
        [attr setObject: m_contactIdentity forKey: @"ContactIdentity"];
    }
    if ( [self hasDetails] ) {
        [attr setObject: m_details forKey: @"Details"];
    }
    [attr setObject: [NSString stringWithFormat:@"%f", m_status] forKey: @"Status"];

    return attr;
}


@end


