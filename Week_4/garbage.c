#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", scores[i]);
    }

    // gives garbage values, remnanats of past ints/floats/values
    // this is why it is important to initialize !!

    printf("\n");

    int *x; // this gives x an address in memory
    x = malloc(sizeof(int)); // This then creates an allocated space where the int begins
    *x = 42; //This is assigning a value to that address, x is the address, *x is dereferencing and saying what the value there is
    int *y;
    y = x; // setting y to the same address as x, so they read the same value
    *y = 13; // Here we change the value to 13
    printf("%i\n", *x);
    printf("%i\n", *y);

    free(x);
}