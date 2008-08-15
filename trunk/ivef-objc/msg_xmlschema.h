
//The Following File was generated with XSD2OBJC Copyright (C) 
2004  Pucky Loucks pucky[at]theloucks[dot]com
#import <Cocoa/Cocoa.h>


@class
 NSObject;

@interface  PLHeader : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_VesselData : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
 NSObject;

@interface  PLBody : NSObject
{

		NSMutableArray * _VesselData;

}


-(NSMutableArray *)vesselData;
-(void)setVesselData:(NSMutableArray 
*)newVesselData;

@end	

@class
PLPosReport,
 NSObject;

@interface  PLVesselData : NSObject
{
PLPosReport 
* _PosReport;

		NSMutableArray * _StaticData;

		NSMutableArray * _Voyage;

}


-(PLPosReport 
*)posReport;
-(void)setPosReport:(PLPosReport 
*)newPosReport;

-(NSMutableArray *)staticData;
-(void)setStaticData:(NSMutableArray 
*)newStaticData;

-(NSMutableArray *)voyage;
-(void)setVoyage:(NSMutableArray 
*)newVoyage;

@end	

@class
PLPos,
 NSObject;

@interface  PLPosReport : NSObject
{
PLPos 
* _Pos;

}


-(PLPos 
*)pos;
-(void)setPos:(PLPos 
*)newPos;

@end	

@class
 NSObject;

@interface  PLStaticData : NSObject
{

}


@end	

@class
 NSObject;

@interface  PLVoyage : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_LoginRequest : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLLoginRequest,
 NSObject;

@interface  PLBody : NSObject
{
PLLoginRequest 
* _LoginRequest;

}


-(PLLoginRequest 
*)loginRequest;
-(void)setLoginRequest:(PLLoginRequest 
*)newLoginRequest;

@end	

@class
 NSObject;

@interface  PLLoginRequest : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_LoginResponse : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLLoginResponse,
 NSObject;

@interface  PLBody : NSObject
{
PLLoginResponse 
* _LoginResponse;

}


-(PLLoginResponse 
*)loginResponse;
-(void)setLoginResponse:(PLLoginResponse 
*)newLoginResponse;

@end	

@class
 NSObject;

@interface  PLLoginResponse : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_Ping : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLPing,
 NSObject;

@interface  PLBody : NSObject
{
PLPing 
* _Ping;

}


-(PLPing 
*)ping;
-(void)setPing:(PLPing 
*)newPing;

@end	

@class
 NSObject;

@interface  PLPing : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_Pong : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLPong,
 NSObject;

@interface  PLBody : NSObject
{
PLPong 
* _Pong;

}


-(PLPong 
*)pong;
-(void)setPong:(PLPong 
*)newPong;

@end	

@class
 NSObject;

@interface  PLPong : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_ServerStatus : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLServerStatus,
 NSObject;

@interface  PLBody : NSObject
{
PLServerStatus 
* _ServerStatus;

}


-(PLServerStatus 
*)serverStatus;
-(void)setServerStatus:(PLServerStatus 
*)newServerStatus;

@end	

@class
 NSObject;

@interface  PLServerStatus : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_Logout : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLLogout,
 NSObject;

@interface  PLBody : NSObject
{
PLLogout 
* _Logout;

}


-(PLLogout *)logout;
-(void)setLogout:(PLLogout 
*)newLogout;

@end	

@class
 NSObject;

@interface  PLLogout : NSObject
{

}


@end	

@class
PLHeader,
PLBody,
 NSObject;

@interface  PLMSG_ServiceRequest : NSObject
{
PLHeader 
* _Header;
PLBody 
* _Body;

}


-(PLHeader 
*)header;
-(void)setHeader:(PLHeader 
*)newHeader;

-(PLBody *)body;
-(void)setBody:(PLBody 
*)newBody;

@end	

@class
PLServiceRequest,
 NSObject;

@interface  PLBody : NSObject
{
PLServiceRequest 
* _ServiceRequest;

}


-(PLServiceRequest 
*)serviceRequest;
-(void)setServiceRequest:(PLServiceRequest 
*)newServiceRequest;

@end	

@class
PLTransmission,
 NSObject;

@interface  PLServiceRequest : NSObject
{

		NSMutableArray * _Area;
PLTransmission 
* _Transmission;

		NSMutableArray * _Item;

		NSMutableArray * _Object;

}


-(NSMutableArray *)area;
-(void)setArea:(NSMutableArray 
*)newArea;

-(PLTransmission *)transmission;
-(void)setTransmission:(PLTransmission 
*)newTransmission;

-(NSMutableArray *)item;
-(void)setItem:(NSMutableArray 
*)newItem;

-(NSMutableArray *)object;
-(void)setObject:(NSMutableArray 
*)newObject;

@end	

@class
 NSObject;

@interface  PLArea : NSObject
{

		NSMutableArray * _Pos;

}


-(NSMutableArray *)pos;
-(void)setPos:(NSMutableArray 
*)newPos;

@end	

@class
 NSObject;

@interface  PLTransmission : NSObject
{

}


@end	

@class
 NSObject;

@interface  PLItem : NSObject
{

}


@end	

@class
 NSObject;

@interface  PLObject : NSObject
{

}


@end	

@class
 NSObject;

@interface  PLPos : NSObject
{

}


@end	
