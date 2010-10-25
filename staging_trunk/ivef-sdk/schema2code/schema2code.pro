include(../ivef-sdk.pri)

BUILD_DIR = ../$$IVEF_BUILD_DIR
TMP_DIR = ../$$IVEF_BUILD_DIR/tmp
DESTDIR = $$BUILD_DIR/bin
MOC_DIR = $$TMP_DIR/moc
OBJECTS_DIR = $$TMP_DIR/obj

TEMPLATE = app
TARGET = $$IVEF_GENERATOR_BIN
DEPENDPATH += . src
INCLUDEPATH += . include

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
}

HEADERS += ./include/cmdlineoption.h \
           ./include/mainapp.h \
           ./include/handler.h \
           ./include/xsdobject.h \
           ./include/xsdattribute.h \
           ./include/codegen.h \
           ./include/codegenpb.h \
           ./include/codegenqt.h \
           ./include/codegenphp.h \
           ./include/codegenobjc.h \
           ./include/codegenjava.h

SOURCES += ./src/cmdlineoption.cpp \
           ./src/mainapp.cpp \
           ./src/handler.cpp \
           ./src/xsdobject.cpp \
           ./src/xsdattribute.cpp \
           ./src/codegenpb.cpp \
           ./src/codegenphp.cpp\
           ./src/codegenqt.cpp \
           ./src/codegenobjc.cpp \
           ./src/codegenjava.cpp \
           ./src/main.cpp

