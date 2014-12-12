DATADIR=data
TMPDIR=tmp

if [ "$1" == "qt" ]
then
    export LD_LIBRARY_PATH="../../build/targets/qt/lib"
    COMMAND='../qt/bin/testqt'
elif [ "$1" == "objc" ]
then
    COMMAND='../objc/build/Release/testobjc'
    if [ ! -f $COMMAND ]
    then
        COMMAND='../objc/build/Debug/testobjc'
    fi
elif [ "$1" == "java" ]
then
    COMMAND='java -classpath ../java/target/testjava.jar:../../build/targets/java/ivef/ivef.jar testjava/testjava'
elif [ "$1" == "php" ]
then
    # Make it more portable
    if type php5 >/dev/null 2>&1    
    then
        COMMAND='php5 ../php/test.php'
    elif type php >/dev/null 2>&1    
    then
        COMMAND='php ../php/test.php'
    else
        echo "php executable not found" >&2
        exit 1
    fi
elif [ "$1" == "all" ]
then
    # recursive call of ourselfs
    $0 php
    $0 qt
    $0 obj-c
    $0 java
    exit 0
else
    echo "syntax $0 [qt | objc | java | php | all]"
    exit 1
fi

mkdir -p $TMPDIR
rm -Rf $TMPDIR/*

for INPUTFILE in $(ls ${DATADIR}/*.xml.in 2>/dev/null) $(ls ${DATADIR}/*.xml-$1.in 2>/dev/null)
do
   STCASE=$(echo $INPUTFILE | cut -d - -f 1)
   TESTNAME=$(echo $INPUTFILE | cut -d . -f 1)
   OUTNAME=$(echo $INPUTFILE | cut -d . -f -2 | cut -d / -f 2-)-$1.out

   if [ ! -f data/$OUTNAME ]
   then
      OUTNAME=$(echo $INPUTFILE | cut -d . -f -2 | cut -d / -f 2-).out
      if [ ! -f data/$OUTNAME ]
      then
         echo ERROR i have no reference for test: data/$OUTNAME
         exit 1
      fi
   fi
   echo -n running test $TESTCASE $TESTNAME ......

   cat ${INPUTFILE} | $COMMAND > ${TMPDIR}/$OUTNAME 

      if [ "$(diff -w data/$OUTNAME ${TMPDIR}/$OUTNAME)" == "" ] 
      then 
          echo OK
      else
          echo NOK
          echo ---
          echo Difference: ${TMPDIR}/$OUTNAME data/$OUTNAME
          echo ---
          sdiff -W ${TMPDIR}/$OUTNAME data/$OUTNAME
          echo ---
          exit 1
      fi
done 

# all test ok, clean up
rm -Rf $TMPDIR
