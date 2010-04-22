
#import "ILVesselData.h"


@implementation ILVesselData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_posReportPresent = false;
        m_staticDatas = [[NSMutableArray alloc] init];
        m_voyages = [[NSMutableArray alloc] init];
        m_taggedItems = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void) dealloc {

    [m_posReport release];
    [m_staticDatas release];
    [m_voyages release];
    [m_taggedItems release];
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

-(bool) setPosReport:(ILPosReport *) val {

    m_posReportPresent = true;
    [m_posReport release];
    m_posReport = val;
    [m_posReport retain];
      return YES;
}

- (ILPosReport *) posReport {

    return m_posReport;
}

-(bool) hasPosReport {

    return m_posReportPresent;
}

-(bool) addStaticData:(ILStaticData *) val {

    [m_staticDatas addObject: val];
      return YES;
}

-(ILStaticData *) staticDataAt:(int) i {

    return [m_staticDatas objectAtIndex: i];
}

-(int) countOfStaticDatas {

    return [m_staticDatas count];
}

-(NSArray *) staticDatas {

    return m_staticDatas;
}

-(bool) addVoyage:(ILVoyage *) val {

    [m_voyages addObject: val];
      return YES;
}

-(ILVoyage *) voyageAt:(int) i {

    return [m_voyages objectAtIndex: i];
}

-(int) countOfVoyages {

    return [m_voyages count];
}

-(NSArray *) voyages {

    return m_voyages;
}

-(bool) addTaggedItem:(ILTaggedItem *) val {

    [m_taggedItems addObject: val];
      return YES;
}

-(ILTaggedItem *) taggedItemAt:(int) i {

    return [m_taggedItems objectAtIndex: i];
}

-(int) countOfTaggedItems {

    return [m_taggedItems count];
}

-(NSArray *) taggedItems {

    return m_taggedItems;
}

-(bool) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"PosReport"]) {
                ILPosReport * val = [attributeDict objectForKey: key];
                if (![self setPosReport: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"StaticData"]) {
                ILStaticData * val = [attributeDict objectForKey: key];
                if (![self addStaticData: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"Voyage"]) {
                ILVoyage * val = [attributeDict objectForKey: key];
                if (![self addVoyage: val]) {
                   return false;
                }
            }
            else if ([key isEqualToString:@"TaggedItem"]) {
                ILTaggedItem * val = [attributeDict objectForKey: key];
                if (![self addTaggedItem: val]) {
                   return false;
                }
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<VesselData"];
    [xml appendString:@">\n"];
    if ( [self hasPosReport] ) {
        [xml appendString: [m_posReport XML] ];
    }
    for(int i=0; i < [m_staticDatas count]; i++ ) {
        ILStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        ILVoyage *attribute = [m_voyages objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_taggedItems count]; i++ ) {
        ILTaggedItem *attribute = [m_taggedItems objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</VesselData>\n"];
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
    [str setString: [lead stringByAppendingString:@"VesselData\n"]];
    if ( [self hasPosReport] ) {
        [str appendString: [m_posReport stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    for(int i=0; i < [m_staticDatas count]; i++ ) {
        ILStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        ILVoyage *attribute = [m_voyages objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_taggedItems count]; i++ ) {
        ILTaggedItem *attribute = [m_taggedItems objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];

    return attr;
}


@end


