#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b);
void swap_addy(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap_addy(&x, &y); // passing through an address
    printf("x is %i, y is %i\n", x, y);


}

void swap(int a, int b) // only uses copies of x and y, doenst save it in the main code. SO WE NEED TO USE THE ADDRESS!
{
    int tmp = a;
    a = b;
    b = tmp;

    printf("x is %i, y is %i\n", a, b);
}

void swap_addy(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}