// header guards
#ifndef OVERFLOW_H_
#define OVERFLOW_H_

#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void usage();
void setFlags(int, char **, bool *,int *, int *, char *);
int printAlphabet(int, char *, int);
int printString(int, char *);

#endif
