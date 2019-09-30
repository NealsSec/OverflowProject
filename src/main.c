#include "main.h"
#include "arguments.h"
#include "overflow.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  /* INIT FLAGS */
  bool alphabet      = false; // If this flag is set then output will be organized as an alphabet so AAAABBBB...
  int  alphabetCount = 4;     // This var holds the interval at which the character is incremented for alphabet flag
  int  count         = 0;     // This var is required to be set, it determines how long output will be
  char letter        = 'A';   // default char for output, 0x41

  /* Sets flags in seperate function to keep only keep important logic in main */
  setFlags(argc,
           argv,
           &alphabet,
           &alphabetCount,
           &count,
           &letter);

  char* mainString = calloc(count + 1, sizeof(char));

  // If the alphabet argument is set then the program will print alphabetically
  if (alphabet == true)
  {
    printAlphabet(count, letter, alphabetCount, mainString);
  }
  else
  {
    printString(count, letter, mainString);
  }

  /*
      Later on in development this is where the function for addresses will be added
  */

  printf("%s\n", mainString);
  free(mainString);

  return 0;
}
