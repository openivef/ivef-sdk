
#import "ILArea.h"


@implementation ILArea

- (id) init {
    self = [super init];
    if (self != nil) {
        m_poss = [[NSMutableArray alloc] init];
        m_posPresent = NO;
        m_namePresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_poss release];
    [m_name release];
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

-(BOOL) removePos:(ILPos *) val {

    [m_poss removeObject: val];
     return YES;
}

-(BOOL) addPos:(ILPos *) val {

    [m_poss addObject: val];
     return YES;
}

-(ILPos *) posAt:(int) i {

    return [m_poss objectAtIndex: i];
}

-(int) countOfPoss {

    return [m_poss count];
}

-(NSArray *) poss {

    return m_poss;
}

-(BOOL) setName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_namePresent = YES;
    [m_name release];
    m_name = val;
    [m_name retain];
    return YES;
}

- (NSString *) name {

    return m_name;
}

-(BOOL) hasName {

    return m_namePresent;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setName: val]) {
                   return NO;
                }
                if (![self setName: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Area"];
    NSString *dataMember;
    if ( [self hasName] ) {
        [xml appendString: @" Name=\""];
        [xml appendString: [self encode: m_name]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    if ([m_poss count] < 3) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of Pos" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_poss count]; i++ ) {
        ILPos *attribute = [m_poss objectAtIndex:i];
        dataMember = [attribute XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Pos" forKey: @"description"]];
            return nil;
        }
    }
    [xml appendString: @"</Area>\n"];
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
    [str setString: [lead stringByAppendingString:@"Area\n"]];
    if ( [self hasName] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Name = "];
        [str appendString: m_name];
        [str appendString: @"\n"];

    }
    for(int i=0; i < [m_poss count]; i++ ) {
        ILPos *attribute = [m_poss objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasName] ) {
        [attr setObject: m_name forKey: @"Name"];
    }

    return attr;
}


@end


