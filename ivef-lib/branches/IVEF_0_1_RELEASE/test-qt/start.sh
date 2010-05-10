install_name_tool -change /ivef.framework/Versions/1/ivef ../../ivef-qt/bin/ivef.framework/Versions/1/ivef bin/testqt
DYLD_LIBRARY_PATH="../ivef-qt/bin" LD_LIBRARY_PATH="../ivef-qt/bin" ./bin/testqt $*
