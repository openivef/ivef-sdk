DATADIR=data
TMPDIR=tmp
COMMAND='java -classpath ../target/testjava.jar:../../ivef-java/ivef/ivef.jar testjava/testjava'

mkdir -p $TMPDIR
rm -Rf $TMPDIR/*

for INPUTFILE in `ls ${DATADIR}/TestIn*` 
do
   TESTCASE=`echo $INPUTFILE | cut -d - -f 2`
   TESTNAME=`echo $INPUTFILE | cut -d - -f 3`
   OUTNAME=TestOut-${TESTCASE}-${TESTNAME}

   echo -n running test $TESTCASE $TESTNAME ......

   cat ${INPUTFILE} | $COMMAND > ${TMPDIR}/$OUTNAME

   if [ ! -f data/$OUTNAME ]
   then
      echo ERROR i have no reference for test
   else
      if [ "`diff data/$OUTNAME ${TMPDIR}/$OUTNAME`" == "" ] 
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
