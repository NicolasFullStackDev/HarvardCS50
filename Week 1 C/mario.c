#include <cs50.h>
#include <stdio.h>

// Main method
int main()
{
    // Variables
    int height;

    // Prompt input
    do
    {
        height = get_int("How many blocks will your tower have? ");
    }
    while (height < 1);

    // Row Logic
    for (int i = 1; i <= height; i++)
    {
        // Empty spaces *before* blocks
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // First block set
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Empty spaces *between* blocks
        printf("  ");

        // Next block set, it mirrors the first by the same amount
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Linebreak
        printf("\n");
    }

    return 0;
}
