#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static char usage [] = "Usage: Rot <string> <number of rotations>\n";

// Rot function
void rot (char *input, char *output, unsigned int len, unsigned int nRot)
{
	int replaceChar;

	// Rot all chars
	for (int i = 0; i < len; i++) {
		int asciiValue = (int) input[i];

		// Rot lowercase 
		if (asciiValue > 96 && asciiValue < 123) {
			asciiValue -= 96;
			replaceChar = (asciiValue + nRot) % 26;
			output [i] = (char) (replaceChar + 96);
		} 

		// Rot uppercase
		else if (asciiValue > 64 && asciiValue < 91) {
			asciiValue -= 64;
			replaceChar = (asciiValue + nRot) % 26;
			output [i] = (char) (replaceChar + 64);
		}

		// Dont rot numbers and symbols
		else 
			output [i] = input [i];
	}
}

// Verify if the second argument is a number
int is_digit (char *nRot, unsigned int len)
{
	for (int i = 0; i < len; i++)
		if (!isdigit(nRot[i]))
			return 0;
	return 1;
}

int main (int argc, char **argv)
{

	if (argc != 3) {
		printf ("%s", usage);
		return 1;
	} else if (!is_digit (argv [2], strlen (argv [2]))) {
		printf ("%s", usage);
		return 1;
	} else if (atoi (argv [2]) > 65535) {
		printf ("Second argument too high\n");
		printf ("%s", usage);
		return 1;
	} else if (strlen (argv [1]) > 65535){
		printf ("First argument too long\n");
		printf ("%s", usage);
		return 1;
	}

	// Input
	char *input = argv [1];
	unsigned int nRot = atoi (argv [2]);

	// Output
	unsigned int output_len = strlen (argv [1]);
	char output [output_len + 1];
	output [output_len] = '\0';

	rot (input, output, output_len, nRot);

	printf("%s\n", output);
	return 0;
}
