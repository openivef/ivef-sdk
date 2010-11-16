######################################################################
# Build the Qt binding
######################################################################
include(../bindings.pri)

INPUT_DIR=../$$GENERATOR_TARGET_DIR/qt

DESTDIR = ../$$GENERATOR_TARGET_DIR/qt/lib
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = ivef
INCLUDEPATH += $$INPUT_DIR/include

QT += xml
VERSION = $$IVEF_VERSION

# Input
MY_SOURCES = $$system( ls $$INPUT_DIR/src/*.cpp )
MY_HEADERS = $$system( ls $$INPUT_DIR/include/*.h )

SOURCES += $$MY_SOURCES
HEADERS += $$MY_HEADERS

