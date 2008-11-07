
#import "IVEFSchema.h"


@implementation IVEFSchema

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

-(NSString *) getElementFormDefault {

    return @"qualified";
}

-(NSString *) getTargetNamespace {

    return @"urn:http://www.hitt.nl/XMLSchema/ISIS/1.1";
}

-(void) setAttributes:(NSDictionary *)attributeDict {

}

-(NSString *) XML {

    NSMutableString *xml = [NSString stringWithString:@"<Schema"];
    [xml appendString:@">\n"];
    [xml appendString: @"</Schema>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Schema\n"]];
    return str;
}


@end


