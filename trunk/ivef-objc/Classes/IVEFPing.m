
#import "IVEFPing.h"


@implementation IVEFPing

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

-(void) setTimeStamp:(NSDate *) val {

    [m_timeStamp release];
    m_timeStamp = val;
    [m_timeStamp retain];
}

- (NSDate *) getTimeStamp {

    return m_timeStamp;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"TimeStamp"]) {
                 NSString *value = [attributeDict objectForKey: key];

                NSDate * val = [NSDate dateWithString: value]; // assume "yyyy-MM-ddThh:mm:ss.zzz"
                [self setTimeStamp: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSString stringWithString:@"<Ping"];
    [xml appendString: @" TimeStamp=\""];
    [xml appendString: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Ping>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Ping\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"TimeStamp=\""];
    [str appendString: [m_timeStamp descriptionWithCalendarFormat:@"%Y-%m-%dT%H:%M:%S.%F" timeZone:nil locale:[[NSUserDefaults standardUserDefaults] dictionaryRepresentation]]];
    [str appendString: @"\"\n"];

    return str;
}


@end


