######################################################################
# Create several bindings libraries
######################################################################
include(bindings.pri)

SCHEMA = ../$$IVEF_SCHEMA
GENERATOR = $$GENERATOR_BIN

message(Create build target dir)
! exists( $$GENERATOR_TARGET_DIR ) {
    system( mkdir $$GENERATOR_TARGET_DIR )
}

# create Qt code -----------------------------------------------------
TARGET_QT_DIR = $$GENERATOR_TARGET_DIR/qt
TARGET_QT_SRC_DIR = $$TARGET_QT_DIR/src

! exists( $$TARGET_QT_DIR ) {
    system( mkdir $$TARGET_QT_DIR )
}
! exists( $$TARGET_QT_SRC_DIR ) {
    system( mkdir $$TARGET_QT_SRC_DIR )
}

system( $$GENERATOR --file=$$SCHEMA --qt --out=$$TARGET_QT_SRC_DIR --prefix=IVEF)

SUBDIRS += qt

TEMPLATE = subdirs
