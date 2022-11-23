#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int)); // malloc gives chunk of memory for 3 integers, x tells us where this starts
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    // can use valgrind ./xyz to find memory related bugs

    free(x);
}