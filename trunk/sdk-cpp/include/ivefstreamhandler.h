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

#include <iostream>

#include <QtCore>
#include <QtXml>
#include <QtNetwork>

#include "ivefhandler.h"

#define BUFFER_SIZE 1024*4

class IVEFStreamHandler : public QObject {
    Q_OBJECT

public:
    IVEFStreamHandler();
    ~IVEFStreamHandler();

    void connectToServer(QString host, int port, QString user, QString password, QString logFileName);

public slots:
    void slotDisconnected();
    void slotReadyRead();
    void slotConnected();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    bool feed();
    void sendRawData(const QByteArray &data);

    QTcpSocket  *m_tcpSocket;
    QTextStream *m_log;
    IVEFHandler *m_handler;

    QString m_user;
    QString m_password;

    QXmlSimpleReader m_reader;
    QString          m_dataBuffer;
};

#endif