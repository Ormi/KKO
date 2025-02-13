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

Tree::Tree()
    :treeWeight{ZERO},
    parentNode{nullptr},
    leftNode{nullptr},
    rightNode{nullptr},
    nodeSymbol{ZERO},
    treeOrder{ZERO}
    {}
Tree::Tree(uint16_t nodeSymbol, size_t treeWeight)
    :treeWeight{treeWeight},
    parentNode{nullptr},
    leftNode{nullptr},
    rightNode{nullptr},
    nodeSymbol{nodeSymbol}
    {}
Tree::Tree(size_t treeWeight, Tree *leftNode, Tree *rightNode)
    :treeWeight{treeWeight},
    parentNode{nullptr},
    leftNode{leftNode},
    rightNode{rightNode}
    {}

uint16_t Tree::getNodeSymbol() {
    return nodeSymbol;
}
size_t Tree::getTreeWeight() {
    return treeWeight;
}
uint16_t Tree::getTreeOrder() {
    return treeOrder;
}

void Tree::setTreeOrder(uint16_t newTreeOrder) {
    treeOrder = newTreeOrder;
}
void Tree::incrementTreeWeight() {
    ++treeWeight;
}
void Tree::setTreeWeight(size_t newTreeWeight) {
    treeWeight = newTreeWeight;
}
void Tree::setNodeSymbol(uint16_t newNodeSymbol) {
    nodeSymbol = newNodeSymbol;
}

void Tree::setLeftTreeNode(Tree *newLeftNode) {
    leftNode = newLeftNode;
}
void Tree::setRightTreeNode(Tree *newRightNode) {
    rightNode = newRightNode;
}
void Tree::setParentTreeNode(Tree *newParentNode) {
    parentNode = newParentNode;
}

Tree *Tree::getLeftTreeNode() {
    return leftNode;
}
Tree *Tree::getRightTreeNode() {
    return rightNode;
}
Tree *Tree::getParentTreeNode() {
    return parentNode;
}

bool Tree::isLeafNode() {
    return leftNode == nullptr && rightNode == nullptr;
}
bool Tree::operator<(Tree &other) const {
    return treeWeight < other.treeWeight;
}
bool compareTreeNodes::operator()(Tree *leftNode, Tree *rightNode) {
    return (leftNode->getTreeWeight() > rightNode->getTreeWeight());
}

////////////////////////////////////////////////////////////////////////////////

BitHandler::BitHandler() : bytes{ZERO}, bitPositionInByte{ZERO} {}

void BitHandler::addBitToStream(bool bit) {
    if (bitPositionInByte < CHAR_BIT) {
        bytes.back() |= bit << (CHAR_BIT - bitPositionInByte - 1);
        bitPositionInByte++;
    } else {
        bytes.emplace_back(bit << (CHAR_BIT - 1));
        bitPositionInByte = 1;
    }
}

void BitHandler::addBitsToStream(std::vector<bool> &bits) {
    for (bool b : bits) {
        addBitToStream(b);
    }
}

void BitHandler::addByteToStream(unsigned char byte) {
    for (size_t i = 0; i < CHAR_BIT; ++i) {
        addBitToStream((byte >> (CHAR_BIT - i - 1)) & 1);
    }
}

unsigned BitHandler::howManyBitLefts() {
    return (CHAR_BIT - bitPositionInByte) % CHAR_BIT;
}

vector<unsigned char> &BitHandler::getBytesFromStream() {
    return bytes;
}