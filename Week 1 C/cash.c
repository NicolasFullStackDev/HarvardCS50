#include <cs50.h>
#include <stdio.h>

// Main method
int main()
{
    int cashOwed;       // User input
    int totalCoins = 0; // Coin counter

    // Prompt input to get cashOwed
    do
    {
        cashOwed = get_int("How many blocks will your tower have? ");
    }
    while (cashOwed < 1);

    // Greedy algorithm implementation
    // Quarters
    totalCoins += cashOwed / 25;
    cashOwed = cashOwed % 25; // Update cashOwed

    // Nickel
    totalCoins += cashOwed / 10;
    cashOwed = cashOwed % 10; // Update cashOwed

    // Dime
    totalCoins += cashOwed / 5;
    cashOwed = cashOwed % 5;

    // Pennies
    totalCoins += cashOwed;

    // Output the total number of coins
    printf("%d", totalCoins);

    return 0;
}
