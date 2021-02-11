#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *rot (char *input, unsigned int n_rot, char *output, unsigned int len)
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

int is_digit(char *n_rot, unsigned int len)
{
	for (int i=0; i < len; i++)
		if (!isdigit(n_rot[i]))
			return 0;
	return 1;
}

int main(int argc, char **argv)
{
	char *n_rot_str = argv[2];
	int n_rot_len= strlen(n_rot_str);
	
	// Input
	char *input = argv[1];
	unsigned int n_rot = atoi(n_rot_str);

	// Output
	unsigned int output_len = strlen(argv[1]);
	char output[output_len + 1];
	output[output_len] = '\0';

	if (argc != 3 || argv[1] == NULL) {
		printf ("Usage: rot <string> <number_of_rotations>\n");
		return 1;
	} else if (!is_digit(n_rot_str, n_rot_len)) {
		printf ("This isn't a number\n");
		printf ("Usage: rot <string> <number_of_rotations>\n");
		return 1;
	} else if (n_rot_len > 4) {
		printf ("Second argument too high\n");
		printf ("Usage: rot <string> <number_of_rotations>\n");
		return 1;
	} else if (strlen(argv[2]) > 65535){
		printf ("First argument too long\n");
		printf ("Usage: rot <string> <number_of_rotations>\n");
	}

	rot(input, n_rot, output, output_len);

	printf("%s\n", output);
	return 0;
}

