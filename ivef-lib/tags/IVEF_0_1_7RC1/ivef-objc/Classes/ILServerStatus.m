
#import "ILServerStatus.h"


@implementation ILServerStatus

- (id) init {
    self = [super init];
    if (self != nil) {
        m_statusPresent = NO;
        m_detailsPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_status release];
    [m_details release];
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

-(BOOL) setStatus:(NSString *) val {

    if ( ( ![val isEqualToString: @"queuefull"] ) &&
         ( ![val isEqualToString: @"ok"] ) )
        return NO;
    m_statusPresent = YES;
    [m_status release];
    m_status = val;
    [m_status retain];
    return YES;
}

- (NSString *) status {

    return m_status;
}

-(BOOL) setDetails:(NSString *) val {

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

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Status"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setStatus: val]) {
                   return NO;
                }
                if (![self setStatus: val]) {
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
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServerStatus"];
    NSString *dataMember;
    if ( m_statusPresent ) {
        [xml appendString: @" Status=\""];
        [xml appendString: [self encode: m_status]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Status" forKey: @"description"]];
        return nil;
    }
    if ( [self hasDetails] ) {
        [xml appendString: @" Details=\""];
        [xml appendString: [self encode: m_details]];
        [xml appendString: @"\""];
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
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Status = "];
    [str appendString: m_status];
    [str appendString: @"\n"];

    if ( [self hasDetails] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Details = "];
        [str appendString: m_details];
        [str appendString: @"\n"];

    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_status forKey: @"Status"];
    if ( [self hasDetails] ) {
        [attr setObject: m_details forKey: @"Details"];
    }

    return attr;
}


@end


