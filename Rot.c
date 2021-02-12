#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Rot function
void rot (char *input, char *output, unsigned int len, unsigned int n_rot)
{
	int replace_char;

	// Rot all chars
	for (int i=0; i < len; i++) {
		int ascii_value = (int) input[i];

		// Rot lowercase 
		if (ascii_value > 96 && ascii_value < 123) {
			ascii_value -= 96;
			replace_char = (ascii_value + n_rot) % 26;
			output[i] = (char) (replace_char + 96);
		} 

		// Rot uppercase
		else if(ascii_value > 64 && ascii_value < 91) {
			ascii_value -= 64;
			replace_char = (ascii_value + n_rot) % 26;
			output[i] = (char) (replace_char + 64);
		}

		// Dont rot numbers and symbols
		else 
			output[i] = input[i];
	}
}

// Verify if the second argument is a number
int is_digit(char *n_rot, unsigned int len)
{
	for (int i=0; i < len; i++)
		if (!isdigit(n_rot[i]))
			return 0;
	return 1;
}

int main(int argc, char **argv)
{
	char usage[] = "Usage: Rot <string> <number of rotations>\n";

	if (argc != 3) {
		printf ("%s", usage);
		return 1;
	} else if (!is_digit(argv[2], strlen(argv[2]))) {
		printf ("%s", usage);
		return 1;
	} else if (atoi(argv[2]) > 65535) {
		printf ("Second argument too high\n");
		printf ("%s", usage);
		return 1;
	} else if (strlen(argv[1]) > 65535){
		printf ("First argument too long\n");
		printf ("%s", usage);
		return 1;
	}

	// Input
	char *input = argv[1];
	unsigned int n_rot = atoi(argv[2]);

	// Output
	unsigned int output_len = strlen(argv[1]);
	char output[output_len + 1];
	output[output_len] = '\0';

	rot(input, output, output_len, n_rot);

	printf("%s\n", output);
	return 0;
}
