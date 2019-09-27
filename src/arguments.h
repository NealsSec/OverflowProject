// header guards
#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

#include "getopt.h" // I changed this to "" to give a local file priority over the lib in Visual Studio
#include <stdbool.h>
#include <stdio.h> 
#include <string.h> 

/* This function parses all arguments supplied and sets flags accordingly */
void setFlags(int argc, char** argv, bool* alphabet, int* alphabetCount, int* count, char letter[2]);

#endif
