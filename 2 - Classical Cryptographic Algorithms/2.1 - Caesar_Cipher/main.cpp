#include <iostream>
#include <string>

char caesar(char c, int k)
{
    if (!isalpha(c)) return c;

    int offset = 'a';
    if (isupper(c)) offset = 'A';

    c = (((c - offset) + k) % 26) + offset;
    return c;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Usage:" << std::endl;
        std::cout << "\tmain plain_text key" << std::endl;
        return EXIT_FAILURE;
    }

    std::string plain_text = argv[1],
                cipher_text = "";
    int key = atoi(argv[2]) % 26;

    for (char c: plain_text) {
        cipher_text += caesar(c, key);
    }

    std::cout << "\nPlain text:\n";
    std::cout << "\t" << plain_text << std::endl;

    std::cout << "\nCipher text:\n";
    std::cout << "\t" << cipher_text << "\n" << std::endl;

    return EXIT_SUCCESS;
}
