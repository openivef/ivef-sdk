
#import "ILLoginRequest.h"


@implementation ILLoginRequest

- (id) init {
    self = [super init];
    if (self != nil) {
        m_encryptionPresent = NO;
        m_namePresent = NO;
        m_passwordPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_name release];
    [m_password release];
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

-(BOOL) setEncryption:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return NO;
    m_encryptionPresent = YES;
    m_encryption = val;
    return YES;
}

- (int) encryption {

    return m_encryption;
}

-(BOOL) setName:(NSString *) val {

    m_namePresent = YES;
    [m_name release];
    m_name = val;
    [m_name retain];
    return YES;
}

- (NSString *) name {

    return m_name;
}

-(BOOL) setPassword:(NSString *) val {

    m_passwordPresent = YES;
    [m_password release];
    m_password = val;
    [m_password retain];
    return YES;
}

- (NSString *) password {

    return m_password;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Encryption"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setEncryption: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Password"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setPassword: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<LoginRequest"];
    if ( m_encryptionPresent ) {
        [xml appendString: @" Encryption=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_encryption]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Encryption" forKey: @"description"]];
        return nil;
    }
    if ( m_namePresent ) {
        [xml appendString: @" Name=\""];
        [xml appendString: [self encode: m_name]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Name" forKey: @"description"]];
        return nil;
    }
    if ( m_passwordPresent ) {
        [xml appendString: @" Password=\""];
        [xml appendString: [self encode: m_password]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Password" forKey: @"description"]];
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
    [str setString: [lead stringByAppendingString:@"LoginRequest\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Encryption = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_encryption]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Name = "];
    [str appendString: m_name];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Password = "];
    [str appendString: m_password];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_encryption] forKey: @"Encryption"];
    [attr setObject: m_name forKey: @"Name"];
    [attr setObject: m_password forKey: @"Password"];

    return attr;
}


@end


