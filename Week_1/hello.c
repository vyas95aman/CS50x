// This is called source code. When it is translated into binary it is called machine code. A COMPILER is a translator! 
// A compiler's purpose is to convert code from one language to another. 

// #include <stdio.h>

// int main(void)
// {
// printf("hello, world\n");
// }

// print f is formatted, ; is basically the same as period at the end of the function

// ./helloworld in terminal runs the program

// type rm to remove files, ls to list files - same in linux

// I need to make the compiled version before running. This makes the machine code actually run on the computer. Use make in terminal. make knows how to find and use a compiler, it is not a compiler

// can't run helloworld.c, bc it is not executable - it is the read write file, then we compile to machine code


// ask in scratch is same as input in Python, and get_string() in C

// have to tell C what kind of variable it is, string in this case. int for integer. If i put wrong data into variable, compiler will give error

// string answer = get_string("What is your name? ");

#include <cs50.h> //have to include this bc im working with strings, CS50 have built their own library. get_string is cs50 written fuction, so need to load library/extension first. need access to their functions. 
#include <stdio.h> // stdio = standard input and output - then we can use printf

int main(void)
{
    string answer = get_string("What is your name? ");
    printf("hello, %s\n", answer); // %s means placeholder, put string variable here
}

// using
// clang hello.c -o hello -lcs50
// to compile


// This is at the begining of all C code. all code goes inside this. 
// int main(void)
// {

// }


// int counter = 0; // Setting counter to 0
// counter = counter + 1; OR  counter += 1; OR counter++; // No longer need to remind what data type it is, only when creating



