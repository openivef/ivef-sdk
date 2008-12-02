/*
 *  IVEFStreamHandler.h
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

#ifndef IVEFSTREAMHANDLER_H
#define IVEFSTREAMHANDLER_H

//#define HAVE_ZLIB

#include <iostream>

#include <QtCore>
#include <QtXml>
#include <QtNetwork>

#ifdef HAVE_ZLIB
#include "zlib.h"
#endif

#include "IVEFParser.h"

#define BUFFER_SIZE 1024*4

class IVEFStreamHandler : public QObject {
    Q_OBJECT

public:
    IVEFStreamHandler(Parser *parser);
    ~IVEFStreamHandler();

    void connectToServer(QString host, int port, QString user, QString password, QString logFileName, bool slipstream, bool statistics);

public slots:
    void slotStatisticsTimerFired();
    void slotDisconnected();
    void slotReadyRead();
    void slotConnected();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    bool feed();
    void sendRawData(const QByteArray &data);

    QTcpSocket  *m_tcpSocket;
    QTextStream *m_log;

    QString m_user;
    QString m_password;

    QByteArray m_buffer;
#ifdef HAVE_ZLIB
    z_stream m_strm;
#endif
    bool m_slipstream;
    bool m_statistics;
    long m_bytesIn;
    long m_bytesOut;
    

    Parser *m_parser;
};

#endif
