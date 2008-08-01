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

IVEFStreamHandler::IVEFStreamHandler() {

    // clear user/password
    m_user = "john doe";
    m_password = "very secret";
    m_log = NULL;
    
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

void IVEFStreamHandler::connectToServer(QString host, int port, QString user, QString password, QString logFileName) {

    QString portString;
    portString.setNum(port);
    std::cout << QString("iListen opening connection to %1:%2").arg(host, portString).toLatin1().data() << std::endl;

    // setup the socket
    m_tcpSocket->connectToHost(host, port);

    // store some info for the login
    m_user = user;
    m_password = password;

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
    } else {
        m_log = NULL;
    }
}

void IVEFStreamHandler::slotConnected() {
    std::cout << QString("iListen connection established logging in as %1").arg( m_user ).toLatin1().data() << std::endl;
    // we are connected, send the login first
    QString loginRequest = QString("<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n<MSG_LoginRequest xmlns=\"urn:http://www.hitt.nl/XMLSchema/ISIS/1.0\" >\n<Header MsgRefId=\"{97b13932-135e-47d7-b29e-25e5f6d7dd2d}\" Version=\"1.0\" />\n<Body>\n  <LoginRequest Name=\"%1\" Password=\"%2\" Encryption=\"plain\"/>\n</Body>\n</MSG_LoginRequest>\n").arg(m_user).arg(m_password);

    QByteArray data = loginRequest.toUtf8().trimmed();
    sendRawData(data);
}

void IVEFStreamHandler::sendRawData(const QByteArray &data) {
    //qDebug(data.data());
    m_tcpSocket->write(data);
    m_tcpSocket->flush();
}

void IVEFStreamHandler::slotDisconnected() {
    std::cout << "iListen connection lost" << std::endl;
    m_tcpSocket->close();
    std::exit(0);
}

void IVEFStreamHandler::slotReadyRead() {
    
    QString data = m_tcpSocket->readAll();
    
    ivefParser.parseXMLString(data, true);
    
    if (m_log != NULL) {   
       // remove xml header from message(s) the file needs it only once
       data.replace("<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n", ""); 
       data.replace("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", ""); 
       *m_log << data.toLatin1().data();
    }
}

