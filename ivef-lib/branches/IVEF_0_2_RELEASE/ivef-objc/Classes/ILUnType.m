
#import "ILUnType.h"


@implementation ILUnType

- (id) init {
    self = [super init];
    if (self != nil) {
    }
    return self;
}

- (void) dealloc {

    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
     }
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss"];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-dd'T'HH:mm"];
     }
     NSDate *val = [formatterWithMillies dateFromString:str];
     if (val) {
         return val;
     }
     val = [formatterWithSeconds dateFromString:str];
     if (val) {
         return val;
     }
     val = [formatterWithMinutes dateFromString:str];
     if (val) {
         return val;
     }
     return nil; // invalid date
}

-(void) setCodeA:(int) val {

    if (val < 0)
        return;
    if (val > 138)
        return;
    m_codeA = val;
}

- (int) codeA {

    return m_codeA;
}

-(void) setCodeB:(int) val {

    if (val < 0)
        return;
    if (val > 9)
        return;
    m_codeB = val;
}

- (int) codeB {

    return m_codeB;
}

-(void) setMode:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return;
    m_mode = val;
}

- (int) mode {

    return m_mode;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"CodeA"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setCodeA: val];
            }
            else if ([key isEqualToString:@"CodeB"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setCodeB: val];
            }
            else if ([key isEqualToString:@"Mode"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setMode: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<UnType"];
    [xml appendString: @" CodeA=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_codeA]];
    [xml appendString: @"\""];
    [xml appendString: @" CodeB=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_codeB]];
    [xml appendString: @"\""];
    [xml appendString: @" Mode=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_mode]];
    [xml appendString: @"\""];
    [xml appendString:@"/>\n"];
    return xml;
}

-(NSString *) encode: (NSString *) input {

    NSMutableString *str = [[[NSMutableString alloc] initWithString: input] autorelease];

    [str replaceOccurrencesOfString: @"&" withString: @"&amp;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: @"&lt;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: @"&gt;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: @"&quot;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];

    return str;
}

-(NSString *) stringValue {

    return [self stringValueWithLead:@""];
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"UnType\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"CodeA = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_codeA]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"CodeB = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_codeB]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Mode = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_mode]];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_codeA] forKey: @"CodeA"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_codeB] forKey: @"CodeB"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_mode] forKey: @"Mode"];

    return attr;
}


@end


