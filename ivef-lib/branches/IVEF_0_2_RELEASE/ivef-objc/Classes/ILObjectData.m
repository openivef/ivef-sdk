
#import "ILObjectData.h"


@implementation ILObjectData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_trackDataPresent = NO;
        m_vesselDataPresent = NO;
        m_vesselDatas = [[NSMutableArray alloc] init];
        m_voyageDataPresent = NO;
        m_voyageDatas = [[NSMutableArray alloc] init];
        m_taggedItemPresent = NO;
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
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm:ss.SSS" allowNaturalLanguage:NO];
     }
#if defined (__clang__)
     return [[formatterWithMillies stringForObjectValue:date] stringByAppendingString:@"Z"]; // always zulu time
#else
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
#endif
}

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
#if defined (__clang__)
     str = [str stringByReplacingString:@"Z" withString:@""];

#else
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

#endif
     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm:ss.SSS" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm:ss" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] initWithDateFormat: @"yyyy-MM-dd'T'HH:mm" allowNaturalLanguage:NO];
     }
#if defined (__clang__)
     NSDate *val;
     [formatterWithMillies getObjectValue: &val forString: str errorDescription: nil];
#else
     NSDate *val = [formatterWithMillies dateFromString:str];
#endif
     if (val) {
         return val;
     }
#if defined (__clang__)
     [formatterWithSeconds getObjectValue: &val forString: str errorDescription: nil];
#else
     val = [formatterWithSeconds dateFromString:str];
#endif
     if (val) {
         return val;
     }
#if defined (__clang__)
     [formatterWithMinutes getObjectValue: &val forString: str errorDescription: nil];
#else
     val = [formatterWithMinutes dateFromString:str];
#endif
     if (val) {
         return val;
     }
     return nil; // invalid date
}

-(BOOL) setTrackData:(ILTrackData *) val {

    m_trackDataPresent = YES;
    [m_trackData release];
    m_trackData = val;
    [m_trackData retain];
    return YES;
}

- (ILTrackData *) trackData {

    return m_trackData;
}

-(BOOL) hasTrackData {

    return m_trackDataPresent;
}

-(BOOL) addVesselData:(ILVesselData *) val {

    [m_vesselDatas addObject: val];
     return YES;
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

-(BOOL) addVoyageData:(ILVoyageData *) val {

    [m_voyageDatas addObject: val];
     return YES;
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

-(BOOL) addTaggedItem:(ILTaggedItem *) val {

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

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"TrackData"]) {
                ILTrackData * val = [attributeDict objectForKey: key];
                if (![self setTrackData: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"VesselData"]) {
                ILVesselData * val = [attributeDict objectForKey: key];
                if (![self addVesselData: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"VoyageData"]) {
                ILVoyageData * val = [attributeDict objectForKey: key];
                if (![self addVoyageData: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"TaggedItem"]) {
                ILTaggedItem * val = [attributeDict objectForKey: key];
                if (![self addTaggedItem: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<ObjectData"];
    [xml appendString:@">\n"];
    if ( [self hasTrackData] ) {
        [xml appendString: [m_trackData XML] ];
    }
    if ([m_vesselDatas count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of VesselData" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        ILVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    if ([m_voyageDatas count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of VoyageData" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_voyageDatas count]; i++ ) {
        ILVoyageData *attribute = [m_voyageDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    if ([m_taggedItems count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of TaggedItem" forKey: @"description"]];
        return nil;
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
    if ( [self hasTrackData] ) {
        [str appendString: [m_trackData stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
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


