#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    if (n <= 0) // without this, will get error that this will be infinite loop. Changed to <= to to not allow negative #s
    {
        return;
    }

    draw(n - 1); // calling itself, draw within a draw

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}