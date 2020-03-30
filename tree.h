/*******************************************************************************
 * @project Static and Adaptive Huffman Coding 
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subject KKO
 * @file tree.h
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#ifndef TREE_H
#define TREE_H

#include <stdint.h>
#include <stdlib.h>

uint16_t notYetTransferredNode = 256;
uint16_t internalNode = 257;
uint16_t extraNode = 256;

class tree {
    tree *parentNode;
    tree *leftNode;
    tree *rightNode;
    size_t treeWeight;
    uint16_t nodeSymbol;
    uint16_t treeOrder;
    public:
        tree();
        tree(uint16_t nodeSymbol, size_t treeWeight);
        tree(size_t treeWeight, tree *leftNode, tree *rightNode);
        tree *getLeftTreeNode();
        void setLeftTreeNode(tree *newLeftNode);

        tree *getRightTreeNode();
        void setRightTreeNode(tree *newRightNode);

        tree *getParentTreeNode();
        void setParentTreeNode(tree *newTreeParent);

        uint16_t getNodeSymbol();
        void setNodeSymbol(uint16_t newNodeSymbol);

        size_t getTreeWeight();
        void setTreeWeight(size_t newTreeWeight);

        uint16_t getTreeOrder();
        void setTreeOrder(uint16_t newOrder);    

        void setParentTreeNode(tree *newTreeParent);
        bool isLeafNode();
        bool isInternalNode();
        void incrementTreeWeight();
        bool operator<(tree &other) const;
    };
struct compareTreeNodes {
    bool operator()(tree *leftNode, tree *rightNode);
};        

#endif