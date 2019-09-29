// header guards
#ifndef OVERFLOW_H_
#define OVERFLOW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function builds a string based on letter for start and count for length and outputs without newline */
int printAlphabet(int length, char character, int alphabetInterval, char *buff);

/* Basic function to build a null terminated string */
int printString(int length, char character, char *buff);

#endif
