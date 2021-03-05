#include <stdio.h>

static char usage [] = "simpleXorAtoB <string> <key>\n";

void xor (char* plainText, char* key)
{
	// Loop through the string
	for (int i = 0, keyCount = 0; plainText [i] != '\0'; i++, keyCount++) {
		// Loop through the key 
		if (key [keyCount] == '\0')
			keyCount = 0;

		// Print cipherText in bits
		for (int j = 7; j >= 0; j--) {
			// printf ("%d ^ %d = ", (plainText [i] & 1 << j), (key [keyCount] & 1 << j));
			if ((plainText [i] & 1 << j) ^ (key [keyCount] & 1 << j))
				printf ("1");
			else
				printf ("0");
			//printf ("\n");
		}
	}
	printf ("\n");
}

int main (int argc, char** argv)
{
	// Errors
	if (argc != 3) {
		printf ("%s", usage);
		return 1;
	}

	xor (argv [1], argv [2]);

	return 0;
}

