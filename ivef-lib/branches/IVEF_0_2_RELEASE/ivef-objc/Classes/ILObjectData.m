
#import "ILObjectData.h"


@implementation ILObjectData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_vesselDatas = [[NSMutableArray alloc] init];
        m_voyageDatas = [[NSMutableArray alloc] init];
        m_taggedItems = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void) dealloc {

    [m_trackData release];
    [m_vesselDatas release];
    [m_voyageDatas release];
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

-(void) setTrackData:(ILTrackData *) val {

    [m_trackData release];
    m_trackData = val;
    [m_trackData retain];
}

- (ILTrackData *) trackData {

    return m_trackData;
}

-(void) addVesselData:(ILVesselData *) val {

    [m_vesselDatas addObject: val];
}

-(ILVesselData *) vesselDataAt:(int) i {

    return [m_vesselDatas objectAtIndex: i];
}

-(int) countOfVesselDatas {

    return [m_vesselDatas count];
}

-(NSArray *) vesselDatas {

    return m_vesselDatas;
}

-(void) addVoyageData:(ILVoyageData *) val {

    [m_voyageDatas addObject: val];
}

-(ILVoyageData *) voyageDataAt:(int) i {

    return [m_voyageDatas objectAtIndex: i];
}

-(int) countOfVoyageDatas {

    return [m_voyageDatas count];
}

-(NSArray *) voyageDatas {

    return m_voyageDatas;
}

-(void) addTaggedItem:(ILTaggedItem *) val {

    [m_taggedItems addObject: val];
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

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"TrackData"]) {
                ILTrackData * val = [attributeDict objectForKey: key];
                [self setTrackData: val];
            }
            else if ([key isEqualToString:@"VesselData"]) {
                ILVesselData * val = [attributeDict objectForKey: key];
                [self addVesselData: val];
            }
            else if ([key isEqualToString:@"VoyageData"]) {
                ILVoyageData * val = [attributeDict objectForKey: key];
                [self addVoyageData: val];
            }
            else if ([key isEqualToString:@"TaggedItem"]) {
                ILTaggedItem * val = [attributeDict objectForKey: key];
                [self addTaggedItem: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ObjectData"];
    [xml appendString:@">\n"];
    [xml appendString: [m_trackData XML] ];
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        ILVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_voyageDatas count]; i++ ) {
        ILVoyageData *attribute = [m_voyageDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    for(int i=0; i < [m_taggedItems count]; i++ ) {
        ILTaggedItem *attribute = [m_taggedItems objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</ObjectData>\n"];
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
    [str setString: [lead stringByAppendingString:@"ObjectData\n"]];
    [str appendString: [m_trackData stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        ILVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    for(int i=0; i < [m_voyageDatas count]; i++ ) {
        ILVoyageData *attribute = [m_voyageDatas objectAtIndex:i];
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


