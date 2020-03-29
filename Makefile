################################################################################
# @project Static and Adaptive Huffman Coding 
# @author Michal Ormos
# @email xormos00@stud.fit.vutbr.cz
# @date March 2020
# @subjeCt KKO
# @file Makefile
################################################################################

CC=g++
CFLAGS= -std=c++11 -Wall -Wextra -O3 -flto -static
OUT=huff_codec

all: $(OUT)

debug:
	$(CC) -std=c++11 -Wall -Wextra -ggdb3 -o $(OUT)

clean:
	rm -f *.o $(OUT)

makezip:
	zip -r kko_xormos00.zip *.cpp *.h Makefile