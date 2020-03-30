/*******************************************************************************
 * @project Static and Adaptive Huffman Coding 
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subject KKO
 * @file tree.cpp
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#include "tree.h"

tree::tree():parentNode{nullptr},leftNode{nullptr},rightNode{nullptr},treeWeight{0},nodeSymbol{0},treeOrder{0} {}
tree::tree(uint16_t nodeSymbol, size_t treeWeight)
:parentNode{nullptr},leftNode{nullptr},rightNode{nullptr},treeWeight{treeWeight},nodeSymbol{nodeSymbol} {}
tree::tree(size_t treeWight, tree *leftNode, tree *rightNode)
:treeWeight{treeWeight}, parentNode{nullptr}, leftNode{leftNode}, rightNode{rightNode} {}

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