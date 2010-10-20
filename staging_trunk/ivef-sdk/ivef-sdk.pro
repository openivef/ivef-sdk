include(ivef-sdk.pri)

message(IVEF-SDK will be installed in $$IVEF_BUILD_DIR)
system(mkdir -p build/tmp/moc)
system(mkdir -p build/tmp/obj)
TEMPLATE = subdirs
SUBDIRS = schema2code bindings tests examples
bindings.depends = schema2code
tests.depends = bindings
examples.depends = bindings
