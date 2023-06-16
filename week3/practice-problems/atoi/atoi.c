#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input, int n);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input, strlen(input)));
    return 0;
}

int convert(string input, int n)
{
    // TODO
    int result = 0;
    int tenth_base = pow(10, (strlen(input) - n)); // will be multiply with int_letter to get an integer and will be added in result later.
    n--; // wil be used to index int_letter and exponent base10
    int int_letter = (int)(input[n] - '0'); // change char (0-9) to be integer (0-9) by subracting with '0' (binary value = 48)

    //base case
    if (n == 0)
    {
        result += int_letter * tenth_base;
        return result;
    }

    // recursive
    result += convert(input, n) + (int_letter * tenth_base);
    return result;
}