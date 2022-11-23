#include<stdio.h>
#include<cs50.h>

// int main(void)
// {
//     int score1 = 72;
//     int score2 = 73;
//     int score3 = 33;

//     printf("Average: %.f\n", (score1 + score2 + score3)/3.0);
// }

// C says it doesnt see the function as a float, we need to make a float by changing 3 to 3.0

// Not efficient bc were using 3 variables to store 3 of the same data types... just make a list OR... ARRAY!

// int main(void)
// {
//      int scores[3]; // telling that this is an int array, and we are going to store 3 values in there
//      scores[0] = get_int("Score: ");
//      scores[1] = get_int("Score: ");
//      scores[2] = get_int("Score: ");

//      printf("Average: %f\n", (scores[0] + scores[1] + scores[2])/3.0);

// }

// BAD FORM ^^

int main(void)
{
    int n = get_int("How many scores? ");
     int scores[n];
     for (int i = 0; i < n; i++)
     {
        scores[i] = get_int("Score: ");
     }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }
    float average = sum / n;
     printf("Average: %f\n", average);
}