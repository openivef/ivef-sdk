
#import "IVEFSchema.h"


@implementation IVEFSchema

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(NSString *) getElementFormDefault {

    return @"qualified";
}

-(NSString *) getTargetNamespace {

    return @"urn:http://www.ivef.org/XMLSchema/IVEF/1.1";
}

-(void) setAttributes:(NSDictionary *)attributeDict {

}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Schema"];
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


