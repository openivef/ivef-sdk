#
# ivef2kml QMake pro file
#

TEMPLATE = app
TARGET = ivef2kml 
DEPENDPATH += ./src
INCLUDEPATH += ./include

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += ./include/cmdlineoption.h \
           ./include/httpdaemon.h \
           ./include/ivef2kmlapplication.h \
           ./include/ivefstreamhandler.h 
	   
SOURCES += ./src/cmdlineoption.cpp \
           ./src/httpdaemon.cpp \
           ./src/ivef2kmlapplication.cpp \
           ./src/ivefstreamhandler.cpp \
           ./src/main.cpp

# include the CPP library
INCLUDEPATH += ../../ivef-qt
LIBS += -L ../../ivef-qt/bin -Bstatic -livef

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
}
