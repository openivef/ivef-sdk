######################################################################
# Build the Qt binding
######################################################################
include(../bindings.pri)

INPUT_DIR=../$$GENERATOR_TARGET_DIR/qt/src

DESTDIR = ../$$GENERATOR_TARGET_DIR/qt/lib
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = ivef

QT += xml
VERSION = 1.3.86

# Input
MY_SOURCES = $$system( ls $$INPUT_DIR/*.cpp )
MY_HEADERS = $$system( ls $$INPUT_DIR/*.h )

SOURCES += $$MY_SOURCES
HEADERS += $$MY_HEADERS

