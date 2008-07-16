#
# ilisten QMake pro file
#

TEMPLATE = app
TARGET = ilisten 
DEPENDPATH += . src
INCLUDEPATH += . src

DESTDIR = bin
MOC_DIR = tmp/moc
OBJECTS_DIR = tmp/objects

HEADERS += src/CmdLineOption.h \
           src/iListenApplication.h \
           src/IVEFFileHandler.h \
           src/IVEFHandler.h \
           src/IVEFStreamHandler.h
SOURCES += src/CmdLineOption.cpp \
           src/iListenApplication.cpp \
           src/IVEFFileHandler.cpp \
           src/IVEFHandler.cpp \
           src/IVEFStreamHandler.cpp \
           src/main.cpp

CONFIG += warn_on stl qt release
QT += network xml
