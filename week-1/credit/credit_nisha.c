#include <stdio.h>

// Prototypes
int number_length(long cc);
int luhn_checksum(long x, int len);

int main(void)
{
    // Input for the credit card number, also prompting user for non negative input
    long num = 0;
    do
    {
        printf("Number: ");
        scanf("%ld", &num);
    }
    while (num < 0);

    // get the number of digits in the number
    int length = number_length(num);

    // validity of credit card number as per length of digits
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculate the checksum of luhn algorithm and store it in result
    int result = luhn_checksum(num, length);

    // Checking if the modulo is equal to 0
    if (result % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Variables to check the digits of from the start
    long start = num;
    int s1 = 0;
    int s2 = 0;

    // reducing the number to the first two digits of the given number
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // s1 is the first digit from the 1st and s2 is the second
    s2 = start % 10;
    s1 = start / 10;

    // AMEX Validy of CC
    if (length == 15 && (s1 == 3 && (s2 == 4 || s2 == 7)))
    {
        printf("AMEX\n");
        return 0;
    }

    // MasterCard Validy of CC
    if (length == 16 && (s1 == 5 && (s2 == 1 || s2 == 2 || s2 == 3 || s2 == 4 || s2 == 5)))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    // VISA Validy of CC
    if ((length == 13 || length == 16) && s1 == 4)
    {
        printf("VISA\n");
        return 0;
    }

    else
    {
        printf("INVALID");
    }

    // Just some fancy code to put a new line, to maintain aesthetics and looks of terminal
    printf("\n");
    return 0;
}

// To get the number of digits in the number
int number_length(long cc)
{
    int len = 0;

    while (cc > 0)
    {
        cc = cc / 10;
        len++;
    }
    return len;
}

// To calculate the checksum of luhn algorithm
int luhn_checksum(long x, int len)
{
    // variables for the formula calculation
    int last1 = 0;
    int last2 = 0;
    int digi1 = 0;
    int digi2 = 0;
    int sum1 = 0;
    int sum2 = 0;

    // Luhn algorithm for check sum of the credit card numbers
    for (int i = 0; i < len; i++)
    {
        // sum of digit from last digit and further alternating
        last1 = x % 10;
        x = x / 10;
        sum1 = sum1 + last1;

        // sum of digit from 2nd last digit and further alternating
        last2 = x % 10;
        x = x / 10;

        last2 = last2 * 2;
        digi1 = last2 % 10;
        digi2 = last2 / 10;

        sum2 = sum2 + digi1 + digi2;
    }

    // total of the sum of the above calculation
    int total = 0;
    total = sum1 + sum2;

    return total;
}
