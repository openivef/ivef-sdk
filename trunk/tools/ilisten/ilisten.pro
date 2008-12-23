#
# ilisten QMake pro file
#

TEMPLATE = app
TARGET = ilisten 
LIBS += -Bstatic
DEPENDPATH += ./src
INCLUDEPATH += ./include

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += ./include/cmdlineoption.h \
           ./include/ilistenapplication.h \
           ./include/ivefstreamhandler.h \
           ./include/iveffilehandler.h 
SOURCES += ./src/cmdlineoption.cpp \
           ./src/ilistenapplication.cpp \
           ./src/ivefstreamhandler.cpp \
           ./src/iveffilehandler.cpp \
           ./src/main.cpp

# include the CPP library
INCLUDEPATH += ../../ivef-qt
LIBS += -L ../../ivef-qt/bin -Bstatic -livef

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
}
