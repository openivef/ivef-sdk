
#import "ILVesselData.h"


@implementation ILVesselData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_staticDatas = [[NSMutableArray alloc] init];
        m_voyages = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void) dealloc {

    [m_posReport release];
    [m_staticDatas release];
    [m_voyages release];
    [super dealloc];
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [NSString stringByReplacingOccurrencesOfString:@"Z" withString:@];

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] init];
         [formatterWithMillies setDateFormat:@"yyyy-MM-ddThh:mm:ss.zzz"];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] init];
         [formatterWithSeconds setDateFormat:@"yyyy-MM-ddThh:mm:ss"];
     }
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] init];
         [formatterWithMinutes setDateFormat:@"yyyy-MM-ddThh:mm"];
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

-(void) setPosReport:(ILPosReport *) val {

    [m_posReport release];
    m_posReport = val;
    [m_posReport retain];
}

- (ILPosReport *) posReport {

    return m_posReport;
}

-(void) addStaticData:(ILStaticData *) val {

    [m_staticDatas addObject: val];
}

-(ILStaticData *) getStaticDataAt:(int) i {

    return [m_staticDatas objectAtIndex: i];
}

-(int) countOfStaticDatas {

    return [m_staticDatas count];
}

-(NSArray *) StaticDatas {

    return m_staticDatas;
}

-(void) addVoyage:(ILVoyage *) val {

    [m_voyages addObject: val];
}

-(ILVoyage *) getVoyageAt:(int) i {

    return [m_voyages objectAtIndex: i];
}

-(int) countOfVoyages {

    return [m_voyages count];
}

-(NSArray *) Voyages {

    return m_voyages;
}

-(void) setIdent:(int) val {

    m_id = val;
}

- (int) ident {

    return m_id;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"PosReport"]) {
                ILPosReport * val = [attributeDict objectForKey: key];
                [self setPosReport: val];
            }
            else if ([key isEqualToString:@"StaticData"]) {
                ILStaticData * val = [attributeDict objectForKey: key];
                [self addStaticData: val];
            }
            else if ([key isEqualToString:@"Voyage"]) {
                ILVoyage * val = [attributeDict objectForKey: key];
                [self addVoyage: val];
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setId: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<VesselData"];
    [xml appendString: @" Id=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: [m_posReport XML] ];
    for(int i=0; i < [m_staticDatas count]; i++ ) {
        ILStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        ILVoyage *attribute = [m_voyages objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</VesselData>\n"];
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

-(NSString *) stringValue {

    return [self stringValueWithLead:@""];
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"VesselData\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\"\n"];

    [str appendString: [m_posReport stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    for(int i=0; i < [m_staticDatas count]; i++ ) {
        ILStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        ILVoyage *attribute = [m_voyages objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: [NSString stringWithFormat:@"%d", m_id] forKey: @"Id"];

    return attr;
}


@end


