#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    // for (int x = 0; x < candidate_count; x++)
    // {
    //     for (int y = x + 1; y < candidate_count; y++)
    //     {
    //         printf("%s/%s, %i ", candidates[x], candidates[y], preferences[x][y]);
    //     }
    //     printf("\n");
    // }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences [j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            if (preferences[i][j] < preferences [j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int j = 0; j < pair_count; j++)
    {
        for (int i = pair_count - 1; i > 0; i--)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] > preferences[pairs[i - 1].winner][pairs[i - 1].loser])
                // Pairs tells you WHO won/lost. Preferences tells you VOTES number! That is what we need here.
            {
                pair x = pairs[i];
                pair y = pairs[i - 1];
                pairs[i] = y;
                pairs[i - 1] = x;
            }
        }
    }
    return;
}

// Recursive function to check for cycle
bool cycle(int winner, int loser)
{
    // If the cycle exists, winner equals loser, return true
    if (winner == loser)
    {
        return true;
    }

    // for all candidates, see if any lose to current loser, then repeat until the loser == winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == true) // see if anyone loses to current loser in locked array
        {
            if (cycle(winner, i) == true) // follow path until we get to end. Why do i need this if my base case does this?
            {
                return true;
            }
        }
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (cycle(pairs[i].winner, pairs[i].loser) == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
// Winner is the one with no true values in their column, bc true means arrow coming to them. We want all false.
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int false_count = 0;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false) // checking locked[row][column]
            {
                false_count++;
                if (false_count == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }
    }
    return;
}