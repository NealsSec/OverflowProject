#include "overflow.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function builds a string based on letter for start and count for length and outputs without newline */
int printAlphabet(int length, char character, int alphabetCount, char *buff)
{
	/* length = length of total string
	 * character = character to start "alphabet with"
	 * alphabetCount = how many times to add each character to string
	 */

	int i;
	int j;
	/* num of cycles to go through to add character n times and increase character */
	int interval = length / alphabetCount;
	/* total of characters added to the buffer */
	int sum = 0;

	/* in intervals of alphabetCount we add 4 of each letter to the buffer */
	for(i = 0; i < interval; i++)
	{
		for(j = 0; j < alphabetCount; j++)
		{
			buff[ (i * alphabetCount) + j] = character;
			sum++;
		}
		character++;
	}

	/* fills the rest of the buffer */
	for(i = sum ; i < length; i++)
	{
		buff[i] = character;
		sum++;
	}

	return sum;	// Return number of characters printed
}

/* Basic function to print a set length of character to stdout */
int printString(int length, char character, char *buff)
{
	memset(buff, character, sizeof(char) * length);
	return 0;
}
