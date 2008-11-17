
#import "IVEFBody.h"


@implementation IVEFBody

- (id) init {
    self = [super init];
    if (self != nil) {
        m_vesselDataPresent = false;
        m_vesselDatas = [[NSMutableArray alloc] init];
        m_loginRequestPresent = false;
        m_loginResponsePresent = false;
        m_pingPresent = false;
        m_pongPresent = false;
        m_serverStatusPresent = false;
        m_logoutPresent = false;
        m_serviceRequestPresent = false;
        m_dateFormatter = [[NSDateFormatter alloc] init];
        [m_dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSS"];
    }
    return self;
}

-(void) addVesselData:(IVEFVesselData *) val {

    [m_vesselDatas addObject: val];
}

-(IVEFVesselData *) getVesselDataAt:(int) i {

    return [m_vesselDatas objectAtIndex: i];
}

-(int) countOfVesselDatas {

    return [m_vesselDatas count];
}

-(void) setLoginRequest:(IVEFLoginRequest *) val {

    m_loginRequestPresent = true;
    [m_loginRequest release];
    m_loginRequest = val;
    [m_loginRequest retain];
}

- (IVEFLoginRequest *) getLoginRequest {

    return m_loginRequest;
}

-(bool) hasLoginRequest {

    return m_loginRequestPresent;
}

-(void) setLoginResponse:(IVEFLoginResponse *) val {

    m_loginResponsePresent = true;
    [m_loginResponse release];
    m_loginResponse = val;
    [m_loginResponse retain];
}

- (IVEFLoginResponse *) getLoginResponse {

    return m_loginResponse;
}

-(bool) hasLoginResponse {

    return m_loginResponsePresent;
}

-(void) setPing:(IVEFPing *) val {

    m_pingPresent = true;
    [m_ping release];
    m_ping = val;
    [m_ping retain];
}

- (IVEFPing *) getPing {

    return m_ping;
}

-(bool) hasPing {

    return m_pingPresent;
}

-(void) setPong:(IVEFPong *) val {

    m_pongPresent = true;
    [m_pong release];
    m_pong = val;
    [m_pong retain];
}

- (IVEFPong *) getPong {

    return m_pong;
}

-(bool) hasPong {

    return m_pongPresent;
}

-(void) setServerStatus:(IVEFServerStatus *) val {

    m_serverStatusPresent = true;
    [m_serverStatus release];
    m_serverStatus = val;
    [m_serverStatus retain];
}

- (IVEFServerStatus *) getServerStatus {

    return m_serverStatus;
}

-(bool) hasServerStatus {

    return m_serverStatusPresent;
}

-(void) setLogout:(IVEFLogout *) val {

    m_logoutPresent = true;
    [m_logout release];
    m_logout = val;
    [m_logout retain];
}

- (IVEFLogout *) getLogout {

    return m_logout;
}

-(bool) hasLogout {

    return m_logoutPresent;
}

-(void) setServiceRequest:(IVEFServiceRequest *) val {

    m_serviceRequestPresent = true;
    [m_serviceRequest release];
    m_serviceRequest = val;
    [m_serviceRequest retain];
}

- (IVEFServiceRequest *) getServiceRequest {

    return m_serviceRequest;
}

-(bool) hasServiceRequest {

    return m_serviceRequestPresent;
}

-(void) setAttributes:(NSDictionary *)attributeDict {

        for (NSString *key in attributeDict) {
            if ([key isEqualToString: @"VesselData"]) {
                IVEFVesselData * val = [attributeDict objectForKey: key];
                [self addVesselData: val];
            }
            else if ([key isEqualToString:@"LoginRequest"]) {
                IVEFLoginRequest * val = [attributeDict objectForKey: key];
                [self setLoginRequest: val];
            }
            else if ([key isEqualToString:@"LoginResponse"]) {
                IVEFLoginResponse * val = [attributeDict objectForKey: key];
                [self setLoginResponse: val];
            }
            else if ([key isEqualToString:@"Ping"]) {
                IVEFPing * val = [attributeDict objectForKey: key];
                [self setPing: val];
            }
            else if ([key isEqualToString:@"Pong"]) {
                IVEFPong * val = [attributeDict objectForKey: key];
                [self setPong: val];
            }
            else if ([key isEqualToString:@"ServerStatus"]) {
                IVEFServerStatus * val = [attributeDict objectForKey: key];
                [self setServerStatus: val];
            }
            else if ([key isEqualToString:@"Logout"]) {
                IVEFLogout * val = [attributeDict objectForKey: key];
                [self setLogout: val];
            }
            else if ([key isEqualToString:@"ServiceRequest"]) {
                IVEFServiceRequest * val = [attributeDict objectForKey: key];
                [self setServiceRequest: val];
            }
        }
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<Body"];
    [xml appendString:@">\n"];
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        IVEFVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [xml appendString: [attribute XML] ];
    }
    if ( [self hasLoginRequest] ) {
        [xml appendString: [m_loginRequest XML] ];
    }
    if ( [self hasLoginResponse] ) {
        [xml appendString: [m_loginResponse XML] ];
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
    if ( [self hasLogout] ) {
        [xml appendString: [m_logout XML] ];
    }
    if ( [self hasServiceRequest] ) {
        [xml appendString: [m_serviceRequest XML] ];
    }
    [xml appendString: @"</Body>\n"];
    return xml;
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"Body\n"]];
    for(int i=0; i < [m_vesselDatas count]; i++ ) {
        IVEFVesselData *attribute = [m_vesselDatas objectAtIndex:i];
        [str appendString: [attribute stringValueWithLead: [lead stringByAppendingString: @" "]] ];
    }
    if ( [self hasLoginRequest] ) {
        [str appendString: [m_loginRequest stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasLoginResponse] ) {
        [str appendString: [m_loginResponse stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
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
    if ( [self hasLogout] ) {
        [str appendString: [m_logout stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    if ( [self hasServiceRequest] ) {
        [str appendString: [m_serviceRequest stringValueWithLead: [lead stringByAppendingString: @"    "]] ];
    }
    return str;
}


@end


