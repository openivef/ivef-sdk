#
# testqt QMake pro file
#

TEMPLATE = app
TARGET = testqt 
DEPENDPATH += ./src
INCLUDEPATH += ./include

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += ./include/testqt.h 
	   
SOURCES += ./src/testqt.cpp \
           ./src/main.cpp

# include the CPP library
INCLUDEPATH += ../../build/targets/qt/src

CONFIG += warn_on stl qt release console
QT += network xml
macx {
   CONFIG -= app_bundle
   LIBS += -F../../build/targets/qt/lib -framework ivef
} else {
   LIBS += -L../../build/targets/qt/lib -Bstatic -livef

}
