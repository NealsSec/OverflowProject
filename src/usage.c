#include "usage.h"
#include <stdio.h>
#include <stdlib.h>

/* This function will print out usage info for users */
void usage()
{
  printf(\
    "------------OVERFLOWING PROJECT HELP PAGE------------\n\n\
The -c argument is required\n\
\n\
-a, --alphabet=, this sets a flag which prints\n\
    an alphabet instead of a single character\n\n\
-c, --count, this defines how many characters\n\
    will be printed or how long the alphabet will be\n\n\
-l, --letter, this defines the character that\n\
    is printed or where the alphabet begins\n\n\
-h, --help, displays this menu\n\n");

  exit(1); // This kills the program early because invalid options were supplied
}
