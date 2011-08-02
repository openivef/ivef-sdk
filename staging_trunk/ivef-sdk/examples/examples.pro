######################################################################
# examples, do some preparations
######################################################################
include(examples.pri)

! exists( $$IVEF_EXAMPLES_DIR ) {
    message(Create build examples dir: $$IVEF_EXAMPLES_DIR)
    system( mkdir $$IVEF_EXAMPLES_DIR )
}

TEMPLATE = subdirs
SUBDIRS = ilisten isim
