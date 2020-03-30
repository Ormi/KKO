################################################################################
# @project Static and Adaptive Huffman Coding 
# @author Michal Ormos
# @email xormos00@stud.fit.vutbr.cz
# @date March 2020
# @subject KKO
# @file Makefile
################################################################################

CC=g++
CFLAGS= -std=c++11 -Wall -Wextra -O3 -flto -static
OUT=huff_codec

all: $(OUT)

main.o: main.cpp tree.h
	$(CC) $(CFLAGS) -c $< -o $@

tree.o: tree.cpp tree.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): main.o tree.o
	$(CC) $(CFLAGS) $^ -o $@

debug:
	$(CC) -std=c++11 -Wall -Wextra -ggdb3 main.cpp tree.cpp -o $(OUT)

clean:
	rm -f *.o $(OUT)

makezip:
	zip -r kko_xormos00.zip *.cpp *.h Makefile