#include <stdio.h>
#include <string.h>
#include <math.h>

static char hexAlfa [16] = "0123456789abcdef";
static char usage [] = "Usage: ascii_hex <string>\n";

void byteToHex (int byteArray[], char* hex, int i) 
{
	int int2 = 0, int1 = 0;
	char char2, char1;

	// Convert bits to decimal
	
	for (int i = 0; i < 4; i++)
		if (byteArray [i])
			int2 += (int) pow (2, i);
	
	for (int i = 4; i < 8; i++)
		if (byteArray [i])
			int1 += (int) pow (2, i - 4);

	char2 = hexAlfa [int2];
	char1 = hexAlfa [int1];
	
	hex [2 * i + 1] = char2;
	hex [2 * i] = char1;
}

void charToByte (char* text, int byteArray[]) 
{	
	int numValue = (int) *text;

	// Store bytes
	for (int i = 0; i < 8; i++) {
		byteArray [i] = (numValue & 1 << i) ? 1 : 0;
		int n = numValue & 1 << i ? 1 : 0;
	}
}

void* stringToHex (char* text, char* hexText) 
{
	// Transform every character
	for (int i = 0; i < strlen (text); i++) {
		int byteArray [8];
		charToByte (text + i, byteArray);
		byteToHex (byteArray, hexText, i);
	}
}

int main (int argc, char **argv)
{	
	if (argc != 2) {
		printf ("%s", usage);
		return 1;
	}

	// Initialize the string
	char hexText [2 * strlen (argv[1]) + 1];
	hexText [2 * strlen (argv[1])] = '\0';
	
	// Transform
	stringToHex (argv [1], hexText);

	// Print
	printf ("%s\n", hexText);
	return 0;
}
