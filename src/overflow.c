#include "overflow.h"

/* This function will print out usage info for users */
void usage()
{
  printf(\
    "------------OVERFLOWING PROJECT HELP PAGE------------\n\n\
The -c argument is required\n\
\n\
-a, --alphabet, this sets a flag which prints\n\
    an alphabet instead of a single character\n\n\
-c, --count, this defines how many characters\n\
    will be printed or how long the alphabet will be\n\n\
-l, --letter, this defines the character that\n\
    is printed or where the alphabet begins\n\n\
-h, --help\n\
	displays this menu\n\n");

  exit(1); // This kills the program early because invalid options were supplied
}

/* This function parses all arguments supplied and sets flags accordingly */
void setFlags(int argc, char **argv, bool *alphabet, int *alphabetCount, int *count, char letter[2])
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

/* This function builds a string based on letter for start and count for length and outputs without newline */
int printAlphabet(int length, char character[], int alphabetInterval, char *stringBuffer)
{
  int sum; // Init iterator outside of loop so it can be returned

  /* This for loop actually builds the string */
  for (sum = 0; sum < length; sum += alphabetInterval)
  {
    /* If the remaining amount of characters is above the interval then enter here */
    if (length - sum > alphabetInterval)
    {
      memset(stringBuffer + sum, character[0], alphabetInterval); // Add characters to buffer
      character[0] += 1;                                          // Iterate the character
    }

    /* Else enter here to finish off the remaining characters and break loop */
    else
    {
      memset(stringBuffer + sum, character[0], (length - sum));   // Add remaining characters
    }
  }
  return sum;                 // Return number of characters printed
}

/* Basic function to build a null terminated string */
int printString(int length, char character[2], char *stringBuffer)
{
  memset(stringBuffer, character[0], length); // Builds string

  return 0; // return 0 for now
}
