
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

-(NSString *) encode: (NSString *) input {

    NSMutableString *str = [[[NSMutableString alloc] initWithString: input] autorelease];

    [str replaceOccurrencesOfString: @"&" withString: "&amp;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: "&lt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: "&gt;") options: nil searchRange: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: "&quot;") options: nil searchRange: NSMakeRange(0, [str length])];

    return str;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Schema\n"]];
    return str;
}


@end


