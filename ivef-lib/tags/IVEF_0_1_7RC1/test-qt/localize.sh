otool -L bin/testqt
PWD=`pwd`
TARGET=`dirname $PWD`
install_name_tool -change /ivef.framework/Versions/1/ivef $TARGET/ivef-qt/bin/ivef.framework/Versions/1/ivef bin/testqt
otool -L bin/testqt
