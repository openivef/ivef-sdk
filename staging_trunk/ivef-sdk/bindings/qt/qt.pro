include(../bindings.pri)

INPUT_DIR=../$$GENERATOR_TARGET_DIR/qt/src
MOC_DIR = ../$$GENERATOR_TARGET_DIR/qt/moc
OBJECTS_DIR = ../$$GENERATOR_TARGET_DIR/qt/obj

MY_SOURCES = $$system(ls $$INPUT_DIR/*.cpp)
MY_HEADERS = $$system(ls $$INPUT_DIR/*.h)
SOURCES += $$MY_SOURCES
HEADERS += $$MY_HEADERS
TARGET = ivef
TEMPLATE = lib
QT += xml
VERSION = 1.3.86
DESTDIR = ../$$GENERATOR_TARGET_DIR/qt/lib

mytarget.target = .buildfile
mytarget.commands = echo "hello you!"
mytarget.depends = ivef
QMAKE_EXTRA_TARGETS += mytarget

