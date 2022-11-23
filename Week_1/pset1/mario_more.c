#include <stdio.h>
#include <cs50.h>

void hashtag(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

int main(void)
{

    // Defines value for Height of pyramid
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Making each pyramid
    for (int j = 1; j <= n; j++)
    {
        // Print spaces
        int space_num = n - j;
        space(space_num);

        // Print left side hashtags
        hashtag(j);

        // Print two spaces
        printf("  ");

        // Print right side hashtags
        hashtag(j);

        printf("\n");
    }
}