
#import "IVEFLogout.h"


@implementation IVEFLogout

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Logout"];
    [xml appendString:@">\n"];
    [xml appendString: @"</Logout>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Logout\n"]];
    return str;
}


@end


