

//The Following File was generated with XSD2OBJC Copyright (C) 
2004  Pucky Loucks pucky[at]theloucks[dot]com
#import <Cocoa/Cocoa.h>
#import "ccm.h"

@implementation  PLHeader : NSObject


@end	

@implementation  PLMSG_VesselData : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(NSMutableArray *)vesselData
{
	return _VesselData;
}
-(void)setVesselData:(NSMutableArray 
*)newVesselData
{
	[newVesselData retain];
	[_VesselData release];
	_VesselData = newVesselData;
}

@end	

@implementation  PLVesselData : NSObject


-(id)posReport
{
	return _PosReport;
}
-(void)setPosReport:(id)newPosReport
{
	[newPosReport retain];
	[_PosReport release];
	_PosReport = newPosReport;
}

-(NSMutableArray *)staticData
{
	return _StaticData;
}
-(void)setStaticData:(NSMutableArray 
*)newStaticData
{
	[newStaticData retain];
	[_StaticData release];
	_StaticData = newStaticData;
}

-(NSMutableArray *)voyage
{
	return _Voyage;
}
-(void)setVoyage:(NSMutableArray 
*)newVoyage
{
	[newVoyage retain];
	[_Voyage release];
	_Voyage = newVoyage;
}

@end	

@implementation  PLPosReport : NSObject


-(id)pos
{
	return _Pos;
}
-(void)setPos:(id)newPos
{
	[newPos retain];
	[_Pos release];
	_Pos = newPos;
}

@end	

@implementation  PLStaticData : NSObject


@end	

@implementation  PLVoyage : NSObject


@end	

@implementation  PLMSG_LoginRequest : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)loginRequest
{
	return _LoginRequest;
}
-(void)setLoginRequest:(id)newLoginRequest
{
	[newLoginRequest retain];
	[_LoginRequest release];
	_LoginRequest = newLoginRequest;
}

@end	

@implementation  PLLoginRequest : NSObject


@end	

@implementation  PLMSG_LoginResponse : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)loginResponse
{
	return _LoginResponse;
}
-(void)setLoginResponse:(id)newLoginResponse
{
	[newLoginResponse retain];
	[_LoginResponse release];
	_LoginResponse = newLoginResponse;
}

@end	

@implementation  PLLoginResponse : NSObject


@end	

@implementation  PLMSG_Ping : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)ping
{
	return _Ping;
}
-(void)setPing:(id)newPing
{
	[newPing retain];
	[_Ping release];
	_Ping = newPing;
}

@end	

@implementation  PLPing : NSObject


@end	

@implementation  PLMSG_Pong : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)pong
{
	return _Pong;
}
-(void)setPong:(id)newPong
{
	[newPong retain];
	[_Pong release];
	_Pong = newPong;
}

@end	

@implementation  PLPong : NSObject


@end	

@implementation  PLMSG_ServerStatus : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)serverStatus
{
	return _ServerStatus;
}
-(void)setServerStatus:(id)newServerStatus
{
	[newServerStatus retain];
	[_ServerStatus release];
	_ServerStatus = newServerStatus;
}

@end	

@implementation  PLServerStatus : NSObject


@end	

@implementation  PLMSG_Logout : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)logout
{
	return _Logout;
}
-(void)setLogout:(id)newLogout
{
	[newLogout retain];
	[_Logout release];
	_Logout = newLogout;
}

@end	

@implementation  PLLogout : NSObject


@end	

@implementation  PLMSG_ServiceRequest : NSObject


-(id)header
{
	return _Header;
}
-(void)setHeader:(id)newHeader
{
	[newHeader retain];
	[_Header release];
	_Header = newHeader;
}

-(id)body
{
	return _Body;
}
-(void)setBody:(id)newBody
{
	[newBody retain];
	[_Body release];
	_Body = newBody;
}

@end	

@implementation  PLBody : NSObject


-(id)serviceRequest
{
	return _ServiceRequest;
}
-(void)setServiceRequest:(id)newServiceRequest
{
	[newServiceRequest retain];
	[_ServiceRequest release];
	_ServiceRequest = newServiceRequest;
}

@end	

@implementation  PLServiceRequest : NSObject


-(NSMutableArray *)area
{
	return _Area;
}
-(void)setArea:(NSMutableArray 
*)newArea
{
	[newArea retain];
	[_Area release];
	_Area = newArea;
}

-(id)transmission
{
	return _Transmission;
}
-(void)setTransmission:(id)newTransmission
{
	[newTransmission retain];
	[_Transmission release];
	_Transmission = newTransmission;
}

-(NSMutableArray *)item
{
	return _Item;
}
-(void)setItem:(NSMutableArray 
*)newItem
{
	[newItem retain];
	[_Item release];
	_Item = newItem;
}

-(NSMutableArray *)object
{
	return _Object;
}
-(void)setObject:(NSMutableArray 
*)newObject
{
	[newObject retain];
	[_Object release];
	_Object = newObject;
}

@end	

@implementation  PLArea : NSObject


-(NSMutableArray *)pos
{
	return _Pos;
}
-(void)setPos:(NSMutableArray 
*)newPos
{
	[newPos retain];
	[_Pos release];
	_Pos = newPos;
}

@end	

@implementation  PLTransmission : NSObject


@end	

@implementation  PLItem : NSObject


@end	

@implementation  PLObject : NSObject


@end	

@implementation  PLPos : NSObject


@end	
