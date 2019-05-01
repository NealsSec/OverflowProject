#include "main.h"

int main(int argc, char ** argv)
{
  /* INIT FLAGS */
  bool alphabet      = false; // If this flag is set then output will be organized as an alphabet so AAAABBBB...
  int  alphabetCount = 4;     // This var holds the interval at which the character is incremented for alphabet flag
  int  count         = 0;     // This var is required to be set, it determines how long output will be
  char letter[1]     = "A"; // This is a sane default for output, 0x41

  bool *ptr_alphabet      = &alphabet;
  int  *ptr_alphabetCount = &alphabetCount;
  int  *ptr_count         = &count;

  // Sets flags in seperate function to keep only keep important logic in main
  setFlags(argc,
           argv,
           ptr_alphabet,
           ptr_alphabetCount,
		       ptr_count,
		       letter);

  /* PROGRAM BEGINS HERE */

  // If the alphabet argument is set then the program will print alphabetically
  if (alphabet == true)
  {
    printAlphabet(count, letter, alphabetCount);
  }
  else
  {
    printString(count, letter);
  }

  printf("\n"); // Terminate the string built previously with a new line

  return 0;
}
