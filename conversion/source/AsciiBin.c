#include <stdio.h>

static char usage [] = "AsciiBin <string>\n";

void AsciiBin (char* string)
{
	int charIndex = 0;
	while (string [charIndex] != '\0') {
		for (int i = 7; i >= 0; i--)
			if (string [charIndex] & 1 << i)
				printf ("1");
			else
				printf ("0");
		charIndex++;
	}
	printf ("\n");
}

int main (int argc, char** argv)
{
	if (argc != 2) {
		printf ("%s", usage);
		return 1;
	}

	AsciiBin (argv [1]);

	return 0;
}

