/*******************************************************************************
 * @project Static and Adaptive Huffman Coding
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subjeCt KKO
 * @file model.h
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#ifndef MODEL_H
#define MODEL_H

#include <stdint.h>
#include <stdlib.h>

void applyModel(unsigned char *fileBytes, size_t fileLength);
void reverseModel(unsigned char *fileBytes, size_t fileLength);

#endif