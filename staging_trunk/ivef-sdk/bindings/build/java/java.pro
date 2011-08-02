######################################################################
# Build the JAVA binding
######################################################################
include(../../bindings.pri)

TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

jar.commands = \
        mkdir -p classes;\
        javac -d classes $$TARGET_JAVA_DIR/ivef/*java;\
        cd classes;\
        jar cf $$TARGET_JAVA_DIR/ivef/ivef.jar ivef/*

QMAKE_EXTRA_TARGETS += jar
PRE_TARGETDEPS += jar
QMAKE_CLEAN += classes/ivef/*
QMAKE_CLEAN += $$TARGET_JAVA_DIR/ivef/ivef.jar

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
