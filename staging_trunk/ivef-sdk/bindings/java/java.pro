######################################################################
# Build the JAVA binding
######################################################################
include(../bindings.pri)

TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( $$TARGET_JAVA_DIR ) {
    message(Create build target dir: $$TARGET_JAVA_DIR)
    unix:system( mkdir $$TARGET_JAVA_DIR )
    win32:system( mkdir ..\\..\\build\\targets\\java )
}

gentarget.commands = $$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN --file=$$IVEF_SCHEMA --java --out=$$TARGET_JAVA_DIR --prefix=IVEF
# This makes the command run before anything else
gentarget.CONFIG += target_predeps

PRE_TARGETDEPS += gentarget
QMAKE_EXTRA_TARGETS += gentarget

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
