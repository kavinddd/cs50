#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int *byte_to_bits(int byte);
int char_to_byte(char letter);

int main(void)
{
    // TODO
    string message = get_string("Message: ");

    for (int i = 0, n = strlen(message); i < n; i++)
    {
        char letter = message[i];
        int byte = char_to_byte(letter);
        int *bits = byte_to_bits(byte);

        for (int j = 7; j >= 0; j--)
        {
            int bit = bits[j];
            print_bulb(bit);
        }
        free(bits);
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

int char_to_byte(char letter)
{
    return (int)letter;
}

int *byte_to_bits(int byte)
{
    int *bits  = (int *)malloc(BITS_IN_BYTE * sizeof(int));
    const int base = 2;
    int two_powered_seven = 128;
    for (int i = 7; i >= 0; i--)
    {
        if (byte >= two_powered_seven)
        {
            bits[i] = 1;
            byte -= two_powered_seven;
        }
        else
        {
            bits[i] = 0;
        }

        two_powered_seven /= base;
    }
    return bits;
}