#include <stdio.h>
#include <cs50.h>

void create_bricks(int n);
int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n <= 0 || n > 8);
    create_bricks(n);
}

void create_bricks(int n)
{
    //row
    for (int i = 1; i <= n; i++)
    {
        //columns
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        // end of each row, get to the new line
        printf("\n");
    }
}