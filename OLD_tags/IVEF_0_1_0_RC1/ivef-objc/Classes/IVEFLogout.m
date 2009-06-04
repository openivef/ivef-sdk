
#import "IVEFLogout.h"


@implementation IVEFLogout

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

}

-(NSString *) XML {

    NSMutableString *xml = [NSString stringWithString:@"<Logout"];
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


