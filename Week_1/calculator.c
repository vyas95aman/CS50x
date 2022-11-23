#include <stdio.h>
#include <cs50.h>

// int main(void)
// {
//     //Prompt user for x
//     int x = get_int("x: ");

//     //Prompt user for y
//     int y = get_int("y: ");

//     // printf(x+y) This is not valid in C

//     //Perform addition
//     printf("%i\n", x + y);
// }

// int main(void)
// {
//     //Prompt user for x
//     long x = get_long("x: ");

//     //Prompt user for y
//     long y = get_long("y: ");

//     // printf(x+y) This is not valid in C

//     //Perform addition
//     printf("%li\n", x + y);
// }


int main(void)
{
    //Prompt user for x
    int x = get_int("x: ");

    //Prompt user for y
    int y = get_int("y: ");

     // dividing an integer by integer, gives an integer not a float. C throws those values away. 4/3 = 1.000...
    float z = (float) x / (float) y; // Here I can cast a float to the integer. 

    //Perform division
    printf("%.50f\n", z); // include .2 before f, to indication # of decimal points. Integer overflow, incorrect values bc out of bits. 
}