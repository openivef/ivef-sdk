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

IVEFStreamHandler::IVEFStreamHandler(Parser *parser) {

    // clear user/password
    m_user = "john doe";
    m_password = "very secret";
    m_log = NULL;
    m_parser = parser;
    m_slipstream = false;
    m_statistics = false;
    m_bytesIn = 0;
    m_bytesOut = 0;

    // create a new socket
    m_tcpSocket = new QTcpSocket(this);

    connect(m_tcpSocket, SIGNAL(connected()),
            this, SLOT(slotConnected()));
    connect(m_tcpSocket, SIGNAL(disconnected()),
            this, SLOT(slotDisconnected()));
    connect(m_tcpSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadyRead()));
    connect(m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

IVEFStreamHandler::~IVEFStreamHandler() {
    qDebug() << "IVEFStreamHandler in destructor";
    if (m_tcpSocket != NULL)
        delete(m_tcpSocket);
    if (m_log != NULL)
        delete(m_log);

#ifdef HAVE_ZLIB
    // cleanup compression
    if ( m_slipstream ) {
        inflateEnd(&m_strm);
    }
#endif
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


    QString portString;
    portString.setNum(port);
    std::cout << QString("iListen opening connection to %1:%2").arg(host, portString).toLatin1().data() << std::endl;

    // should we use keep track of line load
    m_statistics = statistics;;

    // should we use compression
    m_slipstream = slipstream;

    // setup the socket
    m_tcpSocket->connectToHost(host, port);

    // store some info for the login
    m_user = user;
    m_password = password;

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
        m_log->setCodec("UTF-8");
        *m_log << "<xml>\n"; // create a start tag
        m_log->flush();
    } else {
        m_log = NULL;
    }
}

void IVEFStreamHandler::slotConnected() {
    std::cout << QString("iListen connection established logging in as %1").arg( m_user ).toLatin1().data() << std::endl;
    // we are connected, send the login first

    // create a message
    MSG_LoginRequest msg;

    // every message has a header
    Header header;
    header.setMsgRefId(QUuid::createUuid());
    header.setVersion("1.0");
    msg.setHeader(header);

    // and a body with the request
    Body body;
    LoginRequest request;
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

    // read data
    QByteArray newData = m_tcpSocket->readAll();
    m_bytesIn += newData.size();
    m_buffer.append( newData );
    QString data;

#ifdef HAVE_ZLIB
    if ( m_slipstream ) {
        // setup decompression mechanism
        // we cannot use Qt for decompression since we do not know where the chunk starts or ends.
        if ( m_slipstream ) {
            m_strm.zalloc = Z_NULL;
            m_strm.zfree = Z_NULL;
            m_strm.opaque = Z_NULL;
            m_strm.avail_in = 0;
            m_strm.next_in = Z_NULL;
            if (inflateInit(&m_strm) != Z_OK) {
                std::cout << "iListen error initiating zlib stream" << std::endl;
            }
        }

        // compress reasonable chunks at the time
        if ( m_buffer.size() < 16382 ) {
            return;
        }

        // connect the input to zlib
        m_strm.avail_in = m_buffer.size();
        m_strm.next_in = (uchar*) m_buffer.data();

        // create a buffer for the output
        int compressedLen = m_buffer.size();
        int bufferLen = compressedLen * 20;
        QByteArray dataUnCompressed = QByteArray(bufferLen, 0x00);

        // we run inflate on the buffer until it will fit in the dataUnCompressed
        // (probably 1 run, but in case it doesn't fit, we will reuse the buffer)
        int ret;
        do {
            // connect the output to zlib
            m_strm.avail_out = bufferLen;
            m_strm.next_out = (uchar*) dataUnCompressed.data();

            // inflate the data
            ret = inflate(&m_strm, Z_SYNC_FLUSH);
            if (( ret != Z_OK ) && (ret != Z_STREAM_END)) {
                std::cerr << "Slipstream decompresion error " << ret << std::endl;
                ret = Z_STREAM_END; // close and try again
            }

            // how much data did we recover
            int uncompressedLen = bufferLen - m_strm.avail_out;
            dataUnCompressed.resize(uncompressedLen);

            // debug the efficiency
            std::cout << "Slipstream of " << compressedLen << " bytes, inflated to " << uncompressedLen << std::endl;

            // parse the chunk
            //std::cout << "\n\n" << QString(dataUnCompressed).toLatin1().data() << "\n\n";
            m_parser->parseXMLString(dataUnCompressed, true);

            // append the uncompressed data to the logging string
            data.append( dataUnCompressed );
          
            // check if we used the entire output buffer, so there may be some input left
            // which we can process in a second run
        } while (ret == Z_OK && m_strm.avail_out == 0); 

        // in case compression is complete, we must close the decompressor
        // and re-initialize it for the next transfer
        if ( ret == Z_STREAM_END ) {
            if (inflateReset(&m_strm) != Z_OK) {
                std::cerr << "iListen error initiating zlib stream" << std::endl;
            }
        }

    }
#endif  // HAVE_ZLIB 

    if ( !m_slipstream ) {
        m_parser->parseXMLString(m_buffer, true);
        data = QString::fromUtf8(m_buffer);
    }

    // clear the buffer
    m_buffer.resize(0);

    if (m_log != NULL) {
        // remove xml header from message(s) the file needs it only once
        data.replace("<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n", "");
        data.replace("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", "");
        *m_log << data;
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
