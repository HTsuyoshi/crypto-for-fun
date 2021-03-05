#include <stdio.h>

static char usage [] = "simpleXorBtoA <string> <key>\n";
static char invalid [] = "Invalid string, size is'nt right\n";
static char invalid2 [] = "Invalid string, string need to be only 1 and 0\n";

void xor (char* binStr, char* key)
{
	// Iterate through the String and the key
	for (int binIndex = 0, keyIndex = 0; binStr [binIndex] != '\0'; binIndex += 8) {

		// Loop through the key
		if (key [keyIndex] == '\0')
			keyIndex = 0;

		// Char to xor
		int charValue = 0;

		// Take the string bits
		for (int i = 7; i >= 0; i--) {

			// Key bit
			int keyBool;
			if (key [keyIndex] & 1 << 7 - i)
				keyBool = (key [keyIndex] & 1 << i) / (key [keyIndex] & 1 << i);
			else 
				keyBool = 0;

			// Compare bits
			if ((binStr [binIndex + i] == '1') ^ (keyBool)) 
				charValue = charValue | 1 << 7 - i;
		}

		printf ("%c", charValue);
		keyIndex++;
	}
	printf ("\n");
}

int checkString (char* string)
{
	for (int i = 0; string [i] != '\0'; i++)
		if (string [i] != '0' && string [i] != '1')
			return 1;
	return 0;
} 

int main (int argc, char** argv)
{
	// Count argv[2] size
	int cipherTextLen = 0;
	if (argv [1])
		while (argv [1][cipherTextLen] != '\0') 
			cipherTextLen++;

	// Errors
	if (argc != 3) {
		printf ("%s", usage);
		return 1;
	} else if (cipherTextLen % 8 != 0) {
		printf ("%s", invalid);
		return 1;
	} else if (checkString (argv[1])) {
		printf ("%s", invalid2);
		return 1;
	}

	xor (argv [1], argv [2]);

	return 0;
}
*/
