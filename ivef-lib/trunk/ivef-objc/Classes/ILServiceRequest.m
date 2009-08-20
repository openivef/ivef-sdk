
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

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [NSString stringByReplacingOccurrencesOfString:@"Z" withString:@];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-ddThh:mm:ss.zzz"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-ddThh:mm:ss"];
     }
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-ddThh:mm"];
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

-(void) addArea:(ILArea *) val {

    [m_areas addObject: val];
}

-(ILArea *) getAreaAt:(int) i {

    return [m_areas objectAtIndex: i];
}

-(int) countOfAreas {

    return [m_areas count];
}

-(NSArray *) Areas {

    return m_areas;
}

-(void) setTransmission:(ILTransmission *) val {

    [m_transmission release];
    m_transmission = val;
    [m_transmission retain];
}

- (ILTransmission *) transmission {

    return m_transmission;
}

-(void) addItem:(ILItem *) val {

    [m_items addObject: val];
}

-(ILItem *) getItemAt:(int) i {

    return [m_items objectAtIndex: i];
}

-(int) countOfItems {

    return [m_items count];
}

-(NSArray *) Items {

    return m_items;
}

-(void) addObject:(ILObject *) val {

    [m_objects addObject: val];
}

-(ILObject *) getObjectAt:(int) i {

    return [m_objects objectAtIndex: i];
}

-(int) countOfObjects {

    return [m_objects count];
}

-(NSArray *) Objects {

    return m_objects;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Area"]) {
                ILArea * val = [attributeDict objectForKey: key];
                [self addArea: val];
            }
            else if ([key isEqualToString:@"Transmission"]) {
                ILTransmission * val = [attributeDict objectForKey: key];
                [self setTransmission: val];
            }
            else if ([key isEqualToString:@"Item"]) {
                ILItem * val = [attributeDict objectForKey: key];
                [self addItem: val];
            }
            else if ([key isEqualToString:@"Object"]) {
                ILObject * val = [attributeDict objectForKey: key];
                [self addObject: val];
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

    [str replaceOccurrencesOfString: @"&" withString: "&amp;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: "&lt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: "&gt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: "&quot;") options: nil searchRange: NSMakeRange(0, [str length])];

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


