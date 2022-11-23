#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // WEEK 1 METHOD
    // int list[3];

    // list[0] = 1;
    // list[1] = 2;
    // list[2] = 3;

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%i\n", list[i]);
    // }

    // NEW SYNTAX, dynamically allocating array
    // int list[3]; // this is identical but the below puts it on the "heap", you have permanently given yourself arrray size of 3, cant change with this method. can change with below.
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
        return 1;
    
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // // OR, but it's a bit much to do
    // // *list = 1;
    // // *(list + 1) = 2;
    // // *(list + 2) = 3;


    // // But now we want to increase size of array... 
    // // list = malloc(4 * sizeof(int)); // this will change the address of list to a new 4 array

    // // allocating a new array
    // int *tmp = malloc(4 * sizeof(int));
    // if (tmp == NULL)
    // {    
    //     free(list);
    //     return 1;
    // }
    
    // for (int i = 0; i < 3; i++)
    // {
    //     tmp[i] = list[i]; // copy values from old to new
    // }
    // tmp[3] = 4; // add new value

    // free(list); // NEED TO FREE OLD VALUES BEFORE REASSIGNING list TO NEW MEMORY
    // list = tmp; // then assign the new chunk of memory to origianl variable

    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%i\n", list[i]);
    // }

    // free(list); // Also need to free new list at the end!


    // NOW USE REALLOC
    // allocating a new array
    list = realloc(list, 4 * sizeof(int)); // free's old memory for you! reallocates space of you. Don't need to assign og values8
    if (list == NULL)
    {    
        free(list);
        return 1;
    }

    list[3] = 4; // add new value

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list); 

}