#include <stdio.h>
#include <string.h>

static char alfaB64 [64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static char usage [] = "Usage: AsciiB64 <string>\n";

void bitToB64 (int bitArray [], char* b64Char)
{
	// Count to padding
	int charCount= 0, i = 0;

	// Iterate 6 bit to 6 bit in bitArray
	while (bitArray [i] != -1 && i < 24) {
		int charValue = 0;

		// Transform 6 bits to decimal
		for (int j = 0; j < 6; j++) {
			if (bitArray [i + j] == 1)
				charValue += 255 & 1 << 5 - j;	
		}

		// Store the char
		b64Char [charCount] = alfaB64 [charValue]; 

		i += 6;
		charCount++;
	}
	
	// Padding =
	while (charCount < 4) {
		b64Char [charCount] = '=';
		charCount++;
	}
}

void char_to_bit (char* chars, int size, int bitArray [])
{
	// First char bits
	for (int i = 0; i < 8; i++){
		if (chars [0] & 1 << 7 - i)
			bitArray [i] = 1;
		else
			bitArray [i] = 0;
	}

	// Second char bits
	if (size > 1)
	for (int i = 0; i < 8; i++)
		if (chars [1] & 1 << 7 - i)
			bitArray [i + 8] = 1;
		else
			bitArray [i + 8] = 0;

	// Third char bits
	if (size > 2)
	for (int i = 0; i < 8; i++)
		if (chars [2] & 1 << 7 - i)
			bitArray [i + 16] = 1;
		else
			bitArray [i + 16] = 0;
	
	// Padding zeros
	if (size < 3)
	for (int i = size * 6; i < (size + 1) * 6; i++)
		if (bitArray[i] == -1)
			bitArray[i] = 0;
}

void stringBase64 (char* base64, int size, char* text)
{
	// Convert every 1/2/3 chars
	for (int i = 0; i < size; i += 3) {
		// Calc each 1/2/3 char to 4 in b64
		int convertSize;
		if (size - i < 3)
			convertSize = size - i;
		else
			convertSize = 3;

		// Init bitArray to -1
		int bitArray[24] = { [0 ... 23] -1 };
		char_to_bit (text + i, convertSize, bitArray);
	
		// Init b64 char
		char b64Char [4];
		bitToB64 (bitArray, b64Char);

		// Put b64 char in base64 String
		for (int j = 0 ; j < 4; j++)
			base64 [i*4/3 + j] = b64Char[j];
	}
}

int main (int argc, char** argv)
{
	if (argc != 2) {
		printf("%s", usage);
		return 1;
	}

	// Output size
	int size = (int) 4 * (strlen (argv [1]) / 3);
	if (strlen (argv [1] )% 3 != 0)
		size += 4;

	// Output
	char base64 [size + 1];
	base64 [size] = '\0';

	stringBase64 (base64, strlen (argv [1]), argv [1]);
	
	printf ("%s\n", base64);
	return 0;
}
