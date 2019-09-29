#include <overflow.h>

/* This function builds a string based on letter for start and count for length and outputs without newline */
char * printAlphabet(int length, char character, int alphabetCount)
{
	/* length = length of total string
	 * character = character to start "alphabet with"
	 * alphabetCount = how many times to add each character to string
	 */

	int i;
	int j;
	int sum;
	int interval;
	char *buff;
	
	/* string is stored here */
	buff = calloc(length + 1, sizeof(char));
	/* num of cycles to go through to add character n times and increase character */
	interval = length / alphabetCount;
	/* total of characters added to the buffer */
	sum = 0;

	/* in intervals of alphabetCount we add 4 of each letter to the buffer */
	for(i = 0; i < interval; i++){
		for(j = 0; j < alphabetCount; j++){
			buff[ (i * alphabetCount) + j] = character;
			sum++;
		}
		character++;
	}

	/* fills the rest of the buffer */
	for(i = sum ; i < length; i++){
		buff[i] = character;
		sum++;
	}

	return buff;	// Return number of characters printed
}

/* Basic function to print a set length of character to stdout */
char * printString(int length, char character)
{
	char *buff;

	buff = calloc(length + 1, sizeof(char));
	memset(buff, character, sizeof(char) * length);

	return buff;
}