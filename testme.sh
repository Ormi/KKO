#!/bin/sh

echo "Make"
make
echo "#################"
echo "Compreess" 
./huff_codec -c -i ../hd01.raw -o ../hd01compress
echo "#################"
echo "Decompress"
./huff_codec -d -i ../hd01compress -o ../hd01decompress
echo "#################"
echo "Diff"
diff ../hd01.raw ../hd01decompress
echo "#################"
echo "See sizes"
ls -la ../hd01*
