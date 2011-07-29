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

TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( $$TARGET_JAVA_DIR ) {
    message(Create build target dir: $$TARGET_JAVA_DIR)
    unix:system( mkdir $$TARGET_JAVA_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\java )
}

gentarget2.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --java --out=$$TARGET_JAVA_DIR --prefix=IVEF
QMAKE_EXTRA_TARGETS += gentarget2
PRE_TARGETDEPS += gentarget2

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
