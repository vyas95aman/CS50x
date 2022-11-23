#include <stdio.h>
#include<cs50.h>

int main(void)
{
//     char c1 = 'H';
//     char c2 = 'I';
//     char c3 = '!';

//     printf("%C%C%C\n", c1, c2, c3);
// }

// int main(void)
// {
//     char c1 = 'H';
//     char c2 = 'I';
//     char c3 = '!';

//     printf("%i %i %i\n", (int) c1, (int) c2, (int) c3); // Using i here made C print the integers for the characters. They can be converted to one data type or another. Chars are just numbers for the computer! Here we are explicitly converting by changing char to int. Or leave as char and it is implicitly converted. 

// // Week 1 method
//     string s = "HI!";
//     printf("%i %i %i\n", s[0], s[1], s[2]); // Now we convert to integer here
// string is an array of characters, and characters are defined by integers

// \0 aka NUL aka tells where to start/stop a string


    string s = "HI!";
    string t = "BYE!";
    printf("%s\n", s);
    printf("%s\n", t);

// Secretly HI! is taking 4 bits not 3, bc HI!\0 tells where to stop, it is 8 bits or 1 byte of 0s









}