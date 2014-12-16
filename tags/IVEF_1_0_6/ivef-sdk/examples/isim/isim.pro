######################################################################
# Build the JAVA binding
######################################################################
include(../examples.pri)

TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( classes ) {
    system( mkdir classes )
}

win32|system( which javac 1>/dev/null 2>&1 ){
   CONFIG += javac
}

javac {
    jar.commands += javac -d classes src/luky/Version.java src/luky/crypt/*java
    jar.commands += src/luky/dialogs/*java src/luky/events/*java src/luky/linux/*java
    jar.commands += src/luky/lua/*java src/luky/serverSimple/*java src/luky/util/*java src/luky/xml/*java
     win32:jar.commands += &
      unix:jar.commands += ;
    jar.commands += javac -d classes src/com/jcraft/jzlib/*java
     win32:jar.commands += & javac -d classes -classpath classes;$$TARGET_JAVA_DIR/ivef/ivef.jar
      unix:jar.commands += ; javac -d classes -classpath classes:$$TARGET_JAVA_DIR/ivef/ivef.jar
    jar.commands += src/isim/core/*java
     win32:jar.commands += &
      unix:jar.commands += ;
    jar.commands += cd classes
     win32:jar.commands += &
      unix:jar.commands += ;
    jar.commands += jar cMf $$IVEF_EXAMPLES_DIR/isim.jar *

    QMAKE_EXTRA_TARGETS += jar
    PRE_TARGETDEPS += jar
    ##QMAKE_CLEAN += classes/*/*
    QMAKE_CLEAN += $$IVEF_EXAMPLES_DIR/isim.jar


     win32:test1.commands += echo "java -classpath $$IVEF_EXAMPLES_DIR/isim.jar;$$TARGET_JAVA_DIR/ivef/ivef.jar isim/core/isim -p 8043 -l 5 -s test.xml"
      unix:test1.commands += echo "java -classpath $$IVEF_EXAMPLES_DIR/isim.jar:$$TARGET_JAVA_DIR/ivef/ivef.jar isim/core/isim -p 8043 -l 5 -s test.xml"
    test1.commands += > $$IVEF_EXAMPLES_DIR/run_isim
      unix:test1.commands +=; chmod +x $$IVEF_EXAMPLES_DIR/run_isim

    QMAKE_EXTRA_TARGETS += test1
    PRE_TARGETDEPS += test1
    QMAKE_CLEAN += $$IVEF_EXAMPLES_DIR/run_isim
}
else {
    message( "javac not installed" )
}

  unix:test2.commands += cp scenario/test.xml $$IVEF_EXAMPLES_DIR/test.xml
 win32:test2.commands += copy scenario\\test.xml ..\\..\\build\\examples\\test.xml

QMAKE_EXTRA_TARGETS += test2
PRE_TARGETDEPS += test2
QMAKE_CLEAN += $$IVEF_EXAMPLES_DIR/test.xml

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj

TEMPLATE = lib
TARGET = dummy
