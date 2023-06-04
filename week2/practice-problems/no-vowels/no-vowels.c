// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
string replace(string input);

int main(int argc, string argv[])
{
    // check argument count: if less than 2 return 1 (error)
    if (argc < 2)
    {
        return 1;
    }
    // take an argument in input
    string input = argv[1];
    // use the function, assign to result
    string result = replace(input);

    // print the result
    printf("%s\n", result);

    free(result);
    // exist status success
    return 0;


}

string replace(string input)
{
    //get a length of the input
    int n = 0;
    while (input[n] != '\0')
    {
        n++;
    }

    string result = malloc((n+1));
    //iterate each char in the input
    for (int i = 0; i < n; i++)
    {
        char letter = input[i];
        switch (letter)
            {
                case 'a':
                result[i] = '6';
                break;

                case 'e':
                result[i] = '3';
                break;

                case 'i':
                result[i] = '1';
                break;

                case 'o':
                result[i] = '0';
                break;

                default:
                result[i] = letter;
                break;
            }
    }
    result[n] = '\0';
    return result;
}