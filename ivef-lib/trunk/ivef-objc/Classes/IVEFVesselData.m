
#import "IVEFVesselData.h"


@implementation IVEFVesselData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_staticDatas = [[NSMutableArray alloc] init];
        m_voyages = [[NSMutableArray alloc] init];
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) setPosReport:(IVEFPosReport *) val {

    [m_posReport release];
    m_posReport = val;
    [m_posReport retain];
}

- (IVEFPosReport *) getPosReport {

    return m_posReport;
}

-(void) addStaticData:(IVEFStaticData *) val {

    [m_staticDatas addObject: val];
}

-(IVEFStaticData *) getStaticDataAt:(int) i {

    return [m_staticDatas objectAtIndex: i];
}

-(int) countOfStaticDatas {

    return [m_staticDatas count];
}

-(void) addVoyage:(IVEFVoyage *) val {

    [m_voyages addObject: val];
}

-(IVEFVoyage *) getVoyageAt:(int) i {

    return [m_voyages objectAtIndex: i];
}

-(int) countOfVoyages {

    return [m_voyages count];
}

-(void) setId:(int) val {

    m_id = val;
}

- (int) getId {

    return m_id;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"PosReport"]) {
                IVEFPosReport * val = [attributeDict objectForKey: key];
                [self setPosReport: val];
            }
            else if ([key isEqualToString:@"StaticData"]) {
                IVEFStaticData * val = [attributeDict objectForKey: key];
                [self addStaticData: val];
            }
            else if ([key isEqualToString:@"Voyage"]) {
                IVEFVoyage * val = [attributeDict objectForKey: key];
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
        IVEFStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        IVEFVoyage *attribute = [m_voyages objectAtIndex:i];
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

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"VesselData\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\"\n"];

    [str appendString: [m_posReport stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    for(int i=0; i < [m_staticDatas count]; i++ ) {
        IVEFStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        IVEFVoyage *attribute = [m_voyages objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}


@end


