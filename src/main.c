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
  char letter[2]     = "A\n"; // This is a sane default for output, 0x41

  // Sets flags in seperate function to keep only keep important logic in main
  setFlags(argc,
           argv,
           &alphabet,
           &alphabetCount,
		   &count,
		   letter);

  /* PROGRAM BEGINS HERE */
  char *mainBuffer = calloc(count + 1, sizeof(char)); // This sets up the buffer for the string to be built

  // If the alphabet argument is set then the program will print alphabetically
  if (alphabet == true)
  {
    printAlphabet(count, letter, alphabetCount, mainBuffer);
  }
  else
  {
    printString(count, letter, mainBuffer);
  }

  /*
      Later on in development this is where the function for addresses will be added
  */

  printf("%s", mainBuffer);             // Print the created string from buffer
  free(mainBuffer);                     // Free allocated memory for string

  printf("\n"); // Terminate the string built previously with a new line

  return 0;
}
