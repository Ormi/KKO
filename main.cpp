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

#define OUTPUT_SUCCESS 0
#define OUTPUT_ERROR 1

const char *HELP = 
    "This is program for Static and Adaptive Huffman Coding";

int main(int argc, char **argv) {
  if (argc == 2) {
    if (strcmp(argv[1], "-h") == 0) {
      puts(HELP);
      return OUTPUT_SUCCESS;
    }
  }
}