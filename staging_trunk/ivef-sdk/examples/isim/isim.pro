######################################################################
# Build the JAVA binding
######################################################################
include(../examples.pri)

TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

jar.commands = \
    mkdir -p classes;\
    javac -d classes src/luky/Version.java src/luky/*/*java;\
    javac -d classes src/com/jcraft/jzlib/*java;\
    javac -d classes -classpath classes:$$TARGET_JAVA_DIR/ivef/ivef.jar src/isim/*/*java;\
    cd classes;\
    jar cMf $$IVEF_EXAMPLES_DIR/isim.jar *

QMAKE_EXTRA_TARGETS += jar
PRE_TARGETDEPS += jar
##QMAKE_CLEAN += classes/*/*
QMAKE_CLEAN += $$IVEF_EXAMPLES_DIR/isim.jar


test1.commands = \
    echo "java -classpath $$IVEF_EXAMPLES_DIR/isim.jar:$$TARGET_JAVA_DIR/ivef/ivef.jar isim/core/isim -p 8043 -l 5  -s test.xml" > $$IVEF_EXAMPLES_DIR/run_isim;\
    chmod +x $$IVEF_EXAMPLES_DIR/run_isim

QMAKE_EXTRA_TARGETS += test1
PRE_TARGETDEPS += test1
QMAKE_CLEAN += $$IVEF_EXAMPLES_DIR/run_isim


test2.commands = \
    cp scenario/test.xml $$IVEF_EXAMPLES_DIR/test.xml

QMAKE_EXTRA_TARGETS += test2
PRE_TARGETDEPS += test2
QMAKE_CLEAN += $$IVEF_EXAMPLES_DIR/test.xml

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
