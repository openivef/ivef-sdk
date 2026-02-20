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

QT += xml
VERSION = $$IVEF_VERSION

SOURCES += $$shell_path($$TARGET_QT_DIR/src/*.cpp)
HEADERS += $$shell_path($$TARGET_QT_DIR/include/*.h)

