
#import "TSTMessage.h"


@implementation TSTMessage

- (id) init {
    self = [super init];
    if (self != nil) {
        m_arguments = [[NSMutableArray alloc] init];
        m_argumentPresent = NO;
        m_timeStampPresent = NO;
        m_codePresent = NO;
        m_version = @"1.0.0";
        m_versionPresent = YES;
    }
    return self;
}

- (void) dealloc {

    [m_arguments release];
    [m_timeStamp release];
    [m_version release];
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

-(BOOL) removeArgument:(NSString *) val {
    if ([m_arguments count] <= 0) {
        return NO; // scalar already at minOccurs
    }

    [m_arguments removeObject: val];
    return YES;
}

-(BOOL) addArgument:(NSString *) val {
    if ([m_arguments count] >= 10) {
        return NO; // scalar already at maxOccurs
    }

    if ([val length] < 1)
        return NO;
    if ([val length] > 1024)
        return NO;
    [m_arguments addObject: val];
    return YES;
}

-(NSString *) argumentAt:(int) i {

    return [m_arguments objectAtIndex: i];
}

-(int) countOfArguments {

    return [m_arguments count];
}

-(NSArray *) arguments {

    return m_arguments;
}

-(BOOL) setTimeStamp:(NSDate *) val {

    m_timeStampPresent = YES;
    [m_timeStamp release];
    m_timeStamp = val;
    [m_timeStamp retain];
    return YES;
}

- (NSDate *) timeStamp {

    return m_timeStamp;
}

-(BOOL) setCode:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_codePresent = YES;
    m_code = val;
    return YES;
}

- (int) code {

    return m_code;
}

- (NSString *) version {

    return m_version;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"TimeStamp"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setTimeStamp: val]) {
                   return NO;
                }
                if (![self setTimeStamp: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Code"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setCode: val]) {
                   return NO;
                }
                if (![self setCode: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Version"]) {
                NSString *val = [attributeDict objectForKey: key];
                [m_version release]; 
                m_version = val; // replace the default versioning number
                m_versionPresent = YES;
                [m_version retain]; 
                [m_version release]; 
                m_version = val; // replace the default versioning number
                m_versionPresent = YES;
                [m_version retain]; 
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Message"];
    NSString *dataMember;
    if ( m_timeStampPresent ) {
        [xml appendString: @" TimeStamp=\""];
        [xml appendString: [self stringFromDate: m_timeStamp]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"TimeStamp" forKey: @"description"]];
        return nil;
    }
    if ( m_codePresent ) {
        [xml appendString: @" Code=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_code]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Code" forKey: @"description"]];
        return nil;
    }
    if ( m_versionPresent ) {
        [xml appendString: @" Version=\""];
        [xml appendString: [self encode: m_version]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Version" forKey: @"description"]];
        return nil;
    }
    [xml appendString:@">\n"];
    if ([m_arguments count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of Argument" forKey: @"description"]];
        return nil;
    }
    if ([m_arguments count] > 10) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Too much entries of Argument" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_arguments count]; i++ ) {
        TSTXs:string *attribute = [m_arguments objectAtIndex:i];
        dataMember = [attribute XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Argument" forKey: @"description"]];
            return nil;
        }
    }
    [xml appendString: @"</Message>\n"];
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
    [str setString: [lead stringByAppendingString:@"Message\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TimeStamp = "];
    [str appendString: [self stringFromDate: m_timeStamp]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Code = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_code]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Version = "];
    [str appendString: m_version];
    [str appendString: @"\n"];

    for(int i=0; i < [m_arguments count]; i++ ) {
        TSTXs:string *attribute = [m_arguments objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [self stringFromDate: m_timeStamp] forKey: @"TimeStamp"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_code] forKey: @"Code"];
    [attr setObject: m_version forKey: @"Version"];

    return attr;
}


@end


