######################################################################
# Build the Qt binding
######################################################################
include(../../bindings.pri)

TARGET_QT_DIR = $$IVEF_TARGETS_DIR/qt

DESTDIR = $$TARGET_QT_DIR/lib
MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
 win32:TARGET = ivef
  unix:TARGET = ivef1
build_pass:CONFIG(debug, debug|release) {
 win32:TARGET = $$join(TARGET,,,d)
}
INCLUDEPATH += $$TARGET_QT_DIR/include

DEFINES += SCHEMAIVEF_BUILD
staticlib:DEFINES += SCHEMAIVEF_BUILD_STATIC
!staticlib:CONFIG += dll

QT += xml
VERSION = $$IVEF_VERSION

message("TARGET_QT_DIR = $$TARGET_QT_DIR")
message("SOURCES files = $$files($$TARGET_QT_DIR/src/*.cpp)")

SOURCES += $$files($$TARGET_QT_DIR/src/*.cpp)
HEADERS += $$files($$TARGET_QT_DIR/include/*.h)
