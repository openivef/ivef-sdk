
#import "IVEFLoginRequest.h"


@implementation IVEFLoginRequest

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setName:(NSString *) val {

    [m_name release];
    m_name = val;
    [m_name retain];
}

- (NSString *) getName {

    return m_name;
}

-(void) setPassword:(NSString *) val {

    [m_password release];
    m_password = val;
    [m_password retain];
}

- (NSString *) getPassword {

    return m_password;
}

-(void) setEncryption:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_encryption = val;
}

- (int) getEncryption {

    return m_encryption;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Name"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setName: val];
            }
            else if ([key isEqualToString:@"Password"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setPassword: val];
            }
            else if ([key isEqualToString:@"Encryption"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setEncryption: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<LoginRequest"];
    [xml appendString: @" Name=\""];
    [xml appendString: m_name];
    [xml appendString: @"\""];
    [xml appendString: @" Password=\""];
    [xml appendString: m_password];
    [xml appendString: @"\""];
    [xml appendString: @" Encryption=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_encryption]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</LoginRequest>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"LoginRequest\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Name=\""];
    [str appendString: m_name];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Password=\""];
    [str appendString: m_password];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Encryption=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_encryption]];
    [str appendString: @"\"\n"];

    return str;
}


@end


