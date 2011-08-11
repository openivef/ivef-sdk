######################################################################
# define directory where IVEF-SDK is built.
# Where using a 'out-of-tree' building structure.
######################################################################

IVEF_BUILD_DIR = $$PWD/build
IVEF_GENERATOR_DIR = $$IVEF_BUILD_DIR/bin
IVEF_TARGETS_DIR   = $$IVEF_BUILD_DIR/targets
IVEF_EXAMPLES_DIR  = $$IVEF_BUILD_DIR/examples

IVEF_GENERATOR_BIN = schema2code
IVEF_SCHEMA = $$PWD/spec/ivef.xsd

IVEF_VERSION = 1.0.0
