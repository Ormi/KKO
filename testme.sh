#!/bin/sh

ERRORS=0

echo "Make"
make
echo "#################"
echo "Static"
echo "Compreess all"
./huff_codec -c -i data/hd01.raw -o data/hd01compress
./huff_codec -c -i data/hd02.raw -o data/hd02compress
./huff_codec -c -i data/hd07.raw -o data/hd07compress
./huff_codec -c -i data/hd08.raw -o data/hd08compress
./huff_codec -c -i data/hd09.raw -o data/hd09compress
./huff_codec -c -i data/hd12.raw -o data/hd12compress
./huff_codec -c -i data/nk01.raw -o data/nk01compress
echo "#################"
echo "Decompress all"
./huff_codec -d -i data/hd01compress -o data/hd01decompress
./huff_codec -d -i data/hd02compress -o data/hd02decompress
./huff_codec -d -i data/hd07compress -o data/hd07decompress
./huff_codec -d -i data/hd08compress -o data/hd08decompress
./huff_codec -d -i data/hd09compress -o data/hd09decompress
./huff_codec -d -i data/hd12compress -o data/hd12decompress
./huff_codec -d -i data/nk01compress -o data/nk01decompress
echo "#################"
echo "Diff"
diff data/hd01.raw data/hd01decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd02.raw data/hd02decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd07.raw data/hd07decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd08.raw data/hd08decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd09.raw data/hd09decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd12.raw data/hd12decompress
ERRORS=`expr $ERRORS + $?`
diff data/nk01.raw data/nk01decompress
ERRORS=`expr $ERRORS + $?`
echo "#################"
echo "See sizes"
# ls -la data/
echo "#################"
echo "Static Model"
echo "Compreess all"
./huff_codec -c -m -i data/hd02.raw -o data/hd02compress
./huff_codec -c -m -i data/hd01.raw -o data/hd01compress
./huff_codec -c -m -i data/hd07.raw -o data/hd07compress
./huff_codec -c -m -i data/hd08.raw -o data/hd08compress
./huff_codec -c -m -i data/hd09.raw -o data/hd09compress
./huff_codec -c -m -i data/hd12.raw -o data/hd12compress
./huff_codec -c -m -i data/nk01.raw -o data/nk01compress
echo "#################"
echo "Decompress all"
./huff_codec -d -m -i data/hd01compress -o data/hd01decompress
./huff_codec -d -m -i data/hd02compress -o data/hd02decompress
./huff_codec -d -m -i data/hd07compress -o data/hd07decompress
./huff_codec -d -m -i data/hd08compress -o data/hd08decompress
./huff_codec -d -m -i data/hd09compress -o data/hd09decompress
./huff_codec -d -m -i data/hd12compress -o data/hd12decompress
./huff_codec -d -m -i data/nk01compress -o data/nk01decompress
echo "#################"
echo "Diff"
diff data/hd01.raw data/hd01decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd02.raw data/hd02decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd07.raw data/hd07decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd08.raw data/hd08decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd09.raw data/hd09decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd12.raw data/hd12decompress
ERRORS=`expr $ERRORS + $?`
diff data/nk01.raw data/nk01decompress
ERRORS=`expr $ERRORS + $?`
echo "#################"
echo "See sizes"
# ls -la data/

echo "#################"
echo "Adaptive"
echo "Compreess all"
./huff_codec -c -a -i data/hd01.raw -o data/hd01compress
./huff_codec -c -a -i data/hd02.raw -o data/hd02compress
./huff_codec -c -a -i data/hd07.raw -o data/hd07compress
./huff_codec -c -a -i data/hd08.raw -o data/hd08compress
./huff_codec -c -a -i data/hd09.raw -o data/hd09compress
./huff_codec -c -a -i data/hd12.raw -o data/hd12compress
./huff_codec -c -a -i data/nk01.raw -o data/nk01compress
echo "#################"
echo "Decompress all"
./huff_codec -d -a -i data/hd01compress -o data/hd01decompress
./huff_codec -d -a -i data/hd02compress -o data/hd02decompress
./huff_codec -d -a -i data/hd07compress -o data/hd07decompress
./huff_codec -d -a -i data/hd08compress -o data/hd08decompress
./huff_codec -d -a -i data/hd09compress -o data/hd09decompress
./huff_codec -d -a -i data/hd12compress -o data/hd12decompress
./huff_codec -d -a -i data/nk01compress -o data/nk01decompress
echo "#################"
echo "Diff"
diff data/hd01.raw data/hd01decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd02.raw data/hd02decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd07.raw data/hd07decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd08.raw data/hd08decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd09.raw data/hd09decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd12.raw data/hd12decompress
ERRORS=`expr $ERRORS + $?`
diff data/nk01.raw data/nk01decompress
ERRORS=`expr $ERRORS + $?`
echo "#################"
echo "See sizes"
# ls -la data/
echo "#################"
echo "Adaptive Model"
echo "Compreess all"
./huff_codec -c -a -m -i data/hd01.raw -o data/hd01compress
./huff_codec -c -a -m -i data/hd02.raw -o data/hd02compress
./huff_codec -c -a -m -i data/hd07.raw -o data/hd07compress
./huff_codec -c -a -m -i data/hd08.raw -o data/hd08compress
./huff_codec -c -a -m -i data/hd09.raw -o data/hd09compress
./huff_codec -c -a -m -i data/hd12.raw -o data/hd12compress
./huff_codec -c -a -m -i data/nk01.raw -o data/nk01compress
echo "#################"
echo "Decompress all"
./huff_codec -d -a -m -i data/hd01compress -o data/hd01decompress
./huff_codec -d -a -m -i data/hd02compress -o data/hd02decompress
./huff_codec -d -a -m -i data/hd07compress -o data/hd07decompress
./huff_codec -d -a -m -i data/hd08compress -o data/hd08decompress
./huff_codec -d -a -m -i data/hd09compress -o data/hd09decompress
./huff_codec -d -a -m -i data/hd12compress -o data/hd12decompress
./huff_codec -d -a -m -i data/nk01compress -o data/nk01decompress
echo "#################"
echo "Diff"
diff data/hd01.raw data/hd01decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd02.raw data/hd02decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd07.raw data/hd07decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd08.raw data/hd08decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd09.raw data/hd09decompress
ERRORS=`expr $ERRORS + $?`
diff data/hd12.raw data/hd12decompress
ERRORS=`expr $ERRORS + $?`
diff data/nk01.raw data/nk01decompress
ERRORS=`expr $ERRORS + $?`
echo "#################"
echo "See sizes"
# ls -la data/

echo "#################"
echo "Clear"
# rm -rf data/hd01compress
# rm -rf data/hd02compress
# rm -rf data/hd07compress
# rm -rf data/hd08compress
# rm -rf data/hd09compress
# rm -rf data/hd12compress
# rm -rf data/nk01compress
# rm -rf data/hd02decompress
# rm -rf data/hd01decompress
# rm -rf data/hd07decompress
# rm -rf data/hd08decompress
# rm -rf data/hd09decompress
# rm -rf data/hd12decompress
# rm -rf data/nk01decompress

echo "#################"
echo "Number of errors"
echo $ERRORS

#cmp -l file1.bin file2.bin | gawk '{printf "%08X %02X %02X\n", $1, strtonum(0$2), strtonum(0$3)}'
