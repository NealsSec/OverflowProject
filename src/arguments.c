#include "arguments.h"

/* If compiled on Windows it will use a packed in library if on Linux it will use Included*/
#if defined(_WIN32)
#include "agetopt.h"
#endif

#if defined(__linux__)
#include <getopt.h>
#endif

#include "usage.h"

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

/* This function parses all arguments supplied and sets flags accordingly */
void setFlags(int argc, char **argv, bool *alphabet, int *alphabetCount, int *count, char *letter)
{
  /* Parse command line options.  */
  char c; // init argument holder

  // long_options struct which defines the long names for arguments
  static struct option long_options[] =
  {
    {"alphabet"   , optional_argument, NULL, 'a'},
    {"count"      , required_argument, NULL, 'c'},
    {"letter"     , required_argument, NULL, 'l'},
    {"help"       , no_argument,       NULL, 'h'},
    {NULL, 0, NULL, 0}
  };

  bool countSet = false; // This flag is set by count arg and will not allow the program to run if not true

  // This is the beginning of the getopt argument parser
  while ( (c = getopt_long (argc, argv, "a::c:l:h", long_options, NULL)) != -1)
  {
    switch (c)
    {
      // This case sets a flag that causes the program to print out alphabetically and has optional args for interval
      case 'a':
        *alphabet = true;
        // This comparison will only attempt to set the alphabetCount if a arg is supplied at all
        if ((optarg != NULL) && ((*alphabetCount = atoi(optarg) ) == 0))
        {
          printf("Chars requires a whole number above 0 ONLY\n");
          break;
        }

        break;

      // This case defines how many characters to print
      case 'c':
        countSet = true; // Sets flag to true to allow the rest of the program to run
        if ((*count = atoi(optarg)) == 0) // I think this could create bugs because of assignment
        {
          printf("Chars requires a whole number above 0 ONLY\n");
          break;
        }
        // printf("Number of characters inputed is %d\n", chars); // Debugging
        break;

      // This case defines the character that will be printed unless alphabet is set
      case 'l':
		    strncpy(letter, optarg, 1);
        break;

      case 'h':
        usage();
        break;

      // This case is a catch all in case user gives invalid argument
      default:
        usage();
    }
  }

  // This if statement prints usage information in the case that runs the program without args or without -c
  if (countSet == false || alphabetCount == 0)
  {
    usage();
  }
}
