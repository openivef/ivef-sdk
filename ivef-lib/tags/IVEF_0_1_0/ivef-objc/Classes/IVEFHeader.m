
#import "IVEFHeader.h"


@implementation IVEFHeader

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setVersion:(NSString *) val {

    [m_version release];
    m_version = val;
    [m_version retain];
}

- (NSString *) getVersion {

    return m_version;
}

-(void) setMsgRefId:(NSString *) val {

    [m_msgRefId release];
    m_msgRefId = val;
    [m_msgRefId retain];
}

- (NSString *) getMsgRefId {

    return m_msgRefId;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Version"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setVersion: val];
            }
            else if ([key isEqualToString:@"MsgRefId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setMsgRefId: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Header"];
    [xml appendString: @" Version=\""];
    [xml appendString: m_version];
    [xml appendString: @"\""];
    [xml appendString: @" MsgRefId=\""];
    [xml appendString: m_msgRefId];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Header>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Header\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Version=\""];
    [str appendString: m_version];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"MsgRefId=\""];
    [str appendString: m_msgRefId];
    [str appendString: @"\"\n"];

    return str;
}


@end


