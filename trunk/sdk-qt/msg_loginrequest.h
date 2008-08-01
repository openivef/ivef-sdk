/* 
 *  MSG_LoginRequest
 *
 *  MSG_LoginRequest is free software: you can redistribute it and/or modify
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
 *  Generated by xsd2code on Wed Jul 30 17:01:59 2008.
 **********************************************************************************
 *  Copyright 2008
 *
 */

#ifndef __MSG_LOGINREQUEST_H__
#define __MSG_LOGINREQUEST_H__

#include <QtCore>
#include "header.h"
#include "body.h"

class MSG_LoginRequest : QObject { 
    Q_OBJECT

public:
    MSG_LoginRequest();
    MSG_LoginRequest(const MSG_LoginRequest&);
    MSG_LoginRequest & operator=(const MSG_LoginRequest&/*val*/);
    void setHeader(Header val);
    Header getHeader();
    void setBody(Body val);
    Body getBody();
    QString toXML();

private:
    Header m_header;
    Body m_body;

}; 

#endif
