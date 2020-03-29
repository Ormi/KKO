/*******************************************************************************
 * @project Static and Adaptive Huffman Coding 
 * @author Michal Ormos
 * @email xormos00@stud.fit.vutbr.cz
 * @date March 2020
 * @subjeCt KKO
 * @file main.cpp
 * @description This file read arguments, parse them and run program
*******************************************************************************/

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#define OUTPUT_SUCCESS 0
#define OUTPUT_ERROR 1

#include "adaptive.h"
#include "static.h"
#include "model.h"

size_t fileLength;
const char *HELP = 
    "This is program for Static and Adaptive Huffman Coding\n"
    "Version 1.0.0\n"
    "\n"
    "Usage:\n"
    "  -c \n      Application with compress input file\n"
    "  -d \n      Application will decompress input file\n"
    "  -a \n      If enabled, dynamic Huffman coding will be used. Other wise static Huffman coding will be used.\n"
    "  -m \n      Activate model\n"
    "  -i <input_file>\n      Name of input stream fo compression/decompression.\n"
    "  -o <output_file>\n      Name of output stream for compresion/decopresion.\n"
    "  -w <width_value>\n      Set the width of the image, width >= 1.\n"
    "  -h\n      Show this help windows.\n"
    "\n"
    "Created by @xormos00 for KKO, BUT FIT in MIT license.";

unsigned char *readFile(char *inputFile) {

    FILE *inputStream;
    size_t fileSize;
    unsigned char *fileBytes;

    /* Read the input file */
    inputStream = fopen(inputFile, "r");
    if (!inputStream) {
        fprintf(stderr, "Cannot read the input file. Please check if it exists.\n");
    }

    fseek(inputStream, 0L, SEEK_END);
    fileSize = ftell(inputStream);
    fseek(inputStream, 0L, SEEK_SET);
    
    fileBytes = (unsigned char *)malloc(sizeof(unsigned char) * fileSize);
    fileLength = fread(fileBytes, sizeof(unsigned char), fileSize, inputStream);
    fclose(inputStream);

    return fileBytes;

}

int main(int argc, char **argv) {
    int argumentParser;
    int compressMode = 1; /* 1 is static, 2 is dynamic */
    bool compress = false;
    bool decompress = false;
    char *inputFile = NULL;
    char *outputFile = NULL;
    char *model = NULL;

    if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            puts(HELP);
            return OUTPUT_SUCCESS;
        }
    }

    while ((argumentParser = getopt(argc, argv, "cdi:o:ma:w:")) != -1) {    
        switch (argumentParser) {
        case 'c':
            compress = true;
            break;
        case 'd':
            decompress = true;
            break;
        case 'i':
            inputFile = optarg;
            break;
        case 'o':
            outputFile = optarg;
            break;
        case 'm':
            model = "pix";
            break;
        case 'a':
            compressMode = 2;
            break;
        case 'w':
            // ?
            break;
        default:
            fprintf(stderr, "%s\n", HELP);
            return OUTPUT_ERROR;
        }
    }

    if ((compress == false) && (decompress == false)) {
        fprintf(stderr, "Selecting compress mode is mandatory.\n");
        return OUTPUT_ERROR;
    }

    if (!inputFile) {
        fprintf(stderr, "Defining input file is mandatory.\n");
        return OUTPUT_ERROR;
    }

    if (!outputFile) {
        fprintf(stderr, "Defining output file is mandatory.\n");
        return OUTPUT_ERROR;
    }

    unsigned char *fileBytes;
    fileBytes = readFile(inputFile);
    

    /* Prepare the output file */
    FILE *outputStream = fopen(outputFile, "w");
    if (!outputStream) {
        fprintf(stderr, "Cannot read the output file. Please check if it exists.\n");
        return OUTPUT_ERROR;
    }    

    // printf(fileBytes);
    printf("%zu\n", fileLength);
	// for (int i = 0; i < 100000; i++){
	// 	printf("%u", fileBytes[i]);
	// 	std::cout << std::endl;
	// }
}