#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

// Prototypes
int string_length(string text);
int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

// global constants
const int GRADE_1 = 1;
const int GRADE_16 = 16;
const float term1 = 0.0588;
const float term2 = 0.296;
const float term3 = 15.8;

// global variables
int length = 0;

int main(void)
{
    // Take the text input from user
    string main_text = get_string("Text: ");
    printf("\n");

    // calculate the length of the string
    length = string_length(main_text);

    // calculate the number of letters
    float letter = letter_count(main_text);

    // calculate the number of words
    float word = word_count(main_text);

    // calculate the number of sentences
    float sentence = sentence_count(main_text);

    // where L is the average number of letters per 100 words in the text,
    // and S is the average number of sentences per 100 words in the text.
    float L = (letter / word) * 100;
    float S = (sentence / word) * 100;

    float index = 0;
    int grade = 0;
    index = term1 * L - term2 * S - term3;
    grade = round(index);

    // conditions for calculating the grades & provide output
    if (grade < GRADE_1)
    {
        printf("Before Grade 1");
    }
    else if (grade > GRADE_16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %d", grade);
    }

    // Just a new line to maitain aesthetics
    printf("\n");
}

// to scan every character of the string and calculate the number of it
int string_length(string text)
{
    int string_len = 0;

    while (text[string_len] != '\0')
    {
        string_len++;
    }

    return string_len;
}

// This function calculates the number of letters in a string
int letter_count(string text)
{
    int letter_num = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letter_num++;
        }
    }

    return letter_num;
}

// This function calculates the number of words in a string
int word_count(string text)
{
    int word_num = 0;

    for (int i = 0; i < length; i++)
    {
        char prechar = text[i - 1];
        if (isblank(text[i]) && isblank(prechar) == false)
        {

            word_num++;
        }
    }

    word_num += 1;
    return word_num;
}

// This function calculates the number of sentences in a string
int sentence_count(string text)
{
    int sentence_num = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_num++;
        }
    }

    return sentence_num;
}
