
#import "IVEFItem.h"


@implementation IVEFItem

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setElement:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_element = val;
}

- (int) getElement {

    return m_element;
}

-(void) setField:(NSString *) val {

    [m_field release];
    m_field = val;
    [m_field retain];
}

- (NSString *) getField {

    return m_field;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Element"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setElement: val];
            }
            else if ([key isEqualToString:@"Field"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setField: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Item"];
    [xml appendString: @" Element=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_element]];
    [xml appendString: @"\""];
    [xml appendString: @" Field=\""];
    [xml appendString: m_field];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Item>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Item\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Element=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_element]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Field=\""];
    [str appendString: m_field];
    [str appendString: @"\"\n"];

    return str;
}


@end


