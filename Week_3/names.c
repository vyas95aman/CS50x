#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "Harry", "Ron", "George", "Ginny", "Percy"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Frank") == 0) // strcmp compares two strings. Also compares order. negative - s1 comes first, 0 - same, positive - s2 first
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}