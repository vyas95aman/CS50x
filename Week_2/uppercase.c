#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// manual.cs50.io

int main(void)
{
    // string s = get_string("Before: ");
    // printf("After: ");
    // for (int i = 0, n = strlen(s); i < n; i++)
    // {
    //     // ASCII Chart - we see captial letters are 32 digits apart
    //     if (s[i] >= 'a' && s[i] <= 'z') //a is 97, z is 132, asking if current letter is lowercase
    //     {
    //         printf("%c", s[i] - 32);
    //     }
    //     else
    //     {
    //         printf("%c", s[i]);
    //     }
    // }
    // printf("\n");




// There is a function for doing this
    // string s = get_string("Before: ");
    // printf("After: ");
    // for (int i = 0, n = strlen(s); i < n; i++)
    // {
    //     if (islower(s[i]) != 0) // Tells us T or F, 1 or 0. If false, it is a lowercase
    //     {
    //         printf("%c", s[i] - 32);
    //     }
    //     else
    //     {
    //         printf("%c", s[i]);
    //     }
    // }
    // printf("\n");

// There is a function to to upper
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");


}