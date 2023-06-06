#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool check_repeated_char(string input);
int standardize(char);
int main(int argc, string argv[])
{
    // no space, only one argument
    if (argc != 2)
    {
        printf("Only one argument\n");
        return 1;
    }
    // check that length of argv[1] is 26
    int n = strlen(argv[1]);
    if (n != 26)
    {
        printf("26 characters!\n");
        return 1;
    }
    // check that all chars are alphabet
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Only alphabet\n");
            return 1;
        }
    }
    // check repeated character
    if (check_repeated_char(argv[1]))
    {
        printf("Duped chars\n");
        return 1;
    }
    char upper_keys[27];
    char letter; // use in loop
    for (int j = 0; j < 26; j++)
    {
        letter = argv[1][j];
        if (islower(letter))
        {
            letter = toupper(letter);
        }
        upper_keys[j] = letter;
    }
    string plain_text = get_string("plaintext: ");
    int n_chars = strlen(plain_text);
    char cipher_text[n_chars]; // to a store a ciphered text (a result)
    int stdized_letter_int; // use in loop
    cipher_text[n_chars] = '\0'; // make it a string
    // standardize to 0-25 then index from key and turn to upper or lower depends from the original char
    // remain it, if it's not an alphabet.
    for (int c = 0 ; c < n_chars; c++)
    {
        letter = plain_text[c];
        stdized_letter_int = standardize(letter);
        if (isupper(letter))
        {
            cipher_text[c] = (char)upper_keys[stdized_letter_int];
        }
        else if (islower(letter))
        {
            cipher_text[c] = (char)(upper_keys[stdized_letter_int] + 32);
        }
        else
        {
            cipher_text[c] = letter;
        }
    }
    printf("ciphertext: %s\n", cipher_text);
}
bool check_repeated_char(string input)
{
    int count[26];
    for (int i = 0; i < 26; i++)
    {
        char letter = input[i];
        count[standardize(letter)]++;
    }
    for (int j = 0; j < 26; j++)
    {
        if (count[j] >= 2)
        {
            return true;
        }
    }
    return false;
}
// standardize
int standardize(char letter)
{
    if (isupper(letter))
    {
        return (int)letter - 65;
    }
    else if (islower(letter))
    {
        return (int)letter - 97;
    }

    return (int)letter;
}