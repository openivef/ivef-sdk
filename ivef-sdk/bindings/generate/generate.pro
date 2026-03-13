######################################################################
# Generate the bindings
######################################################################
include(../bindings.pri)

CONFIG -= silent

TARGET_QT_DIR = $$IVEF_TARGETS_DIR/qt

mkoutdir1.commands = $$QMAKE_MKDIR $$shell_quote($$TARGET_QT_DIR)
mkoutdir1.CONFIG  += phony
QMAKE_EXTRA_TARGETS += mkoutdir1

GEN_EXE   = $$shell_quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN)
GEN_ARGS  = --file=$$shell_quote($$IVEF_SCHEMA) --qt --out=$$TARGET_QT_DIR --prefix=IVEF

gentarget1.target    = $$TARGET_QT_DIR/include/IVEFMSG_IVEF.h
win32 {
    # On Windows use cmd.exe, echo the command, then run it.
    # '|| exit /b 1' ensures failure propagates to nmake.
    gentarget1.commands = \
        echo Running: $${GEN_EXE}.exe $$GEN_ARGS && \
        if not exist $${GEN_EXE}.exe ( echo ERROR: generator not found & exit /b 1 ) && \
        cmd /c "$${GEN_EXE}.exe $$GEN_ARGS" || exit /b 1
} else {
    gentarget1.commands = $$GEN_EXE $$GEN_ARGS
}
gentarget1.CONFIG += phony
gentarget1.depends  += mkoutdir1
QMAKE_EXTRA_TARGETS += gentarget1
QMAKE_CLEAN += $$TARGET_QT_DIR/*/*


TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

mkoutdir2.commands = $$QMAKE_MKDIR $$shell_quote($$TARGET_JAVA_DIR)
mkoutdir2.CONFIG  += phony
QMAKE_EXTRA_TARGETS += mkoutdir2

gentarget2.commands = $$quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN) --file=$$IVEF_SCHEMA \
                      --java --out=$$TARGET_JAVA_DIR --prefix=IVEF
gentarget2.CONFIG += phony
gentarget2.depends  += mkoutdir2
QMAKE_EXTRA_TARGETS += gentarget2
QMAKE_CLEAN += $$TARGET_JAVA_DIR/ivef/*


TARGET_PHP_DIR = $$IVEF_TARGETS_DIR/php

mkoutdir3.commands = $$QMAKE_MKDIR $$shell_quote($$TARGET_PHP_DIR)
mkoutdir3.CONFIG  += phony
QMAKE_EXTRA_TARGETS += mkoutdir3

gentarget3.commands = $$quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN) --file=$$IVEF_SCHEMA \
                      --php --out=$$TARGET_PHP_DIR --prefix=IVEF
gentarget3.CONFIG += phony
gentarget3.depends  += mkoutdir3
QMAKE_EXTRA_TARGETS += gentarget3
QMAKE_CLEAN += $$TARGET_PHP_DIR/*


TARGET_OBJC_DIR = $$IVEF_TARGETS_DIR/objc

mkoutdir4.commands = $$QMAKE_MKDIR $$shell_quote($$TARGET_OBJC_DIR)
mkoutdir4.CONFIG  += phony
QMAKE_EXTRA_TARGETS += mkoutdir4

gentarget4.commands = $$quote($$IVEF_GENERATOR_DIR/$$IVEF_GENERATOR_BIN) --file=$$IVEF_SCHEMA \
                      --objc --out=$$TARGET_OBJC_DIR --prefix=IL
gentarget4.CONFIG += phony
gentarget4.depends  += mkoutdir4
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
