#include <stdio.h>
#include <cs50.h>
#include <string.h>

int string_length(string s);


int main(void)
{
//     string name = get_string("Name: ");

// // Counting characters/integers in a value. '\0' means NUL aka the end of the string! Counts the length of a string.
//     int i = 0;
//     while (name[i] != '\0')
//     {
//         i++;
//     }
//    printf("%i\n", i);

    // string name = get_string("Name: ");
    // int length = string_length(name);
    // printf("%i\n", length);

    string name = get_string("Name: ");
    int length = strlen(name); // This function gets the length of the string. The function does exactly what we did manually. See ### manual.cs50.io #### for info on cs50 available functions
    printf("%i\n", length);



 
}


int string_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}