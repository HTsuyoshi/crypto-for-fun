#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *rot(char *input, int n_rot, int len, char *output)
{
	char alpha[] = "0abcdefghijklmnopqrstuvwxyz";
	char ALPHA[] = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int replace_char;

	for (int i=0; i < len; i++) {
		int ascii_value = (int) input[i];
		if (ascii_value > 96 && ascii_value < 123) {
			ascii_value -= 96;
			replace_char = (ascii_value + n_rot) % 26;
			output[i] = alpha[replace_char];
		} else if(ascii_value > 64 && ascii_value < 91) {
			ascii_value -= 64;
			replace_char = (ascii_value + n_rot) % 26;
			output[i] = ALPHA[replace_char];
		} else 
			output[i] = input[i];
	}
}

int is_digit(char *n_rot, int len)
{
	for (int i=0; i < len; i++)
		if (!isdigit(n_rot[i]))
			return 0;
	return 1;
}

int main(int argc, char **argv)
{
	char *n_rot = argv[2];
	char *input = argv[1];
	int digit_len = strlen(n_rot);

	if (argc != 3 || !is_digit(n_rot, digit_len))
	{
		printf ("Usage: rot <string> <number_of_rotations>");
		return 1;
	}
	
	int n_rot_int = atoi(n_rot);
	int output_len = strlen(argv[1]);

	char output[output_len];
	rot(input, n_rot_int, output_len, output);

	printf("%s", output);
	return 0;
}

