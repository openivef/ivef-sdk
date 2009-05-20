
#import "IVEFObject.h"


@implementation IVEFObject

- (id) init {
    self = [super init];
    if (self != nil) {
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setFileName:(NSString *) val {

    [m_fileName release];
    m_fileName = val;
    [m_fileName retain];
}

- (NSString *) getFileName {

    return m_fileName;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"FileName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setFileName: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Object"];
    [xml appendString: @" FileName=\""];
    [xml appendString: [m_fileName encode]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: @"</Object>\n"];
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
    [str setString: [lead stringByAppendingString:@"Object\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"FileName=\""];
    [str appendString: m_fileName];
    [str appendString: @"\"\n"];

    return str;
}


@end


