// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;
    bool has_symbol = false;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        char letter = password[i];

        if (!has_upper)
        {
            if (isupper(letter))
            {
                has_upper = true;
            }
        }

        if (!has_lower)
        {
            if (islower(letter))
            {
                has_lower = true;
            }
        }

        if (!has_number)
        {
            if (isdigit(letter))
            {
                has_number = true;
            }
        }

        if (!has_symbol)
        {
            if (ispunct(letter))
            {
                has_symbol = true;
            }
        }
    }

    return (has_upper && has_lower && has_number && has_symbol);
}
