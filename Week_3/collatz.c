#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int num = get_int("Number: ");
    int steps = collatz(num);
    printf("Collatz steps: %i\n", steps);
}

int collatz(int n)
{

    if (n == 1)
        return 0;

    else if ((n % 2) == 0)
    {
        n = n/2;
        return 1 + collatz(n);
    }

    else
    {
        n = 3*n + 1;
        return 1 + collatz(n);
    }
}