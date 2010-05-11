
#import "ILItem.h"


@implementation ILItem

- (id) init {
    self = [super init];
    if (self != nil) {
        m_elementPresent = NO;
        m_fieldPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_field release];
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

-(BOOL) setElement:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_elementPresent = YES;
    m_element = val;
    return YES;
}

- (int) element {

    return m_element;
}

-(BOOL) setField:(NSString *) val {

    m_fieldPresent = YES;
    [m_field release];
    m_field = val;
    [m_field retain];
    return YES;
}

- (NSString *) field {

    return m_field;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Element"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setElement: val]) {
                   return NO;
                }
                if (![self setElement: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Field"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setField: val]) {
                   return NO;
                }
                if (![self setField: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Item"];
    NSString *dataMember;
    if ( m_elementPresent ) {
        [xml appendString: @" Element=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_element]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Element" forKey: @"description"]];
        return nil;
    }
    if ( m_fieldPresent ) {
        [xml appendString: @" Field=\""];
        [xml appendString: [self encode: m_field]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Field" forKey: @"description"]];
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
    [str setString: [lead stringByAppendingString:@"Item\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Element = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_element]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Field = "];
    [str appendString: m_field];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_element] forKey: @"Element"];
    [attr setObject: m_field forKey: @"Field"];

    return attr;
}


@end


