// header guards
#ifndef ARGUMENTS_H_
#define ARGUMENTS_H_

#include <stdbool.h>

/* This function parses all arguments supplied and sets flags accordingly */
void setFlags(int argc, char** argv, bool* alphabet, int* alphabetCount, int* count, char *letter);

#endif
