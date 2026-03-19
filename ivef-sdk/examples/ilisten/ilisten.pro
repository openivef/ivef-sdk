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

DEFINES += IVEF_SDK_VERSION=$$IVEF_SDK_VERSION
unix:DEFINES += HAVE_ZLIB

QT += network xml
greaterThan(QT_MAJOR_VERSION, 5) {
   QT += core5compat
}

# Read ZLIB_DIR from environment
ZLIB_DIR = $$(ZLIB_DIR)

macx {
   CONFIG -= app_bundle
   LIBS += -F$$IVEF_BUILD_DIR/targets/qt/lib -framework ivef
} else {
   LIBS += -L$$IVEF_BUILD_DIR/targets/qt/lib -livef1
   win32 {
      LIBS += -L$$ZLIB_DIR/lib
      LIBS += -lzlib
   } else {
      LIBS += -lz
   }
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

run.commands += echo "export LD_LIBRARY_PATH=$$IVEF_BUILD_DIR/targets/qt/lib" > $$IVEF_EXAMPLES_DIR/set_ld_library_path
 win32:run.commands += &
  unix:run.commands += ;

QMAKE_EXTRA_TARGETS += run
POST_TARGETDEPS += run
