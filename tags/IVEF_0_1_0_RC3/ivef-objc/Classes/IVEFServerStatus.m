
#import "IVEFServerStatus.h"


@implementation IVEFServerStatus

- (id) init {
    self = [super init];
    if (self != nil) {
        m_detailsPresent = false;
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setStatus:(NSString *) val {

    if ( ( ![val isEqualToString: @"queuefull"] ) &&
         ( ![val isEqualToString: @"ok"] ) )
        return;
    [m_status release];
    m_status = val;
    [m_status retain];
}

- (NSString *) getStatus {

    return m_status;
}

-(void) setDetails:(NSString *) val {

    m_detailsPresent = true;
    [m_details release];
    m_details = val;
    [m_details retain];
}

- (NSString *) getDetails {

    return m_details;
}

-(bool) hasDetails {

    return m_detailsPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Status"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setStatus: val];
            }
            else if ([key isEqualToString:@"Details"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setDetails: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ServerStatus"];
    [xml appendString: @" Status=\""];
    [xml appendString: m_status];
    [xml appendString: @"\""];
    if ( [self hasDetails] ) {
        [xml appendString: @" Details=\""];
        [xml appendString: m_details];
        [xml appendString: @"\""];
    }
    [xml appendString:@">\n"];
    [xml appendString: @"</ServerStatus>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"ServerStatus\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Status=\""];
    [str appendString: m_status];
    [str appendString: @"\"\n"];

    if ( [self hasDetails] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Details = \""];
        [str appendString: m_details];
    }
    return str;
}


@end


