#
# ilisten QMake pro file
#

TEMPLATE = app
TARGET = ilisten 
DEPENDPATH += ./src
INCLUDEPATH += ./include

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += ./include/cmdlineoption.h \
           ./include/ilistenapplication.h
SOURCES += ./src/cmdlineoption.cpp \
           ./src/ilistenapplication.cpp \
           ./src/main.cpp

# include the CPP library
INCLUDEPATH += ../sdk-cpp/include
LIBS += -L ../sdk-cpp/lib -lifev

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
}
