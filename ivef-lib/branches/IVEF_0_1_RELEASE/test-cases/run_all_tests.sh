DATADIR=data
TMPDIR=tmp
COMMAND='../build/Debug/testobjc'

mkdir -p $TMPDIR
rm -Rf $TMPDIR/*

for INPUTFILE in `ls ${DATADIR}/*.in` 
do
   TESTCASE=`echo $INPUTFILE | cut -d - -f 1`
   TESTNAME=`echo $INPUTFILE | cut -d . -f 3`
   OUTNAME=`echo $INPUTFILE | cut -d . -f -2`.out

   echo -n running test $TESTCASE $TESTNAME ......

   cat ${INPUTFILE} | $COMMAND > ${TMPDIR}/$OUTNAME &2>/dev/null

   if [ ! -f data/$OUTNAME ]
   then
      echo ERROR i have no reference for test
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
