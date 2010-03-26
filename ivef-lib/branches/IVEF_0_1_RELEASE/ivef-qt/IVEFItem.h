/* 
 *  Item
 *
 *  Item is free software: you can redistribute it and/or modify
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
 *  Generated by xsd2code on Fri Mar 26 13:53:21 2010.
 **********************************************************************************
 *  Copyright 2010
 *
 */

#ifndef __ITEM_H__
#define __ITEM_H__

#include <QtCore>

//-----------------------------------------------------------
//! \brief       Class definition of Item
//!
//! 
//!

class Item : public QObject { 
    Q_OBJECT

public:
    //!constructor
    //!
    Item();
    //!copy constructor
    //!
    Item(const Item&);
    //!= operator
    //!
    Item & operator=(const Item&/*val*/);
    //!              sets the Element: Describes requested Vessel data element, possible values:\n
    //!              1 = position\n
    //!              2 = static data\n
    //!              3 = voyage
    //!
    void setElement(int val);

    //!              gets the Element: Describes requested Vessel data element, possible values:\n
    //!              1 = position\n
    //!              2 = static data\n
    //!              3 = voyage
    //!
    //! \return     int
    //!
    int getElement() const;

    //!              sets the Field: Selected field. Can be 'all' or one of the items of vessel data PositionReport, Static Data  or Voyage
    //!
    void setField(QString val);

    //!              gets the Field: Selected field. Can be 'all' or one of the items of vessel data PositionReport, Static Data  or Voyage
    //!
    //! \return     QString
    //!
    QString getField() const;

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
    int m_element;
    QString m_field;

}; 

#endif

