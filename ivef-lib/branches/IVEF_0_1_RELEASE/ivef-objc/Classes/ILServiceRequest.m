
#import "ILServiceRequest.h"


@implementation ILServiceRequest

- (id) init {
    self = [super init];
    if (self != nil) {
        m_areas = [[NSMutableArray alloc] init];
        m_items = [[NSMutableArray alloc] init];
        m_objects = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void) dealloc {

    [m_areas release];
    [m_transmission release];
    [m_items release];
    [m_objects release];
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

-(BOOL) addArea:(ILArea *) val {

    [m_areas addObject: val];
     return YES;
}

-(ILArea *) areaAt:(int) i {

    return [m_areas objectAtIndex: i];
}

-(int) countOfAreas {

    return [m_areas count];
}

-(NSArray *) areas {

    return m_areas;
}

-(BOOL) setTransmission:(ILTransmission *) val {

    [m_transmission release];
    m_transmission = val;
    [m_transmission retain];
    return YES;
}

- (ILTransmission *) transmission {

    return m_transmission;
}

-(BOOL) addItem:(ILItem *) val {

    [m_items addObject: val];
     return YES;
}

-(ILItem *) itemAt:(int) i {

    return [m_items objectAtIndex: i];
}

-(int) countOfItems {

    return [m_items count];
}

-(NSArray *) items {

    return m_items;
}

-(BOOL) addObject:(ILObject *) val {

    [m_objects addObject: val];
     return YES;
}

-(ILObject *) objectAt:(int) i {

    return [m_objects objectAtIndex: i];
}

-(int) countOfObjects {

    return [m_objects count];
}

-(NSArray *) objects {

    return m_objects;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Area"]) {
                ILArea * val = [attributeDict objectForKey: key];
                if (![self addArea: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Transmission"]) {
                ILTransmission * val = [attributeDict objectForKey: key];
                if (![self setTransmission: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Item"]) {
                ILItem * val = [attributeDict objectForKey: key];
                if (![self addItem: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Object"]) {
                ILObject * val = [attributeDict objectForKey: key];
                if (![self addObject: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServiceRequest"];
    [xml appendString:@">\n"];
    for(int i=0; i < [m_areas count]; i++ ) {
        ILArea *attribute = [m_areas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: [m_transmission XML] ];
    for(int i=0; i < [m_items count]; i++ ) {
        ILItem *attribute = [m_items objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_objects count]; i++ ) {
        ILObject *attribute = [m_objects objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</ServiceRequest>\n"];
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
    [str setString: [lead stringByAppendingString:@"ServiceRequest\n"]];
    for(int i=0; i < [m_areas count]; i++ ) {
        ILArea *attribute = [m_areas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    [str appendString: [m_transmission stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    for(int i=0; i < [m_items count]; i++ ) {
        ILItem *attribute = [m_items objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_objects count]; i++ ) {
        ILObject *attribute = [m_objects objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];

    return attr;
}


@end


