######################################################################
# Generate the bindings
######################################################################
include(../bindings.pri)

CONFIG -= silent

TARGET_QT_DIR = $$IVEF_TARGETS_DIR/qt

! exists( $$TARGET_QT_DIR ) {
    message(Create build target dir: $$TARGET_QT_DIR)
    mkpath( $$TARGET_QT_DIR )
}

GEN_EXE   = $$shell_quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN)
GEN_ARGS  = --file=$$shell_quote($$IVEF_SCHEMA) --qt --out=$$TARGET_QT_DIR --prefix=IVEF

gentarget1.target    = $$TARGET_QT_DIR/include/IVEFMSG_IVEF.h
win32 {
    # On Windows use cmd.exe, echo the command, then run it.
    # '|| exit /b 1' ensures failure propagates to nmake.
    gentarget1.commands = echo Running: $${GEN_EXE}.exe $$GEN_ARGS &
    gentarget1.commands += cmd /c "$${GEN_EXE}.exe" --version &
    gentarget1.commands += cmd /c "$${GEN_EXE}.exe" $$GEN_ARGS || exit /b 1
} else {
    gentarget1.commands = $$GEN_EXE --version;
    gentarget1.commands += $$GEN_EXE $$GEN_ARGS
}
gentarget1.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget1
QMAKE_CLEAN += $$TARGET_QT_DIR/*/*


TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( $$TARGET_JAVA_DIR ) {
    message(Create build target dir: $$TARGET_JAVA_DIR)
    mkpath( $$TARGET_JAVA_DIR )
}

gentarget2.commands = $$quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN) --file=$$IVEF_SCHEMA \
                      --java --out=$$TARGET_JAVA_DIR --prefix=IVEF
gentarget2.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget2
QMAKE_CLEAN += $$TARGET_JAVA_DIR/ivef/*


TARGET_PHP_DIR = $$IVEF_TARGETS_DIR/php

! exists( $$TARGET_PHP_DIR ) {
    message(Create build target dir: $$TARGET_PHP_DIR)
    mkpath( $$TARGET_PHP_DIR )
}

gentarget3.commands = $$quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN) --file=$$IVEF_SCHEMA \
                      --php --out=$$TARGET_PHP_DIR --prefix=IVEF
gentarget3.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget3
QMAKE_CLEAN += $$TARGET_PHP_DIR/*


TARGET_OBJC_DIR = $$IVEF_TARGETS_DIR/objc

! exists( $$TARGET_OBJC_DIR ) {
    message(Create build target dir: $$TARGET_OBJC_DIR)
    mkpath( $$TARGET_OBJC_DIR )
}

gentarget4.commands = $$quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN) --file=$$IVEF_SCHEMA \
                      --objc --out=$$TARGET_OBJC_DIR --prefix=IL
gentarget4.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget4
QMAKE_CLEAN += $$TARGET_OBJC_DIR/*


first.depends += gentarget1
first.depends += gentarget2
first.depends += gentarget3
first.depends += gentarget4
first.CONFIG += phony
QMAKE_EXTRA_TARGETS += first

TEMPLATE = aux
TARGET = dummy
