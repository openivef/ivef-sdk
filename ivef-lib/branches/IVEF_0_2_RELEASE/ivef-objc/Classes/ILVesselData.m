
#import "ILVesselData.h"


@implementation ILVesselData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_constructionPresent = NO;
        m_identifierPresent = NO;
        m_classPresent = NO;
        m_blackListedPresent = NO;
        m_idPresent = NO;
        m_specialAttentionPresent = NO;
        m_sourceIdPresent = NO;
        m_sourceNamePresent = NO;
        m_sourceTypePresent = NO;
        m_updateTimePresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_construction release];
    [m_identifier release];
    [m_specialAttention release];
    [m_sourceId release];
    [m_sourceName release];
    [m_updateTime release];
    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
     [formatterWithMillies setTimeZone:timeZone];
#if defined (__clang__)
     return [[formatterWithMillies stringForObjectValue:date] stringByAppendingString:@"Z"]; // always zulu time
#else
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
#endif
}

- (NSDate*) dateFromString:(NSString *)str {

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
     // new date strings can be in Zulu time
     NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
     if ([str characterAtIndex: [str length] - 1] == 'Z') {
         [formatterWithMillies setTimeZone:timeZone]; // localtime is default
         [formatterWithSeconds setTimeZone:timeZone]; // localtime is default
         [formatterWithMinutes setTimeZone:timeZone]; // localtime is default
#if defined (__clang__)
         str = [str stringByReplacingString:@"Z" withString:@""];

#else
         str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

#endif
     }
     // convert
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

-(BOOL) setConstruction:(ILConstruction *) val {

    m_constructionPresent = YES;
    [m_construction release];
    m_construction = val;
    [m_construction retain];
    return YES;
}

- (ILConstruction *) construction {

    return m_construction;
}

-(BOOL) hasConstruction {

    return m_constructionPresent;
}

-(BOOL) setIdentifier:(ILIdentifier *) val {

    m_identifierPresent = YES;
    [m_identifier release];
    m_identifier = val;
    [m_identifier retain];
    return YES;
}

- (ILIdentifier *) identifier {

    return m_identifier;
}

-(BOOL) hasIdentifier {

    return m_identifierPresent;
}

-(BOOL) setClass:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return NO;
    m_classPresent = YES;
    m_class = val;
    return YES;
}

- (int) class {

    return m_class;
}

-(BOOL) hasClass {

    return m_classPresent;
}

-(BOOL) setBlackListed:(BOOL) val {

    m_blackListedPresent = YES;
    m_blackListed = val;
    return YES;
}

- (BOOL) blackListed {

    return m_blackListed;
}

-(BOOL) hasBlackListed {

    return m_blackListedPresent;
}

-(BOOL) setIdent:(int) val {

    m_idPresent = YES;
    m_id = val;
    return YES;
}

- (int) ident {

    return m_id;
}

-(BOOL) setSpecialAttention:(NSString *) val {

    if ([val length] > 20)
        return NO;
    m_specialAttentionPresent = YES;
    [m_specialAttention release];
    m_specialAttention = val;
    [m_specialAttention retain];
    return YES;
}

- (NSString *) specialAttention {

    return m_specialAttention;
}

-(BOOL) hasSpecialAttention {

    return m_specialAttentionPresent;
}

-(BOOL) setSourceId:(NSString *) val {

    if ([val length] < 5)
        return NO;
    if ([val length] > 15)
        return NO;
    m_sourceIdPresent = YES;
    [m_sourceId release];
    m_sourceId = val;
    [m_sourceId retain];
    return YES;
}

- (NSString *) sourceId {

    return m_sourceId;
}

-(BOOL) hasSourceId {

    return m_sourceIdPresent;
}

-(BOOL) setSourceName:(NSString *) val {

    if ([val length] < 1)
        return NO;
    if ([val length] > 42)
        return NO;
    m_sourceNamePresent = YES;
    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
    return YES;
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(BOOL) setSourceType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return NO;
    m_sourceTypePresent = YES;
    m_sourceType = val;
    return YES;
}

- (int) sourceType {

    return m_sourceType;
}

