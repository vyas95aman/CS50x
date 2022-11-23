#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (vote(name) == false)
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            // printf("name: %s, votes: %i\n", candidates[i].name, candidates[i].votes);
            return 1;
        }
    }

    printf("Not found\n");
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // sort, then select highest value in votes, then print those winners

    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count - 1; i++)
        {
            if (candidates[i].votes > candidates[i + 1].votes)
            {
                candidate x = candidates[i];
                candidate y = candidates[i + 1];
                candidates[i] = y;
                candidates[i + 1] = x;
            }
        }
    }

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     printf("SORTED candidate: %s, votes: %i\n", candidates[i].name, candidates[i].votes);
    // }


    int winners = candidates[candidate_count - 1].votes;
    // printf("highest votes: %i\n", winners);

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winners)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}