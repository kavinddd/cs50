#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n_digit(long number);
bool validate(long card_id);
void which_card(long card_id);
int main(void)
{
    long credit_number;
    do
    {
        credit_number = get_long("Number: ");
    }
    while (credit_number < 0);

    if (validate(credit_number))
    {
        which_card(credit_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

int n_digit(long number)
{
    return floor(log10(labs(number))) + 1;
}

bool validate(long card_id)
{
    // luhn's algo
    //for each digit (10^1 - 10^16) ps. there are 16 digits in visa card number
    int sum = 0; // to contain sum of the formula
    for (int i = 1; i <= n_digit(card_id); i++)
    {
        // divider, for getting the digit number
        long divider = 1;
        for (int j = 1; j < i; j++)
        {
            divider = divider * 10 ;
        }
        // modulus to get the remainder or that specific digit
        // ex. 10010, we want to get 10^1 digit = 10010/10 -> 1001 % 10 -> 1
        int digit = (card_id / divider) % 10;

        // every other digit will be multiplied by 2
        if (i % 2 == 0)
        {
            digit = digit * 2;
            // replace the digit wil sum of digits if its multiplication is more than 10
            if (digit >= 10)
            {
                // A multiplication of two single digits will always be less than 100.
                digit = (digit / 10 % 10) + (digit % 10); // get remainders of 10^1 + 10^2 and then sum
            }
        }

        sum += digit;
    }
    // if the last digit of sum is 0
    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}



void which_card(long card_id)
{
    // we only need 10^15 and 10^14 to check which type of the card (incase of 16-digits)
    int n_digits = n_digit(card_id);
    // get the first two digits first: find a divider (10^(n-2)) because we want to keep 2 left digits then do a floor division
    long divider = 1;
    for (int i = 0; i < (n_digits - 2); i++)
    {
        divider = divider * 10;
    }
    // first-two-digit intitialize
    int ft_dg = floor(card_id / divider);

    if ((ft_dg == 34 || ft_dg == 37) && n_digits == 15)
    {
        printf("AMEX\n");
    }
    else if ((ft_dg >= 51 && ft_dg <= 55) && n_digits == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((ft_dg >= 40 && ft_dg <= 49) && (n_digits >= 13 && n_digits <= 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
