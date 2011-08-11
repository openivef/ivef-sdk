######################################################################
# Create several bindings libraries
######################################################################
include(bindings.pri)

! exists( $$IVEF_TARGETS_DIR ) {
    message(Create build target dir: $$IVEF_TARGETS_DIR)
    system( mkdir $$IVEF_TARGETS_DIR )
}

SUBDIRS += build generate
build.depends = generate

TEMPLATE = subdirs
