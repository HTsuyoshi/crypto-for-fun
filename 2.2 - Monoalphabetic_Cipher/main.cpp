#include <iostream>
#include <string>
#include <utility>
#include <vector>

//#define SUBSTITUTE {'b', 'a', 'd', 'c', 'f', 'e', 'h', 'g', 'j', 'i', 'l', 'k', 'n', 'm', 'p', 'o', 'r', 'q', 't', 's', 'v', 'u', 'x', 'w', 'z', 'y'}
#define SUBSTITUTE "badcfehgjilknmporqtsvuxwz"


char mono_alphabetic(char c)
{
    if (!isalpha(c)) return c;

    int offset = 'a';
    if (isupper(c)) offset = 'A';

    std::string substitute = SUBSTITUTE;

    c = substitute[c - offset];
    return c;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Usage:" << std::endl;
        std::cout << "\tmain plain_text" << std::endl;
        return EXIT_FAILURE;
    }

    std::string plain_text = argv[1],
                cipher_text = "";

    for (char c: plain_text) {
        cipher_text += mono_alphabetic(c);
    }

    std::cout << "\nPlain text:\n";
    std::cout << "\t" << plain_text << std::endl;

    std::cout << "\nCipher text:\n";
    std::cout << "\t" << cipher_text << "\n" << std::endl;

    return EXIT_SUCCESS;
}
