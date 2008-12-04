#include <iostream>
#include "httpdaemon.h"

HttpDaemon::HttpDaemon( QObject* parent, int port, QMap<int, VesselData> *trackStore ) :
QTcpServer(parent)
{ 
    m_trackStore =  trackStore;
    listen(QHostAddress::Any, port);
    if ( !isListening() ) {
        qWarning("Failed to bind to port "+port);
        exit( 1 );
    }
    // required?
    connect( this, SIGNAL(newConnection()), this, SLOT(newConnection() ) );
}

void HttpDaemon::newConnection()
{
    // When a new client connects, the server constructs a QTcpSocket and all
    // communication with the client is done over this QTcpSocket. QTcpSocket
    // works asynchronouslyl, this means that all the communication is done
    // in the two slots readClient() and discardClient().
    QTcpSocket* s = nextPendingConnection();
    connect( s, SIGNAL(readyRead()), this, SLOT(readClient()) );
    connect( s, SIGNAL(disconnected()), this, SLOT(discardClient()) );
    emit newConnect();
}

void HttpDaemon::readClient()
{
    // This slot is called when the client sent data to the server. The
    // server looks if it was a get request and sends a very simple HTML
    // document back.
    QTcpSocket* socket = (QTcpSocket*)sender();
    if ( socket->canReadLine() ) {
        QStringList tokens = QString(socket->readLine()).split( QRegExp("[ \r\n][ \r\n]*" ) );
        if ( tokens[0] == "GET" ) {
            QTextStream os( socket );
            os.setCodec( QTextCodec::codecForName("UTF-8") );

            // write the header
            os << "HTTP/1.0 200 Ok\r\n"
                "Content-Type: text/html; charset=\"utf-8\"\r\n"
                "\r\n";
            // write the content
            os << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
                  "<kml xmlns=\"http://www.opengis.net/kml/2.2\">\r\n"
                  "<Document>\r\n"
		  "<Style id=\"ivefDefault\">\r\n"
	          "   <IconStyle>\r\n"
	          "     <Icon>\r\n"
	          "       <href>http://maps.google.com/mapfiles/kml/shapes/ferry.png</href>\r\n"
	          "     </Icon>\r\n"
	          "   </IconStyle>\r\n"
	          "</Style>\r\n"
		  "<Folder>\r\n"
		  "  <name>IVEF Tracks</name>\r\n";

           std::cout << "Serving tracks: " << m_trackStore->count() << std::endl;
           QMapIterator<int, VesselData> i(*m_trackStore);
           while (i.hasNext()) {
                i.next();
                VesselData vessel = i.value();
   
                //QString str = vessel.toString("");
                //std::cout << str.toLatin1().data() << std::endl;

                os << "  <Placemark>\r\n"
             	      "      <name>";
            
                if ( vessel.countOfStaticDatas() > 0) {
                   StaticData plan = vessel.getStaticDataAt(0);
                   if (plan.hasShipName()) {
                      os << plan.getShipName();
                   } else {
                      os << plan.getId();
                   }
                } else {
                      os << vessel.getPosReport().getId();
                }

                os << "</name>\r\n"
             	      "      <Point>\r\n"
             	      "	        <coordinates>";
                os << vessel.getPosReport().getPos().getLong();
                os << ",";
                os << vessel.getPosReport().getPos().getLat();
                os << ",0</coordinates>\r\n" // should check for altitude
             	      "	     </Point>\r\n"
                      "      <styleUrl>#ivefDefault</styleUrl>\r\n" // should base icon on shiptype
             	      "   </Placemark>\r\n";
            }
	    os << " </Folder>\r\n"
                  "</Document>\r\n"
                  "</kml>\r\n";

            // close the connection
            socket->close();
            emit wroteToClient();
        }
    }
}

void HttpDaemon::discardClient()
{
    emit endConnect();
}
