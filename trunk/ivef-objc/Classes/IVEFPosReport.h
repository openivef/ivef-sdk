/* 
 *  IVEFPosReport
 *
 *  IVEFPosReport is free software: you can redistribute it and/or modify
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
#import "IVEFPos.h"

@interface IVEFPosReport : NSObject { 
    IVEFPos *m_pos;
    int m_id;
    int m_sourceId;
    NSDate *m_updateTime;
    float m_SOG;
    float m_COG;
    NSString *m_lost;
    float m_rateOfTurn;
    bool m_rateOfTurnPresent;
    float m_orientation;
    bool m_orientationPresent;
    float m_length;
    bool m_lengthPresent;
    float m_breadth;
    bool m_breadthPresent;
    float m_altitude;
    bool m_altitudePresent;
    int m_navStatus;
    bool m_navStatusPresent;
    int m_updSensorType;
    bool m_updSensorTypePresent;
    bool m_ATONOffPos;
    bool m_ATONOffPosPresent;
    NSDateFormatter *m_dateFormatter;
}

-(void) setPos:(IVEFPos *) val;
-(IVEFPos *) getPos;

/* Id:
   The identification of this track */
-(void) setId:(int) val;
-(int) getId;

/* SourceId:
   The identification of the node who initially created this message */
-(void) setSourceId:(int) val;
-(int) getSourceId;

/* UpdateTime:
   Date and time in ISO 8601 UTC format (YYYY-MM-DDThh:mm:ss.sss)  this position was measured. */
-(void) setUpdateTime:(NSDate *) val;
-(NSDate *) getUpdateTime;

/* SOG:
   Speed over ground in meters per second */
-(void) setSOG:(float) val;
-(float) getSOG;

/* COG:
   Course over ground  in degrees. (0-360) */
-(void) setCOG:(float) val;
-(float) getCOG;

/* Lost:
   'yes' or 'no' */
-(void) setLost:(NSString *) val;
-(NSString *) getLost;

/* RateOfTurn:
   Rate of turn in degrees per minute */
-(void) setRateOfTurn:(float) val;
-(float) getRateOfTurn;
-(bool) hasRateOfTurn;

/* Orientation:
   Orientation of the target in degrees */
-(void) setOrientation:(float) val;
-(float) getOrientation;
-(bool) hasOrientation;

/* Length:
   Length of the target in meter */
-(void) setLength:(float) val;
-(float) getLength;
-(bool) hasLength;

/* Breadth:
   Breadth of the target in  meter */
-(void) setBreadth:(float) val;
-(float) getBreadth;
-(bool) hasBreadth;

/* Altitude:
   The altitude of the target above the WGS-84 ellipsoid in meters */
-(void) setAltitude:(float) val;
-(float) getAltitude;
-(bool) hasAltitude;

/* NavStatus:
   Navigation status of the target
   0 = under way using engine
   1 = at anchor
   2 = not under command
   3 = restricted manoeuvrability
   4 = constrained by her draught
   5 = moored
   6 = aground
   7 = engaged in fishing
   8 = under way sailing
   9 - 14 = reserved for future use
   15 = undefined default */
-(void) setNavStatus:(int) val;
-(int) getNavStatus;
-(bool) hasNavStatus;

/* UpdSensorType:
   Type of detection or track type:
   1 = radar
   2 = ais
   3 = ais+radar
   4 = deadreckoning */
-(void) setUpdSensorType:(int) val;
-(int) getUpdSensorType;
-(bool) hasUpdSensorType;

/* ATONOffPos:
   "1" or "0". Indicates whether or not the ATON is on position or not */
-(void) setATONOffPos:(bool) val;
-(bool) getATONOffPos;
-(bool) hasATONOffPos;

-(void) setAttributes:(NSDictionary *)attributeDict;
-(NSString *) XML;
-(NSString *) stringValueWithLead:(NSString *) lead;

@end



