#include "overflow.h"
#include <string.h>

/* This function builds a string based on letter for start and count for length and outputs without newline */
int printAlphabet(int length, char *character, int alphabetInterval, char *stringBuffer)
{
  int sum; // Init iterator outside of loop so it can be returned

  /* This for loop actually builds the string */
  for (sum = 0; sum < length; sum += alphabetInterval)
  {
    /* If the remaining amount of characters is above the interval then enter here */
    if (length - sum > alphabetInterval)
    {
      memset(stringBuffer + sum, *character, alphabetInterval); // Add characters to buffer
      *character += 1;                                          // Iterate the character
    }

    /* Else enter here to finish off the remaining characters and break loop */
    else
    {
      memset(stringBuffer + sum, *character, (length - sum));   // Add remaining characters
    }
  }
  return sum;                 // Return number of characters printed
}

/* Basic function to build a null terminated string */
int printString(int length, char *character, char *stringBuffer)
{
  memset(stringBuffer, *character, length); // Builds string

  return 0; // return 0 for now
}