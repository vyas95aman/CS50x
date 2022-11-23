#include <stdio.h>

int main(void)
{
    int n = 50; // This value has a certain address in memory. A pointer is a variable storing the address
    // printf("%i\n", n); // 4 bytes in an int

    int *p = &n; // & to find address, andh have to tell C that it is a varibale for an address. P is a pointer here, not a regular int
    printf("%p\n", p); // pointers always take up a bit of space, 8 bytes, bc we have more memory nowadays
    printf("%i\n", *p); // Can call the int in the pointer, using * as a deference operator, aka go to that address

    printf("\n");

    // string s = "HI!"; // string has been an alias for this! The variable s is stored in memory, different location, than string HI!
    char *s = "HI!"; // tells where to start the string. nul is where string ends. Address of the first character
    printf("%s\n", s);

    char *x = &s[0];

    printf("%p\n", x);// prints the location of first character
    printf("%p\n", s);// prints the starting of the string s, both are same


    printf("\n");

    int numbers[] = {4, 8, 6, 2, 5, 7, 0};

    printf("%i\n", *numbers);
    printf("%i\n", *(numbers + 1)); // compiler knows to move over 4 bytes over for +1, bc it knows what type of data im using
    printf("%i\n", *(numbers + 2));




}