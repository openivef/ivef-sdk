/* 
 *  MSG_ServerStatus
 *
 *  MSG_ServerStatus is free software: you can redistribute it and/or modify
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
 *  Generated by xsd2code on Thu Apr 15 16:04:58 2010.
 **********************************************************************************
 *  Copyright 2010
 *
 */

#ifndef __MSG_SERVERSTATUS_H__
#define __MSG_SERVERSTATUS_H__

#include <QtCore>
#include "IVEFHeader.h"
#include "IVEFBody.h"

//-----------------------------------------------------------
//! \brief       Class definition of MSG_ServerStatus
//!
//! MESSAGE sent by the supplier in case the server is experienceing / recovering from load problems
//!

class MSG_ServerStatus : public QObject { 
    Q_OBJECT

public:
    //!constructor
    //!
    MSG_ServerStatus();
    //!copy constructor
    //!
    MSG_ServerStatus(const MSG_ServerStatus&);
    //!= operator
    //!
    MSG_ServerStatus & operator=(const MSG_ServerStatus&/*val*/);
    //!              sets the Header
    //!
    void setHeader(Header val);

    //!              gets the Header
    //!
    //! \return     Header
    //!
    Header getHeader() const;

    //!              sets the Body
    //!
    void setBody(Body val);

    //!              gets the Body
    //!
    //! \return     Body
    //!
    Body getBody() const;

    //!              generates XML of this object including attributes and child elements
    //!
    //! \return     QString
    QString toXML();

    //!              generates output of this object including attributes and child elements
    //!
    //! \return     QString
    QString toString();

    //!              generates output of this object including attributes and child elements
    //!
    //! \return     QString
    QString toString(QString lead);

    //!              encodes a string returning the encoded string
    //!
    //! \return     QString
    QString encode(QString str);


private:
    Header m_header;
    Body m_body;

}; 

#endif

