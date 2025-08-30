#include <cs50.h>
#include <stdio.h>

int get_height(int height);
void print_row(int spaces, int bricks);

int main(void)
{
    // initial integer for height of pyramid, it gets adjusted as user input
    int height = 0;
    height = get_height(height);

    // This loop runs the print row function while changing the value of input.
    // And in that function, the loops use the given input to make it run that number of times.
    for (int i = 0; i < height; i++)
    {
        print_row(height - i - 1, i + 1);
    }
}

// Function to get user input for height of pyramid
int get_height(int n)
{
    // To prompt the user repeatedly if user give -ve or 0 as input
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    return n;
}

// Function to actually print the pyramid
void print_row(int spaces, int bricks)
{
    // Print spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // Print bricks
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
    printf("\n");
}
