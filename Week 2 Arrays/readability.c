#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Custom function signatures
string count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calc_cl_index(int letters, int words, int sentences);
void print_reading_grade(float index);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float index = calc_cl_index(letters, words, sentences);

    // Print the reading grade results
    print_reading_grade(index);

    return 0;
}

// Count how many letters are in the text
int count_letters(string text)
{
    int number_of_sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isalnum(c))
        {
            number_of_sentences += 1;
        }
    }
    return number_of_sentences;
}

// Count how many words are in the text
int count_words(string text)
{
    int number_of_words = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (isspace(c))
        {
            number_of_words += 1;
        }
    }
    return number_of_words;
}

// Count how many sentences are in the text
int count_sentences(string text)
{
    int number_of_sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        char c = text[i];

        if (c == '.' || c == '?' || c == '!')
        {
            number_of_sentences += 1;
        }
    }
    return number_of_sentences;
}

// Calculate teh Coleman-Liau index
float calc_cl_index(int letters, int words, int sentences)
{
    // Coleman Liau index formula
    float index = 0.0588 * (100 * letters / words) - 0.296 * (100 * sentences / words) - 15.8;

    return index; // This is the reading grade level.
}

void print_reading_grade(float index)
{
    int reading_grade = round(index);

    if (reading_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (reading_grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", reading_grade);
    }
}
