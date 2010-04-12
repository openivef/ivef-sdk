DATADIR=data
TMPDIR=tmp
COMMAND='../build/Debug/testobjc'


if [ "$1" == "qt" ]
then
    export DYLD_LIBRARY_PATH="../ivef-qt/bin"
    export LD_LIBRARY_PATH="../ivef-qt/bin"
    COMMAND='../test-qt/bin/testqt'
elif [ "$1" == "objc" ]
then
    COMMAND='../test-objc/build/Debug/testobjc'
elif [ "$1" == "java" ]
then
    COMMAND='java -classpath ../test-java/target/testjava.jar:../ivef-java/ivef/ivef.jar testjava/testjava'
elif [ "$1" == "all" ]
then
    # recursive call of ourselfs
    $0 qt
    $0 obj-c
    $0 java
    exit 0
else
    echo "syntax $0 [qt | objc | java | all]"
    exit 1
fi

mkdir -p $TMPDIR
rm -Rf $TMPDIR/*

for INPUTFILE in `ls ${DATADIR}/*.xml.in ${DATADIR}/*.xml-$1.in` 
do
   STCASE=`echo $INPUTFILE | cut -d - -f 1`
   TESTNAME=`echo $INPUTFILE | cut -d . -f 1`
   OUTNAME=`echo $INPUTFILE | cut -d . -f -2 | cut -d / -f 2-`.out

   echo -n running test $TESTCASE $TESTNAME ......

   cat ${INPUTFILE} | $COMMAND > ${TMPDIR}/$OUTNAME 

   if [ ! -f data/$OUTNAME ]
   then
      echo ERROR i have no reference for test: data/$OUTNAME
   else
      if [ "`diff -b data/$OUTNAME ${TMPDIR}/$OUTNAME`" == "" ] 
      then 
          echo OK
      else
          echo NOK
          echo ---
          echo Difference: ${TMPDIR}/$OUTNAME data/$OUTNAME
          echo ---
          diff ${TMPDIR}/$OUTNAME data/$OUTNAME
          echo ---
          exit 1
      fi
   fi
done 

# all test ok, clean up
rm -Rf $TMPDIR
