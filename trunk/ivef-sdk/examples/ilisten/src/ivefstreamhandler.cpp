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
    m_statistics = statistics;

    // should we use compression
    m_slipstream = slipstream;

    // setup the socket
    m_tcpSocket->connectToHost(host, port);

    // store some info for the login
    m_user = user;
    m_password = password;

#ifdef HAVE_ZLIB
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

    // read data
    QByteArray newData = m_tcpSocket->readAll();
    m_bytesIn += newData.size();
    QString outString;
    uint outBufferLen = 32768;

#ifdef HAVE_ZLIB
    if ( m_slipstream ) {
        if (inflateInit(&m_strm) != Z_OK) {
            std::cerr <<  "error initiating zlib stream" << std::endl;
        }

        // When there is still some left in the buffer from the previous message,
        // check if the new chunk is decompressible by itself.
        // If it is decompressible, we missed the complementary part of the left over
        // which we will ignore and continue with the new chunk
        if ( m_buffer.size() > 0 ) {
            m_strm.avail_in = newData.size();
            m_strm.next_in = reinterpret_cast<Bytef*> (newData.data());

            QByteArray outBuffer = QByteArray(outBufferLen, 0x00);
            m_strm.avail_out = outBuffer.size();
            m_strm.next_out = reinterpret_cast<Bytef*> (outBuffer.data());

            if ( inflate( &m_strm , Z_SYNC_FLUSH ) >= 0 ) {
                m_buffer.clear();
            }
            // Reset the state, or the error is preserved.
            inflateReset( &m_strm );
        }
        m_buffer.append( newData );

        // set decompression starting point at begin of m_buffer
        m_strm.avail_in = m_buffer.size();
        m_strm.next_in = reinterpret_cast<Bytef*> (m_buffer.data());

        int ret = 0;
        int prevAvailIn;

        do {
            // reset output buffer
            QByteArray outBuffer = QByteArray(outBufferLen, 0x00);
            m_strm.avail_out = outBuffer.size();
            m_strm.next_out = reinterpret_cast<Bytef*> (outBuffer.data());

            // remember avail_in before inflate so that we can keep a chunk that was decompressed without STREAM_END
            // in m_buffer.
            prevAvailIn = m_strm.avail_in;

            // reset decompressor stream
            // From zlib.h:
            // Initializes the internal stream state for decompression. [...]
            // All dynamically allocated data structures for this stream are freed.
            // This function discards any unprocessed input and does not flush any pending output.
            // Does not free and reallocate all the internal decompression state.
            //if ( inflateReset( &zlibStream ) != Z_OK ) //qDebug () << "Inflate reset error";
            if (ret != Z_OK)
                inflateReset( &m_strm );

            // decompress as much compressed data in m_buffer as possible
            // Note: will stop at end of each concatenated block of compressed data in the buffer
            ret = inflate( &m_strm, Z_SYNC_FLUSH );

            if ( ret < 0 ) {
                std::cerr << "Inflate error: " << ret << std::endl;
                m_buffer.clear();
            } else if ( ret == Z_OK && m_strm.avail_out == 0 ) {
                // Save the data in the outBuffer
                outString.append( outBuffer );
            } else if (ret > 0 ){
                // append decompressed data to output data if Z_STREAM_END (or Z_NEED_DICT) was returned
                outBuffer.resize( outBufferLen - m_strm.avail_out );
                outString.append( QString::fromUtf8(outBuffer) );
            }
        // repeat while (STREAM_END was not reached and out_buffer is full) or
        // (STREAM_END was reached, but there is still data in the in_buffer)
        } while ( ( ret == Z_OK && m_strm.avail_out == 0 ) || ( m_strm.avail_in > 0 && ret == Z_STREAM_END ) );

        // if decompressor processed all input, clear the buffer, otherwise keep what is left for the next run
        if ( m_strm.avail_in == 0 && ret == Z_STREAM_END ) {
            m_buffer.clear();
        }else if ( ret == Z_OK ) { // STREAM_END not reached, keep unfinished chunk for next run
            m_buffer = QByteArray( m_buffer.mid(m_buffer.size() - prevAvailIn) );
        }

        inflateEnd( &m_strm );
    }
    else
#endif // HAVE_ZLIB
    {
       outString = QString::fromUtf8(m_buffer);

       // clear the buffer
       m_buffer.resize(0);
    }

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
