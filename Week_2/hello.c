#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}

// Using clang hello.c creates an a.out file
// Running ./a.out executes my function. clang is the compiler for C
// clang -o hello hello.c // This tells what to call the output file

// Adding get_string gives error, like it doesnt exist... encountered this error before - need linker command
// need this: clang -o hello hello.c -lcs50
// clang is the compiler, but continue to use make which uses it to give a file name. Does what the above code does

