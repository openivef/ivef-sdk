#
# ilisten QMake pro file
#

TEMPLATE = app
TARGET = ilisten 
DEPENDPATH += . src
INCLUDEPATH += . src

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += src/cmdlineoption.h \
           src/ilistenapplication.h \
           src/iveffilehandler.h \
           src/ivefhandler.h \
           src/IVEFStreamHandler.h
SOURCES += src/cmdlineoption.cpp \
           src/ilistenapplication.cpp \
           src/iveffilehandler.cpp \
           src/ivefhandler.cpp \
           src/IVEFStreamHandler.cpp \
           src/main.cpp

CONFIG += warn_on stl qt release
QT += network xml
