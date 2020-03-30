/*******************************************************************************
 * @project Static and Adaptive Huffman Coding 
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subject KKO
 * @file helper.cpp
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#include "helper.h"
#define ZERO 0

tree::tree()
    :parentNode{nullptr},
    leftNode{nullptr},
    rightNode{nullptr},
    treeWeight{ZERO},
    nodeSymbol{ZERO},
    treeOrder{ZERO} 
    {}
tree::tree(uint16_t nodeSymbol, size_t treeWeight)
    :parentNode{nullptr},
    leftNode{nullptr},
    rightNode{nullptr},
    treeWeight{treeWeight},
    nodeSymbol{nodeSymbol} 
    {}
tree::tree(size_t treeWight, tree *leftNode, tree *rightNode)
    :treeWeight{treeWeight},
    parentNode{nullptr},
    leftNode{leftNode},
    rightNode{rightNode}
    {}

size_t tree::getTreeWeight() {
    return treeWeight;
}
uint16_t tree::getNodeSymbol() {
    return nodeSymbol;
}
uint16_t tree::getTreeOrder() {
    return treeOrder;
}
void tree::setTreeOrder(uint16_t newTreeOrder) {
    treeOrder = newTreeOrder;
}
void tree::incrementTreeWeight() {
    treeWeight++;
}
void tree::setTreeWeight(size_t newTreeWeight) {
    treeWeight = newTreeWeight;
}
void tree::setNodeSymbol(uint16_t newNodeSymbol) {
    nodeSymbol = newNodeSymbol;
}

tree *tree::getLeftTreeNode() {
    return leftNode;
}
void tree::setLeftTreeNode(tree *newLeftNode) {
    leftNode = newLeftNode;
}

tree *tree::getRightTreeNode() {
    return rightNode;
}
void tree::setRightTreeNode(tree *newRightNode) {
    rightNode = newRightNode;
}

tree *tree::getParentTreeNode() {
    return parentNode;
}
void tree::setParentTreeNode(tree * newParentNode) {
    parentNode = newParentNode;
}

bool tree::isLeafNode() {
    return leftNode == nullptr && rightNode == nullptr;
}
bool tree::operator<(tree &other) const {
    return treeWeight < other.treeWeight;
}
bool compareTreeNodes::operator()(tree *leftNode, tree *rightNode) {
    return (leftNode->getTreeWeight() > rightNode->getTreeWeight());
}

////////////////////////////////////////////////////////////////////////////////

bitHandler::bitHandler() : bitPositionInByte{ZERO}, fileBytes{ZERO} {}

void bitHandler::addBitToStream(bool bit) {
    if (bitPositionInByte >= CHAR_BIT) {
        fileBytes.emplace_back(bit << (CHAR_BIT - 1));
        bitPositionInByte = 1;
    } else {
        fileBytes.back() = fileBytes.back() | bit << (CHAR_BIT - bitPositionInByte - 1);
        bitPositionInByte++;      
    }
}

void bitHandler::addBitsToStream(std::vector<bool> &bits) {
    for (bool b : bits) {
        addBitToStream(b);
    }
}

void bitHandler::addByteToStream(unsigned char byte) {
    for (size_t i = 0; i < CHAR_BIT; ++i) {
        addBitToStream((byte >> (CHAR_BIT - i - 1)) & 1);
    }
}

unsigned bitHandler::howManyBitLefts() {
    return (CHAR_BIT - bitPositionInByte) % CHAR_BIT;
}

std::vector<unsigned char> &bitHandler::getBytesFromStream() { 
    return fileBytes; 
}