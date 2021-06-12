#include <stdio.h>

static char usage [] = "BinAscii <string>\n";
static char invalid [] = "Invalid string, size is'nt right\n";
static char invalid2 [] = "Invalid string, string need to be only 1 and 0\n";

void BinAscii (char* Bin)
{
	int charIndex = 0;
	while (Bin [charIndex] != '\0') {
		int charValue = 0;
		for (int i = 7; i >= 0; i--, charIndex++) 
			if (Bin [charIndex] == '1')
				charValue = charValue | 1 << i;
		printf ("%c", charValue);
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
	int size = 0;
	if (argv [1])
		while(argv [1][size] != '\0')
			size++;

	if (argc != 2) {
		printf ("%s", usage);
		return 1;
	} else if (size % 8 != 0) {
		printf ("%s", invalid);
		return 1;
	} else if (checkString (argv [1])) {
		printf ("%s", invalid2);
		return 1;
	}

	BinAscii (argv [1]);

	return 0;
}
