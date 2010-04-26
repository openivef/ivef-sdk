
#import "ILVesselData.h"


@implementation ILVesselData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_posReportPresent = NO;
        m_staticDatas = [[NSMutableArray alloc] init];
        m_staticDataPresent = NO;
        m_voyages = [[NSMutableArray alloc] init];
        m_voyagePresent = NO;
        m_taggedItems = [[NSMutableArray alloc] init];
        m_taggedItemPresent = NO;
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
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
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
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M" allowNaturalLanguage:NO];
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

-(BOOL) setPosReport:(ILPosReport *) val {

    m_posReportPresent = YES;
    [m_posReport release];
    m_posReport = val;
    [m_posReport retain];
    return YES;
}

- (ILPosReport *) posReport {

    return m_posReport;
}

-(BOOL) hasPosReport {

    return m_posReportPresent;
}

-(BOOL) addStaticData:(ILStaticData *) val {

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

-(BOOL) addVoyage:(ILVoyage *) val {

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
            if ([key isEqualToString: @"PosReport"]) {
                ILPosReport * val = [attributeDict objectForKey: key];
                if (![self setPosReport: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"StaticData"]) {
                ILStaticData * val = [attributeDict objectForKey: key];
                if (![self addStaticData: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Voyage"]) {
                ILVoyage * val = [attributeDict objectForKey: key];
                if (![self addVoyage: val]) {
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

    NSMutableString *xml = [NSMutableString stringWithString:@"<VesselData"];
    [xml appendString:@">\n"];
    if ( [self hasPosReport] ) {
        [xml appendString: [m_posReport XML] ];
    }
    if ([m_staticDatas count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of StaticData" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_staticDatas count]; i++ ) {
        ILStaticData *attribute = [m_staticDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    if ([m_voyages count] < 0) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Not enough entries of Voyage" forKey: @"description"]];
        return nil;
    }
    for(int i=0; i < [m_voyages count]; i++ ) {
        ILVoyage *attribute = [m_voyages objectAtIndex:i];
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


