
#import "IVEFPos.h"


@implementation IVEFPos

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setLat:(float) val {

    if (val < -90)
        return;
    if (val > 90)
        return;
    m_lat = val;
}

- (float) getLat {

    return m_lat;
}

-(void) setLong:(float) val {

    if (val < -180)
        return;
    if (val > 180)
        return;
    m_long = val;
}

- (float) getLong {

    return m_long;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Lat"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLat: val];
            }
            else if ([key isEqualToString:@"Long"]) {
                NSString *value = [attributeDict objectForKey: key];
                float val = [value floatValue];
                [self setLong: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Pos"];
    [xml appendString: @" Lat=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_lat]];
    [xml appendString: @"\""];
    [xml appendString: @" Long=\""];
    [xml appendString: [NSString stringWithFormat:@"%f", m_long]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Pos>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Pos\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Lat=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_lat]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Long=\""];
    [str appendString: [NSString stringWithFormat:@"%f", m_long]];
    [str appendString: @"\"\n"];

    return str;
}


@end


