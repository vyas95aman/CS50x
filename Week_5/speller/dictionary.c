// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <stdint.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    // iterate throughout the linked list to find the word
    for (node *tmp = table[index]; tmp != NULL; tmp =  tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    // find num value of first letter
    // int counter = 0;
    int first_letter = (int) tolower(word[0]) - 97;

    return first_letter;

    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // fread text to load into hash table
    // if (dictionary == NULL)
    // {
    //     dictionary = "dictionaries/large.txt";
    // }
    FILE *inptr = fopen(dictionary, "r"); /////////
    if (inptr == NULL)
    {
        printf("Could not load dictionary.\n");
        return false;
    }

    // iterate over each word, read into variable, new node, then insert
    char word[LENGTH + 1]; // initialize the word variable

    while (fscanf(inptr, "%s", word) != EOF) // I used the wrong syntax before, fscanf goes in here!
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Not enough memory to allocate for new node.\n");
            return false;
        }

        strcpy(new_node->word, word);
        new_node->next = NULL; // do i need this if im assigning value later?

        // use hash to find where in the linked list to put in linked list, index for where word can go!
        int index = hash(new_node->word);

        new_node->next = table[index];
        table[index] = new_node;
        dict_size++;
        // do not free the nodes yet, not until we unload them at the end
    }


    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // int counter;
    // counter++;
    return dict_size; // need a global variable for this to see!
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int index = 0; index < N; index++)
    {
        while (table[index] != NULL)
        {
            node *tmp = table[index]->next;
            free(table[index]);
            table[index] = tmp;
        }

    }

    for (int index = 0; index < N; index++)
    {
        if (table[index] != NULL)
        {
            return false;
        }
    }


    return true;
}