-(BOOL) setUpdateTime:(NSDate *) val {

    m_updateTimePresent = YES;
    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
    return YES;
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"Class"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setClass: val]) {
                   return NO;
                }
                if (![self setClass: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"BlackListed"]) {
                NSString *value = [attributeDict objectForKey: key];
                BOOL val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                if (![self setBlackListed: val]) {
                   return NO;
                }
                if (![self setBlackListed: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setIdent: val]) {
                   return NO;
                }
                if (![self setIdent: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SpecialAttention"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSpecialAttention: val]) {
                   return NO;
                }
                if (![self setSpecialAttention: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceId: val]) {
                   return NO;
                }
                if (![self setSourceId: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setSourceName: val]) {
                   return NO;
                }
                if (![self setSourceName: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"SourceType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setSourceType: val]) {
                   return NO;
                }
                if (![self setSourceType: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                if (![self setUpdateTime: val]) {
                   return NO;
                }
                if (![self setUpdateTime: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<VesselData"];
    NSString *dataMember;
    if ( [self hasClass] ) {
        [xml appendString: @" Class=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_class]];
        [xml appendString: @"\""];
    }
    if ( [self hasBlackListed] ) {
        [xml appendString: @" BlackListed=\""];
        [xml appendString: (m_blackListed?@"true":@"false")];
        [xml appendString: @"\""];
    }
    if ( m_idPresent ) {
        [xml appendString: @" Id=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Id" forKey: @"description"]];
        return nil;
    }
    if ( [self hasSpecialAttention] ) {
        [xml appendString: @" SpecialAttention=\""];
        [xml appendString: [self encode: m_specialAttention]];
        [xml appendString: @"\""];
    }
    if ( [self hasSourceId] ) {
        [xml appendString: @" SourceId=\""];
        [xml appendString: [self encode: m_sourceId]];
        [xml appendString: @"\""];
    }
    if ( m_sourceNamePresent ) {
        [xml appendString: @" SourceName=\""];
        [xml appendString: [self encode: m_sourceName]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceName" forKey: @"description"]];
        return nil;
    }
    if ( m_sourceTypePresent ) {
        [xml appendString: @" SourceType=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"SourceType" forKey: @"description"]];
        return nil;
    }
    if ( m_updateTimePresent ) {
        [xml appendString: @" UpdateTime=\""];
        [xml appendString: [self stringFromDate: m_updateTime]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"UpdateTime" forKey: @"description"]];
        return nil;
    }
    [xml appendString:@">\n"];
    if ( [self hasConstruction] ) {
        dataMember = [m_construction XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Construction" forKey: @"description"]];
            return nil;
        }
    }
    if ( [self hasIdentifier] ) {
        dataMember = [m_identifier XML];
        if (dataMember != nil) {
            [xml appendString: dataMember];
        } else { 
            [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Identifier" forKey: @"description"]];
            return nil;
        }
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
    if ( [self hasClass] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"Class = "];
        [str appendString: [NSString stringWithFormat:@"%d", m_class]];
        [str appendString: @"\n"];

    }
    if ( [self hasBlackListed] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"BlackListed = "];
        [str appendString: (m_blackListed?@"true":@"false")];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\n"];

    if ( [self hasSpecialAttention] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SpecialAttention = "];
        [str appendString: m_specialAttention];
        [str appendString: @"\n"];

    }
    if ( [self hasSourceId] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SourceId = "];
        [str appendString: m_sourceId];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName = "];
    [str appendString: m_sourceName];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceType = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
    [str appendString: @"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime = "];
    [str appendString: [self stringFromDate: m_updateTime]];
    [str appendString: @"\n"];

    if ( [self hasConstruction] ) {
        [str appendString: [m_construction stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasIdentifier] ) {
        [str appendString: [m_identifier stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    if ( [self hasClass] ) {
        [attr setObject: [NSString stringWithFormat:@"%d", m_class] forKey: @"Class"];
    }
    if ( [self hasBlackListed] ) {
        [attr setObject: [NSString stringWithFormat:@"%f", m_blackListed] forKey: @"BlackListed"];
    }
    [attr setObject: [NSString stringWithFormat:@"%d", m_id] forKey: @"Id"];
    if ( [self hasSpecialAttention] ) {
        [attr setObject: m_specialAttention forKey: @"SpecialAttention"];
    }
    if ( [self hasSourceId] ) {
        [attr setObject: m_sourceId forKey: @"SourceId"];
    }
    [attr setObject: m_sourceName forKey: @"SourceName"];
    [attr setObject: [NSString stringWithFormat:@"%d", m_sourceType] forKey: @"SourceType"];
    [attr setObject: [self stringFromDate: m_updateTime] forKey: @"UpdateTime"];

    return attr;
}


@end


