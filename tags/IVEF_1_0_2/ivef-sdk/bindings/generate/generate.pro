######################################################################
# Generate the bindings
######################################################################
include(../bindings.pri)


TARGET_QT_DIR = $$IVEF_TARGETS_DIR/qt

! exists( $$TARGET_QT_DIR ) {
    message(Create build target dir: $$TARGET_QT_DIR)
    unix:system( mkdir $$TARGET_QT_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\qt )
}

gentarget1.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --qt --out=$$TARGET_QT_DIR --prefix=IVEF
QMAKE_EXTRA_TARGETS += gentarget1
PRE_TARGETDEPS += gentarget1
QMAKE_CLEAN += $$TARGET_QT_DIR/*/*


TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( $$TARGET_JAVA_DIR ) {
    message(Create build target dir: $$TARGET_JAVA_DIR)
    unix:system( mkdir $$TARGET_JAVA_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\java )
}

gentarget2.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --java --out=$$TARGET_JAVA_DIR --prefix=IVEF
QMAKE_EXTRA_TARGETS += gentarget2
PRE_TARGETDEPS += gentarget2
QMAKE_CLEAN += $$TARGET_JAVA_DIR/ivef/*


TARGET_PHP_DIR = $$IVEF_TARGETS_DIR/php

! exists( $$TARGET_PHP_DIR ) {
    message(Create build target dir: $$TARGET_PHP_DIR)
    unix:system( mkdir $$TARGET_PHP_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\php )
}

gentarget3.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --php --out=$$TARGET_PHP_DIR --prefix=IVEF
QMAKE_EXTRA_TARGETS += gentarget3
PRE_TARGETDEPS += gentarget3
QMAKE_CLEAN += $$TARGET_PHP_DIR/*


TARGET_OBJC_DIR = $$IVEF_TARGETS_DIR/objc

! exists( $$TARGET_OBJC_DIR ) {
    message(Create build target dir: $$TARGET_OBJC_DIR)
    unix:system( mkdir $$TARGET_OBJC_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\objc )
}

gentarget4.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --objc --out=$$TARGET_OBJC_DIR --prefix=IL
QMAKE_EXTRA_TARGETS += gentarget4
PRE_TARGETDEPS += gentarget4
QMAKE_CLEAN += $$TARGET_OBJC_DIR/*


MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
