######################################################################
# Build the JAVA binding
######################################################################
include(../../bindings.pri)

TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( classes ) {
    system( mkdir classes )
}

win32|system( which javac 1>/dev/null 2>&1 ){
   CONFIG += javac
}

javac {
    jar.commands += javac -d classes $$TARGET_JAVA_DIR/ivef/*java
     win32:jar.commands += &
      unix:jar.commands += ;
    jar.commands += cd classes
     win32:jar.commands += &
      unix:jar.commands += ;
    jar.commands += jar cf $$TARGET_JAVA_DIR/ivef/ivef.jar ivef/*

    QMAKE_EXTRA_TARGETS += jar
    PRE_TARGETDEPS += jar
    QMAKE_CLEAN += classes/ivef/*
    QMAKE_CLEAN += $$TARGET_JAVA_DIR/ivef/ivef.jar
}
else {
    message( "javac not installed" )
}

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
