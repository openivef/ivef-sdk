/*
 *  IVEFStreamHandler.cpp
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

#include <cstdlib>

#include "ivefstreamhandler.h"

#define TIMER_INTERVAL 10

// Limit socket buffering and work per event-loop turn, not the size of an XML message.
const int RECEIVE_CHUNK_BYTES = 64 * 1024;
const int RECEIVE_BUFFER_BYTES = 256 * 1024;
const int RECEIVE_TIME_PER_TURN_MS = 10;

IVEFStreamHandler::IVEFStreamHandler(ivef::Parser *parser) {

    // clear user/password
    m_user = "john doe";
    m_password = "very secret";
    m_log = NULL;
    m_parser = parser;
    m_slipstream = false;
    m_statistics = false;
    m_bytesIn = 0;
    m_bytesOut = 0;
    m_inputClosed = false;
    m_receiveStopped = true;
#ifdef HAVE_ZLIB
    m_strm = {};
    m_inputOffset = 0;
    m_inflatePending = false;
    m_inflateInitialized = false;
#endif
    m_receiveTimer.setSingleShot(true);
    m_receiveTimer.setInterval(1);
    connect(&m_receiveTimer, SIGNAL(timeout()), this, SLOT(processReceive()));
    connect(this, SIGNAL(signalInputDrained()), this, SLOT(slotDisconnected()));

    // create a new socket
    m_tcpSocket = new QTcpSocket(this);
    m_tcpSocket->setReadBufferSize(RECEIVE_BUFFER_BYTES);

    connect(m_tcpSocket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
    connect(m_tcpSocket, SIGNAL(disconnected()),
            this, SLOT(finishReceive()));
    connect(m_tcpSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    connect(m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
#else
    connect(m_tcpSocket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
#endif
}

IVEFStreamHandler::~IVEFStreamHandler() {
    qDebug() << "IVEFStreamHandler in destructor";
    stopReceive();
    if (m_tcpSocket != NULL)
        delete(m_tcpSocket);
    if (m_log != NULL)
        delete(m_log);
}

void IVEFStreamHandler::displayError(QAbstractSocket::SocketError socketError) {

    switch (socketError) {
    case QAbstractSocket::ConnectionRefusedError:
        std::cout << "The connection was refused by the peer (or timed out)." << std::endl;
        break;
    case QAbstractSocket::RemoteHostClosedError:
        std::cout << "The remote host closed the connection." << std::endl;
        break;
    case QAbstractSocket::HostNotFoundError:
        std::cout << "The host address was not found." << std::endl;
        break;
    case QAbstractSocket::SocketAccessError:
        std::cout << "The socket operation failed because the application lacked the required privileges." << std::endl;
        break;
    case QAbstractSocket::SocketResourceError:
        std::cout << "The local system ran out of resources (e.g., too many sockets)." << std::endl;
        break;
    case QAbstractSocket::SocketTimeoutError:
        std::cout << "The socket operation timed out." << std::endl;
        break;
    case QAbstractSocket::NetworkError:
        std::cout << "An error occurred with the network (e.g., the network cable was accidentally plugged out)." << std::endl;
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        std::cout << "The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support)." << std::endl;
        break;
    default:
        std::cout << "An unidentified error occurred." << std::endl;
        break;
    }
}

void IVEFStreamHandler::connectToServer(QString host, int port, QString user, QString password, QString logFileName, bool slipstream, bool statistics) {

    stopReceive();
    m_receiveStopped = false;
    m_inputClosed = false;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    m_decoder.reset(QTextCodec::codecForName("UTF-8")->makeDecoder());
#else
    m_decoder = QStringDecoder(QStringDecoder::Utf8);
#endif

    QString portString;
    portString.setNum(port);
    std::cout << QString("iListen opening connection to %1:%2").arg(host, portString).toLatin1().data() << std::endl;

    // should we use keep track of line load
    m_statistics = statistics;

    // should we use compression
    m_slipstream = slipstream;

    // store some info for the login
    m_user = user;
    m_password = password;

#ifdef HAVE_ZLIB
    // setup decompression mechanism
    // we cannot use Qt for decompression since we do not know where the chunk starts or ends.
    if ( m_slipstream ) {
        m_strm = {};
        m_inflateInitialized = inflateInit(&m_strm) == Z_OK;
        if (!m_inflateInitialized) {
            failReceive("Error initiating zlib stream");
            return;
        }
    }
#else
    if (m_slipstream) {
        failReceive("Compression support is unavailable");
        return;
    }
#endif

    // set a timer to check the bytes in/out every minte
    if ( m_statistics ) {
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(slotStatisticsTimerFired()));
        timer->start(TIMER_INTERVAL*1000);
    }

    // setup the logstream if needed
    if (logFileName != "") {
        QFile* file = new QFile(logFileName);
        file->setParent(this); // make sure it gets cleaned up

        if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
            std::cerr << QString("iListen error opening file: %1 for writing").arg(logFileName).toLatin1().data() << std::endl;
            std::exit(1);
        }

        m_log = new QTextStream(file);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        m_log->setCodec("UTF-8");
#else
        m_log->setEncoding(QStringConverter::Utf8);
#endif
        *m_log << "<xml>\n"; // create a start tag
        m_log->flush();
    } else {
        m_log = NULL;
    }
    // setup the socket
    m_tcpSocket->connectToHost(host, port);
}

void IVEFStreamHandler::slotConnected() {
    std::cout << QString("iListen connection established logging in as %1").arg( m_user ).toLatin1().data() << std::endl;
    // we are connected, send the login first

    // create a message
    ivef::MSG_IVEF msg;

    // every message has a header
    ivef::Header header;
    header.setMsgRefId(QUuid::createUuid().toString());
    //header.setVersion("1.0");
    msg.setHeader(header);

    // and a body with the request
    ivef::Body body;
    ivef::LoginRequest request;
    request.setName(m_user);
    request.setPassword(m_password);
    request.setEncryption(1); // plain
    body.setLoginRequest(request);
    msg.setBody(body);

    // log
    //std::cout << msg.toXML().toLatin1().data() << std::endl;

    QByteArray data = msg.toXML().toUtf8();
    sendRawData(data);
}

void IVEFStreamHandler::sendRawData(const QByteArray &dataUnCompressed) {

    if ( m_slipstream ) {

        // compress the data using Qt Compression mechanism
        QByteArray dataCompressedPlusLen = qCompress(dataUnCompressed);

        // Qt wants to know the size, but zlib does not
        QByteArray dataCompressed = QByteArray(dataCompressedPlusLen.data() + 4, dataCompressedPlusLen.size() - 4);

        m_bytesOut += m_tcpSocket->write(dataCompressed);
    } else {
        m_bytesOut += m_tcpSocket->write(dataUnCompressed);
    }

    //qDebug(data.data());
    m_tcpSocket->flush();
}

void IVEFStreamHandler::slotDisconnected() {
    std::cout << "iListen connection lost" << std::endl;
    m_tcpSocket->close();
    std::exit(0);
}

void IVEFStreamHandler::slotReadyRead() {

    if (!m_receiveStopped && !m_receiveTimer.isActive())
        m_receiveTimer.start();
}

void IVEFStreamHandler::finishReceive() {

    if (m_receiveStopped)
        return;
    m_inputClosed = true;
    slotReadyRead();
}

void IVEFStreamHandler::stopReceive() {

    m_receiveStopped = true;
    m_receiveTimer.stop();
    m_inputClosed = false;
    m_parser->parseXMLString("", false);
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    m_decoder.reset();
#else
    m_decoder = QStringDecoder();
#endif
#ifdef HAVE_ZLIB
    if (m_inflateInitialized)
        inflateEnd( &m_strm );
    m_inflateInitialized = false;
    m_inflatePending = false;
    m_input.clear();
    m_inputOffset = 0;
#endif
}

void IVEFStreamHandler::failReceive(const QString &reason) {

    stopReceive();
    std::cerr << reason.toUtf8().constData() << std::endl;
    emit signalReceiveError(reason);
    m_tcpSocket->abort();
}

void IVEFStreamHandler::processReceive() {

    if (m_receiveStopped)
        return;
    QElapsedTimer elapsed;
    elapsed.start();
    int bytesRead = 0;
    int bytesFed = 0;
    while (!m_receiveStopped && bytesFed < RECEIVE_BUFFER_BYTES
           && elapsed.elapsed() < RECEIVE_TIME_PER_TURN_MS) {
#ifdef HAVE_ZLIB
        if ( m_inflatePending ) {
            QByteArray output(RECEIVE_CHUNK_BYTES, 0);
            m_strm.next_in = reinterpret_cast<Bytef*> (m_input.data() + m_inputOffset);
            m_strm.avail_in = m_input.size() - m_inputOffset;
            m_strm.next_out = reinterpret_cast<Bytef*> (output.data());
            m_strm.avail_out = output.size();
            const int result = inflate( &m_strm, Z_NO_FLUSH );
            m_inputOffset = m_input.size() - m_strm.avail_in;
            output.resize(output.size() - m_strm.avail_out);
            m_inflatePending = m_strm.avail_in > 0 || m_strm.avail_out == 0;
            if ( result == Z_STREAM_END ) {
                m_inflatePending = m_strm.avail_in > 0;
                if ( inflateReset( &m_strm ) != Z_OK ) {
                    failReceive("Invalid compressed stream");
                    return;
                }
            } else if ( result != Z_OK && !(result == Z_BUF_ERROR && !m_inflatePending) ) {
                failReceive("Invalid compressed stream");
                return;
            }
            bytesFed += output.size();
            feedBytes(output);
            continue;
        }
#endif
        if (m_tcpSocket->bytesAvailable() == 0 || bytesRead >= RECEIVE_BUFFER_BYTES)
            break;
        const QByteArray input = m_tcpSocket->read(RECEIVE_CHUNK_BYTES);
        if (input.isEmpty())
            break;
        bytesRead += input.size();
        m_bytesIn += input.size();
#ifdef HAVE_ZLIB
        if ( m_slipstream ) {
            m_input = input;
            m_inputOffset = 0;
            m_inflatePending = true;
            continue;
        }
#endif
        bytesFed += input.size();
        feedBytes(input);
    }
    if (m_receiveStopped)
        return;
    bool pending = m_tcpSocket->bytesAvailable() > 0;
#ifdef HAVE_ZLIB
    pending = pending || m_inflatePending;
#endif
    if (pending) {
        // Continue buffered work even when the peer sends no more bytes.
        slotReadyRead();
    } else if (m_inputClosed) {
        stopReceive();
        emit signalInputDrained();
    }
}

void IVEFStreamHandler::feedBytes(const QByteArray &data) {

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QString outString = m_decoder->toUnicode(data);
#else
    QString outString = m_decoder(data);
#endif
    m_parser->parseXMLString(outString, true);

    if (m_log != NULL) {
       // remove xml header from message(s) the file needs it only once
       outString.replace("<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n", "");
       outString.replace("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", "");
       *m_log << outString;
       m_log->flush();
    }
}

void IVEFStreamHandler::slotStatisticsTimerFired() {

    long bitsPerSecIn  = ((m_bytesIn * 8) / (TIMER_INTERVAL));
    long bitsPerSecOut = ((m_bytesOut * 8) / (TIMER_INTERVAL));
    long kBitsPerSecIn = bitsPerSecIn / 1024;
    long kBitsPerSecOut = bitsPerSecOut / 1024;

    std::cout << "iListen in = " << bitsPerSecIn << " bit/sec (" << kBitsPerSecIn << " kbits/sec) out = " << bitsPerSecOut << " bit/sec (" << kBitsPerSecOut << " kbits/sec)" << std::endl;
    m_bytesIn = 0;
    m_bytesOut = 0;
}
