
#import "IVEFTransmission.h"


@implementation IVEFTransmission

- (id) init {
    self = [super init];
    if (self != nil) {
        m_periodPresent = false;
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) )
        return;
    m_type = val;
}

- (int) getType {

    return m_type;
}

-(void) setPeriod:(float) val {

    m_periodPresent = true;
    m_period = val;
}

- (float) getPeriod {

    return m_period;
}

-(bool) hasPeriod {

    return m_periodPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Type"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setType: val];
            }
            else if ([key isEqualToString:@"Period"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setPeriod: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Transmission"];
    [xml appendString: @" Type=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_type]];
    [xml appendString: @"\""];
    if ( [self hasPeriod] ) {
        [xml appendString: @" Period=\""];
        [xml appendString: [NSString stringWithFormat:@"%f", m_period]];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: @"</Transmission>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Transmission\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Type=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_type]];
    [str appendString: @"\"\n"];

    if ( [self hasPeriod] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Period = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_period]];
    }
    return str;
}


@end


