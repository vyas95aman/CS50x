#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");// want to quit program prematurely. 
        return 1; // return a non-zero value to call main. Tells the computer something went wrong, bc it is not 0. Used as error codes! Seeing exit statuses 
    }
    else // don't need else line, bc we wont get here if didnt get past if statement
    {
        printf("hello, %s\n", argv[1]);
        return 0; // Signals to computer all is well. the cmputer auto returns this 
    }
}