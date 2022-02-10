#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// caesar.c accepts a numeric key as a command line argument, prompts
// the user for plaintext, encrypts the message using Caesar's cipher,
// and returns the ciphertext.

int main(int argc, string argv[])
{
    int key;

    // check for valid input and convert key to integer
    if (argc == 2)
    {
        printf("Success - one arg!\n");
        printf("%s\n", argv[1]);
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            printf("%i: %c\n", i, argv[1][i]);
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar numerical key\n");
                return 1;
            }
        }
        key = atoi(argv[1]) % 26;
        printf("key: %i\n", key);

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    char cipher;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // uppercase
        if (isupper(plaintext[i]))
        {
            cipher = (plaintext[i] - 65 + key) % 26 + 65;
        }
        // lowercase
        else if (islower(plaintext[i]))
        {
            cipher = (plaintext[i] - 97 + key) % 26 + 97;
        }
        // not alpha, just print
        else
        {
            cipher = plaintext[i];
        }

        printf("%i: %c %i %c %i\n", i, plaintext[i], plaintext[i], cipher, cipher);
    }

    return 0;
}