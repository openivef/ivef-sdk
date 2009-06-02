/*
 *  CmdLineOption.h
 *
 *  iListen is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Created by Lukassen on 11/06/08.
 *  Copyright 2008
 *
 */

#ifndef __HCMDLINEOPTION_H__
#define __HCMDLINEOPTION_H__

#include <QString>
#include <QMap>

class CmdLineOption {

public:
    enum Types { BOOLEAN=1, INTEGER, TEXT };
    union dataType {
        int i;
        bool b;
        QString *s;
    };
    CmdLineOption() {
        m_Set = false;
    }
    CmdLineOption( Types, const char *, const char * );
    QString getHelpText( void );
    Types getType() const;
    bool isSet() const {
        return m_Set;
    }
    const QString &getFieldName() {
        return m_FieldName;
    }
    const union dataType &getValue() const {
            return m_FieldData;
        }
    void setVal( bool );
    void setVal( int );
    void setVal( QString );
    void reset( void );

private:
    QString m_FieldName;
    QString m_HelpText;
    Types m_FieldType;
    union dataType m_FieldData;
    bool m_Set;
};

class CmdLineOptions {
public:
    CmdLineOptions() {
        m_Options.clear();
    }
    ~CmdLineOptions();
    void append( CmdLineOption o );
    void parse( int &argc, char **argv );
    bool getBoolean( const QString & );
    bool getText( const QString &, QString & );
    bool getInteger( const QString &, int & );
    void printHelp( void );

private:
    QMap<QString, CmdLineOption> m_Options;
};

#endif
