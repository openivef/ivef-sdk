
#import "ILVesselData.h"


@implementation ILVesselData

- (id) init {
    self = [super init];
    if (self != nil) {
        m_classPresent = false;
        m_blackListedPresent = false;
        m_specialAttentionPresent = false;
        m_sourceIdPresent = false;
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

-(void) setConstruction:(ILConstruction *) val {

    [m_construction release];
    m_construction = val;
    [m_construction retain];
}

- (ILConstruction *) construction {

    return m_construction;
}

-(void) setIdentifier:(ILIdentifier *) val {

    [m_identifier release];
    m_identifier = val;
    [m_identifier retain];
}

- (ILIdentifier *) identifier {

    return m_identifier;
}

-(void) setClass:(int) val {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) )
        return;
    m_classPresent = true;
    m_class = val;
}

- (int) class {

    return m_class;
}

-(bool) hasClass {

    return m_classPresent;
}

-(void) setBlackListed:(bool) val {

    m_blackListedPresent = true;
    m_blackListed = val;
}

- (bool) blackListed {

    return m_blackListed;
}

-(bool) hasBlackListed {

    return m_blackListedPresent;
}

-(void) setIdent:(int) val {

    m_id = val;
}

- (int) ident {

    return m_id;
}

-(void) setSpecialAttention:(NSString *) val {

    m_specialAttentionPresent = true;
    [m_specialAttention release];
    m_specialAttention = val;
    [m_specialAttention retain];
}

- (NSString *) specialAttention {

    return m_specialAttention;
}

-(bool) hasSpecialAttention {

    return m_specialAttentionPresent;
}

-(void) setSourceId:(NSString *) val {

    m_sourceIdPresent = true;
    [m_sourceId release];
    m_sourceId = val;
    [m_sourceId retain];
}

- (NSString *) sourceId {

    return m_sourceId;
}

-(bool) hasSourceId {

    return m_sourceIdPresent;
}

-(void) setSourceName:(NSString *) val {

    [m_sourceName release];
    m_sourceName = val;
    [m_sourceName retain];
}

- (NSString *) sourceName {

    return m_sourceName;
}

-(void) setSourceType:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_sourceType = val;
}

- (int) sourceType {

    return m_sourceType;
}

-(void) setUpdateTime:(NSDate *) val {

    [m_updateTime release];
    m_updateTime = val;
    [m_updateTime retain];
}

- (NSDate *) updateTime {

    return m_updateTime;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"Construction"]) {
                ILConstruction * val = [attributeDict objectForKey: key];
                [self setConstruction: val];
            }
            else if ([key isEqualToString:@"Identifier"]) {
                ILIdentifier * val = [attributeDict objectForKey: key];
                [self setIdentifier: val];
            }
            else if ([key isEqualToString:@"Class"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setClass: val];
            }
            else if ([key isEqualToString:@"BlackListed"]) {
                NSString *value = [attributeDict objectForKey: key];
                bool val = ([[value uppercaseString] isEqualToString: @"YES"] || 
                            [[value uppercaseString] isEqualToString: @"TRUE"] ||
                            [[value uppercaseString] isEqualToString: @"1"]);
                [self setBlackListed: val];
            }
            else if ([key isEqualToString:@"Id"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setIdent: val];
            }
            else if ([key isEqualToString:@"SpecialAttention"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSpecialAttention: val];
            }
            else if ([key isEqualToString:@"SourceId"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceId: val];
            }
            else if ([key isEqualToString:@"SourceName"]) {
                NSString *val = [attributeDict objectForKey: key];
                [self setSourceName: val];
            }
            else if ([key isEqualToString:@"SourceType"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                [self setSourceType: val];
            }
            else if ([key isEqualToString:@"UpdateTime"]) {
                NSString *value = [attributeDict objectForKey: key];
                NSDate *val = [self dateFromString: value];
                [self setUpdateTime: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<VesselData"];
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
    [xml appendString: @" Id=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_id]];
    [xml appendString: @"\""];
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
    [xml appendString: @" SourceName=\""];
    [xml appendString: [self encode: m_sourceName]];
    [xml appendString: @"\""];
    [xml appendString: @" SourceType=\""];
    [xml appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
    [xml appendString: @"\""];
    [xml appendString: @" UpdateTime=\""];
    [xml appendString: [self stringFromDate: m_updateTime]];
    [xml appendString: @"\""];
    [xml appendString:@">\n"];
    [xml appendString: [m_construction XML] ];
    [xml appendString: [m_identifier XML] ];
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
        [str appendString: @"Class = \""];
        [str appendString: [NSString stringWithFormat:@"%d", m_class]];
        [str appendString: @"\"\n"];

    }
    if ( [self hasBlackListed] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"BlackListed = \""];
        [str appendString: [NSString stringWithFormat:@"%f", m_blackListed]];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Id=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_id]];
    [str appendString: @"\"\n"];

    if ( [self hasSpecialAttention] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SpecialAttention = \""];
        [str appendString: m_specialAttention];
        [str appendString: @"\"\n"];

    }
    if ( [self hasSourceId] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"SourceId = \""];
        [str appendString: m_sourceId];
        [str appendString: @"\"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceName=\""];
    [str appendString: m_sourceName];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"SourceType=\""];
    [str appendString: [NSString stringWithFormat:@"%d", m_sourceType]];
    [str appendString: @"\"\n"];

    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"UpdateTime=\""];
    [str appendString: [self stringFromDate: m_updateTime]];
    [str appendString: @"\"\n"];

    [str appendString: [m_construction stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    [str appendString: [m_identifier stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
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


