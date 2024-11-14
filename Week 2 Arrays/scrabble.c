#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet (A-Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function pattern of calc_scrabble_score
int calc_scrabble_score(string word);

// Function to calculate the Scrabble score of a word
int calc_scrabble_score(string word)
{
    int score = 0;

    for (int i = 0; word[i] != '\0'; i++) // Iterate through each character of the string
    {
        char c = toupper(word[i]); // Convert to uppercase for easier comparison

        if (c >= 'A' && c <= 'Z') // Ensure the character is a valid alphabet letter
        {
            // Calculate the index for the letter (0 for 'A', 1 for 'B', ..., 25 for 'Z')
            int index = c - 'A';

            // Add the corresponding score from the POINTS array
            score += POINTS[index];
        }
    }

    return score;
}

int main(void)
{
    // Get input words from both players
    string user1_word = get_string("Player 1: \n");
    string user2_word = get_string("Player 2: \n");

    // Compute the score of each word
    int score1 = calc_scrabble_score(user1_word);
    int score2 = calc_scrabble_score(user2_word);

    // Print the scores
    printf("Player 1's score: %d\n", score1);
    printf("Player 2's score: %d\n", score2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}
