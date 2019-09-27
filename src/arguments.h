// header guards
#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

/* If compiled on Windows it will use a packed in library if on Linux it will use Included*/
#if defined(_WIN32)
#include "getopt.h"
#endif

#if defined(__linux__)
#include <getopt.h>
#endif

#include "usage.h"

#include <stdbool.h>
#include <stdio.h> 
#include <string.h> 

/* This function parses all arguments supplied and sets flags accordingly */
void setFlags(int argc, char** argv, bool* alphabet, int* alphabetCount, int* count, char letter[2]);

#endif
