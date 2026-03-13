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

QT += network xml
greaterThan(QT_MAJOR_VERSION, 5) {
   QT += core5compat
}
macx {
   CONFIG -= app_bundle
   LIBS += -F$$IVEF_BUILD_DIR/targets/qt/lib -framework ivef
} else {
   LIBS += -L$$IVEF_BUILD_DIR/targets/qt/lib -livef1 -lz
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

mkoutdir.commands = $$QMAKE_MKDIR $$shell_quote($$IVEF_EXAMPLES_DIR)

QMAKE_EXTRA_TARGETS += mkoutdir
PRE_TARGETDEPS += mkoutdir

run.commands += echo "export LD_LIBRARY_PATH=$$IVEF_BUILD_DIR/targets/qt/lib" > $$IVEF_EXAMPLES_DIR/set_ld_library_path
 win32:run.commands += &
  unix:run.commands += ;

QMAKE_EXTRA_TARGETS += run
POST_TARGETDEPS += run
