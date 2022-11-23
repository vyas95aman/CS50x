#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
    printf("hello, %s\n", argv[1]); // argv[0] is the name of the string! argv[1] is where your arguments start
    }
    else
    {
        printf("hello, world\n");
    }
}