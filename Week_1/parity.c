#include <stdio.h>
#include<cs50.h>

int main(void)
{

    int n = get_int("n: ");

    //If n is even, remainder is 0
    if (n % 2 == 0)
    {
        printf("even\n");
    }

    else
    {
        printf("odd\n");
    }

}