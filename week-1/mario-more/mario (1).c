#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_row(int num_spaces, int brick);

int main(void)
{
    // To get user input and set + assign the height of pyramid by the function.
    int height = 0;
    height = get_height();

    // This loop gives different values to the function inside as input to print different number of
    // rows. And the value is assigned by the user through line 11.
    if (height <= 50)
    {
        for (int i = 0; i < height; i++)
        {
            print_row(height - i - 1, i + 1);
        }
    }
    else
    {
        printf("The number is too large, please try again.\n");
    }
}

// To get user input, and return the value.
int get_height(void)
{
    // To keep prompting the user if input is -ve or 0 or non integer number.
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);
    return height;
}

// Prints row in a straight line, with the number of n given.
void print_row(int num_spaces, int num_bricks)
{
    // print spaces before the brick to adjust it.
    for (int i = num_spaces; i > 0; i--)
    {
        printf(" ");
    }

    // Print a row of brick with the number of brick given as input.
    for (int i = 0; i < num_bricks; i++)
    {
        printf("#");
    }

    // space between the do pyramids
    printf("  ");

    // see line 28
    for (int i = 0; i < num_bricks; i++)
    {
        printf("#");
    }

    printf("\n");
}
