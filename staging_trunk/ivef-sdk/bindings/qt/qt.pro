######################################################################
# Build the Qt binding
######################################################################
include(../bindings.pri)

TARGET_QT_DIR = $$IVEF_TARGETS_DIR/qt

! exists( $$TARGET_QT_DIR ) {
    message(Create build target dir: $$TARGET_QT_DIR)
    unix:system( mkdir $$TARGET_JAVA_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\qt )
}

gentarget.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --qt --out=$$TARGET_QT_DIR --prefix=IVEF
# This makes the command run before anything else
gentarget.CONFIG += target_predeps

PRE_TARGETDEPS += gentarget
QMAKE_EXTRA_TARGETS += gentarget

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

