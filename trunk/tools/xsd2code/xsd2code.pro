#
# ilisten QMake pro file
#

TEMPLATE = app
TARGET = xsd2code 
DEPENDPATH += . src
INCLUDEPATH += . src

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += src/cmdlineoption.h \
           src/mainapp.h \
           src/handler.h \
		   src/xsdobject.h \
		   src/xsdattribute.h \
		   src/codegen.h \
		   src/codegenqt.h
SOURCES += src/cmdlineoption.cpp \
           src/mainapp.cpp \
           src/handler.cpp \
		   src/xsdobject.cpp \
		   src/xsdattribute.cpp \
		   src/codegenqt.cpp \
           src/main.cpp

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
}
