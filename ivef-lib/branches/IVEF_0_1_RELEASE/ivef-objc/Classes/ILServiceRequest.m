
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
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
     }
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss"];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-dd'T'HH:mm"];
     }
     NSDate *val = [formatterWithMillies dateFromString:str];
     if (val) {
         return val;
     }
     val = [formatterWithSeconds dateFromString:str];
     if (val) {
         return val;
     }
     val = [formatterWithMinutes dateFromString:str];
     if (val) {
         return val;
     }
     return nil; // invalid date
}

-(bool) addArea:(ILArea *) val {

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

-(bool) setTransmission:(ILTransmission *) val {

    [m_transmission release];
    m_transmission = val;
    [m_transmission retain];
      return YES;
}

- (ILTransmission *) transmission {

    return m_transmission;
}

-(bool) addItem:(ILItem *) val {

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

-(bool) addObject:(ILObject *) val {

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

-(bool) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Area"]) {
                ILArea * val = [attributeDict objectForKey: key];
                if (![self addArea: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Transmission"]) {
                ILTransmission * val = [attributeDict objectForKey: key];
                if (![self setTransmission: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Item"]) {
                ILItem * val = [attributeDict objectForKey: key];
                if (![self addItem: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Object"]) {
                ILObject * val = [attributeDict objectForKey: key];
                if (![self addObject: val]) {
                   return false;
                }
            }
        }
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


