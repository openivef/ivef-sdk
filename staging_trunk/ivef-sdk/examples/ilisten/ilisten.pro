######################################################################
# ilisten example
######################################################################
include(../examples.pri)

DESTDIR = ../$$EXAMPLE_DEST_DIR
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = app
TARGET = ilisten
DEPENDPATH += . include src
INCLUDEPATH += . include

# include the IVEF Qt library
INCLUDEPATH += ../../$$IVEF_BUILD_DIR/targets/qt/src

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
   LIBS += -F../../$$IVEF_BUILD_DIR/targets/qt/lib -framework ivef
} else {
   LIBS += -L../../$$IVEF_BUILD_DIR/targets/qt/lib -Bstatic -livef
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
