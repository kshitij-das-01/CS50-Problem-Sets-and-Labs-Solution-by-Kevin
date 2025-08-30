#include <cs50.h>
#include <stdio.h>

int coin_num_cal(int cents, int coin_value);
int change_cents(int cents, int coin_num, int coin_value);

int main(void)
{
    // Prompt the user to input the change, in cents and a non-negative number
    int cents = 0;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate the number of quarters
    int quarters = coin_num_cal(cents, 25);

    // Subtract the value of quarters from the change
    cents = change_cents(cents, quarters, 25);

    // Calculate the number of dimes
    int dimes = coin_num_cal(cents, 10);

    // Subtract the value of dimes from the change
    cents = change_cents(cents, dimes, 10);

    // Calculate the number of nickels
    int nickels = coin_num_cal(cents, 5);

    // Subtract the value of nickels from the change
    cents = change_cents(cents, nickels, 5);

    // Calculate the number of pennies
    int pennies = coin_num_cal(cents, 1);

    // Subtract the value of pennies from the change
    cents = change_cents(cents, pennies, 1);

    // Print the final value of minimum numbers of coins for the given change of cents owed
    int change_coins = quarters + dimes + nickels + pennies;
    printf("%i\n", change_coins);
}

// Function to calculate the number of coin (25,10,5,1) from the value of cents,
// to determine the minimum number of coins required.
int coin_num_cal(int cents, int coin_value)
{
    int coin_num = 0;
    while (cents / coin_value >= 1)
    {
        coin_num++;
        cents -= coin_value;
    }
    return coin_num;
}

// Function to subtract the value of the coin to get the remaining value of change/
int change_cents(int cents, int coin_num, int coin_value)
{
    cents = cents - (coin_num * coin_value);
    return cents;
}
