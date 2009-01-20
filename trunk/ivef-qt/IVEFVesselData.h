/* 
 *  VesselData
 *
 *  VesselData is free software: you can redistribute it and/or modify
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
 *  Generated by xsd2code on Tue Jan 20 19:31:40 2009.
 **********************************************************************************
 *  Copyright 2008
 *
 */

#ifndef __VESSELDATA_H__
#define __VESSELDATA_H__

#include <QtCore>
#include "IVEFPosReport.h"
#include "IVEFStaticData.h"
#include "IVEFVoyage.h"

class VesselData : public QObject { 
    Q_OBJECT

public:
    VesselData();
    VesselData(const VesselData&);
    VesselData & operator=(const VesselData&/*val*/);
    void setPosReport(PosReport val);
    PosReport getPosReport() const;
    void addStaticData(StaticData val);
    StaticData getStaticDataAt(int i) const;
    int countOfStaticDatas() const;
    void addVoyage(Voyage val);
    Voyage getVoyageAt(int i) const;
    int countOfVoyages() const;
    QString toXML();
    QString toString(QString lead);

private:
    PosReport m_posReport;
    QVector<StaticData> m_staticDatas;
    QVector<Voyage> m_voyages;

}; 

#endif

