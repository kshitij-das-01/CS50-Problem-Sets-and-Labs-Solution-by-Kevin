#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Input your name and it greets you
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}
