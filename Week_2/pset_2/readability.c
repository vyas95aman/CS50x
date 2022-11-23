#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);
float cl_index(float letters, float words, float sentences);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    int index = cl_index(letters, words, sentences);
    // printf("Letters: %.f\n", letters);
    // printf("Words: %.f\n", words);
    // printf("Sentences: %.f\n", sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}

// Functions count the number of letters, words, sentences
float count_letters(string text)
{
    float letters = 0;
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters ++;
        }
    }
    return letters;
}

// // Any occurance of letters separated by a space - count spaces
float count_words(string text)
{
    float words = 1; // starting with 1 bc last word in text does not have space after, need to accomodate
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if ((int) text[i] == 32)
        {
            words ++;
        }
    }
    return words;
}

// // Any occurance of .!?
float count_sentences(string text)
{
    float sentences = 0; // starting with 1 bc last word in text does not have space after, need to accomodate
    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences ++;
        }
    }
    return sentences;
}

float cl_index(float letters, float words, float sentences)
{
// index = 0.0588*L - 0.296*S - 15.8
    float L = letters / words * 100;
    float S = sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    return round(index);
}