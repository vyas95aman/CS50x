#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int numbers[7];
    // numbers [0] = 4; This is inefficient
    // numbers [1] = 3; 
    int numbers[] = {4, 6, 8, 2, 7, 5,0};

    for (int i = 0; i <= 7; i++)
    {
        if (numbers[i] == 10)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not found!\n"); // This goes outisde of the for loop!
    return 1;
}