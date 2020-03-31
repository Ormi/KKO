/*******************************************************************************
 * @project Static and Adaptive Huffman Coding 
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subject KKO
 * @file Tree.h
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#ifndef TREE_H
#define TREE_H

#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

uint16_t notYetTransferredNode = 256;
uint16_t internalNode = 257;
uint16_t extraNode = 256;

class Tree {
    Tree *parentNode;
    Tree *leftNode;
    Tree *rightNode;
    size_t treeWeight;
    uint16_t nodeSymbol;
    uint16_t treeOrder;
    public:
        Tree();
        Tree(uint16_t nodeSymbol, size_t treeWeight);
        Tree(size_t treeWeight, Tree *leftNode, Tree *rightNode);
        Tree *getLeftTreeNode();
        void setLeftTreeNode(Tree *newLeftNode);

        Tree *getRightTreeNode();
        void setRightTreeNode(Tree *newRightNode);

        Tree *getParentTreeNode();
        void setParentTreeNode(Tree *newTreeParent);

        uint16_t getNodeSymbol();
        void setNodeSymbol(uint16_t newNodeSymbol);

        size_t getTreeWeight();
        void setTreeWeight(size_t newTreeWeight);

        uint16_t getTreeOrder();
        void setTreeOrder(uint16_t newOrder);    

        bool isLeafNode();
        bool isInternalNode();
        void incrementTreeWeight();
        bool operator<(Tree &other) const;
    };

class BitHandler {
    size_t bitPositionInByte;    
    vector<unsigned char> fileBytes;
    public:
    BitHandler();
    void addBitToStream(bool bit);
    void addBitsToStream(vector<bool> &bits);
    void addByteToStream(unsigned char byte);
    unsigned howManyBitLefts();
    vector<unsigned char> &getBytesFromStream();
};

struct compareTreeNodes {
    bool operator()(Tree *leftNode, Tree *rightNode);
};        

#endif