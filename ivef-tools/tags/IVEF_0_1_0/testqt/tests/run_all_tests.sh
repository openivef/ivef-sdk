DATADIR=data
TMPDIR=tmp

mkdir -p $TMPDIR
rm -Rf $TMPDIR/*

for INPUTFILE in `ls ${DATADIR}/TestIn*` 
do
   TESTCASE=`echo $INPUTFILE | cut -d - -f 2`
   TESTNAME=`echo $INPUTFILE | cut -d - -f 3`
   OUTNAME=TestOut-${TESTCASE}-${TESTNAME}

   echo -n running test $TESTCASE $TESTNAME ......

   cat ${INPUTFILE} | ../bin/testqt > ${TMPDIR}/$OUTNAME

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
          diff data/$OUTNAME ${TMPDIR}/$OUTNAME
          echo ---
      fi
   fi
 
done 
