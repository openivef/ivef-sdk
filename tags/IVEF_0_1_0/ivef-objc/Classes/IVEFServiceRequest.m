
#import "IVEFServiceRequest.h"


@implementation IVEFServiceRequest

- (id) init {
    self = [super init];
    if (self != nil) {
        m_areas = [[NSMutableArray alloc] init];
        m_items = [[NSMutableArray alloc] init];
        m_objects = [[NSMutableArray alloc] init];
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) addArea:(IVEFArea *) val {

    [m_areas addObject: val];
}

-(IVEFArea *) getAreaAt:(int) i {

    return [m_areas objectAtIndex: i];
}

-(int) countOfAreas {

    return [m_areas count];
}

-(void) setTransmission:(IVEFTransmission *) val {

    [m_transmission release];
    m_transmission = val;
    [m_transmission retain];
}

- (IVEFTransmission *) getTransmission {

    return m_transmission;
}

-(void) addItem:(IVEFItem *) val {

    [m_items addObject: val];
}

-(IVEFItem *) getItemAt:(int) i {

    return [m_items objectAtIndex: i];
}

-(int) countOfItems {

    return [m_items count];
}

-(void) addObject:(IVEFObject *) val {

    [m_objects addObject: val];
}

-(IVEFObject *) getObjectAt:(int) i {

    return [m_objects objectAtIndex: i];
}

-(int) countOfObjects {

    return [m_objects count];
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Area"]) {
                IVEFArea * val = [attributeDict objectForKey: key];
                [self addArea: val];
            }
            else if ([key isEqualToString:@"Transmission"]) {
                IVEFTransmission * val = [attributeDict objectForKey: key];
                [self setTransmission: val];
            }
            else if ([key isEqualToString:@"Item"]) {
                IVEFItem * val = [attributeDict objectForKey: key];
                [self addItem: val];
            }
            else if ([key isEqualToString:@"Object"]) {
                IVEFObject * val = [attributeDict objectForKey: key];
                [self addObject: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServiceRequest"];
    [xml appendString:@">\n"];
    for(int i=0; i < [m_areas count]; i++ ) {
        IVEFArea *attribute = [m_areas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: [m_transmission XML] ];
    for(int i=0; i < [m_items count]; i++ ) {
        IVEFItem *attribute = [m_items objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_objects count]; i++ ) {
        IVEFObject *attribute = [m_objects objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</ServiceRequest>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"ServiceRequest\n"]];
    for(int i=0; i < [m_areas count]; i++ ) {
        IVEFArea *attribute = [m_areas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    [str appendString: [m_transmission stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    for(int i=0; i < [m_items count]; i++ ) {
        IVEFItem *attribute = [m_items objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_objects count]; i++ ) {
        IVEFObject *attribute = [m_objects objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}


@end


