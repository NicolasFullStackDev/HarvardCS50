#include <cs50.h>
#include <stdio.h>

// Main method
int main(void)
{
    // Variables
    string name = get_string("What's your name? ");

	printf("hello, %s\n", name);
}
