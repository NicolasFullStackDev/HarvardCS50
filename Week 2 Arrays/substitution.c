#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Custom function signatures
int check_for_repeated_letters(string cipher_key, int i);
void print_cipher_text(string cipher_key, string plain_text);

int main(int argc, string argv[])
{
    // If number of terminal commands is equal to 2
    // It means a key as passed
    if (argc == 2) //
    {
        // The cipher key is the command array with position 1
        // Which refers to the second command
        // argv[0] is always ./PROGRAM_NAME
        string cipher_key = argv[1];
        if (strlen(cipher_key) == 26)
        {
            // Loops through each item in the cipher_key array
            for (int i = 0; i < strlen(cipher_key); i++)
            {

                // If there are any non-letter values, exit the program with code 1
                if (!isalpha(cipher_key[i]))
                {
                    printf("Key must contain only letters.\n");
                    return 1;
                }

                // If there are repeated letters, exit the program with code 1
                if (check_for_repeated_letters(cipher_key, i))
                {
                    printf("Key must not contain repeated letters.\n");
                    return 1;
                }
            }

            // Get the plain text
            // Get the cipher_text

            string plain_text = get_string("plaintext: ");
            printf("ciphertext: ");
            print_cipher_text(cipher_key, plain_text);
            printf("\n");
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}

// Returns true if there are repeated letters in any given key
int check_for_repeated_letters(string key, int i)
{
    for (int j = i + 1; j < strlen(key); j++)
    {

        // Checks for repeated letter element in the key
        if (toupper(key[j]) == toupper(key[i]))
        {
            return 1;
        }
    }
    return 0;
}

// Prints the cipher text
void print_cipher_text(string cipher_key, string plain_text)
{
    // For reference, there ASCII values of alphabet uppercase letters starts at 65
    // and for lower case letters start at 97
    for (int i = 0; i < strlen(plain_text); i++)
    {
        char c = plain_text[i];

        // Handles uppercase letters
        if (isupper(c))
        {
            int letter = (int) c - 65;
            char cipher_text = cipher_key[letter];
            // Ensures the final result is uppercase
            // regardless of they chiper_key capitalization
            printf("%c", toupper(cipher_text));
        }
        // Handles lowercase letters
        else if (islower(c))
        {
            int letter = (int) c - 97;
            char cipher_text = (cipher_key[letter]);
            // Ensures the final result is lowercase
            // regardless of they chiper_key capitalization
            printf("%c", tolower(cipher_text));
        }
        // Handles non-letters
        else
        {
            char cipher_text = plain_text[i];
            printf("%c", cipher_text);
        }
    }
}
