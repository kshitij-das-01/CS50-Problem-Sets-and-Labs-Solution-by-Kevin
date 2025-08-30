// Libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
int argument_validation(int cla_c, string cla_v[]);
char rotate_char(char c, int n);

int main(int argc, string argv[])
{
    // Function to check the command line argument is valid or not
    argument_validation(argc, argv);

    // Text input from the user
    string plaintext = get_string("plaintext:  ");

    // Converting the command line argument string into int
    int key = atoi(argv[1]);

    // Ciphering text through loops and a function to rotate the character by the number of
    // character by a certain number of mentioned by the user.
    printf("ciphertext:  ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char ch = plaintext[i];
        ch = rotate_char(ch, key);
        printf("%c", ch);
    }

    // Just to print a new line to maintain aesthetics
    printf("\n");
    return 0;
}

// Function to check the if CLA is valid, it considers the following conditions:
// only one input should be there after the main program name.
// the input should be a numerical digit only.
int argument_validation(int incnt, string instr[])
{
    if (incnt == 1 || incnt > 2)
    {
        printf("Please provide only 1 input\n");
        exit(1);
    }

    for (int i = 1; i < incnt; i++)
    {
        for (int j = 0, len = strlen(instr[i]); j < len; j++)
        {
            if (isdigit(instr[i][j]) == 0)
            {
                printf("Usage: %s key\n", instr[0]);
                exit(1);
            }
        }
    }
    return 0;
}

// Function rotate the char to a num of times, while retaining the Uppercase or lowercase of the
// letter. Also it take two input one is the char which is give by the user, another is the int key.
char rotate_char(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c -= 'A';
            c = (c + n) % 26;
            c += 'A';
        }
        else if (islower(c))
        {
            c -= 'a';
            c = (c + n) % 26;
            c += 'a';
        }
    }
    return c;
}
