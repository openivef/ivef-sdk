include(targets.pri)

# now create the code
SCHEMA = ../$$IVEF_SCHEMA
GENERATOR = $$GENERATOR_BIN
TARGETDIR_QT = $$GENERATOR_TARGET_DIR/qt

# first only for Qt
#message(Create Qt target...)
#system(mkdir -p $$TARGETDIR_QT/src; $$GENERATOR --file=$$SCHEMA --out=$$TARGETDIR_QT/src --prefix=IVEF)
#system(mkdir -p $$GENERATOR_TARGET_DIR/qt/moc)
#system(mkdir -p $$GENERATOR_TARGET_DIR/qt/obj)
TEMPLATE = subdirs
SUBDIRS = testje qt
qt.depends = testje

#mytarget.target = .buildfile
#mytarget.commands = touch $$mytarget.target
#mytarget.depends = mytarget2

#mytarget2.commands = echo "hallo dan!"

#QMAKE_EXTRA_TARGETS += mytarget2
#PRE_TARGETDEPS += mytarget2
