#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype of the function
int calculate_score(string word);

// Points for the alphabets arranged in the order
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Input for player 1 and player 2
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate the points
    int score1 = calculate_score(word1);
    int score2 = calculate_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins! Score: %i", score1);
    }
    else if (score2 > score1)
    {
        printf("Player 2 Wins! Score: %i", score2);
    }
    else if (score1 == score2)
    {
        printf("Tie! Score: %i", score1);
    }

    printf("\n");
}

// Function to calculate the score & using the pre defined score to sum them up
int calculate_score(string word)
{
    int score = 0;

    for (int i = 0, s = strlen(word); i < s; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
