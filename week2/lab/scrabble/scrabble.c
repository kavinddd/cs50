#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int to_byte(char letter);
int judge(int p1, int p2);
int main(void)
{

    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i vs %i", score1, score2);
    // TODO: Print the winner
    judge(score1, score2);
    return 0;
}

int compute_score(string word)
{
    int n =  strlen(word);
    // TODO: Compute and return score for string

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int index = to_byte(word[i]);
        if (index != -1)
        {
            sum += POINTS[index];
        }

    }
    return sum;
}
// functions take words and return bytes of each char a = 0 z = 25
int to_byte(char letter)
{
    int byte;
    if (islower(letter))
    {
        //a start from 97
        return letter - 97;
    }
    else if (isupper(letter))
    {
        return letter - 65; // A start from 65
    }
    else
    {
        return -1;
    }
}

// judge
int judge(int p1, int p2)
{
    if (p1 == p2)
    {
        printf("Tie!\n");
    }
    if (p1 > p2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
    return 0;
}