#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    // string s = get_string("s: ");

    // string t = s;

    // t[0] = toupper(t[0]);

    // printf("s: %s\n", s);
    // printf("t: %s\n", t); //this assigns the same address to the variables, pointing to the same address


    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1); // malloc allocates memory for this variable, free used in conjunction to free said memory after. +1 bc we need null
    if (t == NULL)
        return 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        t[i] = s[i];
    } // or use strcpy(t, s)

    if (strlen(t) > 0) // make sure there is a character there
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    return 0;
}