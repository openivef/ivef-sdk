/*
 *
 *  ivef2kml is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ivef2kml is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  Created by Lukassen on 11/06/08.
 *  Copyright 2008
 *
 */
 

#include <stdlib.h>
#include <QtCore>
#include <QtNetwork>
#include "IVEFVesselData.h"

// HttpDaemon is the the class that implements the simple HTTP server.
class HttpDaemon : public QTcpServer {
    Q_OBJECT
public:
    HttpDaemon( QObject* parent, int port, QMap<int, VesselData> *trackStore );

signals:
    void newConnect();
    void endConnect();
    void wroteToClient();

private slots:
    void newConnection();
    void readClient();
    void discardClient();

private:
    void writeHeader(QTextStream &os);
    void writeDescription(QTextStream &os, VesselData vessel);
    void writeIcon(QTextStream &os, VesselData vessel);
    QMap<int, VesselData> *m_trackStore;
};
