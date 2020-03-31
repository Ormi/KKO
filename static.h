/*******************************************************************************
 * @project Static and Adaptive Huffman Coding 
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subject KKO
 * @file static.h
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#ifndef STATIC_H
#define STATIC_H

#include "helper.h"

const uint16_t INTERVAL_SIZE = 256;

class Static {
	vector<size_t> symbolFrequency;
  	vector<std::pair<unsigned char, vector<bool>>> synbolCode;
  	std::priority_queue<Tree *, vector<Tree *>, compareTreeNodes>huffmanCodeTree;
  	unsigned char *fileBytes;
  	size_t fileLength;
  	size_t countOfBytes;
  	size_t bitPositionInByte;
  	unsigned pad;
	public:
		Static(unsigned char *fileBytes, size_t fileLength);
		bool hasNext();
		bool getNext();
		void buildTree();
		void firstComeFirstServer();
		void decodeBytes(vector<unsigned char> &decodeBytes);
		void encodeBytes(FILE *outputBytes);
		void makeTreeCanonical();
		void saveCode();
		void saveCode(Tree *treeNode, vector<bool> treeCode = {});
		void freeTree(Tree *treeNode);
		~Static();
};

#endif