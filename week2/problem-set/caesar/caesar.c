#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
char caesar(char letter, int key);
int main(int argc, string argv[])
{
    // check if
    if (argc <= 1 || argc > 2)
    {
        printf("You need to pass exactly one argument\n");
        return 1;
    }


    // check if it is a number
    int i = 0;
    char letter = argv[1][i];
    while (letter != '\0')
    {
        i++;

        if (!(letter >= '0' && letter <= '9'))
        {
            printf("You need to pass only numbers\n");
            return 1;
        }
        letter = argv[1][i];
    }

    // key for algorithm
    int key = atoi(argv[1]);

    // get the plain text
    string plain_text = get_string("plaintext: ");

    // get length of string
    int n = 0;
    while (plain_text[n] != '\0')
    {
        n++;
    }

    // interate each char applying caesar algorithm with key
    char result[n];
    result[n] = '\0';
    for (int j = 0; j < n; j++)
    {
        result[j] = caesar(plain_text[j], key);
    }
    printf("ciphertext: %s\n", result);
    return 0;
}

char caesar(char letter, int key)
{
    // standardize letter to 0 - 26 not, save a result in letter_int
    int temp_subtract;
    if (letter >= 'A' && letter <= 'Z')
    {
        temp_subtract = 65;
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        temp_subtract = 97;
    }
    else // incase a special character, puctuations
    {
        return letter;
    }
    int standardized_letter_int = letter - temp_subtract;
    return (char)(((standardized_letter_int + key) % 26) + temp_subtract);
}

