#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("Output: ");
    int length = strlen(s);
    for (int i = 0, n = strlen(s); i< n; i++) // using n in the for loop to define strlen(s) is optimal 
    {
        printf("%c", s[i]);
    }
    printf("\n");

// Not well designed ^^ not optimal bc strlen can be its own variable
}

