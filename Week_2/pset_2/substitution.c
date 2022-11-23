#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string text_exchange(string s, string key);
int key_verification(string s);


// Key: VCHPRZGJNTLSKFBDQWAXEUYMOI
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument.\n");
        return 1;
    }

    string key = argv[1];
    int only_letters = key_verification(key);
    if (only_letters == 0)
    {
        // printf("key veri passed, %i\n", only_letters);
        string plaintext = get_string("plaintext: ");
        string ciphertext = text_exchange(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);

    }

    else
    {
        printf("Invalid key\n");
        return 1;
    }
}

int key_verification(string s)
{
    int n = strlen(s);
    int result = 0;

    // Check if key has 26 letters
    if (n == 26)
    {
        // printf("key has 26 letters\n");
        for (int i = 0; i < n; i++)
        {
            // Check if letters only
            // if (((int) s[i] >= 65 && (int) s[i] <= 90) || ((int) s[i] >= 97 && (int) s[i] <= 122))
            if (isalpha(s[i]) != 0)
            {
                // Check every letter occurs only once
                for (int j = 0 ; j < n; j++)
                {
                    if (j != i)
                    {
                        if (s[i] == s[j])
                        {
                            printf("Letters used more than once.\n");
                            result++;
                        }

                        else
                        {
                            // printf("all good\n");
                        }
                    }

                    else
                    {
                        continue;
                    }


                }
            }

            else
            {
                printf("only use letters\n");
                result++;
            }
        }
    }

    else
    {
        printf("Key does not have 26 characters\n");
        result++;
    }

    return result;

}

string text_exchange(string s, string key)
{
    string ciphertext = s;
    int letter_num = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (islower(s[i]) != 0)
        {
            letter_num = s[i] - 97;
            ciphertext[i] = tolower(key[letter_num]);
            // printf("letter num: %i\n", letter_num);
            // printf("Ciphertext: %s\n", ciphertext);
        }

        else if (isupper(s[i]) != 0)
        {
            letter_num = s[i] - 65;
            ciphertext[i] = toupper(key[letter_num]);
            // printf("letter num: %i\n", letter_num);
            // printf("Ciphertext: %s\n", ciphertext);
        }

        // ciphertext += argv[1][letter_num];
    }
    return ciphertext;
}