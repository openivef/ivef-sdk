######################################################################
# examples, do some preparations
######################################################################
include(examples.pri)

message(Create destination for exampels)
!exists( $$EXAMPLE_DEST_DIR ) {
    system(mkdir $$EXAMPLE_DEST_DIR)
}

TEMPLATE = subdirs
SUBDIRS = ilisten
