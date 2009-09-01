
#import "ILBody.h"


@implementation ILBody

- (id) init {
    self = [super init];
    if (self != nil) {
        m_loginRequestPresent = false;
        m_loginResponsePresent = false;
        m_logoutPresent = false;
        m_pingPresent = false;
        m_pongPresent = false;
        m_serverStatusPresent = false;
        m_serviceRequestPresent = false;
        m_vesselDataPresent = false;
        m_vesselDatas = [[NSMutableArray alloc] init];
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

- (NSDate*) dateFromString:(NSString *)str {

     // new date strings can be in Zulu time
     str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

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
     static NSDateFormatter *formatterWithMinutes = nil;
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

-(void) setLoginRequest:(ILLoginRequest *) val {

    m_loginRequestPresent = true;
    [m_loginRequest release];
    m_loginRequest = val;
    [m_loginRequest retain];
}

- (ILLoginRequest *) loginRequest {

    return m_loginRequest;
}

-(bool) hasLoginRequest {

    return m_loginRequestPresent;
}

-(void) setLoginResponse:(ILLoginResponse *) val {

    m_loginResponsePresent = true;
    [m_loginResponse release];
    m_loginResponse = val;
    [m_loginResponse retain];
}

- (ILLoginResponse *) loginResponse {

    return m_loginResponse;
}

-(bool) hasLoginResponse {

    return m_loginResponsePresent;
}

-(void) setLogout:(ILLogout *) val {

    m_logoutPresent = true;
    [m_logout release];
    m_logout = val;
    [m_logout retain];
}

- (ILLogout *) logout {

    return m_logout;
}

-(bool) hasLogout {

    return m_logoutPresent;
}

-(void) setPing:(ILPing *) val {

    m_pingPresent = true;
    [m_ping release];
    m_ping = val;
    [m_ping retain];
}

- (ILPing *) ping {

    return m_ping;
}

-(bool) hasPing {

    return m_pingPresent;
}

-(void) setPong:(ILPong *) val {

    m_pongPresent = true;
    [m_pong release];
    m_pong = val;
    [m_pong retain];
}

- (ILPong *) pong {

    return m_pong;
}

-(bool) hasPong {

    return m_pongPresent;
}

-(void) setServerStatus:(ILServerStatus *) val {

    m_serverStatusPresent = true;
    [m_serverStatus release];
    m_serverStatus = val;
    [m_serverStatus retain];
}

- (ILServerStatus *) serverStatus {

    return m_serverStatus;
}

-(bool) hasServerStatus {

    return m_serverStatusPresent;
}

-(void) setServiceRequest:(ILServiceRequest *) val {

    m_serviceRequestPresent = true;
    [m_serviceRequest release];
    m_serviceRequest = val;
    [m_serviceRequest retain];
}

- (ILServiceRequest *) serviceRequest {

    return m_serviceRequest;
}

-(bool) hasServiceRequest {

    return m_serviceRequestPresent;
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

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"LoginRequest"]) {
                ILLoginRequest * val = [attributeDict objectForKey: key];
                [self setLoginRequest: val];
            }
            else if ([key isEqualToString:@"LoginResponse"]) {
                ILLoginResponse * val = [attributeDict objectForKey: key];
                [self setLoginResponse: val];
            }
            else if ([key isEqualToString:@"Logout"]) {
                ILLogout * val = [attributeDict objectForKey: key];
                [self setLogout: val];
            }
            else if ([key isEqualToString:@"Ping"]) {
                ILPing * val = [attributeDict objectForKey: key];
                [self setPing: val];
            }
            else if ([key isEqualToString:@"Pong"]) {
                ILPong * val = [attributeDict objectForKey: key];
                [self setPong: val];
            }
            else if ([key isEqualToString:@"ServerStatus"]) {
                ILServerStatus * val = [attributeDict objectForKey: key];
                [self setServerStatus: val];
            }
            else if ([key isEqualToString:@"ServiceRequest"]) {
                ILServiceRequest * val = [attributeDict objectForKey: key];
                [self setServiceRequest: val];
            }
            else if ([key isEqualToString:@"VesselData"]) {
                ILVesselData * val = [attributeDict objectForKey: key];
                [self addVesselData: val];
            }
        }
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


