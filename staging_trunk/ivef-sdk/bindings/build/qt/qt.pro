######################################################################
# Build the Qt binding
######################################################################
include(../../bindings.pri)

TARGET_QT_DIR = $$IVEF_TARGETS_DIR/qt

DESTDIR = $$TARGET_QT_DIR/lib
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = ivef
INCLUDEPATH += $$TARGET_QT_DIR/include

QT += xml
VERSION = $$IVEF_VERSION

SOURCES += $$TARGET_QT_DIR/src/*.cpp
HEADERS += $$TARGET_QT_DIR/include/*.h

