#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static char usage [] = "Usage: PolyRot <string> <key>\n";

void Rot (int ascii_value, int ascii_value_key, char *output, int aux_rot)
{
	// Input lowercase
	if (ascii_value > 96 && ascii_value < 123) {
	ascii_value -= 96;	
	output [aux_rot] = (char) ((ascii_value + ascii_value_key) % 26 + 96);

	// Input uppercase
	} else if (ascii_value > 64 && ascii_value < 91) {
	ascii_value -= 64;	
	output [aux_rot] = (char) ((ascii_value + ascii_value_key) % 26 + 64);
	
	// Dont rot numbers and symbols
	} else 
		output [aux_rot];
}

// PolyRot function
void PolyRot (char *input, int len, char *key, int key_len, char *output)
{
	// Show char to rot
	int aux_rot = 0;	

	while (1) {
		for (int i = 0; i < key_len; i++) {
			int ascii_value_key = (int) key[i];
			int ascii_value = (int) input[aux_rot];
			
			if (aux_rot == len)
				return;

			// Key lowercase
			if (ascii_value_key > 96 && ascii_value_key < 123) {
				ascii_value_key -= 96;
				Rot (ascii_value, ascii_value_key, output, aux_rot);
			
			// Key uppercase
			} else if (ascii_value_key > 64 && ascii_value_key< 91){
				ascii_value_key -= 64;
				Rot (ascii_value, ascii_value_key, output, aux_rot);

			// Dont rot numbers and symbols
			} else {
				output [aux_rot] = input [aux_rot];
			}
			aux_rot++;
		}
	}
}

// Verify if the second argument is a letter
int is_alpha (char *key, unsigned int key_len) 
{
	for (int i = 0; i < key_len; i++ )
		if (isalpha (key [i]))
			return 0;
	return 1;
}

int main (int argc, char **argv)
{
	// Errors
	if (argc != 3) {
		printf ("%s", usage);
		return 1;
	} else if (is_alpha(argv [2], strlen (argv [2]))) {
		printf ("%s", usage);
		return 1;
	} else if (strlen (argv [1]) > 65535 || strlen (argv [2]) > 65535) {
		printf ("Argument(s) too long");
		printf ("%s", usage);
		return 1;
	}

	// Key
	char *key = argv [2];
	int key_len = strlen (key);

	// Input
	char *input = argv [1];
	int len = strlen (argv [1]);

	// Output
	char output [len + 1];
	output [len] = '\0';

	PolyRot(input, len, key, key_len, output);

	printf("%s\n", output);
	return 0;
}
