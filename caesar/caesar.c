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
        // check for numerical key value
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]) % 26;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    char cipher;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // encrypt uppercase
        if (isupper(plaintext[i]))
        {
            cipher = (plaintext[i] - 65 + key) % 26 + 65;
        }
        // encrypt lowercase
        else if (islower(plaintext[i]))
        {
            cipher = (plaintext[i] - 97 + key) % 26 + 97;
        }
        // not alpha, just print
        else
        {
            cipher = plaintext[i];
        }

        printf("%c", cipher);
    }

    printf("\n");
    return 0;
}