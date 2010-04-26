
#import "ILBody.h"


@implementation ILBody

- (id) init {
    self = [super init];
    if (self != nil) {
        m_loginRequestPresent = NO;
        m_loginResponsePresent = NO;
        m_logoutPresent = NO;
        m_pingPresent = NO;
        m_pongPresent = NO;
        m_serverStatusPresent = NO;
        m_serviceRequestPresent = NO;
        m_vesselDatas = [[NSMutableArray alloc] init];
        m_vesselDataPresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_loginRequest release];
    [m_loginResponse release];
    [m_logout release];
    [m_ping release];
    [m_pong release];
    [m_serverStatus release];
    [m_serviceRequest release];
    [m_vesselDatas release];
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

-(BOOL) setLoginRequest:(ILLoginRequest *) val {

    m_loginRequestPresent = YES;
    [m_loginRequest release];
    m_loginRequest = val;
    [m_loginRequest retain];
    return YES;
}

- (ILLoginRequest *) loginRequest {

    return m_loginRequest;
}

-(BOOL) hasLoginRequest {

    return m_loginRequestPresent;
}

-(BOOL) setLoginResponse:(ILLoginResponse *) val {

    m_loginResponsePresent = YES;
    [m_loginResponse release];
    m_loginResponse = val;
    [m_loginResponse retain];
    return YES;
}

- (ILLoginResponse *) loginResponse {

    return m_loginResponse;
}

-(BOOL) hasLoginResponse {

    return m_loginResponsePresent;
}

-(BOOL) setLogout:(ILLogout *) val {

    m_logoutPresent = YES;
    [m_logout release];
    m_logout = val;
    [m_logout retain];
    return YES;
}

- (ILLogout *) logout {

    return m_logout;
}

-(BOOL) hasLogout {

    return m_logoutPresent;
}

-(BOOL) setPing:(ILPing *) val {

    m_pingPresent = YES;
    [m_ping release];
    m_ping = val;
    [m_ping retain];
    return YES;
}

- (ILPing *) ping {

    return m_ping;
}

-(BOOL) hasPing {

    return m_pingPresent;
}

-(BOOL) setPong:(ILPong *) val {

    m_pongPresent = YES;
    [m_pong release];
    m_pong = val;
    [m_pong retain];
    return YES;
}

- (ILPong *) pong {

    return m_pong;
}

-(BOOL) hasPong {

    return m_pongPresent;
}

-(BOOL) setServerStatus:(ILServerStatus *) val {

    m_serverStatusPresent = YES;
    [m_serverStatus release];
    m_serverStatus = val;
    [m_serverStatus retain];
    return YES;
}

- (ILServerStatus *) serverStatus {

    return m_serverStatus;
}

-(BOOL) hasServerStatus {

    return m_serverStatusPresent;
}

-(BOOL) setServiceRequest:(ILServiceRequest *) val {

    m_serviceRequestPresent = YES;
    [m_serviceRequest release];
    m_serviceRequest = val;
    [m_serviceRequest retain];
    return YES;
}

- (ILServiceRequest *) serviceRequest {

    return m_serviceRequest;
}

-(BOOL) hasServiceRequest {

    return m_serviceRequestPresent;
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

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"LoginRequest"]) {
                ILLoginRequest * val = [attributeDict objectForKey: key];
                if (![self setLoginRequest: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"LoginResponse"]) {
                ILLoginResponse * val = [attributeDict objectForKey: key];
                if (![self setLoginResponse: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Logout"]) {
                ILLogout * val = [attributeDict objectForKey: key];
                if (![self setLogout: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Ping"]) {
                ILPing * val = [attributeDict objectForKey: key];
                if (![self setPing: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Pong"]) {
                ILPong * val = [attributeDict objectForKey: key];
                if (![self setPong: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ServerStatus"]) {
                ILServerStatus * val = [attributeDict objectForKey: key];
                if (![self setServerStatus: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"ServiceRequest"]) {
                ILServiceRequest * val = [attributeDict objectForKey: key];
                if (![self setServiceRequest: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"VesselData"]) {
                ILVesselData * val = [attributeDict objectForKey: key];
                if (![self addVesselData: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Body"];
    [xml appendString:@">\n"];
    if ( [self hasLoginRequest] ) {
        [xml appendString: [m_loginRequest XML] ];
    }
    if ( [self hasLoginResponse] ) {
        [xml appendString: [m_loginResponse XML] ];
    }
    if ( [self hasLogout] ) {
        [xml appendString: [m_logout XML] ];
    }
    if ( [self hasPing] ) {
        [xml appendString: [m_ping XML] ];
    }
    if ( [self hasPong] ) {
        [xml appendString: [m_pong XML] ];
    }
    if ( [self hasServerStatus] ) {
        [xml appendString: [m_serverStatus XML] ];
    }
    if ( [self hasServiceRequest] ) {
        [xml appendString: [m_serviceRequest XML] ];
    }
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        ILVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    [xml appendString: @"</Body>\n"];
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
    [str setString: [lead stringByAppendingString:@"Body\n"]];
    if ( [self hasLoginRequest] ) {
        [str appendString: [m_loginRequest stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasLoginResponse] ) {
        [str appendString: [m_loginResponse stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasLogout] ) {
        [str appendString: [m_logout stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasPing] ) {
        [str appendString: [m_ping stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasPong] ) {
        [str appendString: [m_pong stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasServerStatus] ) {
        [str appendString: [m_serverStatus stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasServiceRequest] ) {
        [str appendString: [m_serviceRequest stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        ILVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];

    return attr;
}


@end


