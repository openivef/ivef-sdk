/* 
 *  IVEFBody
 *
 *  IVEFBody is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY ); without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 **********************************************************************************
 *  WARNING: THIS CODE WAS GENERATED DO NOT MODIFY, CHANGE THE XSD INSTEAD
 *  Generated by xsd2code on Thu Feb 19 11:05:57 2009.
 **********************************************************************************
 *  Copyright 2008
 *
 */

#import <Foundation/Foundation.h>
#import "IVEFVesselData.h"
#import "IVEFLoginRequest.h"
#import "IVEFLoginResponse.h"
#import "IVEFPing.h"
#import "IVEFPong.h"
#import "IVEFServerStatus.h"
#import "IVEFLogout.h"
#import "IVEFServiceRequest.h"

@interface IVEFBody : NSObject { 
    NSMutableArray *m_vesselDatas;
    bool m_vesselDataPresent;
    IVEFLoginRequest *m_loginRequest;
    bool m_loginRequestPresent;
    IVEFLoginResponse *m_loginResponse;
    bool m_loginResponsePresent;
    IVEFPing *m_ping;
    bool m_pingPresent;
    IVEFPong *m_pong;
    bool m_pongPresent;
    IVEFServerStatus *m_serverStatus;
    bool m_serverStatusPresent;
    IVEFLogout *m_logout;
    bool m_logoutPresent;
    IVEFServiceRequest *m_serviceRequest;
    bool m_serviceRequestPresent;
    NSDateFormatter *m_dateFormatter;
}

-(void) addVesselData:(IVEFVesselData *) val;
-(IVEFVesselData *) getVesselDataAt:(int) i;
-(int) countOfVesselDatas;
-(void) setLoginRequest:(IVEFLoginRequest *) val;
-(IVEFLoginRequest *) getLoginRequest;
-(bool) hasLoginRequest;
-(void) setLoginResponse:(IVEFLoginResponse *) val;
-(IVEFLoginResponse *) getLoginResponse;
-(bool) hasLoginResponse;
-(void) setPing:(IVEFPing *) val;
-(IVEFPing *) getPing;
-(bool) hasPing;
-(void) setPong:(IVEFPong *) val;
-(IVEFPong *) getPong;
-(bool) hasPong;
-(void) setServerStatus:(IVEFServerStatus *) val;
-(IVEFServerStatus *) getServerStatus;
-(bool) hasServerStatus;

/* Logout:
   Logout element node */
-(void) setLogout:(IVEFLogout *) val;
-(IVEFLogout *) getLogout;
-(bool) hasLogout;
-(void) setServiceRequest:(IVEFServiceRequest *) val;
-(IVEFServiceRequest *) getServiceRequest;
-(bool) hasServiceRequest;

-(void) setAttributes:(NSDictionary *)attributeDict;
-(NSString *) XML;
-(NSString *) stringValueWithLead:(NSString *) lead;

@end



