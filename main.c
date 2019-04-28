#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

/*
===================
     PLANNING
===================
I need to change the help page and add a help option to the argument list

For alphabet functions it may be a good idea to rollover the character after
several iterations

Consider changing several of the functions to accept pointers
*/

// This function will print out usage info for users
void usage()
{
  printf(\
    "------------OVERFLOWING PROJECT HELP PAGE------------\n\
The -c argument is required\n\
\n\
-a, --alphabet, this sets a flag which prints\n\
    an alphabet instead of a single character\n\
-c, --count, this defines how many characters\n\
    will be printed or how long the alphabet will be\n\
-l, --letter, this defines the character that\n\
    is printed or where the alphabet begins\n");
  exit(1); // This kills the program early because invalid options were supplied
}

// This function builds a string based on letter for start and count for length and outputs without newline
int printAlphabet(int length, char character[2], int alphabetInterval)
{
  int iterator;

  for (iterator = 1; iterator <= length; iterator++)
  {
    printf("%s", character);
    if (iterator % alphabetInterval == 0)
    {
      character[0] += 1;
    }
  }
  return iterator;
}

// This function builds a string based on letter and count and outputs it without a newline
int printString(int length, char character[2])
{
  // Basic loop to build output given length
  int iterator;

  for (iterator = 0; iterator < length; iterator++)
  {
    printf("%s", character);
  }

  return iterator; // return chars printed
}

int main(int argc, char ** argv)
{
  /* INIT FLAGS */
  bool alphabet      = false; // If this flag is set then output will be organized as an alphabet so AAAABBBB...
  int  alphabetCount = 4;     // This var holds the interval at which the character is incremented for alphabet flag
  int  count         = 0;     // This var is required to be set, it determines how long output will be
  char letter[2]     = "A\0"; // This is a sane default for output, 0x41

  /* Parse command line options.  */
  char c; // init argument holder

  // long_options struct which defines the long names for arguments
  static struct option long_options[] =
  {
    {"alphabet"   , optional_argument, NULL, 'a'},
    {"count"      , required_argument, NULL, 'c'},
    {"letter"     , required_argument, NULL, 'l'},
    {NULL, 0, NULL, 0}
  };

  // This is the beginning of the getopt argument parser
  while ( (c = getopt_long (argc, argv, "a::c:l:", long_options, NULL)) != -1)
  {
    switch (c)
    {
      // This case sets a flag that causes the program to print out alphabetically and has optional args for interval
      case 'a':
        alphabet = true;
        // This comparison will only attempt to set the alphabetCount if a arg is supplied at all
        if ((optarg != NULL) && ((alphabetCount = atoi(optarg) ) == 0))
        {
          printf("Chars requires a whole number above 0 ONLY\n");
          break;
        }

        break;

      // This case defines how many characters to print
      case 'c':
        if ((count = atoi(optarg)) == 0) // I think this could create bugs because of assignment
        {
          printf("Chars requires a whole number above 0 ONLY\n");
          break;
        }
        // printf("Number of characters inputed is %d\n", chars); // Debugging
        break;

      // This case defines the character that will be printed unless alphabet is set
      case 'l':
        letter[0] = ((char)*optarg); // I legitimately have no idea why this works but ok.
        printf("%s\n", letter); // This will need validation, this is also debugging info
        break;

      // This case is a catch all in case user gives invalid argument
      default:
        usage();
    }
  }

  /* PROGRAM BEGINS HERE */

  // This if statement prints usage information in the case that runs the program without args or without -c
  if (argc == 1 || count == 0 || alphabetCount == 0)
  {
    usage();
  }

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
