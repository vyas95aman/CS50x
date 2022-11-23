#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[] = {5, 128, 43, 66, 2, 0, 50};

    for (int j = 0; j < 7; j++)
    {
        for (int i = 7 - 1; i > 0; i--)
        {
            if (array[i] > array[i-1])
            {
                int x = array[i];
                int y = array[i-1];
                array[i] = y;
                array[i-1] = x;
            }
         }
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}