#include <stdio.h>

// int main(void)
// {
//     printf("meow\n");
//     printf("meow\n");
//     printf("meow\n");
// }
// This is repetitive

// int main(void)
// {
//     int i = 0; // or start at i = 1
//     while (i < 3) // then have to do i <= 3
//     {
//         printf("meow\n");
//         i++;
//     }


// Creating a function called meow
// void meow(void) // (void) means it doesnt take inputs, void means it doesnt return anything like get_string
// {
//     printf("meow\n");
// }

// int main(void) // main means main part of your program 
// {
//     for (int i = 0; i < 3; i++) // Another method using a for loop with a condition
//         meow();
// }



void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}

int main(void)
{
    meow(3);
}