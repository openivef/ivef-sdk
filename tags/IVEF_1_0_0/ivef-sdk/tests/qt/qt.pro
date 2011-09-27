######################################################################
# Create test executable for Qt binding
######################################################################
include(../tests.pri)

DESTDIR = bin
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = app
TARGET = testqt 
DEPENDPATH += . include src
INCLUDEPATH += . include

# include the IVEF Qt library
INCLUDEPATH += $$IVEF_BUILD_DIR/targets/qt/include

#CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
   LIBS += -F$$IVEF_BUILD_DIR/targets/qt/lib -framework ivef
} else {
   LIBS += -L$$IVEF_BUILD_DIR/targets/qt/lib -livef1
}

# Input
HEADERS += ./include/testqt.h

SOURCES += ./src/testqt.cpp \
           ./src/main.cpp
