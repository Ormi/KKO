/*******************************************************************************
 * @project Static and Adaptive Huffman Coding
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subject KKO
 * @file model.h
 * @description Pixel difference model
*******************************************************************************/

#include "model.h"

/**
 * @TODO
 */
void applyModel(unsigned char *fileBytes, size_t fileLength) {
    unsigned char previousByteValue = fileBytes[0];
    size_t position = 1;
    while ( position < fileLength ) {
        unsigned char currentBytevalue = fileBytes[position];
        fileBytes[position] = currentBytevalue - previousByteValue;
        previousByteValue = currentBytevalue;
        position++;
    }
}

/**
 * @TODO
 */
void reverseModel(unsigned char *fileBytes, size_t fileLength) {
    size_t position = 1;
    while (position < fileLength) {
        unsigned char currentByteValue = fileBytes[position];
        fileBytes[position] = currentByteValue + fileBytes[position--];
        position++;
    }
}

