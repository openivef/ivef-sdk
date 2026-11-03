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
#include <memory>

#include <QtCore>
#include <QtXml>
#include <QtNetwork>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QTextCodec>
#else
#include <QStringDecoder>
#endif

#ifdef HAVE_ZLIB
#include "zlib.h"
#endif

#include "IVEFParser.h"

#define BUFFER_SIZE 1024*4

class IVEFStreamHandler : public QObject {
    Q_OBJECT

public:
    //! The parser must outlive this handler; its partial input is reset on stop/reconnect.
    IVEFStreamHandler(ivef::Parser *parser);
    ~IVEFStreamHandler();

    void connectToServer(QString host, int port, QString user, QString password, QString logFileName, bool slipstream, bool statistics);

    //! Cancel queued reception and discard connection-specific XML, UTF-8 and zlib state.
    void stopReceive();

signals:
    //! Emitted after complete messages buffered at remote EOF have been delivered.
    void signalInputDrained();
    //! Emitted on receive setup failure or invalid compressed input; stops until reconnect.
    void signalReceiveError(const QString &reason);

public slots:
    void slotStatisticsTimerFired();
    void slotDisconnected();
    void slotReadyRead();
    void slotConnected();
    void displayError(QAbstractSocket::SocketError socketError);
    //! Drain buffered input before signalling disconnection; incomplete XML is discarded.
    void finishReceive();

private slots:
    void processReceive();

private:
    void sendRawData(const QByteArray &data);
    //! Decode incrementally so UTF-8 characters may span TCP reads or inflate chunks.
    void feedBytes(const QByteArray &data);
    void failReceive(const QString &reason);

    QTcpSocket  *m_tcpSocket;
    QTextStream *m_log;

    QString m_user;
    QString m_password;

    // Yield between bounded batches, including when no further readyRead signal arrives.
    QTimer m_receiveTimer;
    // Remote EOF has arrived; deliver remaining complete messages before notifying clients.
    bool m_inputClosed;
    // Prevent socket signals or queued work from restarting reception after cancellation.
    bool m_receiveStopped;
    // Decoder state retains a UTF-8 character split across successive byte chunks.
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    std::unique_ptr<QTextDecoder> m_decoder;
#else
    QStringDecoder m_decoder;
#endif
#ifdef HAVE_ZLIB
    // Current compressed read and its consumption offset; old input is never re-inflated.
    QByteArray m_input;
    int m_inputOffset;
    // Input or output remains to be inflated before reading another socket chunk.
    bool m_inflatePending;
    // Whether m_strm owns zlib state that must be released with inflateEnd.
    bool m_inflateInitialized;
    // Retained between reads, reset only at the end of a concatenated zlib stream.
    z_stream m_strm;
#endif
    bool m_slipstream;
    bool m_statistics;
    long m_bytesIn;
    long m_bytesOut;


    ivef::Parser *m_parser;
};

#endif
