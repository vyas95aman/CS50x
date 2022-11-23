#include <cs50.h>
#include <stdio.h>
#include <string.h>

// int main(void)
// {
//     string names[] = {"Carter", "David"};
//     string numbers[] = {"215-123-5432", "523-135-1232"};

//     for (int i = 0; i < 2; i++)
//     {
//         if (strcmp(names[i], "David") == 0)
//         {
//             printf("Found %s\n", numbers[i]);
//             return 0;
//         }
//     }

//     printf("Not found\n");
//     return 1;
// }

typedef struct // Creating your own data type here, called person with name and number as data stored. Relates data
{
    string name;
    string number;
}
person;


int main(void)
{
    person people[2];
    people[0].name = "Carter";
    people[1].name = "David";
    people[0].number = "215-123-5432";
    people[1].number = "523-135-1232";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
    return 1;
}
