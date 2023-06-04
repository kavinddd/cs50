#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

// functions
int extract_n_letter_sentence(string text);
int cal_readability(int l, int s, int n_word);
int round_to_near_int(float number);

// just initialize these to be global variables for simplicity.
int n_letter = 0;
int n_sentence = 0;
int n_word = 1; // we will count from whitespace, which the last word won't have.

int main(void)
{
    string text = get_string("Text: ");
    extract_n_letter_sentence(text);
    int index = cal_readability(n_letter, n_sentence, n_word);

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

    return 0;
}

int extract_n_letter_sentence(string text)
{
    // get n_char of string
    int n_char = 0;
    while (text[n_char] != '\0')
    {
        n_char++;
    }
    // count: n_letter, n_sentence
    // one puctuation = one sentence
    // one spacebar = one word
    // one character that is not above = one letter
    // so we can do both by one function

    for (int i = 0; i < n_char; i++)
    {
        char letter = text[i];

        if (isupper(letter) || islower(letter))
        {
            n_letter++;
        }
        else if (isspace(letter))
        {
            n_word++;
        }
        else if (ispunct(letter) && letter != '\'' && letter != ',' && letter != '-' && letter != ':' && letter != '"' && letter != ';')
        {
            if (i > 0 && letter == '.')
            {
                if (text[i - 2] == 'M' || text[i - 1] == '.') // skip if Mr. or Ms.  OR char before . is also .
                {
                    n_letter++;
                }
                else
                {
                    n_sentence++;
                }
            }
            else
            {
                n_sentence++;
            }
        }
    }
    return 0;
}

// Coleman-Liau index formula (l and s / 100 words)
int cal_readability(int l, int s, int n_words)
{
    // make them an average per 100 words
    float l_avg =  l * 100.0 / n_words;
    float s_avg =  s * 100.0 / n_words;
    return round_to_near_int((0.0588 * l_avg) - (0.296 * s_avg) - 15.8);
}

// only works with positive
int round_to_near_int(float number)
{
    return (int)(number + 0.5);
}
