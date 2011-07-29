######################################################################
# ilisten example
######################################################################
include(../examples.pri)

DESTDIR = $$IVEF_EXAMPLES_DIR
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = app
TARGET = ilisten
DEPENDPATH += . include src
INCLUDEPATH += . include

# include the IVEF Qt library
INCLUDEPATH += $$IVEF_BUILD_DIR/targets/qt/include

DEFINES += VERSION=$$IVEF_VERSION
unix:DEFINES += HAVE_ZLIB

#CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
   LIBS += -F$$IVEF_BUILD_DIR/targets/qt/lib -framework ivef
} else {
   win32:LIBS += -L$$IVEF_BUILD_DIR/targets/qt/lib -livef0
   unix:LIBS += -L$$IVEF_BUILD_DIR/targets/qt/lib -livef
}

# Input
HEADERS += include/cmdlineoption.h \
           include/ilistenapplication.h \
           include/iveffilehandler.h \
           include/ivefstreamhandler.h
SOURCES += src/cmdlineoption.cpp \
           src/ilistenapplication.cpp \
           src/iveffilehandler.cpp \
           src/ivefstreamhandler.cpp \
           src/main.cpp
