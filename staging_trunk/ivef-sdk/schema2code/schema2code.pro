include(../ivef-sdk.pri)

BUILD_DIR = ../$$IVEF_BUILD_DIR
TMP_DIR = ../$$IVEF_BUILD_DIR/tmp
DESTDIR = $$BUILD_DIR/bin
MOC_DIR = $$TMP_DIR/moc
OBJECTS_DIR = $$TMP_DIR/obj

TEMPLATE = app
TARGET = $$IVEF_GENERATOR_BIN
DEPENDPATH += . src
INCLUDEPATH += . src

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
}

HEADERS += src/cmdlineoption.h \
           src/mainapp.h \
           src/handler.h \
	   src/xsdobject.h \
	   src/xsdattribute.h \
	   src/codegen.h \
	   src/codegenpb.h \
	   src/codegenqt.h \
	   src/codegenphp.h\
	   src/codegenobjc.h\
	   src/codegenjava.h

SOURCES += src/cmdlineoption.cpp \
           src/mainapp.cpp \
           src/handler.cpp \
	   src/xsdobject.cpp \
	   src/xsdattribute.cpp \
	   src/codegenpb.cpp \
	   src/codegenphp.cpp\
	   src/codegenqt.cpp \
	   src/codegenobjc.cpp \
	   src/codegenjava.cpp \
           src/main.cpp

