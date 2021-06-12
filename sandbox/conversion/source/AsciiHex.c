#include <stdio.h>
#include <string.h>

static char usage[] = "Usage: AsciiHex <string>\n";

char hexDigit(unsigned n)
{
	if (n < 10)
		return n + '0';
	else 
		return (n - 10) + 'A';
}

void charToHex(char c, char hex[], int i)
{
	hex [i] = hexDigit (c / 0x10);
	hex [i+1] = hexDigit (c % 0x10);
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		printf ("%s", usage);
		return 1;
	}

	// Init the string
	char hexText [2 * strlen (argv[1]) + 1];
	hexText [2 * strlen (argv[1])] = '\0';

	// Transform
	for (int i = 0; i < strlen (argv[1]); i++) {
		charToHex (argv[1][i], hexText, i*2);
	}

	// Print
	printf("%s\n", hexText);
	return 0;
}
