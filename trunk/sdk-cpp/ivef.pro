#
# ivef QMake pro file
#

TEMPLATE = lib
TARGET = ivef
DEPENDPATH += ./src
INCLUDEPATH += ./include

DESTDIR = lib
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += ./include/iveffilehandler.h \
           ./include/ivefhandler.h \
           ./include/ivefstreamhandler.h
SOURCES += ./src/iveffilehandler.cpp \
           ./src/ivefhandler.cpp \
           ./src/ivefstreamhandler.cpp

CONFIG += warn_on stl qt debug_and_release console
QT += network xml
macx {
   CONFIG -= app_bundle
}
