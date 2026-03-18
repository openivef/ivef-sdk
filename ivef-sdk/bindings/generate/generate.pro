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

win32 {
    GEN_EXE = 'cmd /c "$$IVEF_GENERATOR_DIR/$${IVEF_GENERATOR_BIN}.exe"'
} else {
    GEN_EXE = $$IVEF_GENERATOR_DIR/$${IVEF_GENERATOR_BIN}
}
GEN_ARGS  = --file=$$shell_quote($$IVEF_SCHEMA) --qt --out=$$TARGET_QT_DIR --prefix=IVEF

gentarget1.target = $$TARGET_QT_DIR/include/IVEFMSG_IVEF.h
gentarget1.commands = $$GEN_EXE $$GEN_ARGS
gentarget1.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget1
QMAKE_CLEAN += $$TARGET_QT_DIR/*/*


TARGET_JAVA_DIR = $$IVEF_TARGETS_DIR/java

! exists( $$TARGET_JAVA_DIR ) {
    message(Create build target dir: $$TARGET_JAVA_DIR)
    mkpath( $$TARGET_JAVA_DIR )
}

GEN_ARGS  = --file=$$shell_quote($$IVEF_SCHEMA) --java --out=$$TARGET_JAVA_DIR --prefix=IVEF
gentarget2.commands = $$GEN_EXE $$GEN_ARGS
gentarget2.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget2
QMAKE_CLEAN += $$TARGET_JAVA_DIR/ivef/*


TARGET_PHP_DIR = $$IVEF_TARGETS_DIR/php

! exists( $$TARGET_PHP_DIR ) {
    message(Create build target dir: $$TARGET_PHP_DIR)
    mkpath( $$TARGET_PHP_DIR )
}

GEN_ARGS  = --file=$$shell_quote($$IVEF_SCHEMA) --php --out=$$TARGET_PHP_DIR --prefix=IVEF
gentarget3.commands = $$GEN_EXE $$GEN_ARGS
gentarget3.CONFIG += phony
QMAKE_EXTRA_TARGETS += gentarget3
QMAKE_CLEAN += $$TARGET_PHP_DIR/*


TARGET_OBJC_DIR = $$IVEF_TARGETS_DIR/objc

! exists( $$TARGET_OBJC_DIR ) {
    message(Create build target dir: $$TARGET_OBJC_DIR)
    mkpath( $$TARGET_OBJC_DIR )
}

GEN_ARGS  = --file=$$shell_quote($$IVEF_SCHEMA) --objc --out=$$TARGET_OBJC_DIR --prefix=IL
gentarget4.commands = $$GEN_EXE $$GEN_ARGS
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
