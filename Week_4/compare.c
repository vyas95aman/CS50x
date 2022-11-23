#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    char *i = get_string("i: "); // This is how to compare strings. using string will compare addresses
    char *t = get_string("t: ");

    if (strcmp(i, t) == 0)
    {
        printf("same\n");
    }
    else{
        printf("Different\n");
    }

    printf("%p\n", i); // p means print the address
    printf("%p\n", t);
}